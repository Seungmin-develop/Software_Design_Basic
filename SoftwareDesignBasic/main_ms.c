//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <windows.h>
//
//#pragma warining(disable:4996)
//
// //���Ӻ����� ũ�⿡ �°� ������ �迭
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
