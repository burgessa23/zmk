#pragma once

#include <lvgl.h>
#include "util.h"

struct mods_status_state {
    uint8_t mods;
};
void draw_mods_status(lv_obj_t *canvas, const struct status_state *state);
