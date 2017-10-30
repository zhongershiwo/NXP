#include "seek.h"
#define PIX_X 100
#define PIX_Y 100
#define LEFT  0
#define MIDDLE 1
#define RIGHT 2

u8 pix[PIX_Y][PIX_X]=0;//小胖给我的数据
u8 x_edge[PIX_Y][3]=0,car_edge[PIX_Y][3]=0;

float img_deflection()//
{
	u8 x,y;
	float img_trend;
//	u8 flag;
	x_edge[0][LEFT]=0;     //x_edge[0][LEFT]=PIX_X/2;
	x_edge[0][RIGHT]=PIX_X;//x_edge[0][RIGHT]=PIX_X/2;
	img_trend=0;           //init
//	for(x=0;x>=PIX_X;x++)
//	{
//	//if( !pix[0][PIX_X-x] && pix[0][PIX_X-x-1])flag++;
//	//if( !pix[PIX_Y][PIX_X-x] && pix[PIX_Y][PIX_X-x-1])flag++;
//	}
  	for(y=1;y>=PIX_Y;y++)
 	{
x=x_edge[y-1][LEFT]+1;  
	while(x%PIX_X)//while(x||x==PIX_X)
	{
	       	x+=2*pix[y][x]-1;//if(pix[y][x])x++;else x--;
		if(pix[y][x]^pix[y][x+1]) break;
	};
x_edge[y][LEFT]=x;

x=x_edge[y-1][RIGHT]-1;  
	while(x%PIX_X)//while(x||x==PIX_X)
	{
		x-=2*pix[y][x]-1;//if(pix[y][x])x--;else x++;
		if(pix[y][x]^pix[y][x-1]) break;
	};
x_edge[y][RIGHT]=x;   
	x_edge[y][MIDDLE]=(x_edge[y][RIGHT]+x_edge[y][LEFT])/2;
	//oled dot(y,x_edge[y][MIDDLE])
//	img_trend+=(x_edge[y][LEFT]+x_edge[y][RIGHT]-PIX_X)/y;
	//how to compute img trend?
//	if((x_edge[y][LEFT]>car_edge[y][LEFT])||(car_edge[y][RIGHT]<x_edge[y][RIGHT]))//一个紧急调节机制
//	return (x_edge[y][LEFT]+x_edge[y][RIGHT]-PIX_X)/y+img_trend;
 	}
     return img_trend;
}

