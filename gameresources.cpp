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

bag::bag()
{
	for(int i=0;i<6;i++)
	{
		box[i]='\0';
	}
	points=0;
}

bag::bag(int level)
{
	for(int i=0;i<4;i++)
	{
		box[i]=0;
	}
	box[4]=level*2;						//Gold
	box[5]=level*4;						//Silver
}

void bag::setbox(int b[6])
{
	for(int i=0;i<6;i++)
	{
		box[i]=b[i];
	}

}

void bag::getbox(int b[6])
{
	for(int i=0;i<6;i++)
	{
		b[i]=box[i];
	}
}


//player::player()
//{
//	points=0;
//}

player::player(string n,int level,int b[6]):mybag(level)
{
	this->level=level;
	name=n;
}

void player::setPlayer(string n,int box[6])
{
	name=n;
	mybag.setbox(box);
}

void player::getPlayer(string n,int box[6])
{
	n=name;
	mybag.getbox(box);
}

gameboard::gameboard(int n)
{
	this->size=n;
	board=new char*[size];
	for(int i=0;i<size;i++)
	{
		board[i]=new char[size]; 
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			board[i][j]='\0';
		}
	}
	board[0][0]='1';
	board[n-1][n-1]='2';

	x=new int[size*size];
	y=new int[size*size];
}

void gameboard::setcord(int size)
{
	int count=0,x,ycord=35;
	for(int i=0;i<size;i++)
	{
		x=400;
		for(int j=0;j<size;j++)
		{
			this->x[count]=x;
			this->y[i]=ycord;
			x=x+60;
			count++;
		}
		ycord=ycord+49;
	}
}

void gameboard::getcord(int* xcord,int* ycord)
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			xcord[count]=x[count];
			ycord[count]=y[count];
			count++;
		}
	}
}

void gameboard::setboard(char** b,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j]=b[i][j];
		}
	}
}

void gameboard::getboard(char** b,int& n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i][j]=board[i][j];
		}
	}
}

void lion::print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board)
	{
		if(player==1)
		{
			if(pc!=0)
			{
				drawlion(xcord[pc-1]+15,ycord[pr]+5);
				board[pr][pc-1]='L';
			}
			else
			{
				drawlion(xcord[level-1]+15,ycord[pr-1]+5);
				board[pr-1][level-1]='L';
			}
		}
		else
		{
			if(pc!=level-1)
			{
				drawlion(xcord[pc+1]+15,ycord[pr]+5);
				board[pr][pc+1]='L';
			}
			else
			{
				drawlion(xcord[0]+15,ycord[pr+1]+5);
				board[pr+1][0]='L';
			}
		}
		cooldown=4;
		c=cooldown;
	}



void snake::print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board)
	{
		if(player==1)
		{
			if(pc!=0)
			{
				drawsnake(xcord[pc-1]+15,ycord[pr]+2);
				board[pr][pc-1]='S';
			}
			else
			{
				drawsnake(xcord[level-1]+15,ycord[pr-1]+2);
				board[pr-1][level-1]='S';
			}
		}
		else
		{
			if(pc!=level-1)
			{
				drawsnake(xcord[pc+1]+15,ycord[pr]+2);
				board[pr][pc+1]='S';
			}
			else
			{
				drawsnake(xcord[0]+15,ycord[pr+1]+2);
				board[pr+1][0]='S';
			}
		}
		cooldown=3;
		c=cooldown;
	}

void fire::print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board)
	{
		if(player==1)
		{
			if(pc!=0)
			{
				drawfire(xcord[pc-1]+20,ycord[pr]+8);
				board[pr][pc-1]='F';
			}
			else
			{
				drawfire(xcord[level-1]+20,ycord[pr-1]+8);
				board[pr-1][level-1]='F';
			}
		}
		else
		{
			if(pc!=level-1)
			{
				drawfire(xcord[pc+1]+20,ycord[pr]+8);
				board[pr][pc+1]='F';
			}
			else
			{
				drawfire(xcord[0]+20,ycord[pr+1]+8);
				board[pr+1][0]='F';
			}
		}
		cooldown=2;
		c=cooldown;
	}

