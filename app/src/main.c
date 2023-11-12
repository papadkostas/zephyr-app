/*
 * Copyright (c) 2018 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <lvgl_input_device.h>
#include <zephyr/logging/log.h>

#include "main_screen.h"

LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

static uint32_t count;

static void lv_btn_click_callback(lv_event_t *e)
{
	ARG_UNUSED(e);
	LOG_INF("button pressed");
	count = 0;
}

int main(void)
{
	const struct device *display_dev;
	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		LOG_ERR("Device not ready, aborting test");
		return 0;
	}

	lv_task_handler();
	
	display_blanking_off(display_dev);
	
	LOG_INF("App started!");
	
	main_screen_create(lv_scr_act());

	while (1) {
		lv_task_handler();
		k_sleep(K_MSEC(10));
	}
}
