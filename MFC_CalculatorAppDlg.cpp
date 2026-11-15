
// MFC_CalculatorAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFC_CalculatorApp.h"
#include "MFC_CalculatorAppDlg.h"
#include "afxdialogex.h"
#include "stdlib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCalculatorAppDlg dialog



CMFCCalculatorAppDlg::CMFCCalculatorAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CALCULATORAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DISPLAY, m_editDisplay);
}

BEGIN_MESSAGE_MAP(CMFCCalculatorAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CMFCCalculatorAppDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CMFCCalculatorAppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMFCCalculatorAppDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMFCCalculatorAppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMFCCalculatorAppDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMFCCalculatorAppDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMFCCalculatorAppDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMFCCalculatorAppDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMFCCalculatorAppDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMFCCalculatorAppDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCCalculatorAppDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUBTRACT, &CMFCCalculatorAppDlg::OnBnClickedButtonSubtract)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CMFCCalculatorAppDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CMFCCalculatorAppDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL, &CMFCCalculatorAppDlg::OnBnClickedButtonDecimal)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMFCCalculatorAppDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CMFCCalculatorAppDlg::OnBnClickedButtonEqual)
END_MESSAGE_MAP()

int CMFCCalculatorAppDlg::dotcount = 0;
// CMFCCalculatorAppDlg message handlers

BOOL CMFCCalculatorAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCCalculatorAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCCalculatorAppDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}


double CMFCCalculatorAppDlg::ApplyOperation(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case 'x': return a * b;
	case '/':
		if (b == 0.0) throw std::runtime_error("Division by zero");
		return a / b;
	default: throw std::runtime_error("Unknown operator");
	}
}

int CMFCCalculatorAppDlg::GetPrecedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == 'x' || op == '/') return 2;
	return 0;
}

