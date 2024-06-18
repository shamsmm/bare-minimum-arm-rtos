#include <stdint.h>
#include "stm32f103_it.h"
#include "system_stm32f1xx.h"

void Default_Handler(void) {
    while(1);
}

void NMIException (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFaultException (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManageException (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFaultException (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFaultException (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMonitor (void) __attribute__ ((weak, alias("Default_Handler")));
void SVCHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSVC (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTickHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void TAMPER_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMAChannel1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMAChannel2_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMAChannel3_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMAChannel4_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMAChannel5_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMAChannel6_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMAChannel7_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_LP_CAN_RX0_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_RX1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_SCE_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void USART3_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void RTCAlarm_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void USBWakeUp_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));


/* Exported types --------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
extern unsigned long _etext;
extern unsigned long _sidata;		/* start address for the initialization values of the .data section. defined in linker script */
extern unsigned long _sdata;		/* start address for the .data section. defined in linker script */
extern unsigned long _edata;		/* end address for the .data section. defined in linker script */

extern unsigned long _sbss;			/* start address for the .bss section. defined in linker script */
extern unsigned long _ebss;			/* end address for the .bss section. defined in linker script */

extern void _estack;		/* init value for the stack pointer. defined in linker script */



/* Private typedef -----------------------------------------------------------*/
/* function prototypes ------------------------------------------------------*/
void Reset_Handler(void) __attribute__((__interrupt__));
extern int main(void);
extern void xPortPendSVHandler(void);
extern void xPortSysTickHandler(void);
//extern void vTimer2IntHandler( void );
extern void vPortSVCHandler( void );

__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
  &_estack,            // The initial stack pointer
  Reset_Handler,             // The reset handler
  NMIException,
  HardFaultException,
  MemManageException,
  BusFaultException,
  UsageFaultException,
  (void*)0, (void*)0, (void*)0, (void*)0,            /* Reserved */ 
  vPortSVCHandler,
  DebugMonitor,
  (void*)0,                      /* Reserved */
  xPortPendSVHandler,
  xPortSysTickHandler,
  WWDG_IRQHandler,
  PVD_IRQHandler,
  TAMPER_IRQHandler,
  RTC_IRQHandler,
  FLASH_IRQHandler,
  RCC_IRQHandler,
  EXTI0_IRQHandler,
  EXTI1_IRQHandler,
  EXTI2_IRQHandler,
  EXTI3_IRQHandler,
  EXTI4_IRQHandler,
  DMAChannel1_IRQHandler,
  DMAChannel2_IRQHandler,
  DMAChannel3_IRQHandler,
  DMAChannel4_IRQHandler,
  DMAChannel5_IRQHandler,
  DMAChannel6_IRQHandler,
  DMAChannel7_IRQHandler,
  ADC_IRQHandler,
  USB_HP_CAN_TX_IRQHandler,
  USB_LP_CAN_RX0_IRQHandler,
  CAN_RX1_IRQHandler,
  CAN_SCE_IRQHandler,
  EXTI9_5_IRQHandler,
  TIM1_BRK_IRQHandler,
  TIM1_UP_IRQHandler,
  TIM1_TRG_COM_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  TIM4_IRQHandler,
  I2C1_EV_IRQHandler,
  I2C1_ER_IRQHandler,
  I2C2_EV_IRQHandler,
  I2C2_ER_IRQHandler,
  SPI1_IRQHandler,
  SPI2_IRQHandler,
  USART1_IRQHandler,
  USART2_IRQHandler,
  USART3_IRQHandler,
  EXTI15_10_IRQHandler,
  RTCAlarm_IRQHandler,
  USBWakeUp_IRQHandler,
  (void*)0,
  (void*)0,
  (void*)0,
  (void*)0,
  (void*)0,
  (void*)0,
  (void*)0,
  (void*)0xF108F85F //this is a workaround for boot in RAM mode.
};

void Reset_Handler(void)
{
//    SystemInit();

    unsigned long *pulSrc, *pulDest;

    //
    // Copy the data segment initializers from flash to SRAM.
    //
    pulSrc = &_sidata;
    for(pulDest = &_sdata; pulDest < &_edata; )
    {
        *(pulDest++) = *(pulSrc++);
    }

    //
    // Zero fill the bss segment.
    //
    for(pulDest = &_sbss; pulDest < &_ebss; )
    {
        *(pulDest++) = 0;
    }

    //
    // Call the application's entry point.
    //
    main();

    for (;;);
}


/********************* (C) COPYRIGHT 2007 STMicroelectronics  *****END OF FILE****/


