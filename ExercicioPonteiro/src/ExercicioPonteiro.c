/*
 ============================================================================
 Name        : ExercicioPonteiro.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(void) {
	setbuf(stdout, NULL);

	printf("-- EXERCÍCIO PONTEIRO --\n\n");

	int tamanhoVetor = solicitarTamanhoVetor();
	int* vetor = criarVetorDinamicamente(tamanhoVetor);

	preencherVetor(vetor, tamanhoVetor);
	exibirResultado(vetor, tamanhoVetor);

	free(vetor);
	printf("\n\n\nFim do programa.");

	return EXIT_SUCCESS;
}
