#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;

struct person
{
    char id[20];
    char name[20];
    int s1, s2, s3;
    int sum;
    double ave;
} p[100];

int main()
{
	int i;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i].sum = 0;
		scanf_s("%s", p[i].id, n);
		scanf_s("%s", p[i].name, n);
		scanf_s("%d", &p[i].s1);
		scanf_s("%d", &p[i].s2);
		scanf_s("%d", &p[i].s3);
		p[i].sum += p[i].s1 + p[i].s2 + p[i].s3;
		p[i].ave = p[i].sum / 3.00;
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %s %d %d %d %.2f\n", p[i].id, p[i].name, p[i].s1, p[i].s2, p[i].s3, p[i].ave);
	}
	system("pause");
	return 0;
}

