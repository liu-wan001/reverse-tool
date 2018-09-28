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
}


BEGIN_MESSAGE_MAP(CDialog1, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CDialog1::OnEnChangeEditText1)
	ON_EN_CHANGE(IDC_EDIT2, &CDialog1::OnEnChangeEditText2)
	ON_EN_CHANGE(IDC_EDIT3, &CDialog1::OnEnChangeEditText3)
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
		WCHAR tmp[5] = { 0 };
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
