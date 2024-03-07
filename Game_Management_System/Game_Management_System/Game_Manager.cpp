#include "stdafx.h"
#include "Game_Manager.h"
#include "Game.h"
#include "Player.h"
#include "windows.h"
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;
//构造函数，初始化pm与hm
Game_Manager::Game_Manager()
{
	string temp = "";
	ifstream infile("player_data.txt", ios::in);
	if (infile)
	{
		while (getline(infile, temp) && temp != "")
		{
			pm.players.push_back(temp);
		}
	}
	infile.close();

	ifstream infile1("hero_info.dat", ios::in | ios::binary);
	infile1.read((char*)&hm.heros, sizeof(hm.heros));
	infile1.close();

}

//析构函数，将数据写入player_data.txt文件
Game_Manager::~Game_Manager()
{
	ofstream outfile;
	outfile.open("player_data.txt", ios::trunc);
	for (int i = 0; i < (int)pm.players.size(); i++)
	{
		outfile << pm.players[i] << endl;
	}
	outfile.close();

	
}

//主菜单
void Game_Manager::menu()
{

	char input;
	int select_num;
	cout << "请选择功能：1进入注册界面，2进入登录界面，3进入管理员界面，4退出" << endl;
	while (cin >> input)
	{
		if (input > '0'&& input < '5')
		{
			select_num = input - '0';
			break;
		}
		else
			cout << "请输入合法的数字!" << endl;
	}

	switch (select_num)
	{
	case 1:
		system("cls");
		Game_Manager::registration();
		break;
	case 2:
		system("cls");
		Game_Manager::log_in();
		break;
	case 3:
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 4:
		cout << "退出游戏" << endl;
		break;
	default:
		break;
	}

}

//玩家注册
void Game_Manager::registration()
{
	Player player;
	cout << "请输入账号：" << endl;
	cin >> player.pi.account;
	cout << "请输入密码：" << endl;
	cin >> player.pi.password;
	cout << "请输入昵称：" << endl;
	cin >> player.pi.name;
	cout << "请输入邮件地址：" << endl;
	cin >> player.pi.email;
	cout << "请输入联系电话：" << endl;
	cin >> player.pi.phone_number;
	pm.add_Player(player);
	cout << "注册成功!" << endl;
	Sleep(1000);
	system("cls");
	Game_Manager::menu();
}

//玩家登录
void Game_Manager::log_in()
{
	string account, password, path;
	Player player;
	bool flag = false;
	cout << "请输入账号：" << endl;
	while (cin >> account)
	{
		flag = false;
		path = "player_data\\" + account + ".dat";
		ifstream infile(path.c_str(), ios::in|ios::binary);
		if (!infile)
		{
			cout << "账号不存在，请重新输入：" << endl;
		}
		else
		{
			infile.read((char*)&player, sizeof(player));

			cout << "请输入密码：" << endl;
			while (cin >> password)
			{
				if (password == player.pi.password)
				{
					flag = true;
					cout << "登录成功，现在进入游戏界面：" << endl;
					Sleep(1000);
					system("cls");
					break;
				}
				else
				{
					system("cls");
					cout << "账号为 " << account << " 的密码输入错误，请重新输入：" << endl;
				}
			}

			infile.close();
		}
		if (flag)
			break;
	}
	Game_Manager::game_Start(account);
}

