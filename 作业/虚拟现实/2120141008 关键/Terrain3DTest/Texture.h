// Texture.h: interface for the Texture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTURE_H__98316D04_4713_4B20_B2C7_647D2861F87E__INCLUDED_)
#define AFX_TEXTURE_H__98316D04_4713_4B20_B2C7_647D2861F87E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Texture  
{
public:
	Texture();
	virtual ~Texture();

	AUX_RGBImageRec *LoadBMP(const char *Filename);						// Loads A Bitmap Image
	GLuint LoadGLTexture( const char *filename );						// Load Bitmaps And Convert To Textures
	int LoadGLTextures();	
};

#endif // !defined(AFX_TEXTURE_H__98316D04_4713_4B20_B2C7_647D2861F87E__INCLUDED_)
