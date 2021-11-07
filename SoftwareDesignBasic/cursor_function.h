#pragma once
#include <windows.h>
void RemoveCursor(void)             // �����̴� Ŀ���� �����ϱ� ���� �Լ�
{
    CONSOLE_CURSOR_INFO current_info;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &current_info);
    current_info.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &current_info);
}

void SetCurrentCursorPos(int x, int y)                  // Ŀ���� ��ġ�� �����ϴ� �Լ�
{
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

COORD GetCurrentCursorPos(void)                         // ���� Ŀ���� ��ġ�� ��ȯ�ϴ� �Լ�
{
    COORD current_position;
    CONSOLE_SCREEN_BUFFER_INFO current_info;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &current_info);
    current_position.X = current_info.dwCursorPosition.X;
    current_position.Y = current_info.dwCursorPosition.Y;

    return current_position;
}