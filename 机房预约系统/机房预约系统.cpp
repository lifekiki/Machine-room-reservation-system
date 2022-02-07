#include<iostream>
using namespace std;
#include"identity.h"
#include <fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<string>
//进入教师子菜单页面

void teacherMenu(Identity *& teacher)
{
	while (true)
	{
		//调用教师子菜单
		teacher->operMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "查看所有预约" << endl;
			tea->showAllOrder();

		}
		else if (select == 2)
		{
			cout << "审核预约" << endl;
			tea->validMyOrder();

		}
		else
		{
			delete teacher;
			system("pause");
			system("cls");
			cout << "注销成功" << endl;
			return;
		}
	}


}
//进入管理员子菜单页面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			man-> addPerson();

		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();

		}
		else if (select == 3)
		{
			cout << "查看机房信息" << endl;
			man->showComouter();
		}
		else if (select == 4)
		{
			//cout << "清空预约记录" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			system("pause");
			system("cls");
			cout << "注销成功" << endl;
			return;
		}
	}

}

//进入学生子菜单页面
void studentMenu (Identity*& student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "申请预约" << endl;
			stu->applyOrder();

		}
		else if (select == 2)
		{
			cout << "查看自身的预约" << endl;
			stu->showMyOrder();

		}
		else if (select == 3)
		{
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			//cout << "取消预约" << endl;
			stu->cancelMyOrder();
		}
		else
		{
			delete student;
			system("pause");
			system("cls");
			cout << "注销成功" << endl;
			return;
		}
	}

}


//全局函数 登录函数封装 
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}


	int id = 0;
	string name;
	string pwd;

	if (type == 1)//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)//教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//学生子菜单
				studentMenu(person);
				return;

			}

		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;

			}

		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//管理员子菜单
				managerMenu(person);
				return;
			}
		}
		cout << "验证登录失败" << endl;
		system("pause");
		system("cls");
		return;
	}

}
int main()

{
	int select = 0;

	while (true)
	{
		cout << "	*********登录界面***********" << endl;
		cout << "	*********1、学生代表*******" << endl;
		cout << "	*********2、教师***********" << endl;
		cout << "	*********3、管理员*********" << endl;
		cout << "	*********0、退出***********" << endl;
		cout << "	***************************" << endl;
		cout << "	****请输入您的选择*********" << endl;

		cin >> select;
		switch (select)

		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://教师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请输入正确的选项" << endl;
			system("pause");
			system("cls");
			break;

		}
	}

	system("pause");
	return 0;

}