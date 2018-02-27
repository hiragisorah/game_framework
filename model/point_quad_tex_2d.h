#pragma once

#include <scene.h>
#include <graphics\d3d11_model.h>

#include <vertex_buffer\one_point.h>
#include <shader\point_quad_tex_2d.h>

#include <component\movement.h>
#include <component\transform.h>
#include <component\camera.h>

namespace Model
{
	namespace Point
	{
		namespace Quad
		{
			class Tex2D : public D3D11Model<VertexBuffer::OnePoint, Shader::Point::Quad::Tex2D>
			{
			public:
				Tex2D(IScene<ID3D11Model> * parent) : D3D11Model(parent)
				{
					{// コンポーネント追加
						this->Add<Component::Transform2D>();
					}

					{//ステート設定
						this->SetBlendState(BLEND_STATE::ALPHA);
					}
				}

			public:

			public:
				virtual void Adjust(void) override
				{
					if (this->Texture(0))
					{
						this->constant_buffer_.split_ = this->Texture(0)->split_;
						this->constant_buffer_.size_ = this->Texture(0)->size_;
					}
					this->constant_buffer_.w_ = this->Get<Component::Transform2D>()->GetMatrix();
				}
			};
		}
	}
}