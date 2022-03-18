 #include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "axis.h"
#include "robot.hpp"

using namespace std;

int enemyY[1];
int enemyX[1];
int enemyFlag[1];
char robot[2][2]={'*','*',
					'*','*'};
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
	//
}

int main()
{
	char c;
	axis a = make_axis (0,0);
	srand((unsigned) time(0));
	axis t = make_axis (rand()%20,rand()%20);

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
