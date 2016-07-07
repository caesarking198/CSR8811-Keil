 #ifndef __5110LCD_H
 #define __5110LCD_H

 #include "stm32f10x.h"	
///////////////////////////////////////////////////////
//------------------------------------/				 //
// SCE    ------------PA5  //Ƭѡ					 //
// RST    ------------PA4  //λѡ					 //
//  D/C    ------------PA3  // 1д���ݣ�0дָ��		 //
// SD     ------------PA2	   //����				 //
// SCLK   ------------PA1	   //ʱ��				 //
// LCD    ------------PA0      //����				 //
///////////////////////////////////////////////////////
    /*
  PB6-RST
  PB5-CE
  PD2-DC
  PC12-DIN
  PC11-CLK
  PC10-LED
  */
 #define sce0   GPIO_ResetBits(GPIOB, GPIO_Pin_5)  //ƬѡCE
 #define res0   GPIO_ResetBits(GPIOB, GPIO_Pin_6)  //��λRST,0��λ
 #define dc0    GPIO_ResetBits(GPIOD, GPIO_Pin_2)   //DC 1д���ݣ�0дָ��
 #define sdin0  GPIO_ResetBits(GPIOC, GPIO_Pin_12)   //����DIN
 #define sclk0  GPIO_ResetBits(GPIOC, GPIO_Pin_11)   //ʱ��CLK


 #define sce1   GPIO_SetBits(GPIOB, GPIO_Pin_5)  //ƬѡCE
 #define res1   GPIO_SetBits(GPIOB, GPIO_Pin_6)  //��λRST,0��λ
 #define dc1    GPIO_SetBits(GPIOD, GPIO_Pin_2)   //DC 1д���ݣ�0дָ��
 #define sdin1  GPIO_SetBits(GPIOC, GPIO_Pin_12)   //����DIN
 #define sclk1  GPIO_SetBits(GPIOC, GPIO_Pin_11)   //ʱ��CLK

 #define LED_LINGHT PCout(10)
	    
void GPIO_Configuration_LCD(void);
void LCD_WriteByte(unsigned char dt, unsigned char command);
void LCD_Init(void);
void LCD_Set_XY(unsigned char X, unsigned char Y);
void LCD_Clear(void);
void LCD_WriteChar(unsigned char X,unsigned char Y,unsigned char c);
void LCD_WriteString_en(unsigned char X,unsigned char Y,unsigned char *s);
void LCD_WriteNumber(unsigned char x,unsigned char y, unsigned long number);
void LCD_write_chinese_string(unsigned char X, unsigned char Y,
                              unsigned char ch_with,unsigned char num,
							  unsigned char line,unsigned char row);
void LCD_Write_cn(unsigned char row, unsigned char page,unsigned char c); //row:�� page:ҳ dd:�ַ�

//void delay_ms(int t);
#endif
