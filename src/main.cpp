#include <Arduino.h>
#include "menu/MenuLevel.h"


MenuLevel* level1 = new MenuLevel();
MenuLevel level2;


void setup() {
  level1->addMenuItem("First", &level2);
  // level1.addMenuItem("First", nullptr);
  // level1.addMenuItem("First", nullptr);
  // level1.addMenuItem("First", nullptr);
  Serial.print("size = ");
  Serial.println(level1->getSize());

}

void loop() {



}