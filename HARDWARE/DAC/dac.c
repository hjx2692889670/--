/*-------------------------------------------------------------------------------------
  miniʾ����
	2021.2.18 bySDS
	
	 TMR+DMA+DACʵ��
	 
	DAC  ʹ��PA4
	
---------------------------------------------------------------------------------------*/
#include "dac.h"
void Dac1_Init(void)
{
	DAC_InitTypeDef DACtypeDef;
	GPIO_PortClock(GPIOA,ENABLE); //�˿�A ʹ��
	GPIO_PinConfigure(GPIOA,4,GPIO_IN_ANALOG,GPIO_MODE_INPUT);  //�˿�5��ģʽ����
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);
	
	DAC_DeInit(); //
	DAC_StructInit(&DACtypeDef);//
	DACtypeDef.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;
	DACtypeDef.DAC_OutputBuffer=DAC_OutputBuffer_Disable;
	DACtypeDef.DAC_Trigger=DAC_Trigger_T6_TRGO;
	DACtypeDef.DAC_WaveGeneration=DAC_WaveGeneration_None;
	DAC_Init(DAC_Channel_1,&DACtypeDef);
		DAC_Cmd(DAC_Channel_1,ENABLE);
	DAC_DMACmd(DAC_Channel_1,ENABLE);
}




















































