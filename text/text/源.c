#include<stdio.h>
#include<stdlib.h>
char x[15][12];
int box[5][2] = { 5,6,2,3,6,1,9,8,4,2 };//箱子的位置，每两个为一组，表示箱子的X,Y坐标
int flag[5][2] = { 2,1,1,10,13,10,4,4,9,1 };//目标点的位置，每两个为一组，表示箱子的X,Y坐标
int actorx = 8, actory = 6;//主角的初始位置。
void move();//主角移动函数
void clearmap();//初始化与更新地图函数
void printmap();//打印地图函数
void movebox();//移动箱子函数
int adjwin();//胜利判断函数，若胜利则返回1
main()
{
	char s;//储存控制指令的变量
	clearmap();
	printmap();
	while (1) {//死循环，让程序不至于中途退出
		if (kbhit()) {//判断是否按下按键
			s = getch();//将按下的按键储存在s中
			move(s);
			s = 0;
		}
		if (adjwin() == 1) {
			printf("You win!\n");
			system("pause");
			return 0;//可以退出程序
		}
	}
}
void move(int key) {
	if (key == 'A' || key == 'a') {
		if (x[actorx - 1][actory] == 'B') {
			movebox(key);//如果主角上方是箱子，进入推箱子判断函数，下边同理
		}
		if (x[actorx - 1][actory] == ' ' || x[actorx - 1][actory] == '*') {
			actorx -= 1;//如果主角上方是空白处‘ ’或目标点‘*’，则上移，下面同理
		}
	}if (key == 'D' || key == 'd') {
		if (x[actorx + 1][actory] == 'B') {
			movebox(key);
		}
		if (x[actorx + 1][actory] == ' ' || x[actorx + 1][actory] == '*') {
			actorx += 1;
		}
	}if (key == 'W' || key == 'w') {
		if (x[actorx][actory - 1] == 'B') {
			movebox(key);
		}
		if (x[actorx][actory - 1] == ' ' || x[actorx][actory - 1] == '*') {
			actory -= 1;
		}
	}if (key == 'S' || key == 's') {
		if (x[actorx][actory + 1] == 'B') {
			movebox(key);
		}
		if (x[actorx][actory + 1] == ' ' || x[actorx][actory + 1] == '*') {
			actory += 1;
		}
	}
	system("cls");//清空屏幕
	printmap();//打印地图，实现地图更新
}
void movebox(int key) {
	int i, j;
	if (key == 'A' || key == 'a') {
		for (i = 0; i < 5; i++) {
			if (box[i][0] == actorx - 1 && box[i][1] == actory) {
				//判断那个箱子在主角的左方，下同理
				if (x[box[i][0] - 1][box[i][1]] != '#') {//判断箱子左方是不是墙，下同理
					box[i][0] -= 1;//箱子左移，下同理
					clearmap();//更新箱子在地图中的位置，由于在箱子上上移后，主角上方变为空地，主角会上移，所以这里不需要变换主角位置
				}
			}
		}
	}
	if (key == 'D' || key == 'd') {
		for (i = 0; i < 5; i++) {
			if (box[i][0] == actorx + 1 && box[i][1] == actory) {
				if (x[box[i][0] + 1][box[i][1]] != '#') {
					box[i][0] += 1;
					clearmap();
				}
			}
		}
	}
	if (key == 'W' || key == 'w') {
		for (i = 0; i < 5; i++) {
			if (box[i][0] == actorx&&box[i][1] == actory - 1) {
				if (x[box[i][0]][box[i][1] - 1] != '#') {
					box[i][1] -= 1;
					clearmap();
				}
			}
		}
	}
	if (key == 'S' || key == 's') {
		for (i = 0; i < 5; i++) {
			if (box[i][0] == actorx&&box[i][1] == actory + 1) {
				if (x[box[i][0]][box[i][1] + 1] != '#') {
					box[i][1] += 1;
					clearmap();
				}
			}
		}
	}
}
void clearmap() {
	int i, j;
	for (j = 0; j < 12; j++) {
		for (i = 0; i < 15; i++) {
			x[i][j] = ' ';//先把地图中所有东西清空
		}
	}
	for (i = 0; i < 15; i++) {
		x[i][0] = '#';
		x[i][11] = '#';
	}
	for (i = 0; i < 12; i++) {
		x[0][i] = '#';
		x[14][i] = '#';
	}
	x[2][5] = '#';
	x[3][1] = '#';
	x[3][2] = '#';
	x[3][3] = '#';
	x[3][4] = '#';
	x[3][5] = '#';
	x[4][5] = '#';
	x[5][5] = '#';
	x[6][5] = '#';
	x[7][5] = '#';
	x[7][6] = '#';
	x[7][7] = '#';
	x[7][8] = '#';
	x[8][8] = '#';
	//安放墙
	for (i = 0; i < 5; i++) {
		x[flag[i][0]][flag[i][1]] = '*';
	}
	//安放目标点
	for (i = 0; i < 5; i++) {
		x[box[i][0]][box[i][1]] = 'B';
	}
	//安放箱子，其位置上有目标点，则覆盖之
}
int adjwin() {
	int i, j, k = 0;
	for (j = 0; j < 12; j++) {
		for (i = 0; i < 15; i++) {
			if (x[i][j] == '*') {
				k = 1;
			}
		}
	}
	if (k == 1) {
		return 0;
	}
	else {
		return 1;
	}
}//判断地图上所有目标点是否被覆盖，若是，则返回1
void printmap() {
	int i, j, k;
	for (j = 0; j < 12; j++) {
		for (i = 0; i < 15; i++) {
			if (i == actorx&&j == actory) {
				printf("$ ");//将主角当前位置用$表示
			}
			else {
				printf("%c ", x[i][j]);
			}
		}
		printf("\n");
	}
}//打印地图中所有符号