void ghost::print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board)
	{
		if(player==1)
		{
			if(pc!=0)
			{
				drawghost(xcord[pc-1]+20,ycord[pr]+5);
				board[pr][pc-1]='G';
			}
			else
			{
				drawghost(xcord[level-1]+20,ycord[pr-1]+5);
				
				board[pr-1][level-1]='G';
	
			}
		}
		else
		{
			if(pc!=level-1)
			{
				drawghost(xcord[pc+1]+20,ycord[pr]+5);
				
				board[pr][pc+1]='G';
			}
			else
			{
				drawghost(xcord[0]+20,ycord[pr+1]+5);
				board[pr+1][0]='G';
			}
		}
		cooldown=1;
		c=cooldown;
	}

void lock::print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board) 
	{
		if(player==1)
		{
			if(pc!=0)
			{
				drawlock(xcord[pc-1]+20,ycord[pr]+20);
				board[pr][pc-1]='l';
			}
			else
			{
				drawlock(xcord[level-1]+20,ycord[pr-1]+20);
				board[pr-1][level-1]='l';
			}
		}
		else
		{
			if(pc!=level-1)
			{
				drawlock(xcord[pc+1]+20,ycord[pr]+20);
				board[pr][pc+1]='l';
			}
			else
			{
				drawlock(xcord[0]+20,ycord[pr+1]+20);
				board[pr+1][0]='l';
			}
		}
		cooldown=80;
		c=cooldown;
	}

void drawboard(int level,int half,int*xcord,int*ycord,char** board)
{
	COLORREF blue = RGB(22,131,136);
	COLORREF black = RGB(00,00,00);
	COLORREF white = RGB(255,255,255);
	COLORREF peach = RGB(243,189,47);
	COLORREF red = RGB(217,27,27);
	char num[3];
	half=(level*level)/2;

	int x=400,y=35,count=1;
	for(int i=0;i<level;i++)
	{
		for(int j=0;j<level;j++)
		{
			if(count<=half)
			{
				myRect(x,y,x+60,y+49,black,red);
			}
			else if(count==half+1)
			{
				myRect(x,y,x+60,y+49,black,peach);
			}
			else
			{
				myRect(x,y,x+60,y+49,black,blue);
			}

			x=x+60;
			count++;
		}
		x=400;
		y=y+49;
	}
	int ij=0,counter=0;
	for(int i=0;i<level*level;i++)
	{
		if(counter==level)
		{
			ij++;
			counter=0;
		}
		num1(i,num);
		for(int j=0;j<2;j++)
		{
			if(i!=half)
			{
				myDrawTextWithFont(xcord[i],ycord[ij],15,num,white,black);
			}
		}
		counter++;
	}
	for(int i=0;i<level;i++)
	{
		for(int j=0;j<level;j++)
		{
			if(board[i][j]=='g')
			{
				drawgold(xcord[j],ycord[i]);
			}
			else if(board[i][j]=='s')
			{
				drawsilver(xcord[j],ycord[i]);
			}
			else if(board[i][j]=='L')
			{
				drawlion(xcord[j]+15,ycord[i]+5);
			}
			else if(board[i][j]=='G')
			{
				drawghost(xcord[j]+20,ycord[i]+5);
			}
			else if(board[i][j]=='F')
			{
				drawfire(xcord[j]+20,ycord[i]+8);
			}
			else if(board[i][j]=='S')
			{
				drawsnake(xcord[j]+15,ycord[i]+2);
			}
			else if(board[i][j]=='l')
			{
				drawlock(xcord[j]+20,ycord[i]+20);
			}
		}
	}
}

