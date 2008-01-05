#pragma once
#include <tchar.h>
#using <mscorlib.dll>

namespace mapeditor {
			int codemap[63][63];
			int codefloormap[63][63];
			int codigo_a_por;
			int floorcodigo_a_por;
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
	private: array<array<System::Windows::Forms::PictureBox^>^>^ map;
	private: array<array<System::Windows::Forms::PictureBox^>^>^ floormap;
	
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tab1;
	private: System::Windows::Forms::TabPage^  tab2;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TabPage^  tab3;
	private: System::Windows::Forms::TabPage^  tab4;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::TabPage^  tab5;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::ListBox^  listBox4;
	private: System::Windows::Forms::ListBox^  listBox5;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


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
			this->tab1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tab2 = (gcnew System::Windows::Forms::TabPage());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->tab3 = (gcnew System::Windows::Forms::TabPage());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->tab4 = (gcnew System::Windows::Forms::TabPage());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->tab5 = (gcnew System::Windows::Forms::TabPage());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tab1->SuspendLayout();
			this->tab2->SuspendLayout();
			this->tab3->SuspendLayout();
			this->tab4->SuspendLayout();
			this->tab5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tab1);
			this->tabControl1->Controls->Add(this->tab2);
			this->tabControl1->Controls->Add(this->tab3);
			this->tabControl1->Controls->Add(this->tab4);
			this->tabControl1->Controls->Add(this->tab5);
			this->tabControl1->Location = System::Drawing::Point(727, 7);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(253, 527);
			this->tabControl1->TabIndex = 2;
			// 
			// tab1
			// 
			this->tab1->Controls->Add(this->listBox1);
			this->tab1->Location = System::Drawing::Point(4, 22);
			this->tab1->Name = L"tab1";
			this->tab1->Padding = System::Windows::Forms::Padding(3);
			this->tab1->Size = System::Drawing::Size(245, 501);
			this->tab1->TabIndex = 0;
			this->tab1->Text = L"Paredes";
			this->tab1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(0, 0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(245, 498);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// tab2
			// 
			this->tab2->Controls->Add(this->listBox2);
			this->tab2->Location = System::Drawing::Point(4, 22);
			this->tab2->Name = L"tab2";
			this->tab2->Padding = System::Windows::Forms::Padding(3);
			this->tab2->Size = System::Drawing::Size(245, 501);
			this->tab2->TabIndex = 1;
			this->tab2->Text = L"Portas";
			this->tab2->UseVisualStyleBackColor = true;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Porta Normal N-S ( |  )", L"Porta Normal O-E (--)", 
				L"Porta Chave 1 Norte-Sul ( | )", L"Porta Chave 1 O-E (--)", L"Porta Chave 2 Norte-Sul ( | )", L"Porta Chave 2 O-E (--)"});
			this->listBox2->Location = System::Drawing::Point(0, 0);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(245, 498);
			this->listBox2->TabIndex = 0;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox2_SelectedIndexChanged);
			// 
			// tab3
			// 
			this->tab3->Controls->Add(this->listBox3);
			this->tab3->Location = System::Drawing::Point(4, 22);
			this->tab3->Name = L"tab3";
			this->tab3->Size = System::Drawing::Size(245, 501);
			this->tab3->TabIndex = 2;
			this->tab3->Text = L"Guardas";
			this->tab3->UseVisualStyleBackColor = true;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(0, 0);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(245, 498);
			this->listBox3->TabIndex = 0;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox3_SelectedIndexChanged);
			// 
			// tab4
			// 
			this->tab4->Controls->Add(this->listBox4);
			this->tab4->Location = System::Drawing::Point(4, 22);
			this->tab4->Name = L"tab4";
			this->tab4->Size = System::Drawing::Size(245, 501);
			this->tab4->TabIndex = 3;
			this->tab4->Text = L"Items";
			this->tab4->UseVisualStyleBackColor = true;
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"Vida - 5%", L"Vida - 15%", L"Vida - 25%", L"Arma 2", 
				L"Arma 3", L"Arma 4", L"Municoes", L"Chave 1", L"Chave 2", L"Inicio Jogo", L"Fim Jogo"});
			this->listBox4->Location = System::Drawing::Point(0, 0);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(245, 498);
			this->listBox4->TabIndex = 0;
			this->listBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox4_SelectedIndexChanged);
			// 
			// tab5
			// 
			this->tab5->Controls->Add(this->listBox5);
			this->tab5->Location = System::Drawing::Point(4, 22);
			this->tab5->Name = L"tab5";
			this->tab5->Size = System::Drawing::Size(245, 501);
			this->tab5->TabIndex = 4;
			this->tab5->Text = L"Floor";
			this->tab5->UseVisualStyleBackColor = true;
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->Location = System::Drawing::Point(0, 0);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(245, 498);
			this->listBox5->TabIndex = 0;
			this->listBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox5_SelectedIndexChanged);
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
			this->button1->Location = System::Drawing::Point(767, 602);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 38);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Abrir mapa";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(862, 602);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 38);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Gravar Mapa";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(767, 556);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(89, 40);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Map codes";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(862, 556);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(87, 40);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Floor Codes";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"map";
			this->saveFileDialog1->Filter = L"map files|*.map";
			this->saveFileDialog1->InitialDirectory = L"..\\\\";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"map";
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"map files|*.map";
			this->openFileDialog1->InitialDirectory = L"..\\\\";
			this->openFileDialog1->ReadOnlyChecked = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 659);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MapEditor";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tab1->ResumeLayout(false);
			this->tab2->ResumeLayout(false);
			this->tab3->ResumeLayout(false);
			this->tab4->ResumeLayout(false);
			this->tab5->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ChangeColor(System::Object^  sender, System::EventArgs^  e) {
				 int x,y;
				 this->label1->Focus();
				 System::Windows::Forms::PictureBox^  t = static_cast<System::Windows::Forms::PictureBox^>(sender);
				 t->BackColor = System::Drawing::Color::FromArgb(10,40,50);
				 array<String^>^ a = t->Text->Split(' ');
				 // x e y do floor
				 x = System::Int32::Parse(a[0]);
				 y = System::Int32::Parse(a[1]);
				 // 
			 }
	
	private: System::Void ChangeFloorColor(System::Object^  sender, System::EventArgs^  e) {
				 this->label1->Focus();
				 System::Windows::Forms::PictureBox^  t = static_cast<System::Windows::Forms::PictureBox^>(sender);
				 t->BackColor = System::Drawing::Color::FromArgb(70,40,50);
			 }

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			/* floor codes */
			/*
			this->floormap = gcnew array< array<System::Windows::Forms::PictureBox^>^ > (64);
			for(int i=1;i<=64;i++){
				 this->floormap[i-1] = gcnew array<System::Windows::Forms::PictureBox^>(64);
				 for(int e=1;e<=64;e++){
					this->floormap[i-1][e-1] = (gcnew System::Windows::Forms::PictureBox());
					//this->floormap[i-1][e-1]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
					//		static_cast<System::Int32>(static_cast<System::Byte>(64)));
					this->floormap[i-1][e-1]->BackColor = System::Drawing::Color::White;
					this->floormap[i-1][e-1]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					//this->floormap[i-1][e-1]->Cursor = System::Windows::Forms::Cursors::Arrow;
					//this->floormap[i-1][e-1]->Font = (gcnew System::Drawing::Font(L"Wingdings 3", 2.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					//	static_cast<System::Byte>(2)));
					//this->floormap[i-1][e-1]->ForeColor = System::Drawing::Color::White;
					this->floormap[i-1][e-1]->Location = System::Drawing::Point((11*e)+1, (11*i)+1);
					this->floormap[i-1][e-1]->Text = i+" "+e;
					//this->floormap[i-1][e-1]->ReadOnly = true;
					this->floormap[i-1][e-1]->Size = System::Drawing::Size(8, 8);
					this->floormap[i-1][e-1]->TabIndex = 1;
					this->floormap[i-1][e-1]->TabStop = false;
					//this->floormap[i-1][e-1]->WordWrap = false;
					this->floormap[i-1][e-1]->Click += gcnew System::EventHandler(this, &Form1::ChangeFloorColor);
					this->floormap[i-1][e-1]->Visible = false;
					this->Controls->Add(this->floormap[i-1][e-1]);
				 }
			}*/
			
			// map codes 
			this->map = gcnew array< array<System::Windows::Forms::PictureBox^>^ > (64);
			for(int i=1;i<=64;i++){
				 this->map[i-1] = gcnew array<System::Windows::Forms::PictureBox^>(64);
				 for(int e=1;e<=64;e++){
					this->map[i-1][e-1] = (gcnew System::Windows::Forms::PictureBox());
					this->map[i-1][e-1]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
							static_cast<System::Int32>(static_cast<System::Byte>(64)));
					//this->map[i-1][e-1]->BackColor = System::Drawing::Color::White;
					//this->map[i-1][e-1]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					//this->map[i-1][e-1]->Cursor = System::Windows::Forms::Cursors::Arrow;
					//this->map[i-1][e-1]->Font = (gcnew System::Drawing::Font(L"Wingdings 3", 2.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					//	static_cast<System::Byte>(2)));
					//this->map[i-1][e-1]->ForeColor = System::Drawing::Color::White;
					this->map[i-1][e-1]->Location = System::Drawing::Point((11*e), (11*i));
					this->map[i-1][e-1]->Text = i+" "+e;
					//this->map[i-1][e-1]->ReadOnly = true;
					this->map[i-1][e-1]->Size = System::Drawing::Size(11, 11);
					this->map[i-1][e-1]->TabIndex = 0;
					this->map[i-1][e-1]->TabStop = false;
					//this->map[i-1][e-1]->WordWrap = false;
					this->map[i-1][e-1]->Click += gcnew System::EventHandler(this, &Form1::ChangeColor);
					this->Controls->Add(this->map[i-1][e-1]);
				 }
			}

			
			/* inicializar listas */
			String ^ g = L"Guarda";
			for(int i=1;i<=4;i++){
				//for(int skill=1;skill<=4;skill++)
				{
					// parado						
						// N
						this->listBox3->Items->Add(g+" "+i+"/Parado/N");
						// S
						this->listBox3->Items->Add(g+" "+i+"/Parado/S");
						// E
						this->listBox3->Items->Add(g+" "+i+"/Parado/E");
						// W
						this->listBox3->Items->Add(g+" "+i+"/Parado/W");
					// andar
						// N
						this->listBox3->Items->Add(g+" "+i+"/Andar/N");
						// S
						this->listBox3->Items->Add(g+" "+i+"/Andar/S");
						// E
						this->listBox3->Items->Add(g+" "+i+"/Andar/E");
						// W
						this->listBox3->Items->Add(g+" "+i+"/Andar/W");
				}
			}
			// floorcodes listbox
			for(int i=1;i<=99;i++){
				this->listBox5->Items->Add("Floorcode "+i);
			}
			// ler texturas
			String^ line;
			try 
			{
				//Pass the file path and file name to the StreamReader constructor.
	#ifdef _DEBUG
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(System::IO::File::OpenRead("..\\..\\data\\textures\\textures.def"));
	#else
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(System::IO::File::OpenRead("..\\data\\textures\\textures.def"));
	#endif
				//Read the first line of text.
				//line = sr->ReadLine();

				//Continue to read until you reach end of file.
				while (!sr->EndOfStream) 
				{
					//Write the lie to console window.
					//Console::WriteLine(line);
					//Read the next line.
					line = sr->ReadLine();
					array<String^>^ a = line->Split(' ');
					line =line->Remove(0,line->IndexOf(' ')+1);
					line =line->Remove(0,line->IndexOf(' ')+1);
					this->listBox1->Items->Add(line+" ("+a[0]+")");
				}

				//Close the file.
				sr->Close();
			}
			catch(Exception^ e)
			{
				Console::WriteLine("Exception: {0}",e->Message);
			}
			codigo_a_por=0;
			floorcodigo_a_por=0;
			for(int i=1;i<64;i++){
				for(int e=1;e<64;e++){
					codemap[i][e]=0;
					codefloormap[i][e]=0;
				}
			}
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			for(int i=1;i<=64;i++){
				 for(int e=1;e<=64;e++){
					 //this->map[i-1][e-1]->Visible = true;
					 this->floormap[i-1][e-1]->Visible = false;
				 }
			}
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			for(int i=1;i<=64;i++){
				 for(int e=1;e<=64;e++){
					 //this->map[i-1][e-1]->Visible = false;
					 this->floormap[i-1][e-1]->Visible = true;
				 }
			}
		 }
