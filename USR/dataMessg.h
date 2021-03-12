#ifndef _DATAMESSG_H
#define _DATAMESSG_H
#include "stm32_dsp.h"
#include "ADC_DMA_TMR.h"

/*
  DAC��ʱ������   TIM6
	rcc��499��pre: 71  Tout=500*72/72 =500us, Ĭ�� 1/0.5 KHZ , 1/0.5/len256 points ==xxx---- 15.625Hz  7.8125 Hz   
	ÿ����֮��ļ�� 500/256== 1.95 us 
	SUM: 2000/len Hz
	
	ADC ת��ʱ�䣨Խ��--->��ȷ��		1/12 *(12.5+13.5)=2.17us 
	��ʱ������   TIM3
	rcc:20, pec:1800(ret) Fout =72/20/ret ��ʼ��� �� Fout=2KHz  500us
	502.17us      1995 Hz    ÿ��502.17us  ����ADCת��
	
	1995/256==7.79hz
	1/(20*ret/72+2.17)/256
	502.17/256 == 1.96	ÿ��ʱ����1.96us
//SUM:����Ƶ�ʣ�256/(2.17+20*ret/72)  *10^6Hz
*/

typedef enum _statue  
{
	START_TASK=0,  
	ADC_TASK,
	DAC_TASK,
	DATA_TASK,
	RUN_TASK, //Ԥѡ״̬
} CUR_TASK;


typedef struct
{
	u8 curTask;
	u8 up;// 				/KEY1
	u8 down;//      //KEY0
	u8 enter;//       //WKUP һ���ص�home
	void (*current_operation)();
} key_table;

void doDataPre(void);
#endif

