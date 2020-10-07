/*
 * biblioteca.c
 *
 *  Created on: 20 de set de 2020
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"

// Exercício 1
void showMenu() {
	char option = '\0';

	do {
		printf("INFORME\nA- Resultado do exercício 5 \nB- Finalizar");
		fflush(stdin);
		scanf("%c", &option);

		option = toupper(option);

		switch (option) {
		case 'A':
			printf("\n\n--- RESULTADO DO EXERCÍCIO 5 ---\n");
			printf("\n--- TAMANHO DO VETOR ---\n");

			// Exercício 5 - a
			int size = validateInteger();
			float* array = malloc(size * sizeof(float));
			fillArray(array, size);
			fillNewSalaries(array, size);
			printf("\nMédia dos salários: R$%.2f", calculateAverageSalaries(array, size));

			free(array);
			break;
		case 'B':
			printf("\n\n--- FIM DO PROGRAMA ---\n");
			break;
		default:
			printf("\nOpção inválida.\n");
			break;
		}

		printf("\n\n");
	} while (option != 'B');
}

// Exercício 2
int validateInteger() {
	boolean isInteger;
	float number = 0.0;

	do {
		isInteger = true;

		printf("\nInforme um número inteiro positivo: ");
		fflush(stdin);
		scanf("%f", &number);

		if (number < 0) {
			printf("\nO número deve ser positivo.");
			isInteger = false;
		}

		if (number != (int) number) {
			printf("\nO número deve ser inteiro.");
			isInteger = false;
		}
	} while (!isInteger);

	return (int) number;
}

// Exercício 3
void validarNumeroReal(float* number) {
	boolean isReal = false;

	do {
		isReal = true;

		printf("\nInforme um número real positivo: ");
		fflush(stdin);
		scanf("%f", number);

		if ((*number) < 0) {
			printf("\nO número deve ser positivo.");
			isReal = false;
		}
	} while (!isReal);
}

// Exercício 4
float calculateNewSalary(float salary) {
	if (salary <= 1500.00)
		salary *= 1.10;
	else if (salary > 1500.00 && salary <= 5000.00)
		salary *= 1.05;

	return salary;
}

// Exercício 5 - b
void fillArray(float* array, int size) {
	printf("\n-- VALORES DOS SALÁRIOS --");

	int i = 0;
	for (i = 0; i < size; i++) {
		printf("\n%iº SALÁRIO", i + 1);
		validarNumeroReal(array);
		array++;
	}

	array -= size;
}

// Exercício 5 - c
void fillNewSalaries(float* array, int size) {
	printf("\n-- VALORES DOS NOVOS SALÁRIOS CALCULADOS --");
	int i = 0;
	for (i = 0; i < size; i++)
		array[i] = calculateNewSalary(array[i]);
}

// Exercício 5 - d
float calculateAverageSalaries(float* array, int size) {
	printf("\n-- MÉDIA DOS NOVOS SALÁRIOS CALCULADA --");

	float sum = 0;
	int i = 0;
	for (i = 0; i < size; i++)
		sum += array[i];

	return sum / size;
}
