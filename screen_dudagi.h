#ifndef _SCREEN_DUDAGI_H_
#define _SCREEN_DUDIGI_H_

#include<iostream>

class CScreen_Dudagi
{
public:
	// Screen 설정 관련
	void ScreenInit();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint(int x, int y, char *string);
	void SetColor(unsigned short color);
public:
	// Screen 화면 보여주는 함수들
	void InitScreen();
	void ReadyScreen();
	void SuccessScreen();
	void RunningScreen();
	void FailureScreen();
	void ResultScreen();
	void Mangchi(int x, int y);
	void MangchiReady(int x, int y);
protected:
	static int g_nScreenIndex;
	static HANDLE g_hScreen[2];
};

#endif