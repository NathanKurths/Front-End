# concatena string
prompt = "If you tell us who you are, we can personalize the messages you see."
prompt += "\nWhat is your first name? "
print(prompt)

#tratar entradas como numeros
age = input()
age = int(age)
if age < 21:
    print(age)

#transferir dados de listas
usuarios_nao_confirmados = ['alice', 'brian', 'candace']
usuarios_confirmados = []  

print(usuarios_nao_confirmados)
print(usuarios_confirmados)

while usuarios_nao_confirmados:
    usuario_analisado = usuarios_nao_confirmados.pop()
    usuarios_confirmados.append(usuario_analisado)
    
print(usuarios_nao_confirmados)
print(usuarios_confirmados)

#inputs em dicionarios
respostas = {}
sinal = True
while sinal:    
    nome = input("Qual é o seu nome? ")
    resposta = input("Você quer participar do questionário? sim ou nao?")
    if resposta == 'nao':
        sinal = False
    respostas[nome] = resposta 
              
print(respostas)