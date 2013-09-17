//#include <opencv2\opencv.hpp>
//#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <process.h> 
#include <fstream> // for fstream open file
#include <direct.h> //get current working directory _getcwd
//#include <Windows.h>

#include "workerThread.h"

//ใช้เหมือนกัน ทั้ง workerThread และ Option form
#define MAXSIZE 500
#define DEFAULT_STRING_SIZE 256

char g_INI_FName[]="\\\\apm.ini";

#pragma comment(lib, "User32.lib")

namespace APM {
using namespace std;
using namespace cv;
using namespace System;
using namespace System::Windows::Forms;
workerThread::workerThread(void)
{
	m_shouldStop = false;

	m_iCapEveryNSec =180;// time (second) to detect motion every X (second).ตรวจจับความเปลี่ยนแปลงทุก X s  1- max integer
	m_iThresDiff= 50; //ค่าสีต่างกัน (หน่วย) ถือว่าเป็นการเคลื่อนไหว   0-255
	m_iThresShutdownComputer= 300; //หากมีจำนวน pixel ที่มีการเคลื่อนไหวต่ำกว่าจะ shutdown  0-307200
	m_iThresBootComputer=1000; // 0-307200
	m_iNumberOfDelay= 100;// เวลาหน่วง (วินาที) ในการ start กล้อง webcam  0- max integer


	m_strIniFileName = NULL;
	m_strIniFileName = new char[MAXSIZE];
	//-------------------------------------------
	//read data from ini file
	char buf[DEFAULT_STRING_SIZE];
//	char strpath[DEFAULT_STRING_SIZE];
//	int retVal = 0;
//	unsigned short pathStrLen;//,iniStrLen;
	char* pstr;
	if( _getcwd(buf, DEFAULT_STRING_SIZE) )  //get current working directory
	{
			System::String^ strPath = gcnew System::String(buf);
			strPath = strPath->Replace("\\","\\\\");
					
			//pathStrLen = strPath->Length;
					
			//size_t sizeinBytes = (pathStrLen + 1)*2;

			//copy path string to buf again เนื่องจากว่า buf เดิม path '\\' มันเป็นแค่อันเดียวจะต้องเพิ่มอีกเท่าใน .net
			//new buf ก็จะเป็น string ที่มี "\\\\" ใน path
			pstr = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(strPath).ToPointer();
			strcpy(m_strIniFileName,pstr);
			Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)pstr);

			//StringToCharPointer(string, buf,sizeinBytes);
			//strcpy(m_strIniFileName,buf);
			
