//
// Game.h
//

#pragma once

#include "StepTimer.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game() noexcept;

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

	void CalculateFrameStats(DX::StepTimer const& timer);

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext;

    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	//
	const static int NUM_ELEMENTS = 64;

	Microsoft::WRL::ComPtr<ID3D11Buffer> m_inputBuffer;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_inputSRV;
	
	Microsoft::WRL::ComPtr<ID3D11Texture1D> m_outputBuffer;
	Microsoft::WRL::ComPtr<ID3D11Texture1D> m_outputTexture;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_outputUAV;

	Microsoft::WRL::ComPtr<ID3D11ComputeShader> m_csShader;
	
	
	// exercise 2
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_inputBuffer2;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_inputSRV2;
	Microsoft::WRL::ComPtr<ID3D11ComputeShader> m_csShader2;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_outputUAV2;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_outputBuffer2;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_outputBufferCPU;

	// exercise 3
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_inputBuffer3;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_outputBuffer3;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_inputUAV3;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_outputUAV3;
	Microsoft::WRL::ComPtr<ID3D11ComputeShader> m_csShader3;


	void DoComputeWork();
	void DoComputeWork_exercise_2();
	void DoComputeWork_exercise_3();
};