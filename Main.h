//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox;
	TButton *AddHeaderButton;
	TButton *AddItemButton;
	TMemo *OutputMemo;
	TButton *ClearButton;
	void __fastcall AddHeaderButtonClick(TObject *Sender);
	void __fastcall AddItemButtonClick(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);
private:	// User declarations
	void __fastcall MouseEnter(TObject *Sender);
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
