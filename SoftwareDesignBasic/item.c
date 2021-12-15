#include "zombie_world.h"

void RandomItem() {                                         // �������� ���� ��ġ�� ���� ����
	int temp_item_location;
	temp_item_location = rand() % 4;
	while (temp_item_location == item_location)
	{
		temp_item_location = rand() % 4;
	}
	item_location = temp_item_location;
	item_type = rand() % 3;

	if (item_location == 0) {
		item_pos.X = GBOARD_ORIGIN_X + 53;
		item_pos.Y = GBOARD_ORIGIN_Y + 5;
	}

	else if (item_location == 1) {
		item_pos.X = GBOARD_ORIGIN_X + 11;
		item_pos.Y = GBOARD_ORIGIN_Y + 16;
	}

	else if (item_location == 2) {
		item_pos.X = GBOARD_ORIGIN_X + 89;
		item_pos.Y = GBOARD_ORIGIN_Y + 16;
	}

	else if (item_location == 3) {
		item_pos.X = GBOARD_ORIGIN_X + 53;
		item_pos.Y = GBOARD_ORIGIN_Y + 27;
	}

	board_array_x = (item_pos.X - GBOARD_ORIGIN_X) / 2;
	board_array_y = item_pos.Y - GBOARD_ORIGIN_Y;
}

void ShowItem() {       // ������ �����ֱ�
	SetCurrentCursorPos(item_pos.X, item_pos.Y);
	if (item_type == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("�� ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	if (item_type == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("��");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	if (item_type == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("X2");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	game_board[board_array_y][board_array_x] = ITEM;
}

void CreateVaccine()
{
	if (stage == 3 && get_vaccine == 0)
	{
		SetCurrentCursorPos(20, 5);
		printf("VC");
		game_board[5 - GBOARD_ORIGIN_Y][(20 - GBOARD_ORIGIN_X) / 2] = VACCINE;
	}
}

void DeleteVaccine()
{
	SetCurrentCursorPos(20, 5);
	printf("  ");
	game_board[(21 - GBOARD_ORIGIN_X) / 2][5 - GBOARD_ORIGIN_Y] = 0;
	get_vaccine = 1;
	VaccineSetting();
}

void DeleteItem() {     // ������ ����
	SetCurrentCursorPos(item_pos.X, item_pos.Y);
	printf("  ");
	game_board[board_array_y][board_array_x] = 0;
	item_start = clock();
	item_flag = 1;
}

void ItemEffect() {   // �������� �Ծ��� �� �߻��ϴ� ȿ��
	DeleteItem();
	if (item_type == 0) {
		LifeIncreaseItem();
	}
	else if (item_type == 1) {
		ZombieSpeedDecreaseItem();
	}
	else if (item_type == 2) {
		DoubleScoreItem();
	}
}

void LifeIncreaseItem() { // ���� ����
	life++;
	LifeSetting();
}

void ZombieSpeedDecreaseItem() { // ���� �ӵ� ��������
	zombie_speed_decrease_start = clock();
	zombie_speed_flag = 0;
}

void DoubleScoreItem() { // ���� 2��
	double_score_start = clock();
	score_flag = 0;
}

void ItemTimer() {
	item_end = clock();
	double time = (double)(item_end - item_start) / CLOCKS_PER_SEC;
	if (item_flag == 1 && time > 10) {
		RandomItem();
		ShowItem();
		item_flag = 0;
	}// ������ �� Ÿ��
}

void ZombieSpeedTimer() {
	zombie_speed_decrease_end = clock();
	double time = (double)(zombie_speed_decrease_end - zombie_speed_decrease_start) / CLOCKS_PER_SEC;
	if (zombie_speed_flag == 1) {
		ProcessKeyInput(30);
	}
	else if (zombie_speed_flag == 0) {
		ProcessKeyInput(55);
		if (time > 5) {
			zombie_speed_flag = 1;
		}
	}
}

void ScoreTimer() {
	double_score_end = clock();
	double time = (double)(double_score_end - double_score_start) / CLOCKS_PER_SEC;
	if (score_flag == 0 && time > 10) {
		score_flag = 1;
	}
}