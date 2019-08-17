/*!
*@file binlib.c
*@Autor Emmanuel Sampaio
*@Date 17/08/2019
*/
/*! 
*@brief Seta o bit da posição de memória apontada por p
*@param p Ponteiro para variável de 32bits cujo bit será setado
*@param bitn Posição do bit (0 a 31) a ser setado
*/
/*! 
*Exemplo do funcionamento da função:*p=3,que é 00000...00111.Seja bitn =3.Assim,1<<bitn =0000..1000.Fazendo
*000...00111 Or 000...1000 = 0000....01111.Assim setamos o bit da posição 3.
*/
void SetBit(unsigned long *p, unsigned char bitn) {    
	int posicao = bitn-'0';/*!posicao< Variável que define a posicao fazendo uma espécie de casting da posição que antes era unsigned char  */
	*p|=(1<<posicao);/*!p|=(1<<posicao)<*Usando Or para setar o bit na posição bitn*/
}
/*! 
*@brief Reseta o bit da posição de memória apontada por p
*@param p Ponteiro para variável de 32bits cujo bit será resetado
*@param bitn Posição do bit (0 a 31) a ser resetado
*/
/*! 
* Exemplo do funcionamento da função:*p=4,que é 000...00100.Seja bitn = 2.Assim,1<<bitn = 0000...100.Fazendo o inverso de 1<<bitn temos=1111...0111,assim:
*000.00100 and 1111...11011 = 000....0000.Restando o bit da posição 2.
*/
void ResetBit(unsigned long *p, unsigned char bitn){
	int posicao = bitn-'0';/*!posicao< Variável que define a posicao fazendo uma espécie de casting da posição que antes era unsigned char  */
	*p&=~(1 <<posicao );/*!*p&=~(1 <<posicao ) Usando "NAnd" para setar o bit na posição bitn **/
}
/*! 
*@brief Inverte um bit da posição de memória apontada por p
*@param p Ponteiro para variável de 32bits cujo bit será invertido
*@param bitn Posição do bit (0 a 31) a ser invertido
*/
/*! 
*Exemplo: *p=1,que é 0000...001.bitn=1,então é esperado realizar o Togglet na posição 1.
* 1<<1 = .0000000010. 0.000001 Xor 000000....010 = 0...00000011.
*/
void ToggletBit(unsigned long *p, unsigned char bitn){
	int posicao = bitn-'0';/*!< Variável que define a posicao fazendo uma espécie de casting da posição que antes era unsigned char  */
    *p ^= 1 << posicao;/*!< *p ^= 1 << posicao Fazendo o Toggle de bit utilizando bit XoR 1.*/ 
}
/*! 
*@brief Ler o bit da posição de memória apontada por p
*@param p Ponteiro para variável de 32bits cujo bit será lido
*@param bitn Posição do bit (0 a 31) a ser lido
*@return retorna o estado (0 ou 1) do bit da posição de memória apontada por p
*/
/*! 
*Exemplo: *p = 15, que é 0....01111.bitn = 3,então é esperado ler 1.
*1<<3 = 0.....1000., 0....01111 And 0.....1000 = 00000.....1000.Logo ele vai retornar 1.
*/
unsigned char ReadBit(unsigned long *p, unsigned char bitn){
    int posicao =bitn-'0';/*!bitn < Variável que define a posicao fazendo uma espécie de casting da posição que antes era unsigned char  */
    unsigned long resultado = (*p &1<<posicao);/*!resultado armazena o número que saiu do *p and posicao*/
    if (resultado == 0){	
		return('0');
	}
	else{
	    return('1');
	}
}
/*! 
*@brief Ler uma fatia de bits da posição bitstart até bitend
*@param p Ponteiro para variável de 32bits de onde a fatia  de bits será lida
*@param bitstart Posição do bit (0 a 31) do primeiro bit a ser lido
*@param bitend Posição do bit (0 a 31) do último bit a ser lido
*@return retorna os bits de bitstart até bitend
*/
/*! Como funciona o método: dado o número "apontado" por p,realizamos a leitura de cada um dos bits
 * da posição inicial,indicada por bitstart,até a posição final indicada por bitend.Usamos And para comparar o bit com 1 e assim
 * definimos se o bit lido é 1 ou 0 e assim,setamos um bit de retorno,caso o bit lido seja um ou mantemos zerado,caso o bit lido
 * seja 0.
 */
unsigned long ReadBitSlice(unsigned long *p, unsigned char bitstart, unsigned char bitend){
	unsigned long retorno=0;/*!<Binário que ira retornar*/
	int inicialposition = bitstart-'0';/*!incialposition<Posição inicial convertida para inteiro*/
	int finalposition = bitend - '0';/*!finalposition<Posição final convertida para inteiro*/
	int j =0;/*!j<Indica a posição (0 a 31) bit da variável retorno*/ 
	for(int i=inicialposition;i<=finalposition;i++){
		if( (*p & (1<<i)) == 0){
			j = j+1;
		}
		else{
			retorno|=1<<j;
			j = j + +1;
		}
	}
	return retorno;
}
/*! 
@brief Detecta se a arquitetura corrente armazena os dados  em formato little endian ou big endian
@return Retorna 1 para Little endian e 0  para Big Endian
*/
/*! 
*Little endian=O número mais significativo vai estar no número de memória maior que o menos siginificativo\\
*Big endian = O número menos significativo vai estar armazenado de forma inversa ao Litlle Endian.
*Exemplo: número 1.Ponteiro ira apontar para 1 caso seja Little Endian,pois o ponteiro aponta para o espaço da memória de menor endereço
*Caso retorne 0 temos o número apontando para o espaço da memória de maior indereço,assim temos Big Endian.
**/
unsigned char IsLittleEndian (void) { 
	unsigned long teste = 0x01020304;
	void *a = &teste;
	char * ch = (char *)a;
	printf("%li\n",*ch);
	if((*ch)==4){
		return('1');
	}
	else{
		return('0');
	}
}