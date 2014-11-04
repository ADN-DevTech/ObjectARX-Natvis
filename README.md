ObjectARX-Natvis
================

MSVC Debugger Type Formatting (NatVis files) for AutoCAD ObjectARX

Visual Studio 2012 has a new  mechanism for creating custom views of native objects. 
The old autoexp.dat files are replaced with new xml-based .natvis files. 
See this MSDN natvis article for details: 
http://msdn.microsoft.com/en-us/library/jj620914.aspx

For info on the old autoexp.dat mechanism, see Kean's blog:
    - July 2006 (http://through-the-interface.typepad.com/through_the_interface/2006/07/advanced_visual.html)
    - August 2006 (http://through-the-interface.typepad.com/through_the_interface/2006/08/more_fun_with_a.html)

The debugger searches for .natvis files in these two locations:
    - %VSINSTALLDIR%\Common7\Packages\Debugger\Visualizers (requires admin access)
    - %USERPROFILE%\My Documents\Visual Studio 2013\Visualizers\

The VSINSTALLDIR location already contains several such files, 
including atlmfc.natvis and stl.natvis, which you are probably already
using during debugging.

Here is a preliminary acad.natvis file for use with VS 2012 (VC11) and later.
It initially supports AcString, AcArray and resbuf. Future candidates for support 
could include AcRxValue, AcDbObject, AcDbObjectId, AcGe*, etc.

To see how big an improvement it makes in variable viewing, here is how the 
debugger shows several kinds of AcStrings by default, without the natvis file:

+ acs1 {mnFlags=4 '\x4' mptr={mnPad2=0x0000004eaddde519 "" mpwszData=0x0000004ebabe1860 L"This is an AcString" ...} ...} AcString
+ acs2 {mnFlags=3 '\x3' mptr={mnPad2=0x0000004eaddde549 "" mpwszData=0x0000004ebabe1920 L"桴獩椠⁳湡愠獮⁩捁瑓楲杮ﷲ﷽꯽ꮫꮫꮫꮫꮫꮫꮫﺫﻮﻮﻮﻮﻮ" ...} ...} AcString
+ acs3 {mnFlags=1 '\x1' mptr={mnPad2=0x0000004eaddde579 "a" mpwszData=0xcccccccccccccccc <Error reading characters of string.> ...} ...} AcString
+ acs4 {mnFlags=2 '\x2' mptr={mnPad2=0x0000004eaddde5a9 "" mpwszData=0xcccccccccccccccc <Error reading characters of string.> ...} ...} AcString
+ acs5 {mnFlags=0 '\0' mptr={mnPad2=0x0000004eaddde5d9 "" mpwszData=0x0000000000000000 <NULL> mpszData=0x0000000000000000 <NULL> ...} ...} AcString
+ acs6 {mnFlags=5 '\x5' mptr={mnPad2=0x0000004eaddde609 "" mpwszData=0x0000004eb4cf2780 L"■듏N" mpszData=0x0000004eb4cf2780 " %Ï´N" ...} ...} AcString

And here is how the same values are shown with acad.natvis:

+ acs1 L"This is an AcString" AcString
+ acs2 "this is an ansi AcString" AcString
+ acs3 "a" AcString
+ acs4 L"u" AcString
+ acs5 "" AcString
+ acs6 L"this is both unicode and ansi" AcString
