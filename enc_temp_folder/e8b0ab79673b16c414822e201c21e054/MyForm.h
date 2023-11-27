#pragma once
#include "CLservicesFichier.h"
#include "CLserviceImage.h"

namespace prosit5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private :
		Windows::Forms::Button^ btn_first;
		Windows::Forms::Button^ btn_previous;
		Windows::Forms::Button^ btn_next;
		Windows::Forms::Button^ btn_last;
		Windows::Forms::PictureBox^ pctBx;
		Windows::Forms::Label^ lbl_vision;
		Windows::Forms::Button^ btn_source;
		Windows::Forms::Button^ btn_destination;
		Windows::Forms::TextBox^ txt_source;
		Windows::Forms::TextBox^ txt_destination;

		Windows::Forms::GroupBox^ gpBox_typeProcessus;

		Windows::Forms::RadioButton^ rdb_coiperEffacer;
		Windows::Forms::RadioButton^ rdb_copier;
		Windows::Forms::Button^ btn_proceder;
		Windows::Forms::TextBox^ txt_rslt;

		Windows::Forms::Label^ lbl_resultats;
		Windows::Forms::FolderBrowserDialog^ fld_source;
		Windows::Forms::FolderBrowserDialog^ fld_destination;
		
		array<String^>^ listeDeFichier;
		NS_services::CLserviceImage^ image;
		NS_services::CLserviceFichier^ svcFichier;
		int index;
		int nombreImages;
	private: System::Windows::Forms::RadioButton^ rdb_effacer;


		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_first = (gcnew System::Windows::Forms::Button());
			this->btn_previous = (gcnew System::Windows::Forms::Button());
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->btn_last = (gcnew System::Windows::Forms::Button());
			this->pctBx = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_vision = (gcnew System::Windows::Forms::Label());
			this->btn_source = (gcnew System::Windows::Forms::Button());
			this->btn_destination = (gcnew System::Windows::Forms::Button());
			this->txt_source = (gcnew System::Windows::Forms::TextBox());
			this->txt_destination = (gcnew System::Windows::Forms::TextBox());
			this->gpBox_typeProcessus = (gcnew System::Windows::Forms::GroupBox());
			this->rdb_effacer = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_coiperEffacer = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_copier = (gcnew System::Windows::Forms::RadioButton());
			this->btn_proceder = (gcnew System::Windows::Forms::Button());
			this->txt_rslt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_resultats = (gcnew System::Windows::Forms::Label());
			this->fld_source = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->fld_destination = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBx))->BeginInit();
			this->gpBox_typeProcessus->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_first
			// 
			this->btn_first->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_first->Location = System::Drawing::Point(13, 415);
			this->btn_first->Margin = System::Windows::Forms::Padding(4);
			this->btn_first->Name = L"btn_first";
			this->btn_first->Size = System::Drawing::Size(100, 28);
			this->btn_first->TabIndex = 0;
			this->btn_first->Text = L"<<";
			this->btn_first->UseVisualStyleBackColor = true;
			// 
			// btn_previous
			// 
			this->btn_previous->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_previous->Location = System::Drawing::Point(121, 415);
			this->btn_previous->Margin = System::Windows::Forms::Padding(4);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(100, 28);
			this->btn_previous->TabIndex = 1;
			this->btn_previous->Text = L"<";
			this->btn_previous->UseVisualStyleBackColor = true;
			this->btn_previous->Click += gcnew System::EventHandler(this, &MyForm::btn_previous_Click);
			// 
			// btn_next
			// 
			this->btn_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_next->Location = System::Drawing::Point(229, 415);
			this->btn_next->Margin = System::Windows::Forms::Padding(4);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(100, 28);
			this->btn_next->TabIndex = 2;
			this->btn_next->Text = L">";
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &MyForm::btn_next_Click);
			// 
			// btn_last
			// 
			this->btn_last->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_last->Location = System::Drawing::Point(337, 415);
			this->btn_last->Margin = System::Windows::Forms::Padding(4);
			this->btn_last->Name = L"btn_last";
			this->btn_last->Size = System::Drawing::Size(100, 28);
			this->btn_last->TabIndex = 3;
			this->btn_last->Text = L">>";
			this->btn_last->UseVisualStyleBackColor = true;
			this->btn_last->Click += gcnew System::EventHandler(this, &MyForm::btn_last_Click);
			// 
			// pctBx
			// 
			this->pctBx->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctBx->Location = System::Drawing::Point(13, 33);
			this->pctBx->Margin = System::Windows::Forms::Padding(4);
			this->pctBx->Name = L"pctBx";
			this->pctBx->Size = System::Drawing::Size(422, 371);
			this->pctBx->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pctBx->TabIndex = 4;
			this->pctBx->TabStop = false;
			// 
			// lbl_vision
			// 
			this->lbl_vision->AutoSize = true;
			this->lbl_vision->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_vision->Location = System::Drawing::Point(13, 10);
			this->lbl_vision->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_vision->Name = L"lbl_vision";
			this->lbl_vision->Size = System::Drawing::Size(88, 17);
			this->lbl_vision->TabIndex = 5;
			this->lbl_vision->Text = L"Visionnage";
			// 
			// btn_source
			// 
			this->btn_source->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_source->Location = System::Drawing::Point(444, 33);
			this->btn_source->Margin = System::Windows::Forms::Padding(4);
			this->btn_source->Name = L"btn_source";
			this->btn_source->Size = System::Drawing::Size(147, 25);
			this->btn_source->TabIndex = 6;
			this->btn_source->Text = L"Source";
			this->btn_source->UseVisualStyleBackColor = true;
			this->btn_source->Click += gcnew System::EventHandler(this, &MyForm::btn_source_Click);
			// 
			// btn_destination
			// 
			this->btn_destination->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_destination->Location = System::Drawing::Point(444, 65);
			this->btn_destination->Margin = System::Windows::Forms::Padding(4);
			this->btn_destination->Name = L"btn_destination";
			this->btn_destination->Size = System::Drawing::Size(147, 25);
			this->btn_destination->TabIndex = 7;
			this->btn_destination->Text = L"Destination";
			this->btn_destination->UseVisualStyleBackColor = true;
			this->btn_destination->Click += gcnew System::EventHandler(this, &MyForm::btn_destination_Click);
			// 
			// txt_source
			// 
			this->txt_source->Location = System::Drawing::Point(599, 33);
			this->txt_source->Margin = System::Windows::Forms::Padding(4);
			this->txt_source->Name = L"txt_source";
			this->txt_source->ReadOnly = true;
			this->txt_source->Size = System::Drawing::Size(408, 22);
			this->txt_source->TabIndex = 8;
			// 
			// txt_destination
			// 
			this->txt_destination->Location = System::Drawing::Point(599, 65);
			this->txt_destination->Margin = System::Windows::Forms::Padding(4);
			this->txt_destination->Name = L"txt_destination";
			this->txt_destination->ReadOnly = true;
			this->txt_destination->Size = System::Drawing::Size(408, 22);
			this->txt_destination->TabIndex = 9;
			// 
			// gpBox_typeProcessus
			// 
			this->gpBox_typeProcessus->Controls->Add(this->rdb_effacer);
			this->gpBox_typeProcessus->Controls->Add(this->rdb_coiperEffacer);
			this->gpBox_typeProcessus->Controls->Add(this->rdb_copier);
			this->gpBox_typeProcessus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->gpBox_typeProcessus->Location = System::Drawing::Point(448, 108);
			this->gpBox_typeProcessus->Margin = System::Windows::Forms::Padding(4);
			this->gpBox_typeProcessus->Name = L"gpBox_typeProcessus";
			this->gpBox_typeProcessus->Padding = System::Windows::Forms::Padding(4);
			this->gpBox_typeProcessus->Size = System::Drawing::Size(559, 54);
			this->gpBox_typeProcessus->TabIndex = 10;
			this->gpBox_typeProcessus->TabStop = false;
			this->gpBox_typeProcessus->Text = L"Type de processus";
			// 
			// rdb_effacer
			// 
			this->rdb_effacer->AutoSize = true;
			this->rdb_effacer->Location = System::Drawing::Point(476, 23);
			this->rdb_effacer->Margin = System::Windows::Forms::Padding(4);
			this->rdb_effacer->Name = L"rdb_effacer";
			this->rdb_effacer->Size = System::Drawing::Size(81, 21);
			this->rdb_effacer->TabIndex = 2;
			this->rdb_effacer->TabStop = true;
			this->rdb_effacer->Text = L"Effacer";
			this->rdb_effacer->UseVisualStyleBackColor = true;
			// 
			// rdb_coiperEffacer
			// 
			this->rdb_coiperEffacer->AutoSize = true;
			this->rdb_coiperEffacer->Location = System::Drawing::Point(272, 23);
			this->rdb_coiperEffacer->Margin = System::Windows::Forms::Padding(4);
			this->rdb_coiperEffacer->Name = L"rdb_coiperEffacer";
			this->rdb_coiperEffacer->Size = System::Drawing::Size(151, 21);
			this->rdb_coiperEffacer->TabIndex = 1;
			this->rdb_coiperEffacer->TabStop = true;
			this->rdb_coiperEffacer->Text = L"Copier et effacer";
			this->rdb_coiperEffacer->UseVisualStyleBackColor = true;
			// 
			// rdb_copier
			// 
			this->rdb_copier->AutoSize = true;
			this->rdb_copier->Location = System::Drawing::Point(151, 23);
			this->rdb_copier->Margin = System::Windows::Forms::Padding(4);
			this->rdb_copier->Name = L"rdb_copier";
			this->rdb_copier->Size = System::Drawing::Size(76, 21);
			this->rdb_copier->TabIndex = 0;
			this->rdb_copier->TabStop = true;
			this->rdb_copier->Text = L"Copier";
			this->rdb_copier->UseVisualStyleBackColor = true;
			// 
			// btn_proceder
			// 
			this->btn_proceder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_proceder->ForeColor = System::Drawing::Color::Blue;
			this->btn_proceder->Location = System::Drawing::Point(448, 174);
			this->btn_proceder->Margin = System::Windows::Forms::Padding(4);
			this->btn_proceder->Name = L"btn_proceder";
			this->btn_proceder->Size = System::Drawing::Size(560, 75);
			this->btn_proceder->TabIndex = 11;
			this->btn_proceder->Text = L"Procéder";
			this->btn_proceder->UseVisualStyleBackColor = true;
			this->btn_proceder->Click += gcnew System::EventHandler(this, &MyForm::btn_proceder_Click_1);
			// 
			// txt_rslt
			// 
			this->txt_rslt->Location = System::Drawing::Point(449, 279);
			this->txt_rslt->Margin = System::Windows::Forms::Padding(4);
			this->txt_rslt->Multiline = true;
			this->txt_rslt->Name = L"txt_rslt";
			this->txt_rslt->ReadOnly = true;
			this->txt_rslt->Size = System::Drawing::Size(557, 163);
			this->txt_rslt->TabIndex = 12;
			// 
			// lbl_resultats
			// 
			this->lbl_resultats->AutoSize = true;
			this->lbl_resultats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_resultats->Location = System::Drawing::Point(445, 260);
			this->lbl_resultats->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_resultats->Name = L"lbl_resultats";
			this->lbl_resultats->Size = System::Drawing::Size(76, 17);
			this->lbl_resultats->TabIndex = 13;
			this->lbl_resultats->Text = L"Résultats";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1021, 459);
			this->Controls->Add(this->lbl_resultats);
			this->Controls->Add(this->txt_rslt);
			this->Controls->Add(this->btn_proceder);
			this->Controls->Add(this->gpBox_typeProcessus);
			this->Controls->Add(this->txt_destination);
			this->Controls->Add(this->txt_source);
			this->Controls->Add(this->btn_destination);
			this->Controls->Add(this->btn_source);
			this->Controls->Add(this->lbl_vision);
			this->Controls->Add(this->pctBx);
			this->Controls->Add(this->btn_last);
			this->Controls->Add(this->btn_next);
			this->Controls->Add(this->btn_previous);
			this->Controls->Add(this->btn_first);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"[EI] [A2 MININF] Bloc Programmation orientée objet- Prosit 5";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBx))->EndInit();
			this->gpBox_typeProcessus->ResumeLayout(false);
			this->gpBox_typeProcessus->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = 0;
		this->nombreImages = 0;
		this->image = gcnew NS_services::CLserviceImage();
		this->svcFichier = gcnew NS_services::CLserviceFichier();
	}

	private: System::Void btn_source_Click(System::Object^ sender, System::EventArgs^ e)
	{
	int i;
	this->image = gcnew NS_services::CLserviceImage();
	this->fld_source->ShowDialog();
	this->txt_source->Text = this->fld_source->SelectedPath;
	this->listeDeFichier = this->svcFichier->explorer(this->txt_source->Text);
	for (i = 0; i < this->listeDeFichier->Length; i++)
	{
		this->txt_rslt->Text += this->listeDeFichier[i] + "\r\n";
	}
	this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
	}
	private: System::Void btn_destination_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->fld_destination->ShowDialog();
		this->txt_destination->Text = this->fld_destination->SelectedPath;
	}
	private: System::Void btn_first_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = 0;
		this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
	}
	private: System::Void btn_proceder_Click_1(System::Object^ sender, System::EventArgs^ e) {
	
		// Afficher un message de débogage
		if (this->rdb_copier->Checked == true)
		{
			MessageBox::Show("Le bouton 'copier' a été cliqué.");
			this->svcFichier->copier(this->listeDeFichier, this->txt_destination->Text);
			this->txt_rslt->Clear();
			this->txt_rslt->Text = "Les fichiers ont été copier dans le dossier : " + this->txt_destination->Text;
			// Afficher un message de débogage
		}
		else if (this->rdb_coiperEffacer->Checked == true)
		{
			// Afficher un message de débogage copier ef
			MessageBox::Show("Le bouton 'copier effacer' a été cliqué.");
			// Copier l'image dans une nouvelle instance pour libérer la référence au fichier
			System::Drawing::Bitmap^ imageCopy = gcnew System::Drawing::Bitmap(this->listeDeFichier[this->index]);
			this->pctBx->Image = imageCopy;
			this->pctBx->Invalidate();  // Forcer le rafraîchissement du PictureBox
			// Vider le PictureBox
			this->pctBx->Image = nullptr;
			// Effacer les fichiers source
			this->svcFichier->effacer(this->listeDeFichier);
			this->txt_rslt->Clear();
			this->txt_rslt->Text = "Les fichiers ont été copiés et les fichiers source ont été effacés.";

			
		
		}
		else if (this->rdb_effacer->Checked == true)
		{
			// Afficher un message de débogage copier ef
			MessageBox::Show("Le bouton 'effacer' a été cliqué.");
			this->pctBx->Image = nullptr; // libérer la référence à l'image actuelle
			this->svcFichier->effacer(this->listeDeFichier);
			this->txt_rslt->Clear();
			this->txt_rslt->Text = "Les fichiers ont été effacer dans le dossier : " + this->txt_source->Text;
		}

	}
	private: System::Void btn_next_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index < this->listeDeFichier->Length - 1)
		{
			this->index++;
			this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
		}
	}
	private: System::Void btn_previous_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index > 0)
		{
			this->index--;
			this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
		}
	}
	private: System::Void btn_last_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = this->listeDeFichier->Length - 1;
		this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
	}


};
}
