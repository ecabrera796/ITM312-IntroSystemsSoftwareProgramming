/*
 * TV_Set.cpp
 *  Created on: Apr 25, 2017
 *  Author: Erick Cabrera
 */

#include "TV_Set.h"
#include "ChannelArrayList.h"
#include <iostream>
using namespace std;

TV_Set::TV_Set(int maxVolume){
	isOn = true;
	this->maxVolume = maxVolume;
	currentVolume = maxVolume/2;
	channels = new ChannelArrayList();
	currentChannel = 0;
}
TV_Set::~TV_Set(){
	delete(channels);
}
void TV_Set::addChannel(int channelNumber, char* programmingTitle){
	ChannelArrayList::Channel *newChannel = new ChannelArrayList::Channel;
	newChannel->channelNumber = channelNumber;
	newChannel->programmingTitle = programmingTitle;
	channels->add(newChannel,true);
	if(currentChannel == 0)
		currentChannel = newChannel;
	channels->findNewIndex(currentChannel);
}
void TV_Set::changeChannel(char direction, int specificChannel){

	if(direction == 'u'){
		currentChannel = channels->changeChannel("up");
	}
	else if(direction == 'd'){
		currentChannel = channels->changeChannel("down");
	}
	else {
		currentChannel = channels->getChannel(specificChannel);
	}
	channelStatus();
}
void TV_Set::changeVolume(char direction, int speficiVolume){
	if(direction == 'u'){
		currentVolume++;
		if(currentVolume > maxVolume)
			currentVolume = maxVolume;
		volumeStatus();
		return;
	}
	if(direction == 'd'){
		currentVolume --;
		if(currentVolume < 0)
			currentVolume = 0;
		volumeStatus();
		return;
	}
	if(direction == 'm'){
		currentVolume = 0;
		volumeStatus();
		return;
	}
	if(speficiVolume >= maxVolume)
		currentVolume = maxVolume;
	else if(speficiVolume <= 0)
		currentVolume = 0;
	else
		currentVolume = speficiVolume;
	volumeStatus();
}
bool TV_Set::isTvOn(){
	return isOn;
}

void TV_Set::removeChannel(int specificChannel){
	if(specificChannel == currentChannel->channelNumber){
		changeChannel('d',0);
	}
	channels->remove(specificChannel);
}

void TV_Set::displayAll(){
	channels->toString();
}

void TV_Set::volumeStatus(){
	cout << "Sound volume @" << currentVolume<<endl;
}
void TV_Set::channelStatus(){
	if(currentChannel)
		cout << "You are currently watching "<<channels->toString(currentChannel)<<endl;
	else
		cout << "OOPS! this channel is not available.\n";
}
void TV_Set::togglePower(){
	isOn = !isOn;
}
void TV_Set::printStatus(){
	if(currentChannel)
		cout << "You are currently watching "<<channels->toString(currentChannel) << ", sound volume @" << currentVolume<<endl;
	else
		cout << "OOPS! this channel is not available.\n";
}
void TV_Set::tvStatus(){
	printStatus();
}