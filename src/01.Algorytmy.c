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
void odw_string(char *tab){
	char *beg = tab;
	while(*(++tab)!='\0');
	while(*(tab--)!=*beg){
		printf("%c",*tab);
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
	fibb_nor(10);


	return EXIT_SUCCESS;
}
