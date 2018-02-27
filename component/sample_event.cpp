#include "sample_event.h"
#include <component\transform.h>

Component::SampleEvent::SampleEvent(ID3D11Model * parent) : IComponent(parent)
{

}

void Component::SampleEvent::Update(void)
{
	this->Parent()->Get<Component::Transform2D>()->scale_.y += .01f;
	this->Parent()->Get<Component::Transform2D>()->position_.x += .1f;
	this->Parent()->Get<Component::Transform2D>()->rotation_ += 1.f;
}

void Component::SampleEvent::Pause(void)
{
}

void Component::SampleEvent::Always(void)
{
}
