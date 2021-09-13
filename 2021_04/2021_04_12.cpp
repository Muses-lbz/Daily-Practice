#include <iostream>
using namespace std;

class Student						//声明一个类，类名为Student
{
private:							//以下为类的私有内容
	int num;						//私有变量num
	int score;						//私有变量score
public:							    //以下为类中公用部分
	void setdata()					//定义公用函数setdata
	{
		cin >> num;					//输入num的值
		cin >> score;				//输入score的值
	}
	void display()					//定义公用函数diaplay
	{
		cout << "num=" << num << endl;		//输出num的值
		cout << "score=" << score << endl;	//输出score的值
	};
};									//类的声明结束

Student stud1, stud2;				//定义stud1和stud2为Student类的变量，称为对象

int main()							//主函数首部
{
	stud1.setdata();				//调用对象stud1的setdata函数
	stud1.display();
	stud2.setdata();
	stud2.display();
	system("pause");
	return 0;
}
//运行结果：
//01 90
//num = 1
//score = 90
//02 100
//num = 2
//score = 100

