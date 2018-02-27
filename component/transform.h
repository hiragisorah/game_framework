#pragma once

#pragma warning(disable: 4238)

#include <component.h>
#include <graphics\d3d11_model.h>

#include <d3dx10.h>

inline float ToRadian(float f)
{
	return f * (3.14159265358979323846f / 180.0f);
}

inline D3DXVECTOR2 ToRadian(D3DXVECTOR2 v2)
{
	D3DXVECTOR2 ret;
	ret.x = ToRadian(v2.x);
	ret.y = ToRadian(v2.y);
	return ret;
}

inline D3DXVECTOR3 ToRadian(D3DXVECTOR3 v3)
{
	D3DXVECTOR3 ret;
	ret.x = ToRadian(v3.x);
	ret.y = ToRadian(v3.y);
	ret.z = ToRadian(v3.z);
	return ret;
}

namespace Component
{
	class Transform : public IComponent<ID3D11Model>
	{
	public:
		Transform(ID3D11Model * parent) : IComponent(parent)
		{
			this->position_ = { 0.f, 0.f, 0.f };
			this->rotation_ = { 0.f, 0.f, 0.f };
			this->scale_ = { 1.f, 1.f, 1.f };
		}

	public:
		D3DXVECTOR3 position_;
		D3DXVECTOR3 rotation_;
		D3DXVECTOR3 scale_;

	public:
		D3DXVECTOR3 center_rotation_;
		D3DXVECTOR3 center_scale_;

	public:
		D3DXMATRIX GetMatrix(void)
		{
			D3DXMATRIX out;
			D3DXQUATERNION rot;
			D3DXQuaternionRotationYawPitchRoll(&rot, ToRadian(this->rotation_.y), ToRadian(this->rotation_.x), ToRadian(this->rotation_.z));
			D3DXMatrixTransformation(&out, &this->center_scale_, nullptr, &this->scale_, &ToRadian(this->center_rotation_), &rot, &this->position_);
			return out;
		}

	private:
		void Update(void) override {}
		void Pause(void) override {}
		void Always(void) override {}
	};
	class Transform2D : public IComponent<ID3D11Model>
	{
	public:
		Transform2D(ID3D11Model * parent) : IComponent(parent)
		{
			this->position_ = { 0.f, 0.f };
			this->rotation_ = 0.f;
			this->scale_ = { 1.f, 1.f };
			this->center_rotation_ = { 0.f, 0.f };
			this->center_scale_ = { 0.f, 0.f };
		}

	public:
		D3DXVECTOR2 position_;
		D3DXVECTOR2 scale_;
		float rotation_;

	public:
		D3DXVECTOR2 center_rotation_;
		D3DXVECTOR2 center_scale_;

	public:
		D3DXMATRIX GetMatrix(void)
		{
			D3DXMATRIX out;
			D3DXMatrixTransformation2D(&out, &this->center_scale_, 0.f, &this->scale_, &ToRadian(this->center_rotation_), ToRadian(this->rotation_), &this->position_);
			return out;
		}

	private:
		void Update(void) override {}
		void Pause(void) override {}
		void Always(void) override {}
	};
}