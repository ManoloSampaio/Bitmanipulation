/*
*@Autor: Emmanuel Sampaio
**/
#include <stdio.h>
#include <stdlib.h>
#include "binlib.h"
int main(void) {
  	unsigned long *a;
  	unsigned long numero=15;//Número que vai ser usado no test
  	unsigned char bitn='3';//O bit que vai ser utilizado no teste
  	unsigned char bitstart='0';//O bit de início 
  	unsigned char bitend='4';//O bit final da leitura
	unsigned char valor1;//Vai armazenar a informação que é retornada pela função IlLittleEndian();
  	unsigned char valor2;//Vai armazenar a informação que é retornada pela função ReadBit();
  	unsigned long valor3;//Vai armazenar a informação que é retornada pela função ReadBitSlice();
	a=&numero;
  	valor1 = IsLittleEndian();
  	valor2 = ReadBit(a,bitn);
  	ToggletBit(a,bitn);
	valor2 = ReadBit(a,bitn);
	SetBit(a,bitn);
	valor2 = ReadBit(a,bitn);
	ResetBit(a,bitn);
	valor2 = ReadBit(a,bitn);
	valor3 = ReadBitSlice(a,bitstart,bitend);
	return 0;
}
