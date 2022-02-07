#include"orderFile.h"
#include<fstream>
//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;//记录条数
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName
		&& ifs >> roomId && ifs >> status)
	{
		/*	cout << "测试" << endl;
			cout << date << endl;
			cout << interval << endl;
			cout << stuId << endl;
			cout << stuName << endl;
			cout << roomId << endl;
			cout << status << endl;
			cout << endl;*/

		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);

			value = date.substr(pos + 1, date.size() - pos - 1);  //size=9 pos=4 size=5
			m.insert(make_pair(key, value));
		}


		//cout << "key=" << key << endl;
		//cout << "value=" << value << endl;

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);  //size=9 pos=4 size=5
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);  //size=9 pos=4 size=5
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);  //size=9 pos=4 size=5
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);  //size=9 pos=4 size=5
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);  //size=9 pos=4 size=5
			m.insert(make_pair(key, value));
		}
		//将小map容器放入到大的容器中去
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();
	/*system("pause");
	system("cls");*/
	//测试最大map容器
	//for (map<int,map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << "条数为" << it->first << "value=" << endl;

	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit!= it->second.end(); mit++)
	//	{
	//		cout << " key=" << mit->first << " value=" << mit->second << " ";

	//	}
	//	cout << endl;
	//} 
}
//更新预约次数
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}

//记录的容器 key---记录的次数  value---具体记录的键值对信息
map<int, map<string, string>> m_orderData;

//预约记录次数
int m_Size;