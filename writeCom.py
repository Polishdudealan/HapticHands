from time import sleep
import serial
ser = serial.Serial('COM2', 115200)
ser.flush()
finger_val = [0, 0, 0, 0, 0]
delta = [4, 4, 4, 4, 4]
while True:
    for i in range(5):
        if finger_val[i] > 0x0FFF:
            finger_val[i] = 0
        else:
            finger_val[i] += delta[i]
    print(finger_val)
    finger_str = [
        b''.join(
            [
                ((x >> 8) & 0xFF).to_bytes(1, 'big'), 
                (x & 0xFF).to_bytes(1, 'big')
                ]
            ) for x in finger_val
        ]
    textMsg = bytes("$1", 'utf-8') + b''.join(finger_str)# + bytes("^", 'utf-8')
    print(textMsg)
    ser.write(textMsg)
    sleep(0.01)