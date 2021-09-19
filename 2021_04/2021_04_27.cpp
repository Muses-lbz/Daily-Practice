#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c, d, e, f;
	int i = 1;
	for (a = 1; a < 7; a++)
	{
		for (b = 1; b < 7; b++)
		{
			for (c = 1; c < 7; c++)
			{
				for (d = 1; d < 7; d++)
				{
					for (e = 1; e < 7; e++)
					{
						for (f = 1; f < 7; f++)
						{
							if (a != b && a != c && a != d && a != e && a != f && b != c && b != d && b != e && b != f && c != d && c != e && c != f && d != e && d != f && e != f)
							{
								if (a + b + d == a + c + f && a + c + f == d + e + f)
								{
									printf("第%2d种情况：%d %d %d %d %d %d\n", i, a, b, c, d, e, f);
									i++;
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
