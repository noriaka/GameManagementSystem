#include "stdafx.h"
#include "Player_Record.h"
#include <fstream>
#include <iostream>
#define MAX -100
using namespace std;

//构造函数
Player_Record::Player_Record()
{
	game_count = 0;
	win_count = 0;
	fail_count = 0;
	win_rate = 0.0f;
	escape_rate = 0.0f;
	rank = 0;
	int i = 0;
	char cur[10];
	ifstream infile("hero_name.txt", ios::in);
	while (infile)
	{

		infile.getline(cur, 10);
		Key cur_key(cur, MAX, 0);
		heros[i] = cur_key;
		i++;
	}
	infile.close();
}

//重载运算符，格式化输出
ostream& operator<<(ostream& os, const Player_Record& c)
{
	os << "游戏总次数：" << c.game_count << endl;		// 记录游戏总场次
	os << "胜利次数：" << c.win_count << endl;		// 记录胜利场次
	os << "失败次数：" << c.fail_count << endl;		// 记录失败场次
	os << "胜率：" << c.win_rate << endl;			// 胜率
	os << "逃跑率：" << c.escape_rate << endl;		// 逃跑率
	os << "当前排名：" << c.rank << endl;			// 当前排名
	os << "英雄情况：" << endl;
	os << "英雄姓名： " << "英雄得分： " << "英雄使用次数： " << endl;
	for (int i = 0; i < 7; i++)
	{
		if (c.heros[i].times != 0)
			os << c.heros[i].name << "\t\t" << c.heros[i].score << "\t\t" << c.heros[i].times << endl;
	}
	return os;
}

