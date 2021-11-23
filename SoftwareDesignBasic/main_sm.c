#include "zombie_world.h"

void Menual();

int main()
{
    RemoveCursor();

    int choose_menu_flag = 1;
    while (1)
    {
        if (choose_menu_flag == 1)
        {
            SetCurrentCursorPos(48, 10);
            printf("��");
        }
        SetCurrentCursorPos(52, 10);
        printf("���� ����");
        SetCurrentCursorPos(52, 13);
        printf("���� ����");
        SetCurrentCursorPos(52, 16);
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
                        SetCurrentCursorPos(48, 10);
                        printf("  ");
                        SetCurrentCursorPos(48, 13);
                        printf("��");
                        choose_menu_flag++;
                    }
                    else if (choose_menu_flag == 2)
                    {
                        SetCurrentCursorPos(48, 13);
                        printf("  ");
                        SetCurrentCursorPos(48, 16);
                        printf("��");
                        choose_menu_flag++;
                    }
                    break;
                case UP:
                    if (choose_menu_flag == 3)
                    {
                        SetCurrentCursorPos(48, 16);
                        printf("  ");
                        SetCurrentCursorPos(48, 13);
                        printf("��");
                        choose_menu_flag--;
                    }
                    else if (choose_menu_flag == 2)
                    {
                        SetCurrentCursorPos(48, 13);
                        printf("  ");
                        SetCurrentCursorPos(48, 10);
                        printf("��");
                        choose_menu_flag--;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

void Menual()
{
    system("cls");
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