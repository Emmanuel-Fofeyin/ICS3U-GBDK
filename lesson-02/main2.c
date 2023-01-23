// copyright (c) 2023 Emmanuel F.N All rights reserved
//
// Created by: Emmanuel Fofeyin
// Created on; Jan 2023
//This is the Gameboy version of (SA)

#include <gb/gb.h>
#include <stdio.h>

#include "MetaSprites.c"
#include "SpaceAliens.c"

void main () {
    set_sprite_data(0, 16, SpaceAliens);
    set_meta_sprite_tile(0, 1, 2, 3, 4);
    move_meta_sprite(0, 76, 120);

    SHOW_SPRITES;
    DISPLAY_ON;
}
