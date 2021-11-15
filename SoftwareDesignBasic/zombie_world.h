#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

//////////////////////////////////////bosszombie.h�� �ִ���/////////////////////////////////////
typedef struct Boss_Zombie_Info {
    COORD pos;
    int cool_time;
    struct Boss_Zombie_Info* next;
}Boss_Zombie_Info;

typedef struct EnergyWave_Info {
    COORD pos;
    int direction_x;
    int direction_y;
    struct EnergyWave_Info* next;
}EnergyWave_Info;

extern Boss_Zombie_Info* boss_zombie_list_head;
extern EnergyWave_Info* energy_wave_list_head;

void MakeBossZombie();                      //�������� ����
void ShowBossZombie();                      //��������� ȭ�鿡 ���
void MoveBossZombie();                      //�������� �̵�
void DeleteBossZombie();                    //��������� ȭ�鿡�� ����
void RemoveBossZombie(Boss_Zombie_Info* dead_boss_zombie); //�������� ��ü����
void MakeEnergyWave(COORD pos, int direction_x, int direction_y);          //�������� ����
void ShowEnergyWave();                      //���������� �������� ȭ�� ���
void MoveEnergyWave();
void DeleteEnergyWave();                    //���������� �������� ȭ�鿡�� ����
EnergyWave_Info* RemoveEnergyWave(EnergyWave_Info* remove_energy_wave);         //�������� ���� 
int BossZombieDetectCollision(int x, int y);                                    //���������浹 ����
int EnergyWaveDetectCollision(int x, int y);                                    //�������� �浹 ����
void SetGameBoardEnergyWave(COORD pos);                                      //���������� ��ġ ���Ӻ��忡 ����
void PrintBossZombie(COORD pos);                                             //3x3����� �������� ���
void DeletePrintedBossZombie(COORD pos);                                     //3x3����� �������� ����    

void RemoveCursor(void);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);

//////////////////////////////////////bosszombie.h�� �ִ���/////////////////////////////////////


//////////////////////////////////////mainchar.h�� �ִ���/////////////////////////////////////
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define INITIAL_MAIN_CHARACTER_POS_X 65
#define INITIAL_MAIN_CHARACTER_POS_Y 20

extern COORD main_character_position;
extern int main_character_id;
extern int invincibility_flag;

extern char main_character[][2][2];               // ���� ĳ���� ǥ��


void DeleteBlock(char main_character[2][2]);
void ShowBlock(char main_character[2][2]);
void ShiftUp();
void ShiftDown();
void ShiftRight();
void ShiftLeft();
void ProcessKeyInput(int time);
void LifeDecrease(int damaged);
int MainCharacterDetectCollision(int position_x, int position_y, char main_character[2][2]);

//////////////////////////////////////mainchar.h�� �ִ���/////////////////////////////////////

//////////////////////////////////////normal_zombie.h�� �ִ���/////////////////////////////////////
typedef struct Normal_Zombie_Info {
    int x;
    int y;
    int hp;
    struct Normal_Zombie_Info* next;
}Normal_Zombie_Info;

extern Normal_Zombie_Info* normal_zombie_list_head;

extern int STAGE;																// ��������										
void PrintNormalZombie(int zombie_x, int zombie_y);
void DeletePrintedNormalZombie(int zombie_x, int zombie_y);
void MakeNormalZombie();												// �Ϲ� ���� ������ ��ġ�� �������� ����
void ShowNormalZombie();												// �Ϲ������ ȭ�鿡 ���
void DeleteNormalZombie();												// �Ϲ������ �̵��� ���� ȭ�鿡�� ����
void MoveNormalZombie();                      // �Ϲ����� �̵�
void RemoveNormalZombie(Normal_Zombie_Info* dead_normal_zombie);		// �Ϲ����� ��ü����(ü���� 0�� �Ǹ� ����)
int NormalZombieDetectCollision(int x, int y);							// �Ϲ����� �浹����

//////////////////////////////////////normal_zombie.h�� �ִ���/////////////////////////////////////

//////////////////////////////////////setting_map.h�� �ִ���/////////////////////////////////////

#define GBOARD_ORIGIN_X 10  //���Ӻ��尡 �����ϱ� �� x�� ����
#define GBOARD_ORIGIN_Y 3   //���Ӻ��尡 �����ϱ� �� y�� ����

#define GBOARD_WIDTH 53     //���Ӻ����� ũ�� (��輱 ���� X)
#define GBOARD_HEIGHT 32    //���Ӻ����� ũ�� (��輱 ���� X)

#define SCORE_X 10          //SCORE, STAGE �� ȭ�鿡 ���̴� UI�� ��ǥ����
#define SCORE_Y 1           //���� SCORE ������ �����Ѵٸ�    
#define STAGE_X 56          //SetCurrentPos�� SCORE_X, SCORE_Y�� �ְ� ������ ������ ��
#define STAGE_Y 1
#define LIFE_X 107
#define LIFE_Y 1
#define USE_WEAPON_X 19
#define USE_WEAPON_Y 37
#define USABLE_WEAPON_X 57
#define USABLE_WEAPON_Y 37

#define MAP_BOUNDARY 1
#define PLAYER 2
#define ZOMBIE 3
#define GUN 4
#define ITEM 5
#define ENERGY_WAVE 6
#define PLAYER_RIGHT 7


extern int score, life, stage, weapon; //����, �����, ��������, ������ ����
extern const char* weapon_name[5]; //���� ����

extern int game_board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];


void DrawGameBoard();
void ScoreSetting();
void LifeSetting();
void WeaponSetting();
void StageSetting();
void SettingMap();
//////////////////////////////////////setting_map.h�� �ִ���/////////////////////////////////////
