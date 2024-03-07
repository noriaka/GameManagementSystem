#include "stdafx.h"
#include "Player.h"

//构造函数
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

//复制构造函数
Player::Player(const Player & player)
{
	pi = player.pi;
	pr = player.pr;
	
}