#include "stdafx.h"
#include "Game_Manager.h"
#include "Game.h"
#include "Player.h"
#include "windows.h"
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;
//���캯������ʼ��pm��hm
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

//����������������д��player_data.txt�ļ�
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

//���˵�
void Game_Manager::menu()
{

	char input;
	int select_num;
	cout << "��ѡ���ܣ�1����ע����棬2�����¼���棬3�������Ա���棬4�˳�" << endl;
	while (cin >> input)
	{
		if (input > '0'&& input < '5')
		{
			select_num = input - '0';
			break;
		}
		else
			cout << "������Ϸ�������!" << endl;
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
		cout << "�˳���Ϸ" << endl;
		break;
	default:
		break;
	}

}

//���ע��
void Game_Manager::registration()
{
	Player player;
	cout << "�������˺ţ�" << endl;
	cin >> player.pi.account;
	cout << "���������룺" << endl;
	cin >> player.pi.password;
	cout << "�������ǳƣ�" << endl;
	cin >> player.pi.name;
	cout << "�������ʼ���ַ��" << endl;
	cin >> player.pi.email;
	cout << "��������ϵ�绰��" << endl;
	cin >> player.pi.phone_number;
	pm.add_Player(player);
	cout << "ע��ɹ�!" << endl;
	Sleep(1000);
	system("cls");
	Game_Manager::menu();
}

//��ҵ�¼
void Game_Manager::log_in()
{
	string account, password, path;
	Player player;
	bool flag = false;
	cout << "�������˺ţ�" << endl;
	while (cin >> account)
	{
		flag = false;
		path = "player_data\\" + account + ".dat";
		ifstream infile(path.c_str(), ios::in|ios::binary);
		if (!infile)
		{
			cout << "�˺Ų����ڣ����������룺" << endl;
		}
		else
		{
			infile.read((char*)&player, sizeof(player));

			cout << "���������룺" << endl;
			while (cin >> password)
			{
				if (password == player.pi.password)
				{
					flag = true;
					cout << "��¼�ɹ������ڽ�����Ϸ���棺" << endl;
					Sleep(1000);
					system("cls");
					break;
				}
				else
				{
					system("cls");
					cout << "�˺�Ϊ " << account << " ����������������������룺" << endl;
				}
			}

			infile.close();
		}
		if (flag)
			break;
	}
	Game_Manager::game_Start(account);
}

