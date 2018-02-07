#pragma once
#pragma comment(lib, "winmm.lib")

#include <ctime>
#include <iostream>
#include "windows.h"
#include <string>
#include "frmAbout.h"
#include "frmInstrukcja.h"
#include <sstream>
#include <fstream>

using namespace std;

#define MAGIC_NUMBER 71830
#define W_KEY "NHGBE1QNERX2OEMRX3-4QYN5JFVM6PBCREAVHF"

namespace WSIZ_Project2_Mastermind {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			this->intSzukane = (gcnew array<Int16,1>(4));
			this->lblArrO = gcnew array<Label^,2>(10,4) {
			{lblO11, lblO12, lblO13, lblO14},
			{lblO21, lblO22, lblO23, lblO24},
			{lblO31, lblO32, lblO33, lblO34},
			{lblO41, lblO42, lblO43, lblO44},
			{lblO51, lblO52, lblO53, lblO54},
			{lblO61, lblO62, lblO63, lblO64},
			{lblO71, lblO72, lblO73, lblO74},
			{lblO81, lblO82, lblO83, lblO84},
			{lblO91, lblO92, lblO93, lblO94},
			{lblOa1, lblOa2, lblOa3, lblOa4}};
			this->lblArrH = gcnew array<Label^,2>(10,4) {
			{lblH11, lblH12, lblH13, lblH14},
			{lblH21, lblH22, lblH23, lblH24},
			{lblH31, lblH32, lblH33, lblH34},
			{lblH41, lblH42, lblH43, lblH44},
			{lblH51, lblH52, lblH53, lblH54},
			{lblH61, lblH62, lblH63, lblH64},
			{lblH71, lblH72, lblH73, lblH74},
			{lblH81, lblH82, lblH83, lblH84},
			{lblH91, lblH92, lblH93, lblH94},
			{lblHa1, lblHa2, lblHa3, lblHa4}};
			this->lblArrPrb = gcnew array<Label^,1>(10) {lblPrb1,lblPrb2,lblPrb3,lblPrb4,lblPrb5,lblPrb6,lblPrb7,lblPrb8,lblPrb9,lblPrb10};
			this->topScore = (gcnew array<time_t,1>(11));

		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: array<Int16,1>^ intSzukane;
	private: array<Label^,2>^ lblArrO;
	private: array<Label^,2>^ lblArrH;
	private: array<Label^,1>^ lblArrPrb;
	private: array<time_t,1>^ topScore;
	private: UInt16 intProba;
	private: Boolean gameInProgress;
	private: time_t sTime, cTime;
	private: System::Windows::Forms::Label^  lblZ1;
	private: System::Windows::Forms::Label^  lblZ2;
	private: System::Windows::Forms::Label^  lblZ3;
	private: System::Windows::Forms::Label^  lblZ4;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblO14;
	private: System::Windows::Forms::Label^  lblO13;
	private: System::Windows::Forms::Label^  lblO12;
	private: System::Windows::Forms::Label^  lblO11;
	private: System::Windows::Forms::Label^  lblH11;
	private: System::Windows::Forms::Label^  lblH12;
	private: System::Windows::Forms::Label^  lblH13;
	private: System::Windows::Forms::Label^  lblH14;
	private: System::Windows::Forms::Label^  lblH24;
	private: System::Windows::Forms::Label^  lblH23;
	private: System::Windows::Forms::Label^  lblH22;
	private: System::Windows::Forms::Label^  lblH21;
	private: System::Windows::Forms::Label^  lblO24;
	private: System::Windows::Forms::Label^  lblO23;
	private: System::Windows::Forms::Label^  lblO22;
	private: System::Windows::Forms::Label^  lblO21;
	private: System::Windows::Forms::Label^  lblH34;
	private: System::Windows::Forms::Label^  lblH33;
	private: System::Windows::Forms::Label^  lblH32;
	private: System::Windows::Forms::Label^  lblH31;
	private: System::Windows::Forms::Label^  lblO34;
	private: System::Windows::Forms::Label^  lblO33;
	private: System::Windows::Forms::Label^  lblO32;
	private: System::Windows::Forms::Label^  lblO31;
	private: System::Windows::Forms::Label^  lblH44;
	private: System::Windows::Forms::Label^  lblH43;
	private: System::Windows::Forms::Label^  lblH42;
	private: System::Windows::Forms::Label^  lblH41;
	private: System::Windows::Forms::Label^  lblO44;
	private: System::Windows::Forms::Label^  lblO43;
	private: System::Windows::Forms::Label^  lblO42;
	private: System::Windows::Forms::Label^  lblO41;
	private: System::Windows::Forms::Label^  lblH54;
	private: System::Windows::Forms::Label^  lblH53;
	private: System::Windows::Forms::Label^  lblH52;
	private: System::Windows::Forms::Label^  lblH51;
	private: System::Windows::Forms::Label^  lblO54;
	private: System::Windows::Forms::Label^  lblO53;
	private: System::Windows::Forms::Label^  lblO52;
	private: System::Windows::Forms::Label^  lblO51;
	private: System::Windows::Forms::Label^  lblH64;
	private: System::Windows::Forms::Label^  lblH63;
	private: System::Windows::Forms::Label^  lblH62;
	private: System::Windows::Forms::Label^  lblH61;
	private: System::Windows::Forms::Label^  lblO64;
	private: System::Windows::Forms::Label^  lblO63;
	private: System::Windows::Forms::Label^  lblO62;
	private: System::Windows::Forms::Label^  lblO61;
	private: System::Windows::Forms::Label^  lblH74;
	private: System::Windows::Forms::Label^  lblH73;
	private: System::Windows::Forms::Label^  lblH72;
	private: System::Windows::Forms::Label^  lblH71;
	private: System::Windows::Forms::Label^  lblO74;
	private: System::Windows::Forms::Label^  lblO73;
	private: System::Windows::Forms::Label^  lblO72;
	private: System::Windows::Forms::Label^  lblO71;
	private: System::Windows::Forms::Label^  lblH84;
	private: System::Windows::Forms::Label^  lblH83;
	private: System::Windows::Forms::Label^  lblH82;
	private: System::Windows::Forms::Label^  lblH81;
	private: System::Windows::Forms::Label^  lblO84;
	private: System::Windows::Forms::Label^  lblO83;
	private: System::Windows::Forms::Label^  lblO82;
	private: System::Windows::Forms::Label^  lblO81;
	private: System::Windows::Forms::Label^  lblH94;
	private: System::Windows::Forms::Label^  lblH93;
	private: System::Windows::Forms::Label^  lblH92;
	private: System::Windows::Forms::Label^  lblH91;
	private: System::Windows::Forms::Label^  lblO94;
	private: System::Windows::Forms::Label^  lblO93;
	private: System::Windows::Forms::Label^  lblO92;
	private: System::Windows::Forms::Label^  lblO91;
	private: System::Windows::Forms::Label^  lblHa4;
	private: System::Windows::Forms::Label^  lblHa3;
	private: System::Windows::Forms::Label^  lblHa2;
	private: System::Windows::Forms::Label^  lblHa1;
	private: System::Windows::Forms::Label^  lblOa4;
	private: System::Windows::Forms::Label^  lblOa3;
	private: System::Windows::Forms::Label^  lblOa2;
	private: System::Windows::Forms::Label^  lblOa1;
	private: System::Windows::Forms::Label^  lblPrb1;
	private: System::Windows::Forms::Label^  lblPrb2;
	private: System::Windows::Forms::Label^  lblPrb3;
	private: System::Windows::Forms::Label^  lblPrb4;
	private: System::Windows::Forms::Label^  lblPrb5;
	private: System::Windows::Forms::Label^  lblPrb6;
	private: System::Windows::Forms::Label^  lblPrb7;
	private: System::Windows::Forms::Label^  lblPrb8;
	private: System::Windows::Forms::Label^  lblPrb9;
	private: System::Windows::Forms::Label^  lblPrb10;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  graToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nowaGraToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  zakończProgramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pomocToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  instrukcjaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  oProgramieToolStripMenuItem;
private: System::Windows::Forms::Label^  lblTimer;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  lblTop;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda wsparcia projektanta - nie należy modyfikować
		/// zawartość tej metody z edytorem kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblZ1 = (gcnew System::Windows::Forms::Label());
			this->lblZ2 = (gcnew System::Windows::Forms::Label());
			this->lblZ3 = (gcnew System::Windows::Forms::Label());
			this->lblZ4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblO14 = (gcnew System::Windows::Forms::Label());
			this->lblO13 = (gcnew System::Windows::Forms::Label());
			this->lblO12 = (gcnew System::Windows::Forms::Label());
			this->lblO11 = (gcnew System::Windows::Forms::Label());
			this->lblH11 = (gcnew System::Windows::Forms::Label());
			this->lblH12 = (gcnew System::Windows::Forms::Label());
			this->lblH13 = (gcnew System::Windows::Forms::Label());
			this->lblH14 = (gcnew System::Windows::Forms::Label());
			this->lblH24 = (gcnew System::Windows::Forms::Label());
			this->lblH23 = (gcnew System::Windows::Forms::Label());
			this->lblH22 = (gcnew System::Windows::Forms::Label());
			this->lblH21 = (gcnew System::Windows::Forms::Label());
			this->lblO24 = (gcnew System::Windows::Forms::Label());
			this->lblO23 = (gcnew System::Windows::Forms::Label());
			this->lblO22 = (gcnew System::Windows::Forms::Label());
			this->lblO21 = (gcnew System::Windows::Forms::Label());
			this->lblH34 = (gcnew System::Windows::Forms::Label());
			this->lblH33 = (gcnew System::Windows::Forms::Label());
			this->lblH32 = (gcnew System::Windows::Forms::Label());
			this->lblH31 = (gcnew System::Windows::Forms::Label());
			this->lblO34 = (gcnew System::Windows::Forms::Label());
			this->lblO33 = (gcnew System::Windows::Forms::Label());
			this->lblO32 = (gcnew System::Windows::Forms::Label());
			this->lblO31 = (gcnew System::Windows::Forms::Label());
			this->lblH44 = (gcnew System::Windows::Forms::Label());
			this->lblH43 = (gcnew System::Windows::Forms::Label());
			this->lblH42 = (gcnew System::Windows::Forms::Label());
			this->lblH41 = (gcnew System::Windows::Forms::Label());
			this->lblO44 = (gcnew System::Windows::Forms::Label());
			this->lblO43 = (gcnew System::Windows::Forms::Label());
			this->lblO42 = (gcnew System::Windows::Forms::Label());
			this->lblO41 = (gcnew System::Windows::Forms::Label());
			this->lblH54 = (gcnew System::Windows::Forms::Label());
			this->lblH53 = (gcnew System::Windows::Forms::Label());
			this->lblH52 = (gcnew System::Windows::Forms::Label());
			this->lblH51 = (gcnew System::Windows::Forms::Label());
			this->lblO54 = (gcnew System::Windows::Forms::Label());
			this->lblO53 = (gcnew System::Windows::Forms::Label());
			this->lblO52 = (gcnew System::Windows::Forms::Label());
			this->lblO51 = (gcnew System::Windows::Forms::Label());
			this->lblH64 = (gcnew System::Windows::Forms::Label());
			this->lblH63 = (gcnew System::Windows::Forms::Label());
			this->lblH62 = (gcnew System::Windows::Forms::Label());
			this->lblH61 = (gcnew System::Windows::Forms::Label());
			this->lblO64 = (gcnew System::Windows::Forms::Label());
			this->lblO63 = (gcnew System::Windows::Forms::Label());
			this->lblO62 = (gcnew System::Windows::Forms::Label());
			this->lblO61 = (gcnew System::Windows::Forms::Label());
			this->lblH74 = (gcnew System::Windows::Forms::Label());
			this->lblH73 = (gcnew System::Windows::Forms::Label());
			this->lblH72 = (gcnew System::Windows::Forms::Label());
			this->lblH71 = (gcnew System::Windows::Forms::Label());
			this->lblO74 = (gcnew System::Windows::Forms::Label());
			this->lblO73 = (gcnew System::Windows::Forms::Label());
			this->lblO72 = (gcnew System::Windows::Forms::Label());
			this->lblO71 = (gcnew System::Windows::Forms::Label());
			this->lblH84 = (gcnew System::Windows::Forms::Label());
			this->lblH83 = (gcnew System::Windows::Forms::Label());
			this->lblH82 = (gcnew System::Windows::Forms::Label());
			this->lblH81 = (gcnew System::Windows::Forms::Label());
			this->lblO84 = (gcnew System::Windows::Forms::Label());
			this->lblO83 = (gcnew System::Windows::Forms::Label());
			this->lblO82 = (gcnew System::Windows::Forms::Label());
			this->lblO81 = (gcnew System::Windows::Forms::Label());
			this->lblH94 = (gcnew System::Windows::Forms::Label());
			this->lblH93 = (gcnew System::Windows::Forms::Label());
			this->lblH92 = (gcnew System::Windows::Forms::Label());
			this->lblH91 = (gcnew System::Windows::Forms::Label());
			this->lblO94 = (gcnew System::Windows::Forms::Label());
			this->lblO93 = (gcnew System::Windows::Forms::Label());
			this->lblO92 = (gcnew System::Windows::Forms::Label());
			this->lblO91 = (gcnew System::Windows::Forms::Label());
			this->lblHa4 = (gcnew System::Windows::Forms::Label());
			this->lblHa3 = (gcnew System::Windows::Forms::Label());
			this->lblHa2 = (gcnew System::Windows::Forms::Label());
			this->lblHa1 = (gcnew System::Windows::Forms::Label());
			this->lblOa4 = (gcnew System::Windows::Forms::Label());
			this->lblOa3 = (gcnew System::Windows::Forms::Label());
			this->lblOa2 = (gcnew System::Windows::Forms::Label());
			this->lblOa1 = (gcnew System::Windows::Forms::Label());
			this->lblPrb1 = (gcnew System::Windows::Forms::Label());
			this->lblPrb2 = (gcnew System::Windows::Forms::Label());
			this->lblPrb3 = (gcnew System::Windows::Forms::Label());
			this->lblPrb4 = (gcnew System::Windows::Forms::Label());
			this->lblPrb5 = (gcnew System::Windows::Forms::Label());
			this->lblPrb6 = (gcnew System::Windows::Forms::Label());
			this->lblPrb7 = (gcnew System::Windows::Forms::Label());
			this->lblPrb8 = (gcnew System::Windows::Forms::Label());
			this->lblPrb9 = (gcnew System::Windows::Forms::Label());
			this->lblPrb10 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->graToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nowaGraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->zakończProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pomocToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instrukcjaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->oProgramieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblTimer = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTop = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblZ1
			// 
			this->lblZ1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblZ1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblZ1->Location = System::Drawing::Point(64, 34);
			this->lblZ1->Name = L"lblZ1";
			this->lblZ1->Size = System::Drawing::Size(23, 21);
			this->lblZ1->TabIndex = 0;
			this->lblZ1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblZ1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblZ2
			// 
			this->lblZ2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblZ2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblZ2->Location = System::Drawing::Point(93, 34);
			this->lblZ2->Name = L"lblZ2";
			this->lblZ2->Size = System::Drawing::Size(23, 21);
			this->lblZ2->TabIndex = 1;
			this->lblZ2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblZ2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblZ3
			// 
			this->lblZ3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblZ3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblZ3->Location = System::Drawing::Point(122, 34);
			this->lblZ3->Name = L"lblZ3";
			this->lblZ3->Size = System::Drawing::Size(23, 21);
			this->lblZ3->TabIndex = 2;
			this->lblZ3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblZ3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblZ4
			// 
			this->lblZ4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblZ4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblZ4->Location = System::Drawing::Point(151, 34);
			this->lblZ4->Name = L"lblZ4";
			this->lblZ4->Size = System::Drawing::Size(23, 21);
			this->lblZ4->TabIndex = 3;
			this->lblZ4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblZ4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Szukana:";
			this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO14
			// 
			this->lblO14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO14->Location = System::Drawing::Point(151, 76);
			this->lblO14->Name = L"lblO14";
			this->lblO14->Size = System::Drawing::Size(23, 21);
			this->lblO14->TabIndex = 8;
			this->lblO14->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO13
			// 
			this->lblO13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO13->Location = System::Drawing::Point(122, 76);
			this->lblO13->Name = L"lblO13";
			this->lblO13->Size = System::Drawing::Size(23, 21);
			this->lblO13->TabIndex = 7;
			this->lblO13->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO12
			// 
			this->lblO12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO12->Location = System::Drawing::Point(93, 76);
			this->lblO12->Name = L"lblO12";
			this->lblO12->Size = System::Drawing::Size(23, 21);
			this->lblO12->TabIndex = 6;
			this->lblO12->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO11
			// 
			this->lblO11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO11->Location = System::Drawing::Point(64, 76);
			this->lblO11->Name = L"lblO11";
			this->lblO11->Size = System::Drawing::Size(23, 21);
			this->lblO11->TabIndex = 5;
			this->lblO11->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblH11
			// 
			this->lblH11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH11->Location = System::Drawing::Point(196, 76);
			this->lblH11->Name = L"lblH11";
			this->lblH11->Size = System::Drawing::Size(11, 21);
			this->lblH11->TabIndex = 9;
			this->lblH11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH11->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH12
			// 
			this->lblH12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH12->Location = System::Drawing::Point(213, 76);
			this->lblH12->Name = L"lblH12";
			this->lblH12->Size = System::Drawing::Size(11, 21);
			this->lblH12->TabIndex = 10;
			this->lblH12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH12->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH13
			// 
			this->lblH13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH13->Location = System::Drawing::Point(230, 76);
			this->lblH13->Name = L"lblH13";
			this->lblH13->Size = System::Drawing::Size(11, 21);
			this->lblH13->TabIndex = 11;
			this->lblH13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH13->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH14
			// 
			this->lblH14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH14->Location = System::Drawing::Point(247, 76);
			this->lblH14->Name = L"lblH14";
			this->lblH14->Size = System::Drawing::Size(11, 21);
			this->lblH14->TabIndex = 12;
			this->lblH14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH14->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH24
			// 
			this->lblH24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH24->Location = System::Drawing::Point(247, 106);
			this->lblH24->Name = L"lblH24";
			this->lblH24->Size = System::Drawing::Size(11, 21);
			this->lblH24->TabIndex = 20;
			this->lblH24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH24->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH23
			// 
			this->lblH23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH23->Location = System::Drawing::Point(230, 106);
			this->lblH23->Name = L"lblH23";
			this->lblH23->Size = System::Drawing::Size(11, 21);
			this->lblH23->TabIndex = 19;
			this->lblH23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH23->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH22
			// 
			this->lblH22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH22->Location = System::Drawing::Point(213, 106);
			this->lblH22->Name = L"lblH22";
			this->lblH22->Size = System::Drawing::Size(11, 21);
			this->lblH22->TabIndex = 18;
			this->lblH22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH22->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH21
			// 
			this->lblH21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH21->Location = System::Drawing::Point(196, 106);
			this->lblH21->Name = L"lblH21";
			this->lblH21->Size = System::Drawing::Size(11, 21);
			this->lblH21->TabIndex = 17;
			this->lblH21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH21->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO24
			// 
			this->lblO24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO24->Location = System::Drawing::Point(151, 106);
			this->lblO24->Name = L"lblO24";
			this->lblO24->Size = System::Drawing::Size(23, 21);
			this->lblO24->TabIndex = 16;
			this->lblO24->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO23
			// 
			this->lblO23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO23->Location = System::Drawing::Point(122, 106);
			this->lblO23->Name = L"lblO23";
			this->lblO23->Size = System::Drawing::Size(23, 21);
			this->lblO23->TabIndex = 15;
			this->lblO23->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO22
			// 
			this->lblO22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO22->Location = System::Drawing::Point(93, 106);
			this->lblO22->Name = L"lblO22";
			this->lblO22->Size = System::Drawing::Size(23, 21);
			this->lblO22->TabIndex = 14;
			this->lblO22->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO21
			// 
			this->lblO21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO21->Location = System::Drawing::Point(64, 106);
			this->lblO21->Name = L"lblO21";
			this->lblO21->Size = System::Drawing::Size(23, 21);
			this->lblO21->TabIndex = 13;
			this->lblO21->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblH34
			// 
			this->lblH34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH34->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH34->Location = System::Drawing::Point(247, 138);
			this->lblH34->Name = L"lblH34";
			this->lblH34->Size = System::Drawing::Size(11, 21);
			this->lblH34->TabIndex = 28;
			this->lblH34->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH34->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH33
			// 
			this->lblH33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH33->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH33->Location = System::Drawing::Point(230, 138);
			this->lblH33->Name = L"lblH33";
			this->lblH33->Size = System::Drawing::Size(11, 21);
			this->lblH33->TabIndex = 27;
			this->lblH33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH33->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH32
			// 
			this->lblH32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH32->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH32->Location = System::Drawing::Point(213, 138);
			this->lblH32->Name = L"lblH32";
			this->lblH32->Size = System::Drawing::Size(11, 21);
			this->lblH32->TabIndex = 26;
			this->lblH32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH32->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH31
			// 
			this->lblH31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH31->Location = System::Drawing::Point(196, 138);
			this->lblH31->Name = L"lblH31";
			this->lblH31->Size = System::Drawing::Size(11, 21);
			this->lblH31->TabIndex = 25;
			this->lblH31->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH31->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO34
			// 
			this->lblO34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO34->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO34->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO34->Location = System::Drawing::Point(151, 138);
			this->lblO34->Name = L"lblO34";
			this->lblO34->Size = System::Drawing::Size(23, 21);
			this->lblO34->TabIndex = 24;
			this->lblO34->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO33
			// 
			this->lblO33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO33->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO33->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO33->Location = System::Drawing::Point(122, 138);
			this->lblO33->Name = L"lblO33";
			this->lblO33->Size = System::Drawing::Size(23, 21);
			this->lblO33->TabIndex = 23;
			this->lblO33->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO32
			// 
			this->lblO32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO32->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO32->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO32->Location = System::Drawing::Point(93, 138);
			this->lblO32->Name = L"lblO32";
			this->lblO32->Size = System::Drawing::Size(23, 21);
			this->lblO32->TabIndex = 22;
			this->lblO32->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO31
			// 
			this->lblO31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO31->Location = System::Drawing::Point(64, 138);
			this->lblO31->Name = L"lblO31";
			this->lblO31->Size = System::Drawing::Size(23, 21);
			this->lblO31->TabIndex = 21;
			this->lblO31->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblH44
			// 
			this->lblH44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH44->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH44->Location = System::Drawing::Point(247, 169);
			this->lblH44->Name = L"lblH44";
			this->lblH44->Size = System::Drawing::Size(11, 21);
			this->lblH44->TabIndex = 36;
			this->lblH44->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH44->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH43
			// 
			this->lblH43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH43->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH43->Location = System::Drawing::Point(230, 169);
			this->lblH43->Name = L"lblH43";
			this->lblH43->Size = System::Drawing::Size(11, 21);
			this->lblH43->TabIndex = 35;
			this->lblH43->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH43->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH42
			// 
			this->lblH42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH42->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH42->Location = System::Drawing::Point(213, 169);
			this->lblH42->Name = L"lblH42";
			this->lblH42->Size = System::Drawing::Size(11, 21);
			this->lblH42->TabIndex = 34;
			this->lblH42->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH42->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH41
			// 
			this->lblH41->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH41->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH41->Location = System::Drawing::Point(196, 169);
			this->lblH41->Name = L"lblH41";
			this->lblH41->Size = System::Drawing::Size(11, 21);
			this->lblH41->TabIndex = 33;
			this->lblH41->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH41->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO44
			// 
			this->lblO44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO44->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO44->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO44->Location = System::Drawing::Point(151, 169);
			this->lblO44->Name = L"lblO44";
			this->lblO44->Size = System::Drawing::Size(23, 21);
			this->lblO44->TabIndex = 32;
			this->lblO44->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO43
			// 
			this->lblO43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO43->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO43->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO43->Location = System::Drawing::Point(122, 169);
			this->lblO43->Name = L"lblO43";
			this->lblO43->Size = System::Drawing::Size(23, 21);
			this->lblO43->TabIndex = 31;
			this->lblO43->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO42
			// 
			this->lblO42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO42->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO42->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO42->Location = System::Drawing::Point(93, 169);
			this->lblO42->Name = L"lblO42";
			this->lblO42->Size = System::Drawing::Size(23, 21);
			this->lblO42->TabIndex = 30;
			this->lblO42->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO41
			// 
			this->lblO41->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO41->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO41->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO41->Location = System::Drawing::Point(64, 169);
			this->lblO41->Name = L"lblO41";
			this->lblO41->Size = System::Drawing::Size(23, 21);
			this->lblO41->TabIndex = 29;
			this->lblO41->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblH54
			// 
			this->lblH54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH54->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH54->Location = System::Drawing::Point(247, 200);
			this->lblH54->Name = L"lblH54";
			this->lblH54->Size = System::Drawing::Size(11, 21);
			this->lblH54->TabIndex = 44;
			this->lblH54->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH54->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH53
			// 
			this->lblH53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH53->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH53->Location = System::Drawing::Point(230, 200);
			this->lblH53->Name = L"lblH53";
			this->lblH53->Size = System::Drawing::Size(11, 21);
			this->lblH53->TabIndex = 43;
			this->lblH53->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH53->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH52
			// 
			this->lblH52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH52->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH52->Location = System::Drawing::Point(213, 200);
			this->lblH52->Name = L"lblH52";
			this->lblH52->Size = System::Drawing::Size(11, 21);
			this->lblH52->TabIndex = 42;
			this->lblH52->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH52->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH51
			// 
			this->lblH51->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH51->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH51->Location = System::Drawing::Point(196, 200);
			this->lblH51->Name = L"lblH51";
			this->lblH51->Size = System::Drawing::Size(11, 21);
			this->lblH51->TabIndex = 41;
			this->lblH51->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH51->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO54
			// 
			this->lblO54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO54->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO54->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO54->Location = System::Drawing::Point(151, 200);
			this->lblO54->Name = L"lblO54";
			this->lblO54->Size = System::Drawing::Size(23, 21);
			this->lblO54->TabIndex = 40;
			this->lblO54->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO53
			// 
			this->lblO53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO53->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO53->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO53->Location = System::Drawing::Point(122, 200);
			this->lblO53->Name = L"lblO53";
			this->lblO53->Size = System::Drawing::Size(23, 21);
			this->lblO53->TabIndex = 39;
			this->lblO53->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO52
			// 
			this->lblO52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO52->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO52->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO52->Location = System::Drawing::Point(93, 200);
			this->lblO52->Name = L"lblO52";
			this->lblO52->Size = System::Drawing::Size(23, 21);
			this->lblO52->TabIndex = 38;
			this->lblO52->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO51
			// 
			this->lblO51->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO51->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO51->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO51->Location = System::Drawing::Point(64, 200);
			this->lblO51->Name = L"lblO51";
			this->lblO51->Size = System::Drawing::Size(23, 21);
			this->lblO51->TabIndex = 37;
			this->lblO51->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblH64
			// 
			this->lblH64->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH64->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH64->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH64->Location = System::Drawing::Point(247, 230);
			this->lblH64->Name = L"lblH64";
			this->lblH64->Size = System::Drawing::Size(11, 21);
			this->lblH64->TabIndex = 52;
			this->lblH64->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH64->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH63
			// 
			this->lblH63->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH63->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH63->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH63->Location = System::Drawing::Point(230, 230);
			this->lblH63->Name = L"lblH63";
			this->lblH63->Size = System::Drawing::Size(11, 21);
			this->lblH63->TabIndex = 51;
			this->lblH63->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH63->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH62
			// 
			this->lblH62->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH62->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH62->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH62->Location = System::Drawing::Point(213, 230);
			this->lblH62->Name = L"lblH62";
			this->lblH62->Size = System::Drawing::Size(11, 21);
			this->lblH62->TabIndex = 50;
			this->lblH62->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH62->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH61
			// 
			this->lblH61->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH61->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH61->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH61->Location = System::Drawing::Point(196, 230);
			this->lblH61->Name = L"lblH61";
			this->lblH61->Size = System::Drawing::Size(11, 21);
			this->lblH61->TabIndex = 49;
			this->lblH61->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH61->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO64
			// 
			this->lblO64->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO64->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO64->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO64->Location = System::Drawing::Point(151, 230);
			this->lblO64->Name = L"lblO64";
			this->lblO64->Size = System::Drawing::Size(23, 21);
			this->lblO64->TabIndex = 48;
			this->lblO64->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO63
			// 
			this->lblO63->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO63->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO63->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO63->Location = System::Drawing::Point(122, 230);
			this->lblO63->Name = L"lblO63";
			this->lblO63->Size = System::Drawing::Size(23, 21);
			this->lblO63->TabIndex = 47;
			this->lblO63->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO62
			// 
			this->lblO62->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO62->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO62->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO62->Location = System::Drawing::Point(93, 230);
			this->lblO62->Name = L"lblO62";
			this->lblO62->Size = System::Drawing::Size(23, 21);
			this->lblO62->TabIndex = 46;
			this->lblO62->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO61
			// 
			this->lblO61->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO61->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO61->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO61->Location = System::Drawing::Point(64, 230);
			this->lblO61->Name = L"lblO61";
			this->lblO61->Size = System::Drawing::Size(23, 21);
			this->lblO61->TabIndex = 45;
			this->lblO61->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblH74
			// 
			this->lblH74->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH74->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH74->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH74->Location = System::Drawing::Point(247, 261);
			this->lblH74->Name = L"lblH74";
			this->lblH74->Size = System::Drawing::Size(11, 21);
			this->lblH74->TabIndex = 60;
			this->lblH74->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH74->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH73
			// 
			this->lblH73->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH73->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH73->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH73->Location = System::Drawing::Point(230, 261);
			this->lblH73->Name = L"lblH73";
			this->lblH73->Size = System::Drawing::Size(11, 21);
			this->lblH73->TabIndex = 59;
			this->lblH73->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH73->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH72
			// 
			this->lblH72->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH72->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH72->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH72->Location = System::Drawing::Point(213, 261);
			this->lblH72->Name = L"lblH72";
			this->lblH72->Size = System::Drawing::Size(11, 21);
			this->lblH72->TabIndex = 58;
			this->lblH72->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH72->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH71
			// 
			this->lblH71->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH71->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH71->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH71->Location = System::Drawing::Point(196, 261);
			this->lblH71->Name = L"lblH71";
			this->lblH71->Size = System::Drawing::Size(11, 21);
			this->lblH71->TabIndex = 57;
			this->lblH71->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH71->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO74
			// 
			this->lblO74->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO74->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO74->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO74->Location = System::Drawing::Point(151, 261);
			this->lblO74->Name = L"lblO74";
			this->lblO74->Size = System::Drawing::Size(23, 21);
			this->lblO74->TabIndex = 56;
			this->lblO74->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO73
			// 
			this->lblO73->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO73->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO73->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO73->Location = System::Drawing::Point(122, 261);
			this->lblO73->Name = L"lblO73";
			this->lblO73->Size = System::Drawing::Size(23, 21);
			this->lblO73->TabIndex = 55;
			this->lblO73->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO72
			// 
			this->lblO72->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO72->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO72->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO72->Location = System::Drawing::Point(93, 261);
			this->lblO72->Name = L"lblO72";
			this->lblO72->Size = System::Drawing::Size(23, 21);
			this->lblO72->TabIndex = 54;
			this->lblO72->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO71
			// 
			this->lblO71->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO71->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO71->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO71->Location = System::Drawing::Point(64, 261);
			this->lblO71->Name = L"lblO71";
			this->lblO71->Size = System::Drawing::Size(23, 21);
			this->lblO71->TabIndex = 53;
			this->lblO71->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblH84
			// 
			this->lblH84->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH84->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH84->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH84->Location = System::Drawing::Point(247, 293);
			this->lblH84->Name = L"lblH84";
			this->lblH84->Size = System::Drawing::Size(11, 21);
			this->lblH84->TabIndex = 68;
			this->lblH84->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH84->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH83
			// 
			this->lblH83->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH83->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH83->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH83->Location = System::Drawing::Point(230, 293);
			this->lblH83->Name = L"lblH83";
			this->lblH83->Size = System::Drawing::Size(11, 21);
			this->lblH83->TabIndex = 67;
			this->lblH83->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH83->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH82
			// 
			this->lblH82->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH82->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH82->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH82->Location = System::Drawing::Point(213, 293);
			this->lblH82->Name = L"lblH82";
			this->lblH82->Size = System::Drawing::Size(11, 21);
			this->lblH82->TabIndex = 66;
			this->lblH82->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH82->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH81
			// 
			this->lblH81->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH81->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH81->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH81->Location = System::Drawing::Point(196, 293);
			this->lblH81->Name = L"lblH81";
			this->lblH81->Size = System::Drawing::Size(11, 21);
			this->lblH81->TabIndex = 65;
			this->lblH81->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH81->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO84
			// 
			this->lblO84->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO84->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO84->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO84->Location = System::Drawing::Point(151, 293);
			this->lblO84->Name = L"lblO84";
			this->lblO84->Size = System::Drawing::Size(23, 21);
			this->lblO84->TabIndex = 64;
			this->lblO84->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO83
			// 
			this->lblO83->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO83->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO83->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO83->Location = System::Drawing::Point(122, 293);
			this->lblO83->Name = L"lblO83";
			this->lblO83->Size = System::Drawing::Size(23, 21);
			this->lblO83->TabIndex = 63;
			this->lblO83->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO82
			// 
			this->lblO82->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO82->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO82->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO82->Location = System::Drawing::Point(93, 293);
			this->lblO82->Name = L"lblO82";
			this->lblO82->Size = System::Drawing::Size(23, 21);
			this->lblO82->TabIndex = 62;
			this->lblO82->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO81
			// 
			this->lblO81->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO81->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO81->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO81->Location = System::Drawing::Point(64, 293);
			this->lblO81->Name = L"lblO81";
			this->lblO81->Size = System::Drawing::Size(23, 21);
			this->lblO81->TabIndex = 61;
			this->lblO81->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblH94
			// 
			this->lblH94->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH94->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH94->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH94->Location = System::Drawing::Point(247, 325);
			this->lblH94->Name = L"lblH94";
			this->lblH94->Size = System::Drawing::Size(11, 21);
			this->lblH94->TabIndex = 76;
			this->lblH94->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH94->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH93
			// 
			this->lblH93->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH93->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH93->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH93->Location = System::Drawing::Point(230, 325);
			this->lblH93->Name = L"lblH93";
			this->lblH93->Size = System::Drawing::Size(11, 21);
			this->lblH93->TabIndex = 75;
			this->lblH93->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH93->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH92
			// 
			this->lblH92->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH92->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH92->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH92->Location = System::Drawing::Point(213, 325);
			this->lblH92->Name = L"lblH92";
			this->lblH92->Size = System::Drawing::Size(11, 21);
			this->lblH92->TabIndex = 74;
			this->lblH92->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH92->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblH91
			// 
			this->lblH91->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblH91->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblH91->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblH91->Location = System::Drawing::Point(196, 325);
			this->lblH91->Name = L"lblH91";
			this->lblH91->Size = System::Drawing::Size(11, 21);
			this->lblH91->TabIndex = 73;
			this->lblH91->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblH91->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblO94
			// 
			this->lblO94->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO94->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO94->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO94->Location = System::Drawing::Point(151, 325);
			this->lblO94->Name = L"lblO94";
			this->lblO94->Size = System::Drawing::Size(23, 21);
			this->lblO94->TabIndex = 72;
			this->lblO94->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO93
			// 
			this->lblO93->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO93->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO93->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO93->Location = System::Drawing::Point(122, 325);
			this->lblO93->Name = L"lblO93";
			this->lblO93->Size = System::Drawing::Size(23, 21);
			this->lblO93->TabIndex = 71;
			this->lblO93->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO92
			// 
			this->lblO92->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO92->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO92->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO92->Location = System::Drawing::Point(93, 325);
			this->lblO92->Name = L"lblO92";
			this->lblO92->Size = System::Drawing::Size(23, 21);
			this->lblO92->TabIndex = 70;
			this->lblO92->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblO91
			// 
			this->lblO91->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblO91->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblO91->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblO91->Location = System::Drawing::Point(64, 325);
			this->lblO91->Name = L"lblO91";
			this->lblO91->Size = System::Drawing::Size(23, 21);
			this->lblO91->TabIndex = 69;
			this->lblO91->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblHa4
			// 
			this->lblHa4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblHa4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblHa4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblHa4->Location = System::Drawing::Point(247, 356);
			this->lblHa4->Name = L"lblHa4";
			this->lblHa4->Size = System::Drawing::Size(11, 21);
			this->lblHa4->TabIndex = 84;
			this->lblHa4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblHa4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblHa3
			// 
			this->lblHa3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblHa3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblHa3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblHa3->Location = System::Drawing::Point(230, 356);
			this->lblHa3->Name = L"lblHa3";
			this->lblHa3->Size = System::Drawing::Size(11, 21);
			this->lblHa3->TabIndex = 83;
			this->lblHa3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblHa3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblHa2
			// 
			this->lblHa2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblHa2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblHa2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblHa2->Location = System::Drawing::Point(213, 356);
			this->lblHa2->Name = L"lblHa2";
			this->lblHa2->Size = System::Drawing::Size(11, 21);
			this->lblHa2->TabIndex = 82;
			this->lblHa2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblHa2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblHa1
			// 
			this->lblHa1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblHa1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblHa1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblHa1->Location = System::Drawing::Point(196, 356);
			this->lblHa1->Name = L"lblHa1";
			this->lblHa1->Size = System::Drawing::Size(11, 21);
			this->lblHa1->TabIndex = 81;
			this->lblHa1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblHa1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblOa4
			// 
			this->lblOa4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblOa4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblOa4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblOa4->Location = System::Drawing::Point(151, 356);
			this->lblOa4->Name = L"lblOa4";
			this->lblOa4->Size = System::Drawing::Size(23, 21);
			this->lblOa4->TabIndex = 80;
			this->lblOa4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblOa3
			// 
			this->lblOa3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblOa3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblOa3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblOa3->Location = System::Drawing::Point(122, 356);
			this->lblOa3->Name = L"lblOa3";
			this->lblOa3->Size = System::Drawing::Size(23, 21);
			this->lblOa3->TabIndex = 79;
			this->lblOa3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblOa2
			// 
			this->lblOa2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblOa2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblOa2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblOa2->Location = System::Drawing::Point(93, 356);
			this->lblOa2->Name = L"lblOa2";
			this->lblOa2->Size = System::Drawing::Size(23, 21);
			this->lblOa2->TabIndex = 78;
			this->lblOa2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblOa1
			// 
			this->lblOa1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblOa1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblOa1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblOa1->Location = System::Drawing::Point(64, 356);
			this->lblOa1->Name = L"lblOa1";
			this->lblOa1->Size = System::Drawing::Size(23, 21);
			this->lblOa1->TabIndex = 77;
			this->lblOa1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::labelO_MouseDown);
			// 
			// lblPrb1
			// 
			this->lblPrb1->AutoSize = true;
			this->lblPrb1->Location = System::Drawing::Point(14, 77);
			this->lblPrb1->Name = L"lblPrb1";
			this->lblPrb1->Size = System::Drawing::Size(44, 13);
			this->lblPrb1->TabIndex = 85;
			this->lblPrb1->Text = L"Próba 1";
			this->lblPrb1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb2
			// 
			this->lblPrb2->AutoSize = true;
			this->lblPrb2->Location = System::Drawing::Point(14, 107);
			this->lblPrb2->Name = L"lblPrb2";
			this->lblPrb2->Size = System::Drawing::Size(44, 13);
			this->lblPrb2->TabIndex = 86;
			this->lblPrb2->Text = L"Próba 2";
			this->lblPrb2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb3
			// 
			this->lblPrb3->AutoSize = true;
			this->lblPrb3->Location = System::Drawing::Point(14, 139);
			this->lblPrb3->Name = L"lblPrb3";
			this->lblPrb3->Size = System::Drawing::Size(44, 13);
			this->lblPrb3->TabIndex = 87;
			this->lblPrb3->Text = L"Próba 3";
			this->lblPrb3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb4
			// 
			this->lblPrb4->AutoSize = true;
			this->lblPrb4->Location = System::Drawing::Point(14, 170);
			this->lblPrb4->Name = L"lblPrb4";
			this->lblPrb4->Size = System::Drawing::Size(44, 13);
			this->lblPrb4->TabIndex = 88;
			this->lblPrb4->Text = L"Próba 4";
			this->lblPrb4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb5
			// 
			this->lblPrb5->AutoSize = true;
			this->lblPrb5->Location = System::Drawing::Point(14, 201);
			this->lblPrb5->Name = L"lblPrb5";
			this->lblPrb5->Size = System::Drawing::Size(44, 13);
			this->lblPrb5->TabIndex = 89;
			this->lblPrb5->Text = L"Próba 5";
			this->lblPrb5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb6
			// 
			this->lblPrb6->AutoSize = true;
			this->lblPrb6->Location = System::Drawing::Point(14, 231);
			this->lblPrb6->Name = L"lblPrb6";
			this->lblPrb6->Size = System::Drawing::Size(44, 13);
			this->lblPrb6->TabIndex = 90;
			this->lblPrb6->Text = L"Próba 6";
			this->lblPrb6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb7
			// 
			this->lblPrb7->AutoSize = true;
			this->lblPrb7->Location = System::Drawing::Point(14, 262);
			this->lblPrb7->Name = L"lblPrb7";
			this->lblPrb7->Size = System::Drawing::Size(44, 13);
			this->lblPrb7->TabIndex = 91;
			this->lblPrb7->Text = L"Próba 7";
			this->lblPrb7->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb8
			// 
			this->lblPrb8->AutoSize = true;
			this->lblPrb8->Location = System::Drawing::Point(14, 294);
			this->lblPrb8->Name = L"lblPrb8";
			this->lblPrb8->Size = System::Drawing::Size(44, 13);
			this->lblPrb8->TabIndex = 92;
			this->lblPrb8->Text = L"Próba 8";
			this->lblPrb8->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb9
			// 
			this->lblPrb9->AutoSize = true;
			this->lblPrb9->Location = System::Drawing::Point(14, 326);
			this->lblPrb9->Name = L"lblPrb9";
			this->lblPrb9->Size = System::Drawing::Size(44, 13);
			this->lblPrb9->TabIndex = 93;
			this->lblPrb9->Text = L"Próba 9";
			this->lblPrb9->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// lblPrb10
			// 
			this->lblPrb10->AutoSize = true;
			this->lblPrb10->Location = System::Drawing::Point(14, 359);
			this->lblPrb10->Name = L"lblPrb10";
			this->lblPrb10->Size = System::Drawing::Size(50, 13);
			this->lblPrb10->TabIndex = 94;
			this->lblPrb10->Text = L"Próba 10";
			this->lblPrb10->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->graToolStripMenuItem, 
				this->pomocToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(273, 24);
			this->menuStrip1->TabIndex = 95;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// graToolStripMenuItem
			// 
			this->graToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->nowaGraToolStripMenuItem, 
				this->toolStripMenuItem1, this->zakończProgramToolStripMenuItem});
			this->graToolStripMenuItem->Name = L"graToolStripMenuItem";
			this->graToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->graToolStripMenuItem->Text = L"&Gra";
			// 
			// nowaGraToolStripMenuItem
			// 
			this->nowaGraToolStripMenuItem->Name = L"nowaGraToolStripMenuItem";
			this->nowaGraToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->nowaGraToolStripMenuItem->Text = L"&Nowa gra";
			this->nowaGraToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::nowaGraToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(164, 6);
			// 
			// zakończProgramToolStripMenuItem
			// 
			this->zakończProgramToolStripMenuItem->Name = L"zakończProgramToolStripMenuItem";
			this->zakończProgramToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->zakończProgramToolStripMenuItem->Text = L"&Zakończ program";
			this->zakończProgramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zakończProgramToolStripMenuItem_Click);
			// 
			// pomocToolStripMenuItem
			// 
			this->pomocToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->instrukcjaToolStripMenuItem, 
				this->toolStripMenuItem2, this->oProgramieToolStripMenuItem});
			this->pomocToolStripMenuItem->Name = L"pomocToolStripMenuItem";
			this->pomocToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->pomocToolStripMenuItem->Text = L"&Pomoc";
			// 
			// instrukcjaToolStripMenuItem
			// 
			this->instrukcjaToolStripMenuItem->Name = L"instrukcjaToolStripMenuItem";
			this->instrukcjaToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->instrukcjaToolStripMenuItem->Text = L"&Instrukcja";
			this->instrukcjaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::instrukcjaToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(138, 6);
			// 
			// oProgramieToolStripMenuItem
			// 
			this->oProgramieToolStripMenuItem->Name = L"oProgramieToolStripMenuItem";
			this->oProgramieToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->oProgramieToolStripMenuItem->Text = L"O progr&amie";
			this->oProgramieToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::oProgramieToolStripMenuItem_Click);
			// 
			// lblTimer
			// 
			this->lblTimer->AutoSize = true;
			this->lblTimer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblTimer->Location = System::Drawing::Point(204, 30);
			this->lblTimer->Name = L"lblTimer";
			this->lblTimer->Size = System::Drawing::Size(49, 18);
			this->lblTimer->TabIndex = 96;
			this->lblTimer->Text = L"00:00";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(202, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 9);
			this->label2->TabIndex = 97;
			this->label2->Text = L"NAJLEPSZY:";
			// 
			// lblTop
			// 
			this->lblTop->AutoSize = true;
			this->lblTop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblTop->Location = System::Drawing::Point(210, 57);
			this->lblTop->Name = L"lblTop";
			this->lblTop->Size = System::Drawing::Size(34, 13);
			this->lblTop->TabIndex = 96;
			this->lblTop->Text = L"00:00";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(273, 388);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblTop);
			this->Controls->Add(this->lblTimer);
			this->Controls->Add(this->lblPrb10);
			this->Controls->Add(this->lblPrb9);
			this->Controls->Add(this->lblPrb8);
			this->Controls->Add(this->lblPrb7);
			this->Controls->Add(this->lblPrb6);
			this->Controls->Add(this->lblPrb5);
			this->Controls->Add(this->lblPrb4);
			this->Controls->Add(this->lblPrb3);
			this->Controls->Add(this->lblPrb2);
			this->Controls->Add(this->lblPrb1);
			this->Controls->Add(this->lblHa4);
			this->Controls->Add(this->lblHa3);
			this->Controls->Add(this->lblHa2);
			this->Controls->Add(this->lblHa1);
			this->Controls->Add(this->lblOa4);
			this->Controls->Add(this->lblOa3);
			this->Controls->Add(this->lblOa2);
			this->Controls->Add(this->lblOa1);
			this->Controls->Add(this->lblH94);
			this->Controls->Add(this->lblH93);
			this->Controls->Add(this->lblH92);
			this->Controls->Add(this->lblH91);
			this->Controls->Add(this->lblO94);
			this->Controls->Add(this->lblO93);
			this->Controls->Add(this->lblO92);
			this->Controls->Add(this->lblO91);
			this->Controls->Add(this->lblH84);
			this->Controls->Add(this->lblH83);
			this->Controls->Add(this->lblH82);
			this->Controls->Add(this->lblH81);
			this->Controls->Add(this->lblO84);
			this->Controls->Add(this->lblO83);
			this->Controls->Add(this->lblO82);
			this->Controls->Add(this->lblO81);
			this->Controls->Add(this->lblH74);
			this->Controls->Add(this->lblH73);
			this->Controls->Add(this->lblH72);
			this->Controls->Add(this->lblH71);
			this->Controls->Add(this->lblO74);
			this->Controls->Add(this->lblO73);
			this->Controls->Add(this->lblO72);
			this->Controls->Add(this->lblO71);
			this->Controls->Add(this->lblH64);
			this->Controls->Add(this->lblH63);
			this->Controls->Add(this->lblH62);
			this->Controls->Add(this->lblH61);
			this->Controls->Add(this->lblO64);
			this->Controls->Add(this->lblO63);
			this->Controls->Add(this->lblO62);
			this->Controls->Add(this->lblO61);
			this->Controls->Add(this->lblH54);
			this->Controls->Add(this->lblH53);
			this->Controls->Add(this->lblH52);
			this->Controls->Add(this->lblH51);
			this->Controls->Add(this->lblO54);
			this->Controls->Add(this->lblO53);
			this->Controls->Add(this->lblO52);
			this->Controls->Add(this->lblO51);
			this->Controls->Add(this->lblH44);
			this->Controls->Add(this->lblH43);
			this->Controls->Add(this->lblH42);
			this->Controls->Add(this->lblH41);
			this->Controls->Add(this->lblO44);
			this->Controls->Add(this->lblO43);
			this->Controls->Add(this->lblO42);
			this->Controls->Add(this->lblO41);
			this->Controls->Add(this->lblH34);
			this->Controls->Add(this->lblH33);
			this->Controls->Add(this->lblH32);
			this->Controls->Add(this->lblH31);
			this->Controls->Add(this->lblO34);
			this->Controls->Add(this->lblO33);
			this->Controls->Add(this->lblO32);
			this->Controls->Add(this->lblO31);
			this->Controls->Add(this->lblH24);
			this->Controls->Add(this->lblH23);
			this->Controls->Add(this->lblH22);
			this->Controls->Add(this->lblH21);
			this->Controls->Add(this->lblO24);
			this->Controls->Add(this->lblO23);
			this->Controls->Add(this->lblO22);
			this->Controls->Add(this->lblO21);
			this->Controls->Add(this->lblH14);
			this->Controls->Add(this->lblH13);
			this->Controls->Add(this->lblH12);
			this->Controls->Add(this->lblH11);
			this->Controls->Add(this->lblO14);
			this->Controls->Add(this->lblO13);
			this->Controls->Add(this->lblO12);
			this->Controls->Add(this->lblO11);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblZ4);
			this->Controls->Add(this->lblZ3);
			this->Controls->Add(this->lblZ2);
			this->Controls->Add(this->lblZ1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WSIZ Mastermind";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_Closing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private: System::Drawing::Color getColor(int colId) 
		{
			switch (colId)
			{
				default: return Color::Black;
				case 0: return Color::Blue;
				case 1: return Color::Green;
				case 2: return Color::Red;
				case 3: return Color::Yellow;
				case 4: return Color::Purple;
				case 5: return Color::Orange;
				case 6: return Color::LightGray;
				case 8: return Color::Black;
				case 9: return Color::White;
			}
		}
private: System::Int16 getColorId(Color colId) 
		{
			if (colId == Color::Blue) return 0;
			else if (colId == Color::Green) return 1;
			else if (colId == Color::Red) return 2;
			else if (colId == Color::Yellow) return 3;
			else if (colId == Color::Purple) return 4;
			else if (colId == Color::Orange) return 5;
			else if (colId == Color::LightGray) return 6;
			else if (colId == Color::Black) return 8;
			else if (colId == Color::White) return 9;
			else return 0;
		}
private: System::Void pokazZadanie() {
			 lblZ1->BackColor = getColor(intSzukane[0]);
			 lblZ2->BackColor = getColor(intSzukane[1]);
			 lblZ3->BackColor = getColor(intSzukane[2]);
			 lblZ4->BackColor = getColor(intSzukane[3]);
			 lblZ1->Text = "";
			 lblZ2->Text = "";
			 lblZ3->Text = "";
			 lblZ4->Text = "";
		 }
private: System::String^ formatTime(time_t cT) {
			std::ostringstream strs;
			UInt32 mins, secs, msecs;
			mins = floor(cT/60);
			secs = cT-(mins*60);
			strs << (mins<=9 ? "0" : "") << mins << ":" << (secs<=9 ? "0" : "") << secs;
			std::string str = strs.str();
			return gcnew String(str.c_str());
		 }
private: System::Void Prog_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e) {
			 if(e->Button == System::Windows::Forms::MouseButtons::Right) {
				 //Console::Beep();
				 // pobieramy dane
				 Int16 intTmp[4] = { getColorId(lblArrO[intProba-1,0]->BackColor),getColorId(lblArrO[intProba-1,1]->BackColor),getColorId(lblArrO[intProba-1,2]->BackColor),getColorId(lblArrO[intProba-1,3]->BackColor)};
				 // sprawdzamy, czy mamy trafione na pozycji
				 int np = 0;
				 for (int i=0; i < 4; i++)
					 if (intTmp[i] == intSzukane[i]) {
						 np++;
						 intTmp[i]=-1;
					 }
				 Boolean odgadnieto = (np == 4);
				 // sprawdzamy, czy mamy trafione w złym miejscu
				 int nz = 0;
				 for (int i=0; i < 4; i++)
					 for (int j=0; j<4; j++)
						 if (intTmp[j] == intSzukane[i] && intTmp[i] != -1) {
							 nz++;
							 intTmp[j]=-2;
							 break;
						 }
				 // ustawiamy podpowiedź
				 for (int i=0; i < 4; i++)
					 if (np>0) {
						 np--;
						 lblArrH[intProba-1,i]->BackColor = getColor(8);
					 } else if (nz>0) {
						 nz--;
						 lblArrH[intProba-1,i]->BackColor = getColor(9);
					 } else
						 lblArrH[intProba-1,i]->Text = "X";
				if (!odgadnieto)
				{
					if (intProba == 10) 
					{
						// nie udalo sie
						int tmp = rand()%2+1;
						std::string start = "Sounds\\gameover", result, end = ".wav";
						char numstr[1];
						result = start + itoa(tmp, numstr, 10) + ".wav";
						PlaySoundA((LPCSTR)result.c_str(), NULL, SND_FILENAME | SND_ASYNC);
						gameInProgress = false;
						pokazZadanie();
						return;
					} else {
						int tmp = rand()%9+1;
						std::string start = "Sounds\\work", result, end = ".wav";
						char numstr[1];
						result = start + itoa(tmp, numstr, 10) + ".wav";
						PlaySoundA((LPCSTR)result.c_str(), NULL, SND_FILENAME | SND_ASYNC);
					}
					lblArrPrb[intProba-1]->ForeColor = MyForm::Form::BackColor;
					intProba++;
					lblArrPrb[intProba-1]->ForeColor = Color::Black;
					lblTop->Text = formatTime(topScore[intProba]);
					return;
				} 
				// odgadnieto :)
				if (cTime < topScore[intProba] || topScore[intProba] == 0)  topScore[intProba] = cTime; // top w próbie
				if (cTime < topScore[0] || topScore[0] == 0)  topScore[0] = cTime; // top of the top :)
				
				int tmp = rand()%7+1;
				std::string start = "Sounds\\ok", result, end = ".wav";
				char numstr[1];
				result = start + itoa(tmp, numstr, 10) + ".wav";
				PlaySoundA((LPCSTR)result.c_str(), NULL, SND_FILENAME | SND_ASYNC);
				pokazZadanie();
				gameInProgress = false;
				timer1->Enabled = false;
				return;
			 }

		 }
