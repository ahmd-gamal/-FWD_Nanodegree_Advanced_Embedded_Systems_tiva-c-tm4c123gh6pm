/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define EN_MAIN_OSCILLATOR                   0u
#define DIS_MAIN_OSCILLATOR                  1u 

#define MAIN_OSCILLATOR                      0u
#define PRECISION_INTERNAL_OSCILLATOR        1u
#define PRECISION_INTERNAL_OSCILLATOR_4      2u
#define LOW_FREQUANCY_INTERNAL_OSCILLATOR    3u

#define CLOCK_VALIDATION_DIS                 0u
#define CLOCK_VALIDATION_EN                  1u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
typedef uint32 Gpt_ValueType;

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    ID_0=0u,
    ID_1,
    ID_2,
    ID_3,
    ID_4,
    ID_5,
    ID_6,
    ID_7,
    ID_8,
    ID_9,
    ID_10,
    ID_11
} Gpt_ChannelType;

typedef enum
{
    ONE_SHOT = 1u,
    PERIODIC, 
} Gpt_Channel_ModeType;

typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 4,
    GPT_PREDEF_TIMER_1US_24BIT = 4,
    GPT_PREDEF_TIMER_1US_32BIT = 0,
	GPT_PREDEF_TIMER_100US_32BIT=1
} Gpt_Predef_TimerType;

typedef struct
{
    Gpt_ChannelType        GPT_ChannelID;
    Gpt_Channel_ModeType GPT_Channel_Mode;
	Gpt_Predef_TimerType GPT_Predef_Timer;

} Gpt_ConfigType;


 
#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h
 *********************************************************************************************************************/