//管理员界面
void Game_Manager::manager_Interface()
{
	char input;
	int num;
	int select_num;
	cout << "请选择功能：1增加指定玩家信息，2查找是否存在指定玩家，3删除指定玩家信息，\n4修改指定玩家信息，5查看指定玩家基本信息，6查看排名信息，7查看玩家战绩图，8退出" << endl;
	while (cin >> input)
	{
		if (input > '0'&& input < '9')
		{
			select_num = input - '0';
			break;
		}
		else
			cout << "请输入合法的数字!" << endl;
	}
	Player player;
	string account;
	int pos;
	switch (select_num)
	{
	case 1:
		system("cls");
		cout << "请输入账号：" << endl;
		cin >> player.pi.account;
		cout << "请输入密码：" << endl;
		cin >> player.pi.password;
		cout << "请输入昵称：" << endl;
		cin >> player.pi.name;
		cout << "请输入邮件地址：" << endl;
		cin >> player.pi.email;
		cout << "请输入联系电话：" << endl;
		cin >> player.pi.phone_number;
		pm.add_Player(player);
		cout << "注册成功!" << endl;
		Sleep(1000);
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 2:
		system("cls");
		cout << "请输入想要查找玩家的账号：" << endl;
		cin >> account;
		pos = pm.find_Player(account);
		if (pos == -1)
		{
			cout << "该玩家不存在" << endl;
		}
		else
		{
			cout << "该玩家存在" << endl;
		}
		Sleep(1000);
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 3:
		system("cls");
		cout << "请输入想要删除的玩家的账号：" << endl;
		cin >> account;
		pos = pm.delete_Player(account);
		if (pos != -1)
		{
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "未找到该玩家信息" << endl;
		}
		Sleep(1000);
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 4:
		system("cls");
		cout << "请输入想要修改的玩家的账号：" << endl;
		cin >> account;
		pos = pm.find_Player(account);
		if (pos == -1)
		{
			cout << "该玩家不存在" << endl;
		}
		else
		{
			pm.modify_Player(account);
		}
		Sleep(1000);
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 5:
		system("cls");
		cout << "请输入想要查看玩家基本信息的对应账号：" << endl;
		cin >> account;
		pos = pm.find_Player(account);
		if (pos == -1)
		{
			cout << "该玩家不存在" << endl;
		}
		else
		{
			pm.show_Player_Information(pos);
		}
		//Sleep(1000);
		system("pause");
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 6:
		system("cls");
		cout << "请输入功能：1查看所有玩家当前排名，2查看指定玩家擅长英雄排名，3查看指定英雄擅长的玩家排名" << endl;
		cin >> num;
		char name[10];
		int pos;
		switch (num)
		{
		case 1:
			system("cls");
			cout << "请输入想要查询的玩家昵称：" << endl;
			cin >> name;
			pm.Player_Rank(name, 1);
			system("pause");
			system("cls");
			//Game_Manager::manager_Interface();
			break;
		case 2:
			system("cls");
			cout << "请输入想要查询的玩家的账号：" << endl;
			cin >> name;
			pm.show_Player_Hero_Rank(name);
			system("pause");
			system("cls");
			//Game_Manager::manager_Interface();
			break;
		case 3:
			system("cls");
			cout << "请输入想要查询的英雄的名字：" << endl;
			cin >> name;
			pos = hm.get_Hero_Id(name);
			pm.show_Hero_Player_Rank(pos);
			system("pause");
			system("cls");
			//Game_Manager::manager_Interface();
			break;
		default:
			break;
		}
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 7:
		system("cls");
		cout << "请输入想要查找玩家的账号：" << endl;
		cin >> account;
		pos = pm.find_Player(account);
		if (pos == -1)
		{
			cout << "该玩家不存在" << endl;
		}
		else
		{
			char acc[10];
			strcpy_s(acc, account.c_str());
			pm.show_Player_Score(acc);
		}
		system("pause");
		system("cls");
		Game_Manager::manager_Interface();
		break;

	case 8:
		system("cls");
		Game_Manager::menu();
		break;
	default:
		break;
	}


}

//游戏开始界面
void Game_Manager::game_Start(string account)
{
	char input;
	cout << "输入s开始一局游戏，输入e退出游戏：" << endl;
	while (cin >> input)
	{
		if (input == 's' || input == 'e')
			break;
		else
			cout << "请输入正确字符：" << endl;
	}
	if (input == 's')
	{
		system("cls");
		cout << "开始游戏：" << endl;
		Game_Manager::game_Play(account);
		cout << "一局游戏结束" << endl;
		Sleep(500);
		system("cls");
		Game_Manager::game_Start(account);
	}
	else
	{
		cout << "退出游戏返回主菜单" << endl;
		system("cls");
		Game_Manager::menu();
	}
}

