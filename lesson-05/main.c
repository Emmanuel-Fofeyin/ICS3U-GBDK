// copyright (c) 2023 Emmanuel F.N All rights reserved
//
// Created by: Emmanuel Fofeyin
// Created on; Jan 2023
//This is the Gameboy version of (SA)

#include <gb/gb.h>
#include <stdio.h>

#include "GBDK_Constants.h"
#include "MetaSprites.c"
#include "SpaceAliens.c"
#include "Background.c"

void main () {
    const int FIXED_Y_POSITION_OF_SHIP = 144;
    int shipXPosition = 76;
    int shipYPosition = FIXED_Y_POSITION_OF_SHIP;

    set_sprite_data(0, 16, SpaceAliens);
    set_meta_sprite_tile(0, 1, 2, 3, 4);
    move_meta_sprite(0, shipXPosition, shipYPosition);

    set_bkg_data(0, 16, SpaceAliens);
    set_bkg_tiles(0, 0, 20, 36, Background);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    // game loop
    while (1) {
        switch (joypad()) {
            case J_LEFT:
                scroll_meta_sprite(0, -1, 0);
                shipXPosition -= 1;
                if (shipXPosition < 8) {
                    shipXPosition = 8;
                    move_meta_sprite(0, 8, FIXED_Y_POSITION_OF_SHIP);
                }
                break;
            case J_RIGHT:
                scroll_meta_sprite(0, 1, 0);
                shipXPosition += 1;
                if (shipXPosition > SCREEN_WIDTH - 8) {
                    shipXPosition = SCREEN_WIDTH - 8;
                    move_meta_sprite(0, (uint8_t)(SCREEN_WIDTH - 8), FIXED_Y_POSITION_OF_SHIP);
                }
                break;
            default:
                break;
        }
        scroll_bkg(0, -1);

        wait_vbl_done();
    }
}
