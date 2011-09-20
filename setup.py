#!/usr/bin/env python

from distutils.core import setup, Extension
from os import path

setup(name = "ns1",
      version = "0.1.9",
      description = "Sun's NS1 Crypt Function for Python",
      long_description = '''
Example:

>>> import ns1
>>> print ns1.evalue('hello')
{NS1}6e376651c1
''',
      author = "Tsukasa Hamano <hamano@osstech.co.jp>",
      author_email = "hamano@osstech.co.jp",
      url="https://github.com/hamano/python-ns1",
      download_url="http://pypi.python.org/pypi/pyns1/",
      license="CDDL&BSD",
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
