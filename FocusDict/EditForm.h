#pragma once
#include <msclr\marshal_cppstd.h>
#include "Hash.h"
#include <string>
using namespace std;
namespace Dictionary_pro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class EditForm : public System::Windows::Forms::Form
	{
	public:
		EditForm(void)
		{
			InitializeComponent();
		}
		Hash* hash = new Hash();
		Word* w = new Word();
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	public:
		TYPE* t = new TYPE();
	protected:
		~EditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ WordTextBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ TypeTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ MeaningTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RichTextBox^ ExRichTextBox;

	private: System::Windows::Forms::Button^ AddMeaningbtn;
	private: System::Windows::Forms::Button^ EditWordbtn;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->WordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->MeaningTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ExRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->AddMeaningbtn = (gcnew System::Windows::Forms::Button());
			this->EditWordbtn = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Red;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Edit the word:";
			this->label1->Click += gcnew System::EventHandler(this, &EditForm::label1_Click);
			// 
			// WordTextBox
			// 
			this->WordTextBox->BackColor = System::Drawing::Color::Red;
			this->WordTextBox->Location = System::Drawing::Point(90, 12);
			this->WordTextBox->Name = L"WordTextBox";
			this->WordTextBox->Size = System::Drawing::Size(201, 20);
			this->WordTextBox->TabIndex = 1;
			this->WordTextBox->TextChanged += gcnew System::EventHandler(this, &EditForm::WordTextBox_TextChanged);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Red;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Location = System::Drawing::Point(12, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Edit the type:";
			// 
			// TypeTextBox
			// 
			this->TypeTextBox->BackColor = System::Drawing::Color::Red;
			this->TypeTextBox->Location = System::Drawing::Point(90, 43);
			this->TypeTextBox->Name = L"TypeTextBox";
			this->TypeTextBox->Size = System::Drawing::Size(201, 20);
			this->TypeTextBox->TabIndex = 3;
			this->TypeTextBox->TextChanged += gcnew System::EventHandler(this, &EditForm::TypeTextBox_TextChanged);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Red;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Location = System::Drawing::Point(12, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Meaning:";
			// 
			// MeaningTextBox
			// 
			this->MeaningTextBox->BackColor = System::Drawing::Color::Red;
			this->MeaningTextBox->Location = System::Drawing::Point(90, 69);
			this->MeaningTextBox->Name = L"MeaningTextBox";
			this->MeaningTextBox->Size = System::Drawing::Size(256, 20);
			this->MeaningTextBox->TabIndex = 5;
			this->MeaningTextBox->TextChanged += gcnew System::EventHandler(this, &EditForm::MeaningTextBox_TextChanged);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Red;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(362, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Examples";
			// 
			// ExRichTextBox
			// 
			this->ExRichTextBox->BackColor = System::Drawing::Color::Red;
			this->ExRichTextBox->Location = System::Drawing::Point(431, 12);
			this->ExRichTextBox->Name = L"ExRichTextBox";
			this->ExRichTextBox->Size = System::Drawing::Size(224, 152);
			this->ExRichTextBox->TabIndex = 7;
			this->ExRichTextBox->Text = L"";
			this->ExRichTextBox->TextChanged += gcnew System::EventHandler(this, &EditForm::ExRichTextBox_TextChanged);
			// 
			// AddMeaningbtn
			// 
			this->AddMeaningbtn->BackColor = System::Drawing::Color::Red;
			this->AddMeaningbtn->ForeColor = System::Drawing::Color::Black;
			this->AddMeaningbtn->Location = System::Drawing::Point(12, 107);
			this->AddMeaningbtn->Name = L"AddMeaningbtn";
			this->AddMeaningbtn->Size = System::Drawing::Size(146, 41);
			this->AddMeaningbtn->TabIndex = 8;
			this->AddMeaningbtn->Text = L"Add Meaning";
			this->AddMeaningbtn->UseVisualStyleBackColor = false;
			this->AddMeaningbtn->Click += gcnew System::EventHandler(this, &EditForm::AddMeaningbtn_Click);
			// 
			// EditWordbtn
			// 
			this->EditWordbtn->BackColor = System::Drawing::Color::Red;
			this->EditWordbtn->Location = System::Drawing::Point(187, 107);
			this->EditWordbtn->Name = L"EditWordbtn";
			this->EditWordbtn->Size = System::Drawing::Size(159, 41);
			this->EditWordbtn->TabIndex = 9;
			this->EditWordbtn->Text = L"Edit Word";
			this->EditWordbtn->UseVisualStyleBackColor = false;
			this->EditWordbtn->Click += gcnew System::EventHandler(this, &EditForm::EditWordbtn_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::Red;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(156, 170);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(326, 143);
			this->richTextBox1->TabIndex = 10;
			this->richTextBox1->Text = L"SHAHZAIB SHAFIQ        20F-0317";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &EditForm::richTextBox1_TextChanged);
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Blue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(665, 325);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->EditWordbtn);
			this->Controls->Add(this->AddMeaningbtn);
			this->Controls->Add(this->ExRichTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->MeaningTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->TypeTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->WordTextBox);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"EditForm";
			this->Text = L"EditForm";
			this->Load += gcnew System::EventHandler(this, &EditForm::EditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void WordTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TypeTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void AddMeaningbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (WordTextBox->Text == "" || TypeTextBox->Text == "" || MeaningTextBox->Text == "" || ExRichTextBox->Text == "") {
			MessageBox::Show("Error!!!");
		}
		else {
			std::string s = msclr::interop::marshal_as<std::string>(TypeTextBox->Text);
			if (t->meanings.size() == 0) {
				t = hash->createType(s);
			}
			s = msclr::interop::marshal_as<std::string>(MeaningTextBox->Text);
			Meaning* m = hash->createMeaning(s);
			for (int i = 0; i < ExRichTextBox->Lines->Length; i++) {
				String^ dumb = ExRichTextBox->Lines[i];
				s = msclr::interop::marshal_as<std::string>(dumb);
				if (s != "") m->example.push_back(s);
			}
			t->meanings.push_back(m);
			MeaningTextBox->Clear();
			ExRichTextBox->Clear();
		}
	}
private: System::Void MeaningTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ExRichTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void EditWordbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (WordTextBox->Text == "" || TypeTextBox->Text == "" || t->meanings.size() == 0) {
		MessageBox::Show("Not successful!");
	}
	else {
		std::string s = msclr::interop::marshal_as<std::string>(WordTextBox->Text);
		Word* tmp = hash->Search(s);
		if (tmp) {
			w = hash->createWord(s, t);
			MessageBox::Show("Successful!");
		}
		else {
			MessageBox::Show("Not found that word!");
		}
		
		this->Hide();
	}
}
private: System::Void EditForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
