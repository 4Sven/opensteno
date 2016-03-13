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

int startGUI(int argc, char *argv[]) {
    GtkWidget *window;
    
    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(window);
    
    gtk_main();
    
    return 0;
}