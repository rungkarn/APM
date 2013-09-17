#include <windows.h>
#include "resource.h"
#include "AboutBox.h"
#include "workerThread.h"
#include "Form1.h"

#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

	

namespace APM {	
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	public ref class ContextMenus
	{
		/// Is the About box displayed?
	private:
		bool m_isAboutLoaded;// = false;
		workerThread* m_motionDetectionThread;
		unsigned char m_chkModifyParam; //(Option Form) check for parameter change 11111 = 63
		/// Creates this instance.
		
	public: ContextMenuStrip^ Create(workerThread* pmotionDetectionThread){
			m_isAboutLoaded = false;
		  

			//pointer to motion Detection Thread
			m_motionDetectionThread = pmotionDetectionThread;
			// Add the default menu options.
			ContextMenuStrip^ menu = gcnew ContextMenuStrip();
			ToolStripMenuItem^ item;
			ToolStripSeparator^ sep;


			// Options.
			item = gcnew ToolStripMenuItem();
			item->Text = gcnew System::String("Options");
			item->Click += gcnew System::EventHandler(this,&ContextMenus::Option_Click);  //when to add 'ref' before class ContextMenus, the error disappear
			
			System::Drawing::Image ^jpeg;
			jpeg = getImageFromRes(IDB_PNG3);
			if(jpeg != nullptr)
			{
				item->Image = jpeg;
			}
			menu->Items->Add(item);

			

			// About.
			item = gcnew ToolStripMenuItem();
			item->Text = gcnew System::String("About");
			item->Click += gcnew System::EventHandler(this,&ContextMenus::About_Click);  //when to add 'ref' before class ContextMenus, the error disappear
			
			
			jpeg = getImageFromRes(IDB_PNG1);
			if(jpeg != nullptr)
			{
				item->Image = jpeg;
			}
			menu->Items->Add(item);


			// Separator.
			sep = gcnew ToolStripSeparator();
			menu->Items->Add(sep);

			// Exit.
			item = gcnew ToolStripMenuItem();
			item->Text = gcnew System::String("Exit");
			item->Click += gcnew System::EventHandler(this,&ContextMenus::Exit_Click);  //when to add 'ref' before class ContextMenus, the error disappear
			//item->Image = Resources.Explorer;

			//System::Drawing::Image ^jpeg;
			jpeg = getImageFromRes(IDB_PNG2);
			if(jpeg != nullptr)
			{
				item->Image = jpeg;
			}
			menu->Items->Add(item);
			return menu;
			}

			//---------------------------------------------------------------------------
			//Name: getImageFromRes
			//Des: A function for loads jpeg images from resources in C++/CLI 
			//---------------------------------------------------------------------------
	public:	Image ^ getImageFromRes(long resource_ID)
		{

			//Load the resource module:
			HMODULE module = GetModuleHandle(0);
			
			//Find the resource using the resource ID from file "resource.rh"
			HRSRC rsrc = FindResource(module, MAKEINTRESOURCE(resource_ID),L"PNG");//RT_RCDATA);
			if(!rsrc)
			{
				return nullptr;		
			}
    
			// Load the resource and save the total size.
			DWORD Size = SizeofResource(module , rsrc);	       	
			HGLOBAL MemoryHandle = LoadResource(module,rsrc);
			if(MemoryHandle == NULL)
			{
			   return nullptr;
			}
    
			//Create a cli::array of byte with size = total size + 2
			cli::array<BYTE> ^MemPtr = gcnew array<BYTE>(Size + 2);
	
			//Cast from LPVOID to char * 
			char *lkr = (char *)(LockResource(MemoryHandle));
	  
			//Copy from unmanaged memory to managed array
			Marshal::Copy((IntPtr)lkr,MemPtr, 0, Size);

			// Create a new MemoryStream with size = MemPtr  
			System::IO::MemoryStream ^stream = gcnew System::IO::MemoryStream(MemPtr);
      
			//Write in the MemoryStream
			stream->Write(MemPtr,0,Size);
      
			//Set the position for read the stream
			stream->Position = 0;

			//Create an Image abstract class pointer						
			System::Drawing::Image ^ptrJpg;  
      
			//Assign the stream to abstract class pointer
			ptrJpg = System::Drawing::Image::FromStream(stream);
			
			return  ptrJpg;

		}
			
	private: System::Void Option_Click(Object^ Sender, EventArgs^ e) {
			OptionForm^ optionForm;
			
			cli::pin_ptr<unsigned char> pchkModifyParam = &m_chkModifyParam;
			optionForm = gcnew OptionForm( m_motionDetectionThread->m_strIniFileName,static_cast<unsigned char*>(pchkModifyParam));
			if(optionForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//there are modified parameter in options Form
			    m_motionDetectionThread->updateParamFromINIFile(pchkModifyParam);
				
			}
   
		}

	private: System::Void Exit_Click(Object^ Sender, EventArgs^ e) {
				 Application::Exit();
   
		}
	private: System::Void About_Click(Object^ Sender, EventArgs^ e) {
			if (!m_isAboutLoaded)
			{
				m_isAboutLoaded = true;
				APM::AboutBox^ aboutForm = gcnew AboutBox();
				aboutForm->ShowDialog();
				m_isAboutLoaded = false;
			}
   
		}

	};

}