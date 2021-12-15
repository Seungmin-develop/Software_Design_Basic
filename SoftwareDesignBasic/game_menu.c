#include "zombie_world.h"

// ���� ����
void PlayGame() 
{
    system("mode con cols=130 lines=40"); //�ܼ�â ũ�� ����
    life = 3;
    score = 0;
    stage = 1;
    get_vaccine = 0;
    shoot_start = clock();
    gun_start = clock();
    item_start = clock();
    zombie_speed_decrease_start = clock();
    double_score_start = clock();
    
    zombie_speed_flag = 1;
    score_flag = 1;
    stage_start_flag = 1;
    item_flag = 1;

    srand(time(0));

    DrawGameBoard();
    SettingMap();

    SetCurrentCursorPos(main_character_position.X, main_character_position.Y);

    while (1)
    {
        if (life <= 0)
        {
            system("cls");
            return;
        }
        SetStage();
        ZombieSpeedTimer(); // ProcessKeyInput ������ ����
        ScoreTimer();

        MakeBossZombie();
        MoveBossZombie();
        ShowEnergyWave();
        MakeNormalZombie();
        MoveNormalZombie();
        MoveEnergyWave();
        MoveBazukaBullet();
        MoveBazukaBullet();
        MoveBazukaBullet();
        //DeleteEnergyWave();
    }
}

