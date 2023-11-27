#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int __clrcall main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    prosit5::MyForm monFormulaire; // Assurez-vous d'utiliser le bon nom d'espace de noms ici
    Application::Run(% monFormulaire);

    return 0;
}