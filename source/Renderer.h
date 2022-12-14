#pragma once
#include "Camera.h"


struct SDL_Window;
struct SDL_Surface;

namespace dae
{
	enum class SampleState
	{
		POINT,
		LINEAR,
		ANISOTROPIC,
		//Define samplestates above

		COUNT
	};

	class Mesh;
	class Texture;
	class Renderer final
	{
	public:
		Renderer(SDL_Window* pWindow);
		~Renderer();

		Renderer(const Renderer&) = delete;
		Renderer(Renderer&&) noexcept = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&&) noexcept = delete;

		void Update(const Timer* pTimer);
		void Render() const;

		void CycleSampleState();

	private:
		SDL_Window* m_pWindow{};

		int m_Width{};
		int m_Height{};

		float m_AspectRatio{};

		bool m_IsInitialized{ false };

		std::vector<Mesh*> m_Meshes{ };
		Camera m_Camera{};

		SampleState m_SamplerState{ SampleState::POINT };

		//DIRECTX
		HRESULT InitializeDirectX();
		ID3D11Device* m_pDevice;
		ID3D11DeviceContext* m_pDeviceContext;
		IDXGISwapChain* m_pSwapChain;

		ID3D11Texture2D* m_pDepthStencilBuffer;
		ID3D11DepthStencilView* m_pDepthStencilView;

		ID3D11Resource* m_pRenderTargetBuffer;
		ID3D11RenderTargetView* m_pRenderTargetView;

		ID3D11SamplerState* m_pSamplerState{ nullptr };
		//...

		const float m_RotationSpeed{ TO_RADIANS * 45.f };

		Texture* m_pDiffuse{ nullptr };
		Texture* m_pNormal{ nullptr };
		Texture* m_pSpecular{ nullptr };
		Texture* m_pGlossiness{ nullptr };
	};
}
