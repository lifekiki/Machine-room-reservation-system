#include<iostream>
using namespace std;
#include"teacher.h"
#include"student.h"
#include"orderFile.h"
#include"globalFile.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId,string name, string pwd)
{
	this->m_Emid = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{

	cout << "��ʦ:" << this->m_Name << "��¼!" << endl;
	cout << "			*****1���鿴����ԤԼ******     " << endl;
	cout << "			*****2�����ԤԼ******     " << endl;
	cout << "			*****0��ע����¼******     " << endl;
	cout << "-----------------_____________________" << endl;
	cout << "��ѡ�����Ĳ���:" << endl;

}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "��ԤԼ��¼" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < of.m_Size; i++)
		{
			cout << i + 1 << "��";

			cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
			cout << "������" << of.m_orderData[i]["stuName"];
			cout << "ԤԼ���ڣ���  " << of.m_orderData[i]["date"];
			cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "�����ţ�" << of.m_orderData[i]["roomId"];
			string status = "״̬";
			//1 �����  2 ��ԤԼ   -1 ԤԼʧ��  0 ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "��ԤԼ,���ͨ��";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��,��˲�ͨ��";
			}
			else if (of.m_orderData[i]["status"] == "0")
			{
				status += "ȡ��ԤԼ";
			}
			cout << status << endl;
		}

		system("pause");
		system("cls");
	}


//���ԤԼ
void Teacher::validMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵ļ�¼����" << endl;
	vector<int>v;
	int index = 0;

	for (int i = 0; i < of.m_Size; i++)
	{
	
		//1 �����  2 ��ԤԼ   -1 ԤԼʧ��  0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���  " << of.m_orderData[i]["date"];
			cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "�����ţ�" << of.m_orderData[i]["roomId"];
			string status = "״̬";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}

	}
	cout << "������ԤԼ��˼�¼��0������" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";

				}
				else 
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";

				}
				of.updateOrder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������" << endl;

	}

	system("pause");
	system("cls");
}



