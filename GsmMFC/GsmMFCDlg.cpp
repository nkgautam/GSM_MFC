
// GsmMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GsmMFC.h"
#include "GsmMFCDlg.h"
#include "Serial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGsmMFCDlg dialog




CGsmMFCDlg::CGsmMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGsmMFCDlg::IDD, pParent)
	, mComPortValue(_T("COM15"))
	, m_AtCmdValue(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGsmMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITCOM, mComPort);
	DDX_Text(pDX, IDC_EDITCOM, mComPortValue);
	DDX_Text(pDX, IDC_EDITAT, m_AtCmdValue);
}

BEGIN_MESSAGE_MAP(CGsmMFCDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	
	ON_BN_CLICKED(IDC_BUTTONOpen, &CGsmMFCDlg::OnBnClickedButtonopen)
	ON_BN_CLICKED(IDC_BUTTONSend, &CGsmMFCDlg::OnBnClickedButtonsend)
	ON_WM_SERIAL(OnSerialMsg)
END_MESSAGE_MAP()

// CGsmMFCDlg message handlers

BOOL CGsmMFCDlg::OnInitDialog()
{
	//CTime t1 = CTime::CTime(2015,05,04);
	CTime t = CTime::GetCurrentTime();
	//CTime t0 = CTime::CTime(t.GetYear(),t.GetMonth(),t.GetDay());
	//
	if(t.GetYear()==2015)
	{
		if(t.GetMonth()==05)
		{
			if(t.GetDay() > 06)
			{
				MessageBox(L"Demo software expire... ");
				exit(0);
			}
		}
		
	}
	
		
    //CString strDate = t.Format("%m%d%Y");

	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	
	ShowWindow(SW_NORMAL);
	// TODO: Add extra initialization here
	m_pSerial = new	CSerial();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGsmMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGsmMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGsmMFCDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	//HANDLE hFile = ::CreateFile("\\\\.\\COM15", 
	//					   GENERIC_READ|GENERIC_WRITE, 
	//					   0, 
	//					   0, 
	//					   OPEN_EXISTING, 
	//					   0,
	//					   0);

	//
	//if (hFile == INVALID_HANDLE_VALUE)
	//{
	//	int lasterror= ::GetLastError();
	//	return;
	//	
	//}

	//if (!::SetupComm(hFile,16,16))
	//{
	//	int lasterror=::GetLastError();
	//	return;
	//	//// Display a warning
	//	//long lLastError = ::GetLastError();
	//	//_RPTF0(_CRT_WARN,"CSerial::Open - Unable to setup the COM-port\n");

	//	//// Close the port
	//	//Close();

	//	//// Save last error from SetupComm
	//	//m_lLastError = lLastError;
	//	//return m_lLastError;	
	//}

	//CDCB dcb;
	//if (!::GetCommState(hFile,&dcb))
	//{
	//	// Obtain the error code
	//	int lasterror= ::	GetLastError();
	//	return;
	//	// Display a warning
	//	/*_RPTF0(_CRT_WARN,"CSerial::Setup - Unable to obtain DCB information\n");
	//	return m_lLastError;*/
	//}

	//dcb.BaudRate = 115200;
	//dcb.ByteSize = 8;
	//dcb.Parity   = 0;
	//dcb.StopBits = 1;

	//if (!::SetCommState(hFile,&dcb))
	//{
	//	// Obtain the error code
	//	int lasterror= ::	GetLastError();
	//	return;

	//	// Display a warning
	//	/*_RPTF0(_CRT_WARN,"CSerial::Setup - Unable to set DCB information\n");
	//	return m_lLastError;*/
	//}

	//COMMTIMEOUTS cto;
	//if (!::GetCommTimeouts(hFile,&cto))
	//{
	//	// Obtain the error code
	//	int lasterror= ::	GetLastError();
	//	return;

	//	// Display a warning
	//	/*_RPTF0(_CRT_WARN,"CSerial::SetupReadTimeouts - Unable to obtain timeout information\n");
	//	return m_lLastError;*/
	//}

	//cto.ReadIntervalTimeout = 0;
	//cto.ReadTotalTimeoutConstant = 0;
	//cto.ReadTotalTimeoutMultiplier = 0;

	//if (!::SetCommTimeouts(hFile,&cto))
	//{
	//	// Obtain the error code
	//	int lasterror= ::	GetLastError();
	//	return;

	//	// Display a warning
	//	/*_RPTF0(_CRT_WARN,"CSerial::SetupReadTimeouts - Unable to set timeout information\n");
	//	return m_lLastError;*/
	//}
	// DWORD numberOfBytesWritten;
	//if (!::WriteFile(hFile,"ATE \r", 6,&numberOfBytesWritten,NULL))
	//{
	//	// Set the internal error code
	//	int lasterror= ::	GetLastError();
	//	if (lasterror != ERROR_IO_PENDING)
	//		return;
	//}
	//::Sleep(5000);
	//LPBYTE lpBuffer = new BYTE[8];
	//DWORD numberOfBytesRead;
	//if (!::ReadFile(hFile,lpBuffer,8,&numberOfBytesRead,NULL))
	//{
	//	int lasterror= ::	GetLastError();
	//	if (lasterror != ERROR_IO_PENDING)
	//		return;
	//}
	//::Sleep(1000);
	//LPBYTE lpBuffer1 = new BYTE[8];
	//DWORD numberOfBytesRead1;
	//if (!::ReadFile(hFile,lpBuffer1,8,&numberOfBytesRead1,NULL))
	//{
	//	int lasterror= ::	GetLastError();
	//	if (lasterror != ERROR_IO_PENDING)
	//		return;
	//}


	
}

void CGsmMFCDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CGsmMFCDlg::OnBnClickedButtonopen()
{
	UpdateData(TRUE);
	//
	if(CSerial::CheckPort(mComPortValue) == CSerial::EPortAvailable)
	{
		MessageBox(L"COM port not Available");
		return;
	}
	else
	{
		CString comPort;
		comPort.Format(_T("\\\\.\\%s"),mComPortValue);
		if(m_serialMFC.Open(comPort,this))
		{
			MessageBox(L"COM Open Error");
			return;

		}

		if(m_serialMFC.Setup(CSerial::EBaud115200))
			int i =0;
		else
			int k= 1;

		//m_AtCmdValue = L"ATI3 ";
		//SetDlgItemText(IDC_EDITAT,m_AtCmdValue);
		GetDlgItem(IDC_BUTTONSend)->EnableWindow(true);
		GetDlgItem(IDC_BUTTONOpen)->EnableWindow(false);
		GetDlgItem(IDC_EDITCOM)->EnableWindow(false);
		//UpdateData(TRUE);
	}
	OnBnClickedButtonsend();
}
char* ConvertToChar(const CString &s)
{
 int nSize = s.GetLength();
 char *pAnsiString = new char[nSize+1];
 memset(pAnsiString,0,nSize+1);
 wcstombs(pAnsiString, s, nSize+1);
 return pAnsiString;
}
void CGsmMFCDlg::OnBnClickedButtonsend()
{
	/*char command[]="ATI3 \r";
	m_serialMFC.Write(command,sizeof(command));*/
	char* ch = ConvertToChar(m_AtCmdValue);
	strcat(ch," \r");
	m_serialMFC.Write(ch,m_AtCmdValue.GetLength()+3);
	// TODO: Add your control notification handler code here
}

LRESULT CGsmMFCDlg::OnSerialMsg (WPARAM wParam, LPARAM /*lParam*/)
{
	CSerial::EEvent eEvent = CSerial::EEvent(LOWORD(wParam));
	CSerial::EError eError = CSerial::EError(HIWORD(wParam));


	if (eEvent & CSerial::EEventRecv)
	{
		// Create a clean buffer
		DWORD dwRead;
		char szData[101];
		const int nBuflen = sizeof(szData)-1;

		// Obtain the data from the serial port
		do
		{
			m_serialMFC.Read(szData,nBuflen,&dwRead);
			szData[dwRead] = '\0';

			// Scan the string for unwanted characters
			for (DWORD dwChar=0; dwChar<dwRead; dwChar++)
			{
				if (!isprint(szData[dwChar]) && !isspace(szData[dwChar]))
				{
					szData[dwChar] = '.';
				}
			}

#ifdef _UNICODE
			// Convert the ANSI data to Unicode
			LPTSTR lpszData = LPTSTR(_alloca((dwRead+1)*sizeof(TCHAR)));
			if (!::MultiByteToWideChar(CP_ACP, 0, szData, -1, lpszData, dwRead+1))
				return 0;

			// Display the fetched string
			MessageBox(lpszData);
#else
			// Display the fetched string
			DisplayData(szData);
#endif
		} while (dwRead == nBuflen);
		//MessageBox(szData);
	}

	return 0;
}