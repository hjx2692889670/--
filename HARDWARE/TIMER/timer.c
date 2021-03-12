#include "timer.h"
#include "led.h"
/*
:Tout=((arr+1)*(psc+1))/Ft us.
  ��ʱ��6  ����DAC1�Ĵ���
*/
void TIM6_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef 				TIMtypeDef;
	NVIC_InitTypeDef 				NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	
	TIM_DeInit(TIM6);
	
	  TIMtypeDef.TIM_ClockDivision=TIM_CKD_DIV1;
	TIMtypeDef.TIM_CounterMode=TIM_CounterMode_Up;
	TIMtypeDef.TIM_Period=arr;
	TIMtypeDef.TIM_Prescaler=psc;
	TIMtypeDef.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM6,&TIMtypeDef);
	
	 TIM_ITConfig(TIM6, TIM_IT_Update,ENABLE);
     //Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 2;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//�����ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���

	
	TIM_SelectOutputTrigger(TIM6,TIM_TRGOSource_Update);

}

 void TIM6_IRQHandler()  //  ��ʱ 500ms
 {
  static u16 count=0;
	while(TIM_GetITStatus(TIM6,TIM_IT_Update)!=RESET)
	{
		count++;
		if(count>1000) {      //  
			LED0=~LED0;	
			count=0 ;
		}
		TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
	}

 }
/*
  ��ʱ��3 ����ADC1 �Ĵ���ת��
:	Tout=((arr+1)*(psc+1))/Ft us.
*/
void TIM3_Int_Init(u16 arr,u16 psc)
{  
	TIM_TimeBaseInitTypeDef  TIM_BaseTypeDef;

 	GPIO_PortClock(GPIOA,ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

		TIM_DeInit(TIM3);
	
	TIM_BaseTypeDef.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_BaseTypeDef.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_BaseTypeDef.TIM_Period=arr;
	TIM_BaseTypeDef.TIM_Prescaler=psc;
	TIM_BaseTypeDef.TIM_RepetitionCounter=0;
		TIM_TimeBaseInit(TIM3,&TIM_BaseTypeDef);
	
	TIM_SelectOutputTrigger(TIM3,TIM_TRGOSource_Update);
}













