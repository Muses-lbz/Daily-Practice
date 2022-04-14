//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<time.h>
//#include<conio.h>
//#include<Windows.h>
//
//void update(int array[4][4]);
//void randTwo(int array[4][4]);
//int hasEmpty(int array[4][4]);
//int isFull(int array[4][4]);
//void slide(char c, int array[4][4]);
//
//// 分数
//static int score = 0;
//// 最大分数
//static int maxScore = 0;
//
////标志是否进行了某种操作
//int operate = 1;
//
//int main() {
//
//	int array[4][4] = { 0 };
//	char c = ' ';
//	while (true) {
//		if (hasEmpty(array) == 1 && operate == 1) {
//			randTwo(array);
//		}
//		update(array);
//		if (hasEmpty(array) == 0 && isFull(array) == 1) {
//			break;
//		}
//		Sleep(400);
//		c = _getch();
//		if (c == 'q' || c == 'Q')
//			exit(0);
//		while (c != 'w' && c != 'W' && c != 's' && c != 'S' && c != 'd' && c != 'D' && c != 'a' && c != 'A') {
//			c = _getch();
//		}
//		slide(c, array);
//		system("cls");
//	}
//	printf("\n失败!");
//	system("pause");
//}
//
//// 更新页面,生成页面信息
//void update(int array[4][4]) {
//	printf("GAME: 2048\tScore:%d", score);
//	printf("\t\tBEST:%d", maxScore);
//	printf("\n---------------------------------------\n");
//	for (int j = 0; j < 4; j++) {
//		printf(" ________");
//	}
//	printf("\n");
//	for (int i = 0; i < 4; i++) {
//
//		for (int j = 0; j < 4; j++) {
//			printf("|        ");
//		}
//		printf("|\n");
//		for (int j = 0; j < 4; j++) {
//			if (array[i][j] == 0) {
//				printf("|        ");
//			}
//			else {
//				//按从上至下的顺序打印二维数组
//				printf("| %4d   ", array[i][j]);
//			}
//		}
//		printf("|\n");
//		for (int j = 0; j < 4; j++) {
//			printf("|________");
//		}
//		printf("|\n");
//	}
//	printf("\n---------------------------------------\n");
//	printf("【W】:UP 【S】:DOWN 【A】:LEFT 【D】:RIGHT 【Q】:EXIT");
//}
//
//// 随机生成2
//void randTwo(int array[4][4]) {
//	//以时间为种子，生成随机数
//	srand((unsigned)time(NULL));
//	int i = abs(rand() % 4);
//	int j = abs(rand() % 4);
//	//不能在已经是大于0的位置生成2
//	while (array[i][j] != 0) {
//		i = abs(rand() % 4);
//		j = abs(rand() % 4);
//	}
//	array[i][j] = 2;
//}
//
//// 判断区域内是否有空位置
//int hasEmpty(int array[4][4]) {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (array[i][j] == 0) {
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//
//// 判断是否已经满位置且不可合并，即游戏结束
//int isFull(int array[4][4]) {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			for (int k = 0; k < 4; k++) {
//				if (array[i][j] == array[i][k] || array[i][j] == array[k][j]) {
//					return 0;
//				}
//			}
//		}
//	}
//	return 1;
//}
//
/* 判断最近的除了空位置的两个格子能否相加
//int isAvaliableAdd(int i, int j) {
//	if (i == j) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}*/
//void slide(char c, int array[4][4]) {
//	if (c == 'a' || c == 'A') {
//		operate = 0;
//		//扫描开始
//		for (int i = 0; i < 4; i++) {
//			//同一行的操作次数
//			int op = 0;
//			//特殊情况
//
//
//			if (array[i][0] != 0 && array[i][2] != 0 && array[i][0] == array[i][1] && array[i][2] == array[i][3]) {
//				array[i][0] *= 2;
//				array[i][1] = array[i][2] * 2;
//				array[i][2] = 0;
//				array[i][3] = 0;
//				continue;
//			}
//			for (int j = 0; j < 4; j++) {
//				int k = j;
//				//当左边存在0时，向左移动
//				while (k > 0 && array[i][k] > 0 && array[i][k - 1] == 0) {
//					array[i][k - 1] = array[i][k];
//					array[i][k] = 0;
//					k--;
//					operate = 1;
//				}
//				//k = j;
//				//判断相邻的两个是否相等，相等即向左移动
//				if (k > 0 && array[i][k] == array[i][k - 1] && op == 0) {
//					if (array[i][k] != 0) {
//						operate = 1;
//						score += array[i][k];
//						op++;
//					}
//					array[i][k - 1] *= 2;
//					array[i][k] = 0;
//				}
//			}
//		}
//		/*
//		//为了防止出现的bug，从右边再扫描一次
//		for (int i = 0; i<4; i++) {
//			for (int j = 3; j>=0; j--) {
//				int k = j;
//
//				while (k>0 && array[i][k - 1] == 0) {
//					array[i][k - 1] = array[i][k];
//					array[i][k] = 0;
//					k--;
//				}
//				k = j;
//				//判断相邻的两个是否相等，相等即向左移动
//				while (k>0 && array[i][k] == array[i][k - 1]) {
//					if (array[i][k] != 0) {
//						score += array[i][k];
//					}
//					array[i][k - 1] *= 2;
//					array[i][k] = 0;
//					k--;
//				}
//			}
//		}
//		*/
//
//	}
//	else if (c == 'd' || c == 'D') {
//		operate = 0;
//		for (int i = 0; i < 4; i++) {
//			//同一行的操作次数
//			int op = 0;
//			//特殊情况
//			if (array[i][0] != 0 && array[i][1] != 0 && array[i][2] != 0 && array[i][0] == array[i][1] && array[i][2] == array[i][3]) {
//				array[i][3] *= 2;
//				array[i][2] = array[i][1] * 2;
//				array[i][1] = 0;
//				array[i][0] = 0;
//				continue;
//			}
//			for (int j = 3; j >= 0; j--) {
//				int k = j;
//
//				while (k < 3 && array[i][k] > 0 && array[i][k + 1] == 0) {
//					array[i][k + 1] = array[i][k];
//					array[i][k] = 0;
//					k++;
//					operate = 1;
//				}
//				//k = j;
//				//判断相邻的两个是否相等，相等即向右移动
//				if (k < 3 && array[i][k] == array[i][k + 1] && op == 0) {
//					if (array[i][k] != 0) {
//						operate = 1;
//						score += array[i][k];
//						op++;
//					}
//					array[i][k + 1] *= 2;
//					array[i][k] = 0;
//
//				}
//			}
//		}
//		/*
//		for (int i = 0; i<4; i++) {
//			for (int j = 0; j <4; j++) {
//				int k = j;
//
//				while (k<3 && array[i][k + 1] == 0) {
//
//					array[i][k + 1] = array[i][k];
//					array[i][k] = 0;
//					k++;
//				}
//				k = j;
//				//判断相邻的两个是否相等，相等即向右移动
//				while (k<3 && array[i][k] == array[i][k + 1]) {
//					if (array[i][k] != 0) {
//						score += array[i][k];
//					}
//					array[i][k + 1] *= 2;
//					array[i][k] = 0;
//					k++;
//				}
//			}
//		}
//		*/
//	}
//
//	else if (c == 'w' || c == 'W') {
//		operate = 0;
//		for (int j = 0; j < 4; j++) {
//
//			//特殊情况，同一列4个数完全相同
//			if (array[0][j] != 0 && array[0][j] == array[1][j] && array[2][j] == array[3][j]) {
//				array[0][j] *= 2;
//				array[1][j] = array[2][j] * 2;
//				array[2][j] = 0;
//				array[3][j] = 0;
//				continue;
//			}
//			//同一列的操作次数
//			int op = 0;
//			for (int i = 0; i < 4; i++) {
//				int k = i;
//				while (k > 0 && array[k][j] > 0 && array[k - 1][j] == 0) {
//					array[k - 1][j] = array[k][j];
//					array[k][j] = 0;
//					k--;
//					operate = 1;
//				}
//				//k = i;
//				//判断相邻的两个是否相等，相等即向上移动
//				if (k > 0 && array[k][j] == array[k - 1][j] && op == 0) {
//					if (array[k][j] != 0) {
//						score += array[k][j];
//						operate = 1;
//						op++;
//					}
//					array[k - 1][j] *= 2;
//					array[k][j] = 0;
//				}
//			}
//		}
//		/*
//		for (int i = 3; i >=0; i--) {
//			for (int j = 0; j<4; j++) {
//				int k = i;
//
//				while (k>0 && array[k - 1][j] == 0) {
//					array[k - 1][j] = array[k][j];
//					array[k][j] = 0;
//					k--;
//				}
//				k = i;
//				//判断相邻的两个是否相等，相等即向上移动
//				while (k>0 && array[k][j] == array[k - 1][j]) {
//					if (array[k][j] != 0) {
//						score += array[k][j];
//					}
//					array[k - 1][j] *= 2;
//					array[k][j] = 0;
//					k--;
//				}
//			}
//		}*/
//
//	}
//	else if (c == 's' || c == 'S') {
//		operate = 0;
//		for (int j = 3; j >= 0; j--) {
//			//特殊情况
//			if (array[0][j] != 0 && array[0][j] == array[1][j] && array[2][j] == array[3][j]) {
//				array[2][j] = array[1][j] * 2;
//				array[1][j] = 0;
//				array[0][j] = 0;
//				array[3][j] *= 2;
//				continue;
//			}
//			int op = 0;
//			for (int i = 3; i >= 0; i--) {
//				int k = i;
//
//				while (k < 3 && array[k][j] > 0 && array[k + 1][j] == 0) {
//					array[k + 1][j] = array[k][j];
//					array[k][j] = 0;
//					k++;
//					operate = 1;
//				}
//				//k = i;
//				//判断相邻的两个是否相等，相等即向下移动
//				if (k < 3 && array[k][j] == array[k + 1][j] && op == 0) {
//					if (array[k][j] != 0) {
//						score += array[k][j];
//						operate = 1;
//						op++;
//					}
//					array[k + 1][j] *= 2;
//					array[k][j] = 0;
//				}
//			}
//		}
//		/*
//		for (int i = 0; i<4; i++) {
//			for (int j = 0; j<4; j++) {
//				int k = i;
//
//				while (k<3&&array[k + 1][j] == 0) {
//					array[k + 1][j] = array[k][j];
//					array[k][j] = 0;
//					k++;
//				}
//				k = i;
//				//判断相邻的两个是否相等，相等即向下移动
//				while (k<3&&array[k][j] == array[k + 1][j]) {
//					if (array[k][j] != 0) {
//						score += array[k][j];
//					}
//					array[k + 1][j] *= 2;
//					array[k][j] = 0;
//					k++;
//				}
//			}
//		}
//		*/
//	}
//
//}
//
/* 滑动之后的结果判定
//void slideResult(char c, int array[4][4]) {
//		slide(c, array);
//
//}*/

