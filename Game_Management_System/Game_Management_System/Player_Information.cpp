#include "stdafx.h"
#include "Player_Information.h"

//���캯��
Player_Information::Player_Information(char name[10], char account[10], char password[10],
	char email[10], char phone_number[10])
{
	strcpy_s(this->name, strlen(name) + 1, name);
	strcpy_s(this->account, strlen(account) + 1, account);
	strcpy_s(this->password, strlen(password) + 1, password);
	strcpy_s(this->email, strlen(email) + 1, email);
	strcpy_s(this->phone_number, strlen(phone_number) + 1, phone_number);
}

Player_Information::Player_Information()
{
	strcpy_s(name, strlen("") + 1, "");
	strcpy_s(account, strlen("") + 1, "");
	strcpy_s(password, strlen("") + 1, "");
	strcpy_s(email, strlen("") + 1, "");
	total_time = 0;
	strcpy_s(phone_number, strlen("") + 1, "");
}

//�������������ʽ�����
ostream& operator<<(ostream& os, Player_Information& pi)
{
	os << "�ǳƣ�" << pi.name << endl;
	os << "�˺ţ�" << pi.account << endl;
	os << "���룺" << pi.password << endl;
	os << "�ʼ���ַ��" << pi.email << endl;
	os << "�ۼ�����ʱ����" << pi.total_time << endl;
	os << "��ϵ�绰��" << pi.phone_number << endl;
	return os;
}
