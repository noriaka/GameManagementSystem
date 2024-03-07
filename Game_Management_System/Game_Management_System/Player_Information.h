#ifndef Player_Information_H
#define Player_Information_H
#include <string>
using namespace std;

//存储玩家基本信息
class Player_Information
{
public:
	char name[10];				// 玩家昵称
	char account[10];			// 玩家账号
	char password[10];			// 密码
	char email[10];				// 邮件地址
	int total_time;				// 累积在线时长
	char phone_number[10];		// 联系电话

	Player_Information();		
	//构造函数
	Player_Information(char name[10], char account[10], char password[10],
		char email[10], char phone_number[10]);
	//重载输出运算符实现格式化输出
	friend ostream& operator<<(ostream& os, Player_Information& pi);
};

#endif 