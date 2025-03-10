#!/bin/bash
# Copyright 2020 The LUCI Authors. All rights reserved.
# Use of this source code is governed under the Apache License, Version 2.0
# that can be found in the LICENSE file.
set -eu

cd $(dirname $0)

# take current revision from written tag.
current_revision=$(
    grep "^ISOLATED_REVISION = 'git_revision:" run_isolated.py | \
    sed -r 's/^.*([a-f0-9]{40,40}).*$/\1/')

# get newer revision and log.
pushd ../..
git fetch
filter="Roll luci-go from "
target_revision=$(git log --grep "${filter}" --oneline -n 1 \
                      --pretty=format:"%H" origin/master DEPS)
logs=$(git --no-pager log --grep "${filter}" --no-decorate \
           "${current_revision}..${target_revision}" DEPS | \
           grep -E '^    202[0-9]-[0-9]{2,2}-[0-9]{2,2} ')
popd

# check existence of package.
for arch in linux-386 linux-amd64 linux-arm64 linux-armv6l linux-mips64 \
                      linux-mips64le linux-mipsle linux-ppc64 \
                      linux-ppc64le linux-s390x mac-amd64 windows-386 \
                      windows-amd64
do
    if ! [[ $(cipd search "infra/tools/luci/isolated/${arch}" \
              -tag "git_revision:${target_revision}") =~ "Instances" ]]; then
        echo "package for ${arch} is not made"
        echo "check https://ci.chromium.org/p/infra-internal/g/infra-packagers/console"
        exit 1
    fi
done

sed -i -e "s/${current_revision}/${target_revision}/" run_isolated.py

git commit -am "client: update isolated client

https://chromium.googlesource.com/infra/infra/+log/${current_revision}..${target_revision}/DEPS

${logs}
"
