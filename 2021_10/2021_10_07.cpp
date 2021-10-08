#include <stdio.h>
#include <stdlib.h>
//CSDN的垃圾代码 还是无法成功运行

typedef struct node
{
    char x;
    node* next;
} LList;

int main()
{
    LList* header = NULL;
    node* p;
    int n;
    scanf_s("%d", &n);
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        if (!header)
        {
            header = (node*)malloc(sizeof(node));
            p = header;
            scanf_s("%c", &(header->x));
            header->next = NULL;
        }
        else
        {
            p->next = (node*)malloc(sizeof(node));
            p = p->next;
            scanf_s("%c", &(p->x));
            p->next = NULL;
        }
    }
    p = header;
    int i = 0;
    while (p)
    {
        if (i++ % 2 == 0)
            printf("%c", p->x);
        p = p->next;
    }
    return 0;
}