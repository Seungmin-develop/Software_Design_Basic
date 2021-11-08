#pragma once
#include <stdlib.h>

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
void Remove_Normal_Zombie(Normal_Zombie_Info* dead_normal_zombie);		// �Ϲ����� ��ü����(ü���� 0�� �Ǹ� ����)


void ShowNormalZombie() {
	Normal_Zombie_Info* normal_zombie = normal_zombie_list_head;
	while (normal_zombie != NULL) {
		SetCurrentCursorPos(normal_zombie->x, normal_zombie->y);
		printf("+");
		normal_zombie = normal_zombie->next;
	}
}

void DeleteNormalZombie() {
	Normal_Zombie_Info* normal_zombie = normal_zombie_list_head;
	while (normal_zombie != NULL) {
		SetCurrentCursorPos(normal_zombie->x, normal_zombie->y);
		printf(" ");
		normal_zombie = normal_zombie->next;
	}
}

void MoveNormalZombie(int num) {
	int dir;

	Normal_Zombie_Info* normal_zombie = normal_zombie_list_head;
	while (normal_zombie != NULL) {
		dir = rand() % 2;

		if (GBOARD_ORIGIN_X + GBOARD_WIDTH / 2 - normal_zombie->x == 0) {
			dir == 1;
		}
		else if (GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 2 - normal_zombie->y == 0) {
			dir == 0;
		}

		if (dir == 0) {
			if (GBOARD_ORIGIN_X + GBOARD_WIDTH / 2 - normal_zombie->x < 0) {
				normal_zombie->x -= 2;
			}
			else {
				normal_zombie->x += 2;
			}
		}
		else if (dir == 1) {
			if (GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 2 - normal_zombie->y < 0) {
				normal_zombie->y--;
			}
			else {
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
	normal_zombie->x = GBOARD_ORIGIN_X + GBOARD_WIDTH / 2;                                //���� ������ ��ġ ���� ���氡��
	normal_zombie->y = GBOARD_ORIGIN_Y;
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

void Remove_Normal_Zombie(Normal_Zombie_Info* dead_normal_zombie) {
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