//模拟游戏进行
void Game_Manager::game_Play(string account)
{
	string path = "";
	int player_number = 0;
	vector<Player> players(6);

	//先实例化一个当前登录的玩家，并写入players向量中
	path = "player_data\\" + account + ".dat";
	ifstream infile(path, ios::in | ios::binary);
	infile.read((char*)&players[0], sizeof(players[0]));
	infile.close();

	//实例化其他五个人匹配进行比赛
	int num;
	if (pm.players.size() - 6 > 0)
	{
		num = rand() % (pm.players.size() - 6);
	}
	else if (pm.players.size() < 6)
	{
		cout << "人数不足" << endl;
		return;
	}
	else
	{
		num = 0;
	}
	
	for (int i = num; player_number != 5; i++)
	{
		if (pm.players[i] == account)
		{
			continue;
		}
		player_number++;
		path = "player_data\\" + pm.players[i] + ".dat";
		ifstream infile(path, ios::in | ios::binary);
		infile.read((char*)&players[player_number], sizeof(players[player_number]));
		infile.close();
	}
	

	//开始游戏
	Game cur_game;
	time_t begin, end;
	begin = clock();
	cur_game.flag = true;
	string time;
	time = cur_game.get_Time();
	strcpy_s(cur_game.begin_time, time.c_str());

	//模拟游戏进行，并初始化这场比赛每个人战绩
	for (int i = 0; i < 6; i++)
	{
		char player_name[10];
		strcpy_s(player_name, strlen(players[i].pi.name) + 1, players[i].pi.name);
		
		int slay = rand() % 10;
		int die = rand() % 10;
		int assist = rand() % 10;
		int double_kill = rand() % 10;
		int triple_kill = rand() % 10;
		int tower = rand() % 12;
		int monster = rand() % 300;
		int hero_id = rand() % 7;

		char hero_name[10];
		strcpy_s(hero_name, strlen(hm.heros[hero_id].hero_name) + 1, hm.heros[hero_id].hero_name);
		Player_Current_Record cur_pcr(player_name, hero_name, slay, die
			, assist, double_kill, triple_kill, tower, monster);
		cur_pcr.hero_score = cur_pcr.get_Hero_Score(cur_pcr.slay, cur_pcr.die, cur_pcr.assist);
		cur_pcr.player_score = cur_pcr.get_Player_Score(cur_pcr.slay, cur_pcr.die, cur_pcr.assist);
		cur_game.pcr[i] = cur_pcr;
		cout << "模拟进行6秒钟游戏，请等待6秒" << endl;
		Sleep(200);
	}
	time = cur_game.get_Time();
	strcpy_s(cur_game.end_time, time.c_str());
	end = clock();
	cur_game.delta_time = double(end - begin) / CLOCKS_PER_SEC;
		
	//更新每个英雄的所有玩过该英雄的玩家的信息
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (!strcmp(hm.heros[i].hero_name, cur_game.pcr[j].selected_hero))
			{
				for (int k = 0; k < 10; k++)
				{
					if (!strcmp(hm.heros[i].players[k].name, ""))
					{
						strcpy_s(hm.heros[i].players[k].name, strlen(cur_game.pcr[j].player_name) + 1, cur_game.pcr[j].player_name);
						hm.heros[i].players[k].times++;
						if (hm.heros[i].players[k].times == 1)
							hm.heros[i].players[k].score = 0;
						hm.heros[i].players[k].score += cur_game.pcr[j].hero_score;
						break;
					}
					else if(!strcmp(hm.heros[i].players[k].name, cur_game.pcr[j].player_name))
					{
						hm.heros[i].players[k].times++;
						if (hm.heros[i].players[k].times == 1)
							hm.heros[i].players[k].score = 0;
						hm.heros[i].players[k].score += cur_game.pcr[j].hero_score;
						break;
					}
				}
			}
		}
	}
	
	//将这场比赛每个人的战绩写入每个人games数组中
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (players[i].games[j].flag == true)
			{
				continue;
			}
			else
			{
				players[i].games[j] = cur_game;
				break;
			}
		}
		
	}
	
	//判断这场比赛两方输赢
	int red = 0, blue = 0;
	if ((cur_game.pcr[0].tower + cur_game.pcr[1].tower + cur_game.pcr[2].tower) >
		(cur_game.pcr[3].tower + cur_game.pcr[4].tower + cur_game.pcr[5].tower))
	{
		red = 1;
	}
	else if ((cur_game.pcr[0].tower + cur_game.pcr[1].tower + cur_game.pcr[2].tower) <
		(cur_game.pcr[3].tower + cur_game.pcr[4].tower + cur_game.pcr[5].tower))
	{
		blue = 1;
	}
	else
	{
		red = blue = 0;
	}

	//完成每个人经过这场比赛后个人战绩的变化
	for (int i = 0; i < 6; i++)
	{
	
		players[i].pr.game_count++;
		if (i < 3)
		{
			if (red == 1)
				players[i].pr.win_count++;
			else
				players[i].pr.fail_count++;
		}
		else
		{
			if (blue == 1)
				players[i].pr.win_count++;
			else
				players[i].pr.fail_count++;
		}
		players[i].pr.win_rate = (float)players[i].pr.win_count / (float)players[i].pr.game_count;
		players[i].pr.rank = pm.Player_Rank(players[i].pi.account, 0);

		//更新heros向量信息
		for (int j = 0; j < 10; j++)
		{
			
			if (!strcmp(cur_game.pcr[i].selected_hero, players[i].pr.heros[j].name))
			{
				players[i].pr.heros[j].times++;
				if (players[i].pr.heros[j].times == 1)
					players[i].pr.heros[j].score = 0;
				players[i].pr.heros[j].score += cur_game.pcr[i].hero_score;
			}

		}
	}

	//更新在线时长
	for (int i = 0; i < 6; i++)
	{
		players[i].pi.total_time += (int)(cur_game.delta_time * 100);
	}


	
	//将玩家信息重新写入文件
	for (int i = 0; i < 6; i++)
	{
		string str;
		str = players[i].pi.account;
		path = "player_data\\" + str + ".dat";
		ofstream outfile(path, ios::out | ios::binary | ios::trunc);
		outfile.write((char*)&players[i], sizeof(players[i]));
		outfile.close();
	}

	//将英雄信息重新写入文件
	ofstream outfile1("hero_info.dat", ios::out | ios::binary | ios::trunc);
	outfile1.write((char*)&hm.heros, sizeof(hm.heros));
	outfile1.close();
	
}