private: System::Void escrever_ficheiro(){


			//Pass the file path and file name to the StreamWriter Constructor.
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(System::IO::File::OpenWrite("textures.def"));

			//Write a line of text.
			sw->WriteLine("Hello World!!");

			//Write a second line of text.
			sw->WriteLine("From the StreamWriter class");

			//Close the file.
			sw->Close();
	
			
		
	}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 // paredes
			 System::Windows::Forms::ListBox^  t = static_cast<System::Windows::Forms::ListBox^>(sender);
			 codigo_a_por = t->SelectedIndex + 1001;
			 this->listBox2->ClearSelected();
			 this->listBox3->ClearSelected();
			 this->listBox4->ClearSelected();
		 }
private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 // portas
			 System::Windows::Forms::ListBox^  t = static_cast<System::Windows::Forms::ListBox^>(sender);
			 codigo_a_por = t->SelectedIndex + 3001;
			 this->listBox1->ClearSelected();
			 this->listBox3->ClearSelected();
			 this->listBox4->ClearSelected();
		 }
private: System::Void listBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 // guardas
			 System::Windows::Forms::ListBox^  t = static_cast<System::Windows::Forms::ListBox^>(sender);
			 codigo_a_por = t->SelectedIndex + 2001;
			 this->listBox2->ClearSelected();
			 this->listBox1->ClearSelected();
			 this->listBox4->ClearSelected();
		 }
