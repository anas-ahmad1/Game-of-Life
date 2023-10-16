#include <iostream>
#include"mygraphics.h"
#include"myconsole.h"
#include"gameresources.h"
#include<windows.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	char num[3];
	int x,y,level,half,p1,p2,choice,hurdle1=0,hurdle2=0,helping=0,gc1=0,sc1=0,gc2=0,sc2=0,snaker=0,snakec=0,snaker2=0,snakec2=0,loop,gametype,load=10;
	int counter1=0,counter2=0,cooldown1=0,cooldown2=0,turn,p1r,p2r,p1c,p2c,rx=60,ry=170;
	bool blocked1,blocked2,hurdleused1,hurdleused2,canbuy=false,canbuyatt=false,complete=false;
	int box1[6];
	int box2[6];
	char** board;
	string name1,name2;

	HANDLE myconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD mycursor;
	COLORREF grey = RGB(128,128,128);
	COLORREF white = RGB(255,255,255);
	COLORREF black = RGB(00,00,00);
	COLORREF text = RGB(64,128,128);
	COLORREF darkgrey = RGB(50,50,50);
	COLORREF blue = RGB(22,131,136);
	COLORREF peach = RGB(243,189,47);
	COLORREF lyel = RGB(255,222,98);
	COLORREF yellow = RGB (219,104,24);
	COLORREF red = RGB(217,27,27);

	for(int i=0;i<200;i=i+2)
	{
		COLORREF grey = RGB(i,i,i);
		myDrawTextWithFont(170,150,150,"GAME OF LIFE",black,grey);
		Sleep(50);
	}
	myDrawText(400,320,10,"Press any key to continue",white,black);
	drawkey(25,190);
	drawshield(50,50);
	drawwater(490,30);
	drawsword(200,90);
	drawgold(600,20);
	drawsilver(400,50);
	drawgold(300,-5);
	drawsilver(200,400);
	drawgold(530,450);
	drawgold(920,280);
	drawsilver(830,160);
	drawgold(-10,300);
	drawsilver(400,50);
	drawlion(90,390);
	drawghost(830,400);
	drawfire(890,70);
	drawsnake(650,400);
	drawlock(400,400);
	getch();
	system("CLS");


	myDrawTextWithFont(400,15,120,"MENU",black,peach);
	myDrawTextWithFont(100,200,60,"1- Start a New Game",peach,black);
	myDrawTextWithFont(100,300,60,"2- Load a Game",peach,black);
	myDrawText(300,400,10,"Enter a number to choose its corresponding option",white,black);
	cin>>gametype;

	if(gametype==1)
	{
		cout<<"Player 1 name: ";
		cin>>name1;
		cout<<"Player 2 name: ";
		cin>>name2;
		loop=0;
		level=5;
		for(int i=0;i<6;i++)
		{
			box1[i]='\0';
			box2[i]='\0';
		}
	}
	if(gametype==2)
	{
		string chr;
		ifstream readintvar;
		readintvar.open("intvar.txt");

		readintvar>>chr;
		stringstream geek(chr);
		geek>>loop;
		load=loop;

		readintvar>>chr;
		stringstream geek1(chr);
		geek1>>level;
		readintvar.close();

	}
	for(loop;loop<3;loop++)
	{
		complete=false;
		half=((level*level))/2;
		int* xcord=new int[level*level];
		int* ycord=new int[level*level];
		
		board=new char*[level];
		for(int i=0;i<level;i++)
		{
			board[i]=new char[level];
		}
	for(int i=0;i<level;i++)
	{
		for(int j=0;j<level;j++)
		{
			board[i][j]='\0';
		}
	}

	player player1(name1,level,box1);
	player1.getPlayer(name1,box1);

	player player2(name2,level,box2);
	player2.getPlayer(name2,box2);
	system("CLS");

	gameboard gb(level);
	gb.setcord(level);
	gb.getcord(xcord,ycord);
	string str[32];
	int convert[32];
	if(loop!=load)
	{
		gametype=1;
	}

	if(gametype==1)
	{
		putcoins(board,level);
		gb.setboard(board,level);
		drawboard(level,half,xcord,ycord,board);
		myLine(350,0,350,480,peach);
		blocked1=false,blocked2=false,hurdleused1=false,hurdleused2=false;
		counter1=0,counter2=0,cooldown1=10,cooldown2=10,turn=0,p1r=0,p2r=level-1,p1c=0,p2c=level-1;
		drawplayer1(xcord[0]+25,ycord[0]+2);
		drawplayer2(xcord[level-1]+25,ycord[level-1]+2);
	}
	else if(gametype==2)
	{
		loadgame(str,board,level);
		conversion(loop,level,counter1,counter2,cooldown1,cooldown2,turn,p1r,p2r,p1c,p2c,p1,p2,hurdle1,hurdle2,helping,gc1,gc2,sc1,sc2,snaker2,snakec2,snaker,snakec,blocked1,blocked2,hurdleused1,hurdleused2,box1,box2,str,convert);
		gb.setboard(board,level);
		drawboard(level,half,xcord,ycord,board);
		myLine(350,0,350,480,peach);
		drawplayer1(xcord[p1c]+25,ycord[p1r]+2);
		drawplayer2(xcord[p2c]+25,ycord[p2r]+2);
	}
	
	while(complete!=true)
	{
		
		gb.getboard(board,level);
		if(board[level/2][level/2]=='1' ||  board[level/2][level/2]=='2')
		{
			complete=true;
			break;
		}
		if(turn%2==0)
		{
			player1.getPlayer(name1,box1);
			gc1=box1[4];
			sc1=box1[5];
			myRect(0,0,345,480,black,black);
			mycursor.X=0;
			mycursor.Y=12;
			SetConsoleCursorPosition(myconsole,mycursor);
			if(blocked1!=true)
			{
				myDrawTextWithFont(45,5,50," PLAYER 1 TURN ",black,peach);
				myDrawTextWithFont(10,65,25," --Choose one of the following number-- ",black,peach);
				myDrawTextWithFont(75,100,30," 1-ATTACK / 3-SKIP ",black,peach);
				myDrawTextWithFont(50,350,26,"--Save game by entering 4--",peach,black);
				if(p1c==level-1)
				{
					myRect(xcord[0]+15,ycord[p1r+1]+2,xcord[0]+55,ycord[p1r+1]+45, red, red);
				}
				else
				{
					myRect(xcord[p1c+1]+15,ycord[p1r]+2,xcord[p1c+1]+55,ycord[p1r]+45, red, red);
				}
			}
			else
			{
				myDrawTextWithFont(45,5,50," PLAYER 1 TURN ",black,peach);
				myDrawTextWithFont(35,65,25," --There is a hurdle in your way-- ",black,peach);
				myDrawTextWithFont(25,100,30," 1-ATTACK / 2-DEFEND / 3-SKIP ",black,peach);
				myDrawTextWithFont(50,350,26,"--Save game by entering 4--",peach,black);
			}
			if(blocked1==true)
			{
				if(hurdle2==4)
				{
					myDrawTextWithFont(25,140,30,"Cooldown: INFINITE",black,peach);
				}
				else
				{
					num1(cooldown2-counter2,num);
					myDrawTextWithFont(25,140,30,"Cooldown: ",black,peach);
					myDrawTextWithFont(155,140,30,num,black,peach);
				}
			}
			cin>>choice;
			if(choice==2)
			{
				myRect(0,0,345,480,black,black);
				myDrawTextWithFont(10,5,50,"PLAYER 1 DEFENDING ",black,red);

				defending(p1c,p1r,p2c,p2r,xcord,ycord,gc1,sc1,num,rx,ry,red);
				while(canbuy==false)
				{
					cin>>helping;
					p1=(gc1*10)+(sc1*5);
					canbuy=checkpoints(helping,p1);
					if(canbuy==true)
						usecoinagain(helping,gc1,sc1);
					else
					{
						canbuy=false;
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(35,65,25,"You do not have enough coins left",black,peach);
						myDrawTextWithFont(95,95,20,"Press any key to skip",peach,black);
						getch();
						break;
					}
				}
				box1[4]=gc1;
				box1[5]=sc1;
				player1.setPlayer(name1,box1);

				if(canbuy!=false)
				{
				if(helping==1)
				{
					if(hurdle2==4)
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,30,"SUCESS! Hurdle has been removed",black,peach);
						if(p1c==level-1)
						{
							myRect(xcord[0]+15,ycord[p1r+1]+2,xcord[0]+55,ycord[p1r+1]+45, red, red);
						}
						else
						{
							myRect(xcord[p1c+1]+15,ycord[p1r]+2,xcord[p1c+1]+55,ycord[p1r]+45, red, red);
						}
						Sleep(3000);
						counter2=cooldown2;
					}
					else
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,25,"This helping object have no effect",black,peach);
						myDrawTextWithFont(5,170,25,"on this hurdle. Helping Object wasted",black,peach);
						Sleep(3000);
					}
				}
				if(helping==2)
				{
					if(hurdle2==2)
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,30,"SUCESS! Hurdle has been removed",black,peach);
						if(p1c==level-1)
						{
							myRect(xcord[0]+15,ycord[p1r+1]+2,xcord[0]+55,ycord[p1r+1]+45, red, red);
						}
						else
						{
							myRect(xcord[p1c+1]+15,ycord[p1r]+2,xcord[p1c+1]+55,ycord[p1r]+45, red, red);
						}
						Sleep(3000);
						counter2=cooldown2;
					}
					else
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,25,"This helping object have no effect",black,peach);
						myDrawTextWithFont(5,170,25,"on this hurdle. Helping Object wasted",black,peach);
						Sleep(3000);
					}
				}
				if(helping==3)
				{
					if(hurdle2==3)
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,30,"SUCESS! Hurdle has been removed",black,peach);
						if(p1c==level-1)
						{
							myRect(xcord[0]+15,ycord[p1r+1]+2,xcord[0]+55,ycord[p1r+1]+45, red, red);
						}
						else
						{
							myRect(xcord[p1c+1]+15,ycord[p1r]+2,xcord[p1c+1]+55,ycord[p1r]+45, red, red);
						}
						Sleep(3000);
						counter2=cooldown2;
					}
					else
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,25,"This helping object have no effect",black,peach);
						myDrawTextWithFont(5,170,25,"on this hurdle. Helping Object wasted",black,peach);
						Sleep(3000);
					}
				}
				if(helping==4)
				{
					if(hurdle2==1 || hurdle2==5)
					{
						myRect(0,0,345,480,black,black);
						if(hurdle2==5)
						{
							myRect(xcord[snakec]+15,ycord[snaker]+2,xcord[snakec]+55,ycord[snaker]+45, red, red);
						}
						myDrawTextWithFont(5,140,30,"SUCESS! Hurdle has been removed",black,peach);
						if(p1c==level-1)
						{
							myRect(xcord[0]+15,ycord[p1r+1]+2,xcord[0]+55,ycord[p1r+1]+45, red, red);
						}
						else
						{
							myRect(xcord[p1c+1]+15,ycord[p1r]+2,xcord[p1c+1]+55,ycord[p1r]+45, red, red);
						}
						Sleep(3000);
						counter2=cooldown2;
					}
					else
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,25,"This helping object have no effect",black,peach);
						myDrawTextWithFont(5,170,25,"on this hurdle. Helping Object wasted",black,peach);
						Sleep(3000);
					}
				}
				}
				canbuy=false;
			}
			else if(choice==1)
			{
				myRect(0,0,345,480,black,black);
				myDrawTextWithFont(10,5,50,"PLAYER 1 ATTACKING ",black,red);
				attacking(p1c,p1r,p2c,p2r,xcord,ycord,gc1,sc1,num,rx,ry,red);

				while(canbuyatt==false)
				{
					cin>>hurdle1;
					p1=(gc1*10)+(sc1*5);
					canbuyatt=checkpointsatt(hurdle1,p1);
					if(canbuyatt==true)
						usecoin(hurdle1,gc1,sc1);
					else
					{
						canbuyatt=false;
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(35,65,25,"You do not have enough coins left",black,peach);
						myDrawTextWithFont(95,95,20,"Press any key to skip",peach,black);
						getch();
						break;
					}
				}
				box1[4]=gc1;
				box1[5]=sc1;
				player1.setPlayer(name1,box1);
				if(canbuyatt!=false)
				{
				if(hurdle1==1)
				{
					counter1=0;
					hurdleused1=true;
					blocked2=true;
					lion lion1;
					lion1.print(xcord,ycord,p2c,p2r,level,1,cooldown1,board);
				}
				else if(hurdle1==2)
				{
					counter1=0;
					hurdleused1=true;
					blocked2=true;
					ghost ghost1;
					ghost1.print(xcord,ycord,p2c,p2r,level,1,cooldown1,board);
				}
				else if(hurdle1==3)
				{
					counter1=0;
					hurdleused1=true;
					blocked2=true;
					fire fire1;
					fire1.print(xcord,ycord,p2c,p2r,level,1,cooldown1,board);
				}
				else if(hurdle1==4)
				{
					counter1=0;
					hurdleused1=true;
					blocked2=true;
					lock lock1;
					lock1.print(xcord,ycord,p2c,p2r,level,1,cooldown1,board);
				}
				else if(hurdle1==5)
				{
					myRect(xcord[p2c]+15,ycord[p2r]+2,xcord[p2c]+55,ycord[p2r]+45,blue,blue);
					counter1=0;
					hurdleused1=true;
					blocked2=true;
					snake snake1;
					snake1.print(xcord,ycord,p2c,p2r,level,1,cooldown1,board);
					if(p2c==0)
					{
						snakec2=p2c+level-1;
						snaker2=p2r-1;
					}
					else
					{
						snakec2=p2c-1;
						snaker2=p2r;
					}
					if(p2r<level-1)
					{
						if(p2c+1>level-1 || p2c+2>level-1 || p2c+3>level-1)
						{
							p2c=p2c-level+3;
							p2r=p2r+1;
						}
						else
						{
							p2c=p2c+3;
						}
					}
					else
					{
						if(p2c+1>level-1)
						{
							p2c=p2c;
						}
						else if(p2c+2>level-1)
						{
							p2c=p2c+1;						
						}
						else if(p2c+3>level-1)
						{
							p2c=p2c+2;
						}
						else
						{
							p2c=p2c+3;
						}
					}
					drawplayer2(xcord[p2c]+25,ycord[p2r]+2);
				}
				}
				canbuyatt=false;
			}
			else if(choice==4)
			{
				savegame(loop,level,counter1,counter2,cooldown1,cooldown2,turn,p1r,p2r,p1c,p2c,p1,p2,hurdle1,hurdle2,helping,gc1,gc2,sc1,sc2,snaker2,snakec2,snaker,snakec,blocked1,blocked2,hurdleused1,hurdleused2,box1,box2,board);

			}
			if(hurdleused1==true)
				{
					counter1++;
				}
			if(counter1==cooldown1+1)
			{
				blocked2=false;
				hurdleused1=false;
			}
			if(blocked1==false)
			{
				myRect(xcord[p1c]+15,ycord[p1r]+2,xcord[p1c]+55,ycord[p1r]+45, red, red);
				board[p1r][p1c]='\0';
			}
			if(p1c!=level && blocked1==false)
			{
				p1c++;
			}
			if(p1c==level && blocked1==false)
			{
					p1c=0;
					p1r++;
			}
			if(p1c!=level)
			{
				drawplayer1(xcord[p1c]+25,ycord[p1r]+2);
			}
			if(board[p1r][p1c]=='g')
			{
				box1[4]=box1[4]+1;
				player1.setPlayer(name1,box1);
				myRect(0,0,345,480,black,black);
				myDrawTextWithFont(35,65,25,"Player 1 has found a Gold coin",black,peach);
				Sleep(1500);
			}
			else if(board[p1r][p1c]=='s')
			{
				box1[5]=box1[5]+1;
				player1.setPlayer(name1,box1);
				myRect(0,0,345,480,black,black);
				myDrawTextWithFont(35,65,25,"Player 1 has found a Silver coin",black,peach);
				Sleep(1500);
			}
			board[p1r][p1c]='1';
		}
		else if(turn%2==1)
		{
			player2.getPlayer(name2,box2);
			gc2=box2[4];
			sc2=box2[5];
			myRect(0,0,345,480,black,black);
			mycursor.X=0;
			mycursor.Y=12;
			SetConsoleCursorPosition(myconsole,mycursor);
			myRect(0,0,340,480,black,black);
			if(blocked2!=true)
			{
				myDrawTextWithFont(45,5,50," PLAYER 2 TURN ",black,peach);
				myDrawTextWithFont(10,65,25," --Choose one of the following number-- ",black,peach);
				myDrawTextWithFont(75,100,30," 1-ATTACK / 3-SKIP ",black,peach);
				myDrawTextWithFont(50,350,26,"--Save game by entering 4--",peach,black);
				if(p2c==0)
				{
					myRect(xcord[level-1]+15,ycord[p2r-1]+2,xcord[level-1]+55,ycord[p2r-1]+45,blue,blue);
				}
				else
				{
					myRect(xcord[p2c-1]+15,ycord[p2r]+2,xcord[p2c-1]+55,ycord[p2r]+45,blue,blue);
				}
			}
			else
			{
				myDrawTextWithFont(45,5,50," PLAYER 2 TURN ",black,peach);
				myDrawTextWithFont(35,65,25," --There is a hurdle in your way-- ",black,peach);
				myDrawTextWithFont(25,100,30," 1-ATTACK / 2-DEFEND / 3-SKIP ",black,peach);
				myDrawTextWithFont(50,350,26,"--Save game by entering 4--",peach,black);
			}
			if(blocked2==true)
			{
				num1(cooldown1-counter1,num);
				myDrawTextWithFont(25,140,30,"Cooldown: ",black,peach);
				myDrawTextWithFont(155,140,30,num,black,peach);
			}
			cin>>choice;
			if(choice==2)
			{


				myRect(0,0,345,480,black,black);
				myDrawTextWithFont(10,5,50,"PLAYER 2 DEFENDING ",black,blue);

				defending(p1c,p1r,p2c,p2r,xcord,ycord,gc2,sc2,num,rx,ry,blue);
				while(canbuy==false)
				{
					cin>>helping;
					p2=(gc2*10)+(sc2*5);
					canbuy=checkpoints(helping,p2);
					if(canbuy==true)
						usecoinagain(helping,gc2,sc2);
					else
					{
						canbuy=false;
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(35,65,25,"You do not have enough coins left",black,peach);
						myDrawTextWithFont(95,95,20,"Press any key to skip",peach,black);
						getch();
						break;
					}
				}
				box2[4]=gc2;
				box2[5]=sc2;
				player2.setPlayer(name2,box2);
				if(canbuy!=false)
				{
				if(helping==1)
				{
					if(hurdle1==4)
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,30,"SUCESS! Hurdle has been removed",black,peach);
						if(p2c==0)
						{
							myRect(xcord[level-1]+15,ycord[p2r-1]+2,xcord[level-1]+55,ycord[p2r-1]+45, blue,blue);
						}
						else
						{
							myRect(xcord[p2c-1]+15,ycord[p2r]+2,xcord[p2c-1]+55,ycord[p2r]+45, blue,blue);
						}
						Sleep(3000);
						counter1=cooldown1;
					}
					else
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,25,"This helping object have no effect",black,peach);
						myDrawTextWithFont(5,170,25,"on this hurdle. Helping Object wasted",black,peach);
						Sleep(3000);
					}
				}
				if(helping==2)
				{
					if(hurdle1==2)
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,30,"SUCESS! Hurdle has been removed",black,peach);
						if(p2c==0)
						{
							myRect(xcord[level-1]+15,ycord[p2r-1]+2,xcord[level-1]+55,ycord[p2r-1]+45, blue,blue);
						}
						else
						{
							myRect(xcord[p2c-1]+15,ycord[p2r]+2,xcord[p2c-1]+55,ycord[p2r]+45, blue,blue);
						}
						Sleep(3000);
						counter1=cooldown1;
					}
					else
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,25,"This helping object have no effect",black,peach);
						myDrawTextWithFont(5,170,25,"on this hurdle. Helping Object wasted",black,peach);
						Sleep(3000);
					}
				}
				if(helping==3)
				{
					if(hurdle1==3)
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,30,"SUCESS! Hurdle has been removed",black,peach);
						if(p2c==0)
						{
							myRect(xcord[level-1]+15,ycord[p2r-1]+2,xcord[level-1]+55,ycord[p2r-1]+45, blue,blue);
						}
						else
						{
							myRect(xcord[p2c-1]+15,ycord[p2r]+2,xcord[p2c-1]+55,ycord[p2r]+45, blue,blue);
						}
						Sleep(3000);
						counter1=cooldown1;
					}
					else
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,25,"This helping object have no effect",black,peach);
						myDrawTextWithFont(5,170,25,"on this hurdle. Helping Object wasted",black,peach);
						Sleep(3000);
					}
				}
				if(helping==4)
				{
					if(hurdle1==1 || hurdle1==5)
					{
						myRect(0,0,345,480,black,black);
						if(hurdle1==5)
						{
							myRect(xcord[snakec2]+15,ycord[snaker2]+2,xcord[snakec2]+55,ycord[snaker2]+45, blue,blue);
						}
						myDrawTextWithFont(5,140,30,"SUCESS! Hurdle has been removed",black,peach);
						if(p2c==0)
						{
							myRect(xcord[level-1]+15,ycord[p2r-1]+2,xcord[level-1]+55,ycord[p2r-1]+45, blue,blue);
						}
						else
						{
							myRect(xcord[p2c-1]+15,ycord[p2r]+2,xcord[p2c-1]+55,ycord[p2r]+45, blue,blue);
						}
						Sleep(3000);
						counter1=cooldown1;
					}
					else
					{
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(5,140,25,"This helping object have no effect",black,peach);
						myDrawTextWithFont(5,170,25,"on this hurdle. Helping Object wasted",black,peach);
						Sleep(3000);
					}
				}
				}
				canbuy=false;
			}
			else if(choice==1)
			{
				myRect(0,0,345,480,black,black);
				myDrawTextWithFont(10,5,50,"PLAYER 2 ATTACKING ",black,blue);
				attacking(p1c,p1r,p2c,p2r,xcord,ycord,gc2,sc2,num,rx,ry,blue);

				while(canbuyatt==false)
				{
					cin>>hurdle2;
					p2=(gc1*10)+(sc1*5);
					canbuyatt=checkpointsatt(hurdle2,p2);
					if(canbuyatt==true)
						usecoin(hurdle2,gc2,sc2);
					else
					{
						canbuyatt=false;
						myRect(0,0,345,480,black,black);
						myDrawTextWithFont(35,65,25,"You do not have enough coins left",black,peach);
						myDrawTextWithFont(95,95,20,"Press any key to skip",peach,black);
						getch();
						break;
					}
				}

				box2[4]=gc2;
				box2[5]=sc2;
				player2.setPlayer(name2,box2);

				if(canbuyatt!=false)
				{
				if(hurdle2==1)
				{
					counter2=0;
					hurdleused2=true;
					blocked1=true;
					lion lion2;
					lion2.print(xcord,ycord,p1c,p1r,level,2,cooldown2,board);
				}
				else if(hurdle2==2)
				{
					counter2=0;
					hurdleused2=true;
					blocked1=true;
					ghost ghost2;
					ghost2.print(xcord,ycord,p1c,p1r,level,2,cooldown2,board);
				}
				else if(hurdle2==3)
				{
					counter2=0;
					hurdleused2=true;
					blocked1=true;
					fire fire2;
					fire2.print(xcord,ycord,p1c,p1r,level,2,cooldown2,board);
				}
				else if(hurdle2==4)
				{
					counter2=0;
					hurdleused2=true;
					blocked1=true;
					lock lock2;
					lock2.print(xcord,ycord,p1c,p1r,level,2,cooldown2,board);
				}
				else if(hurdle2==5)
				{
					myRect(xcord[p1c]+15,ycord[p1r]+2,xcord[p1c]+55,ycord[p1r]+45,red,red);
					counter2=0;
					hurdleused2=true;
					blocked1=true;
					snake snake2;
					snake2.print(xcord,ycord,p1c,p1r,level,2,cooldown2,board);
					if(p1c==level-1)
					{
						snakec=0;
						snaker=p1r+1;
					}
					else
					{
						snakec=p1c+1;
						snaker=p1r;
					}
					if(p1r>0)
					{
						if(p1c-1<0 || p1c-2<0 || p1c-3<0)
						{
							p1c=p1c+level-3;
							p1r=p1r-1;
						}
						else
						{
							p1c=p1c-3;
						}
					}
					else
					{
						if(p1c-1<0)
						{
							p1c=p1c;
						}
						else if(p1c-2<0)
						{
							p1c=p1c-1;						
						}
						else if(p1c-3<0)
						{
							p1c=p1c-2;
						}
						else
						{
							p1c=p1c-3;
						}
					}
					drawplayer1(xcord[p1c]+25,ycord[p1r]+2);
				}
				}
				canbuyatt=false;
			}
			else if(choice==4)
			{
				savegame(loop,level,counter1,counter2,cooldown1,cooldown2,turn,p1r,p2r,p1c,p2c,p1,p2,hurdle1,hurdle2,helping,gc1,gc2,sc1,sc2,snaker2,snakec2,snaker,snakec,blocked1,blocked2,hurdleused1,hurdleused2,box1,box2,board);
			}

			if(hurdleused2==true)
			{
				counter2++;
			}
			if(counter2==cooldown2+1)
			{
				blocked1=false;
				hurdleused2=false;
			}
			if(blocked2==false)
			{
				myRect(xcord[p2c]+15,ycord[p2r]+2,xcord[p2c]+55,ycord[p2r]+45, blue, blue);
				board[p2r][p2c]='\0';
			}
			if(p2c!=0 && blocked2==false)
			{
					p2c--;
			}
			else
			{
				if(blocked2==false)
				{
					if(p2r-1>=0)
						p2r--;
					p2c=level-1;
				}
			}
			drawplayer2(xcord[p2c]+25,ycord[p2r]+2);
			if(board[p2r][p2c]=='g')
			{
				box2[4]=box2[4]+1;
				player2.setPlayer(name2,box2);
				myRect(0,0,345,480,black,black);
				myDrawTextWithFont(35,65,25,"Player 2 has found a Gold coin",black,peach);
				Sleep(2000);
			}
			else if(board[p2r][p2c]=='s')
			{
				box2[5]=box2[5]+1;
				player2.setPlayer(name2,box2);
				myRect(0,0,345,480,black,black);
				myDrawTextWithFont(35,65,25,"Player 2 has found a Silver coin",black,peach);
				Sleep(2000);
			}
			board[p2r][p2c]='2';
		}
		gb.setboard(board,level);
		turn++;
	}
	p1=(gc1*10)+(sc1*5);
	p2=(gc2*10)+(sc2*5);
	if(complete==true)
	{
		system("CLS");
		if(board[level/2][level/2]=='1' && (p1>=p2))
		{
			if(loop==0)
			{
				myDrawTextWithFont(200,100,80," Player 1 wins round 1 ",black,red);
			}
			else if(loop==1)
			{
				myDrawTextWithFont(200,100,80," Player 1 wins round 2 ",black,red);
			}
			else if(loop==2)
			{
				myDrawTextWithFont(200,100,80," Player 1 wins round 3 ",black,red);
			}
		}
		else if(board[level/2][level/2]=='2' && (p2>=p1))
		{
			if(loop==0)
			{
				myDrawTextWithFont(200,100,80," Player 2 wins round 1 ",black,blue);
			}
			else if(loop==1)
			{
				myDrawTextWithFont(200,100,80," Player 2 wins round 2 ",black,blue);
			}
			else if(loop==2)
			{
				myDrawTextWithFont(200,100,80," Player 2 wins round 3 ",black,blue);
			}
		}
		else
		{
			myDrawTextWithFont(300,100,80," Round Drawn ",black,peach);
		}
		if(loop<3)
		{
			myDrawTextWithFont(250,200,40," Press any key to move to next round " ,blue,black);
		}
	}
	level=level+2;
	getch();
	}
	system("pause");
}