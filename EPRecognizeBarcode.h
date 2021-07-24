#pragma once

// CEPRecognizeBarcode command target

class CEPRecognizeBarcode : public CObject
{
public:
	virtual ~CEPRecognizeBarcode();

public:
	CEPRecognizeBarcode();
protected:
	void RecognizeVialBarcode();
//	void RecognizeBagBarcode();
	void RecognizeStickerBarcode();
//	void RecognizeApprovalStickerBarcode();
private:
	void	CreatePartOfImage(CEQRequestDataBarcode * pData);
	void	FindResult(CEPRecognizeBarcodeThread	* pipThread);
	void	ClearThreads(CEPRecognizeBarcodeThread	* pipThread);
	void	CreateTestBarcodeResponse();
	void	CreateTestStickerBarcodeResponse();
	HANDLE	m_hWorkEvent;
	CArrayBarcodeThreads m_arrayThreads;
	int		m_iStretchX; // Stretching X [percentage]
	int		m_iStretchY; // Stretching Y [percentage]
};

