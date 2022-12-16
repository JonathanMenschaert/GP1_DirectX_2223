#include "pch.h"
#include "EffectPosTex.h"

namespace dae
{
    EffectPosTex::EffectPosTex(ID3D11Device* pDevice, const std::wstring& assetFile)
        :Effect(pDevice, assetFile)
    {
    }

    ID3D11InputLayout* EffectPosTex::CreateInputLayout(ID3D11Device* pDevice) const
    {
        return nullptr;
    }
}
