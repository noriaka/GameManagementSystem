#include "stdafx.h"
#include "Player_Current_Record.h"
#include <string>


using namespace std;

//�������������ʽ�����
ostream& operator<<(ostream& os, Player_Current_Record& pcr)
{
	os << "�������Ϊ��" << pcr.player_name << endl;
	os << "ѡ��Ӣ��Ϊ��" << pcr.selected_hero << endl;
	os << "��ɱ��Ϊ��" << pcr.slay << endl;
	os << "������Ϊ��" << pcr.die << endl;
	os << "������Ϊ��" << pcr.assist << endl;
	os << "��Ӣ�۵÷�Ϊ��" << pcr.hero_score << endl;
	os << "����ҵ÷�Ϊ��" << pcr.player_score << endl;
	os << "˫ɱ����Ϊ��" << pcr.double_kill << endl;
	os << "��ɱ����Ϊ��" << pcr.triple_kill << endl;
	os << "����Ϊ��" << pcr.tower << endl;
	os << "��ɱҰ�ִ���Ϊ��" << pcr.monster << endl;
	return os;
}

//���캯��
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

//��ȡӢ�۵÷�
int Player_Current_Record::get_Hero_Score(int slay, int die, int assist)	//����Ӣ�۵÷�
{
	return slay * KILL_SCORE + die * DEAD_SCORE + assist * ASS_SCORE;
}

//��ȡ��ҵ÷�
int Player_Current_Record::get_Player_Score(int slay, int die, int assist)	//������ҵ÷�
{
	return slay * KILL_SCORE + die * DEAD_SCORE + assist * ASS_SCORE;
}