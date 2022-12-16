#include "pch.h"
#include "Mesh.h"
#include "Effect.h"
#include "EffectPosCol.h"
#include "EffectPosTex.h"
#include "Texture.h"
namespace dae
{
	Mesh::Mesh(ID3D11Device* pDevice, std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
		:m_pEffect{new EffectPosTex(pDevice, L"Resources/PosTex3D.fx")}
	{
		m_pDiffuse = Texture::LoadFromFile(pDevice, "Resources/uv_grid_2.png");
		m_pEffect->SetDiffuseMap(m_pDiffuse);
		m_pInputLayout = m_pEffect->CreateInputLayout(pDevice);

		//Create Vertex Buffer
		D3D11_BUFFER_DESC bd{};
		bd.Usage = D3D11_USAGE_IMMUTABLE;
		bd.ByteWidth = sizeof(Vertex) * static_cast<uint32_t>(vertices.size());
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0;
		bd.MiscFlags = 0;

		D3D11_SUBRESOURCE_DATA initData{};
		initData.pSysMem = vertices.data();

		HRESULT result = pDevice->CreateBuffer(&bd, &initData, &m_pVertexBuffer);
		if (FAILED(result))
		{
			std::wcout << L"Vertex Buffer creation failed!\n";
			return;
		}

		//Create Index Buffer
		m_NumIndices = static_cast<uint32_t>(indices.size());
		bd.Usage = D3D11_USAGE_IMMUTABLE;
		bd.ByteWidth = sizeof(uint32_t) * m_NumIndices;
		bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bd.CPUAccessFlags = 0;
		bd.MiscFlags = 0;
		initData.pSysMem = indices.data();
		
		result = pDevice->CreateBuffer(&bd, &initData, &m_pIndexBuffer);
		if (FAILED(result))
		{
			std::wcout << L"Index Buffer creation failed!\n";
			return;
		}
	}


	Mesh::~Mesh()
	{
		delete m_pEffect;
		m_pEffect = nullptr;

		delete m_pDiffuse;
		m_pDiffuse = nullptr;

		if (m_pIndexBuffer) m_pIndexBuffer->Release();		
		if (m_pVertexBuffer) m_pVertexBuffer->Release();		
		if (m_pInputLayout) m_pInputLayout->Release();		
	}
	void Mesh::Render(ID3D11DeviceContext* pDeviceContext) const
	{
		//1. Set Primitive Topology
		pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//2. Set Input Layout
		pDeviceContext->IASetInputLayout(m_pInputLayout);

		//3. Set Vertex Buffer
		constexpr UINT stride = sizeof(Vertex);
		constexpr UINT offset = 0;
		pDeviceContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);

		//4. Set IndexBuffer
		pDeviceContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

		//5. Draw
		D3DX11_TECHNIQUE_DESC techDesc{};
		m_pEffect->GetTechnique()->GetDesc(&techDesc);

		for (UINT p{ 0 }; p < techDesc.Passes; ++p)
		{
			m_pEffect->GetTechnique()->GetPassByIndex(p)->Apply(0, pDeviceContext);
			pDeviceContext->DrawIndexed(m_NumIndices, 0, 0);
		}
	}
	void Mesh::SetMatrix(const Matrix& matrix)
	{
		m_pEffect->SetMatrix(matrix);
	}
}