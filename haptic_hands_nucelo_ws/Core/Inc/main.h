/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define pot0_Pin GPIO_PIN_5
#define pot0_GPIO_Port GPIOA
#define pot1_Pin GPIO_PIN_6
#define pot1_GPIO_Port GPIOA
#define pot2_Pin GPIO_PIN_7
#define pot2_GPIO_Port GPIOA
#define pot3_Pin GPIO_PIN_0
#define pot3_GPIO_Port GPIOB
#define pot4_Pin GPIO_PIN_1
#define pot4_GPIO_Port GPIOB
#define servo2_Pin GPIO_PIN_10
#define servo2_GPIO_Port GPIOB
#define vib4_Pin GPIO_PIN_8
#define vib4_GPIO_Port GPIOA
#define vib3_Pin GPIO_PIN_9
#define vib3_GPIO_Port GPIOA
#define vib2_Pin GPIO_PIN_10
#define vib2_GPIO_Port GPIOA
#define vib1_Pin GPIO_PIN_11
#define vib1_GPIO_Port GPIOA
#define vib0_Pin GPIO_PIN_12
#define vib0_GPIO_Port GPIOA
#define servo1_Pin GPIO_PIN_15
#define servo1_GPIO_Port GPIOA
#define servo0_Pin GPIO_PIN_3
#define servo0_GPIO_Port GPIOB
#define servo3_Pin GPIO_PIN_6
#define servo3_GPIO_Port GPIOB
#define servo4_Pin GPIO_PIN_7
#define servo4_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
