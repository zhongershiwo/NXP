/*
 * Camera.c
 *
 *  Created on: 2017��9��25��
 *      Author: ����
 */
#include "Camera.h"

#define R 38//��
#define C 90//��
uint8_t Data1[R][C];
uint8_t N =0;
uint8_t YUZHI = 5;
uint8_t InterruptLine=0;
uint8_t TrueLine;
uint8_t DataReadyFlag=0;
extern uint8_t huidu(void);
const uint8_t SlampeLine[R]=
  {
		  56,//
		       57,//
		       58,//
		       59,//
		       60,//
		       61,//121.5
		       62,//118
		       64,//114.5
		       66,//111
		       68,//107.5
		       70,//104
		       72,//100.5
		       74,//97
		       76,//93.5
		       79,//90
		       82,//86.5
		       85,//83
		       88,//79.5
		       91,//76
		       94,//72.5
		       97, //69
		       101,//65.5
		       105,//62
		       110,//58.5
		       115,//55
		       120,//51.5
		       126,//48
		       134,//44.5
		       142,//41
		       150,//37.5
		       158,//34
		       166,//30.5
		       174,//27
		       182,//23.5cm
		       190,//20cm
		       204,//16.5cm
		       220,//13cm
		       238 //9.5cm
  };
LDD_TDeviceDataPtr myHREF;
LDD_TDeviceDataPtr myVSYN;
//LDD_TDeviceDataPtr myCamD;

void Camera_Init(void)
{
	myHREF	= HREF_Init(NULL);
	myVSYN	= VSYN_Init(NULL);
	//myCamD	= AD1_Init(NULL);

}
/*���ж�*/
void HREF_IRQ(void)
{
	uint8_t j=0;
	uint8_t	ipx=0;
		   InterruptLine++;

		  if(InterruptLine==SlampeLine[TrueLine]) //�����Ƿ�Ϊ������
		   {
		      while(j < C)  //�ɼ�90��
		      {
		    	  if(huidu()<YUZHI)
		    		  Data1[TrueLine][j]=0;
		    	  else

		          Data1[TrueLine][j]=1;  //���˿�
		        //asm("nop");    //���в�������ɢ����������
		       // asm("nop");
for(;ipx<N;ipx++)asm("nop");
		        j++;
		      } //����ָ��ָ������1
		    TrueLine++;  //�����м�������1

		   }

//		    if(InterruptLine>238)//�ó��������
//		    {
//		      DataReadyFlag= 1; //����1�е�ͼ��׼�����
//		      InterruptLine = 0;
//		      TrueLine = 0;
//		    }

}
/*���ж�*/
void VSYN_IRQ(void)
{


	  InterruptLine = 0;  //ͼ��������α�����
		   TrueLine  = 0;      //����������α�����

}