private: System::Void game_Start() {
			 // losujemy kolory
			 // 0 - niebieski, 1 - zielony, 2 - czerowny, 3 - zółty, 4 - fioletowy, 5 - pomarańczowy
			 for (int i= 0; i<10;i++)
			 {
				 lblArrPrb[i]->ForeColor = MyForm::Form::BackColor;
				 for(int j=0; j<4; j++)
				 {
					 lblArrO[i,j]->BackColor=getColor(6);
					 lblArrH[i,j]->BackColor=getColor(6);
					 lblArrH[i,j]->Text = "";
				 }
			 }
			 intSzukane[0] = (rand()%6);
			 intSzukane[1] = (rand()%6);
			 intSzukane[2] = (rand()%6);
			 intSzukane[3] = (rand()%6);

			 intProba = 1;
			 lblArrPrb[intProba-1]->ForeColor = Color::Black;

			 lblZ1->BackColor = getColor(6);
			 lblZ2->BackColor = getColor(6);
			 lblZ3->BackColor = getColor(6);
			 lblZ4->BackColor = getColor(6);
			 lblZ1->Text = "?";
			 lblZ2->Text = "?";
			 lblZ3->Text = "?";
			 lblZ4->Text = "?";

			 gameInProgress = true;
			 sTime = time(NULL);
			 timer1->Enabled = true;
			 lblTop->Text = formatTime(topScore[intProba]);
		 }

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			// wczytaj najlepsze wyniki
			fstream myFile;
			myFile.open("HighScore.dat", fstream::in );
			string strT0,strT1;
			if(!myFile.fail())
			{
				getline(myFile,strT0);
				if (strT0 == "[High Score]") 
				{
					getline(myFile,strT0);
					getline(myFile,strT1);
					int a = atoi(strT0.c_str());
					int b = atoi(strT1.c_str()) ^ MAGIC_NUMBER;
					if (a == b)
						topScore[0] = atoi(strT0.c_str());
				}
				
				for (int i=1; i <= 10; i++)
				{
					std::ostringstream strs;
					strs << "[p" << i << "]";
					std::string str = strs.str();
					getline(myFile,strT0);
					if (strT0==str)
					{
						getline(myFile,strT0);
						getline(myFile,strT1);
						int a = atoi(strT0.c_str());
						int b = atoi(strT1.c_str()) ^ MAGIC_NUMBER;
						if (a == b)
							topScore[i] = atoi(strT0.c_str());
					}
				}
				myFile.close();
			}
			 
			 // start
			 srand(time(NULL));

			 game_Start();
			 

		 }
