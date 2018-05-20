#include "Texture.h"


Texture::Texture(const char* filepath,D3DCOLOR transColor)
{
	Init(filepath,transColor);
}

void Texture::Init(const char* filepath, D3DCOLOR transColor)
{
	direction = DIR_LEFT;
	HRESULT result;
	D3DXIMAGE_INFO info;
	result = D3DXGetImageInfoFromFileA(filepath, &info);
	Width = info.Width;
	Height = info.Height;
	if (result != D3D_OK)
		return;

	result = D3DXCreateTextureFromFileExA(
		DirectXTool::getInstance()->GetDevice(),
		filepath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transColor,
		&info,
		NULL,
		&m_image);

	if (result != D3D_OK)
		return;
}


void Texture::RenderTexture(int x, int y, RECT *r)
{
	DirectXTool::getInstance()->GetSprite()->Draw(m_image,
	r,
	&D3DXVECTOR3(anchorPoint.X,anchorPoint.Y,0),
	&D3DXVECTOR3(x,y,0),
	D3DCOLOR_XRGB(255, 255,255));
}




Texture::~Texture()
{
	if (m_image)
	{
		m_image->Release();
		m_image = 0;
	}

}
