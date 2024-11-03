#include <zephyr/kernel.h>
#include "mods.h"
#include "../assets/custom_fonts.h"

void draw_mods_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_rect_dsc_t rect_black_dsc;
    init_rect_dsc(&rect_black_dsc, LVGL_BACKGROUND);
    lv_draw_rect_dsc_t rect_white_dsc;
    init_rect_dsc(&rect_white_dsc, LVGL_FOREGROUND);
    lv_draw_label_dsc_t mod_dsc;
    init_label_dsc(&mod_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_CENTER);
    lv_draw_label_dsc_t mod_dsc_black;
    init_label_dsc(&mod_dsc_black, LVGL_BACKGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_CENTER);

    // Fill background
    /* lv_canvas_draw_rect(canvas, 0, 70, DISP_WIDTH, MODS_HEIGHT, &rect_black_dsc); */

    // Mod Labels
    char names[4][4] = {"CTL", "SFT", "ALT", "CMD"};

    // Drawing Mod Boxes
    int mod_offsets[4][2] = {{2, 70}, {35, 70}, {2, 90}, {35, 90}};
    /* lv_canvas_draw_rect(canvas, 0, 64, DISP_WIDTH, 42, &rect_white_dsc); */
    for (int i = 0; i < 4; i++) {
        bool selected = (state->mod_state >> i) & 0x11;
        lv_canvas_draw_rect(canvas, mod_offsets[i][0], mod_offsets[i][1], 31, 18, &rect_black_dsc);
        if (selected)
            lv_canvas_draw_rect(canvas, mod_offsets[i][0] + 2, mod_offsets[i][1] + 2, 27, 15,
                                &rect_white_dsc);
        lv_canvas_draw_text(canvas, mod_offsets[i][0], mod_offsets[i][1] + 4, 32,
                            (selected ? &mod_dsc_black : &mod_dsc), names[i]);
    }

}
