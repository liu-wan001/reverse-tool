#pragma once
#include "afxcmn.h"
#include "Dialog1.h"
#include "Dialog2.h"
#include "Dialog3.h"

// Creverse_toolDlg 对话框

class Creverse_toolDlg : public CDialogEx
{
	DECLARE_DYNAMIC(Creverse_toolDlg)

public:
	Creverse_toolDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Creverse_toolDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CDialog1 m_dialog1;
	CDialog2 m_dialog2;
	CDialog3 m_dialog3;
	afx_msg void OnTcnSelchangeTab2(NMHDR *pNMHDR, LRESULT *pResult);
};
