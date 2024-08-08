with open('files/testing.txt') as file_object:
    #lendo o arquivo normalmente
    # contents = file_object.read()
    # print(contents)
    
    #lendo o arquivo percorrendo com um laço
    # for string in file_object:
    #     print(string.strip())
    
    
    #lendo o arquivo o colocando em lista
    full_string = ''
    for string in file_object:
        full_string += string
print(full_string)        

#trocando palavra python por c
full_string = full_string.replace('python','c')
print(full_string)

    