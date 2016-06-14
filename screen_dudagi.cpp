#include <windows.h>
#include"screen_dudagi.h"

HANDLE CScreen_Dudagi::g_hScreen[] = { 0 };
int CScreen_Dudagi::g_nScreenIndex = 0;

void CScreen_Dudagi::ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// ������ �ܼ�â 2���� �����.
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// Ŀ�� �����
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void CScreen_Dudagi::ScreenFlipping()
{
	Sleep(10);
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void CScreen_Dudagi::ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
}

void CScreen_Dudagi::ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}


void CScreen_Dudagi::ScreenPrint(int x, int y, char *string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

// 1 ~ 15 ���� ���� ���� ����
void CScreen_Dudagi::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

void CScreen_Dudagi::InitScreen()
{
	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "��                                        ��");
	ScreenPrint(0, 2, "��                                        ��");
	ScreenPrint(0, 3, "��                                        ��");
	ScreenPrint(0, 4, "��                                        ��");
	ScreenPrint(0, 5, "��                                        ��");
	ScreenPrint(0, 6, "��                                        ��");
	ScreenPrint(0, 7, "��                                        ��");
	ScreenPrint(0, 8, "��             ////////                   ��");
	ScreenPrint(0, 9, "��             ���� /�� ����/             ��");
	ScreenPrint(0, 10, "��             ����������������           ��");
	ScreenPrint(0, 11, "��             ����������������           ��");
	ScreenPrint(0, 12, "��                                        ��");
	ScreenPrint(0, 13, "��                                        ��");
	ScreenPrint(0, 14, "��                                        ��");
	ScreenPrint(0, 15, "��             �δ��� ��� ����           ��");
	ScreenPrint(0, 16, "��                                        ��");
	ScreenPrint(0, 17, "��          space Ű�� �����ּ���         ��");
	ScreenPrint(0, 18, "��                                        ��");
	ScreenPrint(0, 19, "��                                        ��");
	ScreenPrint(0, 20, "��                                        ��");
	ScreenPrint(0, 21, "��                                        ��");
	ScreenPrint(0, 22, "��                                        ��");
	ScreenPrint(0, 23, "��������������������������������������������");
}

void CScreen_Dudagi::ReadyScreen()
{
	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "����������������������᦭");
	ScreenPrint(0, 2, "����������������������᦭");
	ScreenPrint(0, 3, "����������������������᦭");
	ScreenPrint(0, 4, "����������������������᦭");
	ScreenPrint(0, 5, "����������������������᦭");
	ScreenPrint(0, 6, "����������������������᦭");
	ScreenPrint(0, 7, "����������������������᦭");
	ScreenPrint(0, 8, "����������������������᦭");
	ScreenPrint(0, 9, "����������������������᦭");
	ScreenPrint(0, 10, "��������                    �����᦭");
	ScreenPrint(0, 11, "��������        ��������    �����᦭");
	ScreenPrint(0, 12, "��������                    �����᦭");
	ScreenPrint(0, 13, "����������������������᦭");
	ScreenPrint(0, 14, "����������������������᦭");
	ScreenPrint(0, 15, "����������������������᦭");
	ScreenPrint(0, 16, "����������������������᦭");
	ScreenPrint(0, 17, "����������������������᦭");
	ScreenPrint(0, 18, "����������������������᦭");
	ScreenPrint(0, 19, "����������������������᦭");
	ScreenPrint(0, 20, "����������������������᦭");
	ScreenPrint(0, 21, "����������������������᦭");
	ScreenPrint(0, 22, "����������������������᦭");
	ScreenPrint(0, 23, "��������������������������������������������");
}

void CScreen_Dudagi::SuccessScreen()
{
	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "��                                        ��");
	ScreenPrint(0, 2, "��                                        ��");
	ScreenPrint(0, 3, "��                                        ��");
	ScreenPrint(0, 4, "��             // / // ������             ��");
	ScreenPrint(0, 5, "��             ��/��    /������           ��");
	ScreenPrint(0, 6, "��             ����  ��  �զ���           ��");
	ScreenPrint(0, 7, "��              ��_________///            ��");
	ScreenPrint(0, 8, "��                                        ��");
	ScreenPrint(0, 9, "��                                        ��");
	ScreenPrint(0, 10, "��                                        ��");
	ScreenPrint(0, 11, "��                       ��������         ��");
	ScreenPrint(0, 12, "��                                        ��");
	ScreenPrint(0, 13, "��                   �̼� ���� !!!!       ��");
	ScreenPrint(0, 14, "��                                        ��");
	ScreenPrint(0, 15, "��                                        ��");
	ScreenPrint(0, 16, "��                                        ��");
	ScreenPrint(0, 17, "��     ���� �δ��� :                      ��");
	ScreenPrint(0, 18, "��                                        ��");
	ScreenPrint(0, 19, "��     ���� :                             ��");
	ScreenPrint(0, 20, "��                                        ��");
	ScreenPrint(0, 21, "��                                        ��");
	ScreenPrint(0, 22, "��                                        ��");
	ScreenPrint(0, 23, "��������������������������������������������");
}

