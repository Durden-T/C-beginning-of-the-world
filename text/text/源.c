#include<stdio.h>
#include<stdlib.h>
char x[15][12];
int box[5][2] = { 5,6,2,3,6,1,9,8,4,2 };//���ӵ�λ�ã�ÿ����Ϊһ�飬��ʾ���ӵ�X,Y����
int flag[5][2] = { 2,1,1,10,13,10,4,4,9,1 };//Ŀ����λ�ã�ÿ����Ϊһ�飬��ʾ���ӵ�X,Y����
int actorx = 8, actory = 6;//���ǵĳ�ʼλ�á�
void move();//�����ƶ�����
void clearmap();//��ʼ������µ�ͼ����
void printmap();//��ӡ��ͼ����
void movebox();//�ƶ����Ӻ���
int adjwin();//ʤ���жϺ�������ʤ���򷵻�1
main()
{
	char s;//�������ָ��ı���
	clearmap();
	printmap();
	while (1) {//��ѭ�����ó���������;�˳�
		if (kbhit()) {//�ж��Ƿ��°���
			s = getch();//�����µİ���������s��
			move(s);
			s = 0;
		}
		if (adjwin() == 1) {
			printf("You win!\n");
			system("pause");
			return 0;//�����˳�����
		}
	}
}
void move(int key) {
	if (key == 'A' || key == 'a') {
		if (x[actorx - 1][actory] == 'B') {
			movebox(key);//��������Ϸ������ӣ������������жϺ������±�ͬ��
		}
		if (x[actorx - 1][actory] == ' ' || x[actorx - 1][actory] == '*') {
			actorx -= 1;//��������Ϸ��ǿհ״��� ����Ŀ��㡮*���������ƣ�����ͬ��
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
	system("cls");//�����Ļ
	printmap();//��ӡ��ͼ��ʵ�ֵ�ͼ����
}
void movebox(int key) {
	int i, j;
	if (key == 'A' || key == 'a') {
		for (i = 0; i < 5; i++) {
			if (box[i][0] == actorx - 1 && box[i][1] == actory) {
				//�ж��Ǹ����������ǵ��󷽣���ͬ��
				if (x[box[i][0] - 1][box[i][1]] != '#') {//�ж��������ǲ���ǽ����ͬ��
					box[i][0] -= 1;//�������ƣ���ͬ��
					clearmap();//���������ڵ�ͼ�е�λ�ã����������������ƺ������Ϸ���Ϊ�յأ����ǻ����ƣ��������ﲻ��Ҫ�任����λ��
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
			x[i][j] = ' ';//�Ȱѵ�ͼ�����ж������
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
	//����ǽ
	for (i = 0; i < 5; i++) {
		x[flag[i][0]][flag[i][1]] = '*';
	}
	//����Ŀ���
	for (i = 0; i < 5; i++) {
		x[box[i][0]][box[i][1]] = 'B';
	}
	//�������ӣ���λ������Ŀ��㣬�򸲸�֮
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
}//�жϵ�ͼ������Ŀ����Ƿ񱻸��ǣ����ǣ��򷵻�1
void printmap() {
	int i, j, k;
	for (j = 0; j < 12; j++) {
		for (i = 0; i < 15; i++) {
			if (i == actorx&&j == actory) {
				printf("$ ");//�����ǵ�ǰλ����$��ʾ
			}
			else {
				printf("%c ", x[i][j]);
			}
		}
		printf("\n");
	}
}//��ӡ��ͼ�����з���