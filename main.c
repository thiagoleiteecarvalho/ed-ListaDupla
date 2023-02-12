/*
 * main.c
 * Classe principal de execução da Lista Dupla.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {

	Lista *lista = iniciar();

	if (!lista) {

		printf("Sem memoria disponivel!\n");
		exit(1);
	} else {

		int opcao;
		char valor;
		int pos;
		int tamanho;

		do {

			printf("\n");
			printf("LISTA DUPLA\n");
			printf("Escolha a opcao\n");
			printf("0. Sair\n");
			printf("1. ADD\n");
			printf("2. ADD_POS\n");
			printf("3. GET\n");
			printf("4. SET\n");
			printf("5. DELETE\n");
			printf("6. SIZE\n");
			printf("7. Exibir lista\n");
			printf("Digite uma opção:");
			scanf("%d", &opcao);

			switch (opcao) {
			case 0:
				exit(1);
				break;

			case 1:
				printf("Digite um valor a ser adicionado:");
				scanf(" %c", &valor);
				add(lista, valor);
				break;

			case 2:
				printf("Digite um valor a ser adicionado:");
				scanf(" %c", &valor);
				printf("Digite a posição:");
				scanf(" %d", &pos);
				add_pos(lista, valor, pos);
				break;

			case 3:
				printf("Digite a posição:");
				scanf(" %d", &pos);
				valor = get(lista, pos);
				if (valor)
					printf("Valor da posição %d: %c\n\n", pos, valor);
				break;

			case 4:
				printf("Digite o novo valor:");
				scanf(" %c", &valor);
				printf("Digite a posição:");
				scanf(" %d", &pos);
				set(lista, valor, pos);
				break;

			case 5:
				printf("Digite a posição a remover:");
				scanf(" %d", &pos);
				char valor = delete(lista, pos);
				if (valor)
					printf("Valor removido da posição %d: %c\n\n", pos, valor);
				break;

			case 6:
				tamanho = size(lista);
				printf("Quantidade de elementos da lista: %d\n\n", tamanho);
				break;

			case 7:
				exibir(lista);
				break;

			default:
				printf("Comando invalido\n\n");
				break;
			}

		} while (opcao);

		free(lista);
		return 0;
	}
}
