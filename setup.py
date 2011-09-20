#!/usr/bin/env python

from distutils.core import setup, Extension
from os import path

setup(name = "ns1",
      version = "0.1.5",
      description = "Sun's NS1 Hash Function for Python",
      long_description = '''
''',
      author = "Tsukasa Hamano <hamano@osstech.co.jp>",
      author_email = "hamano@osstech.co.jp",
      url="",
      download_url="http://pypi.python.org/pypi/pyns1/",
      license="CDDL",
      ext_modules = [
        Extension(
            "ns1",
            ["pyns1.c", "ns_crypt.c"],
            libraries=["crypt"],
            )
        ],
      classifiers = [
        'Programming Language :: Python',
        'Topic :: Security :: Cryptography',
        'Topic :: Software Development :: Libraries :: Python Modules',
        ],
      )
