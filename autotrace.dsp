# Microsoft Developer Studio Project File - Name="autotrace" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=autotrace - Win32 Debug
!MESSAGE Dies ist kein g�ltiges Makefile. Zum Erstellen dieses Projekts mit NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und f�hren Sie den Befehl
!MESSAGE 
!MESSAGE NMAKE /f "autotrace.mak".
!MESSAGE 
!MESSAGE Sie k�nnen beim Ausf�hren von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "autotrace.mak" CFG="autotrace - Win32 Debug"
!MESSAGE 
!MESSAGE F�r die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "autotrace - Win32 Release" (basierend auf  "Win32 (x86) Console Application")
!MESSAGE "autotrace - Win32 Debug" (basierend auf  "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "autotrace - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "autotrace___Win32_Release"
# PROP BASE Intermediate_Dir "autotrace___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "autotrace___Win32_Release"
# PROP Intermediate_Dir "autotrace___Win32_Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /MD /W3 /Gm /GX /Zi /Od /I "." /I "C:\ImageMagick-5.2.4" /I "C:\ImageMagick-5.2.4\magick" /I "C:\ImageMagick-5.2.4\xlib" /I "C:\ImageMagick-5.2.4\Magick++\lib" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_VISUALC_" /D "NeedFunctionPrototypes" /D "_MBCS" /D "_DLL" /D "_MAGICKMOD_" /D "HAVE_MAGICK" /D "_AFXDLL" /D VERSION=\"0.27\" /Fp"C:\autotrace-neu\autotrace___Win32_Release/autotraceexe.pch" /YX /Fo"C:\autotrace-neu\autotrace___Win32_Release/" /Fd"C:\autotrace-neu\autotrace___Win32_Release/" /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 CORE_RL_magick_.lib CORE_RL_xlib_.lib CORE_RL_Magick++_.lib winmm.lib dxguid.lib wsock32.lib LIBR_RL_PNG_.lib /nologo /subsystem:console /machine:I386 /libpath:"C:\ImageMagick-5.2.4\VisualMagick\lib\\" /libpath:"E:\Programme\Microsoft Visual Studio\VC98\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "autotrace - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "autotrace___Win32_Debug"
# PROP BASE Intermediate_Dir "autotrace___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "autotrace___Win32_Debug"
# PROP Intermediate_Dir "autotrace___Win32_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "." /I "C:\ImageMagick-5.2.4" /I "C:\ImageMagick-5.2.4\magick" /I "C:\ImageMagick-5.2.4\xlib" /I "C:\ImageMagick-5.2.4\Magick++\lib" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_VISUALC_" /D "NeedFunctionPrototypes" /D "_MBCS" /D "_DLL" /D "_MAGICKMOD_" /D "HAVE_MAGICK" /D "_AFXDLL" /D VERSION=\"0.27\" /Fp"C:\autotrace-neu\autotrace___Win32_Debug\autotrace.exe.pch" /YX /Fo"C:\autotrace-neu/" /Fd"C:\autotrace-neu/" /FD /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 CORE_DB_magick_.lib CORE_DB_xlib_.lib CORE_DB_Magick++_.lib dxguid.lib winmm.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"C:\ImageMagick-5.2.4\VisualMagick\lib\\"

!ENDIF 

# Begin Target

# Name "autotrace - Win32 Release"
# Name "autotrace - Win32 Debug"
# Begin Source File

SOURCE=.\atou.c
# End Source File
# Begin Source File

SOURCE=.\atou.h
# End Source File
# Begin Source File

SOURCE=.\autotrace.c
# End Source File
# Begin Source File

SOURCE=.\autotrace.h
# End Source File
# Begin Source File

SOURCE=.\bitmap.c
# End Source File
# Begin Source File

SOURCE=.\bitmap.h
# End Source File
# Begin Source File

SOURCE=.\cmdline.h
# End Source File
# Begin Source File

SOURCE=.\color.c
# End Source File
# Begin Source File

SOURCE=.\color.h
# End Source File
# Begin Source File

SOURCE=.\curve.c
# End Source File
# Begin Source File

SOURCE=.\curve.h
# End Source File
# Begin Source File

SOURCE=".\epsilon-equal.c"
# End Source File
# Begin Source File

SOURCE=".\epsilon-equal.h"
# End Source File
# Begin Source File

SOURCE=.\filename.c
# End Source File
# Begin Source File

SOURCE=.\filename.h
# End Source File
# Begin Source File

SOURCE=.\fit.c
# End Source File
# Begin Source File

SOURCE=.\fit.h
# End Source File
# Begin Source File

SOURCE=.\getopt.c
# End Source File
# Begin Source File

SOURCE=.\getopt.h
# End Source File
# Begin Source File

SOURCE=.\getopt1.c
# End Source File
# Begin Source File

SOURCE=".\image-header.h"
# End Source File
# Begin Source File

SOURCE=".\input-bmp.c"
# End Source File
# Begin Source File

SOURCE=".\input-bmp.h"
# End Source File
# Begin Source File

SOURCE=".\input-magick.c"
# End Source File
# Begin Source File

SOURCE=".\input-magick.h"
# End Source File
# Begin Source File

SOURCE=".\input-pnm.c"
# End Source File
# Begin Source File

SOURCE=".\input-pnm.h"
# End Source File
# Begin Source File

SOURCE=".\input-tga.c"
# End Source File
# Begin Source File

SOURCE=".\input-tga.h"
# End Source File
# Begin Source File

SOURCE=.\input.c
# End Source File
# Begin Source File

SOURCE=.\input.h
# End Source File
# Begin Source File

SOURCE=.\logreport.c
# End Source File
# Begin Source File

SOURCE=.\logreport.h
# End Source File
# Begin Source File

SOURCE=.\main.c
# End Source File
# Begin Source File

SOURCE=.\median.c
# End Source File
# Begin Source File

SOURCE=.\median.h
# End Source File
# Begin Source File

SOURCE=.\message.h
# End Source File
# Begin Source File

SOURCE=".\output-dxf.c"
# End Source File
# Begin Source File

SOURCE=".\output-dxf.h"
# End Source File
# Begin Source File

SOURCE=".\output-dxf12.c"
# End Source File
# Begin Source File

SOURCE=".\output-dxf12.h"
# End Source File
# Begin Source File

SOURCE=".\output-emf.c"
# End Source File
# Begin Source File

SOURCE=".\output-emf.h"
# End Source File
# Begin Source File

SOURCE=".\output-eps.c"
# End Source File
# Begin Source File

SOURCE=".\output-eps.h"
# End Source File
# Begin Source File

SOURCE=".\output-fig.c"
# End Source File
# Begin Source File

SOURCE=".\output-fig.h"
# End Source File
# Begin Source File

SOURCE=".\output-p2e.c"
# End Source File
# Begin Source File

SOURCE=".\output-p2e.h"
# End Source File
# Begin Source File

SOURCE=".\output-sk.c"
# End Source File
# Begin Source File

SOURCE=".\output-sk.h"
# End Source File
# Begin Source File

SOURCE=".\output-svg.c"
# End Source File
# Begin Source File

SOURCE=".\output-svg.h"
# End Source File
# Begin Source File

SOURCE=.\output.c
# End Source File
# Begin Source File

SOURCE=.\output.h
# End Source File
# Begin Source File

SOURCE=".\pxl-outline.c"
# End Source File
# Begin Source File

SOURCE=".\pxl-outline.h"
# End Source File
# Begin Source File

SOURCE=.\quantize.h
# End Source File
# Begin Source File

SOURCE=.\spline.c
# End Source File
# Begin Source File

SOURCE=.\spline.h
# End Source File
# Begin Source File

SOURCE=.\swf.h
# End Source File
# Begin Source File

SOURCE=".\thin-image.c"
# End Source File
# Begin Source File

SOURCE=".\thin-image.h"
# End Source File
# Begin Source File

SOURCE=.\types.h
# End Source File
# Begin Source File

SOURCE=.\usefull.h
# End Source File
# Begin Source File

SOURCE=.\vector.c
# End Source File
# Begin Source File

SOURCE=.\vector.h
# End Source File
# Begin Source File

SOURCE=.\version.c
# End Source File
# Begin Source File

SOURCE=.\xstd.c
# End Source File
# Begin Source File

SOURCE=.\xstd.h
# End Source File
# End Target
# End Project
