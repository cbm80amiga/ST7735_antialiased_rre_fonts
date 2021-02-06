@rem tcc rrefontgen.c
@rem if %ERRORLEVEL% neq 0 exit /B %ERRORLEVEL%
@rem @echo Build OK

@rem https://github.com/cbm80amiga/rrefontgen
@rem Usage in PBM mode:
@rem    rrefontgen [font.pbm] [char w] [char h] <fontName> <fontMode> <overlap> <optim>
@rem  Usage in LCD/XML mode:
@rem    rrefontgen [font.lcd] <fontName> <fontMode> <overlap> <optim>
@rem  Usage in C header font mode:
@rem    rrefontgen <fontName> <fontMode> <overlap> <optim>
@rem  fontMode: 0 - rect, 1 - vert, 2 - horiz, 3 - pixel
@rem  overlap:  0 - no overlapping quads, 1 - old overlapping, 2 - less overlapping (default)
@rem  optim:    0 - do not remove empty columns, 1 - shift chars to the left

echo %time%

@rem rrefontgen dig16x24_c1.pbm 48 24 dig16x24_c1 0 2 0 >dig16x24_c1.h
@rem rrefontgen dig16x24_c2.pbm 48 24 dig16x24_c2 0 2 0 >dig16x24_c2.h
@rem rrefontgen dig16x24_c3.pbm 48 24 dig16x24_c3 0 2 0 >dig16x24_c3.h
@rem rrefontgen dig16x24_c123.pbm 48 24 dig16x24_c123 0 2 0 >dig16x24_c123.h

@rem rrefontgen dig12x17_c1.pbm 16 17 dig12x17_c1 0 2 0 >dig12x17_c1.h
@rem rrefontgen dig12x17_c2.pbm 16 17 dig12x17_c2 0 2 0 >dig12x17_c2.h
@rem rrefontgen dig12x17_c3.pbm 16 17 dig12x17_c3 0 2 0 >dig12x17_c3.h
@rem rrefontgen dig12x17_c123.pbm 16 17 dig12x17_c123 0 2 0 >dig12x17_c123.h

@rem rrefontgen dig10x14_c1.pbm 16 14 dig10x14_c1 0 2 0 >dig10x14_c1.h
@rem rrefontgen dig10x14_c2.pbm 16 14 dig10x14_c2 0 2 0 >dig10x14_c2.h
@rem rrefontgen dig10x14_c3.pbm 16 14 dig10x14_c3 0 2 0 >dig10x14_c3.h
@rem rrefontgen dig10x14_c123.pbm 16 14 dig10x14_c123 0 2 0 >dig10x14_c123.h

@rem rrefontgen dig7x11_c1.pbm 16 11 dig7x11_c1 0 2 0 >dig7x11_c1.h
@rem rrefontgen dig7x11_c2.pbm 16 11 dig7x11_c2 0 2 0 >dig7x11_c2.h
@rem rrefontgen dig7x11_c3.pbm 16 11 dig7x11_c3 0 2 0 >dig7x11_c3.h
@rem rrefontgen dig7x11_c123.pbm 16 11 dig7x11_c123 0 2 0 >dig7x11_c123.h

@rem rrefontgen dig12x19_c1.pbm 16 19 dig12x19_c1 0 2 0 >dig12x19_c1.h
@rem rrefontgen dig12x19_c2.pbm 16 19 dig12x19_c2 0 2 0 >dig12x19_c2.h
@rem rrefontgen dig12x19_c3.pbm 16 19 dig12x19_c3 0 2 0 >dig12x19_c3.h
@rem rrefontgen dig12x19_c123.pbm 16 19 dig12x19_c123 0 2 0 >dig12x19_c123.h

@rem rrefontgen dig29x36_c1.pbm 32 36 dig29x36_c1 0 2 0 >dig29x36_c1.h
@rem rrefontgen dig29x36_c2.pbm 32 36 dig29x36_c2 0 2 0 >dig29x36_c2.h
@rem rrefontgen dig29x36_c3.pbm 32 36 dig29x36_c3 0 2 0 >dig29x36_c3.h

@rem rrefontgen dig7x9_c1.pbm 8 9 dig7x9_c1 0 2 0 >dig7x9_c1.h
@rem rrefontgen dig7x9_c2.pbm 8 9 dig7x9_c2 0 2 0 >dig7x9_c2.h
@rem rrefontgen dig7x9_c3.pbm 8 9 dig7x9_c3 0 2 0 >dig7x9_c3.h
@rem rrefontgen dig7x9_c123.pbm 8 9 dig7x9_c123 0 2 0 >dig7x9_c123.h

@rem rrefontgen font16x32_c1.pbm 16 32 font16x32_c1 0 2 0 >font16x32_c1.h
@rem rrefontgen font16x32_c2.pbm 16 32 font16x32_c2 0 2 0 >font16x32_c2.h
@rem rrefontgen font16x32_c3.pbm 16 32 font16x32_c3 0 2 0 >font16x32_c3.h
@rem rrefontgen font16x32_c123.pbm 16 32 font16x32_c123 0 2 0 >font16x32_c123.h

@rem rrefontgen font16x32_c2.pbm 16 32 font16x32_c2 3 2 0 >font16x32_c2p.h

@rem rrefontgen fonti16x32_c1.pbm 16 32 fonti16x32_c1 0 2 0 >fonti16x32_c1.h
@rem rrefontgen fonti16x32_c2.pbm 16 32 fonti16x32_c2 0 2 0 >fonti16x32_c2.h
@rem rrefontgen fonti16x32_c3.pbm 16 32 fonti16x32_c3 0 2 0 >fonti16x32_c3.h
@rem rrefontgen fonti16x32_c123.pbm 16 32 fonti16x32_c123 0 2 0 >fonti16x32_c123.h

rrefontgen dig16x24_c1.pbm 48 24 dig16x24_c1 3 2 0 >dig16x24_c1p.h
rrefontgen dig16x24_c1.pbm 48 24 dig16x24_c1 1 2 0 >dig16x24_c1v.h
rrefontgen dig16x24_c1.pbm 48 24 dig16x24_c1 2 2 0 >dig16x24_c1h.h
rrefontgen dig16x24_c1.pbm 48 24 dig16x24_c1 0 2 0 >dig16x24_c1.h

rrefontgen dig16x24_c2.pbm 48 24 dig16x24_c2 3 2 0 >dig16x24_c2p.h
rrefontgen dig16x24_c2.pbm 48 24 dig16x24_c2 1 2 0 >dig16x24_c2v.h
rrefontgen dig16x24_c2.pbm 48 24 dig16x24_c2 2 2 0 >dig16x24_c2h.h
rrefontgen dig16x24_c2.pbm 48 24 dig16x24_c2 0 2 0 >dig16x24_c2.h

rrefontgen dig16x24_c3.pbm 48 24 dig16x24_c3 3 2 0 >dig16x24_c3p.h
rrefontgen dig16x24_c3.pbm 48 24 dig16x24_c3 1 2 0 >dig16x24_c3v.h
rrefontgen dig16x24_c3.pbm 48 24 dig16x24_c3 2 2 0 >dig16x24_c3h.h
rrefontgen dig16x24_c3.pbm 48 24 dig16x24_c3 0 2 0 >dig16x24_c3.h

echo %time%

set /p DUMMY=Hit Enter ...
