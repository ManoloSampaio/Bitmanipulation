void SetBit(unsigned long *p, unsigned char bitn) {    
	int position = bitn - '0';
	*p|=1<<position;
}
void ResetBit(unsigned long *p, unsigned char bitn){
	int position = bitn - '0';
	*p&=~(1 << position);
}
void ToggletBit(unsigned long *p, unsigned char bitn){
	int position = bitn-'0';
	*p^=(1<<position);
}
unsigned char  ReadBit(unsigned long *p, unsigned char bitn){
	unsigned long valoranterior=*p;
	int position = bitn - '0';
	unsigned char resultado = *p & (1<<position);
	if (resultado =='0'){	
		return('0');
	}
	return('1');
}
unsigned long ReadBitSlice(unsigned long *p, unsigned char bitstart, unsigned char bitend){
	unsigned long retorno=0;
	int inicialposition = bitstart-'0';
	int finalposition = bitend - '0';
	int j =0;
	unsigned char resultado;
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
unsigned char IsLittleEndian (void) { 
	unsigned char IsLittleEndian (void) { 
	unsigned long teste = 1;
	if(*&teste==1){
		return('1');
	}
	else{
		return('0');
	}
}
