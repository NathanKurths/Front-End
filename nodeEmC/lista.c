#include "lista.h"

/**
 * arquivo lista.c
 *
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas de nó e lista fornecidas
 * Você pode implementar funções auxiliares além das fornecidas,
 * para isso, coloque o cabeçário da função no arquivo .h e sua
 * implementação aqui, no arquivo .c. Não altere assinaturas de
 * funções, caso contrário seu código receberá nota 0,0 (zero).
 */

// Estrutura de nó duplamente encadeado
struct no
{
	tipo info;		// Informação (dado) armazenada no nó
	struct no *ant; // Ponteiro para o nó anterior
	struct no *prx; // Ponteiro para o próximo nó
};

// Estrutura de lista duplamente encadeada com nós
struct lista
{
	no_t *cabeca; // Ponteiro para a cabeça da lista (primeiro)
	no_t *cauda;  // Ponteiro para a cauda da lista (último)
	int tamanho;  // Tamanho aux da lista
};

// Coloque a partir daqui a implementação das funções

lista_t *lista_cria()
{
	lista_t *lista = (lista_t *)malloc(sizeof(lista_t));
	if (lista == NULL)
		return NULL;
	lista->cabeca = NULL;
	lista->cauda = NULL;
	lista->tamanho = 0;
	return lista;
}

