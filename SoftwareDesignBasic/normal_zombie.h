#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "setting_map.h"
#include "cursor_function.h"
#include "main_character.h"

typedef struct Normal_Zombie_Info {
	int x;
	int y;
	int hp;
	struct Normal_Zombie_Info* next;
}Normal_Zombie_Info;

Normal_Zombie_Info* normal_zombie_list_head = NULL;

int STAGE;																// ��������										
void MakeNormalZombie();												// �Ϲ� ���� ������ ��ġ�� �������� ����
void ShowNormalZombie();												// �Ϲ������ ȭ�鿡 ���
void DeleteNormalZombie();												// �Ϲ������ �̵��� ���� ȭ�鿡�� ����
void MoveNormalZombie(int player_x, int player_y);                      // �Ϲ����� �̵�
void RemoveNormalZombie(Normal_Zombie_Info* dead_normal_zombie);		// �Ϲ����� ��ü����(ü���� 0�� �Ǹ� ����)
int NormalZombieDetectCollision(int x, int y);							// �Ϲ����� �浹����


void PrintNormalZombie(int zombie_x, int zombie_y)
{
	int board_array_x = (zombie_x - GBOARD_ORIGIN_X) / 2;
	int board_array_y = zombie_y - GBOARD_ORIGIN_Y;

	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			SetCurrentCursorPos(zombie_x + (x * 2), zombie_y + y);
			printf("��");
			game_board[board_array_y + y][board_array_x + x] = ZOMBIE;
		}
	}
	SetCurrentCursorPos(zombie_x, zombie_y);
}
void DeletePrintedNormalZombie(int zombie_x, int zombie_y)
{
	int board_array_x = (zombie_x - GBOARD_ORIGIN_X) / 2;
	int board_array_y = zombie_y - GBOARD_ORIGIN_Y;

	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			SetCurrentCursorPos(zombie_x + (x * 2), zombie_y + y);
			printf("  ");
			game_board[board_array_y + y][board_array_x + x] = 0;
		}
	}
	SetCurrentCursorPos(zombie_x, zombie_y);
}

void ShowNormalZombie() {
	Normal_Zombie_Info* normal_zombie = normal_zombie_list_head;
	while (normal_zombie != NULL) {
		SetCurrentCursorPos(normal_zombie->x, normal_zombie->y);
		PrintNormalZombie(normal_zombie->x, normal_zombie->y);
		normal_zombie = normal_zombie->next;
	}
}

void DeleteNormalZombie() {
	Normal_Zombie_Info* normal_zombie = normal_zombie_list_head;
	while (normal_zombie != NULL) {
		SetCurrentCursorPos(normal_zombie->x, normal_zombie->y);
		DeletePrintedNormalZombie(normal_zombie->x, normal_zombie->y);
		normal_zombie = normal_zombie->next;
	}
}

void MoveNormalZombie() {
	int dir;

	Normal_Zombie_Info* normal_zombie = normal_zombie_list_head;
	while (normal_zombie != NULL) {
		dir = rand() % 2;

		if (main_character_position.X - normal_zombie->x == 0) {
			dir = 1;
		}
		else if (main_character_position.Y - normal_zombie->y == 0) {
			dir = 0;
		}

		if (dir == 0) {
			if (main_character_position.X - normal_zombie->x < 0) {
				if (!NormalZombieDetectCollision(normal_zombie->x, normal_zombie->y))
					normal_zombie->x -= 2;
			}
			else {
				if (!NormalZombieDetectCollision(normal_zombie->x, normal_zombie->y))
					normal_zombie->x += 2;
			}
		}
		else if (dir == 1) {
			if (main_character_position.Y - normal_zombie->y < 0) {
				if (!NormalZombieDetectCollision(normal_zombie->x, normal_zombie->y))
					normal_zombie->y--;
			}
			else {
				if (!NormalZombieDetectCollision(normal_zombie->x, normal_zombie->y))
					normal_zombie->y++;
			}
		}

		normal_zombie = normal_zombie->next;
	}
}

void MakeNormalZombie() {
	int x, y;
	int n = STAGE;
	int cnt = 0;

	Normal_Zombie_Info* normal_zombie = (Normal_Zombie_Info*)malloc(sizeof(Normal_Zombie_Info));
	normal_zombie->x = GBOARD_ORIGIN_X + GBOARD_WIDTH / 2 + 1;                                //���� ������ ��ġ ���� ���氡��
	normal_zombie->y = GBOARD_ORIGIN_Y + 5;
	normal_zombie->next = NULL;
	if (normal_zombie_list_head == NULL) {
		normal_zombie_list_head = normal_zombie;
		return;
	}
	Normal_Zombie_Info* last_normal_zombie = normal_zombie_list_head;
	while (last_normal_zombie->next != NULL) {
		last_normal_zombie = last_normal_zombie->next;
	}
	last_normal_zombie->next = normal_zombie;



	//Num = (NormalZombie*)malloc(n * sizeof(NormalZombie));				// �������� ���� �̿��� �������� ���������� ���� �Ϲ� ������ ���ڸ� ����

}

void RemoveNormalZombie(Normal_Zombie_Info* dead_normal_zombie) {
	Normal_Zombie_Info* normal_zombie = normal_zombie_list_head;
	Normal_Zombie_Info* prev = NULL;
	while (normal_zombie != dead_normal_zombie) {
		prev = normal_zombie;
		normal_zombie = normal_zombie->next;
	}
	if (prev == NULL) {
		normal_zombie_list_head = NULL;
	}
	prev->next = dead_normal_zombie->next;
	free(dead_normal_zombie);
}

int NormalZombieDetectCollision(int x, int y)
{
	int board_array_x = (x - GBOARD_ORIGIN_X) / 2;
	int board_array_y = y - GBOARD_ORIGIN_Y;

	if (game_board[board_array_y][board_array_x] == MAP_BOUNDARY)
	{
		return 1;
	}
	else if (game_board[board_array_y][board_array_x] == PLAYER)
	{
		LifeDecrease();
		return 1;
	}
	else if (game_board[board_array_y][board_array_x] == GUN)
	{
		;
	}
	return 0;
}