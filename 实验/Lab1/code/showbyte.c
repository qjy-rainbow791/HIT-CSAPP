#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("hello.c", "r");
    if (file == NULL)
    {
        printf("未找到文件\n");
        exit(0);
    }
    char a[16];
    int i = 0, j;
    for (;; i++)
    {
        if ((fscanf(file, "%c", &a[i])) == EOF) break;
        if (i == 15)
        {
            for (j = 0; j < 16; j++)
            {
                if (a[j] == ' ')
                    printf("  SP");
                else if (a[j] == '\n')
                    printf("  \\n");
                else if (a[j] == '\r')
                    printf("  \\r");
                else
                    printf("%4c", a[j]);
            }
            printf("\n");
            for (j = 0; j < 16; j++)
            {
                printf("%4d", a[j]);
            }
            printf("\n");
            i = -1;
        }
    }
    for (j = 0; j < i; j++)
    {
        if (a[j] == ' ')
            printf("  SP");
        else if (a[j] == '\n')
            printf("  \\n");
        else if (a[j] == '\r')
            printf("  \\r");
        else
            printf("%4c", a[j]);
    }
    printf("\n");
    for (j = 0; j < i; j++)
    {
        printf("%4d", a[j]);
    }
    printf("\n\n");
    return 0;
}
