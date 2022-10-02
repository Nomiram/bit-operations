#include <stdint.h>
#include <stdio.h>
//Битовые операции:
//Сделать первые k битов числа a нулями 
#define set_kzeroes(a,k) ((-1>>((k)))<<((k)))
// Поменять местами биты n и k в числе a
#define swap(a,n,k) (((a)&~(1 << (n))) & ~(1 << (k))) |\
 ((((a) >> (k)) & 1) << n) | ((((a) >> (n)) & 1) << (k))
// Обнулить биты с n по k в числе a
#define set_zeroes(a,n,k) ((a) & ((((long long)-1>>((k)))<<((k))) |\
 ~(((long long)-1>>((n)))<<((n)))))
// Поменять местами байты n и k в 32 битном числе a
#define swap_bytes(a,n,k) set_zeroes(set_zeroes(a,k*8,k*8+8),n*8,n*8+8)|\
((((a) >> (k*8)) & 0xff) << n*8) | ((((a) >> (n*8)) & 0xff) << (k*8))

// Побитовая печать числа x
void printb(uint32_t x);

// Побитовая печать числа x
void printb(uint32_t x){
	for (int i = (sizeof(x)*8)-1; i>=0; i--){
		if ((i+1)%8 == 0 and i!=(sizeof(x)*8)-1) printf(" ");
		printf("%d",x >> i & 1);
	}
	printf("\n");
}