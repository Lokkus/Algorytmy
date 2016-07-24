/*
 * nieliniowe.c
 *
 *  Created on: 17 lip 2016
 *      Author: lokkus
 */
#include "nieliniowe.h"
#include <math.h>
#include <stdio.h>


double funkcja(double x){
	return sin(2*x)+x - 2;
}

void przedzial(double *a, double *b, double (*fun)(double)){
	double m, n;
	int flag=1;
	for(*a = 1; *a<10; (*a)++){
		for(*b = 1; *b<10; (*b)++){
			m=fun(*a);
			n=fun(*b);
			if(n*m < 0){
				flag=0;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	printf("Przedzialy wynosza odpowiednio %4.3f oraz %4.3f\n", *a, *b);

}

void regula_falsi2(double(*fun)(double)){
	double a=1, b=1;
	przedzial(&a, &b, funkcja);
	double eps = 1e-7;
	double xk;
	int krok = 1;
	while(1){
		xk=(a*fun(b) - b*fun(a))/(fun(b) - fun(a));
		printf("Krok %d, wartosc xk = %8.7f,\t wartosc f(xk) = %8.7f\n",krok++, xk, fun(xk));

		if(fabs(fun(xk))< eps){
			break;
		}

		if((fun(a)*fun(xk))<0){
			b=xk;
		}
		else{
			a=xk;
		}
	}

	printf("Pierwiastek funkcji wynosi: %8.7f\n", xk);

}

void bisekcja2(double (*fun)(double)){
	double a=1, b=1;
	przedzial(&a, &b, fun);
	double m, n, xk, xk1, eps=1e-5, eps2=1e-7;
	int krok=1;

	while(1){
		xk = (a+b)/2;
		printf("Krok %d, xk wynosi: %6.5f", krok++, xk);
		m=fun(xk);
		printf("\t Wartosc funkcji f(xk) wynosi %7.6f\n", m);
		if(m == 0){
			break;
		}

		n=fun(a);

		if(m*n < 0){
			b=xk;
		}
		else{
			a=xk;
		}
		xk1 = xk;
		xk = (a+b)/2;

		if((fabs(xk1-xk)<eps) && (fabs(m))<eps2){
			break;
		}
	}
	printf("Miejsce zerowe funkcji wynosi %7.6f\n", xk1);

}
