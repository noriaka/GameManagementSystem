#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;
//�������������ʽ�����
ostream& operator<<(ostream& os, Game game)
{
	os << "��ʼʱ��Ϊ��" << game.begin_time << endl;
	os << "����ʱ��Ϊ��" << game.end_time << endl;
	os << "��Ϸ����Ϊ��" << game.player_number << endl;
	os << "ÿ��ս�����Ϊ��" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << game.pcr[i] << endl;
	}

	return os;
}

//���캯��
Game::Game(int num)
{
	strcpy_s(begin_time, "");
	strcpy_s(end_time, "");
	this->player_number = num;
	for (int i = 0; i < num; i++)
	{
		Player_Current_Record cur_pcr;
		pcr[i] = cur_pcr;
	}
}

Game::Game()
{
	delta_time = 0.0f;
	flag = false;
	strcpy_s(begin_time, "");
	strcpy_s(end_time, "");
	player_number = 6;
	for (int i = 0; i < 6; i++)
	{
		Player_Current_Record cur_pcr;
		pcr[i] = cur_pcr;
	}
}

//��ȡʱ���ʽ
string Game::get_Time()
{
	SYSTEMTIME start;
	string time;
	GetLocalTime(&start);
	time = to_string(start.wYear) + "-" + to_string(start.wMonth)
		+ "-" + to_string(start.wDay) + " " +
		to_string(start.wHour) + ":" + to_string(start.wMinute)
		+ ":" + to_string(start.wSecond);
	return time;
}

//���캯��
Key::Key(char name[10], int score, int times)
{
	strcpy_s(this->name, name);
	this->score = score;
	this->times = times;
}

Key::Key()
{
	strcpy_s(name, strlen("") + 1, "");
	score = 0;
	times = 0;
}

//���캯��
Hero::Hero()
{
	for (int i = 0; i < 10; i++)
	{
		Key cur_key;
		cur_key.score = -100;
		players[i] = cur_key;
	}
}

Hero::Hero(char* name, int id)
{
	strcpy_s(hero_name, strlen(name) + 1, name);
	hero_id = id;
	for (int i = 0; i < 10; i++)
	{
		Key cur_key;
		cur_key.score = -100;
		players[i] = cur_key;
	}
}

//���캯��
Rate::Rate(char name[10], double rate)
{
	strcpy_s(this->name, name);
	this->win_rate = rate;
}

Rate::Rate()
{
	strcpy_s(name, "");
	win_rate = 0;
}

//���캯��
Hero_Manager::Hero_Manager()
{
	char cur[10];
	int i = 0;
	ifstream infile("hero_name.txt", ios::in);
	while (infile)
	{

		infile.getline(cur, 10);
		Hero cur_hero(cur, i);
		heros[i] = cur_hero;
		i++;
	}
	infile.close();
	//ofstream outfile("hero_info.dat", ios::out | ios::binary);
	//outfile.write((char*)&heros, sizeof(heros));
	//outfile.close();
}

//��ȡ��ӦӢ��id
int Hero_Manager::get_Hero_Id(char* name)
{
	for (int i = 0; i < 10; i++)
	{
		if (!strcmp(heros[i].hero_name, name))
		{
			return heros[i].hero_id;
		}
	}
	return 0;
}

