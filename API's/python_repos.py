import requests
import pygal
from pygal.style import LightColorizedStyle as LCS, LightenStyle as LS

# Faz uma chamada de API e armazena a resposta 
url = 'https://api.github.com/search/repositories?q=language:python&sort=stars'
r = requests.get(url)
print("Status code:", r.status_code)

# Armazena a resposta da API em uma variável
response_dict = r.json()
print ("Total repositories:", response_dict['total_count'])

# Explora informações sobre os repositórios
repo_dicts = response_dict['items']
names, stars = [], []

for repo_dict in repo_dicts:
    names.append(repo_dict['name'])
    stars.append(repo_dict['stargazers_count'])

# Cria a visualização
my_style = LS('#333366', base_style=LCS)
chart = pygal.Bar(style=my_style, x_label_rotation=45, show_legends=False)
chart.title = 'Most-Starred Python Projects on Github'
chart.x_labels = names
chart.add('', stars)
chart.render_to_file('python_repos.svg')


# Analisa o primeiro repositório
# repo_dict = repo_dicts[0]
# print("\nSelected information about first repository:")
# print('Name:', repo_dict['name'])
# print('Owner:', repo_dict['owner']['login'])
# print('Stars:', repo_dict['stargazers_count'])
# print('Repository:', repo_dict['html_url'])
# print('Created:', repo_dict['created_at'])
# print('Updated:', repo_dict['updated_at'])
# print('Description:', repo_dict['description'])

