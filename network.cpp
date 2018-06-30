#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include "network.h"

//------------------- Supernode ----------------------

supernode::supernode(int portnum) : clientstatus() , portnum(portnum), server_address(), client()
{
	//set up server
	client = socket(AF_INET, SOCK_STREAM, 0);
	
	if( client < 0 )
	{
		std::cout << "there was an error setting up the supernode\n";
		clientstatus = 0;
		return;
	}
	else
	{
		struct sockaddr_in server_address;
		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(portnum);
		server_address.sin_addr.s_addr = INADDR_ANY;
		int word = bind(client , (struct sockaddr *)&server_address, sizeof(server_address));
		if(word < 0)
		{
			std::cout << "there was an issue binding to the port\n";
			clientstatus = 0;
			return;
		}
		
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



