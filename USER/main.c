//***********************************************************

#include "sys.h"
#include "plusc2c.h"

//***********************************************************

#define STR(A) 	(unsigned char*)(A)



int main ( void )
{
	
	uint8_t static ledstat;
	SystemInit();//ϵͳʱ�ӵȳ�ʼ��
	if(SysTick_Config(72000*1))	 //���ô��󷵻�1,max 16777216   Ĭ��72Mhz ʱ�� ,1ms��ʱ
	{							
		LED4_ON; 	//������ 		
		while(1);
	}
	
	LED_Init();	 //LED�˿ڳ�ʼ��
	NVIC_Configuration();//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	Uart1Init ( 115200 ); //���ڳ�ʼ��Ϊ115200
	Uart2Init ( 115200 ); //���ڳ�ʼ��Ϊ115200
	Uart3Init ( 115200 );//���ڳ�ʼ��Ϊ115200

	Uart1SendStr(STR("uart1 init\r\n"));

	Uart2SendStr(STR("uart2 init\r\n"));

	Uart3SendStr(STR("uart3 init\r\n"));


//	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD , ENABLE );
//	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOC, ENABLE );
//	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOD, ENABLE );

	
//	GPIO_Configuration_LCD();
//	GPIO_ResetBits ( GPIOC, GPIO_Pin_10 );
//	LED_LINGHT = 1;
//	LCD_Init();
//	LCD_Clear();
//	LCD_WriteString_en ( 0, 0, PSTR("gsm starting") );
//	LCD_WriteString_en ( 1, 1, PSTR("gsm starting") );
//	LCD_WriteString_en ( 2, 2, PSTR("gsm starting") );
//	LCD_WriteString_en ( 3, 3, PSTR("gsm starting") );
//	LCD_WriteString_en ( 4, 4, PSTR("gsm starting") );
//	Timerx_Init ( 1000, 7199 ); //10Khz�ļ���Ƶ�ʣ�1000��Ϊ10ms
	
	C_bt_init();
	C_bt_module_reset();
	C_bt_module_init();
	
	 
	LED1_ON;
	LED2_ON;
	LED3_ON;
	LED4_ON;
	delay_ms ( 500 );
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF; 

	while(1)
	{
		//���е�
		if( ms_delay_counter >500 ){
			ms_delay_counter = 0;
			if( ledstat ){
				LED1_ON;
			}else{
				LED1_OFF;
			}
			ledstat = !ledstat;
		}
		
		//�����ٶ��ر��ᵼ�³�ʼ��ʧ��
		if((ms_timer %10) == 0){
			C_bt_step();
		}
		
		//ģ���ʼ���ɹ����
		if(C_bt_selftest()){
			LED2_ON;
		}else{
			LED2_OFF;
		}
		
		//ģ����Ժ�ͨ������ok
		if(C_bt_device_active()){
			LED3_ON;
			if(Uart1_RcvCnt){
				delay_ms(100);
				//��������
				C_bt_send((char*)Uart1_Buff,Uart1_RcvCnt);
				Uart1_RcvCnt = 0;				
			}
		}else{
			LED3_OFF;
		}

	}
}