void usecoin(int& hurdle,int& gc,int& sc)
{
	COLORREF peach = RGB(243,189,47);
	COLORREF black = RGB(0,0,0);
	if(hurdle==1)
	{
		if(gc>=5)
		{
			gc=gc-5;
		}
		else
		{
			myRect(0,0,345,480,black,black);
			myDrawTextWithFont(5,240,25,"You can only buy lion with gold coins",black,peach);
			Sleep(3000);
			myRect(0,0,345,480,black,black);
			myDrawTextWithFont(10,65,25," --Choose one of the following number-- ",black,peach);
			myDrawTextWithFont(75,100,30," Choose a hurdle again ",black,peach);
			cin>>hurdle;
			usecoin(hurdle,gc,sc);
		}
	}
	else if(hurdle==2)
	{			
		if(gc>=2)
		{
			gc=gc-2;
		}
		else if(gc==1)
		{
			gc=gc-1;
			sc=sc-2;
		}
		else if(gc==0)
		{
			sc=sc-4;
		}
	}
	else if(hurdle==3)
	{
		if(gc>=5)
		{
			gc=gc-5;
		}
		else if(gc==4)
		{
			gc=gc-4;
			sc=sc-2;
		}
		else if(gc==3)
		{
			gc=gc-3;
			sc=sc-4;
		}
		else if(gc==2)
		{
			gc=gc-2;
			sc=sc-6;
		}
		else if(gc==1)
		{
			gc=gc-1;
			sc=sc-8;
		}
		else if(gc==0)
		{
			sc=sc-10;
		}
	}
	else if(hurdle==4)
	{
		if(gc>=6)
		{
			gc=gc-6;
		}
		else if(gc==5)
		{
			gc=gc-5;
			sc=sc-2;
		}
		else if(gc==4)
		{
			gc=gc-4;
			sc=sc-4;
		}
		else if(gc==3)
		{
			gc=gc-3;
			sc=sc-6;
		}
		else if(gc==2)
		{
			gc=gc-2;
			sc=sc-8;
		}
		else if(gc==1)
		{
			gc=gc-1;
			sc=sc-10;
		}
		else if(gc==0)
		{
			sc=sc-12;
		}
	}
	else if(hurdle==5)
	{
		if(gc>=3)
		{
			gc=gc-3;
		}
		else if(gc==2)
		{
			gc=gc-2;
			sc=sc-2;
		}
		else if(gc==1)
		{
			gc=gc-1;
			sc=sc-4;
		}
		else if(gc==0)
		{
			sc=sc-6;
		}
	}
}

void usecoinagain(int& helping,int& gc,int& sc)
{
	if(helping==1)
	{
		if(gc>=7)
		{
			gc=gc-7;
		}
		else if(gc==6)
		{
			gc=gc-6;
			sc=sc-2;
		}
		else if(gc==5)
		{
			gc=gc-5;
			sc=sc-4;
		}
		else if(gc==4)
		{
			gc=gc-4;
			sc=sc-6;
		}
		else if(gc==3)
		{
			gc=gc-3;
			sc=sc-8;
		}
		else if(gc==2)
		{
			gc=gc-2;
			sc=sc-10;
		}
		else if(gc==1)
		{
			gc=gc-1;
			sc=sc-12;
		}
		else if(gc==0)
		{
			sc=sc-14;
		}
	}
	else if(helping==2)
	{
		if(gc>=3)
		{
			gc=gc-3;
		}
		else if(gc==2)
		{
			gc=gc-2;
			sc=sc-2;
		}
		else if(gc==1)
		{
			gc=gc-1;
			sc=sc-4;
		}
		else if(gc==0)
		{
			sc=sc-6;
		}
	}
	else if(helping==3)
	{
		if(gc>=5)
		{
			gc=gc-5;
		}
		else if(gc==4)
		{
			gc=gc-4;
			sc=sc-2;
		}
		else if(gc==3)
		{
			gc=gc-3;
			sc=sc-4;
		}
		else if(gc==2)
		{
			gc=gc-2;
			sc=sc-6;
		}
		else if(gc==1)
		{
			gc=gc-1;
			sc=sc-8;
		}
		else if(gc==0)
		{
			sc=sc-10;
		}
	}
	else if(helping==4)
	{
		if(gc>=4)
		{
			gc=gc-4;
		}
		else if(gc==3)
		{
			gc=gc-3;
			sc=sc-2;
		}
		else if(gc==2)
		{
			gc=gc-2;
			sc=sc-4;
		}
		else if(gc==1)
		{
			gc=gc-1;
			sc=sc-6;
		}
		else if(gc==0)
		{
			sc=sc-8;
		}
	}
}

