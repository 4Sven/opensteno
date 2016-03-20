//
//  sdleventthread.cpp
//  opensteno
//
//  Created by Sven Jerat2 on 19.03.16.
//
//

#include "sdleventthread.hpp"
#include <iostream>

SdlEventThread::SdlEventThread(QObject *parent) : QThread(parent) {
    
}

void SdlEventThread::run() {
    std::cout << "SDL Thread started!" << std::endl;
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return;
                break;
                
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                std::cout << "SDL KEY UP/DOWN Events registered" << std::endl;
                emit keyPressEvent(event.key);
                break;
                
            default:
                emit sdlEvent(event);
        }
    }
}

void SdlEventThread::stop() {
    std::cout << "SDL Thread stopped!" << std::endl;
    SDL_Event event;
    event.type = SDL_QUIT;
    SDL_PushEvent(&event);
}