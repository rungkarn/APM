#include <fstream> // for fstream open file
#include <Windows.h>
#include "resource.h"

#define MAXSIZE 500

#pragma once


namespace APM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for OptionForm
	/// </summary>
	public ref class OptionForm : public System::Windows::Forms::Form
	{
	public:
		OptionForm(char* pstrIniFileName,unsigned char* chkModifyParam)
		{
			InitializeComponent();
			
			m_pstrIniFileName =  pstrIniFileName;

			//m_chKModifyParam ถ้าแก้ทั้งหมด 111111 (31)  
			//m_iCapEveryNSec:1 (00001);	m_iThresDiff:2 (00010); m_iThresShutdownComputer:4 (00100); m_iThresBootComputer:8 (01000); m_iNumberOfDelay:16 (10000);
			m_chkModifyParam = chkModifyParam;
			*m_chkModifyParam = 0;  
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OptionForm()
		{
			if (components)
			{
				delete components;
			}
			// destroy the unmanaged icon 
			DestroyIcon(static_cast<HICON>(m_ptrIcon->Handle.ToPointer() ));

		}

	private:	unsigned char* m_chkModifyParam; //check for parameter change 11111 = 63
				char* m_pstrIniFileName;// ini file name

				System::Drawing::Icon ^m_ptrIcon;

	private: System::Windows::Forms::NumericUpDown^  m_upDownCapInterval;
	private: System::Windows::Forms::NumericUpDown^  m_upDownThresDiff;
	private: System::Windows::Forms::NumericUpDown^  m_upDownThresShutdown;
	private: System::Windows::Forms::NumericUpDown^  m_upDownThresBoot;
	private: System::Windows::Forms::NumericUpDown^  m_upDownTimeDelay;
	protected: 

	protected: 

	protected: 

	protected: 





	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  m_btnOK;
	private: System::Windows::Forms::Button^  m_btnCancel;


	private: System::Windows::Forms::Button^  m_btnDefault;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(OptionForm::typeid));
			this->m_upDownCapInterval = (gcnew System::Windows::Forms::NumericUpDown());
			this->m_upDownThresDiff = (gcnew System::Windows::Forms::NumericUpDown());
			this->m_upDownThresShutdown = (gcnew System::Windows::Forms::NumericUpDown());
			this->m_upDownThresBoot = (gcnew System::Windows::Forms::NumericUpDown());
			this->m_upDownTimeDelay = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->m_btnOK = (gcnew System::Windows::Forms::Button());
			this->m_btnCancel = (gcnew System::Windows::Forms::Button());
			this->m_btnDefault = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownCapInterval))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownThresDiff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownThresShutdown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownThresBoot))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownTimeDelay))->BeginInit();
			this->SuspendLayout();
			// 
			// m_upDownCapInterval
			// 
			this->m_upDownCapInterval->Location = System::Drawing::Point(347, 19);
			this->m_upDownCapInterval->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->m_upDownCapInterval->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->m_upDownCapInterval->Name = L"m_upDownCapInterval";
			this->m_upDownCapInterval->Size = System::Drawing::Size(75, 20);
			this->m_upDownCapInterval->TabIndex = 1;
			this->m_upDownCapInterval->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->m_upDownCapInterval->ValueChanged += gcnew System::EventHandler(this, &OptionForm::m_upDownCapInterval_ValueChanged);
			// 
			// m_upDownThresDiff
			// 
			this->m_upDownThresDiff->Location = System::Drawing::Point(347, 63);
			this->m_upDownThresDiff->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->m_upDownThresDiff->Name = L"m_upDownThresDiff";
			this->m_upDownThresDiff->Size = System::Drawing::Size(75, 20);
			this->m_upDownThresDiff->TabIndex = 2;
			this->m_upDownThresDiff->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->m_upDownThresDiff->ValueChanged += gcnew System::EventHandler(this, &OptionForm::m_upDownThresDiff_ValueChanged);
			// 
			// m_upDownThresShutdown
			// 
			this->m_upDownThresShutdown->Location = System::Drawing::Point(347, 107);
			this->m_upDownThresShutdown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {307200, 0, 0, 0});
			this->m_upDownThresShutdown->Name = L"m_upDownThresShutdown";
			this->m_upDownThresShutdown->Size = System::Drawing::Size(75, 20);
			this->m_upDownThresShutdown->TabIndex = 3;
			this->m_upDownThresShutdown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {300, 0, 0, 0});
			this->m_upDownThresShutdown->ValueChanged += gcnew System::EventHandler(this, &OptionForm::m_upDownThresShutdown_ValueChanged);
			// 
			// m_upDownThresBoot
			// 
			this->m_upDownThresBoot->Location = System::Drawing::Point(349, 151);
			this->m_upDownThresBoot->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {307200, 0, 0, 0});
			this->m_upDownThresBoot->Name = L"m_upDownThresBoot";
			this->m_upDownThresBoot->Size = System::Drawing::Size(75, 20);
			this->m_upDownThresBoot->TabIndex = 4;
			this->m_upDownThresBoot->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->m_upDownThresBoot->ValueChanged += gcnew System::EventHandler(this, &OptionForm::m_upDownThresBoot_ValueChanged);
			// 
			// m_upDownTimeDelay
			// 
			this->m_upDownTimeDelay->Location = System::Drawing::Point(349, 195);
			this->m_upDownTimeDelay->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {307200, 0, 0, 0});
			this->m_upDownTimeDelay->Name = L"m_upDownTimeDelay";
			this->m_upDownTimeDelay->Size = System::Drawing::Size(75, 20);
			this->m_upDownTimeDelay->TabIndex = 5;
			this->m_upDownTimeDelay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			this->m_upDownTimeDelay->ValueChanged += gcnew System::EventHandler(this, &OptionForm::m_upDownTimeDelay_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"ตรวจจับความเปลี่ยนแปลงทุกๆ ( 1- max int วินาที)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"ค่าสีต่างกัน ( 0-255 หน่วย)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 107);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(290, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"จำนวน pixel เคลื่อนไหวต่ำกว่ากำหนดจะ shutdown 0-307200";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 151);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(320, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"จำนวน pixel เคลื่อนไหวมากกว่ากำหนดจะ Boot computer 0-307200";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 195);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(269, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"เวลาหน่วง (วินาที) ในการ start กล้อง webcam 0-307200 ";
			// 
			// m_btnOK
			// 
			this->m_btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->m_btnOK->Location = System::Drawing::Point(247, 273);
			this->m_btnOK->Name = L"m_btnOK";
			this->m_btnOK->Size = System::Drawing::Size(75, 23);
			this->m_btnOK->TabIndex = 11;
			this->m_btnOK->Text = L"OK";
			this->m_btnOK->UseVisualStyleBackColor = true;
			this->m_btnOK->Click += gcnew System::EventHandler(this, &OptionForm::m_btnOK_Click);
			// 
			// m_btnCancel
			// 
			this->m_btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->m_btnCancel->Location = System::Drawing::Point(349, 273);
			this->m_btnCancel->Name = L"m_btnCancel";
			this->m_btnCancel->Size = System::Drawing::Size(75, 23);
			this->m_btnCancel->TabIndex = 12;
			this->m_btnCancel->Text = L"Cancel";
			this->m_btnCancel->UseVisualStyleBackColor = true;
			// 
			// m_btnDefault
			// 
			this->m_btnDefault->Location = System::Drawing::Point(24, 273);
			this->m_btnDefault->Name = L"m_btnDefault";
			this->m_btnDefault->Size = System::Drawing::Size(75, 23);
			this->m_btnDefault->TabIndex = 13;
			this->m_btnDefault->Text = L"&Default";
			this->m_btnDefault->UseVisualStyleBackColor = true;
			this->m_btnDefault->Click += gcnew System::EventHandler(this, &OptionForm::m_btnDefault_Click);
			// 
			// OptionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 308);
			this->Controls->Add(this->m_btnDefault);
			this->Controls->Add(this->m_btnCancel);
			this->Controls->Add(this->m_btnOK);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->m_upDownTimeDelay);
			this->Controls->Add(this->m_upDownThresBoot);
			this->Controls->Add(this->m_upDownThresShutdown);
			this->Controls->Add(this->m_upDownThresDiff);
			this->Controls->Add(this->m_upDownCapInterval);
			
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"OptionForm";
			this->Padding = System::Windows::Forms::Padding(9);
			this->Text = L"Engy Options";
			this->Load += gcnew System::EventHandler(this, &OptionForm::OptionForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownCapInterval))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownThresDiff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownThresShutdown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownThresBoot))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_upDownTimeDelay))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void m_btnDefault_Click(System::Object^  sender, System::EventArgs^  e) {
			this->m_upDownCapInterval->Value = 180;
			this->m_upDownThresDiff->Value = 50;
			this->m_upDownThresShutdown->Value = 300;
			this->m_upDownThresBoot->Value = 1000;
			this->m_upDownTimeDelay->Value = 100;
			*m_chkModifyParam = 63;
		 }

