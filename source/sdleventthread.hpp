//
//  sdleventthread.hpp
//  opensteno
//
//  Created by Sven Jerat2 on 19.03.16.
//
//

#ifndef sdleventthread_hpp
#define sdleventthread_hpp

#include <QThread>
#include <QMetaType>
#include <SDL_events.h>

Q_DECLARE_METATYPE(SDL_Event);
Q_DECLARE_METATYPE(SDL_KeyboardEvent);

class SdlEventThread : public QThread {
    Q_OBJECT
    
public:
    explicit SdlEventThread(QObject *parent=0);
    void stop();
    
signals:
    void keyPressEvent(SDL_KeyboardEvent event);
    void sdlEvent(SDL_Event event);
    
public slots:
    
protected:
    virtual void run();
};


#endif /* sdleventthread_hpp */
