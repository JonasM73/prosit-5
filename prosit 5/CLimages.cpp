//CLimages.cpp
#include "CLimages.h"
using namespace System;

namespace NS_composants
{
	Drawing::Bitmap^ CLimages::acquisitionImage(String^ fichier)
	{
		return gcnew Drawing::Bitmap(fichier);
	}
}
