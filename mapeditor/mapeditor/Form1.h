#pragma once
#include <tchar.h>
#using <mscorlib.dll>

namespace mapeditor {
			extern int codemap[64][64];
			extern int codefloormap[64][64];
			extern int codigo_a_por;
			extern int floorcodigo_a_por;
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
	private: System::Windows::Forms::Button^  button5;
			 System::Boolean floor;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
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
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->tab1->SuspendLayout();
			this->tab2->SuspendLayout();
			this->tab3->SuspendLayout();
			this->tab4->SuspendLayout();
			this->tab5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
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
			this->listBox4->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"Vida - 15%", L"Vida - 25%", L"Vida - 50%", L"Arma 1", 
				L"Arma 2", L"Arma 3", L"Municoes", L"Chave 1", L"Chave 2", L"Inicio Jogo", L"Fim Jogo"});
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
			this->label1->Location = System::Drawing::Point(756, 540);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Descricao";
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
			this->button1->Location = System::Drawing::Point(759, 627);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 38);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Abrir mapa";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(851, 627);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 38);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Gravar Mapa";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(851, 671);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 38);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Floor Codes Off";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(759, 671);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(86, 38);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Floor Codes On";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"map";
			this->saveFileDialog1->Filter = L"map files|*.map";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"map";
			this->openFileDialog1->FileName = L"e1m1.map";
			this->openFileDialog1->Filter = L"map files|*.map";
			this->openFileDialog1->ReadOnlyChecked = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(759, 556);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(83, 35);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Sem Nada";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(260, 260);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 738);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button5);
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
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tab1->ResumeLayout(false);
			this->tab2->ResumeLayout(false);
			this->tab3->ResumeLayout(false);
			this->tab4->ResumeLayout(false);
			this->tab5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ChangeColor(System::Object^  sender, System::EventArgs^  e) {
				 int x,y;
				 if(this->floor == false) {
					 System::Windows::Forms::PictureBox^  t = static_cast<System::Windows::Forms::PictureBox^>(sender);
					 array<String^>^ a = t->Text->Split(' ');
					 // x e y do floor
					 x = System::Int32::Parse(a[0]);
					 y = System::Int32::Parse(a[1]);
					 // atribuir ao mapa
					 codemap[x-1][y-1]=codigo_a_por;
					 // desenhar a cor no quadrado
					this->pintar_quadrados(t, codigo_a_por);
				}
			 }
	
	private: System::Void ChangeFloorColor(System::Object^  sender, System::EventArgs^  e) {
				 int x,y;
				 //this->label1->Focus();
				 System::Windows::Forms::PictureBox^  t = static_cast<System::Windows::Forms::PictureBox^>(sender);
				 array<String^>^ a = t->Text->Split(' ');
				 // x e y do floor
				 x = System::Int32::Parse(a[0]);
				 y = System::Int32::Parse(a[1]);
				 // atribuir ao mapa
				 codefloormap[x-1][y-1]=floorcodigo_a_por;
				 // desenhar a cor no quadrado
				 this->pintar_quadrados_floor(t, floorcodigo_a_por);
			 }

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
 private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
						 /*for(int i=1;i<=64;i++){
							for(int f=1;f<=64;f++){
								e->Graphics->FillRectangle( gcnew SolidBrush( ColorTranslator::FromHtml("Black") ), (11*f)+1, (11*i)+1, 8, 8 );
							}
						}*/
					}
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			/* floor codes */
			 this->floor = false;
			this->floormap = gcnew array< array<System::Windows::Forms::PictureBox^>^ > (64);
			for(int i=1;i<=64;i++){
				 this->floormap[i-1] = gcnew array<System::Windows::Forms::PictureBox^>(64);
				 for(int e=1;e<=64;e++){
					this->floormap[i-1][e-1] = (gcnew System::Windows::Forms::PictureBox());
					//this->floormap[i-1][e-1]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
					//		static_cast<System::Int32>(static_cast<System::Byte>(64)));
					this->floormap[i-1][e-1]->BackColor = System::Drawing::Color::Gray;
					this->floormap[i-1][e-1]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					//this->floormap[i-1][e-1]->BorderStyle = System::Windows::Forms::BorderStyle::None;
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
					this->floormap[i-1][e-1]->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::code_MouseMove);
					this->floormap[i-1][e-1]->Visible = false;
					this->Controls->Add(this->floormap[i-1][e-1]);
 
				 }
			}
			
			// map codes 
			this->map = gcnew array< array<System::Windows::Forms::PictureBox^>^ > (64);
			for(int i=1;i<=64;i++){
				 this->map[i-1] = gcnew array<System::Windows::Forms::PictureBox^>(64);
				 for(int e=1;e<=64;e++){
					this->map[i-1][e-1] = (gcnew System::Windows::Forms::PictureBox());
					//this->map[i-1][e-1]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
					//		static_cast<System::Int32>(static_cast<System::Byte>(64)));
					this->map[i-1][e-1]->BackColor = System::Drawing::Color::Gray;
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
					this->map[i-1][e-1]->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::code_MouseMove);
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
			this->listBox3->Items->Add("Direccao E");
			this->listBox3->Items->Add("Direccao O");
			this->listBox3->Items->Add("Direccao N");
			this->listBox3->Items->Add("Direccao S");
			this->listBox3->Items->Add("Direccao NE");
			this->listBox3->Items->Add("Direccao SE");
			this->listBox3->Items->Add("Direccao NO");
			this->listBox3->Items->Add("Direccao SO");
			// floorcodes listbox
			for(int i=1;i<=50;i++){
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
			for(int i=0;i<64;i++){
				for(int e=0;e<64;e++){
					codemap[i][e]=0;
					codefloormap[i][e]=0;
				}
			}
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			this->floor = false;
			 for(int i=1;i<=64;i++){
				 for(int e=1;e<=64;e++){
					 //this->map[i-1][e-1]->Visible = true;
					 this->floormap[i-1][e-1]->Visible = false;
				 }
			}
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			this->floor = true;
			 for(int i=1;i<=64;i++){
				 for(int e=1;e<=64;e++){
					 //this->map[i-1][e-1]->Visible = false;
					 this->floormap[i-1][e-1]->Visible = true;
				 }
			}
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
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 // gravar ficheiro
			 if( this->saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			 {
				try 
				{
					System::IO::File::Delete(this->saveFileDialog1->FileName);
					//Pass the file path and file name to the StreamReader constructor.
					System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(System::IO::File::OpenWrite(this->saveFileDialog1->FileName));

					//64
					sw->WriteLine("64");
					//tecto
					sw->WriteLine("1001");
					//chao
					sw->WriteLine("1001");

					//64 linhas for sure
					for(int i=0;i<64;i++)
					{
						for(int e=0;e<63;e++)
						{
							sw->Write(System::Int32(codemap[i][e]).ToString());
							sw->Write(",");
						}
						sw->Write(System::Int32(codemap[i][63]).ToString());
						sw->WriteLine();
					}
					//enter
					sw->WriteLine();
					//64 linhas for sure
					for(int i=0;i<64;i++)
					{
						for(int e=0;e<63;e++)
						{
							sw->Write(System::Int32(codefloormap[i][e]).ToString());
							sw->Write(",");
						}
						sw->WriteLine(codefloormap[i][63]);
					}
					//Close the file.
					sw->Close();
				}
				catch(Exception^ e)
				{
					Console::WriteLine("Exception: {0}",e->Message);
				
				}
			}
		 }
private: System::Void pintar_quadrados(System::Windows::Forms::PictureBox^ aqui, int cor){
			 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			 if(cor>1000 && cor<2000){
				// paredes
			    aqui->Image = nullptr ;
				aqui->BackColor = System::Drawing::Color::FromArgb(cor*cor*5%255,cor*cor*5%255,203);
				this->label1->Text = "SAVE: Textura:" + this->listBox1->Items[cor-1000-1];

			 }else
			 if(cor>3000 && cor<4000){
				// portas
				 this->label1->Text = "SAVE: Porta:" + this->listBox2->Items[cor-3000-1];
				 switch(cor){
					case 3001:
						aqui->BackColor = System::Drawing::Color::FromArgb(180,255,0);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"porta_norte_normal")));
						break;
					case 3002:
						aqui->BackColor = System::Drawing::Color::FromArgb(185,255,10);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"porta_oeste_normal")));
						break;	
					case 3003:
						aqui->BackColor = System::Drawing::Color::FromArgb(120,255,0);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"porta_norte_chave1")));
						break;
					case 3004:
						aqui->BackColor = System::Drawing::Color::FromArgb(125,255,40);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"porta_oeste_chave1")));
						break;
					case 3005:
						aqui->BackColor = System::Drawing::Color::FromArgb(80,255,0);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"porta_norte_chave2")));
						break;
					case 3006:
						aqui->BackColor = System::Drawing::Color::FromArgb(105,255,40);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"porta_oeste_chave2")));
						break;
				}

			}else
				if(cor>4000 && cor<5000){
				// items
					this->label1->Text = "SAVE: Item:" + this->listBox4->Items[cor-4000-1];
				switch(cor){
					case 4001:
						aqui->BackColor = System::Drawing::Color::FromArgb(255,88,86);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"vida_15")));
						break;
					case 4002:
						aqui->BackColor = System::Drawing::Color::FromArgb(255,45,43);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"vida_25")));
						break;	
					case 4003:
						aqui->BackColor = System::Drawing::Color::FromArgb(255,1,1);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"vida_50")));
						break;
					case 4004:
						aqui->BackColor = System::Drawing::Color::FromArgb(201,201,201);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"gun_1")));
						break;
					case 4005:
						aqui->BackColor = System::Drawing::Color::FromArgb(211,211,211);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"gun_2")));
						break;
					case 4006:
						aqui->BackColor = System::Drawing::Color::FromArgb(222,222,222);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"gun_3")));
						break;
					case 4007:
						aqui->BackColor = System::Drawing::Color::FromArgb(1,255,255);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"municoes")));
						break;
					case 4008:
						aqui->BackColor = System::Drawing::Color::FromArgb(255,240,1);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"chave_1")));
						break;
					case 4009:
						aqui->BackColor = System::Drawing::Color::FromArgb(204,192,1);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"chave_2")));
						break;
					case 4010:
						aqui->BackColor = System::Drawing::Color::FromArgb(120,255,1);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"start")));
						break;
					case 4011:
						aqui->BackColor = System::Drawing::Color::FromArgb(96,203,1);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"finish")));
						break;
				}
			}else
				if(cor>2000 && cor<3000){
				// guardas
					if(cor>=2001 && cor<=2008){
						aqui->BackColor = System::Drawing::Color::FromArgb(255,175,50);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"guarda_small")));
					}
					if(cor>=2009 && cor<=2016){
						aqui->BackColor = System::Drawing::Color::FromArgb(255,146,41);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"guarda_medium")));
					}
					if(cor>=2017 && cor<=2024){
						aqui->BackColor = System::Drawing::Color::FromArgb(254,114,1);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"guarda_intermedio")));
					}
					if(cor>=2025 && cor<=2032){
						aqui->BackColor = System::Drawing::Color::FromArgb(193,87,1);
						aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"guarda_heavy")));
					}
					if(cor>=2033){
						switch(cor){
							case 2033:
								aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"0")));
								break;
							case 2034:
								aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"180")));
								break;
							case 2035:
								aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"90")));
								break;
							case 2036:
								aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"270")));
								break;
							case 2037:
								aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"45")));
								break;
							case 2038:
								aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"315")));
								break;
							case 2039:
								aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"135")));
								break;
							case 2040:
								aqui->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"225")));
								break;
						}
					}
					this->label1->Text = "SAVE: Guarda:" + this->listBox3->Items[cor-2000-1];
				}else if(cor==0){
					aqui->BackColor = System::Drawing::Color::Gray;
					aqui->Image = nullptr ;
					this->label1->Text = "SAVE: Sem nada";
				}
			else
				this->label1->Text = "SAVE: WTF?! nao pode ser.. falta codigo "+cor;
		}
