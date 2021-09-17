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
	ClearButtonClick(nullptr);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddHeaderButtonClick(TObject *Sender)
{
	TListBoxGroupHeader* header = new TListBoxGroupHeader(nullptr);
	header->Parent = ListBox;
	header->Visible = true;
	header->Text = L"Header";
	header->HitTest = true;
	header->OnMouseEnter = MouseEnter;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddItemButtonClick(TObject *Sender)
{
	TListBoxItem* item = new TListBoxItem(nullptr);
	item->Parent = ListBox;
	item->Visible = true;
	item->Text = L"Item";
	item->HitTest = true;
	item->OnMouseEnter = MouseEnter;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MouseEnter(TObject *Sender)
{
	TListBoxItem* item = dynamic_cast<TListBoxItem*>(Sender);
	if(item == nullptr) return;

	String msg = item->Text + L" entered";
	OutputMemo->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClearButtonClick(TObject *Sender)
{
	ListBox->Clear();
	OutputMemo->Lines->Clear();

	OutputMemo->Lines->Add(L"Click Add Header button.");
	OutputMemo->Lines->Add(L"Mouse over header in list and notification is posted.");
	OutputMemo->Lines->Add(L"");
	OutputMemo->Lines->Add(L"Click Add Item button.");
	OutputMemo->Lines->Add(L"Item will respond to mouse enter,");
	OutputMemo->Lines->Add(L"but header now does not.");
	OutputMemo->Lines->Add(L"");
	OutputMemo->Lines->Add(L"Click Clear button.");
	OutputMemo->Lines->Add(L"Add two headers.");
	OutputMemo->Lines->Add(L"Both headers respond to mouse enter.");
	OutputMemo->Lines->Add(L"");

}
//---------------------------------------------------------------------------