void defending(int p1c,int p1r,int p2c,int p2r,int xcord[],int ycord[],int gc,int sc,char* num,int rx,int ry,COLORREF color)
{
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
	COLORREF silver=RGB(169,167,162);
	COLORREF orange=RGB(240,172,26);
	myLine(350,0,350,480,peach);
				drawplayer1(xcord[p1c]+25,ycord[p1r]+2);
				drawplayer2(xcord[p2c]+25,ycord[p2r]+2);
				myDrawTextWithFont(5,70,27,"--Your Wallet--",black,orange);
				myDrawTextWithFont(5,100,23,"Gold Coins: ",peach,black);
				num1(gc-1,num);
				myDrawTextWithFont(100,100,23,num,peach,black);
				myDrawTextWithFont(5,130,23,"Silver Coins: ",silver,black);
				num1(sc-1,num);
				myDrawTextWithFont(110,130,23,num,silver,black);
				myDrawText(200,100,20,"1 Gold Coin=10 Points",peach,black);
				myDrawText(200,130,20,"1 Silver Coin=5 Points",silver,black);

				myDrawText(5,180,25," --Choose a number to buy helping object-- ",peach,black);
				myDrawTextWithFont(42+rx,77+ry,33," Helping Objects ",black,color);
				myDrawTextWithFont(10,130+ry,40," S ",black,color);
				myDrawTextWithFont(10,170+ry,40," H ",black,color);
				myDrawTextWithFont(10,210+ry,40," O ",black,color);
				myDrawTextWithFont(10,250+ry,40," P ",black,color);

				myRect(7+rx,117+ry,253+rx,304+ry,color,black);
				myRect(7+rx,143+ry,253+rx,210+ry,color,black);
				myRect(7+rx,210+ry,253+rx,237+ry,color,black);
				myLine(89+rx,117+ry,89+rx,303+ry,color);
				myLine(171+rx,117+ry,171+rx,303+ry,color);
				
				
				myDrawTextWithFont(33+rx,120+ry,20,"1: Key",peach,black);
				drawkey(25+rx,158+ry);
				myDrawText(17+rx,188+ry,15,"Points=70",white,black);
				myDrawTextWithFont(108+rx,120+ry,20,"2: Shield",peach,black);
				drawshield(112+rx,148+ry);
				myDrawText(98+rx,188+ry,15,"Points=30",white,black);
				myDrawTextWithFont(188+rx,120+ry,20,"3: Water",peach,black);
				drawwater(197+rx,160+ry);
				myDrawText(180+rx,188+ry,15,"Points=50",white,black);
				myDrawTextWithFont(25+rx,212+ry,20,"4: Sword",peach,black);
				drawsword(45+rx,245+ry);
				myDrawText(15+rx,285+ry,15,"Points=40",white,black);

}

