#include "zombie_world.h"

typedef struct bazuka_bullet_info {
	COORD pos;
	int direction_x;
	int direction_y;
	struct bazuka_bullet_info* next;
}Bazuka_Bullet_Info;

Bazuka_Bullet_Info* bazuka_bullet_list_head = NULL;

void SetGameBoardBazukaBullet(COORD pos)
{
	int board_array_x = (pos.X - GBOARD_ORIGIN_X) / 2;
	int board_array_y = pos.Y - GBOARD_ORIGIN_Y;
	game_board[board_array_y][board_array_x] = GUN;
}
void MakeBazukaBullet(COORD pos, int direction_x, int direction_y){
	Bazuka_Bullet_Info* bazuka_bullet = (Bazuka_Bullet_Info*)malloc(sizeof(Bazuka_Bullet_Info));
	bazuka_bullet->pos.X = pos.X;
	bazuka_bullet->pos.Y = pos.Y;
	bazuka_bullet->direction_x = direction_x;
	bazuka_bullet->direction_y = directtion_y;
	bazuka_bullet->next = NULL;
	if (bazuka_bullet_list_head == NULL) {
		bazuka_bullet_list_head = bazuka_bullet;
		return;
	}
	Bazuka_Bullet_Info* last_bazuka_bullet = bazuka_bullet_list_head;
	while (last_bazuka_bullet != NULL) {
		last_bazuka_bullet = last_bazuka_bullet->next;
	}
	last_bazuka_bullet->next = bazuka_bullet;
}

void ShowBazukaBullet() {
	Bazuka_Bullet_Info* bazuka_bullet = bazuka_bullet_list_head;
	while (bazuka_bullet != NULL) {
		SetCurrentCursorPos(bazuka_bullet->pos.X, bazuka_bullet->pos.Y);
		SetGameBoardBazukaBullet(bazuka_bullet->pos);
		printf("*");
		bazuka_bullet = bazuka_bullet->next;
	}
}

Bazuka_Bullet_Info* RemoveBazukaBullet(Bazuka_Bullet_Info* remove_bazuka_bullet) {
	Bazuka_Bullet_Info* bazuka_bullet = bazuka_bullet_list_head;
	Bazuka_Bullet_Info* prev = NULL;
	while (bazuka_bullet != remove_bazuka_bullet) {
		prev = bazuka_bullet;
		bazuka_bullet = bazuka_bullet->next;
	}
	if (prev == NULL) {
		Bazuka_Bullet_Info* first = remove_bazuka_bullet->next;
		bazuka_bullet_list_head = first;
		SetCurrentCursorPos(remove_bazuka_bullet->pox.X, remove_bazuka_bullet->pos.Y);
		printf(" ");
		SetGameBoardToZero(remove_bazuka_bullet->pos);
		free(remove_bazuka_bullet);
		return first;
	}
	prev->next = remove_bazuka_bullet->next;
	SetCurrentCursorPos(remove_bazuka_bullet->pox.X, remove_bazuka_bullet->pos.Y);
	printf(" ");
	SetGameBoardToZero(remove_bazuka_bullet->pos);
	free(remove_bazuka_bullet);
	return prev->next;
}
void ShowOneBazukaBullet(Bazuka_Bullet_Info* bazuka_bullet) {
	SetCurrentCursorPos(bazuka_bullet->pos.X, bazuka_bullet->pos.Y);
	SetGameBoardBazukaBullet(bazuka_bullet->pos);
	printf("@");
}
void DeleteOneBazukaBullet(Bazuka_Bullet_Info* bazuka_bullet) {
	SetCurrentCursorPos(bazuka_bullet->pos.X, bazuka_bullet->pos.Y);
	SetGameBoardToZero(remove_bazuka_bullet->pos);
	printf(" ");
}
void MoveBazukaBullet() {
	Bazuka_Bullet_Info* bazuka_bullet = bazuka_bullet_list_head;
	while (bazuka_bullet != NULL) {
		DeleteOneBazukaBullet(bazuka_bullet);
		if (BazukaBulletDetectCollision(bazuka_bullet->pox.X, bazuka_bullet->pos.Y))
			bazuka_bullet = RemoveBazukaBullet(bazuka_bullet);
		else
		{
			bazuka_bullet->pos.X += bazuka_bullet->direction_x *2;
			bazuka_bullet->pos.Y += bazuka_bullet->direction_y;
			ShowOneBazukaBullet(bazuka_bullet);
			bazuka_bullet = bazuka_bullet->next;
		}
	}
}
void BazukaBulletDetectCollision(int x, int y)
{
	int board_array_x = (x - GBOARD_ORIGIN_X) / 2;
	int board_array_y = y - GBOARD_ORIGIN_Y;

	if (game_board[board_array_y][board_array_x] == MAP_BOUNDARY)
	{
		return 1;
	}
	else if (game_board[board_array_y][board_array_x] == PLAYER || game_board[board_array_y][board_array_x] == PLAYER_RIGHT)
	{
		return 1;
	}
	else if (game_board[board_array_y][board_array_x] == ZOMBIE)
	{
		return 1;
	}
	else if (game_board[board_array_y][board_array_x] == ITEM)
	{
		return 1;
	}
	return 0;
}