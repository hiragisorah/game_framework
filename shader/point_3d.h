#pragma once

#include <graphics\d3d11_shader.h>
#include <d3dx10.h>

namespace Shader
{
	class Point3D : public D3D11Shader
	{
	public:
		struct CB
		{
			ALIGN16 D3DXMATRIX w_;
			ALIGN16 D3DXMATRIX v_;
			ALIGN16 D3DXMATRIX p_;
		};
	public:
		Point3D(void) : D3D11Shader("point_3d"_hlsl)
		{
			D3D11_INPUT_ELEMENT_DESC layout = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 };
			this->element_desc_.emplace_back(layout);
		}
	};
}