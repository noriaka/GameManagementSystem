#ifndef Player_Information_H
#define Player_Information_H
#include <string>
using namespace std;

//�洢��һ�����Ϣ
class Player_Information
{
public:
	char name[10];				// ����ǳ�
	char account[10];			// ����˺�
	char password[10];			// ����
	char email[10];				// �ʼ���ַ
	int total_time;				// �ۻ�����ʱ��
	char phone_number[10];		// ��ϵ�绰

	Player_Information();		
	//���캯��
	Player_Information(char name[10], char account[10], char password[10],
		char email[10], char phone_number[10]);
	//������������ʵ�ָ�ʽ�����
	friend ostream& operator<<(ostream& os, Player_Information& pi);
};

#endif 