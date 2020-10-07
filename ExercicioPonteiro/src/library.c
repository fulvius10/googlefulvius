/*
 * library.c
 *
 *  Created on: 13 de set de 2020
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int solicitarTamanhoVetor() {
	float tamanhoVetor = 0.0;
	int tamanhoVetorValidado = 0;

	do {
		printf("Informe o tamanho do vetor: ");
		fflush(stdin);
		scanf("%f", &tamanhoVetor);

		if (tamanhoVetor != (int) tamanhoVetor) {
			printf("\n\nO tamanho do vetor deve ser número inteiro.\n");
			continue;
		}
		if (tamanhoVetor <= 0) {
			printf("\n\nO tamanho do vetor deve ser positivo.\n");
			continue;
		}

		tamanhoVetorValidado = (int) tamanhoVetor;
		break;
	} while (1);

	return tamanhoVetorValidado;
}

int* criarVetorDinamicamente(int tamanhoVetor) {
	if (tamanhoVetor >= 0)
		return  (int*) calloc(tamanhoVetor, sizeof(int));

	return NULL;
}

void preencherVetor(int* vetor, int tamanhoVetor) {
	int i = 0;

	for (i = 0; i < tamanhoVetor; i++) {
		printf("\nInforme o %iº valor: ", i + 1);
		fflush(stdin);
		scanf("%i", &vetor[i]);
	}

	for (i = 0; i < tamanhoVetor; i++) {
		if (i % 2 == 0)
			vetor[i] = vetor[i] * 2;
		else
			vetor[i] = vetor[i] / 2;
	}
}

void exibirResultado(int* vetor, int tamanhoVetor) {
	int i = 0;
	int somatorioValoresVetor = 0;

	printf("\n\nNOVO VETOR");
	for (i = 0; i < tamanhoVetor; i++) {
		printf("\nValor da posicão %i: %i", i + 1, vetor[i]);
		somatorioValoresVetor += vetor[i];
	}

	printf("\nSOMA DOS VALORES DO VETOR: %i", somatorioValoresVetor);
	free(vetor);
}
