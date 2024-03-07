#ifndef Game_H
#define Game_H
#include "stdafx.h"
#include <string>
#include <vector>
#include "Player_Current_Record.h"
using namespace std;

//�洢ÿһ����Ϸ����Ϣ
class Game
{
public:
	bool flag;						//�ж�ÿ����ҵ�Game������Ԫ���Ƿ�Ϊ��
	char begin_time[20];			//��Ϸ��ʼʱ��
	char end_time[20];				//��Ϸ����ʱ��
	int player_number;				//���뱾����Ϸ������
	double delta_time;				//��ʼ��Ϸ��������ʱ���
	Player_Current_Record pcr[6];	//�洢ÿ���˵�ս�����
	string get_Time();				//��ȡʱ���ʽ

	friend ostream& operator<<(ostream& os, Game game);		//������������ʵ�ָ�ʽ�����
	Game();
	Game(int num);					//���캯��
	
};

//��Ϊһ�����ݽṹ����������ʵ��������
class Key
{
public:
	char name[10];					//�洢����
	int score;						//�洢�����ֶ�Ӧ�ķ���
	int times;						//�洢�����ֵ���һ�Ӣ�۱�ʹ�õĴ���

	Key();
	Key(char name[10], int score, int times);	//���캯��
};

//��Ϊһ�����ݽṹ������������Ҹ���ʤ������
class Rate
{
public:
	char name[10];					//����ǳ�
	double win_rate;				//���ʤ��

	Rate();		
	Rate(char name[10], double rate);	//���캯��
};

//�洢Ӣ����Ϣ
class Hero
{
public:
	int hero_id;					//Ӣ��id�����������±귽�㶨λ��ĳ��Ӣ��
	char hero_name[10];				//Ӣ������
	Key players[10];				//�洢�����Ӣ�۵������Ϣ

	Hero();							
	Hero(char* name, int id);		//���캯��
};

//��������Ӣ����Ϣ
class Hero_Manager
{
public:
	Hero heros[10];					//�洢����Ӣ����Ϣ

	Hero_Manager();
	int get_Hero_Id(char* name);	//ͨ��Ӣ����������ȡ���Ӧid
};
#endif