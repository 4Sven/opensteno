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

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    gui window;
    window.show();
    return app.exec();
}