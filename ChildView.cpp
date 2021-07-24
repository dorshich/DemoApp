// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "DemoApp.h"
#include "ChildView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
}

//////////////////////////////////////////////////////////////////////////
/*!
*/
CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers:

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::showBuffer( const _DSHOWLIB_NAMESPACE::tFrameQueueBufferPtr& pBuffer )
{
	m_pBuffer = pBuffer;
}

//////////////////////////////////////////////////////////////////////////
/*! If the live mode of the Grabber has been stopped, the last captured
    frame is displayed in this window.
*/
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // Create a device context for painting.
	
	if( m_pBuffer != NULL )
	{
		smart_ptr<BITMAPINFOHEADER> pInf = createBitmapInfoHeader( m_pBuffer->getFrameType() );
		
		int nLines = SetDIBitsToDevice( 
			dc.GetSafeHdc(),					// Handle to the device
			0, 
			0, 
			pInf->biWidth,	// Source rectangle width
			pInf->biHeight, // Source rectangle height
			0,				// X-coordinate of lower-left corner of the source rect
			0,				// Y-coordinate of lower-left corner of the source rect
			0,				// First scan line in array
			pInf->biHeight, // Number of scan lines
			m_pBuffer->getPtr(),	// Modified address of array with DIB bits
			reinterpret_cast<LPBITMAPINFO>( &*pInf ),	// Address of structure with bitmap info
			DIB_RGB_COLORS	// RGB or palette indices
			);

		if( nLines == GDI_ERROR )
		{
			AfxMessageBox(L"GDI_ERROR");
		}
	}	
	
	// Do not call CWnd::OnPaint() for painting messages
}

