#include "InicioForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main()
{
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TRABAJOFINAL::InicioForm());
}