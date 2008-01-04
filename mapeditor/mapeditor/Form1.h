#pragma once


namespace mapeditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: array<array<System::Windows::Forms::TextBox^>^>^ map;
	private: array<array<System::Windows::Forms::TextBox^>^>^ floormap;
	
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(743, 7);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(246, 584);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(238, 558);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(238, 558);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 3;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Wingdings 3", 2.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(2)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(4, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(11, 11);
			this->textBox1->TabIndex = 0;
			this->textBox1->TabStop = false;
			this->textBox1->Visible = false;
			this->textBox1->WordWrap = false;
			this->textBox1->Click += gcnew System::EventHandler(this, &Form1::ChangeColor);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(747, 639);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 38);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Abrir mapa";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(842, 639);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 38);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Gravar Mapa";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(747, 593);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(89, 40);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Map codes";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(842, 593);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(87, 40);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Floor Codes";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 719);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ChangeColor(System::Object^  sender, System::EventArgs^  e) {
				 this->label1->Focus();
				 System::Windows::Forms::TextBox^  t = static_cast<System::Windows::Forms::TextBox^>(sender);
				 t->BackColor = System::Drawing::Color::FromArgb(10,40,50);
			 }
	
	private: System::Void ChangeFloorColor(System::Object^  sender, System::EventArgs^  e) {
				 this->label1->Focus();
				 System::Windows::Forms::TextBox^  t = static_cast<System::Windows::Forms::TextBox^>(sender);
				 t->BackColor = System::Drawing::Color::FromArgb(70,40,50);
			 }

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			this->map = gcnew array< array<System::Windows::Forms::TextBox^>^ > (64);
			for(int i=1;i<=64;i++){
				 this->map[i-1] = gcnew array<System::Windows::Forms::TextBox^>(64);
				 for(int e=1;e<=64;e++){
					this->map[i-1][e-1] = (gcnew System::Windows::Forms::TextBox());
					this->map[i-1][e-1]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
							static_cast<System::Int32>(static_cast<System::Byte>(64)));
					//this->map[i-1][e-1]->BackColor = System::Drawing::Color::White;
					this->map[i-1][e-1]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					this->map[i-1][e-1]->Cursor = System::Windows::Forms::Cursors::Arrow;
					this->map[i-1][e-1]->Font = (gcnew System::Drawing::Font(L"Wingdings 3", 2.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(2)));
					this->map[i-1][e-1]->ForeColor = System::Drawing::Color::White;
					this->map[i-1][e-1]->Location = System::Drawing::Point((11*e), (11*i));
					this->map[i-1][e-1]->Name = L"map";
					this->map[i-1][e-1]->ReadOnly = true;
					this->map[i-1][e-1]->Size = System::Drawing::Size(11, 11);
					this->map[i-1][e-1]->TabIndex = 0;
					this->map[i-1][e-1]->TabStop = false;
					this->map[i-1][e-1]->WordWrap = false;
					this->map[i-1][e-1]->Click += gcnew System::EventHandler(this, &Form1::ChangeColor);
					this->Controls->Add(this->map[i-1][e-1]);
				 }
			}

			/* floor codes */
			this->floormap = gcnew array< array<System::Windows::Forms::TextBox^>^ > (64);
			for(int i=1;i<=64;i++){
				 this->floormap[i-1] = gcnew array<System::Windows::Forms::TextBox^>(64);
				 for(int e=1;e<=64;e++){
					this->floormap[i-1][e-1] = (gcnew System::Windows::Forms::TextBox());
					this->floormap[i-1][e-1]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
							static_cast<System::Int32>(static_cast<System::Byte>(64)));
					//this->floormap[i-1][e-1]->BackColor = System::Drawing::Color::White;
					this->floormap[i-1][e-1]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					this->floormap[i-1][e-1]->Cursor = System::Windows::Forms::Cursors::Arrow;
					this->floormap[i-1][e-1]->Font = (gcnew System::Drawing::Font(L"Wingdings 3", 2.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(2)));
					this->floormap[i-1][e-1]->ForeColor = System::Drawing::Color::White;
					this->floormap[i-1][e-1]->Location = System::Drawing::Point((11*e), (11*i));
					this->floormap[i-1][e-1]->Name = L"map";
					this->floormap[i-1][e-1]->ReadOnly = true;
					this->floormap[i-1][e-1]->Size = System::Drawing::Size(11, 11);
					this->floormap[i-1][e-1]->TabIndex = 0;
					this->floormap[i-1][e-1]->TabStop = false;
					this->floormap[i-1][e-1]->WordWrap = false;
					this->floormap[i-1][e-1]->Click += gcnew System::EventHandler(this, &Form1::ChangeFloorColor);
					this->floormap[i-1][e-1]->Visible = false;
					this->Controls->Add(this->floormap[i-1][e-1]);
				 }
			}


		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			for(int i=1;i<=64;i++){
				 for(int e=1;e<=64;e++){
					 this->map[i-1][e-1]->Visible = true;
					 this->floormap[i-1][e-1]->Visible = false;
				 }
			}
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			for(int i=1;i<=64;i++){
				 for(int e=1;e<=64;e++){
					 this->map[i-1][e-1]->Visible = false;
					 this->floormap[i-1][e-1]->Visible = true;
				 }
			}
		 }
};
}

