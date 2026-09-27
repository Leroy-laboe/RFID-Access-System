# Arduino RFID Access Control System

**An embedded access-control prototype using Arduino UNO, an MFRC522 RFID reader, servo-actuated locking, visual indicators, and buzzer feedback.**

Built to demonstrate **SPI-based RFID communication, UID validation, actuator control, and simple embedded access logic**.

---

## Overview

The system reads an RFID card or tag using the **MFRC522** module and compares its UID against an authorised UID stored in the Arduino firmware.

Depending on the result:

- an authorised card triggers the **green LED**, a short confirmation tone, and the servo unlock sequence;
- an unauthorised card triggers the **red LED** and repeated warning tones.

After a successful unlock, the servo automatically returns to the locked position.

---

## System Flow

```text
RFID card / tag
      │
      ▼
MFRC522 reader
      │  SPI
      ▼
Arduino UNO
      │
      ▼
Read card UID
      │
      ▼
Compare with authorised UID
      │
   ┌──┴───────────────┐
   ▼                  ▼
Match              No match
   │                  │
   ▼                  ▼
Green LED          Red LED
Short tone         Warning tones
Servo unlock
   │
   ▼
1 second delay
   │
   ▼
Servo returns to locked position
```

---

## Hardware

| Component | Role |
| --- | --- |
| Arduino UNO | Main controller |
| MFRC522 / RC522 RFID reader | Reads RFID card UID |
| Servo motor | Simulates lock / unlock mechanism |
| Green LED | Access-granted indicator |
| Red LED | Access-denied indicator |
| Buzzer | Audible status feedback |
| Breadboard / jumper wires | Prototype connections |

---

## Pin Mapping

### MFRC522 → Arduino UNO

| MFRC522 Pin | Arduino UNO |
| --- | ---: |
| SDA / SS | 10 |
| SCK | 13 |
| MOSI | 11 |
| MISO | 12 |
| RST | 9 |
| 3.3V | 3.3V |
| GND | GND |

### Outputs

| Component | Arduino Pin |
| --- | ---: |
| Servo signal | 3 |
| Green LED | 6 |
| Red LED | 7 |
| Buzzer | 8 |

> The MFRC522 operates at **3.3 V**. It should not be powered from the Arduino 5 V pin.

---

## Firmware Logic

The main loop:

1. waits for a new RFID card;
2. reads the card serial number;
3. converts the UID to uppercase hexadecimal text;
4. compares it with the configured authorised UID;
5. executes either the access-granted or access-denied sequence;
6. halts the current card session and waits for the next scan.

### Access granted

```text
Green LED ON
      ↓
Short confirmation beep
      ↓
Servo moves to unlock position
      ↓
Wait 1 second
      ↓
Servo returns to lock position
```

### Access denied

The red LED flashes while the buzzer produces repeated low-frequency warning tones.

---

## Servo Positions

The firmware currently uses:

```cpp
lockPos = 15;
unlockPos = 75;
```

These values can be adjusted to match the physical orientation of the servo and lock mechanism.

---

## Configure an Authorised Card

The authorised RFID UID is configured in:

```cpp
String allowedUID = "27F1E600";
```

To use a different card:

1. upload the sketch;
2. open the Serial Monitor at **9600 baud**;
3. scan the card;
4. copy the printed UID;
5. replace the configured `allowedUID`;
6. upload the firmware again.

---

## Required Arduino Libraries

The sketch uses:

- `SPI` — included with Arduino;
- `MFRC522`;
- `Servo`.

---

## Run the Project

1. Connect the MFRC522, LEDs, buzzer, and servo according to the pin mapping.
2. Install the `MFRC522` library from the Arduino Library Manager.
3. Open `rfid_access_system.ino`.
4. Select the correct Arduino UNO board and port.
5. Upload the sketch.
6. Open Serial Monitor at **9600 baud**.
7. Scan an RFID card or tag.

---

## Repository Structure

```text
.
├── rfid_access_system.ino
├── .gitignore
└── README.md
```

---

## What This Project Demonstrates

- Arduino embedded programming;
- SPI communication;
- MFRC522 RFID integration;
- UID parsing and comparison;
- servo actuator control;
- LED and buzzer feedback;
- simple state-based access logic;
- hardware prototyping.

---

## Security Scope

This is an **educational access-control prototype**, not a production security system.

The current design authorises users using only the RFID card UID. Many low-cost RFID cards expose identifiers that can be read or cloned, so UID matching alone should not be treated as strong authentication.

A production system would require additional measures such as:

- stronger card authentication;
- secure credential storage;
- anti-cloning controls;
- event logging;
- tamper detection;
- access revocation;
- backend identity management.

---

## Possible Extensions

- support multiple authorised cards;
- store authorised credentials in EEPROM or an external database;
- add an LCD/OLED display;
- record access events with timestamps;
- add keypad or biometric second-factor verification;
- connect the system to Wi-Fi or MQTT;
- add administrator enrolment / card-revocation workflows.

---

## Author

**Leroy Nyasha Mangwarara**

Computer Science · Software Engineering · Embedded Systems · IoT

[GitHub](https://github.com/Leroy-laboe) · [LinkedIn](https://www.linkedin.com/in/leroy-nyasha-mangwarara-86185a302/) · [Email](mailto:mangwararaleroy@gmail.com)
