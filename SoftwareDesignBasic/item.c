#include "zombie_world.h";

void RandomItem() {                                         // �������� ���� ��ġ�� ���� ����
	item_location = rand() % 4;
	item_type = rand() % 3;

	if (item_location == 0) {
		item_pos.X = (rand() % GBOARD_WIDTH) + (GBOARD_ORIGIN_X + 1);
		item_pos.Y = (rand() % (GBOARD_HEIGHT / 2)) + (GBOARD_ORIGIN_Y + 1);
	}

	else if (item_location == 1) {
		item_pos.X = (rand() % GBOARD_WIDTH) + (GBOARD_ORIGIN_X + GBOARD_WIDTH);
		item_pos.Y = (rand() % (GBOARD_HEIGHT / 2)) + (GBOARD_ORIGIN_Y + 1);
	}

	else if (item_location == 2) {
		item_pos.X = (rand() % GBOARD_WIDTH) + (GBOARD_ORIGIN_X + 1);
		item_pos.Y = (rand() % (GBOARD_HEIGHT / 2)) + (GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 2);
	}

	else if (item_location == 3) {
		item_pos.X = (rand() % GBOARD_WIDTH) + (GBOARD_ORIGIN_X + GBOARD_WIDTH);
		item_pos.Y = (rand() % (GBOARD_HEIGHT / 2)) + (GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 2);
	}

	board_array_x = (item_pos.X - GBOARD_ORIGIN_X) / 2;
	board_array_y = item_pos.Y - GBOARD_ORIGIN_Y;
}

void ShowItem() {       // ������ �����ֱ�
	SetCurrentCursorPos(item_pos.X, item_pos.Y);
	printf("��");
	game_board[board_array_y][board_array_x] = ITEM;
}

void DeleteItem() {     // ������ ����
	SetCurrentCursorPos(item_pos.X, item_pos.Y);
	printf("  ");
	game_board[board_array_y][board_array_x] = 0;
}

void ItemEffect() {   // �������� �Ծ��� �� �߻��ϴ� ȿ��
	DeleteItem();
	item_start = clock();
	item_flag = 1;
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
	if (item_flag == 1 && time > 1) {
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