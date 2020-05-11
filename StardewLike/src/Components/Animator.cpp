#include "pch.h"
#include "Animator.h"

#include "GameObject.h"
#include "Orientation.h"

void Animator::Start()
{
	m_orientation = m_owner->GetComponent<Orientation>();
	m_StateChangedIndex = m_owner->GetStateMachine()->OnStateChangeEvent->AddCallback(ON_STATE_CHANGE(&Animator::UpdateCurrentAnimation));
}

const SpriteSheetTile& Animator::GetSpriteSheetTileToDraw() const
{ 
	return SpriteSheetTile{ m_currentAnimation.CurrentSpriteSheetRect(), std::move(Vector2i(32,32)) };
}


void Animator::UpdateCurrentAnimation(State aNewState)
{
	bool thisGameObjectHasOrientation = m_orientation != nullptr;
	auto thisGameObjectData = m_owner->GetData();

	if (thisGameObjectHasOrientation)
		m_currentAnimation.SetNewAnimation(thisGameObjectData->GetAnimationState(aNewState, m_orientation->GetOrientation()));
	else
		m_currentAnimation.SetNewAnimation(thisGameObjectData->GetAnimationState(aNewState));
}

Animator::~Animator()
{
	m_owner->GetStateMachine()->OnStateChangeEvent->RemoveCallback(m_StateChangedIndex);
	printf("destroyed transform\n");
}
