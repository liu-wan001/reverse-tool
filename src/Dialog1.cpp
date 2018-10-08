// Dialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "reverse_tool.h"
#include "Dialog1.h"
#include "afxdialogex.h"


// CDialog1 对话框

IMPLEMENT_DYNAMIC(CDialog1, CDialogEx)

CDialog1::CDialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDialog1::~CDialog1()
{
}

void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_hEdit1);
	DDX_Control(pDX, IDC_EDIT2, m_hEdit2);
	DDX_Control(pDX, IDC_EDIT3, m_hEdit3);
	DDX_Control(pDX, IDC_EDIT4, m_hEdit4);
	DDX_Control(pDX, IDC_EDIT5, m_hEdit5);
	DDX_Control(pDX, IDC_EDIT6, m_hEdit6);
	DDX_Control(pDX, IDC_EDIT7, m_hEdit7);
	DDX_Control(pDX, IDC_EDIT8, m_hEdit8);
	DDX_Control(pDX, IDC_EDIT9, m_hEdit9);
	DDX_Control(pDX, IDC_EDIT10, m_hEdit10);
	DDX_Control(pDX, IDC_EDIT11, m_hEdit11);
	DDX_Control(pDX, IDC_EDIT12, m_hEdit12);
}


BEGIN_MESSAGE_MAP(CDialog1, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CDialog1::OnEnChangeEditText1)
	ON_EN_CHANGE(IDC_EDIT2, &CDialog1::OnEnChangeEditText2)
	ON_EN_CHANGE(IDC_EDIT3, &CDialog1::OnEnChangeEditText3)
	ON_EN_CHANGE(IDC_EDIT4, &CDialog1::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CDialog1::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT7, &CDialog1::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &CDialog1::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT10, &CDialog1::OnEnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT11, &CDialog1::OnEnChangeEdit10)
END_MESSAGE_MAP()


// CDialog1 消息处理程序
//TODO:大数运算
void CDialog1::OnEnChangeEditText1()
{
	int CtrlID = GetFocus()->GetDlgCtrlID();
	if (CtrlID != IDC_EDIT1)
		return;
	CString HexText;
	CString DecText;
	WCHAR text[TEXT_MAX_LENGTH];
	::GetWindowText(m_hEdit1, text, TEXT_MAX_LENGTH);
	int i = 0;
	while (text[i])
	{
		WCHAR tmp[20] = { 0 };
		wsprintf(tmp, L"%X ", text[i]);
		HexText += tmp;
		wsprintf(tmp, L"%d ", text[i]);
		DecText += tmp;
		i++;
	}
	::SetWindowText(m_hEdit2, DecText);
	::SetWindowText(m_hEdit3, HexText);
}

void CDialog1::OnEnChangeEditText2()
{
	int CtrlID = GetFocus()->GetDlgCtrlID();
	if (CtrlID != IDC_EDIT2)
		return;
	bool flag = false;
	CString HexText;
	CString StrText;
	WCHAR text[TEXT_MAX_LENGTH];
	LONGLONG num;
	CString Ctmp;
	WCHAR tmp[32] = { 0 };
	::GetWindowText(m_hEdit2, text, TEXT_MAX_LENGTH);
	int i = 0;
	while (text[i])
	{
		if (text[i] == ' ')
		{
			flag = true;
		}
		i++;
	}
	i = 0;

	if (flag == true)
	{
		while (text[i])
		{
			if (text[i] == ' ')
			{
			_format:
				num = _wtoll(Ctmp.GetBuffer(0));
				StrText += (WCHAR)num;
				wsprintf(tmp, L"%lX ", num);
				HexText += tmp;
				Ctmp.Empty();
			}
			else if(text[i + 1] == 0)
			{
				Ctmp += text[i];
				goto _format;
			}
			else
			{
				Ctmp += text[i];
			}
			i++;
		}
	}
	else
	{
		num = _wtoll(text);
		wsprintf(tmp, L"%lX", num);
		HexText += tmp;
		StrText += (WCHAR)num;
	}
	::SetWindowText(m_hEdit1, StrText);
	::SetWindowText(m_hEdit3, HexText);
}

