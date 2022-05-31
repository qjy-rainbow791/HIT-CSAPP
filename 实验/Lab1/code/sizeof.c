#include <stdio.h>

int main()
{
    printf("char:\t\t%lubyte\n", sizeof(char));
    
    printf("short:\t\t%lubyte\n", sizeof(short));
    printf("int:\t\t%lubyte\n",sizeof(int));
    printf("long:\t\t%lubyte\n", sizeof(long));
    printf("long long:\t%lubyte\n", sizeof(long long));

    printf("float:\t\t%lubyte\n", sizeof(float));
    printf("double:\t\t%lubyte\n", sizeof(double));
    printf("long double:\t%lubyte\n", sizeof(long double));

    printf("÷∏’Î:\t\t%lubyte\n", sizeof(void*));
    
    return 0;
}