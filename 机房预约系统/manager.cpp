#pragma once
#include<iostream>
using namespace std;
#include"manager.h"
#include <fstream>
#include"globalFile.h"
#include<algorithm>

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʵ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʵ�������õ���Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "���Ի���������Ϊ" << vCom.size() << endl;



}


//�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա:" << this->m_Name << "��¼!" << endl;
	cout << "			*****1������˺�******     " << endl;
	cout << "			*****2���鿴�˺�******     " << endl;
	cout << "			*****3���鿴����******     " << endl;
	cout << "			*****4�����ԤԼ******     " << endl;
	cout << "			*****0��ע����¼******     " << endl;
	cout << "-----------------_____________________"<<endl;
		cout << "��ѡ�����Ĳ���:" << endl;

}

//����˺�
void Manager::addPerson()
{
	cout << "��ѡ��Ҫ��ӵ��˺�" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2����ʦ" << endl;

	ofstream ofs;
	string fileName;
	string tip;
	string errorTip;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ��";
		//cout << "������ѧ��" << endl;
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����";
		errorTip = "ְ�����ظ�������������";

	}

	//����׷���ļ��ķ�ʽд����Ϣ
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, 1);
		if (ret)//���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	//cin >> id;

	cout << "����������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	ofs << id <<" " << name<<" " << pwd <<" " << endl;
	//ofs << "��������" << endl;

	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
	//��ʱ��������
	this->initVector();

}
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "����:" << s.m_Name << "����" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_Emid << "����:" << t.m_Name << "����" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴������" << endl;
	cout << "1������ѧ��" << endl;
	cout << "2�����н�ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}

	else
	{
		//�鿴��ʦ
		cout << "���н�ʦ��Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);


	}
	system("pause");
	system("cls");

}
//�鿴������Ϣ
void Manager::showComouter()
{
	cout << "������Ϣ����" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�������" << it->m_ComId << "�����������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}


//��ʼ������
void Manager::initVector()
{
	//ȷ���������
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ 
	ifstream ifs;
	//ѧ��
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "���Ե�ǰѧ������" << vStu.size() << endl;
	ifs.close();
	//��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_Emid && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "���Ե�ǰ��ʦ����" << vTea.size() << endl;
	ifs.close();


}
//����Ƿ��ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_Emid)
			{
				return true;
			}
		}
	}
}
