#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <functional>
using namespace std;

/* Manage.cpp
 * Author: Paul May , 25/6/18
 * this is the entrypoint for a database I spent
 * the summer of 2018 learning how to build in
 * an unfamiliar language and an unfamiliar text 
 * editor. so be forgiving.
 */

void launch(){
	cout << "launching DB\n";
}

unordered_map<string,function< void() > >  dict;


void process(char *command){
	std::stringstream comss;
	comss.str(command);
	string com = comss.str();
	
	try{
		function<void()> callable = dict[com];
		callable();
		 
	}catch(exception& e){
		cout << com <<" is and invalid option or command\n";
		exit(EXIT_FAILURE);
	}
}


int main(int argc, char *argv[]){

if(argc <= 1){
	cout << "Usage: manage -[flags] [options]\n";
	cout << "run manage --help for options and flags\n";
	return 1;
}


for (char **a = argv+1 ; a != argv+argc ; a++) {
	dict["run_db"]=launch;
	process(*a);


}

}
