#ifndef Player_H
#define Player_H
#include "Player_Information.h"
#include "Player_Record.h"
#include "Game.h"
#include <vector>

//�洢���������Ϣ
class Player
{
public:
	Player_Information pi;	//��һ�����Ϣ
	Player_Record pr;		//�����ս����Ϣ
	Game games[10];			//���ÿ��ս����Ϣ

	Player();
	Player(const Player & player);	//���캯��
};
#endif