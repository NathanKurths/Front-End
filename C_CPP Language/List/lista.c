#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas fornecidas. Você pode 
 * implementar funções auxiliares além das fornecidas, para isso,
 * coloque o cabeçário da função no arquivo .h e sua implementação 
 * aqui, no arquivo .c. Não altere assinaturas de funções, caso 
 * contrário seu código receberá nota 0,0 (zero).
 */

//Estrutura de lista
struct lista {
	tipo 		*dados;		//Vetor que armazena os dados
	int 		capacidade; //Capacidade de armazenamento da lista
 	int 		tamanho;	//Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções
lista_t *lista_cria(int capacidade)
{
	lista_t *lista = (lista_t *)malloc(sizeof(lista_t));
	if (lista == NULL)
		return NULL;
	lista->capacidade = capacidade;
	lista->tamanho = 0;
	lista->dados = (tipo *)malloc(capacidade * sizeof(tipo));
	return lista;
}

void lista_destroi(lista_t **l)
{
	if (l == NULL)
		return;
	free((*l)->dados);
	free(*l);
	*l = NULL;
}

int lista_inicializada(lista_t *l)
{
	if (l == NULL)
		return 0;
	return 1;
}

int lista_tamanho(lista_t *l)
{
	if (l == NULL)
		return -1;
	return l->tamanho;
}

int lista_capacidade(lista_t *l)
{
	if (l == NULL)
		return -1;
	return l->capacidade;
}

int lista_cheia(lista_t *l)
{
	if (l == NULL)
		return -1;
	if (l->tamanho == l->capacidade)
		return 1;
	return 0;
}

int lista_info_cabeca(lista_t *l, int *dado)
{
	if (l == NULL || dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	*dado = l->dados[0];
	return 1;
}

int lista_info_cauda(lista_t *l, int *dado)
{
	if (l == NULL || dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	*dado = l->dados[l->tamanho - 1];
	return 1;
}

int lista_info_posicao(lista_t *l, int *dado, int pos)
{
	if (l == NULL || dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	if (pos >= 0 && pos < l->tamanho)
		*dado = l->dados[pos];
    else
    {
        return 0;
    }
	return 1;
}

int lista_insere_cabeca(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	if (l->tamanho >= l->capacidade)
		return -1;
	if (l->tamanho == 0)
	{
		l->tamanho++;
		l->dados[0] = dado;
		return 1;
	}
	else
	{
		l->tamanho++;
		for (int i = l->tamanho - 1; i > 0; i--)
		{
			l->dados[i] = l->dados[i - 1];
		}
		l->dados[0] = dado;
	}
	return 1;
}

int lista_insere_cauda(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	if (l->tamanho >= l->capacidade)
		return -1;
	l->tamanho++;
	l->dados[l->tamanho - 1] = dado;
	return 1;
}

int lista_insere_posicao(lista_t *l, tipo dado, int pos)
{
	if (l == NULL || l->tamanho >= l->capacidade)
		return -1;
	if (pos < 0 || pos > l->tamanho)
		return 0;
	l->tamanho++;
	for (int i = l-> tamanho - 1; i > pos; i--)
	{
		l->dados[i] = l->dados[i - 1];
	}
	l->dados[pos] = dado;
	return 1;
}

int lista_remove_cabeca(lista_t *l, tipo *dado)
{
	if (l == NULL)
		return -1;
	if (dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	*dado = l->dados[0];
	l->tamanho--;
	for (int i = 0; i < l->tamanho; i++)
	{
		l->dados[i] = l->dados[i + 1];
	}
	return 1;
}

int lista_remove_cauda(lista_t *l, tipo *dado)
{
	if (l == NULL)
		return -1;
	if (dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	*dado = l->dados[l->tamanho - 1];
	l->tamanho--;

	return 1;
}

int lista_remove_posicao(lista_t *l, tipo *dado, int pos)
{
	if (l == NULL || !(lista_inicializada(l)) || dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	if (pos < 0 || pos >= l->tamanho)
		return 0;
	*dado = l->dados[pos];
	for (int i = pos; i < l->tamanho; i++)
	{
		l->dados[i] = l->dados[i + 1];
	}
	l->tamanho--;
	return 1;
}

int 		lista_remove_primeira	(lista_t *l, tipo dado)
{
	if (l == NULL || !(lista_inicializada(l)))
		return -1;
	int pos;
	int aux;
	int verificador = -1;	
	for (int i = 0; i < l->tamanho; i++)
	{
		if(l->dados[i] == dado)
		{	
			pos = i;
			verificador = 666;
			lista_remove_posicao(l, &aux, i);
			break;
		}
	}
	if(verificador == -1) return -2;
	return pos;
}

int 		lista_remove_todas		(lista_t *l, tipo dado)
{
	if (l == NULL || !(lista_inicializada(l)))
		return -1;
	int cont = 0;
	int aux;
	for (int i = 0; i < l->tamanho; i++)
	{
		if(l->dados[i] == dado)
		{	
			lista_remove_posicao(l, &aux, i);
			cont++;
		}
	}
	return cont;
}

int 		lista_busca_info		(lista_t *l, tipo dado)
{
	if (l == NULL || l->tamanho == 0)
		return -1;
	int pos;
	int verificador = -1;	
	for (int i = 0; i < l->tamanho; i++)
	{
		if(l->dados[i] == dado)
		{	
			pos = i;
			verificador = 666;
			break;
		}
	}
	if(verificador == -1) return -1;
	return pos;
}

int 		lista_frequencia_info	(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	int cont = 0;
	for (int i = 0; i < l->tamanho; i++)
	{
		if(l->dados[i] == dado)
		{	
			cont++;
		}
	}
	return cont;
}

int			lista_ordenada 			(lista_t *l)
{
	if (l == NULL || !(lista_inicializada(l)))
		return -1;
	for (int i = 0; i < l->tamanho - 1; i++)
	{
		if(l->dados[i] > l->dados[i + 1])
		{	
			return 0;
		}
	}
	return 1;
}

int 		lista_insere_ordenado	(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	if(l->tamanho == l->capacidade) 
	    return -1;
	if(l->dados[0] >= dado) 
	{
	    lista_insere_cabeca(l,dado);
	    return 1;
	}
	for (int i = 0; i<l->tamanho; i++)
	{
		if(l->dados[i] < dado && l->dados[i+1] >= dado)
		{
			lista_insere_posicao(l, dado, i + 1);
			return 1;
		}
		else if(l->dados[l->tamanho - 1] <= dado) 
		{
		    lista_insere_cauda(l,dado);
		    return 1;
		}
	}
	return -1;
}

int 		lista_compara(lista_t *l1, lista_t *l2)
{
	if(l1 == NULL && l2 == NULL) return 1;
	if((l1 == NULL && l2 !=NULL) || (l1!=NULL && l2==NULL) || l1->tamanho != l2->tamanho) return 0;
	for(int i = 0; i < l1->tamanho; i++)
	{
		if(l1->dados[i] != l2->dados[i]) return 0;
	}
	return 1;
}

int 		lista_reverte(lista_t *l)
{
	if(l == NULL) return -1;
	if(l->tamanho == 0) return 1;
	int aux;
	for(int i = 0; i <l->tamanho/2; i++)
	{
		aux = l->dados[i];
		l->dados[i] = l->dados[l->tamanho - i - 1];
		l->dados[l->tamanho - i - 1] = aux;
	}
	return 1;
}

lista_t*	lista_cria_copia(lista_t *l)
{
	if(l == NULL || l->dados == NULL) return NULL;
	lista_t *lista_nova = lista_cria(l->capacidade);
	lista_nova->capacidade = l->capacidade;
	lista_nova->tamanho = l->tamanho;
	for(int i = 0; i<l->tamanho; i++)
	{
		lista_nova->dados[i] = l->dados[i];
	}
	return lista_nova;
}
