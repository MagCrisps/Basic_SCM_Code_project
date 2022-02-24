#include "intrins.h"

/*
 *�˴���ֻ��ʵ��һЩ�������ܣ�����Ծ�����㷨����Ȥ�Ļ�����ô�����ȥ����Ҫ�����Ĵ���ʵ��
 *
 */


//�������⹦�ܼĴ�����ԭ��ͼ��ͬ������ļĴ���Ҳ��ͬ�������ʵ�ʵ�ԭ��ͼ����
sbit L298D_IN1 = 0x92;
sbit L298D_IN2 = 0x93;
sbit L298D_IN3 = 0x94;
sbit L298D_IN4 = 0x95;

sbit leftPro = 0xB4; 
sbit rightPro  = 0xB5;
/*
 ***********************************************
 * name Delay
 * function	 ��ʱ50΢��
 * parameter ��
 * return	 ��
 ***********************************************
 */ 
void Delay()		//@12.000MHz 50us
{
	unsigned char i, j;

	i = 1;
	j = 146;
	do
	{
		while (--j);
	} while (--i);
}


/*
 ***********************************************
 * name process
 * function	ʶ�𲢴����������Ϣ
 * parameter   ��
 * return ���޷��ŵ��ַ��ͣ�1~4 
 			*1���� ǰ�����Ҿ����ϰ���
			*2���� �����ϰ��ҷ����ϰ���
			*3���� �ҷ����ϰ������ϰ���
			*4���� ǰ�����Ҿ����ϰ���
 ***********************************************
 */	 
char process()
{	
	unsigned char flag = 0;
	if(leftPro){
		flag += 0;	
	}else{
		flag ++;
	}
	flag = flag << 1;
	if(rightPro){
		flag += 0;	
	}else{
		flag ++;
	}
	switch(flag){
		case 0 : return 1;break;
		case 1 : return 2;break;
		case 2 : return 3;break;
		case 3 : return 4;break;
		default : return 0;
	}
	
}

/*
 ***********************************************
 * name  ****
 * function	ͨ��L298N����С���н�����
 * parameter   ����
 * return	   ����
 ***********************************************
 */
void goForward()
{
	L298D_IN1 = 1;
	L298D_IN2 = 0;
	L298D_IN3 = 1;
	L298D_IN4 = 0;
	Delay();	
}
void goBackward()
{
	L298D_IN1 = 0;
	L298D_IN2 = 1;
	L298D_IN3 = 0;
	L298D_IN4 = 1;
	Delay();	
}
void goRight()
{
	L298D_IN1 = 1;
	L298D_IN2 = 0;
	L298D_IN3 = 0;
	L298D_IN4 = 1;
	Delay();	
}
void goLeft()
{
	L298D_IN1 = 0;
	L298D_IN2 = 1;
	L298D_IN3 = 1;
	L298D_IN4 = 0;
	Delay();
}
void stop()
{
	L298D_IN1 = 1;
	L298D_IN2 = 1;
	L298D_IN3 = 1;
	L298D_IN4 = 1;
	while(1);
}