#pragma once
#include "Manager.h"

namespace SudokuA7Forms {

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
		Manager* m_pManager;
	private: System::Windows::Forms::Button^  btExit;
	public: 
		array<TextBox^>^ m_aTextBoxes;
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
	private: System::Windows::Forms::Button^  btLoad;
	private: System::Windows::Forms::Button^  btSolve;
	protected: 

	protected: 

	private: System::Windows::Forms::ComboBox^  cmbPuzzleList;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox10;
	private: System::Windows::Forms::GroupBox^  groupBox9;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox3;


	private: System::Windows::Forms::Button^  btHelp;

	private: System::Windows::Forms::Button^  btSave;
	private: System::Windows::Forms::GroupBox^  groupBox11;
	private: System::Windows::Forms::TextBox^  textBox72;
	private: System::Windows::Forms::TextBox^  textBox71;
	private: System::Windows::Forms::TextBox^  textBox70;
	private: System::Windows::Forms::TextBox^  textBox63;
	private: System::Windows::Forms::TextBox^  textBox62;
	private: System::Windows::Forms::TextBox^  textBox61;
	private: System::Windows::Forms::TextBox^  textBox77;
	private: System::Windows::Forms::TextBox^  textBox76;
	private: System::Windows::Forms::TextBox^  textBox69;
	private: System::Windows::Forms::TextBox^  textBox68;
	private: System::Windows::Forms::TextBox^  textBox67;
	private: System::Windows::Forms::TextBox^  textBox60;
	private: System::Windows::Forms::TextBox^  textBox59;
	private: System::Windows::Forms::TextBox^  textBox58;
	private: System::Windows::Forms::TextBox^  textBox75;
	private: System::Windows::Forms::TextBox^  textBox74;
	private: System::Windows::Forms::TextBox^  textBox73;
	private: System::Windows::Forms::TextBox^  textBox66;
	private: System::Windows::Forms::TextBox^  textBox65;
	private: System::Windows::Forms::TextBox^  textBox64;
	private: System::Windows::Forms::TextBox^  textBox57;
	private: System::Windows::Forms::TextBox^  textBox56;
	private: System::Windows::Forms::TextBox^  textBox55;
	private: System::Windows::Forms::TextBox^  textBox54;
	private: System::Windows::Forms::TextBox^  textBox53;
	private: System::Windows::Forms::TextBox^  textBox52;
	private: System::Windows::Forms::TextBox^  textBox45;
	private: System::Windows::Forms::TextBox^  textBox44;
	private: System::Windows::Forms::TextBox^  textBox43;
	private: System::Windows::Forms::TextBox^  textBox36;
	private: System::Windows::Forms::TextBox^  textBox35;
	private: System::Windows::Forms::TextBox^  textBox34;
	private: System::Windows::Forms::TextBox^  textBox51;
	private: System::Windows::Forms::TextBox^  textBox50;
	private: System::Windows::Forms::TextBox^  textBox49;
	private: System::Windows::Forms::TextBox^  textBox42;
	private: System::Windows::Forms::TextBox^  textBox41;
	private: System::Windows::Forms::TextBox^  textBox40;
	private: System::Windows::Forms::TextBox^  textBox33;
	private: System::Windows::Forms::TextBox^  textBox32;
	private: System::Windows::Forms::TextBox^  textBox31;
	private: System::Windows::Forms::TextBox^  textBox48;
	private: System::Windows::Forms::TextBox^  textBox47;
	private: System::Windows::Forms::TextBox^  textBox46;
	private: System::Windows::Forms::TextBox^  textBox39;
	private: System::Windows::Forms::TextBox^  textBox38;
	private: System::Windows::Forms::TextBox^  textBox37;
	private: System::Windows::Forms::TextBox^  textBox30;
	private: System::Windows::Forms::TextBox^  textBox29;
	private: System::Windows::Forms::TextBox^  textBox28;
	private: System::Windows::Forms::TextBox^  textBox27;
	private: System::Windows::Forms::TextBox^  textBox26;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::TextBox^  textBox1;



