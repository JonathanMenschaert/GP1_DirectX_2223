#pragma once

namespace dae
{
	struct Vertex_PosCol final
	{
		Vector3 position;
		ColorRGB color;
	};


	class Effect;
	class Mesh final
	{
	public:
		Mesh(ID3D11Device* pDevice, std::vector<Vertex_PosCol>& vertices, std::vector<uint32_t>& indices);
		~Mesh();

		Mesh(const Mesh&) = delete;
		Mesh(Mesh&&) noexcept = delete;
		Mesh& operator=(const Mesh&) = delete;
		Mesh& operator=(Mesh&&) noexcept = delete;

		void Render(ID3D11DeviceContext* pDeviceContext) const;

	private:
		Effect* m_pEffect{ nullptr };
		ID3D11Buffer* m_pVertexBuffer{ nullptr };
		ID3D11Buffer* m_pIndexBuffer{ nullptr };
		ID3D11InputLayout* m_pInputLayout{ nullptr };

		uint32_t m_NumIndices{};
	};
}
