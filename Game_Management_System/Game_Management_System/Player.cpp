#include "stdafx.h"
#include "Player.h"

//���캯��
Player::Player()
{
	Game cur_game(6);
	for (int i = 0; i < 10; i++)
	{
		games[i] = cur_game;
	}
	pi = Player_Information();
	pr = Player_Record();
}

//���ƹ��캯��
Player::Player(const Player & player)
{
	pi = player.pi;
	pr = player.pr;
	
}