#include<iostream>
#include<ctime>
#include<iomanip>
#include<conio.h>
#include <stdlib.h>

//游戏的行列格数（超过10时需要修改位置读取函数
#define COL 4
#define ROW 4
//新出现的数字为2的比例
#define RATIO 0.9
int real_time_mark;//即时总分
int best_score = 0;//最佳分数
bool ifPlaying = true;//记录游戏是否正在进行

					  //定义一个函数和用来打印表格
void printMe(int table[ROW][COL])
{
	system("cls");
	printf("\n\n           Game:2048                SCORE:%6d             BEST:%6d\n", real_time_mark, best_score);
	printf("----------------------------------------------------------------------------------------\n\n\n");
	printf("\n                   -----------------------------------------\n");
	for (int n = 0; n < ROW; n++)
	{
		printf("                   |");
		for (int m = 0; m < COL; m++)
		{
			if (table[n][m] == 0) {
				printf("         |");
			}
			else {
				//按从上至下的顺序打印二维数组
				printf("%8d |", table[n][m]);
			}

			if (m == COL - 1)
				printf("\n                   -----------------------------------------\n");
		}
	}
	printf("\n\n----------------------------------------------------------------------------------------\n\n\n");
	printf("Press Q to quit.");
}

//检查是否已经无法移动，游戏结束
bool gameOverCheck(int table[ROW][COL])
{
	bool ifFull = true;
	for (int m = 0; m < ROW; m++)
	{
		for (int n = 0; n < COL; n++)
		{
			if (table[m][n] == 0)
			{
				ifFull = false;
			}
		}
	}
	if (ifFull) {
		bool ifCannotMove = true;
		for (int m = 0; m < ROW; m++)
		{
			for (int n = 0; n < COL - 1; n++)
			{
				if (table[m][n] == table[m][n + 1])
				{
					ifCannotMove = false;
				}
			}
		}
		for (int n = 0; n < COL; n++)
		{
			for (int m = 0; m < ROW - 1; m++)
			{
				if (table[m][n] == table[m + 1][n])
				{
					ifCannotMove = false;
				}
			}
		}
		if (ifCannotMove)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//游戏结束界面
void printGameOver()
{
	ifPlaying = false;
	system("cls");
	printf("\n\n\n              Game    Over   !!!\n\n\n              Your Score:%d\n\n\n              press r to restart, press any other button to exit  !!!", real_time_mark);
	if (best_score < real_time_mark)
	{
		best_score = real_time_mark;
		printf("\n\n\n              You had broke the record      !!!\n\n\n              Congratulations!!!");
	}
}

//控制分数增加，每一次得分时调用
void addToMark(int addition)
{
	real_time_mark += addition;
}

//规定新出现的数字的大小
int createNewNum()
{
	if (rand() / (RAND_MAX + 1.0) < RATIO)
	{
		return 2;
	}
	else
	{
		return 4;
	}
}

//确定新出现数字的位置
int locateNewNum(int table[ROW][COL])
{
	while (true) {
		for (int n = 0; n < ROW; n++)
		{
			if (rand() / (RAND_MAX + 1.0) > 0.8)
			{
				for (int m = 0; m < COL; m++)
				{
					if (table[n][m] == 0)
					{
						if (rand() / (RAND_MAX + 1.0) > 0.8)
						{
							return (n * 10 + m);
						}
					}
				}
			}
		}
	}
}

//解码字符中储存的位置的X坐标
int getNewNumX(int code)
{
	return code / 10;
}

//解码字符中储存的位置的Y坐标
int getNewNumY(int code)
{
	return (code - (code / 10) * 10);
}

//接受到上键时的操作
void whenUp(int table[ROW][COL])
{
	bool ifMove = false;
	//循环处理格网中的每一列
	for (int n = 0; n < COL; n++)
	{
		int temp = 0;
		//存放更新后的某列
		int newCol[ROW] = { 0 };
		int count = 0;
		//循环处理列中每一个数
		for (int m = 0; m < ROW; m++)
		{
			if (table[m][n] != 0)
			{
				if (temp != 0 && temp == table[m][n]) {
					newCol[count - 1] = 2 * temp;
					addToMark(2 * temp);
					temp = 0;
					ifMove = true;
				}
				else
				{
					temp = table[m][n];
					newCol[count] = temp;
					if (m != count) {
						ifMove = true;
					}
					count++;
				}
			}
		}
		for (int m = 0; m < ROW; m++)
		{
			table[m][n] = newCol[m];
		}
	}
	if (ifMove) {
		char location = locateNewNum(table);
		table[getNewNumX(location)][getNewNumY(location)] = createNewNum();
		printMe(table);
		if (gameOverCheck(table))
		{
			printGameOver();
		}
	}
}

//接受到下键的操作
void whenDown(int table[ROW][COL])
{
	bool ifMove = false;
	for (int n = 0; n < COL; n++)
	{
		int temp = 0;
		//存放更新后的某列
		int newCol[ROW] = { 0 };
		int count = 0;
		//将该列倒序
		int adverseCol[ROW] = { 0 };
		for (int m = 0; m < ROW; m++) {
			adverseCol[ROW - 1 - m] = table[m][n];
		}
		//处理该列中的每一个数
		for (int m = 0; m < ROW; m++)
		{
			if (adverseCol[m] != 0)
			{
				if (temp != 0 && temp == adverseCol[m])
				{
					newCol[count - 1] = 2 * temp;
					addToMark(2 * temp);
					temp = 0;
					ifMove = true;
				}
				else
				{
					temp = adverseCol[m];
					newCol[count] = temp;
					if (m != count) {
						ifMove = true;
					}
					count++;
				}

			}
		}
		for (int m = 0; m < ROW; m++)
		{
			table[ROW - 1 - m][n] = newCol[m];
		}
	}
	if (ifMove) {
		char location = locateNewNum(table);
		table[getNewNumX(location)][getNewNumY(location)] = createNewNum();
		printMe(table);
		if (gameOverCheck(table))
		{
			printGameOver();
		}
	}
}

//接受到右键的操作
void whenRight(int table[ROW][COL])
{
	bool ifMove = false;
	//循环处理个网中的每一行
	for (int m = 0; m < ROW; m++)
	{
		int temp = 0;
		int newRow[COL] = { 0 };
		int count = 0;
		//将该行倒序
		int adverseRow[COL] = { 0 };
		for (int n = 0; n < COL; n++)
		{
			adverseRow[COL - 1 - n] = table[m][n];
		}
		//循环处理行中的每一个数
		for (int n = 0; n < COL; n++)
		{
			if (adverseRow[n] != 0)
			{
				if (temp != 0 && temp == adverseRow[n])
				{
					newRow[count - 1] = 2 * temp;
					addToMark(2 * temp);
					temp = 0;
					ifMove = true;
				}
				else
				{
					temp = adverseRow[n];
					newRow[count] = temp;
					if (n != count) {
						ifMove = true;
					}
					count++;
				}
			}
		}
		for (int n = 0; n < COL; n++)
		{
			table[m][COL - 1 - n] = newRow[n];
		}
	}
	if (ifMove) {
		char location = locateNewNum(table);
		table[getNewNumX(location)][getNewNumY(location)] = createNewNum();
		printMe(table);
		if (gameOverCheck(table))
		{
			printGameOver();
		}
	}
}

//接受到左键时的操作
void whenLeft(int table[ROW][COL])
{
	bool ifMove = false;
	//循环处理个网中的每一行
	for (int m = 0; m < ROW; m++)
	{
		int temp = 0;
		int newRow[COL] = { 0 };
		int count = 0;
		//循环处理行中的每一个数
		for (int n = 0; n < COL; n++)
		{
			if (table[m][n] != 0)
			{
				if (temp != 0 && temp == table[m][n]) {
					newRow[count - 1] = 2 * temp;
					addToMark(2 * temp);
					temp = 0;
					ifMove = true;
				}
				else
				{
					temp = table[m][n];
					newRow[count] = temp;
					if (n != count) {
						ifMove = true;
					}
					count++;
				}
			}
		}
		for (int n = 0; n < COL; n++)
		{
			table[m][n] = newRow[n];
		}
	}
	if (ifMove) {
		char location = locateNewNum(table);
		table[getNewNumX(location)][getNewNumY(location)] = createNewNum();
		printMe(table);
		if (gameOverCheck(table))
		{
			printGameOver();
		}
	}
}

void setOriginalLocation(int table[ROW][COL])
{
	int x = (int)(floor((rand() / (RAND_MAX + 1.0)) * COL));
	int y = (int)(floor((rand() / (RAND_MAX + 1.0)) * ROW));
	table[x][y] = 2;
}

void initializeGame(int table[ROW][COL])
{
	for (int n = 0; n < ROW; n++)
		for (int m = 0; m < COL; m++)
			table[n][m] = 0;
	real_time_mark = 0;
	setOriginalLocation(table);
	printMe(table);
}

int main()
{
	int gameTable[ROW][COL] = { 0 };
	initializeGame(gameTable);
	bool ifExit = false;
	while (!ifExit)
	{
		switch (_getch())
		{
		case 75:
			whenLeft(gameTable);
			break;
		case 80:
			whenDown(gameTable);
			break;
		case 77:
			whenRight(gameTable);
			break;
		case 72:
			whenUp(gameTable);
			break;
		case 'Q':
			ifExit = true;
			break;
		default:
			break;
		}
		if (!ifPlaying) {
			switch (_getch())
			{
			case 'r':
				ifPlaying = true;
				initializeGame(gameTable);
				break;
			default:
				ifExit = true;
			}
		}
	}
	return 0;
}