			//copy path of current directory to m_strIniFileName
			strcat((char*) m_strIniFileName,g_INI_FName);
			manipulateCPFeedINIFile(m_strIniFileName);
	}
}
workerThread::~workerThread()
{	
	WaitForSingleObject(m_hWorker, INFINITE);
	CloseHandle(m_hWorker);
}
//manipulate ini File
//------------------------------------------------------
//Name manipulateAPMINIFile
//Desc get dat from INI file
//     char* pFileName  name and path of ini file
//		 feed data
//------------------------------------------------------
void workerThread::manipulateCPFeedINIFile(char* pFileName)
{
		char* retBuffer;
		string strSection ("Parameter");
		//ควรตรวจสอบก่อนว่า มีไฟล์นี้อยู่หรือเปล่า
		//set feed type to list
		fstream file;
		file.open( pFileName, ios::in );
		if(file.fail())
		{
			file.close();
			MessageBox::Show("File " + gcnew System::String(pFileName) + " is not exist!!!");
			return ;
		}
		else
		{
			file.close();
			retBuffer = (char*)calloc(MAXSIZE,sizeof(char));
			char* pdest = NULL;
			char* psrc = NULL;

			//read Parameter section data
			m_iCapEveryNSec=::GetPrivateProfileIntA(strSection.c_str(),"CapEveryNSec",180,pFileName);
			if(m_iCapEveryNSec == 0)
				return;

			m_iThresDiff=::GetPrivateProfileIntA(strSection.c_str(),"ThresDiff",50,pFileName);
			if(m_iThresDiff == 0)
				return;


			m_iThresShutdownComputer=::GetPrivateProfileIntA(strSection.c_str(),"ThresShutdownComputer",50,pFileName);
			if(m_iThresShutdownComputer == 0)
				return;
			
			m_iThresBootComputer=::GetPrivateProfileIntA(strSection.c_str(),"ThresBootComputer",50,pFileName);
			if(m_iThresBootComputer == 0)
				return;
			
			m_iNumberOfDelay=::GetPrivateProfileIntA(strSection.c_str(),"NumberOfDelay",50,pFileName);
			if(m_iNumberOfDelay == 0)
				return;	

		}

}
//------------------------------------------------------
//Name updateParamFromINIFile
//Desc parameter modified need to read up-to-date parameter
//	   unsigned char*	pchkModifyParam  --check for parameter change 11111 = 63
//------------------------------------------------------
void workerThread::updateParamFromINIFile(unsigned char* pchkModifyParam)
{
		unsigned char idxBit;
		string strSection ("Parameter");

		idxBit = 1 & *pchkModifyParam;
		if(idxBit ==1)
		{
			m_iCapEveryNSec=::GetPrivateProfileIntA(strSection.c_str(),"CapEveryNSec",180,m_strIniFileName);
			if(m_iCapEveryNSec == 0)
				return;
		}
		idxBit = 2 & *pchkModifyParam;
		if(idxBit ==2)
		{
			m_iThresDiff=::GetPrivateProfileIntA(strSection.c_str(),"ThresDiff",50,m_strIniFileName);
			if(m_iThresDiff == 0)
				return;
		}
		idxBit = 4 & *pchkModifyParam;
		if(idxBit ==4)
		{
			m_iThresShutdownComputer=::GetPrivateProfileIntA(strSection.c_str(),"ThresShutdownComputer",50,m_strIniFileName);
			if(m_iThresShutdownComputer == 0)
				return;
		}
		idxBit = 8 & *pchkModifyParam;
		if(idxBit ==8)
		{
			m_iThresBootComputer=::GetPrivateProfileIntA(strSection.c_str(),"ThresBootComputer",50,m_strIniFileName);
			if(m_iThresBootComputer == 0)
				return;
		}
		idxBit = 16 & *pchkModifyParam;
		if(idxBit ==16)
		{
			m_iNumberOfDelay=::GetPrivateProfileIntA(strSection.c_str(),"NumberOfDelay",50,m_strIniFileName);
			if(m_iNumberOfDelay == 0)
				return;	
		}

		//read Parameter section data
			
		
			
			

}
void workerThread::RequestStop()
{
    m_shouldStop = true;
}
//-----------------------------------------------------------
//Name:
//Desc: run motion detection thread
//Usage:
//-----------------------------------------------------------
void workerThread::runMotionDetThread()
{
	m_hWorker = (HANDLE)_beginthreadex(NULL,0,ThreadFunc,(void*) this,0,&m_nThreadID);			// Thread address
}
cv::Scalar workerThread::iDiffImage(const cv::Mat &image1, const cv::Mat &image2)
{
	cv::Mat grayImage1,grayImage2,grayImageTmp;

	grayImage1 = cvmConvertToGray(image1);
	grayImage2 = cvmConvertToGray(image2);
	cv::absdiff(grayImage1, grayImage2, grayImageTmp);

	return cv::sum(grayImageTmp);
}

cv::Mat workerThread::cvmConvertToGray(const cv::Mat &inputImage)
{
	cv::Mat tmpImage;

	if(inputImage.channels() == 3)
	{
		cv::cvtColor(inputImage, tmpImage, CV_BGR2GRAY);
	}
	else if(inputImage.channels() == 4)
	{
		cv::cvtColor(inputImage, tmpImage, CV_BGRA2GRAY);
	}
	else
		tmpImage = inputImage;

	return tmpImage;
}

// Draw text into an image. Defaults to top-left-justified text, but you can give negative x coords for right-justified text,
// and/or negative y coords for bottom-justified text.
// Returns the bounding rect around the drawn text.
Rect workerThread::drawString(Mat img, string text, Point coord, Scalar color, float fontScale, int thickness, int fontFace)
{
	 fontScale = 0.6f;
	 thickness = 1;
	 fontFace = FONT_HERSHEY_COMPLEX;
    // Get the text size & baseline.
    int baseline=0;
    Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseline);
    baseline += thickness;

    // Adjust the coords for left/right-justified or top/bottom-justified.
    if (coord.y >= 0) {
        // Coordinates are for the top-left corner of the text from the top-left of the image, so move down by one row.
        coord.y += textSize.height;
    }
    else {
        // Coordinates are for the bottom-left corner of the text from the bottom-left of the image, so come up from the bottom.
        coord.y += img.rows - baseline + 1;
    }
    // Become right-justified if desired.
    if (coord.x < 0) {
        coord.x += img.cols - textSize.width + 1;
    }

    // Get the bounding box around the text.
    Rect boundingRect = Rect(coord.x, coord.y - textSize.height, textSize.width, baseline + textSize.height);

    // Draw anti-aliased text.
    putText(img, text, coord, fontFace, fontScale, color, thickness, CV_AA);

    // Let the user know how big their text is, in case they want to arrange things.
    return boundingRect;
}

