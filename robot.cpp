#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "axis.h"
#include "robot.hpp"

using namespace std;

int enemyY[1];
int enemyX[1];
int enemyFlag[1];
//char robot[2][2]={'*','*',
					//'*','*'};
int health = 100;

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
/*void genEnemy(int ind){
	enemyX[ind] = rand();
}
void drawEnemy(int ind){
	if( enemyFlag[ind] == true ){
		gotoxy(enemyX[ind], enemyY[ind]);   cout<<"**";  
		gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"**"; 
	} 
}
void eraseEnemy (int ind){
	if( enemyFlag[ind] == true ){
		gotoxy(enemyX[ind], enemyY[ind]); cout<<"  ";  
		gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"  "; 
	} 
}
void resetEnemy(int ind){
	eraseEnemy(ind);
	enemyY[ind] = 1;
	genEnemy(ind);
}*/

double distance(axis* a, axis* b)
{
	double ret;
	ret = ((*a).x-(*b).x)*((*a).x-(*b).x) + ((*a).y-(*b).y)*((*a).y-(*b).y);
	ret = sqrt(ret);
	return ret;
}

robot::robot()
{
	this->health = 50;
	this->power = 5;
	this->range = 5;
	this->position.x = 0;
	this->position.y = 0;
}

robot::robot(char k, axis a)
{
	if (k == 'r')
	{
		this->health = 50;
		this->power = 5;
		this->range = 5;
	}
	else
	{
		this->health = 15;
		this->power = 1;
		this->range = 40;
	}
	this->position.x =a.x;
	this->position.y =a.y;
}

void robot::moverobot(axis a)
{
	this->position = a;
}

bool robot::isalive()
{
	return (health > 0);
}

void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	getch();
}
void updateHealth(){
	//gotoxy(7, 5);cout<<"Score: "<<health<<endl;
}
void instructions(){

	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Avoid  by moving left, right. ";
	cout<<"\n\n Press 'a' to move left";
	cout<<"\n Press 'd' to move right";
	cout<<"\n Press 'w' to move up";
	cout<<"\n Press 's' to move down";
	cout<<"\n Press 'escape' to exit";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}
void play(){
	system("cls");
	char c;
	robot r;
	int cnt = 0;
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
	axis a = make_axis (0,0);
	while (r.isalive())
	{
		srand((unsigned) time(0));
		axis t = make_axis (rand()%20,rand()%20);
		robot k('k',t);
		gotoxy(t.x,19-t.y);
		printf(".");
		while (k.isalive())
		{
			c = getch();
			if (c == ' ')
			{
				if (distance(&a,&t) <= r.range)
				{
					k.health-=r.power;
				}
				else
				{
					gotoxy(0,20);
					printf("out of range");
					gotoxy(a.x,19-a.y);
				}
			}
			else
			{
				move_axis (&a,c);
				gotoxy(a.x,19-a.y);
			}
			if (distance(&a,&t) <= k.range)
			{
				r.health-=k.power;
				if (!r.isalive())
				{
					break;
				}
			}
		}
		if (!k.isalive())
		{
			cnt++;
		}
	}
	gotoxy(0,20);
	printf("Successfully destroy %d mecha kurama\n",cnt);
	printf("Press any key to go back to menu");
	getch();
}

int main()
{
	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |        Robot War       | "; 
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();

		if( op=='1') play();
		else if( op=='2') instructions();
		else if( op=='3') exit(0);

	}while(1);
    return 0;
}