private: System::Void m_btnOK_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(*m_chkModifyParam == 0) 
			 {
				 //no parameter modified
				this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			 }
			 else
			 {
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				//need to modify ini file and main form must load ini file again
				unsigned char idxBit;
				System::String^ strTmp;
				char* pstr;
				string strSection ("Parameter");

				idxBit = 1 & *m_chkModifyParam;
				if(idxBit ==1)
				{
					strTmp =  System::Convert::ToString(this->m_upDownCapInterval->Value);
					pstr = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(strTmp).ToPointer();
					::WritePrivateProfileStringA(strSection.c_str(),"CapEveryNSec",pstr,m_pstrIniFileName);
					Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)pstr);
				}
				idxBit = 2 & *m_chkModifyParam;
				if(idxBit ==2)
				{
					strTmp =  System::Convert::ToString(this->m_upDownThresDiff->Value);// m_pcurFeedData->QCType.ToString("#0");
					pstr = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(strTmp).ToPointer();
					::WritePrivateProfileStringA(strSection.c_str(),"ThresDiff",pstr,m_pstrIniFileName);
					Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)pstr);
				}
				idxBit = 4 & *m_chkModifyParam;
				if(idxBit ==4)
				{
					strTmp =  System::Convert::ToString(this->m_upDownThresShutdown->Value);// m_pcurFeedData->QCType.ToString("#0");
					pstr = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(strTmp).ToPointer();
					::WritePrivateProfileStringA(strSection.c_str(),"ThresShutdownComputer",pstr,m_pstrIniFileName);
					Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)pstr);
				}
				idxBit = 8 & *m_chkModifyParam;
				if(idxBit ==8)
				{
					strTmp =  System::Convert::ToString(this->m_upDownThresBoot->Value);// m_pcurFeedData->QCType.ToString("#0");
					pstr = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(strTmp).ToPointer();
					::WritePrivateProfileStringA(strSection.c_str(),"ThresBootComputer",pstr,m_pstrIniFileName);
					Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)pstr);
				}
				idxBit = 16 & *m_chkModifyParam;
				if(idxBit ==16)
				{
					strTmp =  System::Convert::ToString(this->m_upDownTimeDelay->Value);// m_pcurFeedData->QCType.ToString("#0");
					pstr = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(strTmp).ToPointer();
					::WritePrivateProfileStringA(strSection.c_str(),"NumberOfDelay",pstr,m_pstrIniFileName);
					Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)pstr);
				}

			 }
		 }
