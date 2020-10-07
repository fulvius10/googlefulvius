/*
 * biblioteca.h
 *
 *  Created on: 20 de set de 2020
 *      Author:
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#define false 0
#define true 1
typedef int boolean;

void showMenu();
int validateInteger();
void validateRealNumber(float*);
float calculateNewSalary(float);
void fillArray(float*, int);
void fillNewSalaries(float*, int);
float calculateAverageSalaries(float*, int);

#endif /* BIBLIOTECA_H_ */
