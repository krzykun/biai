#include "MainForm.h"

#pragma once
namespace biai {

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	MainForm::MainForm(void)
	{
		InitializeComponent();
		this->initializeChart();
		//
		//TODO: Add the constructor code here
		//
	}
}