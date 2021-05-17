
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
//#include <unistd.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void food();
void show();
void move();
void turn();
void check();
void ini();
//void calculate();
//int movable[4] = { 0, 1, 1, 0 };  //������±��ʾ����0123�ֱ��ʾ�������ң���ͬ
//int distance[4] = { 9999, 9999, 9999, 9999 };
int  dy[4] = { 0, 1, 0, -1 };
int  dx[4] = { -1, 0, 1, 0 };
int sum = 5;  //���ܳ���
int over = 0;
int speed;   
//int foodx, foody;  //ʳ�������
char map[17][17];

struct snake {
    int x, y;  //�������� 
    int dir;  //����ֻ����ͷ�ķ��������õģ� 
} A[100];

void ini() {  //��ʼ������
    speed = 500;
    over = 0;
    sum = 5;
    //movable[0] = 0; movable[1] = 1; movable[2] = 1; movable[3] = 0;
    //distance[0] = 9999; distance[1] = 9999; distance[2] = 9999; distance[3] = 9999;
    int i, j;
    for (i = 0; i < 100; i++) {  //��ʼ����ͷ�����������
        A[i].dir = 0;
        A[i].x = 0;
        A[i].y = 0;
    }
    A[0].x = 1; A[0].y = 1;  //��ͼ���Ͻ�����һ������Ϊ5����
    A[1].x = 1; A[1].y = 2;
    A[2].x = 1; A[2].y = 3;
    A[3].x = 1; A[3].y = 4;
    A[4].x = 1; A[4].y = 5; A[4].dir = 1;
    srand(time(0));
    for (i = 0; i < 17; i++) {  //���õ�ͼ
        for (j = 0; j < 17; j++) {
            map[i][j] = '*';
        }
    }
    for (i = 1; i < 16; i++) {
        for (j = 1; j < 16; j++) {
            map[i][j] = ' ';
        }
    }
    //map[6][5] = '*'; map[6][6] = '*'; map[6][7] = '*';
    //map[7][5] = '*'; map[7][7] = '*';
    map[A[4].x][A[4].y] = 'H';  //������ͷ
    for (i = 0; i < sum - 1; i++) {  //��������
        map[A[i].x][A[i].y] = 'X';
    }
    food();
    //calculate();
}


