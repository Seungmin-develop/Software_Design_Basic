#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct Normal_Zombie_Info {
	int x;
	int y;
	int hp;
	struct Normal_Zombie_Info *next;
}Normal_Zombie_Info;

typedef struct {
	Normal_Zombie_Info *header;
}Normal_Zombie_Info_h;

Normal_Zombie_Info_h* createZombieList();

int STAGE;																// ��������
													
Normal_Zombie_Info_h* createZombieList();								// �Ϲ� ����� ���� ������ ���� 0�� �Ǹ� �������� Ŭ����
int MakeNormalZombie();													// �Ϲ� ���� ������ ��ġ�� �������� ����
void ShowNormalZombie();												// �Ϲ������ ȭ�鿡 ���
void DeleteNormalZombie();												// �Ϲ������ �̵��� ���� ȭ�鿡�� ����
void MoveNormalZombie(int player_x, int player_y);                      // �Ϲ����� �̵�
void Remove_Normal_Zombie();											// �Ϲ����� ��ü����(ü���� 0�� �Ǹ� ����)


void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos();
void ShowBlock(char blockinfo[4][4]);
void DeleteBlock(char blockinfo[4][4]);
void Move(int dir, int x, int y);

int main() {
	int i;
	int dir;
	int x, y;
	int num;

	srand(time(NULL));

	num = MakeNormalZombie();

	MoveNormalZombie(player_x, player_y,num);
	

	getchar();
	return 0;
}

Normal_Zombie_Info_h* createZombieList() {
	Normal_Zombie_Info_h *L;
	L = (Normal_Zombie_Info_h*)malloc(sizeof(Normal_Zombie_Info_h));
	L->header = (Normal_Zombie_Info*)malloc(sizeof(Normal_Zombie_Info));
	
	L->header->next = NULL;

	return L;
}

int MakeNormalZombie() {
	int x, y;
	int n = STAGE;

	Num = (NormalZombie*)malloc(n*sizeof(NormalZombie));				// �������� ���� �̿��� �������� ���������� ���� �Ϲ� ������ ���ڸ� ����
	
	x = rand() % 180;		// ������ ��ġ(������ �ϴ� ���� ����)/
	y = rand() % 47;

	return n;
}

void ShowNormalZombie() {
	COORD p = GetCurrentCursorPos();
	int x, y;
	
	printf("��");
	SetCurrentCursorPos(p.X, p.Y);
}

void DeleteNormalZombie() {
	COORD p = GetCurrentCursorPos();
	int x, y;

	printf("  ");
	SetCurrentCursorPos(p.X, p.Y);
}

void MoveNormalZombie(int num) {
	int dir, i;
	int x, y;
	
	for (i = 0; i < num;i++) {
		dir = rand() % 2;

		if (player_x == Num[i].x) {
			dir == 1;
		}
		else if (player_y == Num[i].y) {
			dir == 0;
		}

		if (dir==0) {
			if (player_x - Num[i].x < 0) {
				Num[i].x--;
				SetCurrentCursorPos(x, y);
				ShowNormalZombie();
				Sleep(100);
				DeleteNormalZombie();
			}
			else if (player_x - Num[i].x > 0) {
				Num[i].x++;
				SetCurrentCursorPos(x, y);
				ShowNormalZombie();
				Sleep(100);
				DeleteNormalZombie();
			}
		}

		else if(dir==1){
			if (player_y - Num[i].y < 0) {
				Num[i].y--;
				SetCurrentCursorPos(x, y);
				ShowNormalZombie();
				Sleep(100);
				DeleteNormalZombie();
			}
			else if (player_y - Num[i].y > 0) {
				Num[i].y++;
				SetCurrentCursorPos(x, y);
				ShowNormalZombie();
				Sleep(100);
				DeleteNormalZombie();
			}
		}
	}
}

void Remove_Normal_Zombie(int num) {
	int i;

	for (i = 0; i < num; i++)
	if (Num[i].hp == 0) {

	}
}


COORD GetCurrentCursorPos() {
	CONSOLE_SCREEN_BUFFER_INFO curinfo;
	COORD curpoint;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
	curpoint.X = curinfo.dwCursorPosition.X;
	curpoint.Y = curinfo.dwCursorPosition.Y;

	return curpoint;
}

void SetCurrentCursorPos(int x, int y) {
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}