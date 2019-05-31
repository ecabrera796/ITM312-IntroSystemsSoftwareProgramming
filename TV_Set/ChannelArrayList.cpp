/*
 * ChannelArrayList.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: Erick Cabrera
 */

#include "ChannelArrayList.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

ChannelArrayList::ChannelArrayList(){
	size = 0;
	currentChannel = 0;
	lastAddedIndex = -1;
}

ChannelArrayList::~ChannelArrayList(){
	for(int i=0;i<=size;i++)
		delete(channels[i]);
	delete [] channels;
}

bool ChannelArrayList::add(struct Channel *channel,bool forceAdd){
	if(size >= MAX_CHANNELS && !forceAdd)
		return false;
	//check for dupes
	if(size>=1){
		if(int index = checkForDupes(channel)>=0){
			channels[index] = channel;
			return true;
		}
	}
	//check for null spaces
	if(lastAddedIndex>=MAX_CHANNELS-1){
		bool reset = true;
		for(int i=0;i<size; i++){
			if(channels[i]==NULL){
				lastAddedIndex = i-1;
				reset = false;
			}
		}
		if(reset){
			lastAddedIndex = -1;
		}
	}
	lastAddedIndex++;
	cout<<lastAddedIndex<<endl;
	if(size < MAX_CHANNELS)
		channels[lastAddedIndex] = (ChannelArrayList::Channel*)malloc(sizeof(ChannelArrayList::Channel));
	channels[lastAddedIndex] = channel;
	if(size<MAX_CHANNELS)
		size++;
	this->sort();
	return true;
}

ChannelArrayList::Channel ChannelArrayList::remove(int channelNumber){
	struct Channel removedChannel;
	for(int i = 0; i<size;i++){
		if(channels[i] != 0 && channels[i]->channelNumber == channelNumber){
			int index = i;
			removedChannel = *channels[i];
			delete(channels[index]);
			for(int j = i+1; j<size; j++){
				channels[index] = channels[j];
				index++;
			}
			size--;
			if(i!=size)
				delete(channels[size]);
			this->sort();
			return removedChannel;
		}
	}
	return removedChannel;
}

ChannelArrayList::Channel* ChannelArrayList::getChannel(int channelNumber){
	for(int i = 0; i<=size;i++){
		if(channels[i] != 0 && channels[i]->channelNumber == channelNumber){
			struct Channel *removedChannel = channels[i];
			currentChannel = i;
			return removedChannel;
		}
	}
	return NULL;
}

ChannelArrayList::Channel* ChannelArrayList::changeChannel(char* direction){
	if(strcmp(direction,"up")==0){
		if(currentChannel >= size-1)
			currentChannel = 0;
		else
			currentChannel++;
	}else{
		if(currentChannel <= 0)
			currentChannel = size-1;
		else
			currentChannel--;
	}
	struct Channel *changedChannel = channels[currentChannel];
	return changedChannel;
}

std::string ChannelArrayList::toString(struct Channel *channel){
	char num[10];
	string toString("Channel ");
	snprintf(num, 10, "%d", channel->channelNumber);
	toString.append(num);
	toString.append(" - ");
	toString.append(channel->programmingTitle);
	return toString;
}

void ChannelArrayList::toString(){
	if(size == 0)
		return;
	for(int i=0;i<size;i++){
		cout << toString(channels[i]) << endl;
	}
}

void ChannelArrayList::sort (){
	int length = size;
	ChannelArrayList::Channel *temp;
	int j;
	for (int i = 0; i < length; i++){
		j = i;

		while (j > 0 && channels[j]->channelNumber < channels[j-1]->channelNumber){
			  temp = channels[j];
			  channels[j] = channels[j-1];
			  channels[j-1] = temp;
			  j--;
		}
	}
}

void ChannelArrayList::findNewIndex(struct Channel *channel){
	if(!channel){
		currentChannel = 0;
		return;
	}
	for(int i=0;i<size;i++){
		if(channels[i]->channelNumber == channel->channelNumber){
			currentChannel = i;
			return;
		}
	}
}

int ChannelArrayList::checkForDupes(struct Channel *channel){
	for(int i=0; i<size;i++){
		if(channels[i]->channelNumber == channel->channelNumber)
			return i;
	}
	return -1;
}
