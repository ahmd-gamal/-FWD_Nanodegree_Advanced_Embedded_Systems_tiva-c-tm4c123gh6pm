/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*system control*/
typedef struct 
{
    uint32 VECACT   :8             ;
    uint32          :3             ;
    uint32 RETBASE  :1             ;
    uint32 VECPEND  :4             ;
    uint32 		    :2             ; 
    uint32 ISRPEND  :1             ;
    uint32 ISRPRE   :1             ;
    uint32          :1             ;
    uint32 PENDSTCLR:1             ;
    uint32 PENDSTSET:1             ;
    uint32 UNPENDSV :1             ;
    uint32 PENDSV   :1             ;
    uint32          :2             ;
    uint32 NMISET   :1             ; 
}INTCTRL_BF                        ;
typedef union 
{
    uint32 R                       ;
    INTCTRL_BF B                   ;
}INTCTRL_Tag                       ;

typedef struct
{
	uint32 MOSCDIS     :1          ;
	uint32             :3          ;
	uint32 OSCSRC      :2          ;
	uint32 XTAL        :5          ;
	uint32 BYPASS      :1          ;
	uint32             :1          ;
	uint32 PWRDN       :1          ;
	uint32             :3          ;
	uint32 PWMDIV      :3          ;
	uint32 USEPWMDIV   :1          ;
	uint32             :1          ;
	uint32 USESYSDI    :1          ; 
	uint32 SYSDIV      :4          ;
	uint32 ACGG        :1          ;
	uint32             :4          ;
}RCC_BF                            ;
 
typedef union 
{
	uint32 R                       ;
	RCC_BF B                       ;
}RCC_Tag                           ;


typedef struct
{
	uint32 CVAL       :1           ;
	uint32 MOSCIM     :1           ;
	uint32 NOXTAL     :1           ;
	uint32            :29          ;
}MOSCCTL_BF                        ;

typedef union 
{
	uint32 R                       ;
	MOSCCTL_BF B                   ;
}MOSCCTL_Tag                       ;

/*GPIO*/
typedef struct
{
	uint32 GPIOA     :1            ;
	uint32 GPIOB     :1            ;
	uint32 GPIOC     :1            ;
	uint32 GPIOD     :1            ;
	uint32 GPIOE     :1            ;
	uint32 GPIOF     :1            ;
	uint32           :26           ;
}RCGCGPIO_BF                       ;

typedef union 
{
	uint32 R                       ;
	RCGCGPIO_BF B                  ;
}RCGCGPIO_Tag                      ;


typedef struct 
{
	volatile uint32 GPIODATA[256]  ;
	volatile uint32 GPIODIR        ;
	volatile uint32 GPIOIS         ;
	volatile uint32 GPIOIBE        ;
	volatile uint32 GPIOIEV        ;
	volatile uint32 GPIOIM         ;
	volatile uint32 GPIORIS        ;
	volatile uint32 GPIOMIS        ;
	volatile uint32 GPIOICR        ;
	volatile uint32 GPIOAFSEL      ;
	volatile uint32 RESERVED[55]   ;
	volatile uint32 GPIODR2R[3]    ;
  /*volatile uint32 GPIODR4R       ;
	volatile uint32 GPIODR8R       ;         */
	volatile uint32 GPIOODR [4]    ;
  /*volatile uint32 GPIOPUR        ;
	volatile uint32 GPIOPDR        ;
	volatile uint32 GPIOSLR        ;        */
	volatile uint32 GPIODEN        ;
	volatile uint32 GPIOLOCK       ;
	volatile uint32 GPIOCR         ;
	volatile uint32 GPIOAMSEL      ;
	volatile uint32 GPIOPCTL       ;
	volatile uint32 GPIOADCCTL     ;
	volatile uint32 GPIODMACTL	   ;
}GPIO_REGS_t                       ;

/*NVIC*/
typedef struct
{
    volatile uint32 EN[5]          ;
    volatile uint32 RESERVED_1[27] ;
    volatile uint32 DIS[5]         ; 
    volatile uint32 RESERVED_2[27] ;
    volatile uint32 PEND[5]        ;
    volatile uint32 RESERVED_3[27] ;
    volatile uint32 UNPEND[5]      ;
    volatile uint32 RESERVED_4[27] ;
    volatile uint32 ACTIVE[5]      ;
    volatile uint32 RESERVED_5[59] ;
    volatile uint32 PRI[35]        ;
    volatile uint32 RESERVED_6[669];
    volatile uint32 SWTRIG         ; 
} NVIC_REGS_t                      ;

typedef struct
{
    volatile uint32 INTCTRL        ;
    volatile uint32 VTABLE         ;
    volatile uint32 APINT          ;
    volatile uint32 SYSCTRL        ;
    volatile uint32 CFGCTRL        ;
    volatile uint32 SYSPRI1        ;
    volatile uint32 SYSPRI2        ;
    volatile uint32 SYSPRI3        ;
    volatile uint32 SYSHNDCTRL     ; 
    volatile uint32 FAULTSTAT      ;
    volatile uint32 HFAULTSTAT     ;
} SCB_REGS_t                       ;


