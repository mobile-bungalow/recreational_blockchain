#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#pragma once

/*
 * i'm literally just messing around here
 * the supernode will distribute and maintain
 * a list of addresses. this is arbitraily 
 * flimsy.
 *
 * the node will run basic consensus operations 
 * and in tern edit the data base on the user back
 * end. 
 */

class supernode 
{

	public:
		//flesh out the constructor
		//later
		supernode(int portnum);
		~supernode();
		int clientstatus;
		int portnum;
		int client;
		sockaddr_in server_address;
		//void acceptconn();
		//void dropconn();
		//std::string listcon();
		//bool isconn();
	private:
		//add some variables here
		//whatever we need to run the
		//supernode
		//void reqResponse();
		//void updateMessage();
};

class node
{

	public:
		node();
		~node();
	private:

};
