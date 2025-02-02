/**
 * @file    isr_vectors.c
 * @brief   Interrupt vector table and default interrupt handlers for STM32F401.
 *
 * This file defines the interrupt vector table for the STM32F401 microcontroller.
 * Each interrupt vector is associated with a weakly linked interrupt handler, which 
 * by default is redirected to a common default handler. Specific interrupt handlers 
 * can be implemented by overriding the weakly linked default handlers.
 *
 * @details
 * The interrupt vector table includes handlers for the core system interrupts (NMI, 
 * HardFault, etc.) and external interrupts for peripherals (e.g., TIM2, USART1).
 * The vector table is placed at the beginning of the memory section defined by 
 * the ".vectors" linker section.
 *
 * @note
 * The _estack symbol is defined in the linker script and points to the end of RAM.
 *
 * @attention
 * Make sure to implement the necessary interrupt handlers for your application 
 * to avoid the default infinite loop in the default handler.
 *
 * @see STM32F401 Reference Manual
 */

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include <stdint.h>

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Local types definitions 
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Object allocations 
|===================================================================================================================================|
*/
/* This symbol is created by the linker script. */
extern const char _estack;

/*
|===================================================================================================================================|
    Local function declarations
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Function definitions
|===================================================================================================================================|
*/

void Reset_Handler(void); /* Defined in assembly startup */

/* Every not used interrupt is redirected to default handler. */
static void __attribute__ ((interrupt)) __Default_Handler(void)
{
    while (1)
    {
        ;
    }
}

/* List of interrupt routines
 * */
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))NMI_Handler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))HardFault_Handler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))MemManage_Handler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))BusFault_Handler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))UsageFault_Handler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))SVC_Handler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DebugMon_Handler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))PendSV_Handler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))SysTick_Handler(void);
/* External Interrupts */
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))WWDG_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))PVD_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TAMP_STAMP_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))RTC_WKUP_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))FLASH_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))RCC_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))EXTI0_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))EXTI1_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))EXTI2_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))EXTI3_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))EXTI4_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA1_Stream0_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA1_Stream1_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA1_Stream2_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA1_Stream3_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA1_Stream4_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA1_Stream5_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA1_Stream6_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))ADC_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))EXTI9_5_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TIM1_BRK_TIM9_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TIM1_UP_TIM10_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TIM1_TRG_COM_TIM11_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TIM1_CC_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TIM2_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TIM3_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TIM4_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))I2C1_EV_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))I2C1_ER_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))I2C2_EV_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))I2C2_ER_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))SPI1_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))SPI2_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))USART1_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))USART2_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))EXTI15_10_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))RTC_Alarm_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))OTG_FS_WKUP_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA1_Stream7_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))SDIO_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))TIM5_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))SPI3_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA2_Stream0_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA2_Stream1_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA2_Stream2_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA2_Stream3_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA2_Stream4_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))OTG_FS_IRQHandler      (void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA2_Stream5_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA2_Stream6_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))DMA2_Stream7_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))USART6_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))I2C3_EV_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))I2C3_ER_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))FPU_IRQHandler(void);
void __attribute__ ((interrupt, weak, alias("__Default_Handler")))SPI4_IRQHandler(void);

