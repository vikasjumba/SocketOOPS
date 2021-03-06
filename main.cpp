#include <stdio.h>
#include "SockConnect.h"
#include "SockAccept.h"
#include "SocketBase.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		// sample code to create server 
		SocketBase* sockAccept = new SockAccept();
		int res = sockAccept->start();
		if (res == -1)
		{
			return res;
		}
		int clientSd = static_cast<SockAccept*>(sockAccept)->acceptConnections(); 
		char buffSer[256];
		res = sockAccept->receiveData(clientSd,buffSer,256,0);
		cout << "Data received -> " << buffSer << endl;
		delete(sockAccept);
	}else{
		SocketBase* sockConnect = new SockConnect();
		int res = sockConnect->start();
		if (res == -1)
		{
			return res;
		}
		string data = "Data from client\n";
		char* buff = (char*)data.c_str();
		res = sockConnect->sendData(sockConnect->sockDesc,buff,data.length(),0);
		delete(sockConnect);
		if(res == -1)
		{
			return res;
		}
	}
	return 0;
}
