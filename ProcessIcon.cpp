//#include "StdAfx.h"
#include "ProcessIcon.h"
#include "ContextMenus.h"


namespace APM {

ProcessIcon::ProcessIcon(void)
{
	// Instantiate the NotifyIcon object.
	m_ni = gcnew NotifyIcon();
	m_motionDetectionThread = nullptr;
	m_motionDetectionThread = new workerThread();
	m_motionDetectionThread->runMotionDetThread();
}


ProcessIcon::~ProcessIcon(void)
{
	m_ni->~NotifyIcon();
	m_motionDetectionThread->RequestStop();
	if(m_motionDetectionThread!=nullptr)
	{
				delete m_motionDetectionThread;
				m_motionDetectionThread = nullptr;
	}
}

void ProcessIcon::Display()
{
	// Put the icon in the system tray and allow it react to mouse clicks.			
	m_ni->MouseClick += gcnew MouseEventHandler(this,&ProcessIcon::m_ni_MouseClick);

		//item->Click += gcnew System::EventHandler(this,&ContextMenus::Exit_Click);  //when to
	m_ni->Icon = gcnew System::Drawing::Icon(L"engy.ico");
	m_ni->Text = "Energy Saving System";
	m_ni->Visible = true;

	// Attach a context menu.
	ContextMenus^ x;
	x = gcnew ContextMenus();
	m_ni->ContextMenuStrip = x->Create(m_motionDetectionThread);
    // fat test

		
}

void ProcessIcon::m_ni_MouseClick(Object^ sender, MouseEventArgs^ e)
		{
			// Handle mouse button clicks.
			if (e->Button == MouseButtons::Left)
			{
				// Start Windows Explorer.
				//Process.Start("explorer", null);
				m_ni->ContextMenuStrip->Show();
			}
		}

}
