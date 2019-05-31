/*
 * main.cpp
 *  Created on: Apr 25, 2017
 *  Author: Erick Cabrera
 */

#include <iostream>
#include <string.h>
#include "TV_Set.h"
#include "ChannelArrayList.h"

using namespace std;
TV_Set *tv;
void printMenu(){
	cout << "1 - Turn TV off/on"<<endl;
	cout << "2 - go to a different channel"<<endl;
	cout << "3 - go up a channel"<<endl;
	cout << "4 - go down a channel"<<endl;
	cout << "5 - go to a different sound volume level"<<endl;
	cout << "6 - go up a sound volume level"<<endl;
	cout << "7 - go down a sound volume level"<<endl;
	cout << "8 - add a new channel"<<endl;
	cout << "9 - remove a channel"<<endl;
	cout << "10 - display all channels"<<endl;
	cout << "11 - what am I watching right now?"<<endl;
	cout << "12 - quit"<<endl;
}

void doOption(int choice){
	switch(choice){
	case 1:
		tv->togglePower();
		if(tv->isTvOn())
			cout<<"TV is now on!\n";
		else
			cout<<"TV is now off!\n";
		break;
	case 2:
		if(tv->isTvOn()){
			int channel;
			cout<<"Please enter a channel\n";
			cin>>channel;
			tv->changeChannel('0',channel);
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 3:
		if(tv->isTvOn()){
			tv->changeChannel('u',0);
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 4:
		if(tv->isTvOn()){
			tv->changeChannel('d',0);
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 5:
		if(tv->isTvOn()){
			int volume;
			cout<<"Please enter a volume\n";
			cin>>volume;
			tv->changeVolume('0',volume);
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 6:
		if(tv->isTvOn()){
			tv->changeVolume('u',0);
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 7:
		if(tv->isTvOn()){
			tv->changeVolume('d',0);
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 8:
		if(tv->isTvOn()){
			int channel;
			cout<<"Please enter a channel number and programming title\n";
			cin>>channel;
			string title;
			getline(cin,title);
			char* cp = new char[title.length()+1];
			strcpy(cp,title.c_str());
			tv->addChannel(channel,cp);
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 9:
		if(tv->isTvOn()){
			int channel;
			cout<<"Please enter a channel to remove\n";
			cin>>channel;
			tv->removeChannel(channel);
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 10:
		if(tv->isTvOn()){
			tv->displayAll();
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	case 11:
		if(tv->isTvOn()){
			tv->tvStatus();
		}else
			cout<<"TV is off, cannot function in this state!\n";
		break;
	}
}
int main(int argc, char** argv){
	int maxVolume = 0;
	if(argc == 2){
		maxVolume = atoi(argv[1]);
	}
	if(maxVolume <= 0)
		maxVolume = 25;
	tv = new TV_Set(maxVolume);
	while(1){
		printMenu();
		int choice;
		cin >> choice;
		if(choice >12 || choice < 1)
			cout << "Not a valid option\n";
		if(choice==12)
			break;
		else
			doOption(choice);

	}
	cout <<"Exiting!\n";
	return 0;
}
