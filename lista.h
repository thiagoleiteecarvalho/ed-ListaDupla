/*
 * fila.h
 * Header de definição da ED Lista Dupla.
 * Author: Thiago Leite
 */

#pragma once

typedef struct elemento {
	char valor;
	struct elemento *proximo;
	struct elemento *anterior;
} Elemento;

typedef struct lista {
	Elemento *inicio;
	Elemento *elemento_corrente;
	int posicao_corrente;
	int tamanho;
} Lista;

Lista* iniciar();
void add(Lista *l, char caractere);
int empty(Lista *l);
void add_pos(Lista *l, char caractere, int posicao);
char get(Lista *l, int posicao);
void set(Lista *l, char caractere, int posicao);
char delete(Lista *l, int posicao);
int size(Lista *l);
void exibir(Lista *l);
