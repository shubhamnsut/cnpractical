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
                self.con.send(bytes(data,"utf-8"))
            elif name == "Receiver":
                recData = self.con.recv(1024).decode()
                if recData == "bye" or recData == "Bye":
                    break
                print("Client : ",recData)

LOCALHOST = "127.0.0.1"
PORT = 15000

server = socket(AF_INET, SOCK_STREAM)
server.bind((LOCALHOST, PORT))
server.listen(4)
connection , address = server.accept()

sender = ClientThread(connection)
sender.setName("Sender")

receiver = ClientThread(connection)
receiver.setName("Receiver")

sender.start()
receiver.start()