	private: System::Windows::Forms::TextBox^  textBox81;
	private: System::Windows::Forms::TextBox^  textBox80;
	private: System::Windows::Forms::TextBox^  textBox79;
	private: System::Windows::Forms::TextBox^  textBox78;


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
			this->btLoad = (gcnew System::Windows::Forms::Button());
			this->btSolve = (gcnew System::Windows::Forms::Button());
			this->cmbPuzzleList = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox81 = (gcnew System::Windows::Forms::TextBox());
			this->textBox80 = (gcnew System::Windows::Forms::TextBox());
			this->textBox79 = (gcnew System::Windows::Forms::TextBox());
			this->textBox72 = (gcnew System::Windows::Forms::TextBox());
			this->textBox71 = (gcnew System::Windows::Forms::TextBox());
			this->textBox70 = (gcnew System::Windows::Forms::TextBox());
			this->textBox63 = (gcnew System::Windows::Forms::TextBox());
			this->textBox62 = (gcnew System::Windows::Forms::TextBox());
			this->textBox61 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox78 = (gcnew System::Windows::Forms::TextBox());
			this->textBox77 = (gcnew System::Windows::Forms::TextBox());
			this->textBox76 = (gcnew System::Windows::Forms::TextBox());
			this->textBox69 = (gcnew System::Windows::Forms::TextBox());
			this->textBox68 = (gcnew System::Windows::Forms::TextBox());
			this->textBox67 = (gcnew System::Windows::Forms::TextBox());
			this->textBox60 = (gcnew System::Windows::Forms::TextBox());
			this->textBox59 = (gcnew System::Windows::Forms::TextBox());
			this->textBox58 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox75 = (gcnew System::Windows::Forms::TextBox());
			this->textBox74 = (gcnew System::Windows::Forms::TextBox());
			this->textBox73 = (gcnew System::Windows::Forms::TextBox());
			this->textBox66 = (gcnew System::Windows::Forms::TextBox());
			this->textBox65 = (gcnew System::Windows::Forms::TextBox());
			this->textBox64 = (gcnew System::Windows::Forms::TextBox());
			this->textBox57 = (gcnew System::Windows::Forms::TextBox());
			this->textBox56 = (gcnew System::Windows::Forms::TextBox());
			this->textBox55 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox54 = (gcnew System::Windows::Forms::TextBox());
			this->textBox53 = (gcnew System::Windows::Forms::TextBox());
			this->textBox52 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45 = (gcnew System::Windows::Forms::TextBox());
			this->textBox44 = (gcnew System::Windows::Forms::TextBox());
			this->textBox43 = (gcnew System::Windows::Forms::TextBox());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->textBox34 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox51 = (gcnew System::Windows::Forms::TextBox());
			this->textBox50 = (gcnew System::Windows::Forms::TextBox());
			this->textBox49 = (gcnew System::Windows::Forms::TextBox());
			this->textBox42 = (gcnew System::Windows::Forms::TextBox());
			this->textBox41 = (gcnew System::Windows::Forms::TextBox());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox48 = (gcnew System::Windows::Forms::TextBox());
			this->textBox47 = (gcnew System::Windows::Forms::TextBox());
			this->textBox46 = (gcnew System::Windows::Forms::TextBox());
			this->textBox39 = (gcnew System::Windows::Forms::TextBox());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btHelp = (gcnew System::Windows::Forms::Button());
			this->btSave = (gcnew System::Windows::Forms::Button());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->btExit = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->SuspendLayout();
			// 
			// btLoad
			// 
			this->btLoad->Enabled = false;
			this->btLoad->Location = System::Drawing::Point(120, 15);
			this->btLoad->Name = L"btLoad";
			this->btLoad->Size = System::Drawing::Size(60, 21);
			this->btLoad->TabIndex = 1;
			this->btLoad->Text = L"Load";
			this->btLoad->UseVisualStyleBackColor = true;
			this->btLoad->Click += gcnew System::EventHandler(this, &Form1::btLoad_Click);
			// 
			// btSolve
			// 
			this->btSolve->Enabled = false;
			this->btSolve->Location = System::Drawing::Point(91, 399);
			this->btSolve->Name = L"btSolve";
			this->btSolve->Size = System::Drawing::Size(60, 21);
			this->btSolve->TabIndex = 2;
			this->btSolve->Text = L"Solve";
			this->btSolve->UseVisualStyleBackColor = true;
			this->btSolve->Click += gcnew System::EventHandler(this, &Form1::btSolve_Click);
			// 
			// cmbPuzzleList
			// 
			this->cmbPuzzleList->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbPuzzleList->FormattingEnabled = true;
			this->cmbPuzzleList->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Puzzle 1 - Easy", L"Puzzle 2 - Medium", L"Puzzle 3 - Easy", 
				L"Puzzle 4 - Hard", L"Puzzle 5 - Hard"});
			this->cmbPuzzleList->Location = System::Drawing::Point(5, 16);
			this->cmbPuzzleList->Name = L"cmbPuzzleList";
			this->cmbPuzzleList->Size = System::Drawing::Size(109, 21);
			this->cmbPuzzleList->TabIndex = 1;
			this->cmbPuzzleList->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cmbPuzzleList_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Controls->Add(this->groupBox10);
			this->groupBox1->Controls->Add(this->groupBox9);
			this->groupBox1->Controls->Add(this->groupBox8);
			this->groupBox1->Controls->Add(this->groupBox7);
			this->groupBox1->Controls->Add(this->groupBox6);
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Location = System::Drawing::Point(12, 58);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(285, 336);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sudoku Puzzle";
			// 
			// groupBox10
			// 
			this->groupBox10->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox10->Controls->Add(this->textBox81);
			this->groupBox10->Controls->Add(this->textBox80);
			this->groupBox10->Controls->Add(this->textBox79);
			this->groupBox10->Controls->Add(this->textBox72);
			this->groupBox10->Controls->Add(this->textBox71);
			this->groupBox10->Controls->Add(this->textBox70);
			this->groupBox10->Controls->Add(this->textBox63);
			this->groupBox10->Controls->Add(this->textBox62);
			this->groupBox10->Controls->Add(this->textBox61);
			this->groupBox10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox10->Location = System::Drawing::Point(192, 227);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(87, 101);
			this->groupBox10->TabIndex = 8;
			this->groupBox10->TabStop = false;
			// 
			// textBox81
			// 
			this->textBox81->Location = System::Drawing::Point(60, 74);
			this->textBox81->Name = L"textBox81";
			this->textBox81->Size = System::Drawing::Size(21, 21);
			this->textBox81->TabIndex = 9;
			this->textBox81->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox81->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox80
			// 
			this->textBox80->Location = System::Drawing::Point(33, 74);
			this->textBox80->Name = L"textBox80";
			this->textBox80->Size = System::Drawing::Size(21, 21);
			this->textBox80->TabIndex = 8;
			this->textBox80->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox80->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox79
			// 
			this->textBox79->Location = System::Drawing::Point(6, 74);
			this->textBox79->Name = L"textBox79";
			this->textBox79->Size = System::Drawing::Size(21, 21);
			this->textBox79->TabIndex = 7;
			this->textBox79->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox79->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox72
			// 
			this->textBox72->Location = System::Drawing::Point(60, 47);
			this->textBox72->Name = L"textBox72";
			this->textBox72->Size = System::Drawing::Size(21, 21);
			this->textBox72->TabIndex = 6;
			this->textBox72->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox72->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox71
			// 
			this->textBox71->Location = System::Drawing::Point(33, 47);
			this->textBox71->Name = L"textBox71";
			this->textBox71->Size = System::Drawing::Size(21, 21);
			this->textBox71->TabIndex = 5;
			this->textBox71->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox71->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox70
			// 
			this->textBox70->Location = System::Drawing::Point(6, 47);
			this->textBox70->Name = L"textBox70";
			this->textBox70->Size = System::Drawing::Size(21, 21);
			this->textBox70->TabIndex = 4;
			this->textBox70->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox70->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox63
			// 
			this->textBox63->Location = System::Drawing::Point(60, 20);
			this->textBox63->Name = L"textBox63";
			this->textBox63->Size = System::Drawing::Size(21, 21);
			this->textBox63->TabIndex = 3;
			this->textBox63->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox63->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox62
			// 
			this->textBox62->Location = System::Drawing::Point(33, 20);
			this->textBox62->Name = L"textBox62";
			this->textBox62->Size = System::Drawing::Size(21, 21);
			this->textBox62->TabIndex = 2;
			this->textBox62->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox62->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox61
			// 
			this->textBox61->Location = System::Drawing::Point(6, 20);
			this->textBox61->Name = L"textBox61";
			this->textBox61->Size = System::Drawing::Size(21, 21);
			this->textBox61->TabIndex = 1;
			this->textBox61->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox61->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// groupBox9
			// 
			this->groupBox9->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox9->Controls->Add(this->textBox78);
			this->groupBox9->Controls->Add(this->textBox77);
			this->groupBox9->Controls->Add(this->textBox76);
			this->groupBox9->Controls->Add(this->textBox69);
			this->groupBox9->Controls->Add(this->textBox68);
			this->groupBox9->Controls->Add(this->textBox67);
			this->groupBox9->Controls->Add(this->textBox60);
			this->groupBox9->Controls->Add(this->textBox59);
			this->groupBox9->Controls->Add(this->textBox58);
			this->groupBox9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox9->Location = System::Drawing::Point(99, 227);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(87, 101);
			this->groupBox9->TabIndex = 7;
			this->groupBox9->TabStop = false;
			// 
			// textBox78
			// 
			this->textBox78->Location = System::Drawing::Point(60, 74);
			this->textBox78->Name = L"textBox78";
			this->textBox78->Size = System::Drawing::Size(21, 21);
			this->textBox78->TabIndex = 9;
			this->textBox78->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox78->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox77
			// 
			this->textBox77->Location = System::Drawing::Point(33, 74);
			this->textBox77->Name = L"textBox77";
			this->textBox77->Size = System::Drawing::Size(21, 21);
			this->textBox77->TabIndex = 8;
			this->textBox77->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox77->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox76
			// 
			this->textBox76->Location = System::Drawing::Point(6, 74);
			this->textBox76->Name = L"textBox76";
			this->textBox76->Size = System::Drawing::Size(21, 21);
			this->textBox76->TabIndex = 7;
			this->textBox76->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox76->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox69
			// 
			this->textBox69->Location = System::Drawing::Point(60, 47);
			this->textBox69->Name = L"textBox69";
			this->textBox69->Size = System::Drawing::Size(21, 21);
			this->textBox69->TabIndex = 6;
			this->textBox69->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox69->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox68
			// 
			this->textBox68->Location = System::Drawing::Point(33, 47);
			this->textBox68->Name = L"textBox68";
			this->textBox68->Size = System::Drawing::Size(21, 21);
			this->textBox68->TabIndex = 5;
			this->textBox68->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox68->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox67
			// 
			this->textBox67->Location = System::Drawing::Point(6, 47);
			this->textBox67->Name = L"textBox67";
			this->textBox67->Size = System::Drawing::Size(21, 21);
			this->textBox67->TabIndex = 4;
			this->textBox67->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox67->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox60
			// 
			this->textBox60->Location = System::Drawing::Point(60, 20);
			this->textBox60->Name = L"textBox60";
			this->textBox60->Size = System::Drawing::Size(21, 21);
			this->textBox60->TabIndex = 3;
			this->textBox60->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox60->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox59
			// 
			this->textBox59->Location = System::Drawing::Point(33, 20);
			this->textBox59->Name = L"textBox59";
			this->textBox59->Size = System::Drawing::Size(21, 21);
			this->textBox59->TabIndex = 2;
			this->textBox59->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox59->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox58
			// 
			this->textBox58->Location = System::Drawing::Point(6, 20);
			this->textBox58->Name = L"textBox58";
			this->textBox58->Size = System::Drawing::Size(21, 21);
			this->textBox58->TabIndex = 1;
			this->textBox58->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox58->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// groupBox8
			// 
			this->groupBox8->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox8->Controls->Add(this->textBox75);
			this->groupBox8->Controls->Add(this->textBox74);
			this->groupBox8->Controls->Add(this->textBox73);
			this->groupBox8->Controls->Add(this->textBox66);
			this->groupBox8->Controls->Add(this->textBox65);
			this->groupBox8->Controls->Add(this->textBox64);
			this->groupBox8->Controls->Add(this->textBox57);
			this->groupBox8->Controls->Add(this->textBox56);
			this->groupBox8->Controls->Add(this->textBox55);
			this->groupBox8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox8->Location = System::Drawing::Point(6, 227);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(87, 101);
			this->groupBox8->TabIndex = 6;
			this->groupBox8->TabStop = false;
			// 
			// textBox75
			// 
			this->textBox75->Location = System::Drawing::Point(60, 74);
			this->textBox75->Name = L"textBox75";
			this->textBox75->Size = System::Drawing::Size(21, 21);
			this->textBox75->TabIndex = 9;
			this->textBox75->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox75->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox74
			// 
			this->textBox74->Location = System::Drawing::Point(33, 74);
			this->textBox74->Name = L"textBox74";
			this->textBox74->Size = System::Drawing::Size(21, 21);
			this->textBox74->TabIndex = 8;
			this->textBox74->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox74->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox73
			// 
			this->textBox73->Location = System::Drawing::Point(6, 74);
			this->textBox73->Name = L"textBox73";
			this->textBox73->Size = System::Drawing::Size(21, 21);
			this->textBox73->TabIndex = 7;
			this->textBox73->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox73->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox66
			// 
			this->textBox66->Location = System::Drawing::Point(60, 47);
			this->textBox66->Name = L"textBox66";
			this->textBox66->Size = System::Drawing::Size(21, 21);
			this->textBox66->TabIndex = 6;
			this->textBox66->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox66->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox65
			// 
			this->textBox65->Location = System::Drawing::Point(33, 47);
			this->textBox65->Name = L"textBox65";
			this->textBox65->Size = System::Drawing::Size(21, 21);
			this->textBox65->TabIndex = 5;
			this->textBox65->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox65->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox64
			// 
			this->textBox64->Location = System::Drawing::Point(6, 47);
			this->textBox64->Name = L"textBox64";
			this->textBox64->Size = System::Drawing::Size(21, 21);
			this->textBox64->TabIndex = 4;
			this->textBox64->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox64->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox57
			// 
			this->textBox57->Location = System::Drawing::Point(60, 20);
			this->textBox57->Name = L"textBox57";
			this->textBox57->Size = System::Drawing::Size(21, 21);
			this->textBox57->TabIndex = 3;
			this->textBox57->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox57->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox56
			// 
			this->textBox56->Location = System::Drawing::Point(33, 20);
			this->textBox56->Name = L"textBox56";
			this->textBox56->Size = System::Drawing::Size(21, 21);
			this->textBox56->TabIndex = 2;
			this->textBox56->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox56->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox55
			// 
			this->textBox55->Location = System::Drawing::Point(6, 20);
			this->textBox55->Name = L"textBox55";
			this->textBox55->Size = System::Drawing::Size(21, 21);
			this->textBox55->TabIndex = 1;
			this->textBox55->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox55->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// groupBox7
			// 
			this->groupBox7->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox7->Controls->Add(this->textBox54);
			this->groupBox7->Controls->Add(this->textBox53);
			this->groupBox7->Controls->Add(this->textBox52);
			this->groupBox7->Controls->Add(this->textBox45);
			this->groupBox7->Controls->Add(this->textBox44);
			this->groupBox7->Controls->Add(this->textBox43);
			this->groupBox7->Controls->Add(this->textBox36);
			this->groupBox7->Controls->Add(this->textBox35);
			this->groupBox7->Controls->Add(this->textBox34);
			this->groupBox7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox7->Location = System::Drawing::Point(192, 120);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(87, 101);
			this->groupBox7->TabIndex = 5;
			this->groupBox7->TabStop = false;
			// 
			// textBox54
			// 
			this->textBox54->Location = System::Drawing::Point(60, 74);
			this->textBox54->Name = L"textBox54";
			this->textBox54->Size = System::Drawing::Size(21, 21);
			this->textBox54->TabIndex = 9;
			this->textBox54->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox54->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox53
			// 
			this->textBox53->Location = System::Drawing::Point(33, 74);
			this->textBox53->Name = L"textBox53";
			this->textBox53->Size = System::Drawing::Size(21, 21);
			this->textBox53->TabIndex = 8;
			this->textBox53->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox53->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox52
			// 
			this->textBox52->Location = System::Drawing::Point(6, 74);
			this->textBox52->Name = L"textBox52";
			this->textBox52->Size = System::Drawing::Size(21, 21);
			this->textBox52->TabIndex = 7;
			this->textBox52->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox52->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox45
			// 
			this->textBox45->Location = System::Drawing::Point(60, 47);
			this->textBox45->Name = L"textBox45";
			this->textBox45->Size = System::Drawing::Size(21, 21);
			this->textBox45->TabIndex = 6;
			this->textBox45->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox45->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox44
			// 
			this->textBox44->Location = System::Drawing::Point(33, 47);
			this->textBox44->Name = L"textBox44";
			this->textBox44->Size = System::Drawing::Size(21, 21);
			this->textBox44->TabIndex = 5;
			this->textBox44->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox44->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox43
			// 
			this->textBox43->Location = System::Drawing::Point(6, 47);
			this->textBox43->Name = L"textBox43";
			this->textBox43->Size = System::Drawing::Size(21, 21);
			this->textBox43->TabIndex = 4;
			this->textBox43->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox43->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox36
			// 
			this->textBox36->Location = System::Drawing::Point(60, 20);
			this->textBox36->Name = L"textBox36";
			this->textBox36->Size = System::Drawing::Size(21, 21);
			this->textBox36->TabIndex = 3;
			this->textBox36->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox36->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox35
			// 
			this->textBox35->Location = System::Drawing::Point(33, 20);
			this->textBox35->Name = L"textBox35";
			this->textBox35->Size = System::Drawing::Size(21, 21);
			this->textBox35->TabIndex = 2;
			this->textBox35->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox35->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox34
			// 
			this->textBox34->Location = System::Drawing::Point(6, 20);
			this->textBox34->Name = L"textBox34";
			this->textBox34->Size = System::Drawing::Size(21, 21);
			this->textBox34->TabIndex = 1;
			this->textBox34->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox34->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// groupBox6
			// 
			this->groupBox6->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox6->Controls->Add(this->textBox51);
			this->groupBox6->Controls->Add(this->textBox50);
			this->groupBox6->Controls->Add(this->textBox49);
			this->groupBox6->Controls->Add(this->textBox42);
			this->groupBox6->Controls->Add(this->textBox41);
			this->groupBox6->Controls->Add(this->textBox40);
			this->groupBox6->Controls->Add(this->textBox33);
			this->groupBox6->Controls->Add(this->textBox32);
			this->groupBox6->Controls->Add(this->textBox31);
			this->groupBox6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox6->Location = System::Drawing::Point(99, 120);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(87, 101);
			this->groupBox6->TabIndex = 4;
			this->groupBox6->TabStop = false;
			// 
			// textBox51
			// 
			this->textBox51->Location = System::Drawing::Point(60, 74);
			this->textBox51->Name = L"textBox51";
			this->textBox51->Size = System::Drawing::Size(21, 21);
			this->textBox51->TabIndex = 9;
			this->textBox51->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox51->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox50
			// 
			this->textBox50->Location = System::Drawing::Point(33, 74);
			this->textBox50->Name = L"textBox50";
			this->textBox50->Size = System::Drawing::Size(21, 21);
			this->textBox50->TabIndex = 8;
			this->textBox50->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox50->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox49
			// 
			this->textBox49->Location = System::Drawing::Point(6, 74);
			this->textBox49->Name = L"textBox49";
			this->textBox49->Size = System::Drawing::Size(21, 21);
			this->textBox49->TabIndex = 7;
			this->textBox49->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox49->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox42
			// 
			this->textBox42->Location = System::Drawing::Point(60, 47);
			this->textBox42->Name = L"textBox42";
			this->textBox42->Size = System::Drawing::Size(21, 21);
			this->textBox42->TabIndex = 6;
			this->textBox42->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox42->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox41
			// 
			this->textBox41->Location = System::Drawing::Point(33, 47);
			this->textBox41->Name = L"textBox41";
			this->textBox41->Size = System::Drawing::Size(21, 21);
			this->textBox41->TabIndex = 5;
			this->textBox41->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox41->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox40
			// 
			this->textBox40->Location = System::Drawing::Point(6, 47);
			this->textBox40->Name = L"textBox40";
			this->textBox40->Size = System::Drawing::Size(21, 21);
			this->textBox40->TabIndex = 4;
			this->textBox40->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox40->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox33
			// 
			this->textBox33->Location = System::Drawing::Point(60, 20);
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(21, 21);
			this->textBox33->TabIndex = 3;
			this->textBox33->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox33->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox32
			// 
			this->textBox32->Location = System::Drawing::Point(33, 20);
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(21, 21);
			this->textBox32->TabIndex = 2;
			this->textBox32->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox32->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox31
			// 
			this->textBox31->Location = System::Drawing::Point(6, 20);
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(21, 21);
			this->textBox31->TabIndex = 1;
			this->textBox31->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox31->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// groupBox5
			// 
			this->groupBox5->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox5->Controls->Add(this->textBox48);
			this->groupBox5->Controls->Add(this->textBox47);
			this->groupBox5->Controls->Add(this->textBox46);
			this->groupBox5->Controls->Add(this->textBox39);
			this->groupBox5->Controls->Add(this->textBox38);
			this->groupBox5->Controls->Add(this->textBox37);
			this->groupBox5->Controls->Add(this->textBox30);
			this->groupBox5->Controls->Add(this->textBox29);
			this->groupBox5->Controls->Add(this->textBox28);
			this->groupBox5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox5->Location = System::Drawing::Point(6, 120);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(87, 101);
			this->groupBox5->TabIndex = 3;
			this->groupBox5->TabStop = false;
			// 
			// textBox48
			// 
			this->textBox48->Location = System::Drawing::Point(60, 74);
			this->textBox48->Name = L"textBox48";
			this->textBox48->Size = System::Drawing::Size(21, 21);
			this->textBox48->TabIndex = 9;
			this->textBox48->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox48->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox47
			// 
			this->textBox47->Location = System::Drawing::Point(33, 74);
			this->textBox47->Name = L"textBox47";
			this->textBox47->Size = System::Drawing::Size(21, 21);
			this->textBox47->TabIndex = 8;
			this->textBox47->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox47->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox46
			// 
			this->textBox46->Location = System::Drawing::Point(6, 74);
			this->textBox46->Name = L"textBox46";
			this->textBox46->Size = System::Drawing::Size(21, 21);
			this->textBox46->TabIndex = 7;
			this->textBox46->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox46->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox39
			// 
			this->textBox39->Location = System::Drawing::Point(60, 47);
			this->textBox39->Name = L"textBox39";
			this->textBox39->Size = System::Drawing::Size(21, 21);
			this->textBox39->TabIndex = 6;
			this->textBox39->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox39->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox38
			// 
			this->textBox38->Location = System::Drawing::Point(33, 47);
			this->textBox38->Name = L"textBox38";
			this->textBox38->Size = System::Drawing::Size(21, 21);
			this->textBox38->TabIndex = 5;
			this->textBox38->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox38->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox37
			// 
			this->textBox37->Location = System::Drawing::Point(6, 47);
			this->textBox37->Name = L"textBox37";
			this->textBox37->Size = System::Drawing::Size(21, 21);
			this->textBox37->TabIndex = 4;
			this->textBox37->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox37->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox30
			// 
			this->textBox30->Location = System::Drawing::Point(60, 20);
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(21, 21);
			this->textBox30->TabIndex = 3;
			this->textBox30->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox30->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox29
			// 
			this->textBox29->Location = System::Drawing::Point(33, 20);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(21, 21);
			this->textBox29->TabIndex = 2;
			this->textBox29->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox29->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(6, 20);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(21, 21);
			this->textBox28->TabIndex = 1;
			this->textBox28->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox28->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox4->Controls->Add(this->textBox27);
			this->groupBox4->Controls->Add(this->textBox26);
			this->groupBox4->Controls->Add(this->textBox25);
			this->groupBox4->Controls->Add(this->textBox18);
			this->groupBox4->Controls->Add(this->textBox17);
			this->groupBox4->Controls->Add(this->textBox16);
			this->groupBox4->Controls->Add(this->textBox9);
			this->groupBox4->Controls->Add(this->textBox8);
			this->groupBox4->Controls->Add(this->textBox7);
			this->groupBox4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox4->Location = System::Drawing::Point(192, 13);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(87, 101);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(60, 74);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(21, 21);
			this->textBox27->TabIndex = 9;
			this->textBox27->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox27->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(33, 74);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(21, 21);
			this->textBox26->TabIndex = 8;
			this->textBox26->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox26->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(6, 74);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(21, 21);
			this->textBox25->TabIndex = 7;
			this->textBox25->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox25->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(60, 47);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(21, 21);
			this->textBox18->TabIndex = 6;
			this->textBox18->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox18->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(33, 47);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(21, 21);
			this->textBox17->TabIndex = 5;
			this->textBox17->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox17->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(6, 47);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(21, 21);
			this->textBox16->TabIndex = 4;
			this->textBox16->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox16->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(60, 20);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(21, 21);
			this->textBox9->TabIndex = 3;
			this->textBox9->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox9->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(33, 20);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(21, 21);
			this->textBox8->TabIndex = 2;
			this->textBox8->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox8->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(6, 20);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(21, 21);
			this->textBox7->TabIndex = 1;
			this->textBox7->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox7->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox3->Controls->Add(this->textBox24);
			this->groupBox3->Controls->Add(this->textBox23);
			this->groupBox3->Controls->Add(this->textBox22);
			this->groupBox3->Controls->Add(this->textBox15);
			this->groupBox3->Controls->Add(this->textBox14);
			this->groupBox3->Controls->Add(this->textBox13);
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox3->Location = System::Drawing::Point(99, 13);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(87, 101);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(60, 74);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(21, 21);
			this->textBox24->TabIndex = 9;
			this->textBox24->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox24->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(33, 74);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(21, 21);
			this->textBox23->TabIndex = 8;
			this->textBox23->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox23->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(6, 74);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(21, 21);
			this->textBox22->TabIndex = 7;
			this->textBox22->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox22->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(60, 47);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(21, 21);
			this->textBox15->TabIndex = 6;
			this->textBox15->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox15->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(33, 47);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(21, 21);
			this->textBox14->TabIndex = 5;
			this->textBox14->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox14->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(6, 47);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(21, 21);
			this->textBox13->TabIndex = 4;
			this->textBox13->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox13->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(60, 20);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(21, 21);
			this->textBox6->TabIndex = 3;
			this->textBox6->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox6->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(33, 20);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(21, 21);
			this->textBox5->TabIndex = 2;
			this->textBox5->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox5->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(6, 20);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(21, 21);
			this->textBox4->TabIndex = 1;
			this->textBox4->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox4->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Controls->Add(this->textBox21);
			this->groupBox2->Controls->Add(this->textBox20);
			this->groupBox2->Controls->Add(this->textBox19);
			this->groupBox2->Controls->Add(this->textBox12);
			this->groupBox2->Controls->Add(this->textBox11);
			this->groupBox2->Controls->Add(this->textBox10);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox2->Location = System::Drawing::Point(6, 13);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(87, 101);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(60, 74);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(21, 21);
			this->textBox21->TabIndex = 8;
			this->textBox21->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox21->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(33, 74);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(21, 21);
			this->textBox20->TabIndex = 7;
			this->textBox20->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox20->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(6, 74);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(21, 21);
			this->textBox19->TabIndex = 6;
			this->textBox19->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox19->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(60, 47);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(21, 21);
			this->textBox12->TabIndex = 5;
			this->textBox12->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox12->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(33, 47);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(21, 21);
			this->textBox11->TabIndex = 4;
			this->textBox11->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox11->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(6, 47);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(21, 21);
			this->textBox10->TabIndex = 3;
			this->textBox10->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox10->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(60, 20);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(21, 21);
			this->textBox3->TabIndex = 2;
			this->textBox3->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox3->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(33, 20);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(21, 21);
			this->textBox2->TabIndex = 1;
			this->textBox2->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox2->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(21, 21);
			this->textBox1->TabIndex = 0;
			this->textBox1->Click += gcnew System::EventHandler(this, &Form1::textBox_Click);
			this->textBox1->Leave += gcnew System::EventHandler(this, &Form1::textBox_Leave);
			// 
			// btHelp
			// 
			this->btHelp->Enabled = false;
			this->btHelp->Location = System::Drawing::Point(25, 399);
			this->btHelp->Name = L"btHelp";
			this->btHelp->Size = System::Drawing::Size(60, 21);
			this->btHelp->TabIndex = 4;
			this->btHelp->Text = L"Help";
			this->btHelp->UseVisualStyleBackColor = true;
			this->btHelp->Click += gcnew System::EventHandler(this, &Form1::btHelp_Click);
			// 
			// btSave
			// 
			this->btSave->Enabled = false;
			this->btSave->Location = System::Drawing::Point(157, 399);
			this->btSave->Name = L"btSave";
			this->btSave->Size = System::Drawing::Size(60, 21);
			this->btSave->TabIndex = 6;
			this->btSave->Text = L"Save";
			this->btSave->UseVisualStyleBackColor = true;
			this->btSave->Click += gcnew System::EventHandler(this, &Form1::btSave_Click);
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->cmbPuzzleList);
			this->groupBox11->Controls->Add(this->btLoad);
			this->groupBox11->Location = System::Drawing::Point(58, 8);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(186, 44);
			this->groupBox11->TabIndex = 7;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Choose Puzzle";
			// 
			// btExit
			// 
			this->btExit->Location = System::Drawing::Point(223, 399);
			this->btExit->Name = L"btExit";
			this->btExit->Size = System::Drawing::Size(60, 21);
			this->btExit->TabIndex = 1;
			this->btExit->Text = L"Exit";
			this->btExit->UseVisualStyleBackColor = true;
			this->btExit->Click += gcnew System::EventHandler(this, &Form1::btExit_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 431);
			this->Controls->Add(this->btExit);
			this->Controls->Add(this->groupBox11);
			this->Controls->Add(this->btSave);
			this->Controls->Add(this->btHelp);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btSolve);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Sudoku";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 m_aTextBoxes = gcnew array<TextBox^>(81);
				 AddTextBoxesToArray();
				 m_pManager = new Manager();
				 //m_pManager->Init();
			 }
	private: System::Void btLoad_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				btLoad->Enabled = false;
				int iLoadPuzNum = 0;
				iLoadPuzNum = m_pManager->GetComboNum();
				//Rest of Load stuff here.
				m_pManager->LoadSudoku(iLoadPuzNum);
				LoadTextBox();
				btSave->Enabled = true;
				btSolve->Enabled = true;
			 }
	private: System::Void btHelp_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				int box = m_pManager->GetCurrTB() - 1;
				 m_pManager->SolveSquare(box);
				 m_aTextBoxes[box]->Text = System::Convert::ToString(m_pManager->GetGridNum(box));
				 
				 //m_pManager->SetGridNum(box, System::Convert::ToInt32(m_aTextBoxes[box]->Text));
				 if (m_pManager->GetSquare(box)->GetForeColour() == ccGreen)
				 {
					//m_aTextBoxes[box]->BackColor = System::Drawing::Color::Green;
					//m_aTextBoxes[box]->ForeColor = System::Drawing::Color::White;
					m_aTextBoxes[box]->Enabled = false;
				 }
				 else if (m_pManager->GetSquare(box)->GetForeColour() == ccRed)
				 {
					 m_aTextBoxes[box]->BackColor = System::Drawing::Color::Red;
					 m_aTextBoxes[box]->ForeColor = System::Drawing::Color::White;
					 m_aTextBoxes[box]->Enabled = true;
				 }
				 else if (m_pManager->GetSquare(box)->GetForeColour() == ccBlue)
				 {
					 //m_aTextBoxes[box]->BackColor = System::Drawing::Color::Blue;
					 //m_aTextBoxes[box]->ForeColor = System::Drawing::Color::White;
					 m_aTextBoxes[box]->Enabled = false;
				 }
			 }
	private: System::Void btSolve_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 m_pManager->SolveSudoku();
				 LoadTextBox();
			 }
	private: System::Void btCompare_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 m_pManager->CompareResults();
			 }
	private: System::Void btSave_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 m_pManager->WriteToFile();
			 }
	private: System::Void cmbPuzzleList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 int temp = System::Convert::ToInt32(cmbPuzzleList->SelectedIndex);
				 m_pManager->SetComboNum(temp+1);
				 btLoad->Enabled = true;
			 }
	private: System::Void AddTextBoxesToArray()
			{
				m_aTextBoxes[0] = textBox1; m_aTextBoxes[21] = textBox22; m_aTextBoxes[41] = textBox42; m_aTextBoxes[61] = textBox62;
				m_aTextBoxes[1] = textBox2; m_aTextBoxes[22] = textBox23; m_aTextBoxes[42] = textBox43; m_aTextBoxes[62] = textBox63;
				m_aTextBoxes[2] = textBox3; m_aTextBoxes[23] = textBox24; m_aTextBoxes[43] = textBox44; m_aTextBoxes[63] = textBox64;
				m_aTextBoxes[3] = textBox4; m_aTextBoxes[24] = textBox25; m_aTextBoxes[44] = textBox45; m_aTextBoxes[64] = textBox65;
				m_aTextBoxes[4] = textBox5; m_aTextBoxes[25] = textBox26; m_aTextBoxes[45] = textBox46; m_aTextBoxes[65] = textBox66;
				m_aTextBoxes[5] = textBox6; m_aTextBoxes[26] = textBox27; m_aTextBoxes[46] = textBox47; m_aTextBoxes[66] = textBox67;
				m_aTextBoxes[6] = textBox7; m_aTextBoxes[27] = textBox28; m_aTextBoxes[47] = textBox48; m_aTextBoxes[67] = textBox68;
				m_aTextBoxes[7] = textBox8; m_aTextBoxes[28] = textBox29; m_aTextBoxes[48] = textBox49; m_aTextBoxes[68] = textBox69;
				m_aTextBoxes[8] = textBox9; m_aTextBoxes[29] = textBox30; m_aTextBoxes[49] = textBox50; m_aTextBoxes[69] = textBox70;
				m_aTextBoxes[9] = textBox10; m_aTextBoxes[30] = textBox31; m_aTextBoxes[50] = textBox51; m_aTextBoxes[70] = textBox71;
				m_aTextBoxes[10] = textBox11; m_aTextBoxes[31] = textBox32; m_aTextBoxes[51] = textBox52; m_aTextBoxes[71] = textBox72;
				m_aTextBoxes[11] = textBox12; m_aTextBoxes[32] = textBox33; m_aTextBoxes[52] = textBox53; m_aTextBoxes[72] = textBox73;
				m_aTextBoxes[12] = textBox13; m_aTextBoxes[33] = textBox34; m_aTextBoxes[53] = textBox54; m_aTextBoxes[73] = textBox74;
				m_aTextBoxes[13] = textBox14; m_aTextBoxes[34] = textBox35; m_aTextBoxes[54] = textBox55; m_aTextBoxes[74] = textBox75;
				m_aTextBoxes[14] = textBox15; m_aTextBoxes[35] = textBox36; m_aTextBoxes[55] = textBox56; m_aTextBoxes[75] = textBox76;
				m_aTextBoxes[15] = textBox16; m_aTextBoxes[36] = textBox37; m_aTextBoxes[56] = textBox57; m_aTextBoxes[76] = textBox77;
				m_aTextBoxes[16] = textBox17; m_aTextBoxes[37] = textBox38; m_aTextBoxes[57] = textBox58; m_aTextBoxes[77] = textBox78;
				m_aTextBoxes[17] = textBox18; m_aTextBoxes[38] = textBox39; m_aTextBoxes[58] = textBox59; m_aTextBoxes[78] = textBox79;
				m_aTextBoxes[18] = textBox19; m_aTextBoxes[39] = textBox40; m_aTextBoxes[59] = textBox60; m_aTextBoxes[79] = textBox80;
				m_aTextBoxes[19] = textBox20; m_aTextBoxes[40] = textBox41; m_aTextBoxes[60] = textBox61; m_aTextBoxes[80] = textBox81;
				m_aTextBoxes[20] = textBox21;

			}
	private: System::Void LoadTextBox()
			{
				for (int i = 0; i < 81; i++)
				{
					if (m_pManager->GetGridNum(i) > 0)
					{
						m_aTextBoxes[i]->Text = System::Convert::ToString(m_pManager->GetGridNum(i));
						m_aTextBoxes[i]->Enabled = false;
					}
					else
					{
						m_aTextBoxes[i]->Text = "";
						m_aTextBoxes[i]->Enabled = true;
					}
				}
				
			}
	private: System::Void textBox_Click(System::Object^ sender, System::EventArgs^ e)
			 {
				 System::String^ sTemp = ""; //= gcnew System::String;
				 sTemp = ((TextBox^)sender)->Name;//sender->GetType()->Name; //->GetType()->Name;
				 sTemp = sTemp->Substring(7, sTemp->Length - 7);
				 m_pManager->SetCurrTB(System::Convert::ToInt32(sTemp));
				 btHelp->Enabled = true;
			 }
	private: System::Void textBox_Leave(System::Object^  sender, System::EventArgs^  e) 
			{
				/*if (textBox1->Text == "0")
				{
				textBox1->Text = System::Convert::ToString(m_pManager->GetGridNum(0));
				}*/
				System::String^ sTemp = ""; //= gcnew System::String;
				int iTemp = -1;
				sTemp = ((TextBox^)sender)->Name;//sender->GetType()->Name; //->GetType()->Name;
				sTemp = sTemp->Substring(7, sTemp->Length - 7);
				iTemp += System::Convert::ToInt32(sTemp);
				m_pManager->SetGridNum(iTemp, System::Convert::ToInt32(((TextBox^)sender)->Text));
			}
private: System::Void btExit_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->Close();
		 }
};
}

