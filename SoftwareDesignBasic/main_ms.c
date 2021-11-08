//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <windows.h>
//
//#pragma warining(disable:4996)
//
//#define GBOARD_ORIGIN_X 10  //���Ӻ��尡 �����ϱ� �� x�� ����
//#define GBOARD_ORIGIN_Y 3   //���Ӻ��尡 �����ϱ� �� y�� ����
//
//#define GBOARD_WIDTH 53     //���Ӻ����� ũ�� (��輱 ���� X)
//#define GBOARD_HEIGHT 32    //���Ӻ����� ũ�� (��輱 ���� X)
//
//#define SCORE_X 10          //SCORE, STAGE �� ȭ�鿡 ���̴� UI�� ��ǥ����
//#define SCORE_Y 1           //���� SCORE ������ �����Ѵٸ�    
//#define STAGE_X 56          //SetCurrentPos�� SCORE_X, SCORE_Y�� �ְ� ������ ������ ��
//#define STAGE_Y 1
//#define LIFE_X 107
//#define LIFE_Y 1
//#define USE_WEAPON_X 19
//#define USE_WEAPON_Y 37
//#define USABLE_WEAPON_X 57
//#define USABLE_WEAPON_Y 37
//
//
//int score = 0, life = 3, stage = 3, weapon = 3;  //����, �����, ��������, ������ ����
//char* weaponName[5] = { "����", "�������", "����", "������", "����ī" }; //���� ����
//int curPosX, curPosY;                   //���콺 Ŀ��
//int gameBoard[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2]; //���Ӻ����� ũ�⿡ �°� ������ �迭
//                                                    //�׵θ��� 1�� ������ �׷��ϱ� GBOARD_WIDTH * GBORAD_HEIGHT��
//                                                    //�׸�ŭ�� ������ ���������� 0��
//
//void RemoveCursor(void); //Ŀ�� �����̴� �� ����
//void SetCurrentCursorPos(int pos_x, int pos_y); //Ŀ�� ��ġ �����Լ�
//void DrawGameBoard();           //ó�� ���� �� gameboard �׷��ִ°�
//void SettingMap();              //ó�� ���۽� �⺻ UI �׷���
//void ScoreSetting();            //SCORE�� �ٲ� ȣ�����ִ� �Լ�
//void LifeSetting();             //LIFE�� �ٲ� �� ȣ�����ִ� �Լ�
//void WeaponSetting();           //���⸦ ��ü�Ҷ� ȣ�����ִ� �Լ�
//void StageSetting();            //STAGE�� �ö󰥶� ȣ�����ִ� �Լ�
//
//int main() {
//
//    RemoveCursor();
//    srand(time(0));
//    system("mode con cols=130 lines=40"); //�ܼ�â ũ�� ����
//
//    DrawGameBoard();
//    SettingMap();
//
//
//    while (1) {
//
//    }
//
//    return 0;
//}
//
//void SetCurrentCursorPos(int pos_x, int pos_y) {
//    COORD p1 = { pos_x, pos_y };
//
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p1);
//}
//
//void RemoveCursor(void)
//{
//    CONSOLE_CURSOR_INFO curInfo;
//    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//    curInfo.bVisible = 0;
//    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//}
//
//void DrawGameBoard() {
//    int x, y;
//    for (y = 0; y <= GBOARD_HEIGHT; y++) {
//        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
//        if (y == 0)
//            printf("��");
//        else if (y == GBOARD_HEIGHT)
//            printf("��");
//        else
//            printf("��");
//    }
//
//    for (y = 0; y <= GBOARD_HEIGHT; y++) {
//        SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);
//        if (y == 0)
//            printf("��");
//        else if (y == GBOARD_HEIGHT)
//            printf("��");
//        else
//            printf("��");
//    }
//
//    for (x = 1; x <= GBOARD_WIDTH; x++) {
//        SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y);
//        printf("��");
//        SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
//        printf("��");
//    }
//
//    for (int i = 0; i <= GBOARD_HEIGHT; i++) {
//        gameBoard[i][0] = 1;
//        gameBoard[i][GBOARD_WIDTH + 2];
//    }
//
//    for (int i = 0; i < GBOARD_WIDTH + 2; i++) {
//        gameBoard[0][i] = 1;
//        gameBoard[GBOARD_HEIGHT + 1][i];
//    }
//}
//
//void SettingMap() {
//    SetCurrentCursorPos(SCORE_X - 8, SCORE_Y);
//    puts("SCORE : ");
//    SetCurrentCursorPos(STAGE_X - 8, STAGE_Y);
//    puts("STAGE : ");
//    SetCurrentCursorPos(LIFE_X - 7, LIFE_Y);
//    puts("LIFE : ");
//    SetCurrentCursorPos(USE_WEAPON_X - 17, USE_WEAPON_Y);
//    puts("��� ���� ���� : ");
//    SetCurrentCursorPos(USABLE_WEAPON_X - 17, USABLE_WEAPON_Y);
//    puts("��ü ���� ���� : ");
//
//    ScoreSetting();
//    LifeSetting();
//    WeaponSetting();
//    StageSetting();
//}
//
//void ScoreSetting() {
//    SetCurrentCursorPos(SCORE_X, SCORE_Y);
//    printf("%d", score);
//}
//
//void LifeSetting() {
//    SetCurrentCursorPos(LIFE_X, LIFE_Y);
//    for (int i = 0; i < life; i++) {
//        printf("�� ");
//    }
//}
//void WeaponSetting() {
//    SetCurrentCursorPos(USE_WEAPON_X, USE_WEAPON_Y);
//    for (int i = 1; i <= 5; i++) {
//        if (i == weapon)
//            printf("%s", weaponName[i - 1]);
//    }
//    SetCurrentCursorPos(USABLE_WEAPON_X, USABLE_WEAPON_Y);
//    for (int i = 1; i <= 5; i++) {
//        if (i != weapon && i <= stage) {
//            printf("%s  ", weaponName[i - 1]);
//        }
//    }
//}
//void StageSetting() {
//    SetCurrentCursorPos(STAGE_X, STAGE_Y);
//    for (int i = 0; i < stage; i++) {
//        printf("�� ");
//    }
//}