void attacking(int p1c,int p1r,int p2c,int p2r,int xcord[],int ycord[],int gc,int sc,char*num,int rx,int ry,COLORREF color)
{
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
	COLORREF silver=RGB(169,167,162);
	COLORREF orange=RGB(240,172,26);
	myLine(350,0,350,480,peach);
				drawplayer1(xcord[p1c]+25,ycord[p1r]+2);
				drawplayer2(xcord[p2c]+25,ycord[p2r]+2);
			
				myDrawTextWithFont(5,70,27,"--Your Wallet--",black,orange);
				myDrawTextWithFont(5,100,23,"Gold Coins: ",peach,black);
				num1(gc-1,num);
				myDrawTextWithFont(100,100,23,num,peach,black);
				myDrawTextWithFont(5,130,23,"Silver Coins: ",silver,black);
				num1(sc-1,num);
				myDrawTextWithFont(110,130,23,num,silver,black);
				myDrawText(200,100,20,"1 Gold Coin=10 Points",peach,black);
				myDrawText(200,130,20,"1 Silver Coin=5 Points",silver,black);

				myDrawText(5,180,25," --Choose a number to buy hurdle-- ",peach,black);
				myDrawTextWithFont(80+rx,77+ry,33," Hurdles ",black,color);
				myDrawTextWithFont(10,130+ry,40," S ",black,color);
				myDrawTextWithFont(10,170+ry,40," H ",black,color);
				myDrawTextWithFont(10,210+ry,40," O ",black,color);
				myDrawTextWithFont(10,250+ry,40," P ",black,color);
					
				myRect(7+rx,117+ry,253+rx,304+ry,color,black);
				myRect(7+rx,143+ry,253+rx,210+ry,color,black);
				myRect(7+rx,210+ry,253+rx,237+ry,color,black);
				myLine(89+rx,117+ry,89+rx,303+ry,color);
				myLine(171+rx,117+ry,171+rx,303+ry,color);
				

				myDrawTextWithFont(30+rx,118+ry,20,"1: Lion",peach,black);
				drawlion(30+rx,148+ry);
				myDrawText(17+rx,188+ry,15,"Points=50",white,black);
				myDrawTextWithFont(103+rx,118+ry,20,"2: Ghost",peach,black);
				drawghost(120+rx,148+ry);
				myDrawText(98+rx,188+ry,15,"Points=20",white,black);
				myDrawTextWithFont(190+rx,118+ry,20,"3: Fire",peach,black);
				drawfire(200+rx,148+ry);
				myDrawText(180+rx,188+ry,15,"Points=50",white,black);
				myDrawTextWithFont(23+rx,212+ry,20,"4: Lock",peach,black);
				drawlock(35+rx,262+ry);
				myDrawText(15+rx,285+ry,15,"Points=60",white,black);
				myDrawTextWithFont(100+rx,212+ry,20,"5: Snake",peach,black);
				drawsnake(115+rx,240+ry);
				myDrawText(98+rx,285+ry,15,"Points=30",white,black);
}

void putcoins(char** board,int n)
{
	int num;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((i!=n/2 && j!=n/2))
			{
				num=rand()%13;
				if(num==1)
				{
					board[i][j]='g';
				}
				else if(num==2)
				{
					board[i][j]='s';
				}
			}
		}
	}
	board[0][0]='\0';
	board[n-1][n-1]='\0';
}

bool checkpoints(int helping,int p)
{
	bool canbuy=false;
	if(helping==1 && p>=70)
		canbuy=true;
	else if(helping==2 && p>=30)
		canbuy=true;
	else if(helping==3 && p>=50)
		canbuy=true;
	else if(helping==4 && p>=40)
		canbuy=true;
	return canbuy;
	

}

bool checkpointsatt(int hurdle,int p)
{
	bool canbuyatt=false;
	if(hurdle==1 && p>=50)
		canbuyatt=true;
	else if(hurdle==2 && p>=20)
		canbuyatt=true;
	else if(hurdle==3 && p>=50)
		canbuyatt=true;
	else if(hurdle==4 && p>=60)
		canbuyatt=true;
	else if(hurdle==5 && p>=30)
		canbuyatt=true;
	return canbuyatt;
}

