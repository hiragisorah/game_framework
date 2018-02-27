#pragma once

#include <scene.h>
#include <graphics\d3d11_model.h>

#include <vertex_buffer\one_point.h>
#include <shader\point_Quad_fill_2d.h>

#include <component\movement.h>
#include <component\transform.h>
#include <component\camera.h>

namespace Model
{
	namespace Point
	{
		namespace Quad
		{
			class Fill2D : public D3D11Model<VertexBuffer::OnePoint, Shader::Point::Quad::Fill2D>
			{
			public:
				Fill2D(IScene<ID3D11Model> * parent) : D3D11Model(parent)
				{
					this->Add<Component::Transform2D>();
				}

			public:
				virtual void Adjust(void) override
				{
					this->constant_buffer_.w_ = this->Get<Component::Transform2D>()->GetMatrix();
				}
			};
		}
	}
}