#include"dudagi_info.h"

CDudagi_Info::CDudagi_Info() :g_nStage(-1), g_nGrade(0), g_nStageCount(1),
g_nDudagiCount(0), g_nTotalGrade(0), g_nIsSuccess(0)
{
	g_Point[0] = { 10, 15 };
	g_Point[1] = { 20, 15 };
	g_Point[2] = { 30, 15 };
	g_Point[3] = { 10, 10 };
	g_Point[4] = { 20, 10 };
	g_Point[5] = { 30, 10 };
	g_Point[6] = { 10, 5 };
	g_Point[7] = { 20, 5 };
	g_Point[8] = { 30, 5 };

	g_StageInfo[0] = { 2, 1000 * 10, 6000, 4000 };
	g_StageInfo[1] = { 5, 1000 * 10, 2000, 2000 };
	g_StageInfo[2] = { 50, 1000 * 120, 1000, 1000 };
	g_nGameState = INIT;
}
