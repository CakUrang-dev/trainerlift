#include "sound.h"

Sound::Sound(DFRobotDFPlayerMini &player_)
    : _player(player_)
{
}

void Sound::init()
{
    Serial.begin(115200);
    Serial1.begin(9600);

    Serial.println();
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

    if (!_player.begin(Serial1))
    { // Use softwareSerial to communicate with mp3.
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while (true)
        {
            delay(0); // Code to compatible with ESP8266 watch dog.
        }
    }
    Serial.println(F("DFPlayer Mini online."));
    _player.volume(20);
    _player.play(1);
    _player.enableLoop();
}

void Sound::check()
{
    if (_player.available())
    {
        printDetail(_player.readType(), _player.read());
    }
}

void Sound::printDetail(uint8_t type, int value)
{
    switch (type)
    {
    case TimeOut:
        Serial.println(F("Time Out!"));
        break;
    case WrongStack:
        Serial.println(F("Stack Wrong!"));
        break;
    case DFPlayerCardInserted:
        Serial.println(F("Card Inserted!"));
        break;
    case DFPlayerCardRemoved:
        Serial.println(F("Card Removed!"));
        break;
    case DFPlayerCardOnline:
        Serial.println(F("Card Online!"));
        break;
    case DFPlayerUSBInserted:
        Serial.println("USB Inserted!");
        break;
    case DFPlayerUSBRemoved:
        Serial.println("USB Removed!");
        break;
    case DFPlayerPlayFinished:
        Serial.print(F("Number:"));
        Serial.print(value);
        Serial.println(F(" Play Finished!"));
        break;
    case DFPlayerError:
        Serial.print(F("DFPlayerError:"));
        switch (value)
        {
        case Busy:
            Serial.println(F("Card not found"));
            break;
        case Sleeping:
            Serial.println(F("Sleeping"));
            break;
        case SerialWrongStack:
            Serial.println(F("Get Wrong Stack"));
            break;
        case CheckSumNotMatch:
            Serial.println(F("Check Sum Not Match"));
            break;
        case FileIndexOut:
            Serial.println(F("File Index Out of Bound"));
            break;
        case FileMismatch:
            Serial.println(F("Cannot Find File"));
            break;
        case Advertise:
            Serial.println(F("In Advertise"));
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Sound::setSoundCondition(int soundCondition_)
{
    _soundCondition = soundCondition_;
}

void Sound::defaultSound()
{
    if (_defaultSound)
    {
        soundCondition();
    }
}

void Sound::soundCondition()
{
    switch (_soundCondition)
    {
    case 1:
        _player.play(3);
        _defaultSound = false;
        delay(2000);
        _soundCondition = 5;
        _defaultSound = true;
        defaultSound();
        break;
    case 2:
        _player.play(4);
        _defaultSound = false;
        delay(2000);
        _soundCondition = 5;
        _defaultSound = true;
        defaultSound();
        break;
    case 3:
        _player.play(5);
        _defaultSound = false;
        delay(2000);
        _soundCondition = 5;
        _defaultSound = true;
        defaultSound();
        break;
    case 4:
        _player.play(6);
        _defaultSound = false;
        delay(2000);
        _soundCondition = 5;
        _defaultSound = true;
        defaultSound();
        break;
    case 5:
        _player.play(1);
        _player.play(2);
        break;
    }
}