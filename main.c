#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <stdlib.h>
# define LIFE 10

void ClearLindeFromReadBuffer();
void decorateConsole();
int makeRandomNum();
void gotoxy(int x, int y);
void removeConsoleCursor();

void removeConsoleCursor() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 1;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void ClearLindeFromReadBuffer(void) {
	while (getchar() != '\n');
}

void decorateConsole() {
	system("mode con cols=100 lines=30 | title ���� ���߱� ����");
}

int makeRandomNum() {
	srand(time(0));
	return rand() % 100 + 1;
}

void gotoxy(int x, int y) {
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawTitle() {
	printf("\n\n\n");
	printf("      #                      #         #########   #          ########        ########    #\n");
	printf("     # #        ########     #         #       #   #          ########               #    #\n");
	printf("    #   #          ##        #         #       #   ###           ##                  #    #\n");
	printf("  ########        #  #       #####     ########    #            #  #                 #    #\n");
	printf("      #          #    #      #                     #           #    #                #    #\n");
	printf("      #                      #              #######         ############             #    #\n");
	printf("     # #                     #                 ##                 #                       #\n");
	printf("    #   #                    #                #  #                #                       #\n");
	printf(" \n\n\n");
}

int main(void) {
	int num, input, life = LIFE;
	decorateConsole();
	drawTitle();
	num = makeRandomNum();
	printf("**1~100 ���� ���߱� UP DOWN**\n");
	printf("�� ���: %d\n", LIFE);
	while (1) {
		printf("���� �Է�: ");
		scanf("%d", &input);
		if (num == input) {
			printf("����!!! \n ���α׷��� ����˴ϴ�.");
			break;
		}
		else if (input < num) {
			printf("UP\n");
		}
		else {
			printf("DOWN\n");
		}
		life--;
		printf("���� ���: %d\n", life);
		if (life == 0) {
			printf("GAME OVER!\n");
			break;
		}
		ClearLindeFromReadBuffer();
	}
}


/*
int main() {
	gotoxy(1, 1);
	printf("��");
	_getch();
	return 0;
}
*/