void show() {  //��ʾ���� 
    int i, j, x, y;
    for (i = 0; i < 17; i++) {  //��ʾ����
        for (j = 0; j < 17; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    while (1) {
        Sleep(speed);  //����ˢ���ٶ�
        turn();
        move();
        if (over) {  //��������������Խ��еĲ��� 
            while (1) {
                char ch = _getch();
                if (ch == 113) {  //���롮q������ 
                    return;
                }
                else if (ch == 114) {  //���롮r�����¿�ʼ 
                    ini();
                    break;
                }
            }
        }
        system("cls");  //���� 
        for (i = 0; i < 17; i++) {  //������ʾ����
            for (j = 0; j < 17; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        //calculate(); //���㲢��¼��ͷ��ʳ�����
    }
}

void food() {  //����ʳ��
    int x, y;
    while (1) {
        x = (int)(15 * rand() / (RAND_MAX + 1.0));  //�������һ��ʳ������
        y = (int)(15 * rand() / (RAND_MAX + 1.0));
        if (map[x][y] == ' ') {  //����ǿո����ڸô�����ʳ��
            map[x][y] = 'O';
            //foodx = x;  //��¼ʳ������ 
            //foody = y;
            break;
        }
    }
}


void move() {  //���ƶ�
    int i, x, y;
    int t = sum;  //t��¼��ǰ���ܳ��� 
    check();  //�ƶ�ǰ��鰴��ǰ�����ƶ�һ��������
    if (t == sum) {  //û�гԵ�ƻ��
        for (i = 0; i < sum - 1; i++) {
            if (i == 0) {  //��β���괦��ɿո񣬰���β������ǰһ����������� 
                map[A[i].x][A[i].y] = ' ';
                A[i].x = A[i + 1].x;
                A[i].y = A[i + 1].y;
            }
            else {  //ÿ���������궼��Ϊ��ǰһ�����������
                A[i].x = A[i + 1].x;
                A[i].y = A[i + 1].y;
            }
            map[A[i].x][A[i].y] = 'X';  //�ѵ�ͼ���������괦���ַ����óɡ�X��
        }
        A[sum - 1].x = A[sum - 1].x + dx[A[sum - 1].dir];  //��ͷ����ǰ�����ƶ�һ�� 
        A[sum - 1].y = A[sum - 1].y + dy[A[sum - 1].dir];
        map[A[sum - 1].x][A[sum - 1].y] = 'H';  //�ѵ�ͼ����ͷ���괦���ַ����óɡ�H��
    }
    else {  //�Ե�ƻ����sum���1��
        map[A[sum - 2].x][A[sum - 2].y] = 'X';  //�ѵ�ͼ��ԭ��ͷ���괦���ַ����óɡ�X��
        A[sum - 1].x = A[sum - 2].x + dx[A[sum - 2].dir];  //����ͷ��������ԭ��ͷ�ص�ǰ�����ƶ�һ�������� 
        A[sum - 1].y = A[sum - 2].y + dy[A[sum - 2].dir];
        A[sum - 1].dir = A[sum - 2].dir;  //����ͷ����Ϊԭ��ͷ�ķ���
        map[A[sum - 1].x][A[sum - 1].y] = 'H';  //�ѵ�ͼ����ͷ���괦���ַ����óɡ�H��
        food();
    }
    /*for(i = 0; i < 4; i++) {  //��¼�����ߵķ���
        x = A[sum - 1].x + dx[i];
        y = A[sum - 1].y + dy[i];
        if(map[x][y] == ' ' || map[x][y] == 'O') {
            movable[i] = 1;  //���߾ͰѶ�Ӧ�����ֵ����Ϊ1 
        } else {
            if(x != A[0].x || y != A[0].y) {
                movable[i] = 0;  //�����߾ͰѶ�Ӧ�����ֵ����Ϊ0 
            } else {
                movable[i] = 1;
            }
        }
    }*/
}

void check() {  //����Ƿ��������߳Ե�ʳ��
    int x, y, i, j;
    x = A[sum - 1].x + dx[A[sum - 1].dir];  //��¼����ǰ�����ƶ�һ�����ͷ������ 
    y = A[sum - 1].y + dy[A[sum - 1].dir];
    if (map[x][y] == '*' || map[x][y] == 'X') {  //�����ͼ�ϸ����괦�ַ�Ϊ��*����X�������� 
        if (x != A[0].x || y != A[0].y) {  //��β���� 
            map[8][4] = 'G'; map[8][5] = 'A'; map[8][6] = 'M'; map[8][7] = 'E';  //�����GAME OVER�� 
            map[8][9] = 'O'; map[8][10] = 'V'; map[8][11] = 'E'; map[8][12] = 'R';
            map[8][8] = ' ';
            system("cls");
            for (i = 0; i < 17; i++) {
                for (j = 0; j < 17; j++) {
                    printf("%c", map[i][j]);
                }
                printf("\n");
            }
            printf("Input 'r' to restart\nInput 'q' to quit\n");
            over = 1;
        }
    }
    else if (map[x][y] == 'O') {  //�Ե�ƻ�� 
        sum++;  //�����ܳ���1 
        speed = ((600 - sum * 20)>100) ? (600 - sum * 20) : 100; //�ٶȼӿ� 
    }
}

void turn() {  //ת��
    if (_kbhit()) {
        char dir = _getch();  //��ȡ����ļ� 
        switch (dir) {  //�ı䷽�� 
        case 119: A[sum - 1].dir = (A[sum - 1].dir == 2)?2:0; break;
        case 100: A[sum - 1].dir = (A[sum - 1].dir == 3)?3:1; break;
        case 115: A[sum - 1].dir = (A[sum - 1].dir == 0)?0:2; break;
        case 97: A[sum - 1].dir = (A[sum - 1].dir == 1)?1:3; break;
        }
    }
}

/*void calculate() {  //���㲢��¼��ͷ��ʳ�����
    int i = 0, x, y;
    for(i = 0; i < 4; i++) {
        if(movable[i] == 1) {  //����÷������ߣ����¼���ظ÷�����һ������ʳ��ľ��� 
            x = A[sum - 1].x + dx[i];
            y = A[sum - 1].y + dy[i];
            distance[i] = abs(foodx-x)+abs(foody-y);
        } else {  //�����������Ѿ�������Ϊ9999 
            distance[i] = 9999;
        }
    }
}*/

int main() {
    printf("'w''s''a''d'������������\n��Խ���ܵ�Խ��~~~\n");
    printf("���������ʼ\n");
    char ch = _getch();
    system("cls");
    ini();
    show();
    return 0;
}
