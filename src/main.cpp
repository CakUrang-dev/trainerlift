#include "animation.h"
#include "sound.h"
#include "motor.h"

int counter = 1;

byte DIN = 50;
byte CLK = 52;
byte CS = 53;
byte maxInUse = 1;

byte dir = 40;
byte step = 42;
byte mode = 1;

int stepsPerRevolution = 2048;

DFRobotDFPlayerMini player;
MaxMatrix matrix(DIN, CS, CLK, maxInUse);
AccelStepper stepper = AccelStepper(mode, step, dir);
Stepper stepper1 = Stepper(stepsPerRevolution, 38, 36, 34, 32);

Animation anim(matrix);
Sound sound(player);
Motor motor(stepper1, stepper);

void setup()
{
  sound.init();
  anim.init();
  pinMode(22, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  // motor.init();
  motor.bounceInit();
  // sound.soundCondition();
}

void loop()
{
  motor.check();
  // anim.up();
  // anim.down();
  // anim.floorOne();
  // sound.setSoundCondition(1);
  // sound.soundCondition();
  // anim.floorTwo();
  // sound.setSoundCondition(2);
  // sound.soundCondition();
  // anim.floorThree();
  // sound.setSoundCondition(3);
  // sound.soundCondition();
  // anim.floorFour();
  // sound.setSoundCondition(4);
  // sound.soundCondition();
  // anim.open();
  // anim.close();
  // motor.bounce();
  // sound.setSoundCondition(5);
  // sound.soundCondition();
  motor.bounce();
  if (motor.bounce())
  {
    switch (counter)
    {
    case 1:
      anim.up();
      anim.down();
      anim.floorOne();
      sound.setSoundCondition(1);
      sound.soundCondition();
      counter += 1;
      break;
    case 2:
      anim.up();
      anim.down();
      anim.floorTwo();
      sound.setSoundCondition(2);
      sound.soundCondition();
      counter += 1;
      break;
    case 3:
      anim.up();
      anim.down();
      anim.floorThree();
      sound.setSoundCondition(3);
      sound.soundCondition();
      counter += 1;
      break;
    case 4:
      anim.up();
      anim.down();
      anim.floorFour();
      sound.setSoundCondition(4);
      sound.soundCondition();
      if (counter == 4)
      {
        counter = 1;
      }
      break;
    }
  }
  // if (digitalRead(22) == LOW)
  // {
  //   Serial.println("Floor 1");
  //   sound.setSoundCondition(1);
  //   sound.soundCondition();
  //   anim.floorOne();
  // }
  // else if (digitalRead(24) == LOW)
  // {
  //   Serial.println("Floor 2");
  //   sound.setSoundCondition(2);
  //   sound.soundCondition();
  //   anim.floorTwo();
  // }
  // else if (digitalRead(26) == LOW)
  // {
  //   Serial.println("Floor 3");
  //   sound.setSoundCondition(3);
  //   sound.soundCondition();
  //   anim.floorThree();
  // }
  // else if (digitalRead(28) == LOW)
  // {
  //   Serial.println("Floor 3");
  //   sound.setSoundCondition(4);
  //   sound.soundCondition();
  //   anim.floorFour();
  // }

  // if (digitalRead(4) == LOW)
  // {
  //   if (counter != 5)
  //   {
  //     Serial.println("Up");
  //     motor.up();
  //     counter += 1;
  //     motor.setCounter(counter);
  //   }
  // }
  // else if (digitalRead(5) == HIGH)
  // {
  //   if (counter != 0)
  //   {
  //     motor.down();
  //     counter -= 1;
  //     motor.setCounter(counter);
  //   }
  // }

  sound.check();
}