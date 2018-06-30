
#include <stdio.h>
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <unordered_map>
#include <netinet/in.h>
#include <sys/socket.h>
#include "network.h"
using namespace std;

/* Manage.cpp
 * Author: Paul May , 25/6/18
 * this is the entrypoint for a database I spent
 * the summer of 2018 learning how to build in
 * an unfamiliar language and an unfamiliar text 
 * editor. so be forgiving.
 *
 * a quick note on syntax philosophy:
 *
 * the c/c++ dereference operator is bad.
 * you should not parse the same object as 
 * multiplication, derreference , exponents and 
 * pointer declaration. i use (*pointer) when
 * I am derefferencing. side note: pythonic tabbing.
 *  
*/

//----------- Data Base Acess functions -----------

supernode* supe;
node* ne;

void quit()
{
	exit(EXIT_FAILURE);
}

void launch_server()
{
	supe = new supernode(8080);
	//put a while loop here which takes commands like main
	//treat this like a seperate program state
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
		cout << ">> Invalid command\n>>";
	}
	
}


}
