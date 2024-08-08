from module import Restaurant
from secondModule import IceCreamStand

my_restaurant = Restaurant('natrix','italiana')
my_restaurant.describe_restaurant()

other_restaurant = IceCreamStand('natrix','sorveteria')
print(other_restaurant.flavors)