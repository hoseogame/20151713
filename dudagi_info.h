#ifndef _DUDAGI_INFO_H_
#define _DUDAGI_INFO_H_

#include<iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

class CDudagi_Info
{
public:
	CDudagi_Info();
public:
	typedef enum _GAME_STATE { INIT, READY, RUNNING, SUCCESS, FAILED, STOP, RESULT } GAME_STATE;
	typedef enum _DUDAGI_STATE { SETUP, UP, DOWN } DUDAGI_STATE;
	typedef struct _STAGE_INFO
	{
		int nCatchDudagi;
		clock_t LimitTime;
		clock_t UpLimitTime;
		clock_t DownLimitTime;
	} STAGE_INFO;
	typedef struct _MANGCHI
	{
		int	nIsAttack;         // ��ġ ���� 
		clock_t	StartTime;     // Ÿ�� ���°� ���۵� �ð�
		clock_t	DelayTime;     // Ÿ�� ������ ���� �ð�
		int	nIndex;            // ��ǥ �迭�� �����ϱ� ���� �ε���
		int	nStayX, nStayY;    // ��� ������ �� ��ǥ	
	} MANGCHI;

	typedef struct _DUDAGI
	{
		DUDAGI_STATE nState;	// Note: �δ��� ����	
		clock_t   StayTime;     // Note: ���� �� ��� �ð�
		clock_t	OutPutTime;     // Note: ������ �� ��� �ð�
		clock_t	OldTime;        // Note: ���� �ð�		
	} DUDAGI;
	typedef struct _XY
	{
		int nX, nY;
	} XY;

protected:
	XY	g_Point[9];
	STAGE_INFO g_StageInfo[3];
	GAME_STATE	g_nGameState;
	/*clock_t		g_GameStartTime;*/
	int         g_nIsSuccess;

	DUDAGI	g_Dudagi[9];
	MANGCHI	g_Mangchi;

	int			g_nStage;
	int			g_nGrade; // ���� 
	int			g_nStageCount;
	int			g_nDudagiCount;
	clock_t		g_GameStartTime, g_UpdateOldTime, g_RemainTime;
	int			g_nTotalGrade; // ����

};
#endif