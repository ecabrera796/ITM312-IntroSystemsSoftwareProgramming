/*
 * ChannelArrayList.hpp
 *
 *  Created on: Apr 24, 2017
 *      Author: Erick Cabrera
 */

#ifndef CHANNELARRAYLIST_H
#define CHANNELARRAYLIST_H
#include <cstdlib>
#include <string>
using namespace std;
#define MAX_CHANNELS 10
class ChannelArrayList{
public:
	struct Channel{
		int channelNumber;
		char* programmingTitle;
	};
	ChannelArrayList();
	~ChannelArrayList();
	bool add(struct Channel *channel, bool forceAdd = false);
	struct Channel remove(int channelNumber);
	struct Channel* getChannel(int channelNumber);
	struct Channel* changeChannel(char* direction);
	std::string toString(struct Channel *channel);
	void toString();
	void findNewIndex(struct Channel *channel);
private:
	int size;
	int currentChannel;
	int lastAddedIndex;
	struct Channel *channels[MAX_CHANNELS];
	void sort();
	int checkForDupes(struct Channel *channel);
};

#endif /* ChannelArrayList_HPP_ */