void CDialog1::OnEnChangeEditText3()
{
	int CtrlID = GetFocus()->GetDlgCtrlID();
	if (CtrlID != IDC_EDIT3)
		return;
	LONGLONG num;
	bool flag = false;
	CString DecText;
	CString StrText;
	WCHAR text[TEXT_MAX_LENGTH];
	CString Ctmp;
	WCHAR tmp[32] = { 0 };
	::GetWindowText(m_hEdit3, text, TEXT_MAX_LENGTH);
	int i = 0;
	while (text[i])
	{
		if (text[i] == ' ')
		{
			flag = true;
		}
		i++;
	}
	i = 0;

	if (flag == true)
	{
		while (text[i])
		{
			if (text[i] == ' ')
			{
			_format:
				swscanf(Ctmp.GetBuffer(0), L"%llx", &num);
				StrText += (WCHAR)num;
				wsprintf(tmp, L"%lu ", num);
				DecText += tmp;
				Ctmp.Empty();
			}
			else if (text[i + 1] == 0)
			{
				Ctmp += text[i];
				goto _format;
			}
			else
			{
				Ctmp += text[i];
			}
			i++;
		}
	}
	else
	{
		swscanf(text, L"%llx", &num);
		wsprintf(tmp, L"%lu", num);
		DecText += tmp;
		StrText += (WCHAR)num;
	}
	::SetWindowText(m_hEdit1, StrText);
	::SetWindowText(m_hEdit2, DecText);
}


void CDialog1::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	WCHAR text1[TEXT_MAX_LENGTH];
	WCHAR text2[TEXT_MAX_LENGTH];
	WCHAR DecText[TEXT_MAX_LENGTH];
	::GetWindowText(m_hEdit4, text1, TEXT_MAX_LENGTH);
	::GetWindowText(m_hEdit5, text2, TEXT_MAX_LENGTH);
	if (wcslen(text1) == 0 || wcslen(text2) == 0)
		return;
	LONGLONG num1 = 0, num2 = 0;
	swscanf(text1, L"%llx", &num1);
	swscanf(text2, L"%llx", &num2);
	wsprintf(DecText, L"%lX", num1 ^ num2);
	::SetWindowText(m_hEdit6, DecText);
}



void CDialog1::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	WCHAR text1[TEXT_MAX_LENGTH];
	WCHAR text2[TEXT_MAX_LENGTH];
	WCHAR DecText[TEXT_MAX_LENGTH];
	::GetWindowText(m_hEdit7, text1, TEXT_MAX_LENGTH);
	::GetWindowText(m_hEdit8, text2, TEXT_MAX_LENGTH);
	if (wcslen(text1) == 0 || wcslen(text2) == 0)
		return;
	LONGLONG num1 = 0, num2 = 0;
	swscanf(text1, L"%llx", &num1);
	swscanf(text2, L"%llx", &num2);
	wsprintf(DecText, L"%lx", num1 | num2);
	::SetWindowText(m_hEdit9, DecText);
}


void CDialog1::OnEnChangeEdit10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	WCHAR text1[TEXT_MAX_LENGTH];
	WCHAR text2[TEXT_MAX_LENGTH];
	WCHAR DecText[TEXT_MAX_LENGTH];
	::GetWindowText(m_hEdit10, text1, TEXT_MAX_LENGTH);
	::GetWindowText(m_hEdit11, text2, TEXT_MAX_LENGTH);
	if (wcslen(text1) == 0 || wcslen(text2) == 0)
		return;
	LONGLONG num1=0, num2=0;
	swscanf(text1, L"%llx", &num1);
	swscanf(text2, L"%llx", &num2);
	wsprintf(DecText, L"%lx", num1 & num2);
	::SetWindowText(m_hEdit12, DecText);
}
