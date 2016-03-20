//
//  main.cpp
//  OpenSteno
//
//  Created by Sven Jerat on 12.03.16.
//
//
/**
 * @mainpage OpenSteno Software
 *
 * \author Sven Jerat
 * 
 */

/**
 * @file main.cpp
 *
 * @brief Main application file.
 *
 */

#include "gui.hpp"
#include <QApplication>
#include "SDL.h"
#include <iostream>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
    qRegisterMetaType<SDL_Event>("SDL_Event");
    qRegisterMetaType<SDL_KeyboardEvent>("SDL_KeyboardEvent");
    
    int initSDL = SDL_Init(SDL_INIT_EVENTS);
    if (initSDL) {
        const char *err = SDL_GetError();
        std::cout << "Fehler: " << err << std::endl;
        return initSDL;
    } else {
        std::cout << "SDL initialisiert" << std::endl;
    }
    
    gui window;
    window.show();
    return app.exec();
}