#include "stdafx.h"
#include "Player_Manager.h"
#include "Player_Information.h"
#include "Player_Record.h"
#include "Player.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//构造函数
Player_Manager::Player_Manager()
{
	players = vector<string>(0);
}

//增加玩家操作
void Player_Manager::add_Player(Player player)//增加玩家，并写入文件
{	
	ofstream outfile1("player_data.txt", ios::out | ios::app);
	outfile1 << player.pi.account << endl;
	players.push_back(player.pi.account);
	string path = "player_data\\";
	path = path + player.pi.account + ".dat";
	ofstream outfile(path, ios::out | ios::binary);
	outfile.write((char*)&player, sizeof(player));
	outfile.close();

}

//查询是否存在指定玩家
int Player_Manager::find_Player(string account)  //查找玩家是否在系统中，若在返回玩家位置，不在则返回-1
{
	for (int i = 0; i < (int)players.size(); i++)
	{
		if (account == players[i])
		{
			return i;
		}
	}
	return - 1;
	
}

//删除指定玩家信息
int Player_Manager::delete_Player(string account)
{
	string path = "player_data\\";
	int pos = Player_Manager::find_Player(account);
	if (pos == -1)
	{
		return -1;
	}
	path = path + players[pos] + ".dat";
	remove(path.c_str());
	
	players.erase(players.begin() + pos);
	return 0;
}

//修改指定玩家信息
void Player_Manager::modify_Player(string account)
{
	int buffer = 1;  //用户位置
	int num;
	string  password1;
	Player player1;
	string path1;
	Player player;
	string path;
	path = "player_data\\" + account + ".dat";
	
	
	while (buffer != 0)
	{
		ifstream infile(path.c_str(), ios::in | ios::binary);
		infile.read((char*)&player, sizeof(player));
		infile.close();
		cout << "请选择想修改的部分：1.昵称 2.密码 3.地址 4.电话号码 0.返回" << endl;
		cin >> num;
		ofstream outfile(path.c_str(), ios_base::out | ios_base::binary);
		switch (num)
		{
		case  0:
			break;
		case  1:
			cout << "请输入新的昵称" << endl;
			cin >> player.pi.name;
			break;
		case 2:
			cout << "请输入原密码：" << endl;
			while (cin >> password1)
			{
				if (password1 == player.pi.password)
				{
					cout << "密码正确" << endl;
					break;
				}
				else
				{
					cout << "密码输入错误，请重新输入：" << endl;
				}
			}
			cout << "请输入想要修改的密码：" << endl;
			cin >> player.pi.password;
			break;
		case 3:
			cout << "请输入新的地址" << endl;
			cin >> player.pi.email;
			break;
		case 4:
			cout << "请输入新的电话号码" << endl;
			cin >> player.pi.phone_number;
			break;
		default:
			break;
		}
		outfile.write((char*)&player, sizeof(player));
		outfile.close();
		if (num != 0)
		{
			cout << "修改成功！是否需要继续修改 " << endl;
			cout << "1.继续 0.返回 " << endl;
			cin >> buffer;
		}
		else
			buffer = 0;
	}
}

//显示玩家所有信息
void Player_Manager::show_Player_Information(int pos)
{
	int num;
	int flag;
	Player player;
	string path = "";
	path = "player_data\\" + players[pos] + ".dat";
	ifstream infile(path, ios::in | ios::binary);
	infile.read((char*)&player, sizeof(player));
	cout << "账号为" + players[pos] + "的玩家的信息如下：" << endl;
	cout << "个人基本信息：" << endl;
	cout << player.pi;
	cout << "战绩信息：" << endl;
	cout << player.pr;
	cout << "请选择想要查看第几场的比赛信息：" << endl;
	while (cin >> num)
	{
		cout << player.games[num];
		cout << "选择是否继续查看：1是，0否" << endl;
		cin >> flag;
		if (flag == 0)
			break;
		else
		{
			cout << "请选择想要查看第几场的比赛信息：" << endl;
		}
	}
	infile.close();
	
}

//显示玩家战绩图
void Player_Manager::show_Player_Score(char* account)
{
	int score[10];
	for (int i = 0; i < 10; i++)
	{
		score[i] = 0;
	}
	Player player;
	string str, path;
	str = account;
	path = "player_data\\" + str + ".dat";
	ifstream infile(path, ios::in | ios::binary);
	infile.read((char*)&player, sizeof(player));
	infile.close();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (!strcmp(player.pi.name, player.games[i].pcr[j].player_name))
			{
				score[i] = player.games[i].pcr[j].player_score;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (player.games[i].flag == true) 
		{
			cout << "比赛" << i << "得分为：";
			for (int j = 0; j < (score[i] >= 0 ? score[i] : -score[i]); j++)
			{
				if (score[i] >= 0)
				{
					if (j == score[i] - 1)
					{
						cout << "*";
					}
					else
					{
						cout << " ";
					}

				}
				else
				{
					if (j == (score[i] >= 0 ? score[i] : -score[i]) - 1)
					{
						cout << "-";
					}
					else
					{
						cout << " ";
					}
				}
					
			}
			cout << endl;
		}
		
	}
	
}

