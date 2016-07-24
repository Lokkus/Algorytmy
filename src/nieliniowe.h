/*
 * nieliniowe.h
 *
 *  Created on: 17 lip 2016
 *      Author: lokkus
 */

#ifndef NIELINIOWE_H_
#define NIELINIOWE_H_

# define M_PI		3.14159265358979323846

double funkcja(double x);
void przedzial(double *a, double *b, double (*fun)(double));
void regula_falsi2(double(*fun)(double));
void bisekcja2(double (*fun)(double));

#endif /* NIELINIOWE_H_ */
