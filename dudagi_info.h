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
		int	nIsAttack;         // 망치 상태 
		clock_t	StartTime;     // 타격 상태가 시작된 시각
		clock_t	DelayTime;     // 타격 상태의 지연 시각
		int	nIndex;            // 좌표 배열에 접근하기 위한 인덱스
		int	nStayX, nStayY;    // 대기 상태일 때 좌표	
	} MANGCHI;

	typedef struct _DUDAGI
	{
		DUDAGI_STATE nState;	// Note: 두더지 상태	
		clock_t   StayTime;     // Note: 들어갔을 때 대기 시간
		clock_t	OutPutTime;     // Note: 나왔을 때 대기 시간
		clock_t	OldTime;        // Note: 이전 시각		
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
	int			g_nGrade; // 점수 
	int			g_nStageCount;
	int			g_nDudagiCount;
	clock_t		g_GameStartTime, g_UpdateOldTime, g_RemainTime;
	int			g_nTotalGrade; // 총점

};
#endif