//显示玩家擅长英雄排名
void Player_Manager::show_Player_Hero_Rank(char* name)
{
	Player cur_player;
	string path, str;
	str = name;
	path = "player_data\\" + str + ".dat";
	ifstream infile(path, ios::in | ios::binary);
	infile.read((char*)&cur_player, sizeof(cur_player));
	infile.close();
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if ((cur_player.pr.heros[j].score / (cur_player.pr.heros[j].times == 0 ? 1 : cur_player.pr.heros[j].times)) <
				(cur_player.pr.heros[j + 1].score / (cur_player.pr.heros[j + 1].times == 0 ? 1 : cur_player.pr.heros[j + 1].times)))
			{
				Key temp;
				temp = cur_player.pr.heros[j];
				cur_player.pr.heros[j] = cur_player.pr.heros[j + 1];
				cur_player.pr.heros[j + 1] = temp;
			}
		}
	}
	cout << "该玩家擅长的英雄排名为：" << endl;
	cout << "排名：名字：分数：使用次数：" << endl;
	int cnt = 0;
	for (int i = 0; i < 10; i++, cnt++)
	{
		if (cur_player.pr.heros[i].times != 0)
		{		
			cout << (cnt + 1) << "	" << cur_player.pr.heros[i].name << "	" <<
				cur_player.pr.heros[i].score << "	" << cur_player.pr.heros[i].times << endl;
		}
		else
		{
			cnt--;
		}
		
	}
}

//显示擅长该英雄玩家的排名
void Player_Manager::show_Hero_Player_Rank(int pos)
{
	Hero cur_hero[10];
	ifstream infile("hero_info.dat", ios::in | ios::binary);
	infile.read((char*)&cur_hero, sizeof(cur_hero));
	infile.close();

	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if ((cur_hero[pos].players[j].score / (cur_hero[pos].players[j].times == 0 ? 1 : cur_hero[pos].players[j].times)) <
				(cur_hero[pos].players[j + 1].score / (cur_hero[pos].players[j + 1].times == 0 ? 1 : cur_hero[pos].players[j + 1].times)))
			{
				Key temp;
				temp = cur_hero[pos].players[j];
				cur_hero[pos].players[j] = cur_hero[pos].players[j + 1];
				cur_hero[pos].players[j + 1] = temp;
			}
		}
	}
	cout << "擅长玩该英雄的玩家排名为：" << endl;
	cout << "排名：名字：分数：使用次数：" << endl;
	int cnt = 0;
	for (int i = 0; i < 10; i++, cnt++)
	{
		if (cur_hero[pos].players[i].times != 0)
		{
			cout << (cnt + 1) << "	" << cur_hero[pos].players[i].name << "	" <<
				cur_hero[pos].players[i].score << "	" << cur_hero[pos].players[i].times << endl;
		}
		else
		{
			cnt--;
		}
		
	}

}

//显示玩家胜率排名
int Player_Manager::Player_Rank(string account, int flag)//玩家的胜率排名
{
	Rate rate[10];
	string path;
	Player player;
	int rank = 0;
	for (int i = 0; i < (int)players.size(); i++)
	{
		
		path = "player_data\\" + players[i] + ".dat";
		ifstream infile(path.c_str(), ios::in | ios::binary);
		if (!infile)
		{
			cout << "error" << endl;
		}
		else
		{
			infile.read((char*)&player, sizeof(player));
			strcpy_s(rate[i].name, player.pi.name);
			
			rate[i].win_rate = player.pr.win_rate;
			//rate[i].win_rate = player.pr.game_count;
		}
		infile.close();
	}

	for (int i = 0; i < (int)players.size() - 1; i++)
	{
		for (int j = 0; j < (int)players.size() - i - 1; j++)
		{
			if ((rate[j].win_rate) < (rate[j + 1].win_rate))
			{
				char a[10] = "";
				Rate temp(a, 0);
				temp = rate[j];
				rate[j] = rate[j + 1];
				rate[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < (int)players.size(); i++)
	{
		if (strcmp(rate[i].name, account.c_str()) == 0)
		{
			if(flag)
				cout << "当前账户为 " << account << "的玩家的排名为:" << i + 1 << endl;
			rank = i + 1;
			break;
		}
	}

	if (flag)
	{
		cout << "各个玩家胜率排名:" << endl;
		for (int i = 0; i < (int)players.size(); i++)
		{
			cout << i + 1 << "姓名：" << rate[i].name
				<< "   胜率： " << rate[i].win_rate << endl;
		}
	}

	
	return rank;

}
