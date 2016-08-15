// Model.h: interface for the Model class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL_H__85D1D432_6220_4EB9_B6A2_12ECFC2B0E5D__INCLUDED_)
#define AFX_MODEL_H__85D1D432_6220_4EB9_B6A2_12ECFC2B0E5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Texture.h"
class Model  
{
public:
	//	Mesh
	struct Mesh
	{
		int m_materialIndex;
		int m_numTriangles;
		int *m_pTriangleIndices;
	};

	//	Material properties
	struct Material
	{
		GLfloat m_ambient[4], m_diffuse[4], m_specular[4], m_emissive[4];
		GLfloat m_shininess;
		GLuint m_texture;
		char *m_pTextureFilename;
	};

	//	Triangle structure
	struct Triangle
	{
		GLfloat m_vertexNormals[3][3];
		GLfloat m_s[3], m_t[3];
		int m_vertexIndices[3];
	};

	//	Vertex structure
	struct Vertex
	{
		char m_boneID;	// for skeletal animation
		GLfloat m_location[3];
	};

	Texture m_texture;
public:
	Model();
	virtual ~Model();

		/*	
			Load the model data into the private variables. 
				filename			Model filename
		*/
		virtual bool loadModelData( const char *filename ) = 0;

		/*
			Draw the model.
		*/
		void draw();
		/*
		    Make a display list from the model
        */
		GLuint makeDisplayList();

		/*
			Called if OpenGL context was lost and we need to reload textures, display lists, etc.
		*/
		void reloadTextures();

	protected:
		//	Meshes used
		int m_numMeshes;
		Mesh *m_pMeshes;

		//	Materials used
		int m_numMaterials;
		Material *m_pMaterials;

		//	Triangles used
		int m_numTriangles;
		Triangle *m_pTriangles;

		//	Vertices Used
		int m_numVertices;
		Vertex *m_pVertices;
};

#endif // !defined(AFX_MODEL_H__85D1D432_6220_4EB9_B6A2_12ECFC2B0E5D__INCLUDED_)
