#pragma once
#include <iostream>
#include <random>
#include <string>
#include <cstring>
#include <msclr/marshal_cppstd.h> // For String conversion
#include <fstream>
using namespace System;

// Function to generate random 16-digit numbers
long long* rng()
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<long long> distr(1000000000000000, 9999999999999999);
	long long* num = new long long[16];
	for (int i = 0; i < 16; i++)
	{
		num[i] = distr(eng);
	}
	return num;
}

// Function to generate a 256-digit key from 16 random numbers
char* keyGen(long long num[16])
{
	char* key = new char[267];
	for (int i = 0; i < 256; i++)
	{
		int numIndex = (i / 16) % 16;
		int digitIndex = i % 16;
		std::string numStr = std::to_string(num[numIndex]);
		key[i] = numStr[digitIndex];
	}
	key[256] = '\0';
	return key;
}

namespace GUI1 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->SetStyle(System::Windows::Forms::ControlStyles::AllPaintingInWmPaint |
				System::Windows::Forms::ControlStyles::UserPaint |
				System::Windows::Forms::ControlStyles::OptimizedDoubleBuffer, true);
			this->UpdateStyles();
			elements = gcnew array<System::Windows::Forms::TextBox^>
			{
				element1, element2, element3, element4, element5,
					element6, element7, element8, element9, element10,
					element11, element12, element13, element14, element15
			};
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ EncryptMain;
	protected:

	protected:
	private: System::String^ selectedImagePath;
	private: System::Windows::Forms::Button^ DecryptMainButton;
	private: System::Windows::Forms::Button^ PassButton;
	private: System::Windows::Forms::Button^ SettingsButton;
	private:
		char* key = nullptr; // Class-level variable to store the generated key
	private: System::Windows::Forms::Button^ InstructionButton;
	private: System::Windows::Forms::Panel^ EncryptPanel;
	private: System::Windows::Forms::Label^ EncryptLabel;
	private: System::Windows::Forms::RichTextBox^ EncryptTextBox;
	private: System::Windows::Forms::Button^ EncryptExitButton;
	private: System::Windows::Forms::Panel^ DecryptPanel;
	private: System::Windows::Forms::RichTextBox^ DecryptTextBox;
	private: System::Windows::Forms::Label^ Decryptlabel;
	private: System::Windows::Forms::Button^ DecryptExitButton;
	private: System::Windows::Forms::Panel^ InstructionsPanel;
	private: System::Windows::Forms::TextBox^ InstructionTextBox;
	private: System::Windows::Forms::Label^ InstructionLabel;
	private: System::Windows::Forms::Button^ InstructionExit;
	private: System::Windows::Forms::Panel^ PasswordPanel;
	private: System::Windows::Forms::TableLayoutPanel^ PasswordTable;
	private: System::Windows::Forms::Label^ AppNameLabel;
	private: System::Windows::Forms::TextBox^ element1;
	private: System::Windows::Forms::TextBox^ element2;
	private: System::Windows::Forms::TextBox^ element9;
	private: System::Windows::Forms::TextBox^ element8;
	private: System::Windows::Forms::TextBox^ element7;
	private: System::Windows::Forms::TextBox^ element6;
	private: System::Windows::Forms::TextBox^ element5;
	private: System::Windows::Forms::TextBox^ element4;
	private: System::Windows::Forms::TextBox^ element3;
	private: System::Windows::Forms::TextBox^ element15;
	private: System::Windows::Forms::TextBox^ element14;
	private: System::Windows::Forms::TextBox^ element13;
	private: System::Windows::Forms::TextBox^ element12;
	private: System::Windows::Forms::TextBox^ element11;
	private: System::Windows::Forms::TextBox^ element10;
	private: System::Windows::Forms::Label^ Passwordlabel;
	private: System::Windows::Forms::Label^ Usernamelabel;
	private: System::Windows::Forms::Button^ PasswordExit;
	private: System::Windows::Forms::Button^ EncryptButton;
	private: System::Windows::Forms::Button^ KeyMain;
	private: System::Windows::Forms::Panel^ Keypanel;
	private: System::Windows::Forms::RichTextBox^ keytextbox;
	private: System::Windows::Forms::Button^ generatekeybutton;
	private: System::Windows::Forms::Button^ exitkeybutton;
	private: System::Windows::Forms::Button^ decryptbutton;
	private: System::Windows::Forms::Label^ decryptkeylabel;
	private: System::Windows::Forms::RichTextBox^ decryptkeyTextBox;
	array<System::Windows::Forms::TextBox^>^ elements;
	private: System::Windows::Forms::Button^ savekeybutton;
	private: System::Windows::Forms::Panel^ settingspanel;
	private: System::Windows::Forms::Button^ darkmodebutton;
	private: System::Windows::Forms::Button^ lightmodebutton;
	private: System::Windows::Forms::Button^ settingsexitbutton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ copyencryptbutton;
	private: System::Windows::Forms::Button^ copykeybutton;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->EncryptMain = (gcnew System::Windows::Forms::Button());
			this->DecryptMainButton = (gcnew System::Windows::Forms::Button());
			this->PassButton = (gcnew System::Windows::Forms::Button());
			this->SettingsButton = (gcnew System::Windows::Forms::Button());
			this->InstructionButton = (gcnew System::Windows::Forms::Button());
			this->EncryptPanel = (gcnew System::Windows::Forms::Panel());
			this->copyencryptbutton = (gcnew System::Windows::Forms::Button());
			this->EncryptButton = (gcnew System::Windows::Forms::Button());
			this->EncryptExitButton = (gcnew System::Windows::Forms::Button());
			this->EncryptTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->EncryptLabel = (gcnew System::Windows::Forms::Label());
			this->DecryptPanel = (gcnew System::Windows::Forms::Panel());
			this->decryptkeylabel = (gcnew System::Windows::Forms::Label());
			this->decryptkeyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->decryptbutton = (gcnew System::Windows::Forms::Button());
			this->DecryptExitButton = (gcnew System::Windows::Forms::Button());
			this->DecryptTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->Decryptlabel = (gcnew System::Windows::Forms::Label());
			this->InstructionsPanel = (gcnew System::Windows::Forms::Panel());
			this->InstructionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->InstructionExit = (gcnew System::Windows::Forms::Button());
			this->InstructionLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordPanel = (gcnew System::Windows::Forms::Panel());
			this->PasswordExit = (gcnew System::Windows::Forms::Button());
			this->PasswordTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Passwordlabel = (gcnew System::Windows::Forms::Label());
			this->Usernamelabel = (gcnew System::Windows::Forms::Label());
			this->element14 = (gcnew System::Windows::Forms::TextBox());
			this->element13 = (gcnew System::Windows::Forms::TextBox());
			this->element12 = (gcnew System::Windows::Forms::TextBox());
			this->element11 = (gcnew System::Windows::Forms::TextBox());
			this->element10 = (gcnew System::Windows::Forms::TextBox());
			this->element8 = (gcnew System::Windows::Forms::TextBox());
			this->element7 = (gcnew System::Windows::Forms::TextBox());
			this->element6 = (gcnew System::Windows::Forms::TextBox());
			this->element5 = (gcnew System::Windows::Forms::TextBox());
			this->element4 = (gcnew System::Windows::Forms::TextBox());
			this->element3 = (gcnew System::Windows::Forms::TextBox());
			this->element2 = (gcnew System::Windows::Forms::TextBox());
			this->element1 = (gcnew System::Windows::Forms::TextBox());
			this->AppNameLabel = (gcnew System::Windows::Forms::Label());
			this->element9 = (gcnew System::Windows::Forms::TextBox());
			this->element15 = (gcnew System::Windows::Forms::TextBox());
			this->KeyMain = (gcnew System::Windows::Forms::Button());
			this->Keypanel = (gcnew System::Windows::Forms::Panel());
			this->copykeybutton = (gcnew System::Windows::Forms::Button());
			this->savekeybutton = (gcnew System::Windows::Forms::Button());
			this->exitkeybutton = (gcnew System::Windows::Forms::Button());
			this->generatekeybutton = (gcnew System::Windows::Forms::Button());
			this->keytextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->settingspanel = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->settingsexitbutton = (gcnew System::Windows::Forms::Button());
			this->lightmodebutton = (gcnew System::Windows::Forms::Button());
			this->darkmodebutton = (gcnew System::Windows::Forms::Button());
			this->EncryptPanel->SuspendLayout();
			this->DecryptPanel->SuspendLayout();
			this->InstructionsPanel->SuspendLayout();
			this->PasswordPanel->SuspendLayout();
			this->PasswordTable->SuspendLayout();
			this->Keypanel->SuspendLayout();
			this->settingspanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// EncryptMain
			// 
			this->EncryptMain->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->EncryptMain->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->EncryptMain->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->EncryptMain->FlatAppearance->BorderSize = 0;
			this->EncryptMain->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->EncryptMain->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->EncryptMain->Location = System::Drawing::Point(530, 91);
			this->EncryptMain->Name = L"EncryptMain";
			this->EncryptMain->Size = System::Drawing::Size(261, 74);
			this->EncryptMain->TabIndex = 1;
			this->EncryptMain->Text = L"ENCRYPT";
			this->EncryptMain->UseVisualStyleBackColor = false;
			this->EncryptMain->Click += gcnew System::EventHandler(this, &MyForm::EncryptMain_Click);
			// 
			// DecryptMainButton
			// 
			this->DecryptMainButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->DecryptMainButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->DecryptMainButton->Font = (gcnew System::Drawing::Font(L"Verdana", 24.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DecryptMainButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->DecryptMainButton->Location = System::Drawing::Point(530, 172);
			this->DecryptMainButton->Name = L"DecryptMainButton";
			this->DecryptMainButton->Size = System::Drawing::Size(261, 69);
			this->DecryptMainButton->TabIndex = 2;
			this->DecryptMainButton->Text = L"DECRYPT";
			this->DecryptMainButton->UseVisualStyleBackColor = false;
			this->DecryptMainButton->Click += gcnew System::EventHandler(this, &MyForm::DecryptMainButton_Click);
			// 
			// PassButton
			// 
			this->PassButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->PassButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->PassButton->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->PassButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->PassButton->Location = System::Drawing::Point(530, 335);
			this->PassButton->Name = L"PassButton";
			this->PassButton->Size = System::Drawing::Size(261, 81);
			this->PassButton->TabIndex = 3;
			this->PassButton->Text = L"PASSWORD";
			this->PassButton->UseVisualStyleBackColor = false;
			this->PassButton->Click += gcnew System::EventHandler(this, &MyForm::PassButton_Click);
			// 
			// SettingsButton
			// 
			this->SettingsButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->SettingsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SettingsButton.BackgroundImage")));
			this->SettingsButton->Location = System::Drawing::Point(1245, 494);
			this->SettingsButton->Name = L"SettingsButton";
			this->SettingsButton->Size = System::Drawing::Size(33, 33);
			this->SettingsButton->TabIndex = 4;
			this->SettingsButton->UseVisualStyleBackColor = true;
			this->SettingsButton->Click += gcnew System::EventHandler(this, &MyForm::SettingsButton_Click);
			// 
			// InstructionButton
			// 
			this->InstructionButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->InstructionButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->InstructionButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InstructionButton.BackgroundImage")));
			this->InstructionButton->Location = System::Drawing::Point(12, 494);
			this->InstructionButton->Name = L"InstructionButton";
			this->InstructionButton->Size = System::Drawing::Size(33, 33);
			this->InstructionButton->TabIndex = 6;
			this->InstructionButton->UseVisualStyleBackColor = false;
			this->InstructionButton->Click += gcnew System::EventHandler(this, &MyForm::InstructionButton_Click);
			// 
			// EncryptPanel
			// 
			this->EncryptPanel->AccessibleName = L"";
			this->EncryptPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EncryptPanel.BackgroundImage")));
			this->EncryptPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->EncryptPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->EncryptPanel->Controls->Add(this->copyencryptbutton);
			this->EncryptPanel->Controls->Add(this->EncryptButton);
			this->EncryptPanel->Controls->Add(this->EncryptExitButton);
			this->EncryptPanel->Controls->Add(this->EncryptTextBox);
			this->EncryptPanel->Controls->Add(this->EncryptLabel);
			this->EncryptPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->EncryptPanel->Location = System::Drawing::Point(0, 0);
			this->EncryptPanel->Name = L"EncryptPanel";
			this->EncryptPanel->Size = System::Drawing::Size(1290, 539);
			this->EncryptPanel->TabIndex = 7;
			this->EncryptPanel->Visible = false;
			// 
			// copyencryptbutton
			// 
			this->copyencryptbutton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->copyencryptbutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->copyencryptbutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->copyencryptbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->copyencryptbutton->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->copyencryptbutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->copyencryptbutton->Location = System::Drawing::Point(953, 339);
			this->copyencryptbutton->Name = L"copyencryptbutton";
			this->copyencryptbutton->Size = System::Drawing::Size(58, 33);
			this->copyencryptbutton->TabIndex = 4;
			this->copyencryptbutton->Text = L"COPY";
			this->copyencryptbutton->UseVisualStyleBackColor = false;
			this->copyencryptbutton->Click += gcnew System::EventHandler(this, &MyForm::copyencryptbutton_Click);
			// 
			// EncryptButton
			// 
			this->EncryptButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->EncryptButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->EncryptButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->EncryptButton->FlatAppearance->BorderSize = 0;
			this->EncryptButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->EncryptButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->EncryptButton->Location = System::Drawing::Point(838, 399);
			this->EncryptButton->Name = L"EncryptButton";
			this->EncryptButton->Size = System::Drawing::Size(173, 45);
			this->EncryptButton->TabIndex = 3;
			this->EncryptButton->Text = L"ENCRYPT";
			this->EncryptButton->UseVisualStyleBackColor = false;
			this->EncryptButton->Click += gcnew System::EventHandler(this, &MyForm::EncryptButton_Click);
			// 
			// EncryptExitButton
			// 
			this->EncryptExitButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->EncryptExitButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->EncryptExitButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EncryptExitButton.BackgroundImage")));
			this->EncryptExitButton->FlatAppearance->BorderSize = 0;
			this->EncryptExitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->EncryptExitButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->EncryptExitButton->Location = System::Drawing::Point(3, 3);
			this->EncryptExitButton->Name = L"EncryptExitButton";
			this->EncryptExitButton->Size = System::Drawing::Size(52, 49);
			this->EncryptExitButton->TabIndex = 2;
			this->EncryptExitButton->UseVisualStyleBackColor = false;
			this->EncryptExitButton->Click += gcnew System::EventHandler(this, &MyForm::EncryptExitButton_Click);
			// 
			// EncryptTextBox
			// 
			this->EncryptTextBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->EncryptTextBox->BackColor = System::Drawing::SystemColors::MenuText;
			this->EncryptTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->EncryptTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Bold));
			this->EncryptTextBox->ForeColor = System::Drawing::SystemColors::Menu;
			this->EncryptTextBox->Location = System::Drawing::Point(335, 164);
			this->EncryptTextBox->Name = L"EncryptTextBox";
			this->EncryptTextBox->Size = System::Drawing::Size(676, 208);
			this->EncryptTextBox->TabIndex = 1;
			this->EncryptTextBox->Text = L"";
			// 
			// EncryptLabel
			// 
			this->EncryptLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->EncryptLabel->AutoSize = true;
			this->EncryptLabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->EncryptLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->EncryptLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->EncryptLabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->EncryptLabel->Location = System::Drawing::Point(335, 94);
			this->EncryptLabel->Name = L"EncryptLabel";
			this->EncryptLabel->Size = System::Drawing::Size(676, 43);
			this->EncryptLabel->TabIndex = 0;
			this->EncryptLabel->Text = L"ENTER THE MESSAGE TO ENCRYPT";
			// 
			// DecryptPanel
			// 
			this->DecryptPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DecryptPanel.BackgroundImage")));
			this->DecryptPanel->Controls->Add(this->decryptkeylabel);
			this->DecryptPanel->Controls->Add(this->decryptkeyTextBox);
			this->DecryptPanel->Controls->Add(this->decryptbutton);
			this->DecryptPanel->Controls->Add(this->DecryptExitButton);
			this->DecryptPanel->Controls->Add(this->DecryptTextBox);
			this->DecryptPanel->Controls->Add(this->Decryptlabel);
			this->DecryptPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DecryptPanel->Location = System::Drawing::Point(0, 0);
			this->DecryptPanel->Name = L"DecryptPanel";
			this->DecryptPanel->Size = System::Drawing::Size(1290, 539);
			this->DecryptPanel->TabIndex = 8;
			this->DecryptPanel->Visible = false;
			// 
			// decryptkeylabel
			// 
			this->decryptkeylabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->decryptkeylabel->AutoSize = true;
			this->decryptkeylabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->decryptkeylabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->decryptkeylabel->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->decryptkeylabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->decryptkeylabel->Location = System::Drawing::Point(58, 65);
			this->decryptkeylabel->Name = L"decryptkeylabel";
			this->decryptkeylabel->Size = System::Drawing::Size(343, 43);
			this->decryptkeylabel->TabIndex = 6;
			this->decryptkeylabel->Text = L"ENTER THE KEY :\r\n";
			// 
			// decryptkeyTextBox
			// 
			this->decryptkeyTextBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->decryptkeyTextBox->BackColor = System::Drawing::SystemColors::MenuText;
			this->decryptkeyTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->decryptkeyTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Bold));
			this->decryptkeyTextBox->ForeColor = System::Drawing::SystemColors::Menu;
			this->decryptkeyTextBox->Location = System::Drawing::Point(407, 65);
			this->decryptkeyTextBox->Name = L"decryptkeyTextBox";
			this->decryptkeyTextBox->Size = System::Drawing::Size(829, 43);
			this->decryptkeyTextBox->TabIndex = 5;
			this->decryptkeyTextBox->Text = L"";
			// 
			// decryptbutton
			// 
			this->decryptbutton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->decryptbutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->decryptbutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->decryptbutton->FlatAppearance->BorderSize = 0;
			this->decryptbutton->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->decryptbutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->decryptbutton->Location = System::Drawing::Point(800, 442);
			this->decryptbutton->Name = L"decryptbutton";
			this->decryptbutton->Size = System::Drawing::Size(173, 45);
			this->decryptbutton->TabIndex = 4;
			this->decryptbutton->Text = L"DECRYPT";
			this->decryptbutton->UseVisualStyleBackColor = false;
			this->decryptbutton->Click += gcnew System::EventHandler(this, &MyForm::decryptbutton_Click);
			// 
			// DecryptExitButton
			// 
			this->DecryptExitButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->DecryptExitButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->DecryptExitButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DecryptExitButton.BackgroundImage")));
			this->DecryptExitButton->FlatAppearance->BorderSize = 0;
			this->DecryptExitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->DecryptExitButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->DecryptExitButton->Location = System::Drawing::Point(3, 3);
			this->DecryptExitButton->Name = L"DecryptExitButton";
			this->DecryptExitButton->Size = System::Drawing::Size(48, 45);
			this->DecryptExitButton->TabIndex = 3;
			this->DecryptExitButton->UseVisualStyleBackColor = false;
			this->DecryptExitButton->Click += gcnew System::EventHandler(this, &MyForm::DecryptExitButton_Click);
			// 
			// DecryptTextBox
			// 
			this->DecryptTextBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->DecryptTextBox->BackColor = System::Drawing::SystemColors::MenuText;
			this->DecryptTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DecryptTextBox->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Bold));
			this->DecryptTextBox->ForeColor = System::Drawing::SystemColors::Menu;
			this->DecryptTextBox->Location = System::Drawing::Point(297, 212);
			this->DecryptTextBox->Name = L"DecryptTextBox";
			this->DecryptTextBox->Size = System::Drawing::Size(676, 204);
			this->DecryptTextBox->TabIndex = 2;
			this->DecryptTextBox->Text = L"";
			// 
			// Decryptlabel
			// 
			this->Decryptlabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Decryptlabel->AutoSize = true;
			this->Decryptlabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Decryptlabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Decryptlabel->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->Decryptlabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Decryptlabel->Location = System::Drawing::Point(297, 153);
			this->Decryptlabel->Name = L"Decryptlabel";
			this->Decryptlabel->Size = System::Drawing::Size(675, 43);
			this->Decryptlabel->TabIndex = 1;
			this->Decryptlabel->Text = L"ENTER THE MESSAGE TO DECRYPT";
			// 
			// InstructionsPanel
			// 
			this->InstructionsPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InstructionsPanel.BackgroundImage")));
			this->InstructionsPanel->Controls->Add(this->InstructionTextBox);
			this->InstructionsPanel->Controls->Add(this->InstructionExit);
			this->InstructionsPanel->Controls->Add(this->InstructionLabel);
			this->InstructionsPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InstructionsPanel->Font = (gcnew System::Drawing::Font(L"MS Outlook", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->InstructionsPanel->Location = System::Drawing::Point(0, 0);
			this->InstructionsPanel->Name = L"InstructionsPanel";
			this->InstructionsPanel->Size = System::Drawing::Size(1290, 539);
			this->InstructionsPanel->TabIndex = 8;
			this->InstructionsPanel->Visible = false;
			// 
			// InstructionTextBox
			// 
			this->InstructionTextBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->InstructionTextBox->BackColor = System::Drawing::SystemColors::InfoText;
			this->InstructionTextBox->Font = (gcnew System::Drawing::Font(L"Verdana", 13));
			this->InstructionTextBox->ForeColor = System::Drawing::SystemColors::Menu;
			this->InstructionTextBox->Location = System::Drawing::Point(290, 127);
			this->InstructionTextBox->Multiline = true;
			this->InstructionTextBox->Name = L"InstructionTextBox";
			this->InstructionTextBox->ReadOnly = true;
			this->InstructionTextBox->Size = System::Drawing::Size(723, 341);
			this->InstructionTextBox->TabIndex = 1;
			this->InstructionTextBox->Text = resources->GetString(L"InstructionTextBox.Text");
			// 
			// InstructionExit
			// 
			this->InstructionExit->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->InstructionExit->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->InstructionExit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InstructionExit.BackgroundImage")));
			this->InstructionExit->FlatAppearance->BorderSize = 0;
			this->InstructionExit->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->InstructionExit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->InstructionExit->Location = System::Drawing::Point(3, 3);
			this->InstructionExit->Name = L"InstructionExit";
			this->InstructionExit->Size = System::Drawing::Size(52, 49);
			this->InstructionExit->TabIndex = 4;
			this->InstructionExit->UseVisualStyleBackColor = false;
			this->InstructionExit->Click += gcnew System::EventHandler(this, &MyForm::InstructionExit_Click);
			// 
			// InstructionLabel
			// 
			this->InstructionLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->InstructionLabel->AutoSize = true;
			this->InstructionLabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->InstructionLabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->InstructionLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InstructionLabel->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->InstructionLabel->Location = System::Drawing::Point(500, 46);
			this->InstructionLabel->Name = L"InstructionLabel";
			this->InstructionLabel->Size = System::Drawing::Size(287, 50);
			this->InstructionLabel->TabIndex = 0;
			this->InstructionLabel->Text = L"How To Use";
			// 
			// PasswordPanel
			// 
			this->PasswordPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PasswordPanel.BackgroundImage")));
			this->PasswordPanel->Controls->Add(this->PasswordExit);
			this->PasswordPanel->Controls->Add(this->PasswordTable);
			this->PasswordPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PasswordPanel->Location = System::Drawing::Point(0, 0);
			this->PasswordPanel->Name = L"PasswordPanel";
			this->PasswordPanel->Size = System::Drawing::Size(1290, 539);
			this->PasswordPanel->TabIndex = 9;
			this->PasswordPanel->Visible = false;
			// 
			// PasswordExit
			// 
			this->PasswordExit->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->PasswordExit->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->PasswordExit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PasswordExit.BackgroundImage")));
			this->PasswordExit->FlatAppearance->BorderSize = 0;
			this->PasswordExit->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->PasswordExit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->PasswordExit->Location = System::Drawing::Point(5, 5);
			this->PasswordExit->Name = L"PasswordExit";
			this->PasswordExit->Size = System::Drawing::Size(50, 50);
			this->PasswordExit->TabIndex = 3;
			this->PasswordExit->UseVisualStyleBackColor = false;
			this->PasswordExit->Click += gcnew System::EventHandler(this, &MyForm::PasswordExit_Click);
			// 
			// PasswordTable
			// 
			this->PasswordTable->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->PasswordTable->BackColor = System::Drawing::Color::Black;
			this->PasswordTable->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::InsetDouble;
			this->PasswordTable->ColumnCount = 3;
			this->PasswordTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				51.33531F)));
			this->PasswordTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.66469F)));
			this->PasswordTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				331)));
			this->PasswordTable->Controls->Add(this->Passwordlabel, 2, 0);
			this->PasswordTable->Controls->Add(this->Usernamelabel, 1, 0);
			this->PasswordTable->Controls->Add(this->element14, 1, 5);
			this->PasswordTable->Controls->Add(this->element13, 0, 5);
			this->PasswordTable->Controls->Add(this->element12, 2, 4);
			this->PasswordTable->Controls->Add(this->element11, 1, 4);
			this->PasswordTable->Controls->Add(this->element10, 0, 4);
			this->PasswordTable->Controls->Add(this->element8, 1, 3);
			this->PasswordTable->Controls->Add(this->element7, 0, 3);
			this->PasswordTable->Controls->Add(this->element6, 2, 2);
			this->PasswordTable->Controls->Add(this->element5, 1, 2);
			this->PasswordTable->Controls->Add(this->element4, 0, 2);
			this->PasswordTable->Controls->Add(this->element3, 2, 1);
			this->PasswordTable->Controls->Add(this->element2, 1, 1);
			this->PasswordTable->Controls->Add(this->element1, 0, 1);
			this->PasswordTable->Controls->Add(this->AppNameLabel, 0, 0);
			this->PasswordTable->Controls->Add(this->element9, 2, 3);
			this->PasswordTable->Controls->Add(this->element15, 2, 5);
			this->PasswordTable->Location = System::Drawing::Point(142, 111);
			this->PasswordTable->Name = L"PasswordTable";
			this->PasswordTable->RowCount = 6;
			this->PasswordTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 65.15151F)));
			this->PasswordTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 34.84848F)));
			this->PasswordTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->PasswordTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 41)));
			this->PasswordTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->PasswordTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->PasswordTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->PasswordTable->Size = System::Drawing::Size(1024, 312);
			this->PasswordTable->TabIndex = 0;
			// 
			// Passwordlabel
			// 
			this->Passwordlabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Passwordlabel->AutoSize = true;
			this->Passwordlabel->BackColor = System::Drawing::Color::DimGray;
			this->Passwordlabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Passwordlabel->ForeColor = System::Drawing::Color::White;
			this->Passwordlabel->Location = System::Drawing::Point(692, 3);
			this->Passwordlabel->Name = L"Passwordlabel";
			this->Passwordlabel->Size = System::Drawing::Size(326, 82);
			this->Passwordlabel->TabIndex = 19;
			this->Passwordlabel->Text = L"Password";
			this->Passwordlabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Usernamelabel
			// 
			this->Usernamelabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Usernamelabel->AutoSize = true;
			this->Usernamelabel->BackColor = System::Drawing::Color::DimGray;
			this->Usernamelabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Usernamelabel->ForeColor = System::Drawing::Color::White;
			this->Usernamelabel->Location = System::Drawing::Point(358, 3);
			this->Usernamelabel->Name = L"Usernamelabel";
			this->Usernamelabel->Size = System::Drawing::Size(325, 82);
			this->Usernamelabel->TabIndex = 18;
			this->Usernamelabel->Text = L"Username";
			this->Usernamelabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// element14
			// 
			this->element14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element14->BackColor = System::Drawing::Color::Black;
			this->element14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element14->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element14->ForeColor = System::Drawing::Color::White;
			this->element14->Location = System::Drawing::Point(358, 276);
			this->element14->Name = L"element14";
			this->element14->Size = System::Drawing::Size(325, 25);
			this->element14->TabIndex = 16;
			this->element14->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element13
			// 
			this->element13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element13->BackColor = System::Drawing::Color::Black;
			this->element13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element13->ForeColor = System::Drawing::Color::White;
			this->element13->Location = System::Drawing::Point(6, 276);
			this->element13->Name = L"element13";
			this->element13->Size = System::Drawing::Size(343, 25);
			this->element13->TabIndex = 15;
			this->element13->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element12
			// 
			this->element12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element12->BackColor = System::Drawing::Color::Black;
			this->element12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element12->ForeColor = System::Drawing::Color::White;
			this->element12->Location = System::Drawing::Point(692, 230);
			this->element12->Name = L"element12";
			this->element12->Size = System::Drawing::Size(326, 25);
			this->element12->TabIndex = 14;
			this->element12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->element12->UseSystemPasswordChar = true;
			// 
			// element11
			// 
			this->element11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element11->BackColor = System::Drawing::Color::Black;
			this->element11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element11->ForeColor = System::Drawing::Color::White;
			this->element11->Location = System::Drawing::Point(358, 230);
			this->element11->Name = L"element11";
			this->element11->Size = System::Drawing::Size(325, 25);
			this->element11->TabIndex = 13;
			this->element11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element10
			// 
			this->element10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element10->BackColor = System::Drawing::Color::Black;
			this->element10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element10->ForeColor = System::Drawing::Color::White;
			this->element10->Location = System::Drawing::Point(6, 230);
			this->element10->Name = L"element10";
			this->element10->Size = System::Drawing::Size(343, 25);
			this->element10->TabIndex = 12;
			this->element10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element8
			// 
			this->element8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element8->BackColor = System::Drawing::Color::Black;
			this->element8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element8->ForeColor = System::Drawing::Color::White;
			this->element8->Location = System::Drawing::Point(358, 185);
			this->element8->Name = L"element8";
			this->element8->Size = System::Drawing::Size(325, 25);
			this->element8->TabIndex = 10;
			this->element8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element7
			// 
			this->element7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element7->BackColor = System::Drawing::Color::Black;
			this->element7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element7->ForeColor = System::Drawing::Color::White;
			this->element7->Location = System::Drawing::Point(6, 185);
			this->element7->Name = L"element7";
			this->element7->Size = System::Drawing::Size(343, 25);
			this->element7->TabIndex = 9;
			this->element7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element6
			// 
			this->element6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element6->BackColor = System::Drawing::Color::Black;
			this->element6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element6->ForeColor = System::Drawing::Color::White;
			this->element6->Location = System::Drawing::Point(692, 142);
			this->element6->Name = L"element6";
			this->element6->Size = System::Drawing::Size(326, 25);
			this->element6->TabIndex = 8;
			this->element6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->element6->UseSystemPasswordChar = true;
			// 
			// element5
			// 
			this->element5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element5->BackColor = System::Drawing::Color::Black;
			this->element5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element5->ForeColor = System::Drawing::Color::White;
			this->element5->Location = System::Drawing::Point(358, 142);
			this->element5->Name = L"element5";
			this->element5->Size = System::Drawing::Size(325, 25);
			this->element5->TabIndex = 7;
			this->element5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element4
			// 
			this->element4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element4->BackColor = System::Drawing::Color::Black;
			this->element4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element4->ForeColor = System::Drawing::Color::White;
			this->element4->Location = System::Drawing::Point(6, 142);
			this->element4->Name = L"element4";
			this->element4->Size = System::Drawing::Size(343, 25);
			this->element4->TabIndex = 6;
			this->element4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element3
			// 
			this->element3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element3->BackColor = System::Drawing::Color::Black;
			this->element3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element3->ForeColor = System::Drawing::Color::White;
			this->element3->Location = System::Drawing::Point(692, 97);
			this->element3->Name = L"element3";
			this->element3->Size = System::Drawing::Size(326, 25);
			this->element3->TabIndex = 5;
			this->element3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->element3->UseSystemPasswordChar = true;
			// 
			// element2
			// 
			this->element2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element2->BackColor = System::Drawing::Color::Black;
			this->element2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element2->ForeColor = System::Drawing::Color::White;
			this->element2->Location = System::Drawing::Point(358, 97);
			this->element2->Name = L"element2";
			this->element2->Size = System::Drawing::Size(325, 25);
			this->element2->TabIndex = 4;
			this->element2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// element1
			// 
			this->element1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element1->BackColor = System::Drawing::Color::Black;
			this->element1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element1->ForeColor = System::Drawing::Color::White;
			this->element1->Location = System::Drawing::Point(6, 97);
			this->element1->Name = L"element1";
			this->element1->Size = System::Drawing::Size(343, 25);
			this->element1->TabIndex = 3;
			this->element1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AppNameLabel
			// 
			this->AppNameLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->AppNameLabel->AutoSize = true;
			this->AppNameLabel->BackColor = System::Drawing::Color::DimGray;
			this->AppNameLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AppNameLabel->ForeColor = System::Drawing::Color::White;
			this->AppNameLabel->Location = System::Drawing::Point(6, 3);
			this->AppNameLabel->Name = L"AppNameLabel";
			this->AppNameLabel->Size = System::Drawing::Size(343, 82);
			this->AppNameLabel->TabIndex = 0;
			this->AppNameLabel->Text = L"App Name";
			this->AppNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// element9
			// 
			this->element9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element9->BackColor = System::Drawing::Color::Black;
			this->element9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element9->ForeColor = System::Drawing::Color::White;
			this->element9->Location = System::Drawing::Point(692, 185);
			this->element9->Name = L"element9";
			this->element9->Size = System::Drawing::Size(326, 25);
			this->element9->TabIndex = 11;
			this->element9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->element9->UseSystemPasswordChar = true;
			// 
			// element15
			// 
			this->element15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->element15->BackColor = System::Drawing::Color::Black;
			this->element15->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->element15->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->element15->ForeColor = System::Drawing::Color::White;
			this->element15->Location = System::Drawing::Point(692, 276);
			this->element15->Name = L"element15";
			this->element15->Size = System::Drawing::Size(326, 25);
			this->element15->TabIndex = 17;
			this->element15->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->element15->UseSystemPasswordChar = true;
			// 
			// KeyMain
			// 
			this->KeyMain->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->KeyMain->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->KeyMain->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->KeyMain->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->KeyMain->Location = System::Drawing::Point(530, 247);
			this->KeyMain->Name = L"KeyMain";
			this->KeyMain->Size = System::Drawing::Size(261, 81);
			this->KeyMain->TabIndex = 10;
			this->KeyMain->Text = L"SET KEY";
			this->KeyMain->UseVisualStyleBackColor = false;
			this->KeyMain->Click += gcnew System::EventHandler(this, &MyForm::KeyMain_Click);
			// 
			// Keypanel
			// 
			this->Keypanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Keypanel.BackgroundImage")));
			this->Keypanel->Controls->Add(this->copykeybutton);
			this->Keypanel->Controls->Add(this->savekeybutton);
			this->Keypanel->Controls->Add(this->exitkeybutton);
			this->Keypanel->Controls->Add(this->generatekeybutton);
			this->Keypanel->Controls->Add(this->keytextbox);
			this->Keypanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Keypanel->Location = System::Drawing::Point(0, 0);
			this->Keypanel->Name = L"Keypanel";
			this->Keypanel->Size = System::Drawing::Size(1290, 539);
			this->Keypanel->TabIndex = 11;
			this->Keypanel->Visible = false;
			// 
			// copykeybutton
			// 
			this->copykeybutton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->copykeybutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->copykeybutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->copykeybutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->copykeybutton->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->copykeybutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->copykeybutton->Location = System::Drawing::Point(689, 327);
			this->copykeybutton->Name = L"copykeybutton";
			this->copykeybutton->Size = System::Drawing::Size(58, 33);
			this->copykeybutton->TabIndex = 9;
			this->copykeybutton->Text = L"COPY";
			this->copykeybutton->UseVisualStyleBackColor = false;
			this->copykeybutton->Click += gcnew System::EventHandler(this, &MyForm::copykeybutton_Click);
			// 
			// savekeybutton
			// 
			this->savekeybutton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->savekeybutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->savekeybutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->savekeybutton->FlatAppearance->BorderSize = 0;
			this->savekeybutton->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->savekeybutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->savekeybutton->Location = System::Drawing::Point(797, 277);
			this->savekeybutton->Name = L"savekeybutton";
			this->savekeybutton->Size = System::Drawing::Size(237, 83);
			this->savekeybutton->TabIndex = 8;
			this->savekeybutton->Text = L"SAVE KEY";
			this->savekeybutton->UseVisualStyleBackColor = false;
			this->savekeybutton->Click += gcnew System::EventHandler(this, &MyForm::savekeybutton_Click);
			// 
			// exitkeybutton
			// 
			this->exitkeybutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->exitkeybutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->exitkeybutton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitkeybutton.BackgroundImage")));
			this->exitkeybutton->FlatAppearance->BorderSize = 0;
			this->exitkeybutton->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->exitkeybutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->exitkeybutton->Location = System::Drawing::Point(5, 6);
			this->exitkeybutton->Name = L"exitkeybutton";
			this->exitkeybutton->Size = System::Drawing::Size(50, 49);
			this->exitkeybutton->TabIndex = 7;
			this->exitkeybutton->UseVisualStyleBackColor = false;
			this->exitkeybutton->Click += gcnew System::EventHandler(this, &MyForm::exitkeybutton_Click);
			// 
			// generatekeybutton
			// 
			this->generatekeybutton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->generatekeybutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->generatekeybutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->generatekeybutton->FlatAppearance->BorderSize = 0;
			this->generatekeybutton->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->generatekeybutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->generatekeybutton->Location = System::Drawing::Point(797, 111);
			this->generatekeybutton->Name = L"generatekeybutton";
			this->generatekeybutton->Size = System::Drawing::Size(237, 130);
			this->generatekeybutton->TabIndex = 6;
			this->generatekeybutton->Text = L"GENERATE KEY";
			this->generatekeybutton->UseVisualStyleBackColor = false;
			this->generatekeybutton->Click += gcnew System::EventHandler(this, &MyForm::generatekeybutton_Click);
			// 
			// keytextbox
			// 
			this->keytextbox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->keytextbox->BackColor = System::Drawing::SystemColors::InfoText;
			this->keytextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->keytextbox->ForeColor = System::Drawing::Color::White;
			this->keytextbox->Location = System::Drawing::Point(212, 111);
			this->keytextbox->Name = L"keytextbox";
			this->keytextbox->Size = System::Drawing::Size(535, 249);
			this->keytextbox->TabIndex = 0;
			this->keytextbox->Text = L"";
			// 
			// settingspanel
			// 
			this->settingspanel->BackColor = System::Drawing::Color::Black;
			this->settingspanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingspanel.BackgroundImage")));
			this->settingspanel->Controls->Add(this->button1);
			this->settingspanel->Controls->Add(this->settingsexitbutton);
			this->settingspanel->Controls->Add(this->lightmodebutton);
			this->settingspanel->Controls->Add(this->darkmodebutton);
			this->settingspanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->settingspanel->Location = System::Drawing::Point(0, 0);
			this->settingspanel->Name = L"settingspanel";
			this->settingspanel->Size = System::Drawing::Size(1290, 539);
			this->settingspanel->TabIndex = 12;
			this->settingspanel->Visible = false;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(530, 292);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(289, 154);
			this->button1->TabIndex = 5;
			this->button1->Text = L"SET BACK GROUND IMAGE";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// settingsexitbutton
			// 
			this->settingsexitbutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->settingsexitbutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->settingsexitbutton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsexitbutton.BackgroundImage")));
			this->settingsexitbutton->FlatAppearance->BorderSize = 0;
			this->settingsexitbutton->Font = (gcnew System::Drawing::Font(L"Verdana", 20, System::Drawing::FontStyle::Bold));
			this->settingsexitbutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->settingsexitbutton->Location = System::Drawing::Point(3, 3);
			this->settingsexitbutton->Name = L"settingsexitbutton";
			this->settingsexitbutton->Size = System::Drawing::Size(50, 50);
			this->settingsexitbutton->TabIndex = 4;
			this->settingsexitbutton->UseVisualStyleBackColor = false;
			this->settingsexitbutton->Click += gcnew System::EventHandler(this, &MyForm::settingsexitbutton_Click);
			// 
			// lightmodebutton
			// 
			this->lightmodebutton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lightmodebutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->lightmodebutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lightmodebutton->FlatAppearance->BorderSize = 0;
			this->lightmodebutton->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->lightmodebutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lightmodebutton->Location = System::Drawing::Point(530, 160);
			this->lightmodebutton->Name = L"lightmodebutton";
			this->lightmodebutton->Size = System::Drawing::Size(289, 100);
			this->lightmodebutton->TabIndex = 3;
			this->lightmodebutton->Text = L"LIGHT MODE";
			this->lightmodebutton->UseVisualStyleBackColor = false;
			this->lightmodebutton->Click += gcnew System::EventHandler(this, &MyForm::lightmodebutton_Click);
			// 
			// darkmodebutton
			// 
			this->darkmodebutton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->darkmodebutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->darkmodebutton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->darkmodebutton->FlatAppearance->BorderSize = 0;
			this->darkmodebutton->Font = (gcnew System::Drawing::Font(L"Verdana", 25, System::Drawing::FontStyle::Bold));
			this->darkmodebutton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->darkmodebutton->Location = System::Drawing::Point(530, 38);
			this->darkmodebutton->Name = L"darkmodebutton";
			this->darkmodebutton->Size = System::Drawing::Size(289, 83);
			this->darkmodebutton->TabIndex = 2;
			this->darkmodebutton->Text = L"DARK MODE";
			this->darkmodebutton->UseVisualStyleBackColor = false;
			this->darkmodebutton->Click += gcnew System::EventHandler(this, &MyForm::darkmodebutton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1290, 539);
			this->Controls->Add(this->PasswordPanel);
			this->Controls->Add(this->settingspanel);
			this->Controls->Add(this->DecryptPanel);
			this->Controls->Add(this->InstructionsPanel);
			this->Controls->Add(this->EncryptPanel);
			this->Controls->Add(this->Keypanel);
			this->Controls->Add(this->EncryptMain);
			this->Controls->Add(this->DecryptMainButton);
			this->Controls->Add(this->KeyMain);
			this->Controls->Add(this->PassButton);
			this->Controls->Add(this->SettingsButton);
			this->Controls->Add(this->InstructionButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->EncryptPanel->ResumeLayout(false);
			this->EncryptPanel->PerformLayout();
			this->DecryptPanel->ResumeLayout(false);
			this->DecryptPanel->PerformLayout();
			this->InstructionsPanel->ResumeLayout(false);
			this->InstructionsPanel->PerformLayout();
			this->PasswordPanel->ResumeLayout(false);
			this->PasswordTable->ResumeLayout(false);
			this->PasswordTable->PerformLayout();
			this->Keypanel->ResumeLayout(false);
			this->settingspanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
		// Ensure the file exists and is accessible
	Void EnsureFileExists(const std::string& filePath) {
		std::ifstream inFile(filePath);
		if (!inFile) {
			std::ofstream outFile(filePath);
			if (outFile.is_open()) {
				for each (System::Windows::Forms::TextBox ^ element in elements) {
					outFile << "Default " << msclr::interop::marshal_as<std::string>(element->Name) << " Content\n";
				}
			outFile.close();
			}
			else {
				MessageBox::Show("Failed to create default file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	   // Save text to file
	Void SaveTextToFile() {
		std::ofstream outFile("saved_textbox_content.txt");
		if (outFile.is_open()) {
			for each (System::Windows::Forms::TextBox ^ element in elements) {
				outFile << msclr::interop::marshal_as<std::string>(element->Text) << std::endl;
			}
			outFile.close();
		}
		else {
			MessageBox::Show("Failed to save the content to the file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	   // Load text from file
	Void LoadTextFromFile() {
		std::ifstream inFile("saved_textbox_content.txt");
		if (inFile.is_open()) {
			std::string line;
			int i = 0;

			while (std::getline(inFile, line) && i < elements->Length) {
				elements[i]->Text = gcnew System::String(line.c_str());
				i++;
			}

			inFile.close();
		}
		else {
			MessageBox::Show("No saved file found. Default values will be used.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		loadKeyFromFile();
		// Ensure the default image path exists or dynamically set it
		if (!String::IsNullOrEmpty(selectedImagePath)) {
			this->BackgroundImage = System::Drawing::Image::FromFile(selectedImagePath);
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		}
		else {
			// Default behavior if no image is selected
			this->BackColor = System::Drawing::Color::Black;
		}
	}

	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	}

	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	}
	private: System::Void EncryptMain_Click(System::Object^ sender, System::EventArgs^ e) {
		EncryptPanel->Visible = true;
		InstructionButton->Visible = false;
		SettingsButton->Visible = false;

	}
	private: System::Void SettingsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		settingspanel->Visible = true;
	}
	private: System::Void PassButton_Click(System::Object^ sender, System::EventArgs^ e) {
		EnsureFileExists("saved_textbox_content.txt");
		LoadTextFromFile();
		PasswordPanel->Visible = true;
	}
	private: System::Void InstructionButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InstructionsPanel->Visible = true;
		InstructionButton->Visible = false;
		SettingsButton->Visible = false;
		
	}
	private: System::Void EncryptExitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		EncryptPanel->Visible = false;
		InstructionButton->Visible = true;
		SettingsButton->Visible = true;
	}
	private: System::Void DecryptMainButton_Click(System::Object^ sender, System::EventArgs^ e) {
		DecryptPanel->Visible = true;
		InstructionButton->Visible = false;
		SettingsButton->Visible = false;
	}
	private: System::Void DecryptExitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		DecryptPanel->Visible = false;
		InstructionButton->Visible = true;
		SettingsButton->Visible = true;
	}

	private: System::Void InstructionExit_Click(System::Object^ sender, System::EventArgs^ e) {
		InstructionsPanel->Visible = false;
		InstructionButton->Visible = true;
		SettingsButton->Visible = true;
	}
	private: System::Void PasswordExit_Click(System::Object^ sender, System::EventArgs^ e) {
		PasswordPanel->Visible = false;
		SaveTextToFile();
	}
	private: System::Void generatekeybutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Free previously allocated memory for key if it exists
		if (key != nullptr) {
			delete[] key;
			key = nullptr;
		}
		// Generate a new key and assign it to the class-level variable
		key = keyGen(rng());
		keytextbox->Text = gcnew System::String(key);
	}

	private: System::Void EncryptButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if key is generated
		if (key == nullptr) {
			MessageBox::Show("Please generate a key before encrypting.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Retrieve user input from the TextBox
		std::string inputMessage = msclr::interop::marshal_as<std::string>(EncryptTextBox->Text);
		if (inputMessage.empty()) {
			MessageBox::Show("Please enter a message to encrypt.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		// Perform encryption
		std::string encrypted;
		for (size_t i = 0; i < inputMessage.size(); i++) {
			int shift = key[i % 256] - '0'; // Use key cyclically
			char encryptedch = inputMessage[i] + shift;
			encrypted += encryptedch;
		}
		// Display the encrypted message
		EncryptTextBox->Text = gcnew System::String(encrypted.c_str());
	}
	
	private: System::Void exitkeybutton_Click(System::Object^ sender, System::EventArgs^ e) {
		Keypanel->Visible = false;
	}
	private: System::Void KeyMain_Click(System::Object^ sender, System::EventArgs^ e) {
		Keypanel->Visible = true;
	}
	private: System::Void decryptbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Step 1: Retrieve encrypted message from DecryptTextBox
		std::string encryptedMessage = msclr::interop::marshal_as<std::string>(DecryptTextBox->Text);
		// Step 2: Retrieve key from KeyDecryptTextBox
		std::string key = msclr::interop::marshal_as<std::string>(decryptkeyTextBox->Text);
		// Validate inputs
		if (encryptedMessage.empty()) {
			MessageBox::Show("Please enter an encrypted message.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (key.length() != 256) { // Ensure the key is exactly 256 digits
			MessageBox::Show("The key must be 256 digits long.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Step 3: Perform decryption
		std::string decryptedMessage;
		for (size_t i = 0; i < encryptedMessage.size(); i++) {
			int shift = key[i % 256] - '0'; // Use the key cyclically
			char decryptedChar = encryptedMessage[i] - shift;
			decryptedMessage += decryptedChar;
		}
		// Step 4: Display decrypted message in DecryptTextBox
		DecryptTextBox->Text = gcnew System::String(decryptedMessage.c_str());
	}
	private: System::Void savekeybutton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (key != nullptr) {
			try {
				std::ofstream outFile("key.txt"); // Open the file
				if (outFile.is_open()) {
					outFile << key; // Write the key
					outFile.close();
					MessageBox::Show("Key saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Failed to open the file for saving.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			catch (const std::exception& ex) {
				MessageBox::Show("Error: " + gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("No key to save. Please generate a key first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
   // Function to load the key from a file
	private: System::Void loadKeyFromFile() {
		try {
			std::ifstream inFile("key.txt"); // Open the file
			if (inFile.is_open()) {
				std::string loadedKey;
				std::getline(inFile, loadedKey); // Read the key from the file
				inFile.close();

				if (loadedKey.length() == 256) {
					// Allocate memory for the key and copy the loaded data
					delete[] key; // Free previously allocated memory if any
					key = new char[267];
					std::strcpy(key, loadedKey.c_str());

					// Update the TextBox to display the loaded key
					keytextbox->Text = gcnew System::String(key);
				}
			}
			else {
				MessageBox::Show("No saved key file found.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		catch (const std::exception& ex) {
			MessageBox::Show("Error: " + gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void darkmodebutton_Click(System::Object^ sender, System::EventArgs^ e) {
		EncryptPanel->BackgroundImage = nullptr;
		EncryptPanel->BackColor = System::Drawing::Color::Black;
		EncryptPanel->ForeColor = System::Drawing::Color::White;

		DecryptPanel->BackgroundImage = nullptr;
		DecryptPanel->BackColor = System::Drawing::Color::Black;
		DecryptPanel->ForeColor = System::Drawing::Color::White;

		settingspanel->BackgroundImage = nullptr;
		settingspanel->BackColor = System::Drawing::Color::Black;
		settingspanel->ForeColor = System::Drawing::Color::White;

		InstructionsPanel->BackgroundImage = nullptr;
		InstructionsPanel->BackColor = System::Drawing::Color::Black;
		InstructionsPanel->ForeColor = System::Drawing::Color::White;

		PasswordPanel->BackgroundImage = nullptr;
		PasswordPanel->BackColor = System::Drawing::Color::Black;
		PasswordPanel->ForeColor = System::Drawing::Color::White;

		Keypanel->BackgroundImage = nullptr;
		Keypanel->BackColor = System::Drawing::Color::Black;
		Keypanel->ForeColor = System::Drawing::Color::White;

		this->BackgroundImage = nullptr;
		this->BackColor = System::Drawing::Color::Black;
		this->ForeColor = System::Drawing::Color::White;

		MessageBox::Show("Dark Mode activated!", "Dark Mode", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

private: System::Void lightmodebutton_Click(System::Object^ sender, System::EventArgs^ e) {
	EncryptPanel->BackgroundImage = nullptr;
	EncryptPanel->BackColor = System::Drawing::Color::White;
	EncryptPanel->ForeColor = System::Drawing::Color::Black;

	DecryptPanel->BackgroundImage = nullptr;
	DecryptPanel->BackColor = System::Drawing::Color::White;
	DecryptPanel->ForeColor = System::Drawing::Color::Black;

	settingspanel->BackgroundImage = nullptr;
	settingspanel->BackColor = System::Drawing::Color::White;
	settingspanel->ForeColor = System::Drawing::Color::Black;

	InstructionsPanel->BackgroundImage = nullptr;
	InstructionsPanel->BackColor = System::Drawing::Color::White;
	InstructionsPanel->ForeColor = System::Drawing::Color::Black;

	PasswordPanel->BackgroundImage = nullptr;
	PasswordPanel->BackColor = System::Drawing::Color::White;
	PasswordPanel->ForeColor = System::Drawing::Color::Black;

	Keypanel->BackgroundImage = nullptr;
	Keypanel->BackColor = System::Drawing::Color::White;
	Keypanel->ForeColor = System::Drawing::Color::Black;

	this->BackgroundImage = nullptr;
	this->BackColor = System::Drawing::Color::White;
	this->ForeColor = System::Drawing::Color::Black;

	MessageBox::Show("Light Mode activated!", "Light Mode", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void settingsexitbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	settingspanel->Visible = false;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create OpenFileDialog
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Filter = "Image Files (*.jpg;*.jpeg;*.png;*.bmp)|*.jpg;*.jpeg;*.png;*.bmp";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Get the selected file path
		selectedImagePath = openFileDialog->FileName;

		// Set the background image of the form and/or panels
		if (!String::IsNullOrEmpty(selectedImagePath)) {
			this->BackgroundImage = System::Drawing::Image::FromFile(selectedImagePath);
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;

			settingspanel->BackgroundImage = System::Drawing::Image::FromFile(selectedImagePath);
			settingspanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;

			EncryptPanel->BackgroundImage = System::Drawing::Image::FromFile(selectedImagePath);
			EncryptPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;

			DecryptPanel->BackgroundImage = System::Drawing::Image::FromFile(selectedImagePath);
			DecryptPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;

			Keypanel->BackgroundImage = System::Drawing::Image::FromFile(selectedImagePath);
			Keypanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			
			InstructionsPanel->BackgroundImage = System::Drawing::Image::FromFile(selectedImagePath);
			InstructionsPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			
			PasswordPanel->BackgroundImage = System::Drawing::Image::FromFile(selectedImagePath);
			PasswordPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		}
	}
	else {
		MessageBox::Show("No image selected.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
	private: System::Void copyencryptbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (EncryptTextBox != nullptr && !String::IsNullOrEmpty(EncryptTextBox->Text)) {
			// Copy text to clipboard
			Clipboard::SetText(EncryptTextBox->Text);

			// Show confirmation message
			MessageBox::Show("Text copied to clipboard!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			// Handle case when TextBox is empty
			MessageBox::Show("No text available to copy.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}


private: System::Void copykeybutton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (keytextbox != nullptr && !String::IsNullOrEmpty(keytextbox->Text)) {
		// Copy text to clipboard
		Clipboard::SetText(keytextbox->Text);

		// Show confirmation message
		MessageBox::Show("Text copied to clipboard!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else {
		// Handle case when TextBox is empty
		MessageBox::Show("No text available to copy.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
};
}


