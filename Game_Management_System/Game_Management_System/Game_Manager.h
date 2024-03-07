#ifndef Game_Manager_H
#define Game_Manager_H
#include <string>
#include "Game.h"
#include "Player_Manager.h"
using namespace std;

//��Ϸ����Ա��
class Game_Manager
{
public:
	Player_Manager pm;		//��ҹ���Ա����
	Hero_Manager hm;		//Ӣ�۹���Ա����

	void menu();						//���˵�
	void registration();				//���ע��
	void log_in();						//��ҵ�¼
	void manager_Interface();			//����Ա����
	void game_Start(string account);	//��Ϸ��ʼ����
	void game_Play(string account);		//ģ����Ϸ����

	Game_Manager();						//���캯��
	~Game_Manager();					//��������
};
#endif
