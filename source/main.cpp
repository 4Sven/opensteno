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
 * \bug I'm using brew on my Mac and always I upgrade/update brew I have to 
    run <b><tt> brew link gettext --force</tt></b>
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
    QMainWindow window;
    window.show();
    return app.exec();
}