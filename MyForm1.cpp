#include "MyForm1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ argv)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    laba42::MyForm1 form;
    Application::Run(% form);
}