cv::Mat workerThread::mCreateDiffMask(const cv::Mat &image1, const cv::Mat &image2, const int &iThreshold, int &iCountPixel)
{
	cv::Mat grayImage1,grayImage2,grayImageTmp;
	iCountPixel = 0;

	grayImage1 = cvmConvertToGray(image1);
	grayImage2 = cvmConvertToGray(image2);
	cv::absdiff(grayImage1, grayImage2, grayImageTmp);
	for(int r=0;r<grayImageTmp.rows;r++)
		for(int c=0;c<grayImageTmp.cols;c++)
			if(grayImageTmp.at<uchar>(r,c) < iThreshold)
				grayImageTmp.at<uchar>(r,c) = 0;
			else
				iCountPixel++;

	return grayImageTmp;
}

string workerThread::mstrPrintNowTime()
{
	time_t nowTime;
	struct tm *nowStruct;
	char strTimeBuf[22] = "";

	time(&nowTime);
	nowStruct = localtime(&nowTime);
	nowStruct->tm_year += 543;
	strftime(strTimeBuf,22,"[%d/%m/%Y %H:%M:%S]",nowStruct);
	
	return strTimeBuf;
}

//--------------------------------------------------------------
//Name: Motion Detection
// This method will be called when the thread is started.
// motion detection
//--------------------------------------------------------------
unsigned workerThread::ThreadFunc (LPVOID thisContext)   
{
	workerThread* pThis = reinterpret_cast<workerThread*>(thisContext);
	assert(pThis);
	//int    iThreshold = (int) thresh;

	const int cameraNumber = CV_CAP_ANY;
	const int iFPS = 1;
	const bool outputDOS = false;


	//int m_iCapEveryNSec = 180;
	//const int m_iThresDiff = 50;
	//const int m_iThresShutdownComputer = 300;
	//const int m_iThresBootComputer = 1000;
	//const int m_iNumberOfDelay = 100;
	
	// I time it that CAPTURE_EVERY_N_FRAME = 10 uses 1.9 second.
	// Thus sec*10/1.9 = number of CAPTURE_EVERY_N_FRAME.
	bool bComputerOnOff = true; // Computer is on now.
	int iCapEveryNFrame = (int)floor(pThis->m_iCapEveryNSec*10/1.9+0.5);
	int iCapEveryNFrameSave = iCapEveryNFrame; // Remember the value.
	
	cv::VideoCapture camera;

	camera.open(cameraNumber);
	if(!camera.isOpened())
	{
		cerr << "ERROR: Could not access the camera or video!" << std::endl;
		exit(1);
	}

	camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	camera.set(CV_CAP_PROP_FPS,iFPS);

	//cv::Mat currentImage, bgImage = cv::imread("person1.bmp");
	cv::Mat currentImage, bgImage, diffImage, displayImage;
	ostringstream cvtToString;
	std::vector<cv::Mat> imageLayers(3);

	int iNumberOfMovePixel = 0;
	int iFrameNumber = 0;

	camera >> currentImage;
	bgImage = currentImage.clone();
#ifdef _SHOWIMG_
	cv::flip(bgImage,bgImage,1);
#endif

	//Flush image if not when you call you will get old picture.
	for(int i=0;i<pThis->m_iNumberOfDelay;i++)
		camera >> currentImage;

	while(!pThis->m_shouldStop)
	{
		iNumberOfMovePixel = 0;
		
		camera >> currentImage;
#ifdef _SHOWIMG_
		cv::flip(currentImage,currentImage,1);
#endif
		diffImage = pThis->mCreateDiffMask(bgImage,currentImage,pThis->m_iThresDiff,iNumberOfMovePixel);
		imageLayers[0] = diffImage.clone();
		imageLayers[1] = diffImage.clone();
		imageLayers[2] = diffImage.clone();
		cv::merge(imageLayers,displayImage);
		cvtToString << "Moved pixels = " << iNumberOfMovePixel;

		if(iFrameNumber == iCapEveryNFrame && bComputerOnOff == true &&
			iNumberOfMovePixel < pThis->m_iThresShutdownComputer)
		{
			bComputerOnOff = false;
			if(outputDOS)
				cout << pThis->mstrPrintNowTime() << " shutdown" << endl;
			iCapEveryNFrame = 10;
			iFrameNumber = 0;
			//turn off monitor
			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
		}
		else if(bComputerOnOff == false && iNumberOfMovePixel > pThis->m_iThresBootComputer)
		{
			bComputerOnOff = true;
			if(outputDOS)
				cout << pThis->mstrPrintNowTime() << " Boot com" << endl;
			iCapEveryNFrame = iCapEveryNFrameSave;
			iFrameNumber = 0;
			//turn on monitor
			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);
		}else if(iFrameNumber == iCapEveryNFrame && bComputerOnOff == true)
		{
			iFrameNumber = 0;
			/*QueryPerformanceCounter(&nsStop);
			if(outputDOS)
			{
				nsDiff = (double)(nsStop.QuadPart - nsStart.QuadPart)/(double)(nsQuantum.QuadPart);
				cout << "Nano sec = " << nsDiff << " seconds" << endl;
			}
			nsStart = nsStop;*/
		}

#ifdef _SHOWIMG_
		if(outputDOS)
		{
			pThis->drawString(displayImage, cvtToString.str(), Point(10, 10), CV_RGB(0,255,0));
			cv::namedWindow("mainWindows");
			cv::imshow("mainWindows",displayImage);
			cv::waitKey(33);
			cvtToString.str("");
		}
#endif
		bgImage = currentImage.clone();
		iFrameNumber++;
	}
	//_endthreadex( 0 ); //_endthreadex, it causes its thread object to go to the signaled state. ส่งไปยัง main thread ที่รอ WaitForSingleObject
	return 0;
}

