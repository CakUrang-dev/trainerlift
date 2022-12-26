#ifndef ANIMATION_H
#define ANIMATION_H

#include <MaxMatrix.h>

class Animation
{
public:
    Animation(MaxMatrix &matrix_);
    void init();
    void open();
    void close();
    void up();
    void down();
    void floorOne();
    void floorTwo();
    void floorThree();
    void floorFour();

private:
    MaxMatrix &_matrix;
    uint16_t _shortDelay = 150;
    uint16_t _longDelay = 2000;
};

#endif