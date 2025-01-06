////////////////////////////////////////////////////////////////////////////////
// Filename: textureclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "textureclass.h"


TextureClass::TextureClass()
{
	m_texture = 0;
}


TextureClass::TextureClass(const TextureClass& other)
{
}


TextureClass::~TextureClass()
{
}





bool TextureClass::Initialize(ID3D11Device* device, WCHAR* filename)
{
	HRESULT result;	
	DirectX::TexMetadata metadata1;
	DirectX::ScratchImage scratchImage;
	result = DirectX::LoadFromDDSFile(filename, DirectX::DDS_FLAGS_NONE, &metadata1, scratchImage);
	if (FAILED(result))
	{
		return false;
	}
	// Load the texture in.	
	result = DirectX::CreateShaderResourceView(device, scratchImage.GetImages(), scratchImage.GetImageCount(), metadata1, &m_texture);
	if(FAILED(result))
	{
		return false;
	}
	return true;
}


void TextureClass::Shutdown()
{
	// Release the texture resource.
	if(m_texture)
	{
		m_texture->Release();
		m_texture = 0;
	}

	return;
}


ID3D11ShaderResourceView* TextureClass::GetTexture()
{
	return m_texture;
}