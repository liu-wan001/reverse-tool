// Dialog3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reverse_tool.h"
#include "Dialog3.h"
#include "afxdialogex.h"
#include "cJSON.h"


// CDialog3 �Ի���

IMPLEMENT_DYNAMIC(CDialog3, CDialogEx)

CDialog3::CDialog3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CDialog3::~CDialog3()
{
}

void CDialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_hEdit);
}


BEGIN_MESSAGE_MAP(CDialog3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialog3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialog3::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialog3 ��Ϣ�������


void CDialog3::OnBnClickedButton1()
{
	// TODO: ��ʽ��json
	WCHAR w_json[10240] = { 0 };
	::GetWindowText(m_hEdit, w_json, 10240);
	USES_CONVERSION;
	char *a_json = W2A(w_json);
	cJSON *j_obj = cJSON_Parse(a_json);
	char *format_json = cJSON_Print(j_obj);
	//ֻ��\nû��\r\n ���Բ��ỻ�� ��Ҫ�滻����
	CString str(format_json);
	str.Replace(L"\n", L"\r\n");
	::SetWindowText(m_hEdit, str.GetBuffer());
	free(format_json);
	cJSON_Delete(j_obj);
}


void CDialog3::OnBnClickedButton2()
{
	// TODO: ɾ����ʽjson
	WCHAR w_json[10240] = { 0 };
	::GetWindowText(m_hEdit, w_json, 10240);
	USES_CONVERSION;
	char *a_json = W2A(w_json);
	cJSON *j_obj = cJSON_Parse(a_json);
	char *unformat_json = cJSON_PrintUnformatted(j_obj);
	::SetWindowTextA(m_hEdit, unformat_json);
	free(unformat_json);
	cJSON_Delete(j_obj);
}
