#include <stdio.h>
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <unordered_map>
using namespace std;

/* Manage.cpp
 * Author: Paul May , 25/6/18
 * this is the entrypoint for a database I spent
 * the summer of 2018 learning how to build in
 * an unfamiliar language and an unfamiliar text 
 * editor. so be forgiving.
 */

//----------- Data Base Acess functions -----------

void quit()
{
	exit(EXIT_FAILURE);
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
