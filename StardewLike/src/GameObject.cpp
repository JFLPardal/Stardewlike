#include "pch.h"
#include "GameObject.h"

#include "Components/SpriteRenderer.h"

GameObject::~GameObject()
{
	//delete m_renderer;
	printf("destroyed GO\n");
}

void GameObject::Start()
{
	for (auto& component : m_componentList)
	{
		component->Start();
	}
	m_renderer = GetComponent<SpriteRenderer>();
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
