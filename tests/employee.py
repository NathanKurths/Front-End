import unittest

class Employee():
    def __init__(self, first_name, last_name, annual_salary):
        self.first_name = first_name
        self.last_name = last_name
        self.annual_salary = annual_salary
    
    def give_raise(self, upgrade):
        self.annual_salary = int(self.annual_salary)
        upgrade = int(upgrade)
        self.annual_salary = self.annual_salary + upgrade
        return self.annual_salary
        
class TestEmployee(unittest.TestCase):
    def setUp(self):
        self.person = Employee('nathan','kurths','220')
        self.person.give_raise(220)
        
    def test_give_raise(self):
        self.assertEqual(self.person.annual_salary, 440)
        
unittest.main()
        