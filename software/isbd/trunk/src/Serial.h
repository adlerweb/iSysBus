// --------------------------------------------------------------------------------------
// (c) 2003 www.winapi.net
//
// Serial.h
//
// Headerdatei fÅr eine einfache, aber leistungsfÑhige 
// Kommunikation Åber die Serielle Schnittstelle
// --------------------------------------------------------------------------------------

#ifndef __SERIAL_H__
#define __SERIAL_H__

class CSerial
{

public:
	CSerial();
	~CSerial();

	BOOL Open (int nComPortNr, int nBaud, int nBits, int nParity, int nStopp);
	BOOL Close (void);
	BOOL ModeSet (int nBaud, int nBits, int nParity, int nStopp);
	BOOL SetTimeout (int iTotalReadTimeout);
	BOOL IsOpen (void);

	int ReadData (char *buffer, int iMaxCount);
	int SendData (const char *buffer, int iBytesToWrite);
	BOOL WriteCommByte (unsigned char ucByte);

private:
	HANDLE hComm;
	DCB dcb_alt;
	COMMTIMEOUTS timeouts_alt;
};

#endif
