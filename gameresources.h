#include <iostream>
using namespace std;

class bag
{
	int box[6];
	int points;
public:
	bag();
	bag(int level);
	void setbox(int b[6]);
	void getbox(int b[6]);
};

class player:public bag
{
	int level;
	string name;
	bag mybag;
public:
	player();
	player(string n,int level,int b[6]);
	void setPlayer(string n,int box[6]);
	void getPlayer(string n,int b[6]);
};

class gameboard
{
	char** board;
	int size;
	int* x;
	int* y;
public:
	gameboard(int n);
	void setboard(char** b,int n);
	void setcord(int size);
	void getcord(int* xcord,int* ycord);
	void getboard(char** b,int& n);
};

class hurdles 
{
public:
	virtual void print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board) = 0;
};

class lion:public hurdles
{
	static int price;
	int cooldown;
public:
	void print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board) override;
};

class snake:public hurdles
{
	static int price;
	int cooldown;
public:
	void print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board) override;
};

class fire:public hurdles
{
	static int price;
	int cooldown;
public:
	void print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board) override;
};

class ghost:public hurdles
{
	int cooldown;
	static int price;
public:
	void print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board) override;
};

class lock:public hurdles
{
	int cooldown;
	static int price;
public:
	void print(int xcord[],int ycord[],int pc,int pr,int level,int player,int& c,char** board) override;
};

void drawboard(int level,int half,int*xcord,int*ycord,char** board);

void usecoin(int& hurdle,int& gc,int& sc);

void usecoinagain(int& helping,int& gc,int& sc);

void defending(int p1c,int p1r,int p2c,int p2r,int xcord[],int ycord[],int gc,int sc,char* num,int rx,int ry,COLORREF color);

void attacking(int p1c,int p1r,int p2c,int p2r,int xcord[],int ycord[],int gc,int sc,char*num,int rx,int ry,COLORREF color);

void putcoins(char** board,int n);

bool checkpoints(int helping,int p);

bool checkpointsatt(int hurdle,int p);

void savegame(int loop,int level,int counter1,int counter2,int cooldown1,int cooldown2,int turn,int p1r,int p2r,int p1c,int p2c,int p1,int p2,int hurdle1,int hurdle2,int helping,int gc1,int gc2,int sc1,int sc2,int snaker2,int snakec2,int snaker,int snakec,bool blocked1,bool blocked2,bool hurdleused1,bool hurdleused2,int box1[6],int box2[6],char** board);

void conversion(int&loop,int&level,int&counter1,int&counter2,int&cooldown1,int&cooldown2,int&turn,int&p1r,int&p2r,int&p1c,int& p2c,int& p1,int& p2,int& hurdle1,int& hurdle2,int& helping,int& gc1,int& gc2,int& sc1,int& sc2,int& snaker2,int& snakec2,int& snaker,int& snakec,bool& blocked1,bool& blocked2,bool& hurdleused1,bool& hurdleused2,int box1[6],int box2[6],string str[32],int convert[32]);

void loadgame(string str[32],char** board,int level);