========================================================================
    APPLICATION : APM Project Overview
========================================================================

AppWizard has created this APM Application for you.  

This file contains a summary of what you will find in each of the files that
make up your APM application.

APM.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard. 
    It contains information about the version of Visual C++ that generated the file, and 
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

APM.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

APM.cpp
    This is the main application source file.
    Contains the code to display the form.

Form1.h
    Contains the implementation of your form class and InitializeComponent() function.

AssemblyInfo.cpp
    Contains custom attributes for modifying assembly metadata.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named APM.pch and a precompiled types file named StdAfx.obj.

//////////////////////////
///////////////////////////////////////////////////

สิ่งสำคัญต้องคำนึง
1.จะต้องมีไฟล์ amp.ini
2.ต้อง set environment  variables       
-$(Opencv245_build) path ที่เก็บ  .h ไฟล์ทั้งหมด = D:\joe\opencv2.4.5\build
-$(Opencv245_32_dir) path ที่เก็บ library 32 bit  = D:\joe\BuildOpencv\opencv245\NoCuda_NoTBB_32
-$(Opencv245_dir) path ที่เก็บ library 32 bit = D:\joe\BuildOpencv\opencv245\NoCuda_NoTBB_64
3.ไฟล์ dll ที่ต้องเรียกใช้ทั้งหมด


