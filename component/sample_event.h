#pragma once

#include <graphics\d3d11_model.h>

namespace Component
{
	class SampleEvent : public IComponent<ID3D11Model>
	{
	public:
		SampleEvent(ID3D11Model * parent);

	public:
		void Update(void);
		void Pause(void);
		void Always(void);
	};
}