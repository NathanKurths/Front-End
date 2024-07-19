import json
file_name = 'favoriteNumber.json'

def verifiyng(number):
    print("I remember, is the number " + number + ".")
try:
    with open(file_name) as f_obj:
        reading = json.load(f_obj)
        verifiyng(reading)
        
except FileNotFoundError:
    favorite_number = input("What's your favorite number?\n")
    with open(file_name, 'w') as f_obj:
        json.dump(favorite_number, f_obj)

