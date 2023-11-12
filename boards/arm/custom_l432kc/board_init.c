/*
 * Copyright (c) 2021 Espressif Systems (Shanghai) Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/gpio.h>

#define BL_PIN     5

static int board_init(void)
{
	/* turns LCD backlight on */
    gpio_pin_configure(gpiob, 0, GPIO_OUTPUT);
	gpio_pin_set(gpiob, 0, 1);

	return 0;
}

SYS_INIT(board_init, APPLICATION, CONFIG_GPIO_INIT_PRIORITY);
