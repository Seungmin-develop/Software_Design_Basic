#include "zombie_world.h";

void RandomItem() {                                         // �������� ���� ��ġ�� ���� ����
	item_location = rand() % 4;
	item_type = 0;   // rand() % 3;

	if (item_location == 0) {
		item_pos.X = GBOARD_ORIGIN_X + 20;
		item_pos.Y = GBOARD_ORIGIN_Y + 7;
	}

	else if (item_location == 1) {
		item_pos.X = GBOARD_ORIGIN_X + (2 * GBOARD_WIDTH) - 20;
		item_pos.Y = GBOARD_ORIGIN_Y + 7;

	}

	else if (item_location == 2) {
		item_pos.X = GBOARD_ORIGIN_X + 20;
		item_pos.Y = GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 7;

	}

	else if (item_location == 3) {
		item_pos.X = GBOARD_ORIGIN_X + (2 * GBOARD_WIDTH) - 20;
		item_pos.Y = GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 7;
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

	shoot_end = clock();
	double time = (double)(shoot_end - shoot_start) / CLOCKS_PER_SEC;
	SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, GBOARD_ORIGIN_Y + GBOARD_HEIGHT+10);
	printf("%lf", time);
	if (time > 5) {
		shoot_start = clock();
		RandomItem();
		ShowItem();
	}

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

}

void DoubleScoreItem() { // ���� 2��

}