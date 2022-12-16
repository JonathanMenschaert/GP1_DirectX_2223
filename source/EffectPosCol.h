#pragma once
#include "Effect.h"
namespace dae
{
    class EffectPosCol final : public Effect
    {
	public:
		EffectPosCol(ID3D11Device* pDevice, const std::wstring& assetFile);
		virtual ~EffectPosCol() = default;
		EffectPosCol(const EffectPosCol&) = delete;
		EffectPosCol(EffectPosCol&&) noexcept = delete;
		EffectPosCol& operator=(const EffectPosCol&) = delete;
		EffectPosCol& operator=(EffectPosCol&&) noexcept = delete;

		virtual ID3D11InputLayout* CreateInputLayout(ID3D11Device* pDevice) const;
    };
}

