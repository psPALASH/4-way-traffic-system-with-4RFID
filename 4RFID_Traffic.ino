#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN1 53
#define RST_PIN1 45
MFRC522 mfrc5221(53, 49 );   // Create MFRC522 instance.

/* SDA Digital 53
SCK Digital 52
MOSI  Digital 51
MISO  Digital 50
IRQ unconnected
GND GND
RST Digital 49
3.3V  3.3V
*/


#define SS_PIN2 48
MFRC522 mfrc5222(48, 49);   // Create MFRC522 instance.

#define SS_PIN3 47
MFRC522 mfrc5223(47,49);   // Create MFRC522 instance.

#define SS_PIN4 46
MFRC522 mfrc5224(46, 49);   // Create MFRC522 instance.


const int greenpin1 = 20;
const int yellowpin1 = 21;
const int redpin1 =22;
const int greenpin2 = 23;
const int yellowpin2 = 24;
const int redpin2 = 25;
const int greenpin3 = 26;
const int yellowpin3 = 27;
const int redpin3 = 28;
const int greenpin4 = 29;
const int yellowpin4 = 30;
const int redpin4 =31;

void setup() {
 // put your setup code here, to run once:

  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc5221.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

  
    pinMode(greenpin1,OUTPUT);
  pinMode(yellowpin1,OUTPUT);
  pinMode(redpin1,OUTPUT);
  pinMode(greenpin2,OUTPUT);
  pinMode(yellowpin2,OUTPUT);
  pinMode(redpin2,OUTPUT);
  pinMode(greenpin3,OUTPUT);
  pinMode(yellowpin3,OUTPUT);
  pinMode(redpin3,OUTPUT);
  pinMode(greenpin4,OUTPUT);
  pinMode(yellowpin4,OUTPUT);
  pinMode(redpin4,OUTPUT);

  digitalWrite(redpin1,LOW);
  delay(100);
  digitalWrite(redpin2,LOW);
  delay(100);
  digitalWrite(redpin3,LOW);
  delay(100);
  digitalWrite(redpin4,LOW);
  delay(100);
  digitalWrite(yellowpin1,LOW);
  delay(100);
  digitalWrite(yellowpin2,LOW);
  delay(100);
  digitalWrite(yellowpin3,LOW);
  delay(100);
  digitalWrite(yellowpin4,LOW);
  delay(100);
  digitalWrite(greenpin1,LOW);
  delay(100);
  digitalWrite(greenpin2,LOW);
  delay(100);
  digitalWrite(greenpin3,LOW);
  delay(100);
  digitalWrite(greenpin4,LOW);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
lane1();
rfid1();
rfid3();
rfid4();
lane2();
rfid1();
rfid2();
rfid4();
lane3();
rfid1();
rfid2();
rfid3();
lane4();
rfid2();
rfid3();
rfid4();
}

void lane1()
{
  digitalWrite(redpin1, LOW);
  digitalWrite(greenpin1,HIGH);
  delay(5000);
  digitalWrite(greenpin1,LOW);
  digitalWrite(yellowpin1, HIGH);
  delay(1000);
  digitalWrite(yellowpin1, LOW);
  digitalWrite(redpin1, HIGH);
}

void lane2()
{
  digitalWrite(redpin2, LOW);
  digitalWrite(greenpin2,HIGH);
  delay(5000);
  digitalWrite(greenpin2,LOW);
  digitalWrite(yellowpin2, HIGH);
  delay(1000);
  digitalWrite(yellowpin2, LOW);
  digitalWrite(redpin2, HIGH);
}

void lane3()
{
  digitalWrite(redpin3, LOW);
  digitalWrite(greenpin3,HIGH);
  delay(5000);
  digitalWrite(greenpin3,LOW);
  digitalWrite(yellowpin3, HIGH);
  delay(1000);
  digitalWrite(yellowpin3, LOW);
  digitalWrite(redpin3, HIGH);
}

void lane4()
{
  digitalWrite(redpin4, LOW);
  digitalWrite(greenpin4,HIGH);
  delay(5000);
  digitalWrite(greenpin4,LOW);
  digitalWrite(yellowpin4, HIGH);
  delay(1000);
  digitalWrite(yellowpin4, LOW);
  digitalWrite(redpin4, HIGH);
}


void rfid1()
{
  // Look for new cards
  if ( ! mfrc5221.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc5221.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor first time to read Tag
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc5221.uid.size; i++) 
  {
     Serial.print(mfrc5221.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc5221.uid.uidByte[i], HEX);
     content.concat(String(mfrc5221.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc5221.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == "67 D9 24 2D") //change here the UID of the card/cards that you want to give access
  {
    lane1();
  }
}

void rfid2()
{
  // Look for new cards
  if ( ! mfrc5222.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc5222.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor first time to read Tag
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc5222.uid.size; i++) 
  {
     Serial.print(mfrc5222.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc5222.uid.uidByte[i], HEX);
     content.concat(String(mfrc5222.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc5222.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == "67 D9 24 2D") //change here the UID of the card/cards that you want to give access
  {
    lane2();
  }
}

void rfid3()
{
  // Look for new cards
  if ( ! mfrc5223.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc5223.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor first time to read Tag
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc5223.uid.size; i++) 
  {
     Serial.print(mfrc5223.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc5223.uid.uidByte[i], HEX);
     content.concat(String(mfrc5223.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc5223.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == "67 D9 24 2D") //change here the UID of the card/cards that you want to give access
  {
    lane3();
  }
}

void rfid4()
{
  // Look for new cards
  if ( ! mfrc5224.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc5224.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor first time to read Tag
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc5224.uid.size; i++) 
  {
     Serial.print(mfrc5224.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc5224.uid.uidByte[i], HEX);
     content.concat(String(mfrc5224.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc5224.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == "67 D9 24 2D") //change here the UID of the card/cards that you want to give access
  {
    lane4();
  }
}
