import serial
import time
import string

# Initialize serial connection to the Arduino
ser = serial.Serial('/dev/serial0', 9600, timeout=1)  # Adjust port if necessary
time.sleep(2)  # Wait for the serial connection to initialize

print("Listening for keypresses...")

try:
    while True:
        if ser.in_waiting > 0:  # Check if there's data to read
            raw_data = ser.readline()  # Read raw bytes
            print("Raw data received:", raw_data)  # Debug print for raw data

            # Decode, ignoring any decoding errors, and filter to printable ASCII characters
            key = ''.join([char for char in raw_data.decode('utf-8', errors='ignore').strip() if char in string.printable])

            if key:  # Only print if the key is non-empty
                print("Key pressed:", key)
except KeyboardInterrupt:
    print("Exiting...")
finally:
    ser.close()
