#include "ContextMenus.h"

namespace Engy {

using namespace System::Windows::Forms;

ContextMenuStrip^ ContextMenus::Create()
		{
			// Add the default menu options.
			ContextMenuStrip^ menu = gcnew ContextMenuStrip();
			ToolStripMenuItem^ item;
			ToolStripSeparator^ sep;

			// Windows Explorer.
			item = gcnew ToolStripMenuItem();
			item->Text = "Explorer";
			item->Click += gcnew System::EventHandler(this,&ContextMenus::Explorer_Click);  //when to add 'ref' before class ContextMenus, the error disappear
			//item->Image = Resources.Explorer;
			menu->Items->Add(item);
			//menu->Items->Add( <System::Windows::Forms::ToolStripItem^> item);  //(ToolStripItem^)
			return menu;

		}
}