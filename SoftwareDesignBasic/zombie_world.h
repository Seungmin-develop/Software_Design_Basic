#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
//////////////////////////////////////game_menu.c�� �ִ� �Լ�//////////////////////////////////
void PlayGame();
void Menual();
void ChooseMenu();
void EndGame();
void TitleDraw();
void GameOverDraw();
void GameClear();

//////////////////////////////////////bosszombie.h�� �ִ���/////////////////////////////////////
typedef struct Boss_Zombie_Info {
    COORD pos;
    int cool_time;
    int hp;
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
Boss_Zombie_Info* RemoveBossZombie(Boss_Zombie_Info* dead_boss_zombie); //�������� ��ü����
void MakeEnergyWave(COORD pos, int direction_x, int direction_y);          //�������� ����
void ShowEnergyWave();                      //���������� �������� ȭ�� ���
void MoveEnergyWave();
void DeleteEnergyWave();                    //���������� �������� ȭ�鿡�� ����
EnergyWave_Info* RemoveEnergyWave(EnergyWave_Info* remove_energy_wave);         //�������� ���� 
int BossZombieDetectCollision(int x, int y, int flag);                                    //���������浹 ����
int EnergyWaveDetectCollision(int x, int y);                                    //�������� �浹 ����
void SetGameBoardEnergyWave(COORD pos);                                      //���������� ��ġ ���Ӻ��忡 ����
void PrintBossZombie(COORD pos);                                             //3x3����� �������� ���
void DeletePrintedBossZombie(COORD pos);                                     //3x3����� �������� ����   
EnergyWave_Info* FindEnergyWave(int x, int y);
void SetGameBoardToZero(COORD pos);
Boss_Zombie_Info* DecreaseBossZombieHp(Boss_Zombie_Info* boss_zombie);
void findBossZombie(int x, int y);
COORD MakeBossZombiePos();

void RemoveCursor(void);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);

extern clock_t boss_zombie_start, boss_zombie_end, normal_zombie_start, normal_zombie_end;

//////////////////////////////////////bosszombie.h�� �ִ���/////////////////////////////////////


//////////////////////////////////////mainchar.h�� �ִ���/////////////////////////////////////
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define INITIAL_MAIN_CHARACTER_POS_X 65
#define INITIAL_MAIN_CHARACTER_POS_Y 20
#define WEAPON_1 49
#define WEAPON_2 50
#define WEAPON_3 51
#define WEAPON_4 52
#define WEAPON_5 53

extern COORD main_character_position;
extern int main_character_id;
extern int invincibility_flag;
extern int GunDirection;
clock_t shoot_start, shoot_end, gun_start, gun_end;
extern char main_character[][2][2];               // ���� ĳ���� ǥ��


void DeleteBlock(char main_character[2][2]);
void ShowBlock(char main_character[2][2]);
void ShiftUp();
void ShiftDown();
void ShiftRight();
void ShiftLeft();
void ShowShooting(int x, int y);
void DeleteShooting(int x, int y);
void ShowShotgun(int x, int y);
void ShootGun();
void ProcessKeyInput(int time);
void LifeDecrease();
int MainCharacterDetectCollision(int position_x, int position_y, char main_character[2][2]);
int GunDetectCollision(int position_x, int position_y);

//////////////////////////////////////mainchar.h�� �ִ���/////////////////////////////////////



//////////////////////////////////////bazuka.c�� �ִ���/////////////////////////////////////

typedef struct bazuka_bullet_info {
    COORD pos;
    int direction_x;
    int direction_y;
    struct bazuka_bullet_info* next;
}Bazuka_Bullet_Info;

extern Bazuka_Bullet_Info* bazuka_bullet_list_head;

void SetGameBoardBazukaBullet(COORD pos);
void MakeBazukaBullet(COORD pos, int direction_x, int direction_y);
void ShowBazukaBullet();
Bazuka_Bullet_Info* RemoveBazukaBullet(Bazuka_Bullet_Info* remove_bazuka_bullet);
void ShowOneBazukaBullet(Bazuka_Bullet_Info* bazuka_bullet);
void DeleteOneBazukaBullet(Bazuka_Bullet_Info* bazuka_bullet);
void MoveBazukaBullet();
int BazukaBulletDetectCollision(int x, int y);
void bazuka_explosion(Bazuka_Bullet_Info* bazuka_bullet);

//////////////////////////////////////bazuka.c�� �ִ���/////////////////////////////////////



//////////////////////////////////////normal_zombie.h�� �ִ���/////////////////////////////////////
typedef struct Normal_Zombie_Info {
    COORD pos;
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
Normal_Zombie_Info* RemoveNormalZombie(Normal_Zombie_Info* dead_normal_zombie);// �Ϲ����� ��ü����(ü���� 0�� �Ǹ� ����)
int NormalZombieDetectCollision(int x, int y, int flag);							// �Ϲ����� �浹����
void findNormalZombie(int x, int y);
Normal_Zombie_Info* DecreaseNormalZombieHp(Normal_Zombie_Info* normal_zombie);
COORD MakeNormalZombiePos();

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
#define USABLE_WEAPON_X 51
#define USABLE_WEAPON_Y 37
#define SHOTGUN_RANGE 12
#define WEAPON_COOLTIME 1

#define MAP_BOUNDARY 1
#define PLAYER 2
#define ZOMBIE 3
#define GUN 4
#define ITEM 5
#define ENERGY_WAVE 6
#define PLAYER_RIGHT 7
#define VACCINE 8


extern int score, life, stage, weapon; //����, �����, ��������, ������ ����
extern const char* weapon_name[5]; //���� ����
extern int get_vaccine; // ��� ������ �ִ��� ����

extern int game_board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];

int stage_start_flag;

void DrawGameBoard();
void ScoreSetting();
void LifeSetting();
void WeaponSetting();
void StageSetting();
void VaccineSetting();
void SettingMap();
void SetStage();
void resetGame();
void StageDraw();
void StageErase();
void PrintStage1Map();
void RemoveStage1Map();
void PrintStage2Map();
void RemoveStage2Map();
void PrintStage3Map();
void RemoveStage3Map();
void PrintStage4Map();
void RemoveStage4Map();

typedef struct stage_info {
    int number_of_boss_zombie;
    int number_of_normal_zombie;
    int made_number_of_boss_zombie;
    int made_number_of_normal_zombie;
    int killed_boss_zombie;
    int killed_normal_zombie;
}Stage_Info;
extern Stage_Info stage_info[5];

//////////////////////////////////////setting_map.h�� �ִ���/////////////////////////////////////
int item_flag;
int zombie_speed_flag;
int score_flag;

clock_t item_start;
clock_t item_end;
clock_t zombie_speed_decrease_start;
clock_t zombie_speed_decrease_end;
clock_t double_score_start;
clock_t double_score_end;

int item_type;
int item_location;
int board_array_x, board_array_y;
COORD item_pos;

void RandomItem();
void ShowItem();
void DeleteItem();
void ItemEffect();

void CreateVaccine();
void DeleteVaccine();

void LifeIncreaseItem();
void ZombieSpeedDecreaseItem();
void DoubleScoreItem();

void ItemTimer();
void ZombieSpeedTimer();
void ScoreTimer();

///////////////////////////////////////////item///////////////////////////////////////////////////
