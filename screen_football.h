#pragma once
#ifndef _FOOTBALL_SCREEN_H_
#define _FOOTBALL_SCREEN_H_
#include"football_info.h"

class CScreen_football :public  CFootball_Info
{
protected:
	static int g_nScreenIndex;
	static HANDLE g_hScreen[2];
public:
	CScreen_football();

	void ScreenInit();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint(int x, int y, char *string);
	void SetColor(unsigned short color);
public:
	void InitScreen();		// �ʱ�ȭ��
	void ReadyScreen(int* g_nStage);		//	�� �������� ȭ��
	void BackScreen(int* g_nStage, STAGE_INFO *g_sStageInfo, clock_t *g_GameStartTime);
	void GoalMessage(int nX, int nY);	// ����
	void SuccessScreen();	// �̼� ����
	void FailureScreen();	// �̼� ����
	void ResultScreen(int* g_nStage);	// ������ ���������� �� �ΰ�
};


#endif