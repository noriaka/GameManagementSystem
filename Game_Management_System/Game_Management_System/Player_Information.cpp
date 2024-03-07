#include "stdafx.h"
#include "Player_Information.h"

//构造函数
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

//重载运算符，格式化输出
ostream& operator<<(ostream& os, Player_Information& pi)
{
	os << "昵称：" << pi.name << endl;
	os << "账号：" << pi.account << endl;
	os << "密码：" << pi.password << endl;
	os << "邮件地址：" << pi.email << endl;
	os << "累计在线时长：" << pi.total_time << endl;
	os << "联系电话：" << pi.phone_number << endl;
	return os;
}
