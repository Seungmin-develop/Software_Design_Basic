#pragma once
#include "stdlib.h"
typedef struct Boss_Zombie_Info {
    int x;
    int y;
    struct Boss_Zombie_Info* next;
}Boss_Zombie_Info;

typedef struct EnergyWave_Info {
    int x;
    int y;
    struct EnergyWave_Info* next;
}EnergyWave_Info;

Boss_Zombie_Info* boss_zombie_list_head = NULL;
EnergyWave_Info* energy_wave_list_head = NULL;

void MakeBossZombie();                      //�������� ����
void ShowBossZombie();                      //��������� ȭ�鿡 ���
void MoveBossZombie();                      //�������� �̵�
void DeleteBossZombie();                    //��������� ȭ�鿡�� ����
void Remove_Boss_Zombie(Boss_Zombie_Info* dead_boss_zombie); //�������� ��ü����
void MakeEnergyWave(int x, int y);          //�������� ����
void ShowEnergyWave();                      //���������� �������� ȭ�� ���
void DeleteEnergyWave();                    //���������� �������� ȭ�鿡�� ����

void ShowBossZombie() {
    Boss_Zombie_Info* boss_zombie = boss_zombie_list_head;
    while (boss_zombie != NULL) {
        SetCurrentCursorPos(boss_zombie->x, boss_zombie->y);
        printf("+");
        boss_zombie = boss_zombie->next;
    }
}
void DeleteBossZombie() {
    Boss_Zombie_Info* boss_zombie = boss_zombie_list_head;
    while (boss_zombie != NULL) {
        SetCurrentCursorPos(boss_zombie->x, boss_zombie->y);
        printf(" ");
        boss_zombie = boss_zombie->next;
    }
}
void ShowEnergyWave() {
    EnergyWave_Info* energy_wave = energy_wave_list_head;
    while (energy_wave != NULL) {
        SetCurrentCursorPos(energy_wave->x, energy_wave->y);
        printf("o");
        energy_wave = energy_wave->next;
    }
}
void DeleteEnergyWave() {
    EnergyWave_Info* energy_wave = energy_wave_list_head;
    while (energy_wave != NULL) {
        SetCurrentCursorPos(energy_wave->x, energy_wave->y);
        printf(" ");
        energy_wave = energy_wave->next;
    }
}
void MakeEnergyWave(int x, int y) {
    EnergyWave_Info* energy_wave = (EnergyWave_Info*)malloc(sizeof(EnergyWave_Info));
    energy_wave->x = x;
    energy_wave->y = y;
    energy_wave->next = NULL;
    if (energy_wave_list_head == NULL) {
        energy_wave_list_head = energy_wave;
        return;
    }
    EnergyWave_Info* last_energy_wave = energy_wave_list_head;
    while (last_energy_wave->next != NULL) {
        last_energy_wave = last_energy_wave->next;
    }
    last_energy_wave->next = energy_wave;
}
void MoveBossZombie() {
    Boss_Zombie_Info* boss_zombie = boss_zombie_list_head;
    while (boss_zombie != NULL) {
        if (GBOARD_ORIGIN_X + GBOARD_WIDTH / 2 -1 == boss_zombie->x || GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 2 == boss_zombie->y) {
            MakeEnergyWave(boss_zombie->x, boss_zombie->y);
        }
        else {
            if (rand() % 2) {
                if (GBOARD_ORIGIN_X + GBOARD_WIDTH / 2 - boss_zombie->x < 0) {
                    boss_zombie->x -= 2;
                }
                else {
                    boss_zombie->x += 2;
                }
            }
            else {
                if (GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 2 - boss_zombie->y < 0) {
                    boss_zombie->y--;
                }
                else {
                    boss_zombie->y++;
                }
            }
        }
        boss_zombie = boss_zombie->next;
    }
}

void MakeBossZombie() {
    Boss_Zombie_Info* boss_zombie = (Boss_Zombie_Info*)malloc(sizeof(Boss_Zombie_Info));
    boss_zombie->x = GBOARD_ORIGIN_X + GBOARD_WIDTH / 2;                                //���� ������ ��ġ ���� ���氡��
    boss_zombie->y = GBOARD_ORIGIN_Y;
    boss_zombie->next = NULL;
    if (boss_zombie_list_head == NULL) {
        boss_zombie_list_head = boss_zombie;
        return;
    }
    Boss_Zombie_Info* last_boss_zombie = boss_zombie_list_head;
    while (last_boss_zombie->next != NULL) {
        last_boss_zombie = last_boss_zombie->next;
    }
    last_boss_zombie->next = boss_zombie;
}

void Remove_Boss_Zombie(Boss_Zombie_Info* dead_boss_zombie) {
    Boss_Zombie_Info* boss_zombie = boss_zombie_list_head;
    Boss_Zombie_Info* prev = NULL;
    while (boss_zombie != dead_boss_zombie) {
        prev = boss_zombie;
        boss_zombie = boss_zombie->next;
    }
    if (prev == NULL) {
        boss_zombie_list_head = NULL;
    }
    prev->next = dead_boss_zombie->next;
    free(dead_boss_zombie);
}