import socket

s = socket.socket()
host=socket.gethostname()
port=12345
s.connect((host,port))
print s.recv(1024)
s.send("This is message from the client to the server")

s.close()
