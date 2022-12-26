#include "animation.h"

byte naik[] = {8, 8, 0x00, 0x20, 0x10, 0x08, 0x08, 0x10, 0x20, 0x00};
byte turun[] = {8, 8, 0x00, 0x04, 0x08, 0x10, 0x10, 0x08, 0x04, 0x00};
byte Lantai1[] = {8, 8, 0x00, 0x00, 0x00, 0x44, 0x7e, 0x40, 0x00, 0x00};
byte Lantai2[] = {8, 8, 0x00, 0x00, 0x44, 0x62, 0x52, 0x4c, 0x00, 0x00};
byte Lantai3[] = {8, 8, 0x00, 0x00, 0x24, 0x42, 0x4a, 0x34, 0x00, 0x00};
byte Lantai4[] = {8, 8, 0x00, 0x00, 0x18, 0x14, 0x12, 0x7e, 0x00, 0x00};

byte anim_buka1[] = {8, 8, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00};
byte anim_buka2[] = {8, 8, 0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00};
byte anim_buka3[] = {8, 8, 0x00, 0x18, 0x24, 0x42, 0x42, 0x24, 0x18, 0x00};
byte anim_buka4[] = {8, 8, 0x18, 0x24, 0x42, 0x00, 0x00, 0x42, 0x24, 0x18};
byte anim_buka5[] = {8, 8, 0x24, 0x42, 0x00, 0x00, 0x00, 0x00, 0x42, 0x24};
byte anim_buka6[] = {8, 8, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42};
byte anim_buka7[] = {8, 8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

byte anim_tutup1[] = {8, 8, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18};
byte anim_tutup2[] = {8, 8, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24};
byte anim_tutup3[] = {8, 8, 0x42, 0x24, 0x18, 0x00, 0x00, 0x18, 0x24, 0x42};
byte anim_tutup4[] = {8, 8, 0x00, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x00};
byte anim_tutup5[] = {8, 8, 0x00, 0x00, 0x42, 0x24, 0x24, 0x42, 0x00, 0x00};
byte anim_tutup6[] = {8, 8, 0x00, 0x00, 0x00, 0x42, 0x42, 0x00, 0x00, 0x00};
byte anim_tutup7[] = {8, 8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

Animation::Animation(MaxMatrix &matrix_)
    : _matrix(matrix_)
{
}

void Animation::init()
{
    _matrix.init();
    _matrix.setIntensity(2);
}

void Animation::open()
{
    _matrix.writeSprite(0, 0, anim_buka1);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_buka2);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_buka3);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_buka4);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_buka5);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_buka6);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_buka7);
    delay(_shortDelay);
}

void Animation::close()
{

    _matrix.writeSprite(0, 0, anim_tutup1);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_tutup2);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_tutup3);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_tutup4);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_tutup5);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_tutup6);
    delay(_shortDelay);
    _matrix.writeSprite(0, 0, anim_tutup7);
    delay(_shortDelay);
}

void Animation::up()
{
    _matrix.writeSprite(0, 0, naik);
    delay(300);
    for (int i = 0; i < 8; i++)
    {
        _matrix.shiftUp(true);
        delay(_shortDelay);
    }
    _matrix.clear();
}

void Animation::down()
{
    _matrix.writeSprite(0, 0, turun);
    delay(_shortDelay);
    for (int i = 0; i < 8; i++)
    {
        _matrix.shiftDown(true);
        delay(_shortDelay);
    }
    _matrix.clear();
}

void Animation::floorOne()
{
    _matrix.writeSprite(0, 0, Lantai1);
    delay(_longDelay);
    _matrix.clear();
}

void Animation::floorTwo()
{
    _matrix.writeSprite(0, 0, Lantai2);
    delay(_longDelay);
    _matrix.clear();
}

void Animation::floorThree()
{
    _matrix.writeSprite(0, 0, Lantai3);
    delay(_longDelay);
    _matrix.clear();
}

void Animation::floorFour()
{
    _matrix.writeSprite(0, 0, Lantai4);
    delay(_longDelay);
    _matrix.clear();
}