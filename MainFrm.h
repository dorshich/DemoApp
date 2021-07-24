// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__014CF740_70E2_4EEF_9355_917E1DE14EE0__INCLUDED_)
#define AFX_MAINFRM_H__014CF740_70E2_4EEF_9355_917E1DE14EE0__INCLUDED_

#pragma once

#include "ChildView.h"

#include <tisudshl.h>

namespace DSNS = _DSHOWLIB_NAMESPACE;

class CMainFrame : public CFrameWnd
{

public:
    CMainFrame();
protected:
    DECLARE_DYNAMIC( CMainFrame )

    // Attributes
public:

    // Operations
public:

    // Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CMainFrame)
    virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
    virtual BOOL OnCmdMsg( UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo );
    //}}AFX_VIRTUAL

// Implementation
public:
    void	LoadPreviouslyUsedDevice();
    void	resizeToVideoFormat();
    void	updateWindowTitle();
protected:  // control bar embedded members
    CToolBar    m_wndToolBar;
    CChildView    m_wndView;

    // Generated message map functions
protected:
    //{{AFX_MSG(CMainFrame)
    afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
    afx_msg void OnSetFocus( CWnd *pOldWnd );
    afx_msg void OnSettingsDevice();
    afx_msg void OnSettingsImage();
    afx_msg void OnPreviewStart();
    afx_msg void OnPreviewStop();
    afx_msg void OnFileSaveimage();
    afx_msg void OnFileWriteavi();
    afx_msg void OnUpdatePreviewStart( CCmdUI* pCmdUI );
    afx_msg void OnUpdatePreviewStop( CCmdUI* pCmdUI );
    afx_msg void OnUpdateSettingsImage( CCmdUI* pCmdUI );
    afx_msg void OnUpdateFileSaveimage( CCmdUI* pCmdUI );
    afx_msg void OnUpdateFileWriteavi( CCmdUI* pCmdUI );
    afx_msg void OnUpdateSettingsDevice( CCmdUI* pCmdUI );
    afx_msg void OnClose();
    afx_msg void OnAppExit();
    afx_msg void OnButtontriggertoggle();
    afx_msg void OnUpdateButtontriggertoggle( CCmdUI* pCmdUI );
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

protected:
    DSNS::Grabber							m_Grabber;
    DSNS::tFrameSnapSinkPtr                 m_pSink;

    DSNS::tFrameQueueBufferPtr              m_pLastSnappedBuffer;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__014CF740_70E2_4EEF_9355_917E1DE14EE0__INCLUDED_)
