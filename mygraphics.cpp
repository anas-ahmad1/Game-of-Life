#define _WIN32_WINNT 0x0500 

#include <windows.h> 
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void myLine(int x1, int y1, int x2, int y2,COLORREF lineColor)
{

	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
	HPEN pen =CreatePen(PS_SOLID,2,lineColor); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	DeleteObject(pen);

	ReleaseDC(console_handle, device_context);  
}
void myRect(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,lineColor); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context); 
}
void myEllipse(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,lineColor); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	DeleteObject(pen);
	DeleteObject(brush);	
	ReleaseDC(console_handle, device_context);

}
void myDrawText(int x,int y,int ht,char str[],COLORREF lineColor,COLORREF fillColor)
{
	WCHAR wstr[20]={};
	for (int i=0;i<20&&str[i];++i)
		wstr[i] = str[i];

	RECT rects;
	rects.left = x;
	rects.top = y;
	rects.right = x+ht;
	rects.bottom = y+ht;//(x,y,x+ht,y+ht);
	
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

	SetTextColor(device_context,lineColor);
	SetBkColor(device_context,fillColor);
	DrawText(device_context,str,-1,&rects,DT_TOP|DT_NOCLIP);
	ReleaseDC(console_handle, device_context);
  
}

void myDrawTextWithFont(int x,int y,int ht,char str[],COLORREF lineColor,COLORREF fillColor)
{
	WCHAR wstr[20]={};
	for (int i=0;i<20&&str[i];++i)
		wstr[i] = str[i];

	RECT rects;
	HFONT hFont;
	rects.left = x;
	rects.top = y;
	rects.right = x+ht;
	rects.bottom = y+ht;//(x,y,x+ht,y+ht);
	
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
	hFont = CreateFont(ht,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			            CLIP_DEFAULT_PRECIS,1, VARIABLE_PITCH,TEXT("Impact"));
    SelectObject(device_context, hFont);

	SetTextColor(device_context,lineColor);
	SetBkColor(device_context,fillColor);
	DrawText(device_context,str,-1,&rects,DT_TOP|DT_NOCLIP);
	DeleteObject(hFont);   
	ReleaseDC(console_handle, device_context);
  
}
void mySetPixel(float x,float y,COLORREF colorVal)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
	
	SetPixel(device_context,x,y,colorVal);
	ReleaseDC(console_handle,device_context);
}


