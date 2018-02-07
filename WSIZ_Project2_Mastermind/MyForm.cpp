#include "MyForm.h"

using namespace WSIZ_Project2_Mastermind;

[STAThread]
void Main(array<String^>^ args)
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);

  MyForm form;
  Application::Run(%form);
}

