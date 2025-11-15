# RFID Access Control System (Arduino UNO + RC522)

A complete **RFID-based access control system** using Arduino UNO, MFRC522 RFID reader, LEDs, buzzer, and a servo-based lock mechanism.  
Perfect for beginners who want to explore **RFID, SPI communication, and embedded security systems**.

---

## 🔧 Hardware Components

| Component         | Purpose |
|-------------------|---------|
| Arduino UNO       | Main controller |
| RC522 RFID Reader | Reads card UID |
| Green LED         | Access Granted indicator |
| Red LED           | Access Denied indicator |
| Buzzer            | Audible feedback |
| Servo Motor       | Lock/unlock mechanism |
| Jumper Wires      | Connections |
| Breadboard        | Assembly |

---

## 🧰 Wiring Diagram

### RFID → Arduino UNO

| RFID Pin | Arduino Pin |
|----------|-------------|
| SDA      | 10          |
| SCK      | 13 |
| MOSI     | 11 |
| MISO     | 12 |
| RST      | 9 |
| 3.3V     | 3.3V |
| GND      | GND |

### LEDs

- Green LED → pin **6** (via 220Ω resistor)  
- Red LED → pin **7** (via 220Ω resistor)

### Buzzer

- + → pin **8**  
- – → GND

### Servo

- Signal → pin **3**  
- VCC → 5V  
- GND → GND

---

## 🚀 Features

- Reads RFID card UID  
- Checks against allowed UID list  
- **Access Granted** → Green LED + Servo unlock  
- **Access Denied** → Red LED + Buzzer  
- Serial monitor output  
- Beginner-friendly and easy to expand

---

## ▶️ Setup & Run

1. Install required Arduino libraries:  
   - `MFRC522`  
   - `SPI`  
   - `Servo`  

2. Upload `rfid_access_system.ino` to your Arduino UNO.

3. Open **Serial Monitor → 9600 baud**.

4. Tap an RFID card:
   - Green LED + Servo unlock → **Access Granted**  
   - Red LED + Buzzer → **Access Denied**

---

## 📸 Media

Store images and demo GIF in the `/images` folder:

- `setup.jpg` → Breadboard setup  
- `wiring.jpg` → Wiring close-up  
- `demo.gif` → Demo of card tapping

---

## 🛠 Troubleshooting

- **RFID not reading** → Ensure 3.3V power, correct SPI pins, card near antenna  
- **Buzzer too quiet** → Use active buzzer or laptop speaker via Python script  
- **Servo vibrating** → Use separate 5V power if needed

---

## ✨ Author

**Leroy Mangwarara**
