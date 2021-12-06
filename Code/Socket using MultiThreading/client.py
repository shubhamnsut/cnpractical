from socket import *
from threading import *

class ClientThread(Thread):
    def __init__(self,con):
        Thread.__init__(self)
        self.con = con

    def run(self):
        name = current_thread().getName()
        while True:
            if name == "Sender":
                data = input("Server : ")
                if data == "bye":
                    break
                self.con.send(bytes(data,"utf-8"))
            elif name == "Receiver":
                recData = self.con.recv(1024).decode()
                print("Client : ",recData)
        client.close()

SERVER = "127.0.0.1"
PORT = 15000

client = socket(AF_INET, SOCK_STREAM)
client.connect((SERVER, PORT))

sender = ClientThread(client)
sender.setName("Sender")

receiver = ClientThread(client)
receiver.setName("Receiver")

sender.start()
receiver.start()