#ifndef Game_H
#define Game_H
#include "stdafx.h"
#include <string>
#include <vector>
#include "Player_Current_Record.h"
using namespace std;

//存储每一局游戏的信息
class Game
{
public:
	bool flag;						//判断每个玩家的Game数组中元素是否为空
	char begin_time[20];			//游戏开始时间
	char end_time[20];				//游戏结束时间
	int player_number;				//参与本局游戏的人数
	double delta_time;				//开始游戏到结束的时间差
	Player_Current_Record pcr[6];	//存储每个人的战绩情况
	string get_Time();				//获取时间格式

	friend ostream& operator<<(ostream& os, Game game);		//重载输出运算符实现格式化输出
	Game();
	Game(int num);					//构造函数
	
};

//作为一种数据结构，用来辅助实现排序功能
class Key
{
public:
	char name[10];					//存储名字
	int score;						//存储该名字对应的分数
	int times;						//存储该名字的玩家或英雄被使用的次数

	Key();
	Key(char name[10], int score, int times);	//构造函数
};

//作为一种数据结构，用来辅助玩家根据胜率排名
class Rate
{
public:
	char name[10];					//玩家昵称
	double win_rate;				//玩家胜率

	Rate();		
	Rate(char name[10], double rate);	//构造函数
};

//存储英雄信息
class Hero
{
public:
	int hero_id;					//英雄id，可以利用下标方便定位到某个英雄
	char hero_name[10];				//英雄名称
	Key players[10];				//存储玩过该英雄的玩家信息

	Hero();							
	Hero(char* name, int id);		//构造函数
};

//管理所有英雄信息
class Hero_Manager
{
public:
	Hero heros[10];					//存储所有英雄信息

	Hero_Manager();
	int get_Hero_Id(char* name);	//通过英雄名称来获取其对应id
};
#endif