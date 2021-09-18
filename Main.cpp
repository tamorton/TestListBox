//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMainForm *MainForm;
//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	headerCount = 0;
	itemCount = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddHeaderButtonClick(TObject *Sender)
{
	headerCount++;

	TListBoxGroupHeader* header = new TListBoxGroupHeader(nullptr);
	header->Parent = ListBox;
	header->Visible = true;
	header->Text = String(L"Header") + IntToStr(headerCount);
	header->HitTest = true;
	header->OnClick = MouseClick;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddItemButtonClick(TObject *Sender)
{
	itemCount++;

	TListBoxItem* item = new TListBoxItem(nullptr);
	item->Parent = ListBox;
	item->Visible = true;
	item->Text = String(L"Item") + IntToStr(itemCount);
	item->HitTest = true;
	item->OnClick = MouseClick;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MouseClick(TObject *Sender)
{
	TListBoxItem* item = dynamic_cast<TListBoxItem*>(Sender);
	if(item == nullptr) return;

	String msg = item->Text + L" clicked";
	OutputMemo->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClearButtonClick(TObject *Sender)
{
	headerCount = 0;
	itemCount = 0;
	ListBox->Clear();
	OutputMemo->Lines->Clear();
}
//---------------------------------------------------------------------------

