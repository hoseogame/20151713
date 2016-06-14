#ifndef _SCREEN_DUDAGI_H_
#define _SCREEN_DUDIGI_H_

#include<iostream>

class CScreen_Dudagi
{
public:
	// Screen ���� ����
	void ScreenInit();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint(int x, int y, char *string);
	void SetColor(unsigned short color);
public:
	// Screen ȭ�� �����ִ� �Լ���
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