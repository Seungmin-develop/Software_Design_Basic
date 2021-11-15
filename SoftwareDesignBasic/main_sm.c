#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "cursor_function.h"
#include "main_character.h"
#include "block_function.h"
#include "boss_zombie.h"
#include "normal_zombie.h"
#include "setting_map.h"

int main()
{
    RemoveCursor();
    srand(time(0));
    system("mode con cols=130 lines=40"); //�ܼ�â ũ�� ����

    DrawGameBoard();
    SettingMap();

    SetCurrentCursorPos(main_character_position.X, main_character_position.Y);
    ShowBlock(main_character);
    MakeBossZombie();
    MakeNormalZombie();
    while (1)
    {
        ShowBossZombie();
        ShowNormalZombie();
        //ShowEnergyWave();
        ProcessKeyInput(30);
        DeleteBossZombie();
        DeleteNormalZombie();
        //DeleteEnergyWave();
        //MoveEnergyWave();
        MoveNormalZombie();
        MoveBossZombie();
        DeleteBossZombie();
        DeleteNormalZombie();
    }
    return 0;
}