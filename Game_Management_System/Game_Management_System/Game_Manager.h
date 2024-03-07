#ifndef Game_Manager_H
#define Game_Manager_H
#include <string>
#include "Game.h"
#include "Player_Manager.h"
using namespace std;

//游戏管理员类
class Game_Manager
{
public:
	Player_Manager pm;		//玩家管理员对象
	Hero_Manager hm;		//英雄管理员对象

	void menu();						//主菜单
	void registration();				//玩家注册
	void log_in();						//玩家登录
	void manager_Interface();			//管理员界面
	void game_Start(string account);	//游戏开始界面
	void game_Play(string account);		//模拟游戏进行

	Game_Manager();						//构造函数
	~Game_Manager();					//析构函数
};
#endif
