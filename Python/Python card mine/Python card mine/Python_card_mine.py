from tkinter import *

bg="#5DADE2"



"""
First Python project ever (8-10h) 2021/04/10

Workflow:
1. Checks for longer numbers (13-19) in "input.txt".
2. Checks if longer number belongs to any bank.
3. Saves valid (or not valid) card number to "output.txt".

Card number specifications:
https://www.freeformatter.com/credit-card-number-generator-validator.html
"""

#function that checks what bank card belogs to
def find_card(string):
    
    test_nr=0
    three_digits=''
    four_digits=''
    six_digits=''

    for ele in string:
            six_digits += ele
            test_nr = test_nr+1
            if test_nr == 6:
                break
    test_nr=0
    for ele in string:
            three_digits += ele
            test_nr = test_nr+1
            if test_nr == 3:
                break
    test_nr=0
    for ele in string:
            four_digits += ele
            test_nr = test_nr+1
            if test_nr == 4:
                break

    #print("three digits: " + three_digits)
    #print("four digits: " + four_digits)
    #print("six digits: " + six_digits)
    #print("string: " + string)

    if string.startswith("34") or string.startswith("37"):
        if 14 < len(str(string)) < 16:
            return "American Express"
    elif 299 < int(three_digits) < 306:
        if 13 < len(str(string)) < 15:
            return "Diners Club - Carte Blanche"
    elif string.startswith("36"):
        if 13 < len(str(string)) < 15:
            return "Diners Club - International"
    elif string.startswith("54"):
        if 15 < len(str(string)) < 17:
            return "Diners Club - USA & Canada"
    elif string.startswith("6011") or string.startswith("65") or 643 < int(three_digits) < 650 or 622125 < int(six_digits) < 622926 :
        if 15 < len(str(string)) < 20:
            return "Discover"
    elif 636 < int(three_digits) < 640:
        if 15 < len(str(string)) < 17:
            return "InstaPayment"
    elif 3527<int(four_digits)<3590:
        if 15 < len(str(string)) < 20:
            return "JCB"
    elif string.startswith("5018") or string.startswith("5020") or string.startswith("5038") or string.startswith("5893") or string.startswith("6304") or string.startswith("6759") or string.startswith("6761") or string.startswith("6762") or string.startswith("6763"):
        if 15 < len(str(string)) < 20:
            return "Maestro"
    elif string.startswith("51") or string.startswith("52") or string.startswith("53") or string.startswith("54") or string.startswith("55") or 222099 < int(six_digits) < 272100:
        if 15 < len(str(string)) < 17:
            return "MasterCard"
    elif string.startswith("4"):
        if 12 < len(str(string)) < 20:
            return "Visa"
    elif string.startswith("4026") or string.startswith("417500") or string.startswith("4508") or string.startswith("4844") or string.startswith("4913") or string.startswith("4917"):
        if 15 < len(str(string)) < 17:
            return "Visa Electron"
    return "Unknown"

#printing "input.txt"
print("Input:\n")
with open("input.txt") as input:
    print(input.read())

#checks "input.txt" and writes card numbers to "output.txt"
with open("input.txt") as input:
    text = input.read()
    number = ''
    card = ''
    text_lenght = 0
    for ele in text:
        if ele.isdigit():
            number += ele
        elif ele == " ":
            pass
        elif not ele.isdigit():
            if 12 < len(str(number)) < 20:
                card = find_card(number)
                with open("output.txt", 'r+') as write:
                    write.seek(text_lenght)
                    write.write(number + " " + card + "\n")
                    text_lenght = text_lenght + int(len(str(number))) + int(len(str(find_card(number)))+3)
            number=''
            pass


#printing "output.txt"
print("\n\nOutput:\n")
with open("output.txt") as output:
        print(output.read())

root = Tk()
root.title('Creddit card miner')
root.geometry("+400+150")
root.geometry("500x400")
#root.overrideredirect(True) #dissables 
root.resizable(0,0)
root.wm_attributes('-transparentcolor','red')
root.configure(background='red')

label = Label(root, bg=bg, text ="Input:")
label.pack(padx=5, pady=0)
with open("input.txt") as input:
    textas = input.read()
    label_input = Label(root, bg="#CAE7FF", text=textas, wraplength=400)
    label_input.pack()

l = Label(root, bg="red")
l.pack(pady=10)

label1 = Label(root, bg=bg, text ="Output:")
label1.pack(padx=5, pady=0)
with open("output.txt") as output:
    textas = output.read()
    label_output = Label(root, bg="#CAE7FF", text=textas, wraplength=400, anchor="e", justify=LEFT)
    label_output.pack()

root.mainloop()