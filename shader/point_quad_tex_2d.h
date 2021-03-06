#pragma once

#include <graphics\d3d11_shader.h>
#include <d3dx10.h>

namespace Shader
{
	namespace Point
	{
		namespace Quad
		{
			class Tex2D : public D3D11Shader
			{
			public:
				struct CB
				{
					ALIGN16 D3DXMATRIX w_;

					ALIGN16 D3DXVECTOR2 view_port_ = { 1280.f, 720.f };

					ALIGN16 D3DXVECTOR2 size_ = { 1.f, 1.f };
					ALIGN16 D3DXVECTOR2 split_ = { 1.f, 1.f };

					ALIGN16 float pattern_ = 0.f;

					ALIGN16 D3DXCOLOR color_ = { 1.f, 1.f, 1.f, 1.f };
				};
			public:
				Tex2D(void) : D3D11Shader("point_quad_tex_2d"_hlsl)
				{
					D3D11_INPUT_ELEMENT_DESC layout = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 };
					this->element_desc_.emplace_back(layout);
				}
			};
		}
	}
}