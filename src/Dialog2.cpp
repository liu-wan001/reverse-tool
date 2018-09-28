// Dialog2.cpp : 实现文件
//

#include "stdafx.h"
#include "reverse_tool.h"
#include "Dialog2.h"
#include "afxdialogex.h"


// CDialog2 对话框

IMPLEMENT_DYNAMIC(CDialog2, CDialogEx)

CDialog2::CDialog2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CDialog2::~CDialog2()
{
}

void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog2, CDialogEx)
END_MESSAGE_MAP()


// CDialog2 消息处理程序
