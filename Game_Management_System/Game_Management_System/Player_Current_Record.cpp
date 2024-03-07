#include "stdafx.h"
#include "Player_Current_Record.h"
#include <string>


using namespace std;

//重载运算符，格式化输出
ostream& operator<<(ostream& os, Player_Current_Record& pcr)
{
	os << "玩家姓名为：" << pcr.player_name << endl;
	os << "选择英雄为：" << pcr.selected_hero << endl;
	os << "击杀数为：" << pcr.slay << endl;
	os << "死亡数为：" << pcr.die << endl;
	os << "助攻数为：" << pcr.assist << endl;
	os << "该英雄得分为：" << pcr.hero_score << endl;
	os << "该玩家得分为：" << pcr.player_score << endl;
	os << "双杀次数为：" << pcr.double_kill << endl;
	os << "三杀次数为：" << pcr.triple_kill << endl;
	os << "推塔为：" << pcr.tower << endl;
	os << "击杀野怪次数为：" << pcr.monster << endl;
	return os;
}

//构造函数
Player_Current_Record::Player_Current_Record(char player_name[10], char selected_hero[10],
	int slay, int die, int assist, int double_kill, int triple_kill,
	int tower, int monster)
{
	strcpy_s(this->player_name, player_name);
	strcpy_s(this->selected_hero, selected_hero);
	this->slay = slay;
	this->die = die;
	this->assist = assist;
	this->double_kill = double_kill;
	this->triple_kill = triple_kill;
	this->tower = tower;
	this->monster = monster;
}
Player_Current_Record::Player_Current_Record()
{
	strcpy_s(player_name, strlen("") + 1, "");
	strcpy_s(selected_hero, strlen("") + 1, "");
	slay = 0;
	die = 0;
	assist = 0;
	hero_score = 0;
	player_score = 0;
	double_kill = 0;
	triple_kill = 0;
	tower = 0;
	monster = 0;
}

//获取英雄得分
int Player_Current_Record::get_Hero_Score(int slay, int die, int assist)	//计算英雄得分
{
	return slay * KILL_SCORE + die * DEAD_SCORE + assist * ASS_SCORE;
}

//获取玩家得分
int Player_Current_Record::get_Player_Score(int slay, int die, int assist)	//计算玩家得分
{
	return slay * KILL_SCORE + die * DEAD_SCORE + assist * ASS_SCORE;
}