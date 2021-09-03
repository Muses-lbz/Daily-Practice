#include <stdio.h>
#include <stdlib.h>

struct people
{
	char name[20];
	char gander[20];
	int age;
	int height;
	double weight;
	char introduction[20];
};

int main()
{
	struct people myself = { "蔺兵姿","Male",19,181,70.0,"Beautiful girl" };
	printf("姓名:%s\n", myself.name);
	printf("性别:%s\n", myself.gander);
	printf("年龄:%d岁\n", myself.age);
	printf("身高:%dcm\n", myself.height);
	printf("体重:%.1fkg\n", myself.weight);
	printf("爱好:%s\n\n", myself.introduction);
	system("pause");
	return 0;
}
