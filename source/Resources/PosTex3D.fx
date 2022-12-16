//-------
//Global Variables
//-------
float4x4 gWorldViewProj : WorldViewProjection;

//-----
//	Input/Output structs
//--------
struct VS_INPUT
{
	float3 Position : POSITION;
	float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
	float4 Position : SV_POSITION;
	float3 uv : TEXCOORD;
};

//---------------
//	Vertex Shader
//---------------
VS_OUTPUT VS(VS_INPUT input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;
	output.Position = mul(float4(input.Position, 1.f), gWorldViewProj);
	output.uv = input.uv;
	return output;
}

//--------------
//	Pixel Shader
//-------------
float4 PS(VS_OUTPUT input) : SV_TARGET
{
	return float4(input.Color, 1.f);
}

//---------------
//	Technique
//--------------
technique11 DefaultTechnique
{
	pass P0
	{
		SetVertexShader( CompileShader(vs_5_0, VS() ) );
		SetGeometryShader( NULL );
		SetPixelShader( CompileShader( ps_5_0, PS() ) );
	}
}

