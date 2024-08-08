file_name = 'files/guest.txt'
name_person = ''

#concatenar no arquivo o que eu quiser escrever
while(name_person != 'sair'):
    name_person = input('Qual o seu nome?\n')
    with open(file_name, 'a') as file_object:
        file_object.write('\n' + name_person)
    