// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/bookmarks/browser/archive_node.h"

#include <map>
#include <string>

#include "base/guid.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"

namespace bookmarks {

namespace {

// Whitespace characters to strip from bookmark titles.
const base::char16 kInvalidChars[] = {
  '\n', '\r', '\t',
  0x2028,  // Line separator
  0x2029,  // Paragraph separator
  0
};

std::string PermanentNodeTypeToGuid(ArchiveNode::Type type) {
  switch (type) {
    case ArchiveNode::BOOKMARK_BAR:
      return ArchiveNode::kBookmarkBarNodeGuid;
    case ArchiveNode::OTHER_NODE:
      return ArchiveNode::kOtherBookmarksNodeGuid;
    case ArchiveNode::MOBILE:
      return ArchiveNode::kMobileBookmarksNodeGuid;
    case ArchiveNode::FOLDER:
      return ArchiveNode::kManagedNodeGuid;
    case ArchiveNode::URL:
      NOTREACHED();
      return std::string();
  }
  NOTREACHED();
  return std::string();
}

}  // namespace

// ArchiveNode ---------------------------------------------------------------

// static
const char ArchiveNode::kRootNodeGuid[] =
    "00000000-0000-4000-a000-000000000001";
const char ArchiveNode::kBookmarkBarNodeGuid[] =
    "00000000-0000-4000-a000-000000000002";
const char ArchiveNode::kOtherBookmarksNodeGuid[] =
    "00000000-0000-4000-a000-000000000003";
const char ArchiveNode::kMobileBookmarksNodeGuid[] =
    "00000000-0000-4000-a000-000000000004";
const char ArchiveNode::kManagedNodeGuid[] =
    "00000000-0000-4000-a000-000000000005";

std::string ArchiveNode::RootNodeGuid() {
  return ArchiveNode::kRootNodeGuid;
}

ArchiveNode::ArchiveNode(int64_t id, const std::string& guid, const GURL& url)
    : ArchiveNode(id, guid, url, url.is_empty() ? FOLDER : URL, false) {}

ArchiveNode::~ArchiveNode() = default;

void ArchiveNode::SetTitle(const base::string16& title) {
  // Replace newlines and other problematic whitespace characters in
  // folder/bookmark names with spaces.

  base::string16 trimmed_title;
  base::ReplaceChars(title, kInvalidChars, base::ASCIIToUTF16(" "),
                     &trimmed_title);

  DVLOG(0) << "-------------------------------------";
  DVLOG(0) << "ArchiveNode";
  DVLOG(0) << trimmed_title;
  DVLOG(0) << "-------------------------------------";
  
  ui::TreeNode<ArchiveNode>::SetTitle(trimmed_title);
}

bool ArchiveNode::IsVisible() const {
  return true;
}

bool ArchiveNode::GetMetaInfo(const std::string& key,
                               std::string* value) const {
  if (!meta_info_map_)
    return false;

  MetaInfoMap::const_iterator it = meta_info_map_->find(key);
  if (it == meta_info_map_->end())
    return false;

  *value = it->second;
  return true;
}

bool ArchiveNode::SetMetaInfo(const std::string& key,
                               const std::string& value) {
  if (!meta_info_map_)
    meta_info_map_.reset(new MetaInfoMap);

  auto it = meta_info_map_->find(key);
  if (it == meta_info_map_->end()) {
    (*meta_info_map_)[key] = value;
    return true;
  }
  // Key already in map, check if the value has changed.
  if (it->second == value)
    return false;
  it->second = value;
  return true;
}

bool ArchiveNode::DeleteMetaInfo(const std::string& key) {
  if (!meta_info_map_)
    return false;
  bool erased = meta_info_map_->erase(key) != 0;
  if (meta_info_map_->empty())
    meta_info_map_.reset();
  return erased;
}

void ArchiveNode::SetMetaInfoMap(const MetaInfoMap& meta_info_map) {
  if (meta_info_map.empty())
    meta_info_map_.reset();
  else
    meta_info_map_.reset(new MetaInfoMap(meta_info_map));
}

const ArchiveNode::MetaInfoMap* ArchiveNode::GetMetaInfoMap() const {
  return meta_info_map_.get();
}

const base::string16& ArchiveNode::GetTitledUrlNodeTitle() const {
  return GetTitle();
}

const GURL& ArchiveNode::GetTitledUrlNodeUrl() const {
  return url_;
}

ArchiveNode::ArchiveNode(int64_t id,
                           const std::string& guid,
                           const GURL& url,
                           Type type,
                           bool is_permanent_node)
    : id_(id),
      guid_(guid),
      url_(url),
      type_(type),
      date_added_(base::Time::Now()),
      favicon_type_(favicon_base::IconType::kInvalid),
      is_permanent_node_(is_permanent_node) {
  DCHECK((type == URL) != url.is_empty());
  DCHECK(base::IsValidGUIDOutputString(guid));
}

void ArchiveNode::InvalidateFavicon() {
  icon_url_.reset();
  favicon_ = gfx::Image();
  favicon_type_ = favicon_base::IconType::kInvalid;
  favicon_state_ = INVALID_FAVICON;
}

// ArchivePermanentNode -------------------------------------------------------

ArchivePermanentNode::ArchivePermanentNode(int64_t id,
                                             Type type,
                                             bool visible_when_empty)
    : ArchiveNode(id,
                   PermanentNodeTypeToGuid(type),
                   GURL(),
                   type,
                   /*is_permanent_node=*/true),
      visible_when_empty_(visible_when_empty) {
  DCHECK(type != URL);
}

ArchivePermanentNode::~ArchivePermanentNode() = default;

bool ArchivePermanentNode::IsVisible() const {
  return visible_when_empty_ || !children().empty();
}

}  // namespace bookmarks
