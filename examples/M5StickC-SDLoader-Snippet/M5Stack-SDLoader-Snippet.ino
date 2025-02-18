/*
 * 
 * M5StickC SD Loader Snippet
 * Project Page: https://github.com/matsumo/M5StickC-SD-Updater
 *
 * Fork From   : https://github.com/tobozo/M5Stack-SD-Updater
 * 
 * Copyright 2018 tobozo http://github.com/tobozo
 *
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files ("M5Stack SD Updater"), to deal in the Software without 
 * restriction, including without limitation the rights to use, 
 * copy, modify, merge, publish, distribute, sublicense, and/or 
 * sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following 
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR 
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * 
 * To be used with M5StickC SD Menu https://github.com/matsumo/M5StickC-SD-Updater
 * This sketch is useless without a precompiled "menu.bin" saved on the SD Card.
 * You may compile menu.bin from the M5StickC-SD-Menu sketch.
 * 
 * Just use this sketch as your boilerplate and code your app over it, then 
 * compile it and put the binary on the sdcard. See M5StickC-SD-Menu for more 
 * info on the acceptable file formats.
 * 
 * When this app is in memory, booting the M5StickC with the Button Reset pushed will 
 * flash back the menu.bin into memory.
 * 
 */

#include <M5StickC.h>
#include <M5StickcUpdater.h>
#include <SPIFFS.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Welcome to the SD-Update example!");
  Serial.print("M5StickC initializing...");
  M5.begin();
  Wire.begin();
  SPIFFS.begin();
  pinMode(M5_BUTTON_RST, INPUT);
  if(digitalRead(M5_BUTTON_RST) == 0) {
    Serial.println("Will Load menu binary");
    updateFromFS(SPIFFS);
    ESP.restart();
  }

}

void loop() {
    
}
