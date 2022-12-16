#pragma once
#include "Effect.h"

namespace dae
{
	class Texture;
	class EffectPosTex final : public Effect
	{
	public:

		EffectPosTex(ID3D11Device* pDevice, const std::wstring& assetFile);
		virtual ~EffectPosTex();
		EffectPosTex(const EffectPosTex&) = delete;
		EffectPosTex(EffectPosTex&&) noexcept = delete;
		EffectPosTex& operator=(const EffectPosTex&) = delete;
		EffectPosTex& operator=(EffectPosTex&&) noexcept = delete;

		void SetDiffuseMap(Texture* pDiffuseTexture);

		virtual ID3D11InputLayout* CreateInputLayout(ID3D11Device* pDevice) const;

	private:
		ID3DX11EffectShaderResourceVariable* m_pDiffuseMapVar{ nullptr };
	};
}

