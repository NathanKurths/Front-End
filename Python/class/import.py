from collections import OrderedDict

favorite_languages = OrderedDict()
favorite_languages['jen'] = 'python'
favorite_languages['sarah'] = 'c'
favorite_languages['edward'] = 'ruby'
favorite_languages['phil'] = 'python'

print(favorite_languages)

from random import randint

class Die():
    def __init__(self, sides=6):
        self.sides = sides
        
    def roll_die(self):
        print(randint(1, self.sides))

jogar = Die()

for i in range (1, 11):
    jogar.roll_die()
