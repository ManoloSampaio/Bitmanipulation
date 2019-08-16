/*
*@Autor: Emmanuel Sampaio
*@
*
**/
#include <stdio.h>
#include <stdlib.h>
#include "binlib.h"
int main(void) {
  	unsigned long *a,*b;
  	unsigned long var=7000;
  	unsigned char bitn='3';
  	a = &var;
  	//printf("%li \n",*a);
  	//printf("%c\n",ReadBit(a,bitn));
	ToggletBit(a,bitn);
	//printf("%li \n",*a);
	SetBit(a,bitn);
	//printf("%c\n",ReadBit(a,bitn));
	//printf("%li\n",*a);
	ResetBit(a,bitn);
	//printf("%li\n",*a);
 	//ResetBit(a,bitn);
	//printf("%c\n",ReadBit(a,bitn));
	//printf("%li\n",ReadBitSlice(a,'0','1'));
	char variable = IsLittleEndian();
	printf("%c",variable);
	unsigned long vara = 0x1000;
 	unsigned long *k=&vara;
	unsigned long resposta= *k;
	printf("%x\n",resposta);
	printf("%c",IsLittleEndian());
	return 0;
}