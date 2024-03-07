#ifndef Player_Record_H
#define Player_Record_H
#include <string>
#include "Game.h"
using namespace std;

//�洢�����ս����Ϣ
class Player_Record
{
public:
	int game_count;					// ��¼��Ϸ�ܳ���
	int win_count;					// ��¼ʤ������
	int fail_count;					// ��¼ʧ�ܳ���
	float win_rate;					// ʤ��
	float escape_rate;				// ������
	int rank;						// ��ǰ����
	Key heros[10];					// ����������Ӣ�۵����ּ������
						
	Player_Record();
	//������������ʵ�ָ�ʽ�����
	friend ostream& operator<<(ostream& os, const Player_Record& c);   
};

#endif