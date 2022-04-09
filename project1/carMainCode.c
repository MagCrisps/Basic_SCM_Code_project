#include "intrins.h"

/*
 *此代码只能实现一些基础功能，如果对具体的算法感兴趣的话，那么你可以去找我要完整的代码实例
 *
 */


//定义特殊功能寄存器，原理图不同所定义的寄存器也不同，请根据实际的原理图定义
sbit L298D_IN1 = 0x92;
sbit L298D_IN2 = 0x93;
sbit L298D_IN3 = 0x94;
sbit L298D_IN4 = 0x95;

sbit leftPro = 0xB4; 
sbit rightPro  = 0xB5;
/*
 ***********************************************
 * name Delay
 * function	 延时50微秒
 * parameter 无
 * return	 无
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
 * function	识别并处理红外线信息
 * parameter   无
 * return （无符号的字符型）1~4 
 			*1代表 前方左右均无障碍；
			*2代表 左方无障碍右方有障碍；
			*3代表 右方无障碍左方有障碍；
			*4代表 前方左右均有障碍；
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
 * function	通过L298N控制小车行进方向
 * parameter   均无
 * return	   均无
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
