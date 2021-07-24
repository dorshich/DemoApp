// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__9E3647E0_2CDC_4912_BC21_5F0EAC73BFED__INCLUDED_)
#define AFX_CHILDVIEW_H__9E3647E0_2CDC_4912_BC21_5F0EAC73BFED__INCLUDED_

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CChildView window
class CChildView : public CWnd
{
public:
	CChildView();

public:
	void showBuffer( const _DSHOWLIB_NAMESPACE::tFrameQueueBufferPtr& pBuffer );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	_DSHOWLIB_NAMESPACE::tFrameQueueBufferPtr m_pBuffer;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__9E3647E0_2CDC_4912_BC21_5F0EAC73BFED__INCLUDED_)
