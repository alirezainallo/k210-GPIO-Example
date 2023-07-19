#include <Arduino.h>
#include "gpiohs.h"
#include "gpio.h"
#include "utils.h"
#include "fpioa.h"
#include "sysctl.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  Serial.println("Starting...");

  //initialise GPIO
  gpio_init ();

  /**
   * @brief notice that I tell pin number from 
   * this doc: MaixDunio(Pin assignment table).xlsx
   * in -> https://dl.sipeed.com/shareURL/MAIX/HDK/Sipeed-Maixduino/Maixduino_2832
   * as K210 IO number.
   */
  //init pin 16 as input that connected to boot key in Maixduino board
  fpioa_set_function (16 , FUNC_GPIO3);
  gpio_set_drive_mode (3 , GPIO_DM_INPUT_PULL_UP );


  //init pin 14 as output that connected to blue light of it's RGB
  fpioa_set_function (14 , FUNC_GPIO4);
  gpio_set_drive_mode (4 , GPIO_DM_OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  if(gpio_get_pin(3) == GPIO_PV_LOW){
    gpio_set_pin(4, GPIO_PV_LOW);
  }
  else{
    gpio_set_pin(4, GPIO_PV_HIGH);
  }
}
