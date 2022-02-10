# Microsoft Developer Studio Project File - Name="VisioApp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=VisioApp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VisioApp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VisioApp.mak" CFG="VisioApp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "VisioApp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "VisioApp - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "VisioApp - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"..\Bin/VisioApp.exe"

!ELSEIF  "$(CFG)" == "VisioApp - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"..\Bin/VisioAppD.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "VisioApp - Win32 Release"
# Name "VisioApp - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\DirDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtListBar.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtTabModel.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtTabModelManager.cpp
# End Source File
# Begin Source File

SOURCE=.\FOHyperLink.cpp
# End Source File
# Begin Source File

SOURCE=..\ExtSource\FOPGDIPlusHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\ExtSource\FOPGDIPlusProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\GWExtBmpListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\LinePropDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MBEventEditDlg6.cpp
# End Source File
# Begin Source File

SOURCE=.\MyCorsssLineShape.cpp
# End Source File
# Begin Source File

SOURCE=.\MyCustomProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\MyToolBoxBar.cpp
# End Source File
# Begin Source File

SOURCE=.\MyToolBoxWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\NewOpenPageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewVisualProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\OutputDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StdioFileEx.cpp
# End Source File
# Begin Source File

SOURCE=.\VisioApp.cpp
# End Source File
# Begin Source File

SOURCE=.\VisioApp.rc
# End Source File
# Begin Source File

SOURCE=.\VisioAppDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\VisioAppView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\DirDialog.h
# End Source File
# Begin Source File

SOURCE=.\ExtListBar.h
# End Source File
# Begin Source File

SOURCE=.\ExtTabModel.h
# End Source File
# Begin Source File

SOURCE=.\ExtTabModelManager.h
# End Source File
# Begin Source File

SOURCE=.\FOHyperLink.h
# End Source File
# Begin Source File

SOURCE=.\FOPathTextShape.h
# End Source File
# Begin Source File

SOURCE=..\..\FO\Include\GdiplusH.h
# End Source File
# Begin Source File

SOURCE=.\GWExtBmpListBox.h
# End Source File
# Begin Source File

SOURCE=.\LinePropDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MBEventEditDlg6.h
# End Source File
# Begin Source File

SOURCE=.\MyCorsssLineShape.h
# End Source File
# Begin Source File

SOURCE=.\MyCustomProperties.h
# End Source File
# Begin Source File

SOURCE=.\MyToolBoxBar.h
# End Source File
# Begin Source File

SOURCE=.\MyToolBoxWnd.h
# End Source File
# Begin Source File

SOURCE=.\NewOpenPageDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewVisualProxy.h
# End Source File
# Begin Source File

SOURCE=.\OutputDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StdioFileEx.h
# End Source File
# Begin Source File

SOURCE=.\VisioApp.h
# End Source File
# Begin Source File

SOURCE=.\VisioAppDoc.h
# End Source File
# Begin Source File

SOURCE=.\VisioAppView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fo_toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mainfram.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mb_trs_l.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mintitle.bmp
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar_.bmp
# End Source File
# Begin Source File

SOURCE=.\res\VisioApp.ico
# End Source File
# Begin Source File

SOURCE=.\res\VisioApp.rc2
# End Source File
# Begin Source File

SOURCE=.\res\VisioAppDoc.ico
# End Source File
# End Group
# End Target
# End Project
