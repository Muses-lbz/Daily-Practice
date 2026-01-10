#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	system("shutdown -s -t 50");
	//表示令计算机关机或者重新启动的命令，"-s"表示关机，"-r"表示重新启动,"-t  50"表示的是在50秒后关机。"-t"和"50之间有一个空格

	//system("shutdown -a");  
	//取消关机的命令
	return 0;
}