//manipulate ini File
//------------------------------------------------------
//Name manipulateAPMINIFile
//Desc get dat from INI file
//     char* pFileName  name and path of ini file
//		 feed data
//------------------------------------------------------
private: System::Void manipulateCPFeedINIFile(char* pFileName)
{
		char* retBuffer;
		string strSection ("Parameter");
		int iTmp;

		//ควรตรวจสอบก่อนว่า มีไฟล์นี้อยู่หรือเปล่า
		//set feed type to list
		std::fstream file;
		file.open( pFileName,std::ios::in );
		if(file.fail())
		{
			file.close();
			MessageBox::Show("File " + gcnew System::String(pFileName) + " is not exist!!!");
			return ;
		}
		else
		{
			file.close();
			retBuffer = (char*)calloc(MAXSIZE,sizeof(char));
			char* pdest = NULL;
			char* psrc = NULL;

			//read Parameter section data
			iTmp=::GetPrivateProfileIntA(strSection.c_str(),"CapEveryNSec",180,pFileName);
			if(iTmp == 0)
				return;
			this->m_upDownCapInterval->Value = Convert::ToDecimal(iTmp);
			
			iTmp=::GetPrivateProfileIntA(strSection.c_str(),"ThresDiff",50,pFileName);
			if(iTmp == 0)
				return;
			this->m_upDownThresDiff->Value =  Convert::ToDecimal(iTmp);
			iTmp=::GetPrivateProfileIntA(strSection.c_str(),"ThresShutdownComputer",50,pFileName);
			if(iTmp == 0)
				return;
			this->m_upDownThresShutdown->Value = Convert::ToDecimal(iTmp);


			iTmp=::GetPrivateProfileIntA(strSection.c_str(),"ThresBootComputer",50,pFileName);
			if(iTmp == 0)
				return;
			this->m_upDownThresBoot->Value = Convert::ToDecimal(iTmp);
			
			iTmp=::GetPrivateProfileIntA(strSection.c_str(),"NumberOfDelay",50,pFileName);
			if(iTmp == 0)
				return;	
			this->m_upDownTimeDelay->Value = Convert::ToDecimal(iTmp);
			

		}

}
private: System::Void m_upDownCapInterval_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 *m_chkModifyParam = *m_chkModifyParam | 1 ;
		 }
