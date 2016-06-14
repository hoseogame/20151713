#ifndef _DUDAGI_H_
#define _DUDAGI_H_

#include"dudagi_info.h"
#include"screen_dudagi.h"

class CDudagi :public CDudagi_Info
{
public:
	CDudagi();
public:
	void Init();
	void Update();
	void Render();
	/*void Release();*/
	void Play();
protected:
	CScreen_Dudagi dudagi_screen;
	CDudagi_Info dudagi_info;
};

#endif