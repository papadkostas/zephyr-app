#include "main_screen.h"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(lv_main_scr, LOG_LEVEL_DBG);

lv_obj_t * img;
lv_obj_t * btn;
lv_obj_t * label;
lv_obj_t * img_btn;

lv_obj_t * chart;
lv_obj_t * pwd_change_label;
lv_obj_t * cpu_label;
lv_obj_t * mem_label;
lv_obj_t * time_lbl;
lv_obj_t * roller1;
lv_obj_t * roller2;
lv_obj_t * roller3;
lv_obj_t * roller4;

lv_obj_t * sens_status;
lv_obj_t * distance_meas;
lv_obj_t * ppl_count;
lv_obj_t * ppl_counter_label;

lv_obj_t * pwd_change_ta;

lv_obj_t * mbox1;
lv_timer_t * timer;

lv_obj_t * list_mainmenu;
lv_obj_t * dropdown;
lv_obj_t * roller1;
lv_obj_t * return_btn;

lv_obj_t * main_screen;

static void login_screen_cb(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
	if(code == LV_EVENT_PRESSED){
		// if(requires_password == true){
		if(true){
            lv_obj_t * lock_screen;
			lv_scr_load_anim(lock_screen_create(lock_screen), LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 0, true);
		} else {
			// lv_scr_load_anim(settings_screen_create(settings_screen), LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 0, true);
		}
        LOG_INF("Button pressed");
	}
}

lv_obj_t * main_screen_create(lv_obj_t * parent) {

	lv_obj_clear_flag(parent, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_clear_flag(parent, LV_OBJ_FLAG_CLICKABLE);

	lv_obj_t * header = lv_obj_create(parent);
	lv_obj_set_size(header, LV_HOR_RES, HEADER_HEIGHT);
	lv_obj_set_pos(header, 0, 0);

	lv_obj_clear_flag(header, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_clear_flag(header, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_style_border_width(header, 0, 0);

	cpu_label = lv_label_create(header);
	lv_obj_set_pos(cpu_label, 0, -10);

	mem_label = lv_label_create(header);
	lv_obj_set_pos(mem_label, 0, 5);

	time_lbl = lv_label_create(header);
	lv_obj_align(time_lbl, LV_ALIGN_TOP_MID, 0, 0);
	lv_label_set_text(time_lbl, "--:--");

	lv_obj_t * btn = lv_btn_create(header);
	lv_obj_t * img = lv_img_create(btn);
	lv_img_set_src(img, LV_SYMBOL_SETTINGS);
	lv_obj_align(btn, LV_ALIGN_TOP_RIGHT, 0, -10);
	lv_obj_add_event_cb(btn, login_screen_cb, LV_EVENT_PRESSED, NULL);

	lv_obj_t * main_cont = lv_obj_create(parent);

	lv_obj_set_size(main_cont, LV_HOR_RES, LV_VER_RES-HEADER_HEIGHT);
	lv_obj_align_to(main_cont, header, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

	lv_obj_set_style_pad_left(main_cont, 0 , 0);
	lv_obj_set_style_pad_right(main_cont, 0 , 0);
	lv_obj_set_style_pad_top(main_cont, 0 , 0);
	lv_obj_set_style_pad_bottom(main_cont, 0 , 0);
	lv_obj_set_style_border_width(main_cont, 0, 0);

	lv_obj_clear_flag(main_cont, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_clear_flag(parent, LV_OBJ_FLAG_CLICKABLE);

	// lv_obj_t * entry_icon = lv_img_create(main_cont);
	// lv_img_set_src(entry_icon, &entry_ico_80);
	// lv_obj_align_to(entry_icon, parent, LV_ALIGN_LEFT_MID, 10, 0);

	lv_style_t * counter_font_style;
	lv_style_init(&counter_font_style);

	lv_obj_t * ppl_counter_label = lv_label_create(main_cont);
	lv_obj_add_style(ppl_counter_label, &counter_font_style, 0);
	// lv_obj_align_to(ppl_counter_label, entry_icon, LV_ALIGN_BOTTOM_MID, 0, 40);

	lv_obj_t * chart1 = lv_chart_create(main_cont);
	lv_obj_align(chart1, LV_ALIGN_RIGHT_MID, -20, 0);
	lv_obj_set_size(chart1, 200, 150);

	lv_chart_set_type(chart1, LV_CHART_TYPE_BAR);
	lv_chart_set_div_line_count(chart1, 5, 7);
	lv_chart_set_update_mode(chart1, LV_CHART_UPDATE_MODE_CIRCULAR);

	/*Add two data series*/
	lv_obj_t * ser1 = lv_chart_add_series(chart1, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);

	return parent;
}
