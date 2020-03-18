// 贪吃蛇大作战.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
void transport(short ,short[] ,short[]);
void set(short,short);
void read(void);
void clear(void);
void ender(short);
short applex(short);
short appley(short);
static char output[11][11];
int score=0;
int w=0;
int main()
{
	srand((unsigned)time(NULL));
	short x[81];
	short y[81];
	int s=0;
	int time=550;
	short n=3;
	short n0=3;
	char input='d';
	char input0;
	short headx=3,heady=3;
	for(int i=0;i<20;i++)
	{
		for(int q=0;q<20;q++)
			output[i][q]='*';
	}
	for(int i=1;i<10;i++)
	{
		for(int q=1;q<10;q++)
			output[i][q]=' ';
	}
	read();
	set(1,1);
	cout<<"   贪吃蛇大作战";
	set(1,2);
	cout<<"              ";
	set(1,3);
	cout<<"   操作方法：";
	set(1,4);
	cout<<"   w：上 s：下 ";
	set(1,5);
	cout<<"   a：左 d：右";
	set(1,6);
	cout<<"              ";
	set(1,7);
	cout<<"   others：暂停";
	set(1,8);
	cout<<"  输入s开始游戏";
	set(1,9);
	cout<<"   输入q退出";
	char start=0;
	
	while(start=getch())
	{
		if(start=='q')
			exit(0);
		else if(start=='s')
			break;
	}
	short app0x,app0y;
	app0x=applex(headx);
	app0y=appley(heady);
	while(input!='q')
	{
		output[app0y][app0x]='@';
		read();
		char input0=input;
		Sleep(time);
		if(kbhit())
			input=getch();
		if(input0=='w'&&input=='s'||input0=='s'&&input=='w'||input0=='a'&&input=='d'||input0=='d'&&input=='a')
			input=input0;
		if(input=='w')
		{
			w++;
			if(output[heady-1][headx]=='@')
				n++;
			if(output[heady-1][headx]=='*')
				break;
			clear();
			x[0]=headx;
			y[0]=heady;
			transport(n-1,x,y);
			output[--heady][headx]='O ';
		}
		else if(input=='s')
		{
			w++;
			if(output[heady+1][headx]=='@')
				n++;
			if(output[heady+1][headx]=='*')
				break;
			clear();
			x[0]=headx;
			y[0]=heady;
			transport(n-1,x,y);
			output[++heady][headx]='O ';
		}
		else if(input=='a')
		{
			w++;
			if(output[heady][headx-1]=='@')
				n++;
			if(output[heady][headx-1]=='*')
				break;
			clear();
			x[0]=headx;
			y[0]=heady;
			transport(n-1,x,y);
			output[heady][--headx]='O ';
		}
		else if(input=='d')
		{
			w++;
			if(output[heady][headx+1]=='@')
				n++;
			if(output[heady][headx+1]=='*')
				break;
			clear();
			x[0]=headx;
			y[0]=heady;
			transport(n-1,x,y);
			output[heady][++headx]='0 ';
		}
		read();
		if(n0<n)
		{
			w=0;
			if(time>=100)
				time-=50;
			while(output[app0y][app0x]=='*'||output[app0y][app0x]=='$')
			{
				app0x=applex(headx);
				app0y=appley(heady);
			}
		}
		n0=n;
	}
	ender(n);
	cin>>start;
	return 0;
}
void set(short x,short y)
{
	HANDLE Stdout=GetStdHandle(STD_OUTPUT_HANDLE);
	short Col=x,Row=y;
	COORD Position={Col,Row};
	SetConsoleCursorPosition(Stdout,Position);
}
void read(void)
{
	set(0,0);
	for(int i=0;i<11;i++)
	{
		for(int q=0;q<11;q++)
			cout<<output[i][q]<<" ";
		cout<<endl;
	}
}
void transport(short n,short x[],short y[])
{
	if(n==1)
	{
		x[n]=x[n-1];
		y[n]=y[n-1];
	}
	else
	{
		x[n]=x[n-1];
		y[n]=y[n-1];
		n--;
		transport(n,x,y);
	}
	for(int i=0;i<=n;i++)
	{
		output[y[n]][x[n]]='*';
	}
}
void clear(void)
{
	for(int i=1;i<10;i++)
		{
			for(int q=1;q<10;q++)
				output[i][q]=' ';
		}
}
short applex(short x)
{
	int i;
	
	i=rand()%10;
	if(i>8)
		i=i-1;
	return i+1;
}
short appley(short y)
{
	int i;
	i=rand()%10;
	if(i>8)
		i=i-1;
	return i+1;
}
void ender(short n)
{
	score=n-3;
	clear();
	read();
	set(2,5);
	cout<<"G a m e  o v e r";
	set(5,6);
	cout<<"score:"<<score;
}
