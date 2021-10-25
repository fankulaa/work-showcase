import socket

# variables
PORT = 5050
SERVER = socket.gethostbyname(socket.gethostname()) #change to your server name
ADDR = (SERVER, PORT)


HEADER = 255
USERNAME = 20
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "!dis"

#connecting server :
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)

#functions:
def setUsername(msg):
    if msg == None:
        pass

    message = msg.encode(FORMAT)
    msg_lenght = len(message)
    send_lenght = str(msg_lenght).encode(FORMAT)
    send_lenght += b' ' * (USERNAME - len(send_lenght))
    client.send(send_lenght)
    client.send(message)

def send(msg):
    if msg == None:
        pass

    message = msg.encode(FORMAT)
    msg_lenght = len(message)
    send_lenght = str(msg_lenght).encode(FORMAT)
    send_lenght += b' ' * (HEADER - len(send_lenght))
    client.send(send_lenght)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))
    if msg == DISCONNECT_MESSAGE:
        print("[SERVER] You were disconected.")
        time.sleep(2)
        exit()

#main
setUsername(input('Input username: '))
while True:
    send(input('Input mesage: '))