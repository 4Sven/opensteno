//
//  gui.hpp
//  OpenSteno
//
//  Created by Sven Jerat2 on 13.03.16.
//
//

#ifndef gui_hpp
#define gui_hpp

#include "ui_opensteno.h"

class OpenSteno : public QMainWindow, public Ui::OpenStenoMainWindow {
    Q_OBJECT
public:
    OpenSteno (QMainWindow *parent = 0);
    ~OpenSteno();
};

#endif /* gui_hpp */
