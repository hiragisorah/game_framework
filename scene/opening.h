#pragma once

#include <scene.h>
#include <graphics\d3d11_model.h>
#include <game_object\sample_object.h>
#include <component\camera.h>

namespace Scene
{
	class Opening : public IScene<ID3D11Model>
	{
	public:
		Opening(void)
		{
			this->Add<Component::Camera>();
			this->Create<SampleObject>();
		}
	};
}