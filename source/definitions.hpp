//
//  definitions.hpp
//  OpenSteno
//
//  Created by Sven Jerat2 on 12.03.16.
//
//

#ifndef definitions_hpp
#define definitions_hpp

#include <stdio.h>
#include "SDL.h"

/** @enum mapper::telegram
*   @brief This enum is helping to assign SDL_SCANCODES to steno keyboard keys.
*
*   Mapping from US / UK Layout like https://en.wikipedia.org/wiki/British_and_American_keyboards to http://depo.com/about/aboutreporting/stenobasics.html
*/
enum telegram {
    /** Initial on Upper Bank */
    KEY01 = SDL_SCANCODE_Q, 
    KEY02 = SDL_SCANCODE_W,
    KEY03 = SDL_SCANCODE_E,
    KEY04 = SDL_SCANCODE_R,
    /** Asterisk Key Upper Bank */
    KEY05 = SDL_SCANCODE_T|SDL_SCANCODE_Y,
    /** Initial on Lower Bank */
    KEY06 = SDL_SCANCODE_A,
    KEY07 = SDL_SCANCODE_S,
    KEY08 = SDL_SCANCODE_D,
    KEY09 = SDL_SCANCODE_F,
    /** Asterisk Key Lower Bank */
    KEY10 = SDL_SCANCODE_G|SDL_SCANCODE_H,
    /** Final on Upper Bank */
    KEY11 = SDL_SCANCODE_U,
    KEY12 = SDL_SCANCODE_I,
    KEY13 = SDL_SCANCODE_O,
    KEY14 = SDL_SCANCODE_P,
    KEY15 = SDL_SCANCODE_LEFTBRACKET,
    /** Final on Lower Bank */
    KEY16 = SDL_SCANCODE_J,
    KEY17 = SDL_SCANCODE_K,
    KEY18 = SDL_SCANCODE_L,
    KEY19 = SDL_SCANCODE_SEMICOLON,
    KEY20 = SDL_SCANCODE_APOSTROPHE,
    /** Vowel Keys */
    KEY21 = SDL_SCANCODE_C,
    KEY22 = SDL_SCANCODE_V,
    KEY23 = SDL_SCANCODE_N,
    KEY24 = SDL_SCANCODE_M
};

#endif /* definitions_hpp */
