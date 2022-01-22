#include "FocusDict.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Dictionary_pro::FocusDict form;
	Application::Run(% form);
}
