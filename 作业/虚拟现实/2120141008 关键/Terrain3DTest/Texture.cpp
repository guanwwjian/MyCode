// Texture.cpp: implementation of the Texture class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Terrain3DTest.h"
#include "Texture.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern GLuint texturem ;
extern GLuint	texture[8];
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Texture::Texture()
{

}

Texture::~Texture()
{

}

AUX_RGBImageRec *Texture::LoadBMP(const char *Filename)						// Loads A Bitmap Image
{
	FILE *File=NULL;												// File Handle

	if (!Filename)													// Make Sure A Filename Was Given
	{
		return NULL;												// If Not Return NULL
	}

	File=fopen(Filename,"r");										// Check To See If The File Exists

	if (File)														// Does The File Exist?
	{
		fclose(File);												// Close The Handle
		CString str = CString(Filename);
		USES_CONVERSION;
		LPCWSTR wFilename = A2CW(W2A(str));
		str.ReleaseBuffer();
		return auxDIBImageLoad(wFilename);							// Load The Bitmap And Return A Pointer

	}

	return NULL;													// If Load Failed Return NULL
}


GLuint Texture::LoadGLTexture( const char *filename )						// Load Bitmaps And Convert To Textures
{
  bool Status=true;
	AUX_RGBImageRec *pImage;										// Create Storage Space For The Texture

	pImage = LoadBMP( filename );									// Loads The Bitmap Specified By filename

	// Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
	if ( pImage != NULL && pImage->data != NULL )					// If Texture Image Exists
	{
		glGenTextures(1, &texturem);									// Create The Texture

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texturem);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, pImage->sizeX, pImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pImage->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

		free(pImage->data);											// Free The Texture Image Memory
		free(pImage);												// Free The Image Structure
	}

  return Status;
}


int Texture::LoadGLTextures()									// Load Bitmap And Convert To A Texture
{
	int Status=FALSE;								// Status Indicator
  AUX_RGBImageRec *TextureImage[1];				// Create Storage Space For The Textures
  memset(TextureImage,0,sizeof(void *)*1);		// Set The Pointer To NULL

  if (TextureImage[0]=LoadBMP("texture/asphalt.bmp"))	// Load Particle Texture
  {
		Status=TRUE;								// Set The Status To TRUE
		glGenTextures(1, &texture[0]);				// Create One Texture
           
    // Create MipMapped Texture
    glBindTexture(GL_TEXTURE_2D, texture[0]);
	  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
	  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);           
  }
  
  if (TextureImage[0]=LoadBMP("texture/sky.bmp"))	// Load Particle Texture
  {
		Status=TRUE;								// Set The Status To TRUE
	  glGenTextures(1, &texture[1]);				// Create One Texture

		// Create MipMapped Texture
 		glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
   	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);           
  }

  if (TextureImage[0]=LoadBMP("texture/Lightmap_256x256.bmp"))	// Load Particle Texture
  {
	  Status=TRUE;								// Set The Status To TRUE
		glGenTextures(1, &texture[2]);				// Create One Texture
		
		// Create MipMapped Texture
 		glBindTexture(GL_TEXTURE_2D, texture[2]);
   	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
   	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);           
  }

  if (TextureImage[0]=LoadBMP("texture/Loading.bmp"))	// Load Particle Texture
  {
		Status=TRUE;								// Set The Status To TRUE
		glGenTextures(1, &texture[3]);				// Create One Texture

    // Create MipMapped Texture
    glBindTexture(GL_TEXTURE_2D, texture[3]);
	  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
	  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);           
  }

  if (TextureImage[0]=LoadBMP("texture/Water.bmp"))	// Load Particle Texture
  {
		Status=TRUE;								// Set The Status To TRUE
		glGenTextures(1, &texture[4]);				// Create One Texture

 		// Create MipMapped Texture
		glBindTexture(GL_TEXTURE_2D, texture[4]);
 		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
 		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);           
  }

  if (TextureImage[0]=LoadBMP("texture/nebula.bmp"))	// Load Particle Texture
  {
		Status=TRUE;								// Set The Status To TRUE
		glGenTextures(1, &texture[5]);				// Create One Texture

 		// Create MipMapped Texture
  	glBindTexture(GL_TEXTURE_2D, texture[5]);
 		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
 		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);           
  }

  if (TextureImage[0]=LoadBMP("texture/Water2.bmp"))	// Load Particle Texture
  {
		Status=TRUE;								// Set The Status To TRUE
		glGenTextures(1, &texture[6]);				// Create One Texture

  	// Create MipMapped Texture
  	glBindTexture(GL_TEXTURE_2D, texture[6]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);           
  }

  if (TextureImage[0])							// If Texture Exists
	{
		if (TextureImage[0]->data)					// If Texture Image Exists
		{
			free(TextureImage[0]->data);			// Free The Texture Image Memory
		}
		free(TextureImage[0]);						// Free The Image Structure
	}

  return Status;									// Return The Status
}
