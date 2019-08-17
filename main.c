/*
*@Autor: Emmanuel Sampaio
**/
#include <stdio.h>
#include <stdlib.h>
#include "binlib.h"
/**
**
*\mainpage Description:
*Funções de manipulação de bits.Funções desenvolvidas 
*Set de bit,Reset de bit,Togglet de bit.Separação de bits e identificação de Little ou Big Endian.
*@date 17/08/2019
*@file  main.c
*@Autor Emmanuel Sampaio
*
*/
/*!
*@Brief É utilizado para fazer os testes da função.Para fazer os testes foi utilizado GDB observando linha a linha o comportamento das variáveis.
*
*/
int main(void) {
  /*!pointeiro utilizado para fazer os testes*/
  unsigned long *a;
  /*número utilizado para fazer os testes*/
  unsigned long numero=1;
  /*!posição do bit que vai ser operado*/
  unsigned char bitn='0';//O bit que vai ser utilizado no teste
  unsigned char bitstart='0';//O bit de início 
  unsigned char bitend='4';//posição final da função ReadBitSlice
  unsigned char valor1;//posição do bit que vai ser operado
  unsigned char valor2;//posição do bit final da função ReadBit
  unsigned long valor3;//Retorno da função ReadBitSlice
  a=&numero;
  unsigned long valor4=(*a&1<<0);
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