// --------------------------------------------------------------------------------------
// (c) 2003 www.winapi.net
//
// Serial.cpp
//
// CPP-Datei für eine einfache, aber leistungsfähige 
// Kommunikation über die Serielle Schnittstelle
// --------------------------------------------------------------------------------------

#include <windows.h>
#include "Serial.h"

CSerial::CSerial()
{
	hComm = INVALID_HANDLE_VALUE;
}


/**
 * Destructor
 */
CSerial::~CSerial()
{
	Close ();
}

/**
 * Check wether the port is open or not
 */
BOOL CSerial::IsOpen()
{
   if (INVALID_HANDLE_VALUE != hComm)
       return (TRUE);
	else
		return (FALSE);
}


BOOL CSerial::ModeSet (int nBaud, int nBits, int nParity, int nStopp)
{
   if (INVALID_HANDLE_VALUE == hComm)
	{
		SetLastError(ERROR_INVALID_HANDLE);
      return (FALSE);
	}

   DCB dcb;

   ZeroMemory (&dcb, sizeof(dcb));
	dcb.DCBlength = sizeof(DCB);

   if (!GetCommState (hComm, &dcb))
      return (FALSE);

   dcb.BaudRate = nBaud;
   dcb.ByteSize = (BYTE)nBits;
   dcb.Parity   = (BYTE)nParity;
	dcb.StopBits = (BYTE)nStopp;   

   if (!SetCommState (hComm, &dcb))
		return (FALSE);

	return (TRUE);
}


BOOL CSerial::Open (int nComPortNr, int nBaud, int nBits, int nParity, int nStopp)
{
   if (INVALID_HANDLE_VALUE != hComm)
	{
      return (TRUE);
	}

   char szPort[16];

   wsprintf (szPort, "\\\\.\\COM%d", nComPortNr);

   hComm = CreateFile (szPort,
						  GENERIC_READ | GENERIC_WRITE,
                    0,
                    0,
                    OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);

   if (hComm == INVALID_HANDLE_VALUE)
      return (FALSE);

   if (!GetCommTimeouts(hComm, &timeouts_alt))
   {
		DWORD dwError = GetLastError();
		Close ();
		SetLastError(dwError);
      return (FALSE);
   }

   COMMTIMEOUTS timeouts;
   timeouts.ReadIntervalTimeout = MAXDWORD ;
   timeouts.ReadTotalTimeoutMultiplier = MAXDWORD ;
   timeouts.ReadTotalTimeoutConstant = 3000; // Timeout ist 3000ms 
   timeouts.WriteTotalTimeoutMultiplier = 1000;
   timeouts.WriteTotalTimeoutConstant = 1000;

   if (!SetCommTimeouts(hComm, &timeouts))
   {
		DWORD dwError = GetLastError();
		Close ();
		SetLastError(dwError);
      return (FALSE);
   }

   DCB dcb;
   ZeroMemory (&dcb, sizeof(dcb));
	dcb.DCBlength = sizeof(DCB);

   if (!GetCommState (hComm, &dcb))
   {
		DWORD dwError = GetLastError();
		Close ();
		SetLastError(dwError);
      return (FALSE);
   }

	dcb_alt = dcb;
	dcb.fBinary = TRUE; // muss immer "TRUE" sein!
	dcb.fParity = TRUE;
	dcb.fOutxCtsFlow = FALSE;
	dcb.fOutxDsrFlow = FALSE;
	dcb.fDtrControl = DTR_CONTROL_ENABLE;
	dcb.fDsrSensitivity = FALSE;
	dcb.fTXContinueOnXoff = TRUE;
	dcb.fOutX = FALSE;
	dcb.fInX = FALSE;
	dcb.fErrorChar = FALSE;
	dcb.fNull = FALSE;
	dcb.fRtsControl = RTS_CONTROL_ENABLE;
	dcb.fAbortOnError = FALSE;
	dcb.wReserved = 0; // muss immer "0" sein!
 
	dcb.BaudRate = nBaud;
	dcb.ByteSize = (BYTE)nBits;
	dcb.Parity   = (BYTE)nParity;
	dcb.StopBits = (BYTE)nStopp;   
	
   dcb.fParity = (dcb.Parity != NOPARITY);

   if (!SetCommState(hComm, &dcb))
   {
		DWORD dwError = GetLastError();
		Close ();
		SetLastError(dwError);
      return (FALSE);
   }

   return(TRUE);
}


BOOL CSerial::Close (void)
{
   BOOL bResult;

	if(INVALID_HANDLE_VALUE == hComm)
		return (TRUE);

	SetCommTimeouts(hComm, &timeouts_alt);
	SetCommState(hComm, &dcb_alt);

	bResult = CloseHandle(hComm);
	hComm   = INVALID_HANDLE_VALUE;

	return(bResult);
}


BOOL CSerial::SetTimeout (int iTotalReadTimeout)
{
   if (INVALID_HANDLE_VALUE == hComm)
      return (TRUE);

   COMMTIMEOUTS timeouts;
   timeouts.ReadIntervalTimeout = MAXDWORD ;
   timeouts.ReadTotalTimeoutMultiplier = MAXDWORD ;
   timeouts.ReadTotalTimeoutConstant = (DWORD) iTotalReadTimeout;
   timeouts.WriteTotalTimeoutMultiplier = 1000;
   timeouts.WriteTotalTimeoutConstant = 1000;

   if (!SetCommTimeouts(hComm, &timeouts))
      return (FALSE);

   return(TRUE);
}


BOOL CSerial::WriteCommByte (unsigned char ucByte)
{
   if (INVALID_HANDLE_VALUE == hComm)
	{
		SetLastError(ERROR_INVALID_HANDLE);
      return (FALSE);
	}

   if (!TransmitCommChar(hComm, ucByte))
		return (FALSE);

   return (TRUE);
}


int CSerial::SendData (const char *buffer, int iBytesToWrite)
{
   if (INVALID_HANDLE_VALUE == hComm)
	{
		SetLastError(ERROR_INVALID_HANDLE);
      return (0);
	}

   DWORD dwBytesWritten = 0;
   WriteFile(hComm, buffer, iBytesToWrite, &dwBytesWritten, NULL);

   return ((int) dwBytesWritten);
}


int CSerial::ReadData (char *buffer, int iMaxCount)
{
   if (INVALID_HANDLE_VALUE == hComm)
	{
		SetLastError(ERROR_INVALID_HANDLE);
      return (0);
	}

   DWORD dwRead = 0;
   char chRead;
   int i = 0;

   while (ReadFile(hComm, &chRead, 1, &dwRead, NULL))
   {
       if (dwRead != 1)
           break;

       buffer[i++] = chRead;

		 if (i == iMaxCount)
			 break;
	}

	return (i);
}
