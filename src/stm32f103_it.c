#include "main.h"
#include "stm32f103_it.h"


//void SysTickHandler(void)
//{
//    HAL_IncTick();
//}

void HardFaultException(void) {
    // TODO:
    while (1);
}