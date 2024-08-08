from citiesFunction import city_capital
import unittest

class TestCities(unittest.TestCase):
    def test_string(self):
        self.assertEqual(city_capital('Paris', 'France'), 'Paris is the capital of France')

unittest.main()