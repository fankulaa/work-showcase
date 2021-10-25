from pyautogui import *
import pyautogui
import keyboard
import time
import random

'''
looking for mouse position
pyautogui.displayMousePosition()
'''

def test (x, y):
    x_random = random.randint(200, 1300) #200 - 1300 /starting pos
    y_random = random.randint(250, 900) #250 - 900 /starting pos
    pyautogui.moveTo(x, y)
    pyautogui.click()
    
    pyautogui.moveTo(x_random, y_random)
    pyautogui.click()

def mousePathing(x,y):
    x_curr,y_curr = pyautogui.position()


    while x_curr != x and y_curr != y:
        if keyboard.is_pressed('c') == True:
            exit()
        

        #changeable
        draw_speed = 0.4 #can be randomized def: 0,4
        sizemin, sizemax = 5, 20 #randomizing between smallest and lowest values def:20-30

        #not worth changing
        precision = 20 #How forgiving algorith is for last pixels of code
        jitterAtTheEnd = 30 # +x/2 -x/2  (Must be there for finishing function or it never ends)
        quotient = 2

        #dont change
        x_Path = x_curr - (x_curr - x)/quotient
        y_Path = y_curr - (y_curr - y)/quotient

        x_NextCord = (x_curr - x)/quotient
        y_NextCord = (y_curr - y)/quotient

        x_temp = x_curr
        y_temp = y_curr

        x_used = False
        y_used = False

        x_in_place = False
        y_in_place = False


        #x early+mid stage
        if (x_temp - x_Path) > 40:
            x_curr = x_temp - random.randint(sizemin, sizemax)
            x_used = True
        if(x_temp - x_Path) < -40:
            x_curr = x_temp + random.randint(sizemin, sizemax)
            x_used = True

        #y early+mid stage
        if (y_temp - y_Path) > 40:
            y_curr = y_temp - random.randint(sizemin, sizemax)
            y_used = True
        if (y_temp - y_Path) < -40:
            y_curr = y_temp + random.randint(sizemin, sizemax)
            y_used = True
        
        #y+x last stages
        if x_used == False:
            x_curr = x_curr - x_NextCord + random.randint(int((jitterAtTheEnd/2)*(-1)), int(jitterAtTheEnd/2))
        if y_used == False:
            y_curr = y_curr - y_NextCord + random.randint(int((jitterAtTheEnd/2)*(-1)), int(jitterAtTheEnd/2))



        pyautogui.click()
        #pyautogui.moveTo(x_curr, y_curr)
        pyautogui.dragTo(x_curr, y_curr, draw_speed, button='left')
        pyautogui.click()

        #Detecting if were already in place where we need to be
        if y-(precision/2) < y_curr < y+(precision/2):
            y_in_place=True
        if x-(precision/2) < x_curr < x+(precision/2):
            x_in_place=True
        if x_in_place == True and y_in_place == True:
            pyautogui.dragTo(x, y, draw_speed, button='left')
            y_curr=y
            x_curr=x
    pyautogui.moveTo(x_curr, y_curr)
    pyautogui.click()

#main
while True:
    x = random.randint(200, 1300) #200 - 1450 /target pos
    y = random.randint(250, 900) #250 - 950 /target pos
    if keyboard.is_pressed('c') == True:
            exit()
    if keyboard.is_pressed('b') == True:
        test(x,y)
        time.sleep(2)
        mousePathing(x,y)
        mousePathing(x,y)