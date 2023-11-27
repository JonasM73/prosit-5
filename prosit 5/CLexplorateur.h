//CLexplorateur.h

#pragma once

using namespace System::IO;
using namespace System;

namespace NS_composants
{
	ref class CLfichier
	{
	public:
		//ajout d'un ^
		array<String^>^ explorerUnDossier(String^);
		void effacer(String^);
		void copier(String^, String^);
	};
}
