#pragma once
#include <windows.h>
#include <stdio.h>
#include "cursor_function.h"
#include "main_character.h"

//void DeleteBlock(char main_character[4][4])               // ��µ� ����� �����ϴ� �Լ�
//{
//    int y, x;
//    COORD current_position = main_character_position;
//    for (y = 0; y < 4; y++)
//    {
//        for (x = 0; x < 4; x++)
//        {
//            SetCurrentCursorPos(current_position.X + (x * 2), current_position.Y + y);
//            if (main_character[y][x] == 2)              // ���� ĳ���Ϳ� ����
//                printf("  ");
//        }
//    }
//    SetCurrentCursorPos(current_position.X, current_position.Y);
//}
//
//void ShowBlock(char main_character[4][4])                // ����� ����ϴ� �Լ�
//{
//    int y, x;
//    COORD current_position = main_character_position;
//    for (y = 0; y < 4; y++)
//    {
//        for (x = 0; x < 4; x++)
//        {
//            SetCurrentCursorPos(current_position.X + (x * 2), current_position.Y + y);
//            if (main_character[y][x] == 2)                          // ���� ĳ���Ϳ� ����    
//                printf("��");
//        }
//    }
//    SetCurrentCursorPos(current_position.X, current_position.Y);
//}