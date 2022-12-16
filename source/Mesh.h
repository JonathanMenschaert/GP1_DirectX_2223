#pragma once

namespace dae
{
	/*struct Vertex_PosCol final
	{
		Vector3 position;
		ColorRGB color;
	};*/

	struct Vertex final
	{
		Vector3 position;
		Vector2 uv;
	};

	class EffectPosCol;
	class EffectPosTex;
	class Texture;
	class Mesh final
	{
	public:
		Mesh(ID3D11Device* pDevice, std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
		~Mesh();

		Mesh(const Mesh&) = delete;
		Mesh(Mesh&&) noexcept = delete;
		Mesh& operator=(const Mesh&) = delete;
		Mesh& operator=(Mesh&&) noexcept = delete;

		void UpdateSampleState(ID3D11SamplerState* pSampleState);
		void RotateY(float angle);
		void Render(ID3D11DeviceContext* pDeviceContext) const;
		void SetMatrix(const Matrix& matrix);

	private:
		EffectPosTex* m_pEffect{ nullptr };
		ID3D11Buffer* m_pVertexBuffer{ nullptr };
		ID3D11Buffer* m_pIndexBuffer{ nullptr };
		ID3D11InputLayout* m_pInputLayout{ nullptr };

		uint32_t m_NumIndices{};
		Texture* m_pDiffuse{ nullptr };

		Matrix m_RotationMatrix{};
	};
}

