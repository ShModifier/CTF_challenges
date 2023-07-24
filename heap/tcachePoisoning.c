#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long localVariables ;
    printf("localVariables addr is %p\n", &localVariables);

    long long * ptr = malloc(0x80);
    printf("malloc ptr addr is %p\n", ptr);
    free(ptr);
    // 只需修改fd指针，申请的大小和当前tcache bin大小相同即可
    ptr[0] = (long long)&localVariables;
    malloc(0x80);
    printf("the second malloc addr is %p\n", malloc(0x80));

    return 0;
}
