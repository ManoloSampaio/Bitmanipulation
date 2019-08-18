Questão ùnica: Desenvolva e teste, em ambiente linux, as funções cujos protótipos estão abaixo descritos. Aproveite a oportunidade para aprender a usar o programa gdb da gnu para fazer o debug em linha de comando, sem o uso da interface gráfica. Mais ainda, aprenda a gerar a documentação desta library gerada por você fazendo uso do programa doxygen. Atividade Extra Opcional: Pesquise sobre, e adote, um dos padrões de codificação Misra C ou Cert C para desenvolvimento de código para sistemas críticos de tempo real.

/**
@brief Seta o bit da posição de memória apontada por p
@param p Ponteiro para variável de 32bits cujo bit será setado
@param bitn Posição do bit (0 a 31) a ser setado
*/
void SetBit(unsigned long *p, unsigned char bitn) {    }

/**
@brief Reseta o bit da posição de memória apontada por p
@param p Ponteiro para variável de 32bits cujo bit será resetado
@param bitn Posição do bit (0 a 31) a ser resetado
*/
void ResetBit(unsigned long *p, unsigned char bitn) {    }

/**
@brief Inverte um bit da posição de memória apontada por p
@param p Ponteiro para variável de 32bits cujo bit será invertido
@param bitn Posição do bit (0 a 31) a ser invertido
*/
void ToggletBit(unsigned long *p, unsigned char bitn) {    }

/**
@brief Ler o bit da posição de memória apontada por p
@param p Ponteiro para variável de 32bits cujo bit será lido
@param bitn Posição do bit (0 a 31) a ser lido
@return retorna o estado (0 ou 1) do bit da posição de memória apontada por p
*/
unsigned char  ReadBit(unsigned long *p, unsigned char bitn) {    }

/**
@brief Ler uma fatia de bits da posição bitstart até bitend
@param p Ponteiro para variável de 32bits de onde a fatia  de bits será lida
@param bitstart Posição do bit (0 a 31) do primeiro bit a ser lido
@param bitend Posição do bit (0 a 31) do último bit a ser lido
@return retorna os bits de bitstart até bitend
*/
unsigned long  ReadBitSlice(unsigned long *p, unsigned char bitstart, unsigned char bitend) {    }

/**
@brief Detecta se a arquitetura corrente armazena os dados  em formato little endian ou big endian
@return Retorna 1 para Little endian e 0  para Big Endian
*/
unsigned char IsLittleEndian (void) { }

