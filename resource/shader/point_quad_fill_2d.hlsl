cbuffer global
{
    matrix g_w : packoffset(c0);

    float2 g_viewport : packoffset(c4);

    float2 g_size : packoffset(c5);

    float4 g_color : packoffset(c6);
};

struct GS_INPUT
{
    float4 pos_ : SV_POSITION;
};

struct PS_INPUT
{
    float4 pos_ : SV_POSITION;
};

GS_INPUT VS(float4 pos : POSITION)
{
    GS_INPUT output;
    output.pos_ = pos;
    return output;
}

[maxvertexcount(4)]
void GS(point GS_INPUT input[1], inout TriangleStream<PS_INPUT> tri_stream)
{
    float w = 0;

    PS_INPUT p = (PS_INPUT) 0;

    p.pos_ = input[0].pos_ + float4(-g_size.x, +g_size.y, 0.f, 0.f) * .5f;
    p.pos_ = mul(p.pos_, transpose(g_w));
    p.pos_.x = (p.pos_.x / g_viewport.x) * 2;
    p.pos_.y = (p.pos_.y / g_viewport.y) * 2;
    w = p.pos_.w;
    tri_stream.Append(p);

    p.pos_ = input[0].pos_ + float4(+g_size.x, +g_size.y, 0.f, 0.f) * .5f;
    p.pos_ = mul(p.pos_, transpose(g_w));
    p.pos_.x = (p.pos_.x / g_viewport.x) * 2;
    p.pos_.y = (p.pos_.y / g_viewport.y) * 2;
    p.pos_.w = w;
    tri_stream.Append(p);
    
    p.pos_ = input[0].pos_ + float4(-g_size.x, -g_size.y, 0.f, 0.f) * .5f;
    p.pos_ = mul(p.pos_, transpose(g_w));
    p.pos_.x = (p.pos_.x / g_viewport.x) * 2;
    p.pos_.y = (p.pos_.y / g_viewport.y) * 2;
    p.pos_.w = w;
    tri_stream.Append(p);
    
    p.pos_ = input[0].pos_ + float4(+g_size.x, -g_size.y, 0.f, 0.f) * .5f;
    p.pos_ = mul(p.pos_, transpose(g_w));
    p.pos_.x = (p.pos_.x / g_viewport.x) * 2;
    p.pos_.y = (p.pos_.y / g_viewport.y) * 2;
    p.pos_.w = w;
    tri_stream.Append(p);

    tri_stream.RestartStrip();
}

float4 PS(PS_INPUT input) : SV_Target
{
	return float4(1,1,1,1);
    return g_color;
}