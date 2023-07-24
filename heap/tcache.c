#include <stdio.h>
#include <stdlib.h>


int main()
{
    long long *ptr[7];
    long long *a = malloc(0x80);
	// 申请7个，释放7个，填满tcache bin[0x90]
    for (int i=0; i<7; i++)
        ptr[i] = malloc(0x80);
    for (int i=0; i<7; i++)
        free(ptr[i]);
    // 这里再释放a，就会放入到unsorted bin中
    free(a);
    printf("libc addr is %llx\n",  *(unsigned long long*)a);
    return 0;
}
