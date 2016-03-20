//
//  definitions.hpp
//  OpenSteno
//
//  Created by Sven Jerat2 on 12.03.16.
//
//

#ifndef definitions_hpp
#define definitions_hpp

#include <map>
#include <QApplication>

/** @enum mapper::telegram
*   @brief This enum is helping to assign Qt::KeyS to steno keyboard keys.
*
*   Mapping from US / UK Layout like https://en.wikipedia.org/wiki/British_and_American_keyboards to http://depo.com/about/aboutreporting/stenobasics.html
*/
enum allowedStenoKeys {
    /** Initial on Upper Bank */
    KEY01 = Qt::Key_Q,
    KEY02 = Qt::Key_W,
    KEY03 = Qt::Key_E,
    KEY04 = Qt::Key_R,
    /** Asterisk Key Upper Bank */
    KEY05 = Qt::Key_T|Qt::Key_Y,
    /** Initial on Lower Bank */
    KEY06 = Qt::Key_A,
    KEY07 = Qt::Key_S,
    KEY08 = Qt::Key_D,
    KEY09 = Qt::Key_F,
    /** Asterisk Key Lower Bank */
    KEY10 = Qt::Key_G|Qt::Key_H,
    /** Final on Upper Bank */
    KEY11 = Qt::Key_U,
    KEY12 = Qt::Key_I,
    KEY13 = Qt::Key_O,
    KEY14 = Qt::Key_P,
    KEY15 = Qt::Key_BraceLeft,
    /** Final on Lower Bank */
    KEY16 = Qt::Key_J,
    KEY17 = Qt::Key_K,
    KEY18 = Qt::Key_L,
    KEY19 = Qt::Key_Semicolon,
    KEY20 = Qt::Key_Apostrophe,
    /** Vowel Keys */
    KEY21 = Qt::Key_C,
    KEY22 = Qt::Key_V,
    KEY23 = Qt::Key_N,
    KEY24 = Qt::Key_M
};

std::map<allowedStenoKeys, char> create_map_de();
std::map<allowedStenoKeys, char> create_map_en();

//std::map<allowedStenoKeys, char> convertKey = create_map_de();

#endif /* definitions_hpp */
