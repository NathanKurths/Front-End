#tratando dicionarios, acessando values ou items

jogadores ={ 'nathan' : {'pontos': 10, 'vida': 3, 'velocidade': 'rapido'}, 'jose': {'pontos': 20, 'vida': 2, 'velocidade': 'lento'}}

for nome, dados in jogadores.items():
    print(nome)

teste = {'nome': 'nathan', 'idade': 20}

for i in teste.values():
    print(i)