void CScreen_Dudagi::RunningScreen()
{
	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "��                                        ��");
	ScreenPrint(0, 2, "��                                        ��");
	ScreenPrint(0, 3, "��                                        ��");
	ScreenPrint(0, 4, "��                                        ��");
	ScreenPrint(0, 5, "��                                        ��");
	ScreenPrint(0, 6, "��                                        ��");
	ScreenPrint(0, 7, "��                                        ��");
	ScreenPrint(0, 8, "��                                        ��");
	ScreenPrint(0, 9, "��                                        ��");
	ScreenPrint(0, 10, "��                                        ��");
	ScreenPrint(0, 11, "��                                        ��");
	ScreenPrint(0, 12, "��                                        ��");
	ScreenPrint(0, 13, "��                                        ��");
	ScreenPrint(0, 14, "��                                        ��");
	ScreenPrint(0, 15, "��                                        ��");
	ScreenPrint(0, 16, "��                                        ��");
	ScreenPrint(0, 17, "��                                        ��");
	ScreenPrint(0, 18, "��                                        ��");
	ScreenPrint(0, 19, "��                            ��    ��    ��");
	ScreenPrint(0, 20, "��                          ���ᦰ���র  ��");
	ScreenPrint(0, 21, "��                            ����  ����  ��");
	ScreenPrint(0, 22, "��                                        ��");
	ScreenPrint(0, 23, "��������������������������������������������");
}

void CScreen_Dudagi::FailureScreen()
{
	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "��                                        ��");
	ScreenPrint(0, 2, "��                                        ��");
	ScreenPrint(0, 3, "��                                        ��");
	ScreenPrint(0, 4, "��                                        ��");
	ScreenPrint(0, 5, "��                                        ��");
	ScreenPrint(0, 6, "��             ��-����-��                 ��");
	ScreenPrint(0, 7, "��             d ��,.�� b                 ��");
	ScreenPrint(0, 8, "��             ���Ѧ��Ҧ�                 ��");
	ScreenPrint(0, 9, "��             �Ŧͦ��ɦ�                 ��");
	ScreenPrint(0, 10, "��               �Ʀ���                   ��");
	ScreenPrint(0, 11, "��                    ��������            ��");
	ScreenPrint(0, 12, "��                                        ��");
	ScreenPrint(0, 13, "��            �̼� ���� !!!!              ��");
	ScreenPrint(0, 14, "��                                        ��");
	ScreenPrint(0, 15, "��                                        ��");
	ScreenPrint(0, 16, "��                                        ��");
	ScreenPrint(0, 17, "��      �ٽ� �Ͻðڽ��ϱ�? ( y/n )        ��");
	ScreenPrint(0, 18, "��                                        ��");
	ScreenPrint(0, 19, "��                                        ��");
	ScreenPrint(0, 20, "��                                        ��");
	ScreenPrint(0, 21, "��                                        ��");
	ScreenPrint(0, 22, "��                                        ��");
	ScreenPrint(0, 23, "��������������������������������������������");
}

void CScreen_Dudagi::ResultScreen()
{
	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "��                                        ��");
	ScreenPrint(0, 2, "��                                        ��");
	ScreenPrint(0, 3, "��                                        ��");
	ScreenPrint(0, 4, "��                                        ��");
	ScreenPrint(0, 5, "��                                        ��");
	ScreenPrint(0, 6, "��                                        ��");
	ScreenPrint(0, 7, "��  (((    �δ��� ��� ���� Score  ))))   ��");
	ScreenPrint(0, 8, "��                                        ��");
	ScreenPrint(0, 9, "��                                        ��");
	ScreenPrint(0, 10, "��                                        ��");
	ScreenPrint(0, 11, "��           �� ����  :                   ��");
	ScreenPrint(0, 12, "��                                        ��");
	ScreenPrint(0, 13, "��                                        ��");
	ScreenPrint(0, 14, "��                                        ��");
	ScreenPrint(0, 15, "��                                        ��");
	ScreenPrint(0, 16, "��                                        ��");
	ScreenPrint(0, 17, "��                                        ��");
	ScreenPrint(0, 18, "��                                        ��");
	ScreenPrint(0, 19, "��                                        ��");
	ScreenPrint(0, 20, "��                                        ��");
	ScreenPrint(0, 21, "��                                        ��");
	ScreenPrint(0, 22, "��                                        ��");
	ScreenPrint(0, 23, "��������������������������������������������");
}

void CScreen_Dudagi::Mangchi(int x, int y)
{
	ScreenPrint(x - 4, y - 1, "�٦�����");
	ScreenPrint(x - 4, y, "�����Φ�������");
	ScreenPrint(x - 4, y + 1, "�٦�����");
}

void CScreen_Dudagi::MangchiReady(int x, int y)
{
	ScreenPrint(x - 4, y - 2, "    ��");
	ScreenPrint(x - 4, y - 1, "  ������");
	ScreenPrint(x - 4, y, "  ��  ��");
	ScreenPrint(x - 4, y + 1, "  ������");
	ScreenPrint(x - 4, y + 2, "    ��");
	ScreenPrint(x - 4, y + 3, "    ��");
	ScreenPrint(x - 4, y + 4, "    ��");
	ScreenPrint(x - 4, y + 5, "    ��");
}