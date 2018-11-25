unit oshb;

interface

type
TPacket = record
Source,Destination:Word;
fncode,length:Byte;
Data:Array[0..7] of Byte;
flags:Byte;
used:boolean;
ready:boolean;
//CRC:integer;
end;

const
UartPacketSize = 15;
implementation

end.
