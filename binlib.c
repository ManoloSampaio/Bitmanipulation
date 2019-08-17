/**
@brief Seta o bit da posição de memória apontada por p
@param p Ponteiro para variável de 32bits cujo bit será setado
@param bitn Posição do bit (0 a 31) a ser setado
*/
void SetBit(unsigned long *p, unsigned char bitn) {    
	int position = bitn - '0';//Posição do bit a ser setado  
	*p|=1<<position;//setando o bit da posição bitn
}
/**
@brief Reseta o bit da posição de memória apontada por p
@param p Ponteiro para variável de 32bits cujo bit será resetado
@param bitn Posição do bit (0 a 31) a ser resetado
*/
void ResetBit(unsigned long *p, unsigned char bitn){
	int position = bitn - '0';//Posição do bit a ser resetado
	*p&=~(1 << position);//Resetando o bit da posição bitn
}
	
/**
@brief Inverte um bit da posição de memória apontada por p
@param p Ponteiro para variável de 32bits cujo bit será invertido
@param bitn Posição do bit (0 a 31) a ser invertido
*/
void ToggletBit(unsigned long *p, unsigned char bitn){
	int position = bitn-'0';//Posição do bit a para Togglet
	*p^=(1<<position);//Realizando Togglet
}
/**
@brief Ler o bit da posição de memória apontada por p
@param p Ponteiro para variável de 32bits cujo bit será lido
@param bitn Posição do bit (0 a 31) a ser lido
@return retorna o estado (0 ou 1) do bit da posição de memória apontada por p
*/
unsigned char  ReadBit(unsigned long *p, unsigned char bitn){
	unsigned long valoranterior=*p;
	int position = bitn - '0';
	unsigned char resultado = *p & (1<<position);
	if (resultado =='0'){	
		return('0');
	}
	return('1');
}
/**
@brief Ler uma fatia de bits da posição bitstart até bitend
@param p Ponteiro para variável de 32bits de onde a fatia  de bits será lida
@param bitstart Posição do bit (0 a 31) do primeiro bit a ser lido
@param bitend Posição do bit (0 a 31) do último bit a ser lido
@return retorna os bits de bitstart até bitend
*/
unsigned long ReadBitSlice(unsigned long *p, unsigned char bitstart, unsigned char bitend){
	unsigned long retorno=0;//Binário que ira retornar
	int inicialposition = bitstart-'0';//Posição inicial
	int finalposition = bitend - '0';//Posição final 
	int j =0;//variável do laço,corresponde a posição do bit para retorno 
	for(int i=inicialposition;i<=finalposition;i++){
		resultado = *p & (1<<i);
		if(resultado =='0'){
			j = j+1;
		}
		else{
			retorno|=1<<j;
			j = j + +1;
		}
	}
	return retorno;
}
/**
@brief Detecta se a arquitetura corrente armazena os dados  em formato little endian ou big endian
@return Retorna 1 para Little endian e 0  para Big Endian
*/
/**
*Little endian=O número mais significativo vai estar no número de memória maior que o menos siginificativo
*Big endian = O número menos significativo vai estar armazenado de forma inversa ao Litlle Endian.
**/
unsigned char IsLittleEndian (void) { 
	unsigned long teste = 1;//Variável de teste
	if(*&teste==1){
		return('1');
	}
	else{
		return('0');
	}
}
