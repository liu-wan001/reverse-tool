#pragma once
#include "afxwin.h"

#define		TEXT_MAX_LENGTH		1024

// CDialog1 �Ի���

class CDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog1)

public:
	CDialog1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialog1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditText1();
	afx_msg void OnEnChangeEditText2();
	afx_msg void OnEnChangeEditText3();
	CEdit m_hEdit1;
	CEdit m_hEdit2;
	CEdit m_hEdit3;
};