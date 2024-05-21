import serial
import sys
import signal

# Declare ser as a global variable
ser = None

def signal_handler(sig, frame):
    """Handle signal interrupt to close the serial port safely."""
    global ser
    if ser is not None and ser.is_open:
        print("\nInterrupción recibida, cerrando el puerto serial.")
        ser.close()
    sys.exit(0)

def main():
    global ser
    try:
        # Open the serial port
        ser = serial.Serial('COM3', 115200)
        señal_inicio = "<>".encode()
        
        # Read until the start signal is found
        ser.read_until(señal_inicio)

        print("Iniciando lectura de datos...")
        while True:
            línea = ser.readline().strip().decode("utf-8")
            print(línea)

    except serial.SerialException as e:
        print(f"Error al abrir el puerto serial: {e}")
    except Exception as e:
        print(f"Error inesperado: {e}")
    finally:
        if ser is not None and ser.is_open:
            ser.close()
            print("Puerto serial cerrado.")

if __name__ == "__main__":
    # Register signal handler for clean exit on Ctrl+C
    signal.signal(signal.SIGINT, signal_handler)
    main()
