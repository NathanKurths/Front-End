import unittest

class Employe():
    def __init__(self, first_name, last_name, annual_salary):
        self.first_name = first_name
        self.last_name = last_name
        self.annual_salary = annual_salary
    
    def give_raise(self, upgrade):
        self.annual_salary = int(self.annual_salary)
        upgrade = int(upgrade)
        self.annual_salary = self.annual_salary + upgrade
        return self.annual_salary
        
class TestEmploye(unittest.TestCase):
    def test_give_raise(self):
        person = Employe('nathan','kurths','300')
        new_salary = person.give_raise(450)
        self.assertEqual(new_salary, 750)
        
unittest.main()
        