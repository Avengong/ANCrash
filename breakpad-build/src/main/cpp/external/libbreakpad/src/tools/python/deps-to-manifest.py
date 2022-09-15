#!/usr/bin/python
# Copyright 2016 Google Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
#     * Neither the name of Google Inc. nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

"""Convert gclient's DEPS file to repo's manifest xml file."""

from __future__ import print_function

import argparse
import os
import sys

REMOTES = {
    'chromium': 'https://chromium.googlesource.com/',
    'github': 'https://github.com/',
}
REVIEWS = {
    'chromium': 'https://chromium-review.googlesource.com',
}

MANIFEST_HEAD = """<?xml version='1.0' encoding='UTF-8'?>
<!-- AUTOGENERATED BY %(prog)s; DO NOT EDIT -->
<manifest>

  <default revision='refs/heads/master'
           remote='chromium'
           sync-c='true'
           sync-j='8' />
"""

MANIFEST_REMOTE = """
  <remote  name='%(name)s'
           fetch='%(fetch)s'
           review='%(review)s' />
"""

MANIFEST_PROJECT = """
  <project path='%(path)s'
           name='%(name)s'
           revision='%(revision)s'
           remote='%(remote)s' />
"""

MANIFEST_TAIL = """
</manifest>
"""


def ConvertDepsToManifest(deps, manifest):
    """Convert the |deps| file to the |manifest|."""
    # Load the DEPS file data.
    ctx = {}
    execfile(deps, ctx)

    new_contents = ''

    # Write out the common header.
    data = {
        'prog': os.path.basename(__file__),
    }
    new_contents += MANIFEST_HEAD % data

    # Write out the <remote> sections.
    for name, fetch in REMOTES.items():
        data = {
            'name': name,
            'fetch': fetch,
            'review': REVIEWS.get(name, ''),
        }
        new_contents += MANIFEST_REMOTE % data

    # Write out the main repo itself.
    data = {
        'path': 'src',
        'name': 'breakpad/breakpad',
        'revision': 'refs/heads/master',
        'remote': 'chromium',
    }
    new_contents += MANIFEST_PROJECT % data

    # Write out the <project> sections.
    for path, url in ctx['deps'].items():
        for name, fetch in REMOTES.items():
            if url.startswith(fetch):
                remote = name
                break
        else:
            raise ValueError('Unknown DEPS remote: %s: %s' % (path, url))

        # The DEPS url will look like:
        # https://chromium.googlesource.com/external/gyp/@e8ab0833a42691cd2
        remote_path, rev = url.split('@')
        remote_path = remote_path[len(fetch):]

        # If it's not a revision, assume it's a tag.  Repo wants full ref names.
        if len(rev) != 40:
            rev = 'refs/tags/%s' % rev

        data = {
            'path': path,
            'name': remote_path,
            'revision': rev,
            'remote': remote,
        }
        new_contents += MANIFEST_PROJECT % data

    # Write out the common footer.
    new_contents += MANIFEST_TAIL

    # See if the manifest has actually changed contents to avoid thrashing.
    try:
        old_contents = open(manifest).read()
    except IOError:
        # In case the file doesn't exist yet.
        old_contents = ''
    if old_contents != new_contents:
        print('Updating %s due to changed %s' % (manifest, deps))
        with open(manifest, 'w') as fp:
            fp.write(new_contents)


def GetParser():
    """Return a CLI parser."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('deps',
                        help='The DEPS file to convert')
    parser.add_argument('manifest',
                        help='The manifest xml to generate')
    return parser


def main(argv):
    """The main func!"""
    parser = GetParser()
    opts = parser.parse_args(argv)
    ConvertDepsToManifest(opts.deps, opts.manifest)


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
