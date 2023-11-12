#include "lock_screen.h"

lv_obj_t * btnm;
lv_obj_t * lock_screen_ta;

static const char * btnm_map[] = {"1", "2", "3", "\n",
								 "4", "5", "6", "\n",
								 "7", "8", "9", "\n",
								 LV_SYMBOL_BACKSPACE, "0", LV_SYMBOL_NEW_LINE, "\n",
								 LV_SYMBOL_HOME, ""};
 
void messagebox_timer(lv_timer_t * timer) {
	lv_obj_t * mbox = timer->user_data;
	lv_msgbox_close(mbox);
	if(lv_obj_is_valid(btnm)) {
		lv_obj_add_flag(btnm, LV_OBJ_FLAG_CLICKABLE);
	}
}

void ta_event_cb(lv_event_t * e) {
	lv_obj_t * ta_ = lv_event_get_target(e);
	lv_event_code_t code = lv_event_get_code(e);
	if (ta_ == lock_screen_ta) {
		if (code == LV_EVENT_READY) {
			if (strcmp(password, lv_textarea_get_text(ta_)) == 0) {
				LV_LOG_USER("Password correct. The current password is: %s", lv_textarea_get_text(ta_));		
				// lv_scr_load_anim(settings_screen_create(settings_screen), LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 0, true);

			} else {
				LV_LOG_USER("Password incorrect. The current password is: %s", lv_textarea_get_text(ta_));
                lv_obj_clear_flag(btnm, LV_OBJ_FLAG_CLICKABLE);
				lv_obj_t * mbox1 = lv_msgbox_create(lv_obj_get_parent(ta_), NULL, "Password Incorrect!", NULL, NULL);
				lv_timer_t * timer = lv_timer_create(messagebox_timer, 1000, mbox1);
				lv_timer_set_repeat_count(timer, 1);
				lv_obj_set_width(mbox1, 200);
				lv_obj_align(mbox1, LV_ALIGN_CENTER, 0, 0);
				lv_textarea_set_text(ta_, "");
			}
		}
	}
}

static void lock_screen_event_handler(lv_event_t * e) {
	lv_obj_t * obj = lv_event_get_target(e);
	lv_obj_t * ta = lv_event_get_user_data(e);
	const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));

	if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
		lv_textarea_del_char(ta);
	} else if(strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
		lv_event_send(ta, LV_EVENT_READY, NULL);
	} else if(strcmp(txt, LV_SYMBOL_HOME) == 0) {
		// lv_scr_load_anim(main_screen_create(main_screen), LV_SCR_LOAD_ANIM_OVER_LEFT, 0, 0, true);
	} else lv_textarea_add_text(ta, txt);
}

lv_obj_t * lock_screen_create(lv_obj_t * parent) {
	parent = lv_obj_create(NULL);
	lock_screen_ta = lv_textarea_create(parent);
	lv_obj_set_parent(lock_screen_ta,parent);
	lv_textarea_set_one_line(lock_screen_ta, true);
	lv_textarea_set_max_length(lock_screen_ta, 8);
	lv_obj_align(lock_screen_ta, LV_ALIGN_TOP_MID, 0, 10);
	lv_textarea_set_password_mode(lock_screen_ta, true);
	lv_obj_add_event_cb(lock_screen_ta, ta_event_cb, LV_EVENT_READY, lock_screen_ta);
	lv_obj_add_state(lock_screen_ta, LV_STATE_FOCUSED);

	btnm = lv_btnmatrix_create(parent);
	lv_obj_set_size(btnm, 200, 160);
	lv_obj_align(btnm, LV_ALIGN_BOTTOM_MID, 0, -20);
	lv_obj_add_event_cb(btnm, lock_screen_event_handler, LV_EVENT_VALUE_CHANGED, lock_screen_ta);
	lv_btnmatrix_set_map(btnm, btnm_map);

	return parent;
}