void savegame(int loop,int level,int counter1,int counter2,int cooldown1,int cooldown2,int turn,int p1r,int p2r,int p1c,int p2c,int p1,int p2,int hurdle1,int hurdle2,int helping,int gc1,int gc2,int sc1,int sc2,int snaker2,int snakec2,int snaker,int snakec,bool blocked1,bool blocked2,bool hurdleused1,bool hurdleused2,int box1[6],int box2[6],char** board)
{
	ofstream intvarfile;
	intvarfile.open("intvar.txt");
	intvarfile<<loop<<endl;
	intvarfile<<level<<endl;
	intvarfile<<counter1<<endl;
	intvarfile<<counter2<<endl;
	intvarfile<<cooldown1<<endl;
	intvarfile<<cooldown2<<endl;
	intvarfile<<turn<<endl;
	intvarfile<<p1r<<endl;
	intvarfile<<p2r<<endl;
	intvarfile<<p1c<<endl;
	intvarfile<<p2c<<endl;
	intvarfile<<p1<<endl;
	intvarfile<<p2<<endl;
	intvarfile<<hurdle1<<endl;
	intvarfile<<hurdle2<<endl;
	intvarfile<<helping<<endl;
	intvarfile<<gc1<<endl;
	intvarfile<<gc2<<endl;
	intvarfile<<sc1<<endl;
	intvarfile<<sc2<<endl;
	intvarfile<<snaker2<<endl;
	intvarfile<<snakec2<<endl;
	intvarfile<<snaker<<endl;
	intvarfile<<snakec<<endl;
	intvarfile<<blocked1<<endl;
	intvarfile<<blocked2<<endl;
	intvarfile<<hurdleused1<<endl;
	intvarfile<<hurdleused2<<endl;
	intvarfile<<box1[4]<<endl;
	intvarfile<<box1[5]<<endl;
	intvarfile<<box2[4]<<endl;
	intvarfile<<box2[5]<<endl;
	intvarfile.close();

	ofstream chararrfile;
	chararrfile.open("mainboard.txt");
	for(int i=0;i<level;i++)
	{
		for(int j=0;j<level;j++)
		{
			chararrfile<<board[i][j]<<endl;
		}
	}
	chararrfile.close();

}

void conversion(int&loop,int&level,int&counter1,int&counter2,int&cooldown1,int&cooldown2,int&turn,int&p1r,int&p2r,int&p1c,int& p2c,int& p1,int& p2,int& hurdle1,int& hurdle2,int& helping,int& gc1,int& gc2,int& sc1,int& sc2,int& snaker2,int& snakec2,int& snaker,int& snakec,bool& blocked1,bool& blocked2,bool& hurdleused1,bool& hurdleused2,int box1[6],int box2[6],string str[32],int convert[32])
{
	for(int i=0;i<32;i++)
	{
		stringstream geek(str[i]);
		geek>>convert[i];
	}	
	loop=convert[0];
	level=convert[1];
	counter1=convert[2];
	counter2=convert[3];
	cooldown1=convert[4];
	cooldown2=convert[5];
	turn=convert[6];
	p1r=convert[7];
	p2r=convert[8];
	p1c=convert[9];
	p2c=convert[10];
	p1=convert[11];
	p2=convert[12];
	hurdle1=convert[13];
	hurdle2=convert[14];
	helping=convert[15];
	gc1=convert[16];
	gc2=convert[17];
	sc1=convert[18];
	sc2=convert[19];
	snaker2=convert[20];
	snakec2=convert[21];
	snaker=convert[22];
	snakec=convert[23];
	blocked1=convert[24];
	blocked2=convert[25];
	hurdleused1=convert[26];
	hurdleused2=convert[27];
	box1[4]=convert[28];
	box1[5]=convert[29];
	box2[4]=convert[30];
	box2[5]=convert[31];
}

void loadgame(string str[32],char** board,int level)
{
	ifstream readintvar;
	string chr;
	readintvar.open("intvar.txt");
	for(int i=0;i<32;i++)
	{
			readintvar>>chr;
			str[i]=chr;
	}
	readintvar.close();

	ifstream readboard;
	readboard.open("mainboard.txt");
	for(int i=0;i<level;i++)
	{
		for(int j=0;j<level;j++)
		{
			readboard>>board[i][j];
		}
	}
	readboard.close();
}