void lista_destroi(lista_t **l)
{
	if (l == NULL)
		return;
	no_t *aux = (*l)->cabeca;
	no_t *aux2;
	while (aux != NULL)
	{
		aux2 = aux->prx;
		free(aux);
		aux = aux2;
	}
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

int lista_info_cabeca(lista_t *l, int *dado)
{
	if (l == NULL || dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	*dado = l->cabeca->info;
	return 1;
}

int lista_info_cauda(lista_t *l, int *dado)
{
	if (l == NULL || dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	*dado = l->cauda->info;
	return 1;
}

int lista_info_posicao(lista_t *l, int *dado, int pos)
{
	if (l == NULL || dado == NULL)
		return -1;
	if (l->tamanho == 0 || pos < 0 || pos >= l->tamanho)
		return 0;
	no_t *aux = l->cabeca;
	int cont = 0;
	while (aux != NULL)
	{
		if (cont == pos)
		{
			*dado = aux->info;
			return 1;
		}
		aux = aux->prx;
		cont++;
	}
	return -1;
}

int lista_insere_cabeca(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	no_t *aux = (no_t *)malloc(sizeof(no_t));
	if (aux == NULL)
		return -1;
	aux->info = dado;
	aux->prx = l->cabeca;
	aux->ant = NULL;
	if (l->cabeca != NULL)
		l->cabeca->ant = aux;
	l->cabeca = aux;
	l->tamanho++;
	if (l->cauda == NULL)
		l->cauda = aux;
	// Setar o aux anterior
	return 1;
}

// Lembrar de ligar os nós entre si e mexer nos ponteiros da lista qnd necessario

int lista_insere_cauda(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	if (l->cabeca == NULL)
		lista_insere_cabeca(l, dado);
	else
	{
		no_t *aux = (no_t *)malloc(sizeof(no_t));
		if (aux == NULL)
			return -1;
		aux->info = dado;
		aux->prx = NULL;
		l->cauda->prx = aux;
		aux->ant = l->cauda;
		l->cauda = aux;
		l->tamanho++;
	}
	return 1;
}

int lista_insere_posicao(lista_t *l, tipo dado, int pos)
{
	if (l == NULL)
		return -1;
	if (pos < 0 || pos > l->tamanho)
		return 0;

	no_t *novo_no = (no_t *)malloc(sizeof(no_t));
	if (novo_no == NULL)
		return -1;

	novo_no->info = dado;
	novo_no->prx = NULL;
	novo_no->ant = NULL;

	if (pos == 0)
	{
		lista_insere_cabeca(l, dado);
		free(novo_no);
		return 1;
	}
	else if (pos == l->tamanho - 1)
	{
		lista_insere_cauda(l, dado);
		free(novo_no);
		return 1;
	}
	else
	{
		int cont = 0;
		no_t *aux = l->cabeca;

		while (cont < pos - 1 && aux != NULL)
		{
			aux = aux->prx;
			cont++;
		}

		if (aux == NULL)
		{
			free(novo_no);
			return 0;
		}

		novo_no->prx = aux->prx;
		novo_no->ant = aux;

		if (aux->prx != NULL)
		{
			aux->prx->ant = novo_no;
		}

		aux->prx = novo_no;

		l->tamanho++;
		return 1;
	}

	return -1;
}

int lista_remove_cabeca(lista_t *l, tipo *dado)
{
	if (!(lista_inicializada(l)) || dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	else
	{
		if (l->tamanho == 1)
		{
			l->tamanho--;
			*dado = l->cabeca->info;
			free(l->cabeca);
			l->cabeca = NULL;
			l->cauda = NULL;
			return 1;
		}
		if (l->tamanho == 2)
		{
			l->tamanho--;
			*dado = l->cabeca->info;
			free(l->cabeca);
			l->cabeca = l->cauda;
			l->cabeca->ant = NULL;
			return 1;
		}
		l->tamanho--;
		*dado = l->cabeca->info;
		no_t *aux = l->cabeca->prx;
		aux->ant = NULL;
		free(l->cabeca);
		l->cabeca = aux;
	}
	return 1;
}

int lista_remove_cauda(lista_t *l, tipo *dado)
{
	if (!(lista_inicializada(l)) || dado == NULL)
		return -1;
	if (l->tamanho == 0)
		return 0;
	else
	{
		if (l->tamanho == 1)
		{
			l->tamanho--;
			*dado = l->cauda->info;
			free(l->cauda);
			l->cabeca = NULL;
			l->cauda = NULL;
			return 1;
		}
		if (l->tamanho == 2)
		{
			l->tamanho--;
			*dado = l->cauda->info;
			free(l->cauda);
			l->cauda = l->cabeca;
			l->cauda->prx = NULL;
			return 1;
		}

		if (l->cabeca->prx == NULL)
		{
			l->tamanho--;
			l->cabeca = NULL;
			l->cauda = NULL;
			return 1;
		}

		l->tamanho--;
		*dado = l->cauda->info;
		no_t *aux = l->cauda->ant;
		aux->prx = NULL;
		free(l->cauda);
		l->cauda = aux;
	}

	return 1;
}

int lista_remove_posicao(lista_t *l, tipo *dado, int pos)
{
	if (!(lista_inicializada(l)) || dado == NULL)
		return -1;
	if (l->tamanho == 0 || (pos < 0 && pos >= l->tamanho))
		return 0;
	if (pos == 0)
		lista_remove_cabeca(l, dado);
	else if (pos == l->tamanho - 1)
		lista_remove_cauda(l, dado);
	else
	{
		no_t *aux = l->cabeca;
		int cont = 0;
		while (cont < pos)
		{
			aux = aux->prx;
			cont++;
		}
		l->tamanho--;
		*dado = aux->info;
		aux->ant->prx = aux->prx;
		aux->prx->ant = aux->ant;
		free(aux);
	}
	return 1;
}

int lista_remove_primeira(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	tipo a;
	if(!l->cabeca){
	    return -2;
	}
	if (dado == l->cabeca->info)
		lista_remove_cabeca(l, &a);
	else if (dado == l->cauda->info)
		lista_remove_cauda(l, &a);
	else
	{
		no_t *aux = l->cabeca;
		int cont = 0;
		while (cont < l->tamanho)
		{
			if (aux->info == dado)
			{
				lista_remove_posicao(l, &a, cont);
				return cont;
			}
			aux = aux->prx;
			cont++;
		}
	}
	return -2;
}

int lista_remove_todas(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	int retorna = 0;
	no_t *aux = l->cabeca;
	while (aux != NULL)
	{
		if (aux->info == dado)
		{
			no_t *temp = aux;
			if (aux->ant != NULL)
				aux->ant->prx = aux->prx;
			else
				l->cabeca = aux->prx;
			if (aux->prx != NULL)
				aux->prx->ant = aux->ant;
			else
				l->cauda = aux->ant; // auxizar a cauda da lista, caso seja o último nó
			aux = aux->prx;
			free(temp);
			l->tamanho--;
			retorna++;
		}
		else
		{
			aux = aux->prx;
		}
	}
	return retorna;
}

int lista_busca_info(lista_t *l, tipo dado)
{
	if (l == NULL || l->tamanho == 0)
		return -1;
	no_t *aux = l->cabeca;
	int cont = 0;
	while (aux != NULL)
	{
		if (aux->info == dado)
		{
			return cont;
		}
		else
		{
			cont++;
			aux = aux->prx;
		}
	}
	return -1;
}

int lista_frequencia_info(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	no_t *aux = l->cabeca;
	int cont = 0;
	while (aux != NULL)
	{
		if (aux->info == dado)
		{
			cont++;
		}
		aux = aux->prx;
	}
	return cont;
}

int lista_ordenada(lista_t *l)
{
	if (l == NULL)
		return -1;
	if (l->tamanho == 0)
		return 1;
	no_t *aux = l->cabeca;
	while (aux->prx != NULL)
	{
		if (aux->info > aux->prx->info)
			return 0;
		aux = aux->prx;
	}
	return 1;
}

int lista_insere_ordenado(lista_t *l, tipo dado)
{
	if (l == NULL)
		return -1;
	if (l->cabeca == NULL && l->cauda == NULL)
	{
		lista_insere_cabeca(l, dado);
		return 1;
	}
	else
	{
		no_t *novo_no = (no_t *)malloc(sizeof(no_t));
		if (novo_no == NULL)
			return -1;
		novo_no->info = dado;
		novo_no->ant = NULL;
		novo_no->prx = NULL;

		no_t *aux = l->cabeca;
		no_t *anterior = NULL;

		while (aux != NULL && dado > aux->info)
		{
			anterior = aux;
			aux = aux->prx;
		}

		if (anterior == NULL)
		{
			lista_insere_cabeca(l, dado);
		}
		else if (aux == NULL)
		{
			lista_insere_cauda(l, dado);
		}
		else
		{
			anterior->prx = novo_no;
			novo_no->ant = anterior;
			novo_no->prx = aux;
			aux->ant = novo_no;
		}

		l->tamanho++;
		return 1;
	}
	return -1;
}

int lista_compara(lista_t *l1, lista_t *l2)
{
	if (!(lista_inicializada(l1)) && !(lista_inicializada(l2)))
		return 1;
	else if (!(lista_inicializada(l1)) || !(lista_inicializada(l2)))
		return 0;
	else if (l1->tamanho != l2->tamanho)
		return 0;
	else
	{
		no_t *aux = l1->cabeca;
		no_t *temp = l2->cabeca;
		while (aux != NULL)
		{
			if (aux->info != temp->info)
				return 0;
			else
			{
				aux = aux->prx;
				temp = temp->prx;
			}
		}
	}
	return 1;
}

int lista_reverte(lista_t *l)
{
	if (l == NULL)
		return -1;

	no_t *anterior = NULL;
	no_t *atual = l->cabeca;

	while (atual != NULL)
	{
		no_t *proximo = atual->prx;
		atual->prx = anterior;
		atual->ant = proximo;
		anterior = atual;
		atual = proximo;
	}

	no_t *temp = l->cabeca;
	l->cabeca = l->cauda;
	l->cauda = temp;

	return 1;
}

lista_t *lista_cria_copia(lista_t *l)
{
	if (l == NULL)
		return NULL;

	lista_t *copia = (lista_t *)malloc(sizeof(lista_t));
	if (copia == NULL)
		return NULL;

	copia->tamanho = 0;
	copia->cabeca = NULL;
	copia->cauda = NULL;

	no_t *aux = l->cabeca;

	while (aux != NULL)
	{
		int dado = aux->info;
		lista_insere_cauda(copia, dado);
		aux = aux->prx;
	}

	return copia;
}
