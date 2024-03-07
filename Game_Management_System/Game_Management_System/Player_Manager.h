#ifndef Player_Manage_H
#define Player_Manage_H
#include "stdio.h"
#include "Player_Information.h"
#include "Player.h"
#include <vector>
#include "string"
using namespace std;

//��ҹ���Ա
class Player_Manager
{
public:
	vector<string> players;					//ÿ������˺���Ϣ

	void add_Player(Player player);			//�������
	int find_Player(string account);		//Ѱ���Ƿ����ָ�����
	int delete_Player(string account);		//ɾ��ָ�������Ϣ
	void modify_Player(string user_id);		//�޸�ָ�������Ϣ
	void show_Player_Information(int pos);	//��ʾ���������Ϣ
	void show_Player_Score(char* name);		//����ָ�����ս��ͼ

	void show_Player_Hero_Rank(char* name);	//��ȡָ�����Ŀǰ�ó���Ӣ������
	void show_Hero_Player_Rank(int pos);	//��ȡĿǰ�ó���ָ��Ӣ�۵��������
	int Player_Rank(string account, int flag);		//���ʤ������


	Player_Manager();
};
#endif