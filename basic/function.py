# utilizando classes para transferir dados entre lista e imprimir
def transferindo_lista(nao_printados, printados):
    while nao_printados:
        iten_analisado = nao_printados.pop()
        printados.append(iten_analisado)

def mostrando_lista(printados):
    for item in printados:
        print(item)
        
lista_nao_printados = ['alice', 'brian', 'candace']
lista_printados = []

transferindo_lista(lista_nao_printados, lista_printados)
mostrando_lista(lista_printados)

#fazendo a mesma coisa mas preservando a primeira lista, incluindo [:] na chamada de transferindo_lista
def transferindo_lista(nao_printados, printados):
    while nao_printados:
        iten_analisado = nao_printados.pop()
        printados.append(iten_analisado)

def mostrando_lista(printados):
    for item in printados:
        print(item)
        
lista_nao_printados = ['alice', 'brian', 'candace']
lista_printados = []

transferindo_lista(lista_nao_printados[:], lista_printados)
mostrando_lista(lista_printados)
mostrando_lista(lista_nao_printados)

#**user_info é um parametro que permite que a função receba um número arbitrário de argumentos por meio de import 
# dessa forma tem que usar functionImport.build_profile
import functionImport 
user_profile = functionImport.build_profile('albert', 'einstein', location='princeton',field='physics') 
print(user_profile)

#apelidando o modulo
import functionImport as fi
user_profile = fi.build_profile('albert', 'einstein', location='princeton',field='physics') 
print(user_profile)

# dessa forma é só usar o nome da função
from functionImport import build_profile 
user_profile = build_profile('albert', 'einstein', location='princeton',field='physics') 
print(user_profile)

# dessa forma é apelidar o nome da função
from functionImport import build_profile as bp 
user_profile = bp('albert', 'einstein', location='princeton',field='physics') 
print(user_profile)

#importa todas as funções
from functionImport import *
user_profile = build_profile('albert', 'einstein', location='princeton',field='physics') 
print(user_profile)

