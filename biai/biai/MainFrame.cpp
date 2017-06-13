#include "Net.h"
#include "Neuron.h"
#include "TrainingData.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include "MainForm.h"

using namespace System::Windows::Forms;
using namespace std;

const bool isDebug = 1;

[System::STAThread]
void main()
{
	biai::MainForm mainForm;
	mainForm.ShowDialog();
}