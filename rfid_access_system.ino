#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// Pin Definitions
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID reader instance

// LEDs and Buzzer
int redLED = 7;
int greenLED = 6;
int buzzer = 8;

// Servo for lock
Servo lockServo;
int lockPos = 15;   // Locked
int unlockPos = 75; // Unlocked

// Allowed RFID card UID (replace with your card UID)
String allowedUID = "27F1E600";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init(); // Initialize RFID

  // Pin setup
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Servo
  lockServo.attach(3);
  lockServo.write(lockPos); // Start locked

  // Startup message
  Serial.println("RFID Access Control System Ready...");
  Serial.println("Tap your card");
}

void loop() {
  // Check for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // Read UID
  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  Serial.print("Card UID: ");
  Serial.println(uid);

  // Check access
  if (uid == allowedUID) {
    accessGranted();
  } else {
    accessDenied();
  }

  mfrc522.PICC_HaltA(); // Stop reading
}

// Access granted sequence
void accessGranted() {
  Serial.println("ACCESS GRANTED");

  digitalWrite(greenLED, HIGH);
  tone(buzzer, 1500, 200); // short beep
  delay(200);
  digitalWrite(greenLED, LOW);

  lockServo.write(unlockPos); // Unlock
  delay(1000);
  lockServo.write(lockPos);   // Lock again
}

// Access denied sequence
void accessDenied() {
  Serial.println("ACCESS DENIED");

  for (int i = 0; i < 6; i++) {
    digitalWrite(redLED, HIGH);
    tone(buzzer, 400, 150); // low beep
    delay(150);
    digitalWrite(redLED, LOW);
    delay(100);
  }
}
