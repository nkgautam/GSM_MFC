
// GsmMFCDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Serial.h"
#include "SerialMFC.h"
// CGsmMFCDlg dialog
class CGsmMFCDlg : public CDialog
{
// Construction
public:
	CGsmMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GSMMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CSerial* m_pSerial;
	CSerialMFC		m_serialMFC;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnSerialMsg (WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtonopen();
	afx_msg void OnBnClickedButtonsend();
	
	CEdit mComPort;
	CString mComPortValue;
	CString m_AtCmdValue;
};

class CDCB : public DCB
	{
	public:
		CDCB() { DCBlength = sizeof(DCB); }
	};
