#ifndef SOUND_H
#define SOUND_H

#include "DFRobotDFPlayerMini.h"

class Sound
{
public:
    Sound(DFRobotDFPlayerMini &player_);

    void printDetail(uint8_t type, int value);
    void init();
    void check();
    void defaultSound();
    void soundCondition();
    void setSoundCondition(int soundCondition_);

private:
    DFRobotDFPlayerMini &_player;
    int _soundCondition = 5;
    bool _defaultSound = true;
};

#endif