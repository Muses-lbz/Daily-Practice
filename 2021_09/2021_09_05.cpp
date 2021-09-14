#include <stdio.h>
#include <stdlib.h>

int myAtoi(char* str)
{
	int i = 0;
	int sign = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == NULL)
		return 0;
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '+')
	{
		sign = 0;
		i++;
	}
	else if (str[i] < '0')
	{
		return 0;
	}
	else if (str[i] > '9')
	{
		return 0;
	}
	long long int r = 0;
	while (str[i])
	{
		if (str[i] < '0')
			break;
		else if (str[i] > '9')
			break;
		else
			r = r * 10 + str[i++] - '0';
		if (r > INT_MAX)
			break;
	}
	r = sign ? -r : r;
	if (r < INT_MIN)
		return INT_MIN;
	if (r > INT_MAX)
		return INT_MAX;
	return (int)r;

}

int main()
{
	char* str;

	system("pause");
	return 0;
}
