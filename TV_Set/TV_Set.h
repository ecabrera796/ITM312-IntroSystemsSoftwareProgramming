/*
 * TV_Set.hpp
 *
 *  Created on: Apr 25, 2017
 *      Author: Erick Cabrera
 */

#ifndef TV_SET_H_
#define TV_SET_H_
#include "ChannelArrayList.h"
class TV_Set{
public:
	TV_Set(int maxVolume);
	~TV_Set();
	void addChannel(int channelNumber, char* programmingTitle);
	void changeChannel(char direction, int specificChannel);
	void changeVolume(char direction, int speficiVolume);
	bool isTvOn();
	void volumeStatus();
	void channelStatus();
	void tvStatus();
	void togglePower();
	void removeChannel(int specificChannel);
	void displayAll();
private:
	ChannelArrayList::Channel *currentChannel;
	int maxVolume;
	bool isOn;
	int currentVolume;
	ChannelArrayList *channels;
	void printStatus();

};



#endif /* TV_SET_HPP_ */
