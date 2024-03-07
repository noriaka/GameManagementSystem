#ifndef Player_H
#define Player_H
#include "Player_Information.h"
#include "Player_Record.h"
#include "Game.h"
#include <vector>

//存储玩家所有信息
class Player
{
public:
	Player_Information pi;	//玩家基本信息
	Player_Record pr;		//玩家总战绩信息
	Game games[10];			//玩家每局战绩信息

	Player();
	Player(const Player & player);	//构造函数
};
#endif