#ifndef Player_Current_Record_H
#define Player_Current_Record_H
#include "stdafx.h"
#include <vector>
#include <string>

#define KILL_SCORE 2		//��ɱһ�ε÷�
#define DEAD_SCORE -1		//����һ�ε÷�
#define ASS_SCORE 1			//����һ�ε÷�
using namespace std;

//�洢ÿ����Ϸ���ս����Ϣ
class Player_Current_Record
{
public:
	char player_name[10];	//����ǳ�
	char selected_hero[10];	//����Ҹó�����ѡ���Ӣ��
	int slay;				//��ɱ��
	int die;				//������
	int assist;				//������
	int hero_score;			//��Ӣ�۵÷�
	int player_score;		//������ҵ÷�
	int double_kill;		//˫ɱ����
	int triple_kill;		//��ɱ����
	int tower;				//������
	int monster;			//��ɱҰ����

	Player_Current_Record();
	//���캯��
	Player_Current_Record(char player_name[10], char selected_hero[10], int slay, int die, int assist
		, int double_kill, int triple_kill, int tower, int monster);

	int get_Hero_Score(int slay, int die, int assist);		//����Ӣ�۵÷�
	int get_Player_Score(int slay, int die, int assist);	//������ҵ÷�
	//������������ʵ�ָ�ʽ�����
	friend ostream& operator<<(ostream& os, Player_Current_Record& pcr);
};
#endif