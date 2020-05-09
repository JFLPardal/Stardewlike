#include "pch.h"
#include "Animator.h"

#include "GameObject.h"
#include "Orientation.h"

void Animator::Start()
{
	m_orientation = m_owner->GetComponent<Orientation>();
	// subscribe to StateMachine's ChangedStateEvent
	m_StateChangedIndex = m_owner->GetStateMachine()->OnStateChangeEvent->AddCallback(ON_STATE_CHANGE(&Animator::UpdateCurrentAnimation));
}

void Animator::UpdateCurrentAnimation(State aNewState)
{
	if(m_orientation != nullptr)
		m_currentAnimation = m_owner->GetData()->GetAnimationState(aNewState, m_orientation->GetOrientation());
	else
		m_currentAnimation = m_owner->GetData()->GetAnimationState(aNewState);
	
	m_currentIndex = 0;
	m_currentRect = sf::IntRect(m_currentAnimation.at(m_currentIndex), sf::Vector2i(TILE_W, TILE_H));
}

Animator::~Animator()
{
	m_owner->GetStateMachine()->OnStateChangeEvent->RemoveCallback(m_StateChangedIndex);
	printf("destroyed transform\n");
}
