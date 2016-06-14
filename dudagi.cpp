#include"dudagi.h"

CDudagi::CDudagi()
{
	Init();
}

void CDudagi::Init()
{
	int i;

	if (g_nStage == -1) // 1���� �ʱ�ȭ�� �Ǵ� �κп� ���� ó�� ����
	{
		g_nStage = 0;
		//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[0], 0, &g_Channel[0] );
	}

	g_nDudagiCount = 0; // ���� �δ��� ����	
	g_nGrade = 0;

	// Note: ��ġ �¾�
	g_Mangchi.nIsAttack = 0;
	g_Mangchi.nIndex = 0;
	g_Mangchi.nStayX = 38;
	g_Mangchi.nStayY = 10;
	g_Mangchi.StartTime = g_GameStartTime;
	g_Mangchi.DelayTime = 300;

	for (i = 0; i < 9; i++)
	{
		g_Dudagi[i].StayTime = rand() % g_StageInfo[g_nStage].DownLimitTime + 10; // Note: �ּ� 10�� �ȴ�.
		g_Dudagi[i].OldTime = clock();
		g_Dudagi[i].nState = SETUP;
		g_Dudagi[i].OutPutTime = rand() % g_StageInfo[g_nStage].UpLimitTime + 10; //�ּ� 10�� �ȴ�.
	}
}

void CDudagi::Update()
{
	int i;
	clock_t CurTime = clock();

	switch (g_nGameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 2000)  // 2��
		{
			g_nGameState = RUNNING;
			g_GameStartTime = CurTime;
		}
		break;
	case RUNNING:
		if ((CurTime - g_GameStartTime) > g_StageInfo[g_nStage].LimitTime)
		{
			g_nGameState = STOP;
			return;
		}
		else{
			// �δ��� ������Ʈ	
			for (i = 0; i < 9; i++)
			{
				switch (g_Dudagi[i].nState)
				{
				case SETUP:
					g_Dudagi[i].OldTime = CurTime;
					g_Dudagi[i].OutPutTime = rand() % (int)g_StageInfo[g_nStage].UpLimitTime + 10;
					g_Dudagi[i].StayTime = rand() % (int)g_StageInfo[g_nStage].DownLimitTime + 10;
					g_Dudagi[i].nState = UP;
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3] ); // ���ö��� ���
					break;
				case UP:
					if (CurTime - g_Dudagi[i].OldTime > g_Dudagi[i].OutPutTime)
					{
						g_Dudagi[i].OldTime = CurTime;
						g_Dudagi[i].nState = DOWN;
					}
					break;
				case DOWN:
					if (CurTime - g_Dudagi[i].OldTime > g_Dudagi[i].StayTime)
						g_Dudagi[i].nState = SETUP;
					break;
				}
			}

			// ��ġ ������Ʈ 
			if (g_Mangchi.nIsAttack)
			{
				// �浹 �׽�Ʈ ��ġ�� ���� �ϳ��� �δ����� ���� �� �ֱ⿡ �ϳ��� ������� �浹 üũ�� ���� ���´�.
				for (i = 0; i < 9; i++)
				{
					if (g_Dudagi[i].nState == UP && i == g_Mangchi.nIndex)
					{
						g_nGrade += 10;
						g_nDudagiCount++;
						g_Dudagi[i].nState = DOWN; // �׾����� �ٿ� ���·� �ٷ� ��ȯ�� �ϵ��� �Ѵ�.															
						//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[4], 0, &g_Channel[4] );								
						break;
					}
				}

				// Note: ��ġ�� ���¸� �������ִ� �κ� ��ġ�� ���� ���� ������ �ð� ���� �ӹ����� �ϱ� ���� �κ�
				if (CurTime - g_Mangchi.StartTime > g_Mangchi.DelayTime)
				{
					g_Mangchi.nIsAttack = 0;
				}
			}

			g_RemainTime = (g_StageInfo[g_nStage].LimitTime - (CurTime - g_GameStartTime)) / 1000; // ���� ���� ���� �ð�
		}
		break;
	case STOP:
		// �����̳� ���и� �Ǵ����־ ����� ���ִ� �κ��� �;� �Ѵ�.
		if (g_nDudagiCount >= g_StageInfo[g_nStage].nCatchDudagi)
		{
			g_UpdateOldTime = CurTime;
			g_nGameState = SUCCESS;
			g_nTotalGrade += g_nGrade;
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[6], 0, &g_Channel[6] ); // �̼� ���� ����
		}
		else{
			g_nGameState = FAILED;
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[1], 0, &g_Channel[1] ); // �̼� ���� ����
		}
		break;
	case SUCCESS:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			g_UpdateOldTime = CurTime;
			g_nGrade = 0;
			++g_nStage;
			Init();
			g_nGameState = READY;
			//FMOD_Channel_Stop( g_Channel[6] );  // �̼� ���� ���� ��� ����					
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]); // READY ���� ���
		}
		break;
	}
}