private: System::Void MyForm_Closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			// zapisz najlepszy wynik
			ofstream myFile;
			myFile.open("Highscore.dat");

			if(!myFile.fail())
			{
				myFile << "[High Score]\n" << topScore[0] << "\n" << (topScore[0] ^ MAGIC_NUMBER) << "\n";
				for(int i=1; i<=10;i++)
					myFile << "[p" << i << "]\n" << topScore[i] << "\n" << (topScore[i] ^ MAGIC_NUMBER) << "\n";
				myFile.close();
			}
		 }
private: System::Void IndexOf(Array^ matrix, Object^ element, int% row, int% column)
	{
		row = column = -1;

		for (int i=matrix->GetLowerBound(0); i <= matrix->GetUpperBound(0); ++i)
			for (int j=matrix->GetLowerBound(1); j <= matrix->GetUpperBound(1); ++j)
				if (Object::ReferenceEquals(matrix->GetValue(i, j), element))
				{
					row = i;
					column = j;
					return;
				}
	}
private: System::Void labelO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e) {
			if(e->Button == System::Windows::Forms::MouseButtons::Left && gameInProgress)
			{
				String^ buttonName = safe_cast<Label^>(sender)->Name;
				int row = 0, column = 0;
				IndexOf(lblArrO, sender, row, column);
				Int16 col = getColorId(lblArrO[row,column]->BackColor);
				if (row+1 == intProba)
					lblArrO[row,column]->BackColor = getColor(col==6 ? 0 : col+1);
				} else if(e->Button == System::Windows::Forms::MouseButtons::Right) Prog_MouseDown (sender, e);
			}

private: System::Void zakończProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		 }
private: System::Void nowaGraToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 game_Start();
		 }
private: System::Void oProgramieToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			frmAbout^ frm = gcnew frmAbout(this);
			frm->Show();
			this->Enabled = false;
		 }
private: System::Void instrukcjaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			frmInstrukcja^ frm = gcnew frmInstrukcja(this);
			frm->Show();
			this->Enabled = false;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if (!gameInProgress) return;
			cTime = time(NULL)-sTime;
			lblTimer->Text = formatTime(cTime);
		 }
};
}
