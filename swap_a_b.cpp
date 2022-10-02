#include "bit_operations.h"

int main()
{
    uint32_t a = 0xf4f3f2f1;
    uint32_t n = 3;
    uint32_t k = 1;
	printf("swap bytes %d and %d in %x\n", n, k, a);
    int rez = swap_bytes(a,n,k);
	printb(a);
	printb(rez);
    return 0;
}
