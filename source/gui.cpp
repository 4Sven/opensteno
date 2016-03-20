//
//  gui.cpp
//  OpenSteno
//
//  Created by Sven Jerat2 on 13.03.16.
//
//
/**
 *  @file gui.cpp
 *
 *  @brief GUI for my application
 */

#include "gui.hpp"
#include <iostream>
#include <QCloseEvent>

gui::gui(QMainWindow *parent) :
    QMainWindow(parent),
    eventThread(new SdlEventThread(this))
{
    setupUi(this);
    setStatusTip("Anwendung wurde gestartet!");
    
    connect(eventThread, SIGNAL(keyPressEvent(SDL_KeyboardEvent)), this, SLOT(keyPressed(SDL_KeyboardEvent)));
    
    eventThread->start();
}

gui::~gui() {
}

void gui::closeEvent(QCloseEvent *event) {
    eventThread->stop();
    eventThread->terminate();
    event->accept();
}

void gui::keyboardKeyPressed(SDL_KeyboardEvent event) {
    std::cout << "keyboardPressed" << std::endl;
}

void gui::keyPressed(SDL_KeyboardEvent event) {
    std::cout << "keyPressed" << std::endl;
}