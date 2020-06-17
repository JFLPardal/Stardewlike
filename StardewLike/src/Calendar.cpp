#include "pch.h"
#include "Calendar.h"

#include "InteractableTypes/Bed.h"

Calendar::Calendar(Bed* bed)
	: m_bed(bed)
{
	assert(bed != nullptr && "Calendar getting nullptr to Bed");
	m_DayOverIndex = bed->m_OnDayOverEvent->AddCallback(DAY_OVER(&Calendar::DayOver));
}

void Calendar::DayOver()
{
	printf("dayOver called\n");
}

Calendar::~Calendar()
{
	 m_bed->m_OnDayOverEvent->RemoveCallback(m_DayOverIndex);
}