/*
*/
void (* const vectors[])(void) __attribute__ ((section(".vectors"))) =
{
    (void (*)(void))(uintptr_t)&_estack,        /* Initial stack pointer - end of RAM */ 
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,
    /* External Interrupts */
    WWDG_IRQHandler           ,      /* Window WatchDog              */
    PVD_IRQHandler            ,      /* PVD through EXTI Line detection */
    TAMP_STAMP_IRQHandler     ,      /* Tamper and TimeStamps through the EXTI line */
    RTC_WKUP_IRQHandler       ,      /* RTC Wakeup through the EXTI line */
    FLASH_IRQHandler          ,      /* FLASH                        */
    RCC_IRQHandler            ,      /* RCC                          */
    EXTI0_IRQHandler          ,      /* EXTI Line0                   */
    EXTI1_IRQHandler          ,      /* EXTI Line1                   */
    EXTI2_IRQHandler          ,      /* EXTI Line2                   */
    EXTI3_IRQHandler          ,      /* EXTI Line3                   */
    EXTI4_IRQHandler          ,      /* EXTI Line4                   */
    DMA1_Stream0_IRQHandler   ,      /* DMA1 Stream 0                */
    DMA1_Stream1_IRQHandler   ,      /* DMA1 Stream 1                */
    DMA1_Stream2_IRQHandler   ,      /* DMA1 Stream 2                */
    DMA1_Stream3_IRQHandler   ,      /* DMA1 Stream 3                */
    DMA1_Stream4_IRQHandler   ,      /* DMA1 Stream 4                */
    DMA1_Stream5_IRQHandler   ,      /* DMA1 Stream 5                */
    DMA1_Stream6_IRQHandler   ,      /* DMA1 Stream 6                */
    ADC_IRQHandler            ,      /* ADC1                         */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    EXTI9_5_IRQHandler        ,      /* External Line[9:5]s          */
    TIM1_BRK_TIM9_IRQHandler  ,      /* TIM1 Break and TIM9          */
    TIM1_UP_TIM10_IRQHandler  ,      /* TIM1 Update and TIM10        */
    TIM1_TRG_COM_TIM11_IRQHandler,   /* TIM1 Trigger and Commutation and TIM11 */
    TIM1_CC_IRQHandler        ,      /* TIM1 Capture Compare         */
    TIM2_IRQHandler           ,      /* TIM2                         */
    TIM3_IRQHandler           ,      /* TIM3                         */
    TIM4_IRQHandler           ,      /* TIM4                         */
    I2C1_EV_IRQHandler        ,      /* I2C1 Event                   */
    I2C1_ER_IRQHandler        ,      /* I2C1 Error                   */
    I2C2_EV_IRQHandler        ,      /* I2C2 Event                   */
    I2C2_ER_IRQHandler        ,      /* I2C2 Error                   */
    SPI1_IRQHandler           ,      /* SPI1                         */
    SPI2_IRQHandler           ,      /* SPI2                         */
    USART1_IRQHandler         ,      /* USART1                       */
    USART2_IRQHandler         ,      /* USART2                       */
    0                         ,      /* Reserved                     */
    EXTI15_10_IRQHandler      ,      /* External Line[15:10]s        */
    RTC_Alarm_IRQHandler      ,      /* RTC Alarm (A and B) through EXTI Line */
    OTG_FS_WKUP_IRQHandler    ,      /* USB OTG FS Wakeup through EXTI line */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    DMA1_Stream7_IRQHandler   ,      /* DMA1 Stream7                 */
    0                         ,      /* Reserved                     */ 
    SDIO_IRQHandler           ,      /* SDIO                         */ 
    TIM5_IRQHandler           ,      /* TIM5                         */ 
    SPI3_IRQHandler           ,      /* SPI3                         */ 
    0                         ,      /* Reserved                     */ 
    0                         ,      /* Reserved                     */ 
    0                         ,      /* Reserved                     */ 
    0                         ,      /* Reserved                     */
    DMA2_Stream0_IRQHandler   ,      /* DMA2 Stream 0                */
    DMA2_Stream1_IRQHandler   ,      /* DMA2 Stream 1                */
    DMA2_Stream2_IRQHandler   ,      /* DMA2 Stream 2                */
    DMA2_Stream3_IRQHandler   ,      /* DMA2 Stream 3                */
    DMA2_Stream4_IRQHandler   ,      /* DMA2 Stream 4                */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    OTG_FS_IRQHandler         ,      /* USB OTG FS                   */
    DMA2_Stream5_IRQHandler   ,      /* DMA2 Stream 5                */
    DMA2_Stream6_IRQHandler   ,      /* DMA2 Stream 6                */
    DMA2_Stream7_IRQHandler   ,      /* DMA2 Stream 7                */
    USART6_IRQHandler         ,      /* USART6                       */
    I2C3_EV_IRQHandler        ,      /* I2C3 event                   */
    I2C3_ER_IRQHandler        ,      /* I2C3 error                   */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    FPU_IRQHandler            ,      /* FPU                          */
    0                         ,      /* Reserved                     */
    0                         ,      /* Reserved                     */
    SPI4_IRQHandler                  /* SPI4                         */
};
