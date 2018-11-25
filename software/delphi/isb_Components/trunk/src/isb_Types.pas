unit isb_Types;

interface

type
  Tisb_Msg = record
    Port: Byte;
    DestId: Word;
    SourceId: Word;
    Flags: Byte;
    DataLength: Byte;
    Data: Array[0..7] of Byte;
  end;

type
  Tisb_Msg_RS232 = record
    Startbyte: Byte;
    Port: Byte;
    DestId: Word;
    SourceId: Word;
    Flags: Byte;
    DataLength: Byte;
    Data: Array[0..7] of Byte;
    Crc: Word;
    Stopbyte: Byte;
  end;

implementation

end.
