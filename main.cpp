#include <stdio.h>
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <unordered_map>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include "network.h"
#include <unistd.h>
using namespace std;

/* Manage.cpp
 * Author: Paul May , 25/6/18
 * this is the entrypoint for a database I spent
 * the summer of 2018 learning how to build in
 * an unfamiliar language and an unfamiliar text 
 * editor. so be forgiving.
 *
*/

//----------- Data Base Acess functions -----------
int sole_client_fdesc;
supernode* supe;
node* ne;
thread* super;
void quit()
{
	super->join();
	exit(EXIT_SUCCESS);
}
//this is called on t1 , it listens to 
//incoming server stuff
//i tried to pass the supernode class
//as an arg like a normal person
//but OSX threw a fit about threading.
//eg: it still ran but it made my linter mad.

void message(){
	if(supe->client < 0)
	{
		cout << "no server launched" << endl;
		return;
	}
	const char* message = "somebody";
	
	write(sole_client_fdesc,message,255);
	
}

void listen_loop()
{
	if(supe->client < 0)
	{
		return;
	}
	int listen_status = listen(supe->client, 1);
	if(listen_status < 0)
	{
		cout << "error setting up listener for supernode\n";
		exit(EXIT_FAILURE);
	}
	cout << "listening on port 8080" << "\n>>" << endl;
	
	struct sockaddr shrim;
	socklen_t client_length = sizeof(shrim);
	int cli_int = supe->client;
	int sock_file_desc = accept(cli_int, (struct sockaddr *) &shrim , 
						&client_length);
	if(sock_file_desc < 0 ){
		return;
	}else{
		cout << "connection on port 8080 >>" << endl;
		char* buffer[256];
		bzero(buffer,256);
		int n = read(sock_file_desc, *buffer, 255);
		cout << buffer << "\n>>" << endl;
		sole_client_fdesc = sock_file_desc;
	}

}

void launch_server()
{
	supe = new supernode(8080);

	//do all the suoernode shit on a different thread
	//let the user enter commands on the main thread.
	super =  new thread(listen_loop);
	return;
}

void launch_client()
{
	ne  = new node();
	return;
}


int main(int argc, char *argv[]){
sqlite3 *db;

int fail_flag = sqlite3_open("shrek.db", &db);

if(fail_flag)
{
	cerr << "error launching db\n";
	return 0;
}
else
{
	cout << "db launched\n";
	cout << ">> ";
}

unordered_map<string,function< void() > >  command_key;

command_key["quit"] = quit;
command_key["server"] = launch_server;
command_key["node"] = launch_client;
command_key["test"] = message;
while(true)
{
	string command;
	getline(cin, command);
	try
	{
		command_key[command]();
	}
	catch(exception& e)
	{
		cout << ">> Invalid command\n";
	}
	cout<<">>";
}

	super->join();

}