/*void workerThread::DoWork(Object^ data)
{
	// threshold for motion dectection
	int iThreshold = (int)data;

    int cameraNumber = CV_CAP_ANY;
	int iComputerOnOff = 1;
	int iFPS = 1;

	
	cv::VideoCapture camera;

	camera.open(cameraNumber);
	if(!camera.isOpened())
	{
		cerr << "ERROR: Could not access the camera or video!" << std::endl;
		exit(1);
	}

	camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	camera.set(CV_CAP_PROP_FPS,iFPS);

	//cv::Mat currentImage, bgImage = cv::imread("person1.bmp");
	cv::Mat currentImage, bgImage, diffImage, displayImage;
	ostringstream cvtToString;
	std::vector<cv::Mat> imageLayers(3);
	int iMovePixel = 0;
	int iFrameAt = 0;


	camera >> currentImage;
	bgImage = currentImage.clone();
	cv::flip(bgImage,bgImage,1);
	
	

	while(!m_shouldStop)
	{
		camera >> currentImage;
		cv::flip(currentImage,currentImage,1);
		iMovePixel = 0;
#ifdef _SHOWIMG_
		cv::imshow("c",currentImage);
		cv::waitKey(33);
		cv::imshow("b",bgImage);
		cv::waitKey(33);
#endif
		diffImage = mCreateDiffMask(bgImage,currentImage,iThreshold,iMovePixel);
		imageLayers[0] = diffImage.clone();
		imageLayers[1] = diffImage.clone();
		imageLayers[2] = diffImage.clone();
		cv::merge(imageLayers,displayImage);
		cvtToString << "Moved pixels = " << iMovePixel;
		if(iFrameAt == 5 && iComputerOnOff == 1 && iMovePixel < 10)
		{
			iComputerOnOff = 0;
			cout << "shutdown" << endl;
			iFrameAt = 0;
		}
		else if(iComputerOnOff == 0 && iMovePixel > 50)
		{
			iComputerOnOff = 1;
			cout << "Boot com" << endl;
			iFrameAt = 0;
		}else if(iFrameAt == 5 && iComputerOnOff == 1)
			iFrameAt = 0;

		drawString(displayImage, cvtToString.str(), Point(10, 10), CV_RGB(0,255,0));
		cv::namedWindow("mainWindows");
		cv::imshow("mainWindows",displayImage);
		cv::waitKey(33);
		cvtToString.str("");
		bgImage = currentImage.clone();
		iFrameAt++;
	}

	
	//worker thread: terminating gracefully
}*/

}