double CMFCCalculatorAppDlg::EvaluateExpression(const std::string& expression, bool& success) {
	success = true;

	std::stack<double> values;  // Stack to store numbers
	std::stack<char> ops;       // Stack to store operators

	for (size_t i = 0; i < expression.length(); i++) {
		// Skip whitespace
		if (isspace(static_cast<unsigned char>(expression[i]))) continue;

		// If current character is a number, push it to the 'values' stack
		if (isdigit(static_cast<unsigned char>(expression[i])) || expression[i] == '.') {
			std::stringstream ss;
			while (i < expression.length() && (isdigit(static_cast<unsigned char>(expression[i])) || expression[i] == '.')) {
				ss << expression[i++];
			}
			double value = 0.0;
			ss >> value;
			values.push(value);
			i--; // Since we increment `i` in the loop, we need to decrement it.
		}
		// If current character is an operator
		else if (expression[i] == '+' || expression[i] == '-' ||
			expression[i] == 'x' || expression[i] == '*' || expression[i] == '/') {
			char currOp = (expression[i] == '*') ? 'x' : expression[i];
			// While top of 'ops' has the same or greater precedence to current operator, apply the operator
			while (!ops.empty() && GetPrecedence(ops.top()) >= GetPrecedence(currOp)) {
				if (values.size() < 2) {
					success = false;
					throw std::runtime_error("Malformed expression");
				}
				double val2 = values.top(); values.pop();
				double val1 = values.top(); values.pop();
				char op = ops.top(); ops.pop();

				values.push(ApplyOperation(val1, val2, op));
			}
			// Push current operator to 'ops'
			ops.push(currOp);
		}
		// Handle parentheses
		else if (expression[i] == '(') {
			ops.push('(');
		}
		else if (expression[i] == ')') {
			while (!ops.empty() && ops.top() != '(') {
				if (values.size() < 2) {
					success = false;
					throw std::runtime_error("Malformed expression");
				}
				double val2 = values.top(); values.pop();
				double val1 = values.top(); values.pop();
				char op = ops.top(); ops.pop();

				values.push(ApplyOperation(val1, val2, op));
			}
			if (!ops.empty()) {
				ops.pop(); // Remove '(' from stack
			}
			else {
				success = false;
				throw std::runtime_error("Mismatched parentheses");
			}
		}
		else {
			success = false;
			throw std::runtime_error("Invalid character in expression");
		}
	}

	// Apply remaining operators to remaining values
	while (!ops.empty()) {
		if (ops.top() == '(' || ops.top() == ')') {
			success = false;
			throw std::runtime_error("Mismatched parentheses");
		}
		if (values.size() < 2) {
			success = false;
			throw std::runtime_error("Malformed expression");
		}
		double val2 = values.top(); values.pop();
		double val1 = values.top(); values.pop();
		char op = ops.top(); ops.pop();

		values.push(ApplyOperation(val1, val2, op));
	}

	// The top of 'values' stack contains the result
	if (values.size() !=1) {
		success = false;
		throw std::runtime_error("Malformed expression");
	}

	return values.top();
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCCalculatorAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCCalculatorAppDlg::AppendToDisplay(const CString& str)
{
	CString text;
	m_editDisplay.GetWindowText(text);
	text += str;
	m_editDisplay.SetWindowText(text);
}

void CMFCCalculatorAppDlg::OnBnClickedButtonEqual()
{
	CString expression;
	m_editDisplay.GetWindowText(expression);

	if (expression.IsEmpty())
	{
		return;
	}

	// Convert CString to std::string for evaluation
	CT2CA pszConvertedAnsiString(expression);
	std::string strExpr(pszConvertedAnsiString);

	try
	{
		bool success = false;
		double result = EvaluateExpression(strExpr, success);

		if (success)
		{
			// Convert result back to CString and display it
			CString resultStr;
			resultStr.Format(_T("%g"), result);
			m_editDisplay.SetWindowText(resultStr);
			dotcount = 0;  // Reset decimal counter for new number
		}
		else
		{
			m_editDisplay.SetWindowText(_T("Error"));
		}
	}
	catch (const std::exception& ex)
	{
		CString errorMsg(ex.what());
		m_editDisplay.SetWindowText(errorMsg);
	}
	catch (...)
	{
		m_editDisplay.SetWindowText(_T("Error"));
	}
}

void CMFCCalculatorAppDlg::OnBnClickedButton0()
{
	AppendToDisplay(_T("0"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton1()
{
	AppendToDisplay(_T("1"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton2()
{
	AppendToDisplay(_T("2"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton3()
{
	AppendToDisplay(_T("3"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton4()
{
	AppendToDisplay(_T("4"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton5()
{
	AppendToDisplay(_T("5"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton6()
{
	AppendToDisplay(_T("6"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton7()
{
	AppendToDisplay(_T("7"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton8()
{
	AppendToDisplay(_T("8"));
}

void CMFCCalculatorAppDlg::OnBnClickedButton9()
{
	AppendToDisplay(_T("9"));
}

void CMFCCalculatorAppDlg::OnBnClickedButtonAdd()
{
	AppendToDisplay(_T("+"));
	dotcount = 0;  // Reset decimal counter for new number

}

void CMFCCalculatorAppDlg::OnBnClickedButtonSubtract()
{
	AppendToDisplay(_T("-"));
	dotcount = 0;  // Reset decimal counter for new number
}

void CMFCCalculatorAppDlg::OnBnClickedButtonMultiply()
{
	AppendToDisplay(_T("x"));
	dotcount = 0;  // Reset decimal counter for new number
}

void CMFCCalculatorAppDlg::OnBnClickedButtonDivide()
{
	AppendToDisplay(_T("/"));
	dotcount = 0;  // Reset decimal counter for new number
}

void CMFCCalculatorAppDlg::OnBnClickedButtonDecimal()
{
	if (dotcount == 0)
	{
		AppendToDisplay(_T("."));
		dotcount++;
	}
}

void CMFCCalculatorAppDlg::OnBnClickedButtonClear()
{
	m_editDisplay.SetWindowText(_T(""));
	dotcount = 0;  // Reset decimal counter for new number
}
