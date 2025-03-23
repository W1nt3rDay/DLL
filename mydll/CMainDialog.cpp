// CMainDialog.cpp: 实现文件
//

#include "pch.h"
#include "mydll.h"
#include "afxdialogex.h"
#include "CMainDialog.h"


// CMainDialog 对话框

IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMainDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMainDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMainDialog 消息处理程序

HMODULE h_DLL = NULL;
void CMainDialog::OnBnClickedButton1()
{
	CFileDialog fileDlg(TRUE, _T("动态库DLL|*.DLL"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("动态库DLL|*.DLL|所有文件(*.*)|*.*||"));
	fileDlg.DoModal();
	h_DLL = LoadLibrary(fileDlg.GetPathName());
	// TODO: 在此添加控件通知处理程序代码
}

void CMainDialog::OnBnClickedButton2()
{
	FreeLibrary(h_DLL);
	// TODO: 在此添加控件通知处理程序代码
}
