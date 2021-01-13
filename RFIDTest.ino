#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>


bool ModuleState=false;
unsigned long timeCount;

#define SS_PIN  10
#define RST_PIN 9

#define blueLed    16
#define redLed      17
#define greenLed     18 
#define buzzer     8

String UID;
 
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() 
  {
    Serial.begin(9600);
    SPI.begin();
    mfrc522.PCD_Init();
    mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);
    LedSequency();
  }

void loop() 
  {
    if ( ! mfrc522.PICC_IsNewCardPresent())
    {
      return;
    }
    if ( ! mfrc522.PICC_ReadCardSerial())
    {
      return;
    }
    CardFound();
     if (( UID == "07 0B 12 3C" ) ||( UID == "27 5B C9 3B" )|| ( UID == "39 6C B3 74" )|| ( UID == "69 D7 6E 2C" )|| ( UID == "79 5E E6 2B" )||( UID == "89 46 35 2C" ))

   {
  digitalWrite(greenLed, HIGH);
  delay(500);
  digitalWrite(buzzer, HIGH);
  delay(165);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(165);
  digitalWrite(greenLed, LOW);
  digitalWrite(buzzer, LOW);
  delay(500);
  
  }
  else{
  digitalWrite(redLed, HIGH);
  delay(500);
  digitalWrite(buzzer, HIGH);
  delay(350);
  digitalWrite(redLed, LOW);
  digitalWrite(buzzer, LOW);
  }
  }

// custom functions

String CardFound()
  {
//    digitalWrite(blueLed, HIGH);    
//    Serial.print("UID tag: ");
    String content = "";
    byte letter;
    for (byte i = 0; i <mfrc522.uid.size; i++)
      {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
//     Serial.println();
     content.toUpperCase();
     UID = content.substring(1);
//     Serial.println(UID);   
     return (UID);
  }

String Authenticate()
{
  
}

String LedSequency()
{
      pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);
    pinMode(buzzer, OUTPUT);

  digitalWrite(blueLed, HIGH);
  delay(1000);
  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(1000);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
  delay(1000);  
  digitalWrite(redLed, LOW);

  digitalWrite(buzzer, HIGH);
  digitalWrite(blueLed, HIGH);
  delay(250);
  digitalWrite(greenLed, HIGH);
  delay(250);
  digitalWrite(redLed, HIGH);

  digitalWrite(blueLed, LOW);
  delay(250);
  digitalWrite(greenLed, LOW);
  delay(250);
  digitalWrite(redLed, LOW);
  digitalWrite(buzzer, LOW);
  
 
}


  
