Texture2D g_tex : register(t0);

SamplerState g_sampler : register(s0);

cbuffer global
{
    matrix g_w : packoffset(c0);

    float2 g_viewport : packoffset(c4);

    float2 g_size : packoffset(c5);
    float2 g_split : packoffset(c6);
    float g_pattern : packoffset(c7);

    float4 g_color : packoffset(c8);
};

struct GS_INPUT
{
    float4 pos_ : SV_POSITION;
};

struct PS_INPUT
{
    float4 pos_ : SV_POSITION;
    float2 uv_ : TEXCOORD;
};

GS_INPUT VS(float4 pos : POSITION)
{
    GS_INPUT output = (GS_INPUT) 0;
    output.pos_ = pos;
    return output;
}

[maxvertexcount(4)]
void GS(point GS_INPUT input[1], inout TriangleStream<PS_INPUT> tri_stream)
{
    float w = 0;

    int2 start = int2((int) g_pattern % (int) g_split.x, (int) g_pattern / (int) g_split.x);
    float2 size = float2(1.f / g_split.x, 1.f / g_split.y);

    PS_INPUT p = (PS_INPUT) 0;

    p.pos_ = input[0].pos_ + float4(-g_size.x, +g_size.y, 0.f, 0.f) * .5f;
    p.pos_ = mul(p.pos_, transpose(g_w));
    p.pos_.x = (p.pos_.x / g_viewport.x) * 2;
    p.pos_.y = (p.pos_.y / g_viewport.y) * 2;
    w = p.pos_.w;
    p.uv_ = (start + int2(0, 0)) * size;
    tri_stream.Append(p);

    p.pos_ = input[0].pos_ + float4(+g_size.x, +g_size.y, 0.f, 0.f) * .5f;
    p.pos_ = mul(p.pos_, transpose(g_w));
    p.pos_.x = (p.pos_.x / g_viewport.x) * 2;
    p.pos_.y = (p.pos_.y / g_viewport.y) * 2;
    p.pos_.w = w;
    p.uv_ = (start + int2(1, 0)) * size;
    tri_stream.Append(p);
    
    p.pos_ = input[0].pos_ + float4(-g_size.x, -g_size.y, 0.f, 0.f) * .5f;
    p.pos_ = mul(p.pos_, transpose(g_w));
    p.pos_.x = (p.pos_.x / g_viewport.x) * 2;
    p.pos_.y = (p.pos_.y / g_viewport.y) * 2;
    p.pos_.w = w;
    p.uv_ = (start + int2(0, 1)) * size;
    tri_stream.Append(p);
    
    p.pos_ = input[0].pos_ + float4(+g_size.x, -g_size.y, 0.f, 0.f) * .5f;
    p.pos_ = mul(p.pos_, transpose(g_w));
    p.pos_.x = (p.pos_.x / g_viewport.x) * 2;
    p.pos_.y = (p.pos_.y / g_viewport.y) * 2;
    p.pos_.w = w;
    p.uv_ = (start + int2(1, 1)) * size;
    tri_stream.Append(p);

    tri_stream.RestartStrip();
}

float4 PS(PS_INPUT input) : SV_Target
{
    return g_tex.Sample(g_sampler, input.uv_) * g_color;
}