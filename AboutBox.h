#pragma once
#include "resource.h"
namespace APM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutBox
	/// </summary>
	public ref class AboutBox : public System::Windows::Forms::Form
	{
	public:
		AboutBox(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  m_btnOK;
	protected: 
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Label^  m_lblProductName;
	private: System::Windows::Forms::Label^  m_lblCompanyName;
	private: System::Windows::Forms::Label^  m_lblCopyright;
	private: System::Windows::Forms::Label^  m_lblVerName;
	private: System::Windows::Forms::TextBox^  m_txtBoxDesc;


	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutBox::typeid));
			this->m_btnOK = (gcnew System::Windows::Forms::Button());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->m_lblCompanyName = (gcnew System::Windows::Forms::Label());
			this->m_lblCopyright = (gcnew System::Windows::Forms::Label());
			this->m_lblProductName = (gcnew System::Windows::Forms::Label());
			this->m_lblVerName = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->m_txtBoxDesc = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// m_btnOK
			// 
			this->m_btnOK->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->m_btnOK->Location = System::Drawing::Point(226, 226);
			this->m_btnOK->Name = L"m_btnOK";
			this->m_btnOK->Size = System::Drawing::Size(75, 23);
			this->m_btnOK->TabIndex = 0;
			this->m_btnOK->Text = L"&OK";
			this->m_btnOK->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point(0, 2);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->splitContainer1->Panel1->Controls->Add(this->m_lblCompanyName);
			this->splitContainer1->Panel1->Controls->Add(this->m_lblCopyright);
			this->splitContainer1->Panel1->Controls->Add(this->m_lblProductName);
			this->splitContainer1->Panel1->Controls->Add(this->m_lblVerName);
			this->splitContainer1->Panel1->Controls->Add(this->pictureBox1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->splitContainer1->Panel2->Controls->Add(this->m_txtBoxDesc);
			this->splitContainer1->Size = System::Drawing::Size(313, 217);
			this->splitContainer1->SplitterDistance = 94;
			this->splitContainer1->TabIndex = 1;
			// 
			// m_lblCompanyName
			// 
			this->m_lblCompanyName->AutoSize = true;
			this->m_lblCompanyName->Location = System::Drawing::Point(101, 69);
			this->m_lblCompanyName->Name = L"m_lblCompanyName";
			this->m_lblCompanyName->Size = System::Drawing::Size(82, 13);
			this->m_lblCompanyName->TabIndex = 4;
			this->m_lblCompanyName->Text = L"Nectec NSTDA";
			// 
			// m_lblCopyright
			// 
			this->m_lblCopyright->AutoSize = true;
			this->m_lblCopyright->Location = System::Drawing::Point(101, 49);
			this->m_lblCopyright->Name = L"m_lblCopyright";
			this->m_lblCopyright->Size = System::Drawing::Size(187, 13);
			this->m_lblCopyright->TabIndex = 3;
			this->m_lblCopyright->Text = L"Copyright © 2013. All Rights reserved.";
			// 
			// m_lblProductName
			// 
			this->m_lblProductName->AutoSize = true;
			this->m_lblProductName->Location = System::Drawing::Point(101, 10);
			this->m_lblProductName->Name = L"m_lblProductName";
			this->m_lblProductName->Size = System::Drawing::Size(31, 13);
			this->m_lblProductName->TabIndex = 1;
			this->m_lblProductName->Text = L"Engy";
			// 
			// m_lblVerName
			// 
			this->m_lblVerName->AutoSize = true;
			this->m_lblVerName->Location = System::Drawing::Point(101, 30);
			this->m_lblVerName->Name = L"m_lblVerName";
			this->m_lblVerName->Size = System::Drawing::Size(78, 13);
			this->m_lblVerName->TabIndex = 2;
			this->m_lblVerName->Text = L"Version 1.0.0.0";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(88, 63);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// m_txtBoxDesc
			// 
			this->m_txtBoxDesc->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->m_txtBoxDesc->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->m_txtBoxDesc->Location = System::Drawing::Point(22, 13);
			this->m_txtBoxDesc->Multiline = true;
			this->m_txtBoxDesc->Name = L"m_txtBoxDesc";
			this->m_txtBoxDesc->Size = System::Drawing::Size(279, 91);
			this->m_txtBoxDesc->TabIndex = 0;
			this->m_txtBoxDesc->Text = L"Engy Application help to save energy by monitoring motion via webcam";
			// 
			// AboutBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(313, 257);
			this->Controls->Add(this->m_btnOK);
			this->Controls->Add(this->splitContainer1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutBox";
			this->Padding = System::Windows::Forms::Padding(9);
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"About Engy";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion



};
}
