#pragma once

//#include <opencv2\opencv.hpp>
#include <opencv2\core\core.hpp>

#include <Windows.h>


namespace APM {

//using namespace System;
using namespace cv;
class workerThread
{
	public:
		workerThread(void);
		~workerThread();
		//void DoWork(Object^ data);
		static unsigned __stdcall ThreadFunc (LPVOID thisContext);
		void RequestStop();
		void runMotionDetThread();
		void updateParamFromINIFile(unsigned char* pchkModifyParam); 
	private:
		Rect drawString(Mat img, string text, cv::Point coord, Scalar color, float fontScale = 0.6f, int thickness = 1, int fontFace = FONT_HERSHEY_COMPLEX);
		cv::Mat mCreateDiffMask(const cv::Mat &image1, const cv::Mat &image2, const int &iThreshold, int &iCountPixel);
		cv::Mat cvmConvertToGray(const cv::Mat &inputImage);
		cv::Scalar iDiffImage(const cv::Mat &image1, const cv::Mat &image2);
		void manipulateCPFeedINIFile(char* pFileName);
		
		string mstrPrintNowTime();
	// Volatile is used as hint to the compiler that this data
	// member will be accessed by multiple threads.
	private: bool m_shouldStop; //volatile  bool
			 UINT  m_nThreadID;
			HANDLE m_hWorker;

			//variable for user to change
			int m_iCapEveryNSec; //180 time (second) to detect motion every X (second).ตรวจจับความเปลี่ยนแปลงทุก X s  1- max integer
			int m_iThresDiff; //50 ค่าสีต่างกัน (หน่วย) ถือว่าเป็นการเคลื่อนไหว   0-255
			int m_iThresShutdownComputer; //300 หากมีจำนวน pixel ที่มีการเคลื่อนไหวต่ำกว่าจะ shutdown  0-307200
			int m_iThresBootComputer; //1000  0-307200
			int m_iNumberOfDelay;// 100  เวลาหน่วง (วินาที) ในการ start กล้อง webcam  0- max integer
			
	public: char* m_strIniFileName;
};
}




