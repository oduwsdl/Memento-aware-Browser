# Copyright 2020 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Functions for formatting things in a human-readable format."""

import datetime
import json as mod_json
import os
import sys
from typing import Optional, TextIO, Union

from chromite.lib import cros_build_lib


assert sys.version_info >= (3, 6), 'This module requires Python 3.6+'


def timedelta(delta):
  """Returns a more human-readable version of the datetime.timedelta.

  Useful when printing durations >= 1 second in logs.

  Args:
    delta: A datetime.timedelta.

  Returns:
    Formatted string of the delta like '1d2h3m4.000s'.
  """
  if not isinstance(delta, datetime.timedelta):
    raise TypeError('delta must be of type datetime.timedelta')
  formated_delta = ''
  if delta.days:
    formated_delta = '%dd' % delta.days
  minutes, seconds = divmod(delta.seconds, 60)
  hours, minutes = divmod(minutes, 60)
  if hours > 0:
    formated_delta += '%dh' % hours
  if minutes > 0:
    formated_delta += '%dm' % minutes
  formated_delta += '%i.%03is' % (seconds, delta.microseconds // 1000)
  return formated_delta


def json(obj, fp: Optional[Union[str, os.PathLike, TextIO]] = None,
         compact: bool = False) -> Optional[str]:
  """Convert an object to JSON with the right format.

  Args:
    obj: The object to serialize & format.
    fp: By default, the JSON string is returned.  The |fp| allows specifying a
        file object (in text mode) to write to instead.
    compact: Whether the output will be compact (flattened to one line), or
        human readable (spread over multiple lines).

  Returns:
    A string if |fp| is not specified, else None.
  """
  kwargs = {
      # JSON style guide says Uunicode characters are fully allowed.
      'ensure_ascii': False,
      # We use 2 space indent to match JSON style guide.
      'indent': None if compact else 2,
      'separators': (',', ':') if compact else (',', ': '),
      'sort_keys': True,
  }
  if fp:
    with cros_build_lib.Open(fp, mode='w') as real_fp:
      mod_json.dump(obj, real_fp, **kwargs)
      if not compact:
        real_fp.write('\n')
  else:
    ret = mod_json.dumps(obj, **kwargs)
    if not compact:
      ret += '\n'
    return ret
