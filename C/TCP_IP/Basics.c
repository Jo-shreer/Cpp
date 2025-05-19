/*
1. What is TCP/IP, and how does it work?
TCP/IP (Transmission Control Protocol/Internet Protocol) is a suite of communication protocols
used to interconnect devices on the internet or local networks. 
It ensures reliable data transmission through the following layers:

Application Layer: Provides services like HTTP, FTP, DNS, etc.
Transport Layer: Includes TCP (reliable, connection-oriented) and UDP (unreliable, connectionless) protocols.
Internet Layer: Defines IP (Internet Protocol) for addressing and routing.
Link Layer: Deals with physical network components (Ethernet, Wi-Fi, etc.).

2. What is a socket in the context of TCP/IP?
A socket is an endpoint for communication in a network. It's a combination of:
IP address: The unique address of the machine.
Port number: The service or application identifier on the machine.
Sockets are used by applications to send and receive data over a network using TCP or UDP.

3. What are the different socket types in C?
SOCK_STREAM: For TCP (stream-oriented communication).
SOCK_DGRAM: For UDP (datagram-oriented communication).
SOCK_RAW: For raw sockets used to work directly with network layers.

4. Explain the steps involved in establishing a TCP connection (3-way handshake).
The TCP 3-way handshake involves:
SYN: The client sends a SYN (synchronize) packet to the server to initiate the connection.
SYN-ACK: The server responds with a SYN-ACK packet to acknowledge the connection.
ACK: The client sends an ACK packet to finalize the connection.

5. What is a port number in TCP/IP, and how is it used?
A port number is a 16-bit integer used to identify specific processes or services running on a machine. 
The port number is combined with the IP address to form a socket:
Well-known ports (0-1023): For common services like HTTP (80), HTTPS (443), FTP (21).
Registered ports (1024-49151): For applications not standardized by IANA.
Dynamic/Private ports (49152-65535): For temporary client-side ports.
















*/
