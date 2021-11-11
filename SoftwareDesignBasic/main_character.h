#pragma once
#include <Windows.h>
#include <conio.h>
#include "cursor_function.h"
#include "block_function.h"
#include "setting_map.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define INITIAL_MAIN_CHARACTER_POS_X 65
#define INITIAL_MAIN_CHARACTER_POS_Y 20

COORD main_character_position = { INITIAL_MAIN_CHARACTER_POS_X ,INITIAL_MAIN_CHARACTER_POS_Y };

char main_character[4][4] =                     // ���� ĳ���� ǥ��
{
    {0, 0, 0, 0},
    {0, 2, 2, 0},
    {0, 2, 2, 0},
    {0, 0, 0, 0}
};

void ShiftUp()                                  // �����¿� ������
{
    if (!MainCharacterDetectCollision(main_character_position.X + 2, main_character_position.Y-1))
        return;
    DeleteBlock(main_character);
    SetCurrentCursorPos(main_character_position.X, main_character_position.Y -= 1);
    ShowBlock(main_character);
}

void ShiftDown()
{
    if (!MainCharacterDetectCollision(main_character_position.X, main_character_position.Y+1))
        return;
    DeleteBlock(main_character);
    SetCurrentCursorPos(main_character_position.X, main_character_position.Y += 1);
    ShowBlock(main_character);
}

void ShiftRight()
{
    if (!MainCharacterDetectCollision(main_character_position.X + 2, main_character_position.Y))
        return;
    DeleteBlock(main_character);
    SetCurrentCursorPos(main_character_position.X += 2, main_character_position.Y);
    ShowBlock(main_character);
}

void ShiftLeft()
{
    if (!MainCharacterDetectCollision(main_character_position.X - 2, main_character_position.Y))
        return;
    DeleteBlock(main_character);
    SetCurrentCursorPos(main_character_position.X -= 2, main_character_position.Y);
    ShowBlock(main_character);
}

void ProcessKeyInput()              // ����Ű�� �Է¹޾� �����̴� �Լ� ����
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
        Sleep(30);
    }
}

int MainCharacterDetectCollision(int position_x, int position_y)
{
    int board_array_x = (position_x - GBOARD_ORIGIN_X) / 2;
    int board_array_y = position_y - GBOARD_ORIGIN_Y;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (main_character[y][x] == 2 && game_board[board_array_y + y][board_array_x + x] == 1)     // ���� ĳ���Ϳ� ���� �浹�� ��
                return 0;
            if (main_character[y][x] == 2 && game_board[board_array_y + y][board_array_x + x] == 3)     // ���� ĳ���Ϳ� ���� �ε����� ��
            {
                life--;
                for (int i = 0; i < 3; i++)
                {
                    DeleteBlock(main_character);
                    Sleep(30);
                    ShowBlock(main_character);
                }
            }
        }
    }
    return 1;
}