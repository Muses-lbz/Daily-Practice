//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//
//int main()
//{
//	int m,n,o;
//	srand((unsigned int)time(NULL));
//	m = rand() % 21;
//	n = rand() % 45;
//	o = rand() % 48;
//	if (m + n + o > 70)
//	{
//		printf("I Think...");
//	}
//	else 
//	{
//		printf("You Are A Stupid!");
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int fun(string str);
int main(void) 
{
    string str = "abc123 def45gh";
    cout << fun(str);
    return 0;
}

int fun(string str) 
{
    int index = -1;
    int score = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 48 && str[i] <= 57) && (i + 1 < str.length()) && (str[i + 1] >= 48 && str[i + 1] <= 57))
        {
            index = i;
            break;
        }
    }
    if (index == -1) 
    {
        return score;
    }
    score = str[index] - '0';
    for (unsigned int i = index + 1; i < str.length(); i++)
    {
        if (str[i] >= 48 && str[i] <= 57) 
        {
            score *= 10;
            score += str[i] - '0';
        }
        else {
            break;
        }
    }
    printf("%d\n\n", score);
    system("pause");
}