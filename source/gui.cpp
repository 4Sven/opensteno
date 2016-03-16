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
#include <QLabel>

gui::gui(void) {
    QLabel* label = new QLabel("Success!");
    setCentralWidget(label);
}