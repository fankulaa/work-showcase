import socket
import threading
import os
import tkinter
from tkinter import messagebox

#https://www.youtube.com/watch?v=3QiPPX-KeSc&ab_channel=TechWithTim


PORT = 5050
HEADER = 255
USERNAME = 20
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = 'utf-8'


server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)

#filters out commands
def command_filter(msg, username):
    DISCONNECT = "!dis"
    SHUTDOWN = "!shutdown"

    if msg == DISCONNECT:
        connected = False
        print(f"[{username}] Disconected.")
        quit
    if msg == SHUTDOWN:
            root = tkinter.Tk()
            root.withdraw()
            messagebox.showwarning("Error404", "Shutdown in 10sec")
            
            os.system("shutdown /s /t 10")

#client handling
def handle_client(conn, addr):


    usr_lenght = conn.recv(USERNAME).decode(FORMAT)
    if usr_lenght:
        usr_lenght = int(usr_lenght)
        username = conn.recv(usr_lenght).decode(FORMAT)
        print(f"[NEW CONNCETION] {username} connceted")

    connected= True
    while connected:
        msg_lenght = conn.recv(HEADER).decode(FORMAT)
        if msg_lenght:
            msg_lenght = int(msg_lenght)
            msg = conn.recv(msg_lenght).decode(FORMAT)
            print(f"[{username}] {msg}")
            conn.send("sent".encode(FORMAT))
            command_filter(msg, username)


    conn.close()


def start():
    server.listen()
    print(f"[LISTENING] Server is listening on {SERVER}")
    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        print(f"[ACTIVE CONNCETIONS] {threading.active_count() - 1}")
        thread.start()


print ("[STARTING] Server is starting...")
start()