/*General Purpose Timer*/
typedef struct
{
    volatile uint32 GPTMCFG        ;
    volatile uint32 GPTMTAMR[2]    ; 
/*	volatile uint32 GPTMTBMR       ;             */
    volatile uint32 GPTMCTL        ;
    volatile uint32 GPTMSYNC       ;
    volatile uint32 Reserved1      ;
    volatile uint32 GPTMIMR        ;             
    volatile uint32 GPTMRIS        ;             
    volatile uint32 GPTMMIS        ;             
    volatile uint32 GPTMICR        ;            
    volatile uint32 GPTMTAILR[2]   ;   
/*	volatile uint32 GPTMTBILR      ;             */
    volatile uint32 GPTMTAMATCHR[2]; 
/*  volatile uint32 GPTMTBMATCHR   ;             */
    volatile uint32 GPTMTAPR[2]    ;    
/*	volatile uint32 GPTMTBPR       ;             */
    volatile uint32 GPTMTAPMR[2]   ;    
/*	volatile uint32 GPTMTBPMR      ;             */
    volatile uint32 GPTMTAR[2]     ;      
/*	volatile uint32 GPTMTBR        ;             */
    volatile uint32 GPTMTAV[2]     ;
/*	volatile uint32 GPTMTBV        ;             */
	volatile uint32 GPTMRTCPD      ;
	volatile uint32 GPTMTAPS       ;
	volatile uint32 GPTMTBPS       ;
	volatile uint32 GPTMTAPV       ;
	volatile uint32 GPTMTBPV       ;
	volatile uint32 GPTMPP         ;
} GPT_REGS;                       


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*system control*/
#define SCB_BASE_ADDRESS                 0x400FE000

#define SYSCTRL_RCC 	    	         ((volatile RCC_Tag*)(SCB_BASE_ADDRESS+0x060))
#define SYSCTRL_MOSCCTL 		         ((volatile MOSCCTL_Tag*)(SCB_BASE_ADDRESS+0x07C))
#define SYSCTRL_RCGCGPIO 	             ((volatile RCGCGPIO_Tag*)(SCB_BASE_ADDRESS+0x608))

/*GPIO*/
#define GPIO_PORT_A_APB                  0x40004000
#define GPIO_PORT_B_APB                  0x40005000
#define GPIO_PORT_C_APB                  0x40006000
#define GPIO_PORT_D_APB                  0x40007000
#define GPIO_PORT_E_APB                  0x40024000
#define GPIO_PORT_F_APB                  0x40025000
#define GPIO_PORT_A_AHB                  0x40058000
#define GPIO_PORT_B_AHB                  0x40059000
#define GPIO_PORT_C_AHB                  0x4005A000
#define GPIO_PORT_D_AHB                  0x4005B000
#define GPIO_PORT_E_AHB                  0x4005C000
#define GPIO_PORT_F_AHB                  0x4005D000

#define MGPIOA                           ((GPIO_REGS_t*)GPIO_PORT_A_APB)
#define MGPIOB                           ((GPIO_REGS_t*)GPIO_PORT_B_APB)
#define MGPIOC                           ((GPIO_REGS_t*)GPIO_PORT_C_APB)
#define MGPIOD                           ((GPIO_REGS_t*)GPIO_PORT_D_APB)
#define MGPIOE                           ((GPIO_REGS_t*)GPIO_PORT_E_APB)
#define MGPIOF                           ((GPIO_REGS_t*)GPIO_PORT_F_APB)

/*NVIC*/
#define CORTEXM4_PERI_BASE_ADDRESS       0xE000E000
#define NVIC_REGS                        ((NVIC_REGS_t *)(CORTEXM4_PERI_BASE_ADDRESS + 0x100))
#define SCB_REGS                         ((SCB_REGS_t *)(CORTEXM4_PERI_BASE_ADDRESS + 0x500))

/*General Purpose Timer*/
#define GPT_16_32_00                     0x40030000
#define GPT_16_32_01                     0x40031000
#define GPT_16_32_02                     0x40032000
#define GPT_16_32_03                     0x40033000
#define GPT_16_32_04                     0x40034000
#define GPT_16_32_05                     0x40035000   
#define GPT_32_64_06                     0x40036000
#define GPT_32_64_07                     0x40037000
#define GPT_32_64_08                     0x4004C000
#define GPT_32_64_09                     0x4004D000
#define GPT_32_64_10                     0x4004E000
#define GPT_32_64_11                     0x4004F000

#define GPT00_REGS                       ((GPT_REGS *)(GPT_16_32_00))
#define GPT01_REGS                       ((GPT_REGS *)(GPT_16_32_01))
#define GPT02_REGS                       ((GPT_REGS *)(GPT_16_32_02))
#define GPT03_REGS                       ((GPT_REGS *)(GPT_16_32_03))
#define GPT04_REGS                       ((GPT_REGS *)(GPT_16_32_04))
#define GPT05_REGS                       ((GPT_REGS *)(GPT_16_32_05))		
#define GPT06_REGS                       ((GPT_REGS *)(GPT_32_64_06))
#define GPT07_REGS                       ((GPT_REGS *)(GPT_32_64_07))
#define GPT08_REGS                       ((GPT_REGS *)(GPT_32_64_08))
#define GPT09_REGS                       ((GPT_REGS *)(GPT_32_64_09))
#define GPT10_REGS                       ((GPT_REGS *)(GPT_32_64_10))
#define GPT11_REGS                       ((GPT_REGS *)(GPT_32_64_11))

  

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/




#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/