private: System::Void m_upDownThresDiff_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			  *m_chkModifyParam = *m_chkModifyParam | 2 ;
		 }
private: System::Void m_upDownThresShutdown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			  *m_chkModifyParam = *m_chkModifyParam | 4 ;
		 }
private: System::Void m_upDownThresBoot_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
 			  *m_chkModifyParam = *m_chkModifyParam | 8 ;
		 }
private: System::Void m_upDownTimeDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 *m_chkModifyParam = *m_chkModifyParam | 16 ;
		 }

		 		//---------------------------------------------------------------------------
			//Name: getImageFromRes
			//Des: A function for loads jpeg images from resources in C++/CLI 
			//---------------------------------------------------------------------------
	public:	System::Drawing::Icon^ getIconFromRes(long resource_ID)
		{

			// Get the primary module
			System::Reflection::Module ^ mod = System::Reflection::Assembly::GetExecutingAssembly()->GetModules()[0];

			// Get the instance handle 
			IntPtr hinst = Marshal::GetHINSTANCE(mod);

			// Get the icon as unmanaged
			HICON hic = LoadIcon((HINSTANCE) hinst.ToPointer(), MAKEINTRESOURCE(IDI_ICON2)); 
		
			    
			// import the unmanaged icon into the managed side 
			m_ptrIcon = Icon->FromHandle(IntPtr(hic));
			
			return  m_ptrIcon;

		}
			

private: System::Void OptionForm_Load(System::Object^  sender, System::EventArgs^  e) {
			System::Drawing::Icon ^jpeg;
			jpeg = getIconFromRes(IDI_ICON1);
			if(jpeg != nullptr)
			{
				this->Icon = jpeg;
			}
			manipulateCPFeedINIFile(m_pstrIniFileName);
		 }
};
}

