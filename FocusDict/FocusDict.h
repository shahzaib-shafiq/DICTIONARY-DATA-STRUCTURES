#pragma once
#include <msclr\marshal_cppstd.h>
#include "AddForm.h"
#include "EditForm.h"
#include "Hash.h"
using namespace std;
namespace Dictionary_pro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	Hash* hash = new Hash();
	public ref class FocusDict : public System::Windows::Forms::Form
	{
	public:
		FocusDict(void)
		{
			InitializeComponent();
		}

	protected:
		~FocusDict()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ Wordlist;
	private: System::Windows::Forms::TextBox^ Input;
	private: System::Windows::Forms::Button^ Searchbtn;
	private: System::Windows::Forms::Button^ Addbtn;
	private: System::Windows::Forms::Button^ Deletebtn;
	private: System::Windows::Forms::Button^ Editbtn;
	private: System::Windows::Forms::RichTextBox^ ContentRichTxt;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;




	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->Wordlist = (gcnew System::Windows::Forms::ListBox());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->Searchbtn = (gcnew System::Windows::Forms::Button());
			this->Addbtn = (gcnew System::Windows::Forms::Button());
			this->Deletebtn = (gcnew System::Windows::Forms::Button());
			this->Editbtn = (gcnew System::Windows::Forms::Button());
			this->ContentRichTxt = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// Wordlist
			// 
			this->Wordlist->BackColor = System::Drawing::Color::Red;
			this->Wordlist->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Wordlist->ForeColor = System::Drawing::Color::Black;
			this->Wordlist->FormattingEnabled = true;
			this->Wordlist->Location = System::Drawing::Point(12, 79);
			this->Wordlist->Name = L"Wordlist";
			this->Wordlist->Size = System::Drawing::Size(296, 130);
			this->Wordlist->TabIndex = 0;
			this->Wordlist->SelectedIndexChanged += gcnew System::EventHandler(this, &FocusDict::Wordlist_SelectedIndexChanged);
			// 
			// Input
			// 
			this->Input->BackColor = System::Drawing::Color::Red;
			this->Input->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Input->Location = System::Drawing::Point(12, 13);
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(296, 20);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &FocusDict::Input_TextChanged);
			// 
			// Searchbtn
			// 
			this->Searchbtn->BackColor = System::Drawing::Color::Red;
			this->Searchbtn->Location = System::Drawing::Point(12, 39);
			this->Searchbtn->Name = L"Searchbtn";
			this->Searchbtn->Size = System::Drawing::Size(184, 34);
			this->Searchbtn->TabIndex = 2;
			this->Searchbtn->Text = L"Search";
			this->Searchbtn->UseVisualStyleBackColor = false;
			this->Searchbtn->Click += gcnew System::EventHandler(this, &FocusDict::Searchbtn_Click);
			// 
			// Addbtn
			// 
			this->Addbtn->BackColor = System::Drawing::Color::Red;
			this->Addbtn->Location = System::Drawing::Point(326, 12);
			this->Addbtn->Name = L"Addbtn";
			this->Addbtn->Size = System::Drawing::Size(104, 29);
			this->Addbtn->TabIndex = 3;
			this->Addbtn->Text = L"Add";
			this->Addbtn->UseVisualStyleBackColor = false;
			this->Addbtn->Click += gcnew System::EventHandler(this, &FocusDict::Addbtn_Click);
			// 
			// Deletebtn
			// 
			this->Deletebtn->BackColor = System::Drawing::Color::Red;
			this->Deletebtn->Location = System::Drawing::Point(553, 13);
			this->Deletebtn->Name = L"Deletebtn";
			this->Deletebtn->Size = System::Drawing::Size(104, 28);
			this->Deletebtn->TabIndex = 4;
			this->Deletebtn->Text = L"Delete";
			this->Deletebtn->UseVisualStyleBackColor = false;
			this->Deletebtn->Click += gcnew System::EventHandler(this, &FocusDict::Deletebtn_Click);
			// 
			// Editbtn
			// 
			this->Editbtn->BackColor = System::Drawing::Color::Red;
			this->Editbtn->Location = System::Drawing::Point(436, 13);
			this->Editbtn->Name = L"Editbtn";
			this->Editbtn->Size = System::Drawing::Size(111, 29);
			this->Editbtn->TabIndex = 5;
			this->Editbtn->Text = L"Edit";
			this->Editbtn->UseVisualStyleBackColor = false;
			this->Editbtn->Click += gcnew System::EventHandler(this, &FocusDict::Editbtn_Click);
			// 
			// ContentRichTxt
			// 
			this->ContentRichTxt->BackColor = System::Drawing::Color::Red;
			this->ContentRichTxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ContentRichTxt->ForeColor = System::Drawing::Color::Black;
			this->ContentRichTxt->Location = System::Drawing::Point(326, 79);
			this->ContentRichTxt->Name = L"ContentRichTxt";
			this->ContentRichTxt->Size = System::Drawing::Size(331, 130);
			this->ContentRichTxt->TabIndex = 6;
			this->ContentRichTxt->Text = L"";
			this->ContentRichTxt->TextChanged += gcnew System::EventHandler(this, &FocusDict::ContentRichTxt_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"dictionary.txt";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &FocusDict::OpenFileDialog1_FileOk);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->richTextBox1->BackColor = System::Drawing::Color::Red;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::Black;
			this->richTextBox1->Location = System::Drawing::Point(195, 215);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(262, 115);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"SHAHZAIB SHAFIQ        20F-0317";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &FocusDict::richTextBox1_TextChanged);
			// 
			// FocusDict
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Blue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(669, 338);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->ContentRichTxt);
			this->Controls->Add(this->Editbtn);
			this->Controls->Add(this->Deletebtn);
			this->Controls->Add(this->Addbtn);
			this->Controls->Add(this->Searchbtn);
			this->Controls->Add(this->Input);
			this->Controls->Add(this->Wordlist);
			this->Name = L"FocusDict";
			this->Text = L"DICTIONARY";
			this->TransparencyKey = System::Drawing::Color::White;
			this->Load += gcnew System::EventHandler(this, &FocusDict::FocusDict_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Wordlist_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void Searchbtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			ContentRichTxt->Text = "";
			std::string s = msclr::interop::marshal_as<std::string>(Wordlist->SelectedItem->ToString());
			Word* entry = hash->Search(s);
			ContentRichTxt->Text += "WORD: ";
			ContentRichTxt->Text += Wordlist->SelectedItem->ToString();
			string tmp = entry->type->type_name;
			String^ dumb = gcnew String(tmp.c_str());
			ContentRichTxt->Text += "\nTYPE: " + dumb;
			ContentRichTxt->Text += "\nMEANING: ";
		
		for (int i = 0; i < entry->type->meanings.size(); i++) {
			tmp = entry->type->meanings[i]->def;
			dumb = gcnew String(tmp.c_str());
			ContentRichTxt->Text += "\n- " + dumb;
			for (int j = 0; j < entry->type->meanings[i]->example.size(); j++) {
				tmp = entry->type->meanings[i]->example[j];
				dumb = gcnew String(tmp.c_str());
				ContentRichTxt->Text += "\nEx: " + dumb;
			}
		}
		}
		catch (...) {
			cout << "exception";
		}
	}
	private: System::Void Addbtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		AddForm^ addform = gcnew AddForm();
		addform->ShowDialog();
		if (addform->isValid())
		{
			String^ dumb = gcnew String(addform->w->word.c_str());
			Wordlist->Items->Add(dumb);
			hash->addTable(addform->w);
			hash->updateFile();
		}
	}
	private: System::Void Deletebtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Wordlist->SelectedIndex == -1) {
			MessageBox::Show("You need to selected one word");
		}
		else {
			std::string s = msclr::interop::marshal_as<std::string>(Wordlist->SelectedItem->ToString());
			if (hash->deleteWord(s)) {
				hash->updateFile();
				Wordlist->Items->Remove(Wordlist->SelectedItem);
			}
			else {
				MessageBox::Show("Something went wrong");
			}
		}
	}
	private: System::Void Editbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		EditForm^ editform = gcnew EditForm();
		editform->ShowDialog();
		if (hash->editWord(editform->w)) {
		}
	}
	private: System::Void ContentRichTxt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void OpenFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void FocusDict_Load(System::Object^ sender, System::EventArgs^ e) {
		std::ifstream myfile;
		std::string str;
		myfile.open("dictionary.txt");

		if (myfile.is_open())
		{
			while (std::getline(myfile, str))
			{
				if ((int)str[0] - '@' == 0)
				{
					str = str.substr(1, str.length());
					String^ dumb = gcnew String(str.c_str());
					Wordlist->Items->Add(dumb);
				}
			}
		}
	}
	private: System::Void Input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->Text != "") {
			int index = Wordlist->FindString(Input->Text);
			if (index != -1) {
				Wordlist->SetSelected(index, true);
			}
			else {
				Wordlist->ClearSelected();
			}
		}
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
