// TransparentLabel.h

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace PathCreator {

	public ref class TransparentLabel : public System::Windows::Forms::Label {
	public:
		TransparentLabel() {
			SetStyle(ControlStyles::Opaque, true);
			SetStyle(ControlStyles::OptimizedDoubleBuffer, false);
		}

	protected:
		property System::Windows::Forms::CreateParams^ CreateParams {
			virtual System::Windows::Forms::CreateParams^ get() override {
				System::Windows::Forms::CreateParams^ parms = __super::CreateParams;
				parms->ExStyle |= 0x20;
				return parms;
			}
		}
	};

}