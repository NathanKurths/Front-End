file_name_cat = 'file/cats.txt'
file_name_dog = 'errors/dogs.txt'

try:
    with open(file_name_cat) as file_object:
        contents = file_object.read()
except FileNotFoundError:
    print("O arquivo não foi encontrado.")
else:
    print(contents)
    
    

try:
    with open(file_name_dog) as file_object:
        contents = file_object.read()
except FileNotFoundError:
    print("O arquivo não foi encontrado.")
else:
    print(contents)