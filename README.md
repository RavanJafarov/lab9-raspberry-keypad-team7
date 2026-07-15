# 🍓 Lab 9 - Raspberry Pi & Arduino UART Communication
### Team 7 | EEC3612 Embedded Systems Lab (Week 11)

![RaspberryPi](https://img.shields.io/badge/Raspberry_Pi-3_Model_B-C51A4A)
![Arduino](https://img.shields.io/badge/Arduino-UNO-0082FC)
![Python](https://img.shields.io/badge/Python-3.9+-green)
![UART](https://img.shields.io/badge/Protocol-UART-yellow)

---

## 👥 Team Members

| Name | Role |
|------|------|
| **Ravan Jafarov** | Team Leader, Raspberry Pi Configuration |
| Azar Aslanov | Hardware (4x4 Keypad to Arduino wiring) |
| Riad Alizada | Arduino Code (Keypad reading & Serial print) |
| Hasan Aliyev | Python Code (RPi Serial Listener) |

📅 **Date:** November 2025  
🎓 **Professor:** Kim Deokhwan  
🛠️ **LA:** Rasim Mahmudov

---

## 🎯 Objective

The main objective of this lab is to establish **UART (Serial) communication** between an Arduino Uno and a Raspberry Pi 3. 
- **Arduino** reads inputs from a **4x4 Matrix Keypad**.
- The pressed key is sent via USB/Serial to the **Raspberry Pi**.
- A **Python script** on the Raspberry Pi listens to the serial port and prints the pressed keys to the Linux terminal.

---

## 🔧 Components Used

| Component | Description |
|-----------|-------------|
| Raspberry Pi 3 Model B | Host computer running Python script |
| Arduino Uno | Microcontroller reading the keypad |
| 4x4 Matrix Keypad | Input device (16 buttons) |
| USB Cable (Type A-B) | Connects Arduino to RPi for Serial/Power |
| Jumper Wires | For Keypad to Arduino connections |

---

## 📂 Project Structure

```
lab9-raspberry-keypad-team7/
├── README.md
├── arduino_code/
│   └── keypad_serial.ino
├── rpi_python_code/
│   └── serial_listener.py
└── images/
    ├── circuit.jpg
    └── terminal_output.jpg
```

---

## ⚙️ Raspberry Pi Configuration

Before running the Python script, the serial port must be configured correctly on the Raspberry Pi:

1. Open terminal on RPi and run:
   ```bash
   sudo raspi-config
   ```
2. Go to **Interfacing Options** > **Serial**.
3. When asked *"Would you like a login shell to be accessible over serial?"*, select **No**.
4. When asked *"Would you like the serial port hardware to be enabled?"*, select **Yes**.
5. Reboot the Raspberry Pi.

---

## 🔌 Circuit Setup

### 4x4 Keypad to Arduino Uno
| Keypad Pin | Arduino Digital Pin |
|------------|---------------------|
| Row 1      | D9                  |
| Row 2      | D8                  |
| Row 3      | D7                  |
| Row 4      | D6                  |
| Col 1      | D5                  |
| Col 2      | D4                  |
| Col 3      | D3                  |
| Col 4      | D2                  |

*Note: The Arduino is connected to the Raspberry Pi via a standard USB cable.*

---

## 💻 Arduino Code

👉 See [`arduino_code/keypad_serial.ino`](arduino_code/keypad_serial.ino)

### Key Features
- Uses the `Keypad.h` library to scan the 4x4 matrix.
- Initializes Serial communication at `9600` baud.
- Sends the pressed character via `Serial.println()` to the RPi.

---

## 🐍 Raspberry Pi Python Code

👉 See [`rpi_python_code/serial_listener.py`](rpi_python_code/serial_listener.py)

### How to Run on Raspberry Pi
1. Ensure `pyserial` is installed (usually pre-installed on Raspbian):
   ```bash
   pip install pyserial
   ```
2. Find your Arduino port (usually `/dev/ttyACM0` or `/dev/ttyUSB0`):
   ```bash
   ls /dev/tty*
   ```
3. Run the script:
   ```bash
   python3 serial_listener.py
   ```

---

## 📊 Results

✅ Arduino successfully reads 4x4 keypad inputs.  
✅ Serial data is transmitted over USB to Raspberry Pi.  
✅ Python script accurately captures and prints the pressed keys in the terminal.  
✅ Demonstrated practical UART communication between two different microcomputers.

---

## 📝 Conclusion

This lab successfully demonstrated how to bridge the gap between a microcontroller (Arduino) and a mini-computer (Raspberry Pi) using UART serial communication. This setup is the foundation for more complex IoT systems where the Arduino handles real-time hardware I/O (like sensors/keypads) and the Raspberry Pi handles data processing, logging, or network transmission.

---

## 📄 License
Educational project for EEC3612 Embedded Systems course.
