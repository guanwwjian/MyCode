// MilkShapeModel.h: interface for the MilkShapeModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILKSHAPEMODEL_H__024F9E98_A01C_4D53_8A52_E656BFCBF341__INCLUDED_)
#define AFX_MILKSHAPEMODEL_H__024F9E98_A01C_4D53_8A52_E656BFCBF341__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Model.h"

class MilkShapeModel : public Model  
{
public:
	MilkShapeModel();
	virtual ~MilkShapeModel();

		/*	
			Load the model data into the private variables. 
				filename			Model filename
		*/
		virtual bool loadModelData( const char *filename );
};

#endif // !defined(AFX_MILKSHAPEMODEL_H__024F9E98_A01C_4D53_8A52_E656BFCBF341__INCLUDED_)
