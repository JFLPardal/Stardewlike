#include "GameObject.h"
#include "Components/SpriteRenderer.h"

void GameObject::Start()
{
	for (auto& component : m_componentList)
	{
		component->Start();
	}
	m_renderer = GetComponent<SpriteRenderer>();
	if (m_renderer) m_isDrawable = true;
}

void GameObject::Update()
{
	for (auto& component : m_componentList)
	{
		component->Update();
	}
}
/*
// draw should only be called if the GO has a SpriteRenderer component. In future, this component should be a drawbleComponent, to include p.e. text drawing
void GameObject::Draw()
{
	if (m_isDrawable) m_renderer->Draw();
}*/
