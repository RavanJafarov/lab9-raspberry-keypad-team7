import serial
import time

# Raspberry Pi-də Arduino adətən bu portlardan birində olur
# Əgər işləməsə, '/dev/ttyUSB0' olaraq dəyişdirin
PORT = '/dev/ttyACM0'
BAUD = 9600

def main():
    print(f"Listening on {PORT} @ {BAUD}...")
    print("Press keys on the 4x4 Keypad. (Ctrl+C to exit)")
    
    try:
        # Serial portu açır
        with serial.Serial(PORT, BAUD, timeout=1) as ser:
            time.sleep(2)  # Arduino-nun reset olunması üçün qısa gözləmə
            
            while True:
                # Serial buffer-də məlumat varsa oxuyur
                if ser.in_waiting > 0:
                    data = ser.readline().decode('utf-8').strip()
                    if data:
                        print(f"Terminal Output -> Pressed Key: {data}")
                        
    except serial.SerialException as e:
        print(f"Serial port xətası: {e}")
        print("Zəhmət olmasa portu yoxlayın (ls /dev/tty*)")
    except KeyboardInterrupt:
        print("\nProqram dayandırıldı.")

if __name__ == "__main__":
    main()