private: System::Void listBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 // items
			 System::Windows::Forms::ListBox^  t = static_cast<System::Windows::Forms::ListBox^>(sender);
			 codigo_a_por = t->SelectedIndex + 4001;
			 this->listBox2->ClearSelected();
			 this->listBox3->ClearSelected();
			 this->listBox1->ClearSelected();
		 }
private: System::Void listBox5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 // floorcodes
			 System::Windows::Forms::ListBox^  t = static_cast<System::Windows::Forms::ListBox^>(sender);
			 floorcodigo_a_por = t->SelectedIndex + 9001;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if( this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			 {
				String^ line;
				try 
				{
					//Pass the file path and file name to the StreamReader constructor.
					System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(System::IO::File::OpenRead(this->openFileDialog1->FileName));

					//64
					line = sr->ReadLine();
					//tecto
					line = sr->ReadLine();
					//chao
					line = sr->ReadLine();

					//64 linhas for sure
					for(int i=0;i<64;i++)
					{
						line = sr->ReadLine();
						array<String^>^ a = line->Split(',');
						for(int e=0;e<64;i++)
						{
							codemap[i][e]=System::Int32::Parse(a[e]);
							// funcao para colorir o mapa

						}
					}
					//enter
					line = sr->ReadLine();
					//64 linhas for sure
					for(int i=0;i<64;i++)
					{
						line = sr->ReadLine();
						array<String^>^ a = line->Split(',');
						for(int e=0;e<64;i++)
						{
							codefloormap[i][e]=System::Int32::Parse(a[e]);
							// funcao para colorir o mapa

						}
					}
					//Close the file.
					sr->Close();
				}
				catch(Exception^ e)
				{
					Console::WriteLine("Exception: {0}",e->Message);
				
				}
			}
		 }
};
}

