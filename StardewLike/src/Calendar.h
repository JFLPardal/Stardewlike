#pragma once
#include "IEvent.h"

/*
	Calendar holds the time representation of the 
	days passing in game
*/

class Bed;

class Calendar
{
public:
	explicit Calendar(Bed* bed);
	~Calendar();
private:
	void DayOver();

	EventIndex m_DayOverIndex = -2;
	const Bed *const m_bed;
};