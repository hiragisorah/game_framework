#pragma once

#include <model\point_quad_tex_2d.h>
#include <component\sample_event.h>

class SampleObject : public Model::Point::Quad::Tex2D
{
public:
	SampleObject(IScene<ID3D11Model> * parent) : Tex2D(parent)
	{
		{// �e�N�X�`���ݒ�
			this->SetTexture(0, "dragon_stay");
		}

		{// �R���|�[�l���g�̒ǉ�
			this->Add<Component::SampleEvent>();
		}
	}
};