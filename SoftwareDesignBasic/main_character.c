#include "zombie_world.h"

COORD main_character_position = { INITIAL_MAIN_CHARACTER_POS_X ,INITIAL_MAIN_CHARACTER_POS_Y };
int main_character_id = 0;
int invincibility_flag = 0;

char main_character[][2][2] =                     // ���� ĳ���� ǥ��
{
    {
        {2, 7},
        {2, 2}
    },
    {
        {7, 2},
        {2, 2}
    },
    {
        {2, 2},
        {7, 2}
    },
    {
        {2, 2},
        {2, 7}
    }
};

void DeleteBlock(char main_character[2][2])               // ��µ� ����� �����ϴ� �Լ�
{
    int y, x;
    COORD current_position = main_character_position;
    int board_array_x = (current_position.X - GBOARD_ORIGIN_X) / 2;
    int board_array_y = current_position.Y - GBOARD_ORIGIN_Y;

    for (y = 0; y < 2; y++)
    {
        for (x = 0; x < 2; x++)
        {
            SetCurrentCursorPos(current_position.X + (x * 2), current_position.Y + y);
            if (main_character[y][x] == 2 || main_character[y][x] == 7)              // ���� ĳ���Ϳ� ����
            {
                printf("  ");
                game_board[board_array_y + y][board_array_x + x] = 0;
            }
        }
    }
    SetCurrentCursorPos(current_position.X, current_position.Y);
}

void ShowBlock(char main_character[2][2])                // ����� ����ϴ� �Լ�
{
    int y, x;
    COORD current_position = main_character_position;
    int board_array_x = (current_position.X - GBOARD_ORIGIN_X) / 2;
    int board_array_y = current_position.Y - GBOARD_ORIGIN_Y;

    for (y = 0; y < 2; y++)
    {
        for (x = 0; x < 2; x++)
        {
            SetCurrentCursorPos(current_position.X + (x * 2), current_position.Y + y);
            if (main_character[y][x] == 2)                          // ���� ĳ���Ϳ� ����    
            {
                printf("��");
                game_board[board_array_y + y][board_array_x + x] = PLAYER;
            }
            if (main_character[y][x] == 7)                          // ���� ĳ���Ϳ� ����    
            {
                if (main_character_id == 0)
                    printf("��");
                if (main_character_id == 1)
                    printf("��");
                if (main_character_id == 2)
                    printf("��");
                if (main_character_id == 3)
                    printf("��");
                game_board[board_array_y + y][board_array_x + x] = PLAYER;
            }
        }
    }
    SetCurrentCursorPos(current_position.X, current_position.Y);
}

void ShiftUp()                                  // �����¿� ������
{
    if (!MainCharacterDetectCollision(main_character_position.X, main_character_position.Y - 1, main_character[main_character_id]))
        return;
    DeleteBlock(main_character[main_character_id]);
    SetCurrentCursorPos(main_character_position.X, main_character_position.Y -= 1);
    main_character_id = 0;
    ShowBlock(main_character[main_character_id]);
}

void ShiftDown()
{
    if (!MainCharacterDetectCollision(main_character_position.X, main_character_position.Y + 1, main_character[main_character_id]))
        return;
    DeleteBlock(main_character[main_character_id]);
    SetCurrentCursorPos(main_character_position.X, main_character_position.Y += 1);
    main_character_id = 2;
    ShowBlock(main_character[main_character_id]);
}

void ShiftRight()
{
    if (!MainCharacterDetectCollision(main_character_position.X + 2, main_character_position.Y, main_character[main_character_id]))
        return;
    DeleteBlock(main_character[main_character_id]);
    SetCurrentCursorPos(main_character_position.X += 2, main_character_position.Y);
    main_character_id = 3;
    ShowBlock(main_character[main_character_id]);
}

void ShiftLeft()
{
    if (!MainCharacterDetectCollision(main_character_position.X - 2, main_character_position.Y, main_character[main_character_id]))
        return;
    DeleteBlock(main_character[main_character_id]);
    SetCurrentCursorPos(main_character_position.X -= 2, main_character_position.Y);
    main_character_id = 1;
    ShowBlock(main_character[main_character_id]);
}

void ProcessKeyInput(int time)              // ����Ű�� �Է¹޾� �����̴� �Լ� ���� (time �⺻�� 30)
{
    int key_input;
    for (int i = 0; i < 20; i++)
    {
        if (_kbhit() != 0)
        {
            key_input = _getch();
            switch (key_input)
            {
            case LEFT:
                ShiftLeft();
                break;
            case RIGHT:
                ShiftRight();
                break;
            case UP:
                ShiftUp();
                break;
            case DOWN:
                ShiftDown();
                break;
            }
        }
        Sleep(time);
    }
}

void LifeDecrease(int damaged)
{
    invincibility_flag = 1;
    life--;
    LifeSetting();
    if (damaged == PLAYER)                      //�÷��̾ �̵��ϴٰ� �������
    {
        for (int i = 0; i < 2; i++)
        {
            DeleteBlock(main_character[main_character_id]);
            ProcessKeyInput(1);
            ShowBlock(main_character[main_character_id]);
            ProcessKeyInput(1);

        }
    }
    else if (damaged == ZOMBIE)                       //�÷��̾ ������ �ִµ� �ǰݴ��Ѱ��
    {
        ShowBossZombie();
        ShowNormalZombie();
        ShowEnergyWave();
        for (int i = 0; i < 2; i++)
        {
            DeleteBlock(main_character[main_character_id]);
            ProcessKeyInput(1);
            ShowBlock(main_character[main_character_id]);
            ProcessKeyInput(1);
        }
        DeleteBossZombie();
        DeleteNormalZombie();
        DeleteEnergyWave();
    }
    invincibility_flag = 0;
}

int MainCharacterDetectCollision(int position_x, int position_y, char main_character[2][2])
{
    int board_array_x = (position_x - GBOARD_ORIGIN_X) / 2;
    int board_array_y = position_y - GBOARD_ORIGIN_Y;
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            if ((main_character[y][x] == PLAYER && game_board[board_array_y + y][board_array_x + x] == MAP_BOUNDARY) || (main_character[y][x] == PLAYER_RIGHT && game_board[board_array_y + y][board_array_x + x] == MAP_BOUNDARY))     // ���� ĳ���Ϳ� ���� �浹�� ��
            {
                return 0;
            }
            if ((main_character[y][x] == PLAYER && game_board[board_array_y + y][board_array_x + x] == ZOMBIE) || (main_character[y][x] == PLAYER_RIGHT && game_board[board_array_y + y][board_array_x + x] == ZOMBIE))     // ���� ĳ���Ϳ� ���� �ε����� ��
            {
                if (invincibility_flag == 0)
                    LifeDecrease(PLAYER);
                return 0;
            }
            if ((main_character[y][x] == PLAYER && game_board[board_array_y + y][board_array_x + x] == ENERGY_WAVE) || (main_character[y][x] == PLAYER_RIGHT && game_board[board_array_y + y][board_array_x + x] == ENERGY_WAVE))  //���� ĳ���Ϳ� ���񿡳����İ� �ε�������
            {
                LifeDecrease(PLAYER);
                return 0;
            }
            if ((main_character[y][x] == PLAYER && game_board[board_array_y + y][board_array_x + x] == ITEM) || (main_character[y][x] == PLAYER_RIGHT && game_board[board_array_y + y][board_array_x + x] == ITEM))         //���� ĳ���Ϳ� ������ �浹
            {
                ;
            }
        }
    }
    return 1;
}