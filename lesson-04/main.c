// copyright (c) 2023 Emmanuel F.N All rights reserved
//
// Created by: Emmanuel Fofeyin
// Created on; Jan 2023
//This is the Gameboy version of (SA)

#include <gb/gb.h>
#include <stdio.h>

#include "MetaSprites.c"
#include "SpaceAliens.c"
#include "Background.c"

void main () {
    uint8_t joypadData;

    set_sprite_data(0, 16, SpaceAliens);
    set_meta_sprite_tile(0, 1, 2, 3, 4);
    move_meta_sprite(0, 76, 144);

    set_bkg_data(0, 16, SpaceAliens);
    set_bkg_tiles(0, 0, 20, 36, Background);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    // game loop
    while (1) {
        joypadData = joypad();

        if (joypadData & J_LEFT) {
            scroll_meta_sprite(0, -1, 0);
        }
        if (joypadData & J_RIGHT) {
            scroll_meta_sprite(0, 1, 0);
        }
        if (joypadData & J_UP) {
            scroll_meta_sprite(0, 0, -1);
        }
        if (joypadData & J_DOWN) {
            scroll_meta_sprite(0, 0, 1);
        }
        scroll_bkg(0, -1);

        wait_vbl_done();
    }
}