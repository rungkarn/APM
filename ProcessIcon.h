#pragma once
#using <System.dll>
#using <System.Windows.Forms.dll>

#include "workerThread.h"
namespace APM {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;

public ref class ProcessIcon :	public IDisposable
{
	private:
		// The NotifyIcon object.
		NotifyIcon^ m_ni;
		workerThread* m_motionDetectionThread;

	public:
		ProcessIcon(void);
		~ProcessIcon(void);
		void Display();
		void m_ni_MouseClick(Object^ sender, MouseEventArgs^ e);
	
};

}
