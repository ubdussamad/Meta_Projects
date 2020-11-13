#URND
main_env = (__name__ == "__main__")
import pynput
import turtle as tr
pensize = 1
from pynput import keyboard

def on_press(key):
    global pensize
    try:
        if key.char == 'r':
            tr.color('red')
        elif key.char == 'g':
            tr.color('green')
        elif key.char == 'b':
            tr.color('blue')
        elif key.char == 'w':
            tr.color('white')    
        elif key.char == 'q':
            tr.bye()
        elif key.char == '+':
            pensize += 1
            tr.pensize(abs(pensize))
        elif key.char == '-':
            pensize -= 1
            tr.pensize(abs(pensize))
        elif key.char == 'c':
            tr.clearscreen()
    except AttributeError:
        if key == key.up :
            tr.forward(8)
        elif key == key.down :
            tr.backward(8)
        elif key == key.left :
            tr.left(8)
        elif key == key.right :
            tr.right(8)
#tr.write("messi fan")
def on_release(key):
    #print('{0} released'.format(key))
    if key == keyboard.Key.esc:
        # Stop listener
        return False
import threading as thread
def zeta():
    while 1:
        tr.forward()
thread.start_new_thread(zeta)
# Collect events until released
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()
