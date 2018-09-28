// E:\personal\project\reverse-tool\src\Creverse_toolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "reverse_tool.h"
#include "Creverse_toolDlg.h"
#include "afxdialogex.h"


// Creverse_toolDlg 对话框

IMPLEMENT_DYNAMIC(Creverse_toolDlg, CDialogEx)

Creverse_toolDlg::Creverse_toolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_MAIN, pParent)
{

}

Creverse_toolDlg::~Creverse_toolDlg()
{

}

void Creverse_toolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB2, m_tab);
}

BOOL Creverse_toolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog(); 
	m_tab.InsertItem(0, _T("字符转换"));
	m_tab.InsertItem(1, _T("逻辑运算"));
	m_tab.InsertItem(2, _T("json相关"));

	m_dialog1.Create(IDD_DIALOG1, &m_tab);
	m_dialog2.Create(IDD_DIALOG2, &m_tab);
	m_dialog3.Create(IDD_DIALOG3, &m_tab);
	//调整子窗口位置
	CRect rc;
	m_tab.GetClientRect(&rc);
	rc.top += 20;
	rc.bottom -= 3;
	rc.left += 2;
	rc.right -= 2;
	m_dialog1.MoveWindow(&rc);
	m_dialog2.MoveWindow(&rc);
	m_dialog3.MoveWindow(&rc);
	m_dialog1.ShowWindow(true);
	m_dialog2.ShowWindow(false);
	m_dialog3.ShowWindow(false);

	m_tab.SetCurSel(0);
	return TRUE;
}

BEGIN_MESSAGE_MAP(Creverse_toolDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, &Creverse_toolDlg::OnTcnSelchangeTab2)
END_MESSAGE_MAP()


// Creverse_toolDlg 消息处理程序


void Creverse_toolDlg::OnTcnSelchangeTab2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	m_dialog1.ShowWindow(false);
	m_dialog2.ShowWindow(false);
	m_dialog3.ShowWindow(false);
	int sel = m_tab.GetCurSel();
	switch (sel)
	{
	case 0:
		m_dialog1.ShowWindow(true);
		break;
	case 1:
		m_dialog2.ShowWindow(true);
		break;
	case 2:
		m_dialog3.ShowWindow(true);
		break;
	}
	*pResult = 0;
}