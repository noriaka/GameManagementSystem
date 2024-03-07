#include "stdafx.h"
#include "Player_Record.h"
#include <fstream>
#include <iostream>
#define MAX -100
using namespace std;

//���캯��
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

//�������������ʽ�����
ostream& operator<<(ostream& os, const Player_Record& c)
{
	os << "��Ϸ�ܴ�����" << c.game_count << endl;		// ��¼��Ϸ�ܳ���
	os << "ʤ��������" << c.win_count << endl;		// ��¼ʤ������
	os << "ʧ�ܴ�����" << c.fail_count << endl;		// ��¼ʧ�ܳ���
	os << "ʤ�ʣ�" << c.win_rate << endl;			// ʤ��
	os << "�����ʣ�" << c.escape_rate << endl;		// ������
	os << "��ǰ������" << c.rank << endl;			// ��ǰ����
	os << "Ӣ�������" << endl;
	os << "Ӣ�������� " << "Ӣ�۵÷֣� " << "Ӣ��ʹ�ô����� " << endl;
	for (int i = 0; i < 7; i++)
	{
		if (c.heros[i].times != 0)
			os << c.heros[i].name << "\t\t" << c.heros[i].score << "\t\t" << c.heros[i].times << endl;
	}
	return os;
}

