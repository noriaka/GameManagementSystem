#ifndef Player_Current_Record_H
#define Player_Current_Record_H
#include "stdafx.h"
#include <vector>
#include <string>

#define KILL_SCORE 2		//击杀一次得分
#define DEAD_SCORE -1		//死亡一次得分
#define ASS_SCORE 1			//助攻一次得分
using namespace std;

//存储每局游戏玩家战绩信息
class Player_Current_Record
{
public:
	char player_name[10];	//玩家昵称
	char selected_hero[10];	//该玩家该场比赛选择的英雄
	int slay;				//击杀数
	int die;				//死亡数
	int assist;				//助攻数
	int hero_score;			//该英雄得分
	int player_score;		//该名玩家得分
	int double_kill;		//双杀次数
	int triple_kill;		//三杀次数
	int tower;				//推塔数
	int monster;			//击杀野怪数

	Player_Current_Record();
	//构造函数
	Player_Current_Record(char player_name[10], char selected_hero[10], int slay, int die, int assist
		, int double_kill, int triple_kill, int tower, int monster);

	int get_Hero_Score(int slay, int die, int assist);		//计算英雄得分
	int get_Player_Score(int slay, int die, int assist);	//计算玩家得分
	//重载输出运算符实现格式化输出
	friend ostream& operator<<(ostream& os, Player_Current_Record& pcr);
};
#endif