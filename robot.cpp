#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "axis.h"
#include "robot.hpp"

using namespace std;

axis make_axis (int x, int y)
{
	axis a;
	a.x = x;
	a.y = y;
	return a;
}

void move_axis (axis* a, char c)
{
	if (c == 'w')
	{
		(*a).y++;
	}
	if (c == 'd')
	{
		(*a).x++;
	}
	if (c == 's')
	{
		if ((*a).y != 0)
		{
			(*a).y--;
		}
	}
	if (c == 'a')
	{
		if ((*a).x != 0)
		{
			(*a).x--;
		}
	}
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}

double distance(axis* a, axis* b)
{
	double ret;
	ret = ((*a).x-(*b).x)*((*a).x-(*b).x) + ((*a).y-(*b).y)*((*a).y-(*b).y);
	ret = sqrt(ret);
	return ret;
}

int main()
{
	char c;
	axis a = make_axis (0,0);
	srand((unsigned) time(0));
	axis t = make_axis (rand()%20,rand()%20);
	for (int i = 0; i < 20; i++)
	{
		printf("|");
		if (i != 19)
		{
			printf("\n");
		}
	}
	for (int i = 0; i < 20; i++)
	{
		printf("_");
	}
	gotoxy(t.x,19-t.y);
	printf(".");
	gotoxy(0,20);
	printf("%d, %d\n", t.x, t.y);
	while (true)
	{
		c = getch();
		move_axis (&a,c);
		gotoxy(a.x,19-a.y);
	}
    return 0;
}