//����Ա����
void Game_Manager::manager_Interface()
{
	char input;
	int num;
	int select_num;
	cout << "��ѡ���ܣ�1����ָ�������Ϣ��2�����Ƿ����ָ����ң�3ɾ��ָ�������Ϣ��\n4�޸�ָ�������Ϣ��5�鿴ָ����һ�����Ϣ��6�鿴������Ϣ��7�鿴���ս��ͼ��8�˳�" << endl;
	while (cin >> input)
	{
		if (input > '0'&& input < '9')
		{
			select_num = input - '0';
			break;
		}
		else
			cout << "������Ϸ�������!" << endl;
	}
	Player player;
	string account;
	int pos;
	switch (select_num)
	{
	case 1:
		system("cls");
		cout << "�������˺ţ�" << endl;
		cin >> player.pi.account;
		cout << "���������룺" << endl;
		cin >> player.pi.password;
		cout << "�������ǳƣ�" << endl;
		cin >> player.pi.name;
		cout << "�������ʼ���ַ��" << endl;
		cin >> player.pi.email;
		cout << "��������ϵ�绰��" << endl;
		cin >> player.pi.phone_number;
		pm.add_Player(player);
		cout << "ע��ɹ�!" << endl;
		Sleep(1000);
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 2:
		system("cls");
		cout << "��������Ҫ������ҵ��˺ţ�" << endl;
		cin >> account;
		pos = pm.find_Player(account);
		if (pos == -1)
		{
			cout << "����Ҳ�����" << endl;
		}
		else
		{
			cout << "����Ҵ���" << endl;
		}
		Sleep(1000);
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 3:
		system("cls");
		cout << "��������Ҫɾ������ҵ��˺ţ�" << endl;
		cin >> account;
		pos = pm.delete_Player(account);
		if (pos != -1)
		{
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "δ�ҵ��������Ϣ" << endl;
		}
		Sleep(1000);
		system("cls");
		Game_Manager::manager_Interface();
		break;
	case 4:
		system("cls");
		cout << "��������Ҫ�޸ĵ���ҵ��˺ţ�" << endl;
		cin >> account;
		pos = pm.find_Player(account);
		if (pos == -1)
		{
			cout << "����Ҳ�����" << endl;
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
		cout << "��������Ҫ�鿴��һ�����Ϣ�Ķ�Ӧ�˺ţ�" << endl;
		cin >> account;
		pos = pm.find_Player(account);
		if (pos == -1)
		{
			cout << "����Ҳ�����" << endl;
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
		cout << "�����빦�ܣ�1�鿴������ҵ�ǰ������2�鿴ָ������ó�Ӣ��������3�鿴ָ��Ӣ���ó����������" << endl;
		cin >> num;
		char name[10];
		int pos;
		switch (num)
		{
		case 1:
			system("cls");
			cout << "��������Ҫ��ѯ������ǳƣ�" << endl;
			cin >> name;
			pm.Player_Rank(name, 1);
			system("pause");
			system("cls");
			//Game_Manager::manager_Interface();
			break;
		case 2:
			system("cls");
			cout << "��������Ҫ��ѯ����ҵ��˺ţ�" << endl;
			cin >> name;
			pm.show_Player_Hero_Rank(name);
			system("pause");
			system("cls");
			//Game_Manager::manager_Interface();
			break;
		case 3:
			system("cls");
			cout << "��������Ҫ��ѯ��Ӣ�۵����֣�" << endl;
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
		cout << "��������Ҫ������ҵ��˺ţ�" << endl;
		cin >> account;
		pos = pm.find_Player(account);
		if (pos == -1)
		{
			cout << "����Ҳ�����" << endl;
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

//��Ϸ��ʼ����
void Game_Manager::game_Start(string account)
{
	char input;
	cout << "����s��ʼһ����Ϸ������e�˳���Ϸ��" << endl;
	while (cin >> input)
	{
		if (input == 's' || input == 'e')
			break;
		else
			cout << "��������ȷ�ַ���" << endl;
	}
	if (input == 's')
	{
		system("cls");
		cout << "��ʼ��Ϸ��" << endl;
		Game_Manager::game_Play(account);
		cout << "һ����Ϸ����" << endl;
		Sleep(500);
		system("cls");
		Game_Manager::game_Start(account);
	}
	else
	{
		cout << "�˳���Ϸ�������˵�" << endl;
		system("cls");
		Game_Manager::menu();
	}
}

//ģ����Ϸ����
void Game_Manager::game_Play(string account)
{
	string path = "";
	int player_number = 0;
	vector<Player> players(6);

	//��ʵ����һ����ǰ��¼����ң���д��players������
	path = "player_data\\" + account + ".dat";
	ifstream infile(path, ios::in | ios::binary);
	infile.read((char*)&players[0], sizeof(players[0]));
	infile.close();

	//ʵ�������������ƥ����б���
	int num;
	if (pm.players.size() - 6 > 0)
	{
		num = rand() % (pm.players.size() - 6);
	}
	else if (pm.players.size() < 6)
	{
		cout << "��������" << endl;
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
	

	//��ʼ��Ϸ
	Game cur_game;
	time_t begin, end;
	begin = clock();
	cur_game.flag = true;
	string time;
	time = cur_game.get_Time();
	strcpy_s(cur_game.begin_time, time.c_str());

	//ģ����Ϸ���У�����ʼ���ⳡ����ÿ����ս��
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
		cout << "ģ�����6������Ϸ����ȴ�6��" << endl;
		Sleep(200);
	}
	time = cur_game.get_Time();
	strcpy_s(cur_game.end_time, time.c_str());
	end = clock();
	cur_game.delta_time = double(end - begin) / CLOCKS_PER_SEC;
		
	//����ÿ��Ӣ�۵����������Ӣ�۵���ҵ���Ϣ
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
	
	//���ⳡ����ÿ���˵�ս��д��ÿ����games������
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
	
	//�ж��ⳡ����������Ӯ
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

	//���ÿ���˾����ⳡ���������ս���ı仯
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

		//����heros������Ϣ
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

	//��������ʱ��
	for (int i = 0; i < 6; i++)
	{
		players[i].pi.total_time += (int)(cur_game.delta_time * 100);
	}


	
	//�������Ϣ����д���ļ�
	for (int i = 0; i < 6; i++)
	{
		string str;
		str = players[i].pi.account;
		path = "player_data\\" + str + ".dat";
		ofstream outfile(path, ios::out | ios::binary | ios::trunc);
		outfile.write((char*)&players[i], sizeof(players[i]));
		outfile.close();
	}

	//��Ӣ����Ϣ����д���ļ�
	ofstream outfile1("hero_info.dat", ios::out | ios::binary | ios::trunc);
	outfile1.write((char*)&hm.heros, sizeof(hm.heros));
	outfile1.close();
	
}