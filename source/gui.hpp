//
//  gui.hpp
//  OpenSteno
//
//  Created by Sven Jerat2 on 13.03.16.
//
//

#ifndef gui_hpp
#define gui_hpp

#include "sdleventthread.hpp"
#include <QMainWindow>
#include "ui_opensteno.h"

class gui : public QMainWindow, public Ui::OpenStenoMainWindow {
    Q_OBJECT
    
public:
    gui(QMainWindow *parent = 0);
    ~gui();
    
public slots:

private slots:
    void keyboardKeyPressed(SDL_KeyboardEvent event);
    void keyPressed(SDL_KeyboardEvent event);

protected:
    virtual void closeEvent(QCloseEvent *event);
    
private:
    SdlEventThread *eventThread;
};

#endif /* gui_hpp */
