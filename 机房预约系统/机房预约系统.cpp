#include<iostream>
using namespace std;
#include"identity.h"
#include <fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<string>
//�����ʦ�Ӳ˵�ҳ��

void teacherMenu(Identity *& teacher)
{
	while (true)
	{
		//���ý�ʦ�Ӳ˵�
		teacher->operMenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();

		}
		else if (select == 2)
		{
			cout << "���ԤԼ" << endl;
			tea->validMyOrder();

		}
		else
		{
			delete teacher;
			system("pause");
			system("cls");
			cout << "ע���ɹ�" << endl;
			return;
		}
	}


}
//�������Ա�Ӳ˵�ҳ��
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "����˺�" << endl;
			man-> addPerson();

		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();

		}
		else if (select == 3)
		{
			cout << "�鿴������Ϣ" << endl;
			man->showComouter();
		}
		else if (select == 4)
		{
			//cout << "���ԤԼ��¼" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			system("pause");
			system("cls");
			cout << "ע���ɹ�" << endl;
			return;
		}
	}

}

//����ѧ���Ӳ˵�ҳ��
void studentMenu (Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "����ԤԼ" << endl;
			stu->applyOrder();

		}
		else if (select == 2)
		{
			cout << "�鿴�����ԤԼ" << endl;
			stu->showMyOrder();

		}
		else if (select == 3)
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			//cout << "ȡ��ԤԼ" << endl;
			stu->cancelMyOrder();
		}
		else
		{
			delete student;
			system("pause");
			system("cls");
			cout << "ע���ɹ�" << endl;
			return;
		}
	}

}


//ȫ�ֺ��� ��¼������װ 
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}


	int id = 0;
	string name;
	string pwd;

	if (type == 1)//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//ѧ���Ӳ˵�
				studentMenu(person);
				return;

			}

		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
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
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//����Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
		cout << "��֤��¼ʧ��" << endl;
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
		cout << "	*********��¼����***********" << endl;
		cout << "	*********1��ѧ������*******" << endl;
		cout << "	*********2����ʦ***********" << endl;
		cout << "	*********3������Ա*********" << endl;
		cout << "	*********0���˳�***********" << endl;
		cout << "	***************************" << endl;
		cout << "	****����������ѡ��*********" << endl;

		cin >> select;
		switch (select)

		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������ȷ��ѡ��" << endl;
			system("pause");
			system("cls");
			break;

		}
	}

	system("pause");
	return 0;

}