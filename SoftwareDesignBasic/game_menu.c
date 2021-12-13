#include "zombie_world.h"

// ���� ����
void PlayGame() 
{
    system("mode con cols=130 lines=40"); //�ܼ�â ũ�� ����
    life = 3;
    score = 0;
    stage = 5;

    shoot_start = clock();
    gun_start = clock();
    item_start = clock();
    zombie_speed_decrease_start = clock();
    double_score_start = clock();
    item_flag = 1;
    zombie_speed_flag = 1;
    score_flag = 1;
    stage_start_flag = 1;

    srand(time(0));

    DrawGameBoard();
    SettingMap();

    SetCurrentCursorPos(main_character_position.X, main_character_position.Y);

    ShowBlock(main_character[main_character_id]);
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
        ItemTimer();

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
    printf("*********���ӼҰ�********");
    SetCurrentCursorPos(5, 4);
    printf("���� ���̷��� �������� �̹μ�...");
    SetCurrentCursorPos(72, 5);
    printf("�ءء�");
    SetCurrentCursorPos(60, 6);
    printf("�������� :");
    SetCurrentCursorPos(72, 6);
    printf("�آ¡�");
    SetCurrentCursorPos(80, 6);
    printf("�Ϲ����� :");
    SetCurrentCursorPos(92, 6);
    printf("�ߡ�");
    SetCurrentCursorPos(98, 6);
    printf("������ :");
    SetCurrentCursorPos(108, 6);
    printf("��");

    SetCurrentCursorPos(92, 7);
    printf("�ߡ�");
    SetCurrentCursorPos(72, 7);
    printf("�ءء�");
    SetCurrentCursorPos(5, 6);
    printf("�������� ���� ���� ���̷����� ����ƴ�...!");
    SetCurrentCursorPos(5, 8);
    printf("� �̰��� Ż���ϰ� ������ ���ؾ���!!!");
    SetCurrentCursorPos(44, 10);
    printf("**********���۹�**********");
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
    SetCurrentCursorPos(28, 17);
    printf("SPACE BAR");
    SetCurrentCursorPos(42, 17);
    printf("�����̽� �ٸ� �̿��� ���� ��� ���� óġ�� �� �־��");
    SetCurrentCursorPos(28, 21);
    printf("������");
    SetCurrentCursorPos(42, 21);
    printf("���� Ű�� �̿��� ������ ������ �ٲ� �� �־��");

    SetCurrentCursorPos(38, 25);
    printf("�ƹ� Ű�� ���� ������ ������ ������!");

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
            SetCurrentCursorPos(48, 18);
            printf("��");
        }
        SetCurrentCursorPos(52, 18);
        printf("���� ����");
        SetCurrentCursorPos(52, 21);
        printf("���� ����");
        SetCurrentCursorPos(52, 24);
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
                        SetCurrentCursorPos(48, 18);
                        printf("  ");
                        SetCurrentCursorPos(48, 21);
                        printf("��");
                        choose_menu_flag++;
                    }
                    else if (choose_menu_flag == 2)
                    {
                        SetCurrentCursorPos(48, 21);
                        printf("  ");
                        SetCurrentCursorPos(48, 24);
                        printf("��");
                        choose_menu_flag++;
                    }
                    break;
                case UP:
                    if (choose_menu_flag == 3)
                    {
                        SetCurrentCursorPos(48, 24);
                        printf("  ");
                        SetCurrentCursorPos(48, 21);
                        printf("��");
                        choose_menu_flag--;
                    }
                    else if (choose_menu_flag == 2)
                    {
                        SetCurrentCursorPos(48, 21);
                        printf("  ");
                        SetCurrentCursorPos(48, 18);
                        printf("��");
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
    int end_game_menu_flag = 1;
    while (1)
    {
        SetCurrentCursorPos(50, 10);
        printf("�ᱹ ������ ���ѳ��� ���߱�...");
        if (end_game_menu_flag == 1)
        {
            SetCurrentCursorPos(54, 15);
            printf("��");
        }
        SetCurrentCursorPos(61, 15);
        printf("�ٽ� ����");
        SetCurrentCursorPos(62, 17);
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
                        SetCurrentCursorPos(54, 15);
                        printf("  ");
                        SetCurrentCursorPos(54, 17);
                        printf("��");
                        end_game_menu_flag++;
                    }
                    break;
                case UP:
                    if (end_game_menu_flag == 2)
                    {
                        SetCurrentCursorPos(54, 17);
                        printf("  ");
                        SetCurrentCursorPos(54, 15);
                        printf("��");
                        end_game_menu_flag--;
                    }
                    break;
                }
            }
        }
    }
}

void TitleDraw() {
    int x=30, y=4;

    SetCurrentCursorPos(x, y++);
    printf("#####    ####   ##       ##  ######   #####    ##### ");
    SetCurrentCursorPos(x, y++);
    printf("   #    #    #  # #     # #  #   ##     #      #     ");
    SetCurrentCursorPos(x, y++);
    printf("  #     #    #  #  #   #  #  ####       #      ####  ");
    SetCurrentCursorPos(x, y++);
    printf(" #      #    #  #   # #   #  #   ##     #      #     ");
    SetCurrentCursorPos(x, y++);
    printf("#####    ####   #    #    #  ######   #####    ##### ");
    y++;
    SetCurrentCursorPos(x, y++);
    printf("  #    #    #    ####    ######   #        #####     ");
    SetCurrentCursorPos(x, y++);
    printf("  #   # #   #   #    #   #    #   #        #    #    ");
    SetCurrentCursorPos(x, y++);
    printf("  #  #   #  #   #    #   #####    #        #     #   ");
    SetCurrentCursorPos(x, y++);
    printf("  # #     # #   #    #   #   #    #        #    #    ");
    SetCurrentCursorPos(x, y++);
    printf("  ##       ##    ####    #    #   ######   #####     ");
}
