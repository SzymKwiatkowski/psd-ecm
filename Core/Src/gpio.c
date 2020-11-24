/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */
#include "canopen_object_dict.h"
#include "can.h"

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_D4_Pin|LED_D5_Pin|LED_D6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CAN1_RS_GPIO_Port, CAN1_RS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CAN2_RS_GPIO_Port, CAN2_RS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin
                           PEPin PEPin PEPin PEPin
                           PEPin PEPin PEPin PEPin
                           PEPin PEPin PEPin */
  GPIO_InitStruct.Pin = OPTO_INPUT2_Pin|OPTO_INPUT3_Pin|OPTO_INPUT4_Pin|OPTO_INPUT5_Pin
                          |OPTO_INPUT6_Pin|OPTO_INPUT15_Pin|OPTO_INPUT14_Pin|OPTO_INPUT13_Pin
                          |OPTO_INPUT12_Pin|OPTO_INPUT11_Pin|OPTO_INPUT10_Pin|OPTO_INPUT9_Pin
                          |OPTO_INPUT8_Pin|OPTO_INPUT7_Pin|OPTO_INPUT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = LED_D4_Pin|LED_D5_Pin|LED_D6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = CAN1_RS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CAN1_RS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = CAN2_RS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CAN2_RS_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI1_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

}

/* USER CODE BEGIN 2 */

/**
 * @brief: store incoming lights cuff switches and send over can to lights controller
 *
 **/
void GpioOptoInputsService() {
	/* opto input 1 */
	if (HAL_GPIO_ReadPin(OPTO_INPUT1_GPIO_Port, OPTO_INPUT1_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x01, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 2 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT2_GPIO_Port, OPTO_INPUT2_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x02, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 3 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT3_GPIO_Port, OPTO_INPUT3_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x03, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 4 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT4_GPIO_Port, OPTO_INPUT4_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x04, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 5 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT5_GPIO_Port, OPTO_INPUT5_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x05, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 6 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT6_GPIO_Port, OPTO_INPUT6_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x06, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 7 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT7_GPIO_Port, OPTO_INPUT7_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x07, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 8 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT8_GPIO_Port, OPTO_INPUT8_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x08, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 9 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT9_GPIO_Port, OPTO_INPUT9_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x09, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 10 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT10_GPIO_Port, OPTO_INPUT10_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x0A, 0, 0, 0, 0, 0, 0);
	}

	/* opto input 11 */
	else if (HAL_GPIO_ReadPin(OPTO_INPUT11_GPIO_Port, OPTO_INPUT11_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 2, SDO_UPLOAD, 0x0B, 0, 0, 0, 0, 0, 0);
	}

	else {
		HAL_GPIO_TogglePin(LED_D4_GPIO_Port, LED_D4_Pin);
	}

}

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
