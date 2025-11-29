/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_ONE_Pin GPIO_PIN_0
#define BUTTON_ONE_GPIO_Port GPIOA
#define BUTTON_TWO_Pin GPIO_PIN_1
#define BUTTON_TWO_GPIO_Port GPIOA
#define BUTTON_THREE_Pin GPIO_PIN_2
#define BUTTON_THREE_GPIO_Port GPIOA
#define LED_RED_EW_Pin GPIO_PIN_3
#define LED_RED_EW_GPIO_Port GPIOA
#define LED_AMBER_EW_Pin GPIO_PIN_4
#define LED_AMBER_EW_GPIO_Port GPIOA
#define LED_GREEN_EW_Pin GPIO_PIN_5
#define LED_GREEN_EW_GPIO_Port GPIOA
#define LED_RED_NS_Pin GPIO_PIN_6
#define LED_RED_NS_GPIO_Port GPIOA
#define LED_AMBER_NS_Pin GPIO_PIN_7
#define LED_AMBER_NS_GPIO_Port GPIOA
#define LED_7SEG_a_Pin GPIO_PIN_0
#define LED_7SEG_a_GPIO_Port GPIOB
#define LED_7SEG_b_Pin GPIO_PIN_1
#define LED_7SEG_b_GPIO_Port GPIOB
#define LED_7SEG_c_Pin GPIO_PIN_2
#define LED_7SEG_c_GPIO_Port GPIOB
#define EN_LED2_Pin GPIO_PIN_10
#define EN_LED2_GPIO_Port GPIOB
#define EN_LED3_Pin GPIO_PIN_11
#define EN_LED3_GPIO_Port GPIOB
#define LED_GREEN_NS_Pin GPIO_PIN_8
#define LED_GREEN_NS_GPIO_Port GPIOA
#define LED_BUTTON_ONE_Pin GPIO_PIN_10
#define LED_BUTTON_ONE_GPIO_Port GPIOA
#define LED_BUTTON_TWO_Pin GPIO_PIN_11
#define LED_BUTTON_TWO_GPIO_Port GPIOA
#define LED_BUTTON_THREE_Pin GPIO_PIN_12
#define LED_BUTTON_THREE_GPIO_Port GPIOA
#define LED_7SEG_d_Pin GPIO_PIN_3
#define LED_7SEG_d_GPIO_Port GPIOB
#define LED_7SEG_e_Pin GPIO_PIN_4
#define LED_7SEG_e_GPIO_Port GPIOB
#define LED_7SEG_f_Pin GPIO_PIN_5
#define LED_7SEG_f_GPIO_Port GPIOB
#define LED_7SEG_g_Pin GPIO_PIN_6
#define LED_7SEG_g_GPIO_Port GPIOB
#define EN_LED0_Pin GPIO_PIN_8
#define EN_LED0_GPIO_Port GPIOB
#define EN_LED1_Pin GPIO_PIN_9
#define EN_LED1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
