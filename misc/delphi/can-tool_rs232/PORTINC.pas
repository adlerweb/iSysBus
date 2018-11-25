unit PORTINC;

interface

uses windows;

const THEDLL='PORT.DLL';
Procedure DELAY(i:WORD); stdcall; external THEDLL;
Procedure TIMEINIT; stdcall; external THEDLL;
Function TIMEREAD: DWORD; stdcall; external THEDLL;
Procedure DELAYUS(i:DWORD); stdcall; external THEDLL;
Procedure TIMEINITUS; stdcall; external THEDLL;
Function TIMEREADUS: DWORD; stdcall; external THEDLL;
Procedure OUTPORT(PortAddr:Word; Data:byte); stdcall; external THEDLL;
Function INPORT(PortAddr:Word):Byte;stdcall; external THEDLL;
Function OPENCOM(S:PCHAR):Integer;stdcall; external THEDLL;
Function READBYTE:Integer;stdcall; external THEDLL;
Procedure SENDBYTE(d:WORD);stdcall; external THEDLL;
Procedure DTR(d:WORD);stdcall; external THEDLL;
Procedure RTS(d:WORD);stdcall; external THEDLL;
Procedure TXD(d:WORD);stdcall; external THEDLL;
Function CTS:Integer;stdcall; external THEDLL;
Function DSR:Integer;stdcall; external THEDLL;
Function RI:Integer;stdcall; external THEDLL;
Function DCD:Integer;stdcall; external THEDLL;
Procedure TIMEOUT(Wert: WORD); stdcall; external THEDLL;
Procedure REALTIME(d:BOOLEAN);stdcall; external THEDLL;
Function SOUNDSETRATE(Rate:DWORD):DWORD; stdcall; external THEDLL;
Function SOUNDGETRATE:DWORD; stdcall; external THEDLL;
Function SOUNDBUSY:Boolean; stdcall; external THEDLL;
Function SOUNDIS:Boolean; stdcall; external THEDLL;
Procedure SOUNDIN(Puffer:Pchar;Size:DWORD); stdcall; external THEDLL;
Procedure SOUNDOUT(Puffer:Pchar;Size:DWORD); stdcall; external THEDLL;
Function SOUNDGETBYTES:DWORD; stdcall; external THEDLL;
Function SOUNDSETBYTES(B:DWORD):DWORD; stdcall; external THEDLL;
Procedure SOUNDCAPIN; stdcall; external THEDLL;
Procedure SOUNDCAPOUT; stdcall; external THEDLL;
Function JOYX:DWORD;stdcall; external THEDLL;
Function JOYY:DWORD;stdcall; external THEDLL;
Function JOYZ:DWORD;stdcall; external THEDLL;
Function JOYR:DWORD;stdcall; external THEDLL;
Function JOYBUTTON:DWORD;stdcall; external THEDLL;

implementation

end.

