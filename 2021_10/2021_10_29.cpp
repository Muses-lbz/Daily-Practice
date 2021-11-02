//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//    char s[85];
//    int score = 0, x;
//    gets_s(s);
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == 'X')
//            score += 0;
//        if (s[i] == 'O')
//        {
//            int temp = 1;
//            if (i == 0)score += 1;
//            else
//            {
//                x = i;
//                while (x > 0)
//                {
//                    if (s[x - 1] == 'O')temp++;
//                    else break;
//                    x--;
//                }
//                score += temp;
//            }
//        }
//    }
//    printf("%d\n", score);
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//#define  MSG  "I  am  a  symbolic  string  constant." 
//#define  MAXLENGTH  81
//
//int main()
//{
//	char words[MAXLENGTH] = "I  am  a  string  in  an  array.";
//	const char* pt1 = "Something is pointing at me."; 
//	puts("Here  are  some  strings:");
//	puts(MSG);
//	puts(words);
//	puts(pt1);
//	words[8] = 'p';
//	puts(words); 
//	return  0;
//}
//

//#include <stdio.h>
//#define  MSG  "I'm  special"
//
//int main()
//{
//	char  ar[] = MSG;
//	const char* pt = MSG;
//	printf("address of  \"I'm  special\":  %p \n",  "I'm  special"); 
//	printf("address ar:  %p\n",  ar); 
//	printf("address pt : % p\n", pt); 
//	printf("address of MSG : % p\n",  MSG);
//	printf("address  of  \"I'm  special\":  %p  \n", "I'm  special"); 
//	return  0;
//}
//

//#include <stdio.h> 
//#define  SLEN  40
//#define  LIM   5 
//
//int main()
//{
//	const char* mytalents[LIM] = {
//		"Adding  numbers  swiftly","Multiplying  accurately",
//		"Stashing  data",
//		"Following  instructions  to  the  letter",
//		"Understanding  the  C  language"
//	};
//	char  yourtalents[LIM][SLEN] = {
//		"Walking  in  a  straight  line",
//		"Sleeping",
//		"Watching  television",
//		"Mailing  letters",
//		"Reading  email"
//	};
//	int  i;
//	puts("Let's  compare  talents.");
//	printf("%-36s   %-25s\n", "My  Talents", "Your  Talents");
//	for (i = 0; i < LIM; i++)
//		printf("%-36s   %-25s\n", mytalents[i], yourtalents[i]);
//	printf("\nsizeof  mytalents:  %zd, sizeof  yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));
//	printf("%zd",sizeof(const char*));
//	return  0;
//}

#include <stdio.h> 

int main()
{
	const char* mesg = "Don't be a fool!";
	const char* copy;
	copy = mesg;
	printf("%s\n", copy);
	printf("mesg  =  %s;  &mesg  =  %p;  value  =  %p\n", mesg, &mesg, mesg);
	printf("copy  =  %s;  &copy  =  %p;  value  =  %p\n", copy, &copy, copy);
	return  0;
}

