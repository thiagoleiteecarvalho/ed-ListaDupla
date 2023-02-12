/*
 * main.c
 * Classe de implemantação da ED Lista Dupla.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* iniciar() {

	Lista *l = malloc(sizeof(Lista));
	l->inicio = NULL;
	l->elemento_corrente = NULL;
	l->tamanho = 0;
	l->posicao_corrente = 0;

	return l;
}

void add(Lista *l, char caractere) {

	if (empty(l)) {

		Elemento *e = malloc(sizeof(Elemento));
		e->valor = caractere;
		e->proximo = NULL;
		e->anterior = NULL;

		l->inicio = e;
	} else {

		Elemento *e = malloc(sizeof(Elemento));
		Elemento *antigo_inicio = l->inicio;

		e->valor = caractere;
		e->proximo = antigo_inicio;
		e->anterior = NULL;
		antigo_inicio->anterior = e;

		l->inicio = e;
	}

	l->tamanho = l->tamanho + 1;
}

int empty(Lista *l) {
	return l->tamanho == 0;
}

void add_pos(Lista *l, char caractere, int posicao) {

	if (empty(l)) {
		printf("Lista vazia. Add posicional não permitido!\n");
		return;
	}

	if (posicao > l->tamanho || posicao <= 0) {
		printf("Posição inválida!\n");
		return;
	}

	if (posicao == 1) {
		add(l, caractere);
		return;
	}

	Elemento *e_atual = l->inicio;
	Elemento *e_anterior;

	Elemento *e = malloc(sizeof(Elemento));
	e->valor = caractere;

	int i;
	for (i = 1; i < posicao; i++) {
		e_anterior = e_atual;
		e_atual = e_atual->proximo;
	}

	e_anterior->proximo = e;
	e->proximo = e_atual;

	e->anterior = e_anterior;
	e_atual->anterior = e;

	l->tamanho = l->tamanho + 1;
}

char get(Lista *l, int posicao) {

	if (empty(l)) {
		printf("Lista vazia.\n");
		return '\0';
	}

	if (posicao > l->tamanho || posicao <= 0) {
		printf("Posição inválida!\n");
		return '\0';
	}

	if (l->elemento_corrente == NULL) {
		l->elemento_corrente = l->inicio;
		l->posicao_corrente = 1;
	}

	if (posicao == l->posicao_corrente) {
		return l->elemento_corrente->valor;
	} else {

		if (posicao > l->posicao_corrente) {

			int i = l->posicao_corrente;
			Elemento *e = l->elemento_corrente;
			while (e != NULL) {

				if (i == posicao) {

					l->elemento_corrente = e;
					l->posicao_corrente = i;
					return e->valor;
				} else {

					e = e->proximo;
					i++;
				}
			}
		}

		if (posicao < l->posicao_corrente) {

			int i = l->posicao_corrente;
			Elemento *e = l->elemento_corrente;
			while (e != NULL) {

				if (i == posicao) {

					l->elemento_corrente = e;
					l->posicao_corrente = i;
					return e->valor;
				} else {

					e = e->anterior;
					i--;
				}
			}
		}
	}

	return '\0';
}

void set(Lista *l, char caractere, int posicao) {

	if (empty(l)) {
		printf("Lista vazia.\n");
		return;
	}

	if (posicao > l->tamanho || posicao <= 0) {
		printf("Posição inválida!\n");
		return;
	}

	if (l->elemento_corrente == NULL) {
		l->elemento_corrente = l->inicio;
		l->posicao_corrente = 1;
	}

	if (posicao == l->posicao_corrente) {
		l->elemento_corrente->valor = caractere;
	} else {

		if (posicao > l->posicao_corrente) {

			int i = l->posicao_corrente;
			Elemento *e = l->elemento_corrente;
			while (e != NULL) {

				if (i == posicao) {

					l->elemento_corrente = e;
					l->posicao_corrente = i;

					e->valor = caractere;
					return;
				} else {

					e = e->proximo;
					i++;
				}
			}
		}

		if (posicao < l->posicao_corrente) {

			int i = l->posicao_corrente;
			Elemento *e = l->elemento_corrente;
			while (e != NULL) {

				if (i == posicao) {

					l->elemento_corrente = e;
					l->posicao_corrente = i;

					e->valor = caractere;
					return;
				} else {

					e = e->anterior;
					i--;
				}
			}
		}
	}
}

char delete(Lista *l, int posicao) {

	if (empty(l)) {
		printf("Lista vazia. Delete não permitido!\n");
		return '\0';
	}

	if (posicao > l->tamanho || posicao <= 0) {
		printf("Posição inválida!\n");
		return '\0';
	}

	if (posicao == 1) {

		Elemento *e = l->inicio;
		char caracter = e->valor;
		l->inicio = l->inicio->proximo;
		l->inicio->anterior = NULL;

		free(e);

		l->tamanho = l->tamanho - 1;
		return caracter;
	} else {

		Elemento *e_atual = l->inicio;
		Elemento *e_anterior;

		int i;
		for (i = 1; i < posicao; i++) {
			e_anterior = e_atual;
			e_atual = e_atual->proximo;
		}

		char caracter = e_atual->valor;
		e_anterior->proximo = e_atual->proximo;
		e_atual->proximo->anterior = e_anterior;

		free(e_atual);

		l->tamanho = l->tamanho - 1;
		return caracter;
	}
}

int size(Lista *l) {
	return l->tamanho;
}

void exibir(Lista *l) {

	if (empty(l)) {

		printf("Lista vazia!\n");
		return;
	}

	Elemento *e = l->inicio;
	printf("Lista:\n");

	while (e != NULL) {

		printf(" %c ", e->valor);
		e = e->proximo;
	}

	printf("\n");
}
