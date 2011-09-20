#!/usr/bin/env python

import unittest
import ns1

class NS1Test(unittest.TestCase):
    def test_evalue(self):
        str = ns1.evalue('hello')
        self.assertEqual(str, '{NS1}6e376651c1')

    def test_dvalue(self):
        str = ns1.dvalue('{NS1}6e376651c1')
        self.assertEqual(str, 'hello')

if __name__ == '__main__':
    unittest.main()
