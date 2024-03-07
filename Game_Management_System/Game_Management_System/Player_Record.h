#ifndef Player_Record_H
#define Player_Record_H
#include <string>
#include "Game.h"
using namespace std;

//存储玩家总战绩信息
class Player_Record
{
public:
	int game_count;					// 记录游戏总场次
	int win_count;					// 记录胜利场次
	int fail_count;					// 记录失败场次
	float win_rate;					// 胜率
	float escape_rate;				// 逃跑率
	int rank;						// 当前排名
	Key heros[10];					// 该玩家所玩的英雄的名字及其分数
						
	Player_Record();
	//重载输出运算符实现格式化输出
	friend ostream& operator<<(ostream& os, const Player_Record& c);   
};

#endif