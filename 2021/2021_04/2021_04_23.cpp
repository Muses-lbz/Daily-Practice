#include <stdio.h> 
#include <stdlib.h>

int main()
{
    int n = 0, i;
    for (i = 1; i <= 200; i++)
    {
        if ((i % 2 == 1) && (i % 3 == 1) && (i % 5 == 1))
        {
            n++;
            if (n < 10)
                printf("%d ", i);
            if (n == 10)
                break;
        }
    }
    system("pause");
    return 0;
}
