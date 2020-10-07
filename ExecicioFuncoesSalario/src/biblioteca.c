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

// Exerc�cio 1
void showMenu() {
	char option = '\0';

	do {
		printf("INFORME\nA- Resultado do exerc�cio 5 \nB- Finalizar");
		fflush(stdin);
		scanf("%c", &option);

		option = toupper(option);

		switch (option) {
		case 'A':
			printf("\n\n--- RESULTADO DO EXERC�CIO 5 ---\n");
			printf("\n--- TAMANHO DO VETOR ---\n");

			// Exerc�cio 5 - a
			int size = validateInteger();
			float* array = malloc(size * sizeof(float));
			fillArray(array, size);
			fillNewSalaries(array, size);
			printf("\nM�dia dos sal�rios: R$%.2f", calculateAverageSalaries(array, size));

			free(array);
			break;
		case 'B':
			printf("\n\n--- FIM DO PROGRAMA ---\n");
			break;
		default:
			printf("\nOp��o inv�lida.\n");
			break;
		}

		printf("\n\n");
	} while (option != 'B');
}

// Exerc�cio 2
int validateInteger() {
	boolean isInteger;
	float number = 0.0;

	do {
		isInteger = true;

		printf("\nInforme um n�mero inteiro positivo: ");
		fflush(stdin);
		scanf("%f", &number);

		if (number < 0) {
			printf("\nO n�mero deve ser positivo.");
			isInteger = false;
		}

		if (number != (int) number) {
			printf("\nO n�mero deve ser inteiro.");
			isInteger = false;
		}
	} while (!isInteger);

	return (int) number;
}

// Exerc�cio 3
void validarNumeroReal(float* number) {
	boolean isReal = false;

	do {
		isReal = true;

		printf("\nInforme um n�mero real positivo: ");
		fflush(stdin);
		scanf("%f", number);

		if ((*number) < 0) {
			printf("\nO n�mero deve ser positivo.");
			isReal = false;
		}
	} while (!isReal);
}

// Exerc�cio 4
float calculateNewSalary(float salary) {
	if (salary <= 1500.00)
		salary *= 1.10;
	else if (salary > 1500.00 && salary <= 5000.00)
		salary *= 1.05;

	return salary;
}

// Exerc�cio 5 - b
void fillArray(float* array, int size) {
	printf("\n-- VALORES DOS SAL�RIOS --");

	int i = 0;
	for (i = 0; i < size; i++) {
		printf("\n%i� SAL�RIO", i + 1);
		validarNumeroReal(array);
		array++;
	}

	array -= size;
}

// Exerc�cio 5 - c
void fillNewSalaries(float* array, int size) {
	printf("\n-- VALORES DOS NOVOS SAL�RIOS CALCULADOS --");
	int i = 0;
	for (i = 0; i < size; i++)
		array[i] = calculateNewSalary(array[i]);
}

// Exerc�cio 5 - d
float calculateAverageSalaries(float* array, int size) {
	printf("\n-- M�DIA DOS NOVOS SAL�RIOS CALCULADA --");

	float sum = 0;
	int i = 0;
	for (i = 0; i < size; i++)
		sum += array[i];

	return sum / size;
}
