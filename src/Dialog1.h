#pragma once
#include "afxwin.h"

#define		TEXT_MAX_LENGTH		1024

// CDialog1 对话框

class CDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog1)

public:
	CDialog1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialog1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditText1();
	afx_msg void OnEnChangeEditText2();
	afx_msg void OnEnChangeEditText3();
	CEdit m_hEdit1;
	CEdit m_hEdit2;
	CEdit m_hEdit3;
};
