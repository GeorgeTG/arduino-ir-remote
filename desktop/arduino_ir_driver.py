import serial
from evdev import uinput, ecodes as e

ARDUINO_PORT = "/dev/ttyACM1"

KEY_MAP = {
    "KEY_UP": e.KEY_UP,
    "KEY_DOWN": e.KEY_DOWN,
    "KEY_RIGHT": e.KEY_RIGHT,
    "KEY_LEFT": e.KEY_LEFT,
    "KEY_OK": e.KEY_SPACE,
}

def main():
    with serial.Serial(ARDUINO_PORT, 9600, timeout=2) as ser:
        with uinput.UInput() as ui:
            while True:
                line = ser.readline()
                if line == b'':
                    continue
                # we got some data
                line = line.decode('utf-8').rstrip()
                try:
                    key = KEY_MAP[line]
                    ui.write(e.EV_KEY, key, 1)
                    ui.write(e.EV_KEY, key, 0)
                    ui.syn()
                except KeyError:
                    print("Could not match input: " + line)
                continue




if __name__ == '__main__':
    main()

"""

"""
