#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Thing
{
public:
	virtual void drow(Graphics^ g) = 0;
	virtual void select() = 0;
	virtual void unselect() = 0;
	virtual bool reach(int x, int y) = 0;
	virtual bool is_select() = 0;
};