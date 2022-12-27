#pragma once
#include "Effect.h"
namespace dae
{
	class Texture;
	class EffectShader final : public Effect
	{
	public:

		EffectShader(ID3D11Device* pDevice, const std::wstring& assetFile);
		virtual ~EffectShader();
		EffectShader(const EffectShader&) = delete;
		EffectShader(EffectShader&&) noexcept = delete;
		EffectShader& operator=(const EffectShader&) = delete;
		EffectShader& operator=(EffectShader&&) noexcept = delete;

		void SetDiffuseMap(Texture* pDiffuseTexture);
		void SetNormalMap(Texture* pNormalTexture);
		void SetSpecularMap(Texture* pSpecularTexture);
		void SetGlossinessMap(Texture* pGlossinessTexture);

		virtual ID3D11InputLayout* CreateInputLayout(ID3D11Device* pDevice) const;

	private:
		ID3DX11EffectShaderResourceVariable* m_pDiffuseMapVar{ nullptr };
		ID3DX11EffectShaderResourceVariable* m_pNormalMapVar{ nullptr };
		ID3DX11EffectShaderResourceVariable* m_pSpecularMapVar{ nullptr };
		ID3DX11EffectShaderResourceVariable* m_pGlossinessMapVar{ nullptr };
	};
}