private: System::Void pintar_quadrados_floor(System::Windows::Forms::PictureBox^ aqui, int cor){
			 int c = cor-9000;
			 if(cor==0)
				 aqui->BackColor = System::Drawing::Color::Gray;
			 else
				aqui->BackColor = System::Drawing::Color::FromArgb(c*50%255,c*5%255,c*10%255);
			}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 // ler ficheiro
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
						for(int e=0;e<64;e++)
						{
							codemap[i][e]=System::Int32::Parse(a[e]);
							// funcao para colorir o mapa +1
							this->pintar_quadrados(this->map[i][e],codemap[i][e]);
						}
					}
					//enter
					line = sr->ReadLine();
					//64 linhas for sure
					for(int i=0;i<64;i++)
					{
						line = sr->ReadLine();
						array<String^>^ a = line->Split(',');
						for(int e=0;e<64;e++)
						{
							codefloormap[i][e]=System::Int32::Parse(a[e]);
							// funcao para colorir o mapa
							this->pintar_quadrados_floor(this->floormap[i][e],codefloormap[i][e]);
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
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			this->listBox2->ClearSelected();
			 this->listBox3->ClearSelected();
			 this->listBox1->ClearSelected();
			 this->listBox5->ClearSelected();
			 this->listBox4->ClearSelected();
			 codigo_a_por = 0;
			 floorcodigo_a_por = 0;
		 }
private: System::Void code_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 	int x,y;
			if(this->floor==false){
				 System::Windows::Forms::PictureBox^  t = static_cast<System::Windows::Forms::PictureBox^>(sender);
				 array<String^>^ a = t->Text->Split(' ');
				 // x e y do floor
				 x = System::Int32::Parse(a[0]);
				 y = System::Int32::Parse(a[1]);

				 if(codemap[x-1][y-1]>1000 && codemap[x-1][y-1]<2000){
					// paredes
					this->label1->Text = "Textura:" + this->listBox1->Items[codemap[x-1][y-1]-1000-1];

				 }else
				 if(codemap[x-1][y-1]>3000 && codemap[x-1][y-1]<4000){
					// portas
					 this->label1->Text = "Porta:" + this->listBox2->Items[codemap[x-1][y-1]-3000-1];
					 

				}else
					if(codemap[x-1][y-1]>4000 && codemap[x-1][y-1]<5000){
					// items
						this->label1->Text = "Item:" + this->listBox4->Items[codemap[x-1][y-1]-4000-1];
					
				}else
					if(codemap[x-1][y-1]>2000 && codemap[x-1][y-1]<3000){
					// guardas
						this->label1->Text = "Guarda:" + this->listBox3->Items[codemap[x-1][y-1]-2000-1];
					}else if(codemap[x-1][y-1]==0){
						this->label1->Text = "Sem nada";
					}
				else
					this->label1->Text = "WTF?! nao pode ser.. falta codigo "+codemap[x-1][y-1];
			}
		 }
 private: System::Void floorcode_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 	int x,y;
			 //this->label1->Focus();
			 System::Windows::Forms::PictureBox^  t = static_cast<System::Windows::Forms::PictureBox^>(sender);
			 array<String^>^ a = t->Text->Split(' ');
			 // x e y do floor
			 x = System::Int32::Parse(a[0]);
			 y = System::Int32::Parse(a[1]);

			this->label1->Text = "Floorcode: "+this->listBox5->Items[codefloormap[x-1][y-1]-9000-1];
		 }
};
}

