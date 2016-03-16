#ifndef SOCKACCEPT_H
#define SOCKACCEPT_H
#include "SocketBase.h"
/*
This creates a server with active socket connection
SockAccept() -> Creates a socket connection with default values
SockAccept(int port, int domain, int type, int protocol, int backLog, string ip) -> creates a socket connection with specified values;
int start() -> activate server from binding to listen and accept state.
*/
class SockAccept : public SocketBase
{
public:
    int clientSock;
	int sBackLog;
    SockAccept();
	SockAccept(int port, int domain, int type, int protocol, int backLog, string ip);
	int start();   
    ~SockAccept();
private:
	int startAcceptingConnections();
};

#endif // SOCKACCEPT_H
