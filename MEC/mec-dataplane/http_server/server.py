import socket

# Implements a simple HTTP/1.1 Server
# tutorial - https://www.codementor.io/@joaojonesventura/building-a-basic-http-server-from-scratch-in-python-1cedkg0842

def handle_request(request):
    headers = request.split('\n')
    filename = headers[0].split()[1]
    if filename == '/':
        filename = '/index.html'

    try:
        fin = open('htdocs' + filename)
        content = fin.read()
        fin.close()

        response = 'HTTP/1.0 200 OK\n\n' + content
    except FileNotFoundError:
        response = 'HTTP/1.0 404 NOT FOUND\n\nFile Not Found'

    return response

# Create this interface 
# sudo ip link add name mylo type dummy
# sudo ifconfig mylo 11.12.13.14 up
# curl from this pc: curl http://11.12.13.14:65432
# curl from ue: curl --interface oaitun_ue1 http://11.12.13.14:65432
#
# This sample server runs on the same machine as MEC server. 
# It works as follows:
#  1. vif creates a GTP device and GTP tunnel to UE.
#  2. dispatcher identifies this server's IP in destination of packets from UE.
#  3. It redirects the packets to MEC(a GTP device) which listens on the GTP port 2152.
#  4. Since this app server is in same machine, MEC GTP device can find this IP and redirect traffic from UE to this server. 
#  5. Traffic to UE is sent through MEC GTP device which automatically encapsulates the packets with GTP. 

SERVER_HOST = '11.12.13.14'
SERVER_PORT = 65432

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind((SERVER_HOST, SERVER_PORT))
sock.listen(1)
print('Listening on port %s ...' % SERVER_PORT)

while True:
    conn, addr = sock.accept()

    request = conn.recv(1024).decode()
    print(request)

    response = handle_request(request)
    conn.sendall(response.encode())

    conn.close()

sock.close()
