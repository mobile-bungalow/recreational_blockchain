#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include "network.h"

using namespace std;

//------------------- Supernode ----------------------



supernode::supernode(int portnum) : clientstatus() , portnum(portnum), server_address(), client()
{
	//set up server
	client = socket(AF_INET, SOCK_STREAM, 0);
	
	if( client < 0 )
	{
		cout << "there was an error setting up the supernode";
		clientstatus = 0;
		return;
	}
	else
	{
		struct sockaddr_in server_address;
		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(8080);
		clientstatus = 1;

	}


}




supernode::~supernode()
{


}


//-------------------- Node -------------------------

node::node()
{

}

node::~node()
{

}



