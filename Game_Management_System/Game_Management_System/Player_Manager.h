#ifndef Player_Manage_H
#define Player_Manage_H
#include "stdio.h"
#include "Player_Information.h"
#include "Player.h"
#include <vector>
#include "string"
using namespace std;

//玩家管理员
class Player_Manager
{
public:
	vector<string> players;					//每个玩家账号信息

	void add_Player(Player player);			//增加玩家
	int find_Player(string account);		//寻找是否存在指定玩家
	int delete_Player(string account);		//删除指定玩家信息
	void modify_Player(string user_id);		//修改指定玩家信息
	void show_Player_Information(int pos);	//显示玩家所有信息
	void show_Player_Score(char* name);		//绘制指定玩家战绩图

	void show_Player_Hero_Rank(char* name);	//获取指定玩家目前擅长的英雄排名
	void show_Hero_Player_Rank(int pos);	//获取目前擅长玩指定英雄的玩家排名
	int Player_Rank(string account, int flag);		//玩家胜率排名


	Player_Manager();
};
#endif