void Menual()
{
    system("cls");
    SetCurrentCursorPos(44, 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("*********���ӼҰ�********");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(5, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("���� ���̷��� �������� �̹μ�...");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(72, 5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("�ءء�");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(60, 6);
    printf("�������� :");
    SetCurrentCursorPos(72, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("��");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("��");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("��");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(80, 6);
    printf("�Ϲ����� :");
    SetCurrentCursorPos(92, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("�ߡ�");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(98, 6);
    printf("������ :");
    SetCurrentCursorPos(106, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("�� ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("�� ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("X2 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("VC");

    SetCurrentCursorPos(92, 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("�ߡ�");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(72, 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("�ءء�");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(5, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("�������� ���� ���� ���̷����� ����ƴ�...!");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(5, 8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("� �̰��� Ż���ϰ� ������ ���ؾ���!!!");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(44, 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("**********���۹�**********");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(32, 12);
    printf("��");
    SetCurrentCursorPos(30, 13);
    printf("��");
    SetCurrentCursorPos(34, 13);
    printf("��");
    SetCurrentCursorPos(32, 14);
    printf("��");
    SetCurrentCursorPos(42, 13);
    printf("����Ű�� �̿��� ���ΰ��� ������ �� �־��");
    SetCurrentCursorPos(28, 16);
    printf("SPACE BAR");
    SetCurrentCursorPos(42, 16);
    printf("�����̽� �ٸ� �̿��� ���� ��� ���� óġ�� �� �־��");
    SetCurrentCursorPos(28, 19);
    printf("������");
    SetCurrentCursorPos(42, 19);
    printf("���� Ű�� �̿��� ������ ������ �ٲ� �� �־��");
    SetCurrentCursorPos(36, 22);
    printf("����� �Ҹ��� ������ ������ �ٰ����� �ѾƿͿ�!");
    SetCurrentCursorPos(36, 25);
    printf("��� �����ǿ��� ����� ã�� �ǹ��� Ż���ϼ���!");
    SetCurrentCursorPos(46, 28);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("Press Any Key To Start!!");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    while (1)
    {
        if (_kbhit() != 0)
        {
            system("cls");
            PlayGame();
        }
    }
}

void ChooseMenu()
{
    RemoveCursor();
    TitleDraw();
    int choose_menu_flag = 1;
    while (1)
    {
        if (choose_menu_flag == 1)
        {
            SetCurrentCursorPos(54, 11);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("��");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        SetCurrentCursorPos(58, 11);
        printf("���� ����");
        SetCurrentCursorPos(58, 14);
        printf("���� ����");
        SetCurrentCursorPos(58, 17);
        printf("���� ����");
        for (int i = 0; i < 20; i++)
        {
            int key_input;
            if (_kbhit() != 0)
            {
                key_input = _getch();
                switch (key_input)
                {
                case ENTER:
                    if (choose_menu_flag == 1)
                    {
                        // ���� ����
                        system("cls");
                        PlayGame();
                    }
                    if (choose_menu_flag == 2)
                    {
                        // ���� ���� ȭ��
                        system("cls");
                        Menual();
                    }
                    if (choose_menu_flag == 3)
                    {
                        // ���� ����
                        exit(0);
                    }
                    break;
                case DOWN:
                    if (choose_menu_flag == 1)
                    {
                        SetCurrentCursorPos(54, 11);
                        printf("  ");
                        SetCurrentCursorPos(54, 14);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                        printf("��");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        choose_menu_flag++;
                    }
                    else if (choose_menu_flag == 2)
                    {
                        SetCurrentCursorPos(54, 14);
                        printf("  ");
                        SetCurrentCursorPos(54, 17);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
                        printf("��");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        choose_menu_flag++;
                    }
                    break;
                case UP:
                    if (choose_menu_flag == 3)
                    {
                        SetCurrentCursorPos(54, 17);
                        printf("  ");
                        SetCurrentCursorPos(54, 14);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                        printf("��");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        choose_menu_flag--;
                    }
                    else if (choose_menu_flag == 2)
                    {
                        SetCurrentCursorPos(54, 14);
                        printf("  ");
                        SetCurrentCursorPos(54, 11);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
                        printf("��");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        choose_menu_flag--;
                    }
                    break;
                }
            }
        }
        if (life <= 0)
            break;
    }
    system("cls");
    EndGame();
}

void EndGame()
{
    GameOverDraw();

    int end_game_menu_flag = 1;
    while (1)
    {
        SetCurrentCursorPos(50, 20);
        printf("�ᱹ ������ ���ѳ��� ���߱�...");
        if (end_game_menu_flag == 1)
        {
            SetCurrentCursorPos(54, 25);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("��");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        SetCurrentCursorPos(61, 25);
        printf("�ٽ� ����");
        SetCurrentCursorPos(62, 27);
        printf("������");
        for (int i = 0; i < 20; i++)
        {
            int key_input;
            if (_kbhit() != 0)
            {
                key_input = _getch();
                switch (key_input)
                {
                case ENTER:
                    if (end_game_menu_flag == 1)
                    {
                        // �ٽ� ����
                        system("cls");
                        resetGame();
                        PlayGame();
                    }
                    if (end_game_menu_flag == 2)
                    {
                        // ���� ����
                        exit(0);
                    }
                    break;
                case DOWN:
                    if (end_game_menu_flag == 1)
                    {
                        SetCurrentCursorPos(54, 25);
                        printf("  ");
                        SetCurrentCursorPos(54, 27);
                        printf("��");
                        end_game_menu_flag++;
                    }
                    break;
                case UP:
                    if (end_game_menu_flag == 2)
                    {
                        SetCurrentCursorPos(54, 27);
                        printf("  ");
                        SetCurrentCursorPos(54, 25);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        printf("��");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        end_game_menu_flag--;
                    }
                    break;
                }
            }
        }
    }
}

void GameClear() {
    int x = 30, y = 10;

    system("cls");

    Sleep(150);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    SetCurrentCursorPos(x, y++);
    printf("        ������       ���      ���      ���    ������   ");
    Sleep(150);
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("       ��               ��  ��     �� ��    �� ��    ��           ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("      ��      ����   �����    ��  ��  ��  ��    �����     ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("       ��       ��    ��      ��   ��    ��    ��    ��           ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("        ������   ��        ��  ��          ��    ������   ");
    y++;
    y++;
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("     �����    ��           ������       ���       �����    ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("   ��            ��           ��              ��  ��      ��      ��  ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("   ��            ��           �����       �����     �����    ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("   ��            ��           ��            ��      ��    ��    ��    ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("     �����    ������   ������   ��        ��   ��      ��  ");
    Sleep(2000);
    exit(0);
}

void TitleDraw() {
    int x = 20, y = 3;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetCurrentCursorPos(x, y++);
    printf("������    �����     ���      ���   ������   ������   ������ ");
    SetCurrentCursorPos(x, y++);
    printf("      ��    ��        ��   �� ��    �� ��   ��      ��       ��       ��  ");
    SetCurrentCursorPos(x, y++);
    printf("    ��      ��        ��   ��  ��  ��  ��   �����         ��       �����");
    SetCurrentCursorPos(x, y++);
    printf("  ��        ��        ��   ��    ��    ��   ��      ��       ��       ��");
    SetCurrentCursorPos(x, y++);
    printf("������    �����     ��          ��   ������   ������   ������");
    SetCurrentCursorPos(x, y++);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("�����                   ��               ���             ���         ����  ");
    SetCurrentCursorPos(x, y++);
    printf("��  ���                                    ��                 ��         ��  �� ");
    SetCurrentCursorPos(x, y++);
    printf("��  ��                                                         ��         ��   ");
    SetCurrentCursorPos(x, y++);
    printf("    ��                                                                    ��     ");
    SetCurrentCursorPos(x, y++);
    printf("    ��                                                 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    y++;
    y++;
    y++;
    y++;
    y++;
    y++;
    y++;
    SetCurrentCursorPos(x, y++);
    printf("      ��     ��     ��     �����     �����     ��           �����        ");
    SetCurrentCursorPos(x, y++);
    printf("      ��   ��  ��   ��   ��        ��   ��      ��   ��           ��      ��      ");
    SetCurrentCursorPos(x, y++);
    printf("      ��  ��    ��  ��   ��        ��   �����     ��           ��       ��     ");
    SetCurrentCursorPos(x, y++);
    printf("      �� ��      �� ��   ��        ��   ��   ��      ��           ��      ��      ");
    SetCurrentCursorPos(x, y++);
    printf("      ���        ���     �����     ��     ��    ������   �����        ");
    SetCurrentCursorPos(x, y++);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("      ���                   ���       ��       ��    ���         ����      ");
    SetCurrentCursorPos(x, y++);
    printf("      ���                   ��                          ��         ��  ��  ");
    SetCurrentCursorPos(x, y++);
    printf("      ��                     ��                                         �� ");
    SetCurrentCursorPos(x, y++);
    printf("      ��                                                                ��");
    SetCurrentCursorPos(x, y++);
    printf("      ��                                                 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void GameOverDraw() {
    int x = 8, y = 7;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("  ������       ���      ���      ���    ������         �����     ��        ��   ������   �����       ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf(" ��               ��  ��     �� ��    �� ��    ��               ��        ��    ��      ��    ��           ��      ��     ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("��      ����   �����    ��  ��  ��  ��    �����         ��        ��     ��    ��     �����     �����       ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf(" ��       ��    ��      ��   ��    ��    ��    ��               ��        ��      ��  ��      ��           ��   ��       ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("  ������   ��        ��  ��          ��    ������         �����          ��        ������   ��     ��     ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("  ���                   ��                    ���                 ����                    ���  ���          ��      ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("  ���                   ��                    ��                   ��  ��                    ��      ��          ��     ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("  ��                     ��                    ��                       ��                            ��          ��     ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("  ��                                                                    ��                            ��              ");
    SetCurrentCursorPos(x, y++);
    Sleep(150);
    printf("  ��                                                 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}