void CDudagi::Render()
{
	int i;
	char string[100];

	dudagi_screen.ScreenClear();

	switch (g_nGameState)
	{
	case INIT:
		if (g_nStage == 0)
			dudagi_screen.InitScreen();
		break;

	case READY:
		dudagi_screen.ReadyScreen();
		sprintf(string, "%d", g_nStage + 1);
		dudagi_screen.ScreenPrint(16, 11, string);
		break;

	case RUNNING:
		dudagi_screen.RunningScreen();

		sprintf(string, "��ǥ �δ��� : %d  ���� �δ��� : %d", g_StageInfo[g_nStage].nCatchDudagi, g_nDudagiCount);
		dudagi_screen.ScreenPrint(2, 1, string);
		sprintf(string, "�������� : %d ���� : %d ���� �ð� : %d ", g_nStage + 1, g_nGrade, g_RemainTime);
		dudagi_screen.ScreenPrint(2, 2, string);

		for (i = 0; i < 9; i++)
		{
			if (g_Dudagi[i].nState == UP)
				dudagi_screen.ScreenPrint(g_Point[i].nX, g_Point[i].nY, "��");

			dudagi_screen.ScreenPrint(g_Point[i].nX, g_Point[i].nY + 1, "��");
		}

		if (g_Mangchi.nIsAttack)
			dudagi_screen.Mangchi(g_Point[g_Mangchi.nIndex].nX, g_Point[g_Mangchi.nIndex].nY);
		else
			dudagi_screen.MangchiReady(g_Mangchi.nStayX, g_Mangchi.nStayY);
		break;

	case SUCCESS:
		dudagi_screen.SuccessScreen();
		sprintf(string, "%d", g_nStage + 1);
		dudagi_screen.ScreenPrint(20, 11, string);
		sprintf(string, "%d", g_nDudagiCount);
		dudagi_screen.ScreenPrint(21, 17, string);
		sprintf(string, "%d", g_nTotalGrade);
		dudagi_screen.ScreenPrint(14, 19, string);
		break;

	case FAILED:
		dudagi_screen.FailureScreen();
		sprintf(string, "%d", g_nStage + 1);
		dudagi_screen.ScreenPrint(16, 11, string);
		break;

	case RESULT:
		dudagi_screen.ResultScreen();
		sprintf(string, "%d", g_nTotalGrade);
		dudagi_screen.ScreenPrint(25, 11, string);
		break;
	}
	dudagi_screen.ScreenFlipping();
}

void CDudagi::Play()
{
	int nKey;

	dudagi_screen.ScreenInit();

	while (1)
	{
		if (_kbhit())
		{
			if (g_nGameState == RESULT)
				break;

			nKey = _getch();
			switch (nKey)
			{
			case ' ':
				if (g_nGameState == INIT && g_nStage == 0)
				{
					g_nGameState = READY;
					//FMOD_Channel_Stop( g_Channel[0] ); // ����� ����
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]); // READY ���� ���
					g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
				}
				break;
			case '1':  // ��ġ Ű �Է� 1 ~ 9����
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (g_Mangchi.nIsAttack == 0 && g_nGameState == RUNNING)
				{
					g_Mangchi.nIndex = nKey - '1';
					g_Mangchi.StartTime = clock();
					g_Mangchi.nIsAttack = 1;
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5] );
				}
				break;

			case 'y':
			case 'Y':
				if (g_nGameState == FAILED)
				{
					Init();
					g_nGameState = READY;
					//FMOD_Channel_Stop( g_Channel[1] );  // �̼� ���� ���� ��� ���� 
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]); // READY ���� ���
					g_nGrade = 0;
					g_UpdateOldTime = clock();
				}
				break;
			case 'n':
			case 'N':
				if (g_nGameState == FAILED)
				{
					g_nGameState = RESULT;
					//FMOD_Channel_Stop( g_Channel[1] );  // �̼� ���� ���� ��� ����							
				}
				break;
			}
		}

		Update();    // ������ ����
		Render();    // ȭ�� ���
		//FMOD_System_Update( g_System );
	}

	//Release();   // ����
	dudagi_screen.ScreenRelease();

}