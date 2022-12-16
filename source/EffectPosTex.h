#pragma once
#include "Effect.h"

namespace dae
{
	class EffectPosTex final : public Effect
	{
	public:

		EffectPosTex(ID3D11Device* pDevice, const std::wstring& assetFile);
		virtual ~EffectPosTex() = default;
		EffectPosTex(const EffectPosTex&) = delete;
		EffectPosTex(EffectPosTex&&) noexcept = delete;
		EffectPosTex& operator=(const EffectPosTex&) = delete;
		EffectPosTex& operator=(EffectPosTex&&) noexcept = delete;

		virtual ID3D11InputLayout* CreateInputLayout(ID3D11Device* pDevice) const;
	};
}
