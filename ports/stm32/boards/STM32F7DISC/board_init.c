#include STM32_HAL_H

#include "stm32746g_discovery_lcd.h"


void STM32F7DISC_board_early_init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    __HAL_RCC_GPIOK_CLK_ENABLE();
    __HAL_RCC_LTDC_CLK_ENABLE();

    // Turn off the backlight. LCD_BL_CTRL = PK3
    GPIO_InitStructure.Pin = GPIO_PIN_3;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOK, &GPIO_InitStructure);
    HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_RESET);

    BSP_LCD_Init();
    BSP_LCD_SetBackColor(0x0000ff00);
    BSP_LCD_LayerDefaultInit(0, 0x20000000); // 0x20023358);
}
