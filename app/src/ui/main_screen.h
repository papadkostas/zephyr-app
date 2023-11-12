#include <lvgl.h>

#define HEADER_HEIGHT 40
#define CONTAINER_HEIGHT 192

// LV_FONT_DECLARE(lv_font_montserrat_48_custom);

// LV_IMG_DECLARE(counter_ico_80);
// LV_IMG_DECLARE(sensor_ico_80);
// LV_IMG_DECLARE(settings_ico_80);
// LV_IMG_DECLARE(password_ico_48);
// LV_IMG_DECLARE(password_ico_80);
// LV_IMG_DECLARE(restart_ico_80);
// LV_IMG_DECLARE(about_ico_80);
// LV_IMG_DECLARE(entry_ico_80);

extern lv_obj_t * header;
extern lv_obj_t * chart;
extern lv_obj_t * cpu_label;
extern lv_obj_t * mem_label;
extern lv_obj_t * time_lbl;


extern lv_obj_t * sens_status;
extern lv_obj_t * distance_meas;
extern lv_obj_t * ppl_count;
extern lv_obj_t * ppl_counter_label;

extern lv_obj_t * starting_hour;
extern lv_obj_t * starting_minutes;
extern lv_obj_t * finishing_hour;
extern lv_obj_t * finishing_minutes;

extern lv_obj_t * main_menu_win;
extern lv_obj_t * couter_config_win;
extern lv_obj_t * sensor_menu_win;
extern lv_obj_t * lock_win;
extern lv_obj_t * counter_win;
extern lv_obj_t * password_change_win;

extern lv_obj_t * pwd_ta;
extern lv_obj_t * pwd_change_ta;

extern lv_style_t style_sel;

extern lv_obj_t * main_screen;
extern lv_obj_t * header_cont;

lv_obj_t *  main_screen_create(lv_obj_t * parent);
