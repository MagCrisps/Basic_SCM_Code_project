#ifndef __MatrixLED_relevant_h__ 
#define __MatrixLED_relevant_h__  

void led_init();
void led_show(unsigned char location,Byte);
void Delay(unsigned int xms);
void led_Anim1(char *animation,unsigned int length);
void led_Anim2(char *animation,unsigned int length);

#endif