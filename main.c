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
	system("mode con cols=100 lines=30 | title 숫자 맞추기 게임");
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
	printf("**1~100 숫자 맞추기 UP DOWN**\n");
	printf("총 목숨: %d\n", LIFE);
	while (1) {
		printf("숫자 입력: ");
		scanf("%d", &input);
		if (num == input) {
			printf("정답!!! \n 프로그램이 종료됩니다.");
			break;
		}
		else if (input < num) {
			printf("UP\n");
		}
		else {
			printf("DOWN\n");
		}
		life--;
		printf("남은 목숨: %d\n", life);
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
	printf("□");
	_getch();
	return 0;
}
*/


