// Random Walker By Kushal Pathak
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define h 49
#define w 105
#define path 'X'
char left = '<', right = '>', up = '^', down = 'v';
char walker = '>';
int x = w / 2, y = h / 2, dir = 1, matrix[h][w];

void maximizeWindow();
void init();	   // To fill matrix with empty spaces
void display();	   // To display contents of matrix
void walk();	   // To walk in a random direction by one unit
void delay(float); // To create delay
void random();	   // To generate a random direction

void main()
{
	maximizeWindow();
	init();
	int i, n;
	float speed;
	printf("Random Walker By Kushal Pathak\nEnter steps (eg 100): ");
	scanf("%d", &n);
	printf("Enter speed (eg 0.3): ");
	scanf("%f", &speed);
	for (i = 0; i <= n; i++)
	{
		display();
		printf("--------------------(Step %d)--------------------", i);
		delay(speed);
		walk();
	}
	getch();
}
void init()
{
	srand(time(0));
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
			matrix[i][j] = ' ';
	}
	matrix[h / 2][w / 2] = path;
}
void walk()
{
	random();
	switch (dir)
	{
	case 0:
		y = (y + h - 1) % h;
		walker = up;
		break;
	case 1:
		x = (x + 1) % w;
		walker = right;
		break;
	case 2:
		y = (y + 1) % h;
		walker = down;
		break;
	case 3:
		x = (x + w - 1) % w;
		walker = left;
		break;
	}
	matrix[y][x] = path;
}
void display()
{
	system("cls");
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (j == x && i == y)
				printf("%c ", walker);
			else
				printf("%c ", matrix[i][j]);
		}

		printf("\n");
	}
}
void delay(float n)
{
	int i, j, k;
	for (i = 0; i < 10000; i++)
	{
		for (j = 0; j < 500; j++)
		{
			for (k = 0; k < n * 100; k++)
				;
		}
	}
}
void random()
{
	dir = rand() % 4;
}
void maximizeWindow()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
