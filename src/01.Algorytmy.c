/*
 ============================================================================
 Name        : Algorytmy.c
 Author      : Lokkus
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void odw_string(char *tab){
	char *beg = tab;
	while(*(++tab)!='\0');
	while(*(tab--)!=*beg){
		printf("%c",*tab);
	}
}

void generator_liczb_pierwszych(int ile_liczb){
	int p=2;
	int flag = 0;
	int n=0;
	while(n<ile_liczb){
		for(int i = 2; i<p; i++){
			if(p%i ==0){
				flag=1;
				break;
			}
		}
		if(!flag){
			printf("%d, ",p);
			n++;
		}
		p++;
		flag = 0;
	}
}
void gen_l_p(int ile_liczb){
	int p=2;
	int flag = 0;
	int n = 0;
	int sq;
	int k = 1;
	int d = 1;

	while(n<ile_liczb){
		if(n<2){
			printf("%d, ",p);
			p++;
			n++;
		}
		else{
			if(d>0){
				d = -1;
			}
			else{
				d=-1;
			}
			p = 6*(k++) + d;
			sq = (int)sqrt(p);
			for(int j = 2; j<=sq; j++){
				if(!(p%j)){
					flag=1;
					break;
				}
			}
			if(!flag){
				printf("%d, ",p);
				n++;
			}
			flag=0;
		}
	}
}
int fibb_rek(int wyraz){
	if(wyraz<3)
		return 1;
	else
		return (fibb_rek(wyraz-2)+fibb_rek(wyraz-1));

}

void fibb_nor(int ile){
	int a=1;
	int b=0;
	printf("1, ");
	while(ile--){
		a=a+b;
		b=a-b;
		printf("%d, ", a);
	}
}

int main(void) {

	//for(int i = 1; i<=10; i++){
	//	printf("%d, ",fibb_rek(i));
	//}
	//fibb_nor(10);
	//generator_liczb_pierwszych(20);
	gen_l_p(20);


	return EXIT_SUCCESS;
}
