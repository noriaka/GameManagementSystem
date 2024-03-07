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

//���캯��
Player_Manager::Player_Manager()
{
	players = vector<string>(0);
}

//������Ҳ���
void Player_Manager::add_Player(Player player)//������ң���д���ļ�
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

//��ѯ�Ƿ����ָ�����
int Player_Manager::find_Player(string account)  //��������Ƿ���ϵͳ�У����ڷ������λ�ã������򷵻�-1
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

//ɾ��ָ�������Ϣ
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

//�޸�ָ�������Ϣ
void Player_Manager::modify_Player(string account)
{
	int buffer = 1;  //�û�λ��
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
		cout << "��ѡ�����޸ĵĲ��֣�1.�ǳ� 2.���� 3.��ַ 4.�绰���� 0.����" << endl;
		cin >> num;
		ofstream outfile(path.c_str(), ios_base::out | ios_base::binary);
		switch (num)
		{
		case  0:
			break;
		case  1:
			cout << "�������µ��ǳ�" << endl;
			cin >> player.pi.name;
			break;
		case 2:
			cout << "������ԭ���룺" << endl;
			while (cin >> password1)
			{
				if (password1 == player.pi.password)
				{
					cout << "������ȷ" << endl;
					break;
				}
				else
				{
					cout << "��������������������룺" << endl;
				}
			}
			cout << "��������Ҫ�޸ĵ����룺" << endl;
			cin >> player.pi.password;
			break;
		case 3:
			cout << "�������µĵ�ַ" << endl;
			cin >> player.pi.email;
			break;
		case 4:
			cout << "�������µĵ绰����" << endl;
			cin >> player.pi.phone_number;
			break;
		default:
			break;
		}
		outfile.write((char*)&player, sizeof(player));
		outfile.close();
		if (num != 0)
		{
			cout << "�޸ĳɹ����Ƿ���Ҫ�����޸� " << endl;
			cout << "1.���� 0.���� " << endl;
			cin >> buffer;
		}
		else
			buffer = 0;
	}
}

//��ʾ���������Ϣ
void Player_Manager::show_Player_Information(int pos)
{
	int num;
	int flag;
	Player player;
	string path = "";
	path = "player_data\\" + players[pos] + ".dat";
	ifstream infile(path, ios::in | ios::binary);
	infile.read((char*)&player, sizeof(player));
	cout << "�˺�Ϊ" + players[pos] + "����ҵ���Ϣ���£�" << endl;
	cout << "���˻�����Ϣ��" << endl;
	cout << player.pi;
	cout << "ս����Ϣ��" << endl;
	cout << player.pr;
	cout << "��ѡ����Ҫ�鿴�ڼ����ı�����Ϣ��" << endl;
	while (cin >> num)
	{
		cout << player.games[num];
		cout << "ѡ���Ƿ�����鿴��1�ǣ�0��" << endl;
		cin >> flag;
		if (flag == 0)
			break;
		else
		{
			cout << "��ѡ����Ҫ�鿴�ڼ����ı�����Ϣ��" << endl;
		}
	}
	infile.close();
	
}

//��ʾ���ս��ͼ
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
			cout << "����" << i << "�÷�Ϊ��";
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

//��ʾ����ó�Ӣ������
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
	cout << "������ó���Ӣ������Ϊ��" << endl;
	cout << "���������֣�������ʹ�ô�����" << endl;
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

//��ʾ�ó���Ӣ����ҵ�����
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
	cout << "�ó����Ӣ�۵��������Ϊ��" << endl;
	cout << "���������֣�������ʹ�ô�����" << endl;
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

//��ʾ���ʤ������
int Player_Manager::Player_Rank(string account, int flag)//��ҵ�ʤ������
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
				cout << "��ǰ�˻�Ϊ " << account << "����ҵ�����Ϊ:" << i + 1 << endl;
			rank = i + 1;
			break;
		}
	}

	if (flag)
	{
		cout << "�������ʤ������:" << endl;
		for (int i = 0; i < (int)players.size(); i++)
		{
			cout << i + 1 << "������" << rate[i].name
				<< "   ʤ�ʣ� " << rate[i].win_rate << endl;
		}
	}

	
	return rank;

}