void num1(int box,char num[3])
{
	switch(box)
	{
	case -1:
		{		
			num[0]='0';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 0:
		{		
			num[0]='0';
			num[1]='1';
			num[2]='\0';
			break;
		}
	case 1:
		{		
			num[0]='0';
			num[1]='2';
			num[2]='\0';
			break;
		}
	case 2:
		{		
			num[0]='0';
			num[1]='3';
			num[2]='\0';
			break;
		}
	case 3:
		{		
			num[0]='0';
			num[1]='4';
			num[2]='\0';
			break;
		}
	case 4:
		{		
			num[0]='0';
			num[1]='5';
			num[2]='\0';
			break;
		}
	case 5:
		{		
			num[0]='0';
			num[1]='6';
			num[2]='\0';
			break;
		}
	case 6:
		{		
			num[0]='0';
			num[1]='7';
			num[2]='\0';
			break;
		}
	case 7:
		{		
			num[0]='0';
			num[1]='8';
			num[2]='\0';
			break;
		}
	case 8:
		{		
			num[0]='0';
			num[1]='9';
			num[2]='\0';
			break;
		}
	case 9:
		{	
			num[0]='1';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 10:
		{		
			num[0]='1';
			num[1]='1';
			num[2]='\0';
			break;
		}
	case 11:
		{		
			num[0]='1';
			num[1]='2';
			num[2]='\0';
			break;
		}
	case 12:
		{		
			num[0]='1';
			num[1]='3';
			num[2]='\0';
			break;
		}
	case 13:
		{		
			num[0]='1';
			num[1]='4';
			num[2]='\0';
			break;
		}
	case 14:
		{		
			num[0]='1';
			num[1]='5';
			num[2]='\0';
			break;
		}
	case 15:
		{		
			num[0]='1';
			num[1]='6';
			num[2]='\0';
			break;
		}
	case 16:
		{		
			num[0]='1';
			num[1]='7';
			num[2]='\0';
			break;
		}
	case 17:
		{		
			num[0]='1';
			num[1]='8';
			num[2]='\0';
			break;
		}
	case 18:
		{		
			num[0]='1';
			num[1]='9';
			num[2]='\0';
			break;
		}
	case 19:
		{	
			num[0]='2';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 20:
		{		
			num[0]='2';
			num[1]='1';
			num[2]='\0';
			break;
		}
	case 21:
		{		
			num[0]='2';
			num[1]='2';
			num[2]='\0';
			break;
		}
	case 22:
		{		
			num[0]='2';
			num[1]='3';
			num[2]='\0';
			break;
		}
	case 23:
		{		
			num[0]='2';
			num[1]='4';
			num[2]='\0';
			break;
		}
	case 24:
		{		
			num[0]='2';
			num[1]='5';
			num[2]='\0';
			break;
		}
	case 25:
		{		
			num[0]='2';
			num[1]='6';
			num[2]='\0';
			break;
		}
	case 26:
		{		
			num[0]='2';
			num[1]='7';
			num[2]='\0';
			break;
		}
	case 27:
		{		
			num[0]='2';
			num[1]='8';
			num[2]='\0';
			break;
		}
	case 28:
		{		
			num[0]='2';
			num[1]='9';
			num[2]='\0';
			break;
		}
	case 29:
		{	
			num[0]='3';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 30:
		{		
			num[0]='3';
			num[1]='1';
			num[2]='\0';
			break;
		}
	case 31:
		{		
			num[0]='3';
			num[1]='2';
			num[2]='\0';
			break;
		}
	case 32:
		{		
			num[0]='3';
			num[1]='3';
			num[2]='\0';
			break;
		}
	case 33:
		{		
			num[0]='3';
			num[1]='4';
			num[2]='\0';
			break;
		}
	case 34:
		{		
			num[0]='3';
			num[1]='5';
			num[2]='\0';
			break;
		}
	case 35:
		{		
			num[0]='3';
			num[1]='6';
			num[2]='\0';
			break;
		}
	case 36:
		{		
			num[0]='3';
			num[1]='7';
			num[2]='\0';
			break;
		}
	case 37:
		{		
			num[0]='3';
			num[1]='8';
			num[2]='\0';
			break;
		}
	case 38:
		{		
			num[0]='3';
			num[1]='9';
			num[2]='\0';
			break;
		}
	case 39:
		{	
			num[0]='4';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 40:
		{		
			num[0]='4';
			num[1]='1';
			num[2]='\0';
			break;
		}
	case 41:
		{		
			num[0]='4';
			num[1]='2';
			num[2]='\0';
			break;
		}
	case 42:
		{		
			num[0]='4';
			num[1]='3';
			num[2]='\0';
			break;
		}
	case 43:
		{		
			num[0]='4';
			num[1]='4';
			num[2]='\0';
			break;
		}
	case 44:
		{		
			num[0]='4';
			num[1]='5';
			num[2]='\0';
			break;
		}
	case 45:
		{		
			num[0]='4';
			num[1]='6';
			num[2]='\0';
			break;
		}
	case 46:
		{		
			num[0]='4';
			num[1]='7';
			num[2]='\0';
			break;
		}
	case 47:
		{		
			num[0]='4';
			num[1]='8';
			num[2]='\0';
			break;
		}
	case 48:
		{		
			num[0]='4';
			num[1]='9';
			num[2]='\0';
			break;
		}
	case 49:
		{	
			num[0]='5';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 50:
		{		
			num[0]='5';
			num[1]='1';
			num[2]='\0';
			break;
		}
	case 51:
		{		
			num[0]='5';
			num[1]='2';
			num[2]='\0';
			break;
		}
	case 52:
		{		
			num[0]='5';
			num[1]='3';
			num[2]='\0';
			break;
		}
	case 53:
		{		
			num[0]='5';
			num[1]='4';
			num[2]='\0';
			break;
		}
	case 54:
		{		
			num[0]='5';
			num[1]='5';
			num[2]='\0';
			break;
		}
	case 55:
		{		
			num[0]='5';
			num[1]='6';
			num[2]='\0';
			break;
		}
	case 56:
		{		
			num[0]='5';
			num[1]='7';
			num[2]='\0';
			break;
		}
	case 57:
		{		
			num[0]='5';
			num[1]='8';
			num[2]='\0';
			break;
		}
	case 58:
		{		
			num[0]='5';
			num[1]='9';
			num[2]='\0';
			break;
		}
	case 59:
		{	
			num[0]='6';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 60:
		{		
			num[0]='6';
			num[1]='1';
			num[2]='\0';
			break;
		}
	case 61:
		{		
			num[0]='6';
			num[1]='2';
			num[2]='\0';
			break;
		}
	case 62:
		{		
			num[0]='6';
			num[1]='3';
			num[2]='\0';
			break;
		}
	case 63:
		{		
			num[0]='6';
			num[1]='4';
			num[2]='\0';
			break;
		}
	case 64:
		{		
			num[0]='6';
			num[1]='5';
			num[2]='\0';
			break;
		}
	case 65:
		{		
			num[0]='6';
			num[1]='6';
			num[2]='\0';
			break;
		}
	case 66:
		{		
			num[0]='6';
			num[1]='7';
			num[2]='\0';
			break;
		}
	case 67:
		{		
			num[0]='6';
			num[1]='8';
			num[2]='\0';
			break;
		}
	case 68:
		{		
			num[0]='6';
			num[1]='9';
			num[2]='\0';
			break;
		}
	case 69:
		{	
			num[0]='7';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 70:
		{		
			num[0]='7';
			num[1]='1';
			num[2]='\0';
			break;
		}
	case 71:
		{		
			num[0]='7';
			num[1]='2';
			num[2]='\0';
			break;
		}
	case 72:
		{		
			num[0]='7';
			num[1]='3';
			num[2]='\0';
			break;
		}
	case 73:
		{		
			num[0]='7';
			num[1]='4';
			num[2]='\0';
			break;
		}
	case 74:
		{		
			num[0]='7';
			num[1]='5';
			num[2]='\0';
			break;
		}
	case 75:
		{		
			num[0]='7';
			num[1]='6';
			num[2]='\0';
			break;
		}
	case 76:
		{		
			num[0]='7';
			num[1]='7';
			num[2]='\0';
			break;
		}
	case 77:
		{		
			num[0]='7';
			num[1]='8';
			num[2]='\0';
			break;
		}
	case 78:
		{		
			num[0]='7';
			num[1]='9';
			num[2]='\0';
			break;
		}
	case 79:
		{	
			num[0]='8';
			num[1]='0';
			num[2]='\0';
			break;
		}
	case 80:
		{		
			num[0]='8';
			num[1]='1';
			num[2]='\0';
			break;
		}
	}
}

void drawlion(int x,int y)
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

	//myLine(250,80,950,80,grey);		//Upper horizontal line
	//myLine(250,80,250,475,grey);		//Left verical line
	//myLine(950,80,950,475,grey);	//Right vertical line
	//myLine(250,475,950,475,grey);	//Lower horizontal line

	/*int x=50;
	int y=400;*/


	myEllipse(x,y,x+40,y+40,yellow,yellow);
	myEllipse(x+7,y+7,x+14,y+12,lyel,lyel);
	myEllipse(x+27,y+7,x+32,y+12,lyel,lyel);

	myEllipse(x+5,y+7,x+35,y+32,peach,peach);
	myEllipse(x+11,y+14,x+16,y+18,white,white);
	myEllipse(x+24,y+14,x+28,y+18,white,white);
	myEllipse(x+12,y+14,x+15,y+18,black,black);
	myEllipse(x+25,y+14,x+27,y+18,black,black);


	myEllipse(x+15,y+22,x+25,y+32,lyel,lyel);
	int size=3;
			for(int i=-size;i<size;i++)
			{
				myLine(x+20,y+22,x+20+i,y+17,yellow);
			}

	myLine(x+20,y+22,x+20,y+25,black);
	//myEllipse(151,320,159,325,black,black);
	//myLine(155,315,147,318,black);
	//myLine(155,315,163,318,black);

	myLine(x+24,y+26,x+31,y+25,black);
	myLine(x+24,y+25,x+31,y+22,black);

	myLine(x+9,y+25,x+16,y+26,black);
	myLine(x+9,y+22,x+16,y+25,black);

	myLine(x+17,y+28,x+22,y+28,black);
}

void drawsnake(int x,int y)
{
    COLORREF Green = RGB(42, 139, 28);
    COLORREF Red = RGB(249, 84, 71);
    COLORREF Black = RGB(0, 0, 0);
    COLORREF White = RGB(244, 243, 239);

    myEllipse(x,y,x+30,y+40, Green, Green);
    myEllipse(x+5, y+7, x+12, y+15, Red, Red);
    myEllipse(x+17, y+7, x+25, y+15, Red, Red);

    myEllipse(x+6, y+10, x+11,y+13, Black, Black);
    myEllipse(x+18, y+10, x+24,y+13, Black, Black);

    myRect(x+12,y+30, x+17,y+40, Red, Red);
    myRect(x+12,y+40, x+14,y+45, Red, Red);
    myRect(x+16,y+40, x+17,y+45, Red, Red);
    myEllipse(x+5,y+28, x+25,y+32, Black, Black);

	int size=1;
	for(int i=-size;i<size;i++)
	{
		myLine(x+6,y+34,x+6+i,y+29,White);
	}

	for(int i=-size;i<size;i++)
	{
		myLine(x+22,y+34,x+22+i,y+29,White);
	}

  /*  myRect(x+5,y+29, x+7,y+32, White, White);
    myEllipse(x+5,y+30, x+7,y+35, White, White);
    myRect(x+22,y+29, x+25, y+32, White, White);
    myEllipse(x+22,y+30, x+25,y+35, White, White);*/
}

void drawlock(int x,int y)
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


	myEllipse(x+3,y,x+23,y-13,white,white);
	myRect(x+3,y,x+23,y-7,black,black);
	myEllipse(x+7,y,x+20,y-10,black,black);

	myRect(x,y,x+27,y+20,white,white);
	myRect(x+3,y,x+7,y-7,white,white);
	myRect(x+20,y,x+23,y-7,white,white);

	myEllipse(x+10,y+5,x+17,y+11,black,black);
	myEllipse(x+11,y+10,x+15,y+17,black,black);
}

void drawsword(int x,int y)
{
	// Sword
    COLORREF Silver = RGB(196, 202, 206);
    COLORREF Gold = RGB(212, 175, 55);
    COLORREF Grey = RGB(64, 64, 64);
    myRect(x,y,x+4,y+25, Silver, Silver);
    int x1 = x+2;
    int y1 = y-3;
    int size = 3;
    for (int i = -size; i < size; i++) {
        myLine(x1, y1, x1 + (i / 2), y1 + 4, Silver);
    }
    myRect(x,y+30,x+4,y+39, Gold, Gold);
    myRect(x-7,y+25, x+11,y+30, Gold, Gold);
    myLine(x-1, y+24, x+4, y+24, Grey);
}

void drawfire(int x,int y)
{
    COLORREF Orange = RGB(252, 99, 0);
    COLORREF LightOrange = RGB(255, 165, 0);
    COLORREF Yellow = RGB(246, 190, 0);
    COLORREF Black = RGB(0, 0, 0);

    myEllipse(x,y+17,x+27, y+37, Orange, Orange);
    myEllipse(x-3,y,x+4,y+31, Orange, Orange);
    myEllipse(x+20,y,x+29,y+29, Orange, Orange);

    myRect(x,y+17,x+27,y+23, Orange, Orange);
    int x1 = x;
    int y1 = y;
    int size = 13;
    for (int i = -size; i < 1; i++) 
	{
        myLine(x1, y1, x1 - i, y1 + 17, Orange);
    }
    x1 =x+26;
    y1 = y;
    size = 13;
    for (int i = -size; i < 1; i++) 
	{
        myLine(x1, y1, x1 + i, y1 + 17, Orange);
    }
    x1 = x+13;
    y1 = y;
    size = 13;
    for (int i = -size; i < size; i++) {
        myLine(x1, y1, x1 + i, y1 + 17, Orange);
    }
    myEllipse(x,y+8,x+26,y+36, LightOrange, LightOrange);
    myEllipse(x+3,y+15,x+23,y+34, Yellow, Yellow);
}

void drawghost(int x,int y)
{
	// Ghost
    COLORREF Pink = RGB(255, 192, 203);
    COLORREF Black = RGB(0, 0, 0);

    myEllipse(x,y,x+27,y+27, Pink, Pink);
    myRect(x, y+13,x+27, y+30, Pink, Pink);
    myEllipse(x+7,y+10,x+10,y+13, Black, Black);
    myLine(x+7,y+7,x+10,y+8, Black);
    myEllipse(x+17,y+10,x+20,y+13, Black, Black);
    myLine(x+17, y+8,x+20, y+7, Black);
    int x1 = x;
    int y1 = y+37;
    int size = 3;
    for (int i = -size; i < 1; i++) {
        myLine(x1, y1, x1 - i, y1 - 7, Pink);
    }
    x1 = x+26;
    y1 = y+37;
    size = 3;
    for (int i = -size; i < 1; i++) {
        myLine(x1, y1, x1 + i, y1 - 7, Pink);
    }
    x1 = x+17;
    y1 = y+37;
    size = 3;
    for (int i = -size; i < size; i++) {
        myLine(x1, y1, x1 - i, y1 - 7, Pink);
    }
    x1 = x+9;
    y1 = y+37;
    size = 3;
    for (int i = -size; i < size; i++) {
        myLine(x1, y1, x1 - i, y1 -7, Pink);
    }
}

void drawshield(int x,int y)
{
	COLORREF red = RGB(222,1,1);
    COLORREF blue = RGB(13,32,172);
	COLORREF white = RGB(255,255,255);

	myEllipse(x,y,x+40,y+40,red,red);
	myEllipse(x+2,y+2,x+38,y+38,white,white);
	myEllipse(x+5,y+5,x+35,y+35,red,red);
	myEllipse(x+7,y+7,x+32,y+32,blue,blue);

	x=x+10;
	y=y+7;
     myLine(x+12,y,x,y+20,white);
	 myLine(x+12,y,x+12,y+20,white);
	 myLine(x+12,y+20,x,y+7,white);
	 myLine(x,y+7,x+20,y+7,white);
	 myLine(x+20,y+7,x,y+20,white);


}

void drawwater(int x,int y)
{
	COLORREF blue = RGB(13,32,172);
	int size=6;

	myEllipse(x,y,x+13,y+17,blue,blue);
	for(int i=-size;i<size;i++)
	{
		myLine(x+6+i,y+5,x+6,y-7,blue);
	}

	myEllipse(x+15,y,x+13+15,y+17,blue,blue);
	for(int i=-size;i<size;i++)
	{
		myLine(x+6+15+i,y+5,x+6+15,y-7,blue);
	}
}

void drawkey(int x,int y)
{
	// Key
    COLORREF Gold = RGB(204, 153, 0);
    COLORREF Black = RGB(0, 0, 0);
    myEllipse(x, y, x+20, y+20, Gold, Gold);
    myEllipse(x+4, y+8, x+10, y+13, Black, Black);
    myRect(x+16, y+8, x+50, y+12, Gold, Gold);
    myRect(x+43, y+12, x+45, y+18, Gold, Gold);
    myRect(x+38, y+12, x+40, y+18, Gold, Gold);
}

void drawplayer1(int x,int y)
{
	 COLORREF Black = RGB(0, 0, 0);
	 COLORREF White = RGB(255,255,255);
	 myEllipse(x, y, x+20, y+20,Black,Black);
	 myLine(x+10,y+20,x+10,y+35,Black);
	 myLine(x+10,y+28,x+20,y+23,Black);
	 myLine(x+10,y+28,x,y+23,Black);
	 myLine(x+10,y+35,x+15,y+42,Black);
	 myLine(x+10,y+35,x+5,y+42,Black);
	 myEllipse(x+4, y+5, x+8, y+8,White,White);
	 myEllipse(x+12, y+5, x+16, y+8,White,White);
	 myEllipse(x+6, y+10, x+14, y+18,White,White);
	 myRect(x+5, y+10, x+15, y+15,Black,Black);

}
void drawplayer2(int x,int y)
{
	 COLORREF Black = RGB(0, 0, 0);
	 COLORREF White = RGB(255,255,255);
	 myEllipse(x, y, x+20, y+20, White,White);
	 myLine(x+10,y+20,x+10,y+35,White);
	 myLine(x+10,y+28,x+20,y+23,White);
	 myLine(x+10,y+28,x,y+23,White);
	 myLine(x+10,y+35,x+15,y+42,White);
	 myLine(x+10,y+35,x+5,y+42,White);
	 myEllipse(x+4, y+5, x+8, y+8, Black,Black);
	 myEllipse(x+12, y+5, x+16, y+8, Black,Black);
	 myEllipse(x+6, y+10, x+14, y+18, Black,Black);
	 myRect(x+5, y+10, x+15, y+15, White, White);

}

void drawgold(int x,int y)
{
	COLORREF gold=RGB(255,202,59);
	 myEllipse(x+20, y+10, x+50, y+40,gold,gold);
}
void drawsilver(int x,int y)
{
	COLORREF silver=RGB(169,167,162);
	 myEllipse(x+20, y+10, x+50, y+40,silver,silver);
}

