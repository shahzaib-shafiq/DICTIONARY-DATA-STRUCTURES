#pragma once
#include <msclr\marshal_cppstd.h>
#include <string>
#include <vector>
#include "Hash.h"
using namespace std;

namespace Dictionary_pro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class AddForm : public System::Windows::Forms::Form
	{
	public:
		AddForm(void)
		{
			InitializeComponent();
		}
		Word* w = new Word();
		TYPE* t = new TYPE();
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	public:
		Hash* hash = new Hash();

		int isValid()
		{
			if (w->word == "" || w->type->type_name == "" || w->type->meanings.size() == 0)	return 0;
			return 1;
		}
	protected:
		~AddForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ WordTextbox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ TypeTextbox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ MeaningTextbox;
	private: System::Windows::Forms::Button^ AddMeaningbtn;
	private: System::Windows::Forms::RichTextBox^ ExRichTextbox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ AddWordbtn;
	protected:


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->WordTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TypeTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->MeaningTextbox = (gcnew System::Windows::Forms::TextBox());
			this->AddMeaningbtn = (gcnew System::Windows::Forms::Button());
			this->ExRichTextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->AddWordbtn = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Red;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter the word";
			// 
			// WordTextbox
			// 
			this->WordTextbox->BackColor = System::Drawing::Color::Red;
			this->WordTextbox->Location = System::Drawing::Point(90, 9);
			this->WordTextbox->Name = L"WordTextbox";
			this->WordTextbox->Size = System::Drawing::Size(219, 20);
			this->WordTextbox->TabIndex = 1;
			this->WordTextbox->TextChanged += gcnew System::EventHandler(this, &AddForm::WordTextbox_TextChanged);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Red;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Location = System::Drawing::Point(12, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Type";
			// 
			// TypeTextbox
			// 
			this->TypeTextbox->BackColor = System::Drawing::Color::Red;
			this->TypeTextbox->Location = System::Drawing::Point(90, 35);
			this->TypeTextbox->Name = L"TypeTextbox";
			this->TypeTextbox->Size = System::Drawing::Size(219, 20);
			this->TypeTextbox->TabIndex = 3;
			this->TypeTextbox->TextChanged += gcnew System::EventHandler(this, &AddForm::TypeTextbox_TextChanged);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Red;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Location = System::Drawing::Point(12, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Meaning";
			// 
			// MeaningTextbox
			// 
			this->MeaningTextbox->BackColor = System::Drawing::Color::Red;
			this->MeaningTextbox->Location = System::Drawing::Point(90, 63);
			this->MeaningTextbox->Name = L"MeaningTextbox";
			this->MeaningTextbox->Size = System::Drawing::Size(219, 20);
			this->MeaningTextbox->TabIndex = 5;
			this->MeaningTextbox->TextChanged += gcnew System::EventHandler(this, &AddForm::MeaningTextbox_TextChanged);
			// 
			// AddMeaningbtn
			// 
			this->AddMeaningbtn->BackColor = System::Drawing::Color::Red;
			this->AddMeaningbtn->Location = System::Drawing::Point(344, 63);
			this->AddMeaningbtn->Name = L"AddMeaningbtn";
			this->AddMeaningbtn->Size = System::Drawing::Size(101, 28);
			this->AddMeaningbtn->TabIndex = 6;
			this->AddMeaningbtn->Text = L"Add Meaning";
			this->AddMeaningbtn->UseVisualStyleBackColor = false;
			this->AddMeaningbtn->Click += gcnew System::EventHandler(this, &AddForm::AddMeaningbtn_Click);
			// 
			// ExRichTextbox
			// 
			this->ExRichTextbox->BackColor = System::Drawing::Color::Red;
			this->ExRichTextbox->Location = System::Drawing::Point(90, 94);
			this->ExRichTextbox->Name = L"ExRichTextbox";
			this->ExRichTextbox->Size = System::Drawing::Size(219, 131);
			this->ExRichTextbox->TabIndex = 7;
			this->ExRichTextbox->Text = L"";
			this->ExRichTextbox->TextChanged += gcnew System::EventHandler(this, &AddForm::ExRichTextbox_TextChanged);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Red;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label4->Location = System::Drawing::Point(12, 94);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Examples";
			// 
			// AddWordbtn
			// 
			this->AddWordbtn->BackColor = System::Drawing::Color::Red;
			this->AddWordbtn->Location = System::Drawing::Point(150, 231);
			this->AddWordbtn->Name = L"AddWordbtn";
			this->AddWordbtn->Size = System::Drawing::Size(159, 31);
			this->AddWordbtn->TabIndex = 9;
			this->AddWordbtn->Text = L"Add Word";
			this->AddWordbtn->UseVisualStyleBackColor = false;
			this->AddWordbtn->Click += gcnew System::EventHandler(this, &AddForm::AddWordbtn_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::Red;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(324, 173);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(172, 65);
			this->richTextBox1->TabIndex = 10;
			this->richTextBox1->Text = L"SHAHZAIB SHAFIQ        20F-0317";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &AddForm::richTextBox1_TextChanged);
			// 
			// AddForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Blue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(537, 273);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->AddWordbtn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->ExRichTextbox);
			this->Controls->Add(this->AddMeaningbtn);
			this->Controls->Add(this->MeaningTextbox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->TypeTextbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->WordTextbox);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"AddForm";
			this->Text = L"AddForm";
			this->Load += gcnew System::EventHandler(this, &AddForm::AddForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FlowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void WordTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TypeTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MeaningTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void AddMeaningbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (WordTextbox->Text == "" || TypeTextbox->Text == "" || MeaningTextbox->Text == "" || ExRichTextbox->Text == "") {
		MessageBox::Show("Error!!!");
	}
	else {

		std::string s = msclr::interop::marshal_as<std::string>(TypeTextbox->Text);
		if (t->meanings.size() == 0) 
		{
			t = hash->createType(s);
		}
		s = msclr::interop::marshal_as<std::string>(MeaningTextbox->Text);
		Meaning* m = hash->createMeaning(s);
		for (int i = 0; i < ExRichTextbox->Lines->Length; i++) {
			String^ dumb = ExRichTextbox->Lines[i];
			s = msclr::interop::marshal_as<std::string>(dumb);
			if (s != "") m->example.push_back(s);
		}
		t->meanings.push_back(m);
		MeaningTextbox->Clear();
		ExRichTextbox->Clear();
	}
}
private: System::Void ExRichTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void AddWordbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (WordTextbox->Text == "" || TypeTextbox->Text == "" || t->meanings.size() == 0) {
		MessageBox::Show("Not successful!");
	}
	else {
		std::string s = msclr::interop::marshal_as<std::string>(WordTextbox->Text);
		if (hash->space(s) == true)
		{
			if (hash->mila(s)==true)
			{
				w = hash->createWord(s,t);
				MessageBox::Show("Successful!");
				this->Hide();
			}
			else {
				MessageBox::Show("ERROR! DUPLICATE NOT ALLOWED.");
				this->Hide();
			}
		}
		else
		{
			MessageBox::Show("ERROR! Words spaces NOT ALLOWED.");
			this->Hide();
		}
	}
}
private: System::Void AddForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
