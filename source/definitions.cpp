//
//  definitions.cpp
//  OpenSteno
//
//  Created by Sven Jerat2 on 12.03.16.
//
//
/**
 *  @file definitions.cpp
 *
 *  @brief Configurations for languages and translations
 */
#include "definitions.hpp"

/**
 * create_map_de
 *
 * Support for German Language
 * @return Mappingtable for Germany
 */
std::map<allowedStenoKeys, char> create_map_de() {
    std::map<allowedStenoKeys, char> m;
    m[KEY01] = 'S';
    m[KEY02] = 'B';
    m[KEY03] = 'G';
    m[KEY04] = 'R';
    m[KEY05] = '*';
    m[KEY06] = 'S';
    m[KEY07] = 'T';
    m[KEY08] = 'D';
    m[KEY09] = 'L';
    m[KEY10] = '*';
    m[KEY11] = 'R';
    m[KEY12] = 'M';
    m[KEY13] = 'G';
    m[KEY14] = 'S';
    m[KEY15] = 'N';
    m[KEY16] = 'L';
    m[KEY17] = 'B';
    m[KEY18] = 'D';
    m[KEY19] = 'L';
    m[KEY20] = 'L';
    m[KEY21] = 'A';
    m[KEY22] = 'U';
    m[KEY23] = 'O';
    m[KEY24] = 'I';
    return m;
}

/**
 * create_map_en
 *
 * Support for English Language
 * @return Mappingtable for UK
 */
std::map<allowedStenoKeys, char> create_map_en() {
    std::map<allowedStenoKeys, char> m;
    m[KEY01] = 'S';
    m[KEY02] = 'T';
    m[KEY03] = 'P';
    m[KEY04] = 'H';
    m[KEY05] = '*';
    m[KEY06] = 'S';
    m[KEY07] = 'K';
    m[KEY08] = 'W';
    m[KEY09] = 'R';
    m[KEY10] = '*';
    m[KEY11] = 'F';
    m[KEY12] = 'P';
    m[KEY13] = 'L';
    m[KEY14] = 'T';
    m[KEY15] = 'D';
    m[KEY16] = 'R';
    m[KEY17] = 'B';
    m[KEY18] = 'G';
    m[KEY19] = 'S';
    m[KEY20] = 'Z';
    m[KEY21] = 'A';
    m[KEY22] = 'O';
    m[KEY23] = 'E';
    m[KEY24] = 'U';
    return m;
}
