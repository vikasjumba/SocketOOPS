#include "SockAccept.h"
#include <iostream>
using namespace std;
SockAccept::SockAccept() : sBackLog(5)
{
// super class calls socket	
}
SockAccept::SockAccept(int port, int domain, int type, int protocol, int backLog, string ip = "0.0.0.0") : SocketBase(port, domain, type, protocol, ip), sBackLog(backLog)
{
// super class calls socket	
}
int SockAccept::start()
{
	int status = SocketBase::start();   // initialize the socket address
	if (status == -1)
	{
		// error printed in base class
		return status;
	}
	// proceed with bind, listen and accept code implementation
	
	if (bind(sockDesc, (struct sockaddr *)&(sockAddr), sizeof(sockAddr)) != 0)
    {
        cout << "Error in bind -> " << strerror(errno) << "\n";
        return -1;
    }
	return startAcceptingConnections();
}

int SockAccept::startAcceptingConnections()
{
    if(listen(sockDesc, sBackLog) != 0)
    {
        cout << "Error in listening -> " << strerror(errno) << "\n";
        return -1;
    }
    clientSock = accept (sockDesc, nullptr, nullptr); 
    
    return 0;
}

SockAccept::~SockAccept()
{
// super class closes the socket 
}

