#pragma once
#ifndef _FOOT_BALL_H_
#define _FOOT_BALL_H_

#include"football_info.h"
#include"screen_football.h"

class CFootball :public CFootball_Info
{
public:
	CFootball();

	void Init();
	void Update();
	void Render();
	void Release();
	void play();
public:
	CScreen_football screen;
	CFootball_Info Football_Info;
};

#endif