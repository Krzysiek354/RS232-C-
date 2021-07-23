// rs232_ok.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include<Windows.h>
#include<fstream>

using namespace std;


class jakas
{
public:

	jakas()
	{

	}

	void fun()
	{
		cout << "funkcja" << endl;
	}
};

//bool tworzenie_portu()
//{
//	hcom = CreateFile(L"COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
//	if (hcom == (HANDLE)-1)
//	{
//		cout << "Nie stworze coma" << endl;
//		return false;
//	}
//	cout << "MAMY KOMA" << endl;
//	return 1;
//}

int main()
{

	DCB dcb;
	static HANDLE hNumPort;
	static char lpBuffor_read[17], lpBuffor_write[17];
	static DWORD RS_ile;

	hNumPort = CreateFile(L"COM4", GENERIC_WRITE |
		GENERIC_READ, 0, NULL,
		OPEN_EXISTING, 0, NULL);



	dcb.DCBlength = sizeof(dcb);
	dcb.BaudRate = CBR_115200;
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;
	dcb.fDtrControl = DTR_CONTROL_ENABLE;
	dcb.fRtsControl = RTS_CONTROL_ENABLE;
	dcb.fOutxCtsFlow = FALSE;
	dcb.fOutxDsrFlow = FALSE;
	dcb.fDsrSensitivity = FALSE;
	dcb.fAbortOnError = FALSE;
	dcb.fOutX = FALSE;
	dcb.fInX = FALSE;
	dcb.fErrorChar = FALSE;
	dcb.fNull = FALSE;

	SetCommState(hNumPort, &dcb);

	COMMTIMEOUTS time_outs;
	time_outs.ReadIntervalTimeout = 1000;
	time_outs.ReadTotalTimeoutMultiplier = 500;
	time_outs.ReadTotalTimeoutConstant = 5000;
	time_outs.WriteTotalTimeoutMultiplier = 500;
	time_outs.WriteTotalTimeoutConstant = 2000;
	if (!SetCommTimeouts(hNumPort, &time_outs))
	{
		return 0;
	}

	fstream zapis;
	/*zapis.open("dane.txt",ios::out|ios::trunc);
	if (zapis.is_open())
	{
		cout << "otwarto plik" << endl;
	}*/
	
	
	
	while (1)
	{
		ReadFile(hNumPort, lpBuffor_read, 17, &RS_ile, 0);
		zapis.open("dane.txt", ios::out | ios::trunc);
		zapis << lpBuffor_read[0];
		zapis << lpBuffor_read[1];
		zapis << lpBuffor_read[2] ;
		zapis << lpBuffor_read[3] ;
		zapis << lpBuffor_read[4] ;
		zapis << lpBuffor_read[5] ;
		zapis << lpBuffor_read[6] ;
		zapis << lpBuffor_read[7] ;
		zapis << lpBuffor_read[8] ;
		zapis << lpBuffor_read[9] ;
		zapis << lpBuffor_read[10];
		zapis << lpBuffor_read[11];
		zapis << lpBuffor_read[12];
		zapis << lpBuffor_read[13];
		zapis << lpBuffor_read[14];
		zapis << lpBuffor_read[15];
		for (int i=0;i<17;i++)
		{
			lpBuffor_read[i] = ' ';
		}
		zapis.close();

	}

	CloseHandle(hNumPort);
	//if (1)
	//{
	//	HANDLE hcom;
	//	hcom = CreateFile(L"COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	//	if (hcom == (HANDLE)-1)
	//	{
	//		cout << "Nie stworze coma" << endl;
	//		return false;
	//	}
	//	cout << "MAMY KOMA" << endl;
	//

	//	SetupComm(hcom, 1024, 1024);
	//	COMMTIMEOUTS time_outs;
	//	time_outs.ReadIntervalTimeout = 1000;
	//	time_outs.ReadTotalTimeoutMultiplier = 500; 
	//	time_outs.ReadTotalTimeoutConstant = 5000;
	//	time_outs.WriteTotalTimeoutMultiplier = 500;
	//	time_outs.WriteTotalTimeoutConstant = 2000;
	//	if (!SetCommTimeouts(hcom, &time_outs))
	//	{
	//		return 0;
	//	}

	//	DCB dcb{0};
	//	dcb.DCBlength = sizeof(dcb);
	//	GetCommState(hcom,&dcb);
	//	dcb.BaudRate = CBR_115200;
	//	dcb.ByteSize = 8;
	//	dcb.Parity = NOPARITY;
	//	dcb.StopBits = ONESTOPBIT;
	//	if (!SetCommState(hcom, &dcb))
	//	{
	//		return 0;
	//	}
	//	cout << "jestem dalej" << endl;
	//	PurgeComm(hcom,PURGE_TXCLEAR|PURGE_RXCLEAR);
	//	
	//	char bufor[1024];

	//	DWORD dwbytesread = 1024;
	//	BOOL bReadStat;
	//	COMSTAT ComStat;
	//	DWORD dwErrorFlags;
	//	OVERLAPPED m_osRead;
	//	ClearCommError(hcom,&dwErrorFlags,&ComStat);
	//	/*if(!ComStat.cbInQue)
	//	{
	//		return 0;
	//	}*/

	//	//dwbytesread = min(dwbytesread,(DWORD)ComStat.cbInQue);
	//	int i = 0;
	//
	//		bReadStat = ReadFile(hcom, bufor, dwbytesread, &dwbytesread, &m_osRead);

	//		for (int i = 0; i < 1024; i++)
	//		{
	//			cout << bufor[i];
	//		}

	//	if (!bReadStat)
	//	{
	//		if (GetLastError() == ERROR_IO_PENDING)
	//		{
	//			GetOverlappedResult(hcom, &m_osRead, &dwbytesread, TRUE);
	//			cout << dwbytesread << endl;
	//		}
	//		
	//		return 0;
	//	}

	//	cout << dwbytesread << endl;;

	//}
	

//    static DCB dcb{0};
//    static HANDLE hNumPort;
//    static char lpBuffor_read[255], lpBuffor_write[255];
//    static DWORD RS_ile;
//    char tab[30] = {"Witam tutaj JA JA\t"};
//
//    hNumPort = CreateFile(TEXT("COM4"), GENERIC_WRITE |
//        GENERIC_READ, 0, 0,
//        OPEN_EXISTING, FILE_FLAG_OVERLAPPED,0);
//
//    if (hNumPort == INVALID_HANDLE_VALUE)
//    {
//        cout << "nie pyklo" << endl;
//    }
//
//
//    dcb.DCBlength = sizeof(dcb);
//
//    dcb.BaudRate = CBR_115200;
//    dcb.fParity = 0;
//    dcb.Parity = 0;
//    dcb.StopBits = ONESTOPBIT;
//    dcb.ByteSize = 8;
//
//    dcb.fDtrControl = DTR_CONTROL_ENABLE;
//    dcb.fRtsControl = RTS_CONTROL_ENABLE;
//
//   /* dcb.fOutxCtsFlow = FALSE;
//    dcb.fOutxDsrFlow = FALSE;
//    dcb.fDsrSensitivity = FALSE;
//    dcb.fAbortOnError = FALSE;
//    dcb.fOutX = FALSE;
//    dcb.fInX = FALSE;
//    dcb.fErrorChar = FALSE;
//    dcb.fNull = FALSE;*/
//
//    DWORD temppor = 0;
//    int len = 255;
//    if (SetCommState(hNumPort, &dcb))
//    {
//
//        {
//            //while (1)
//            {
//                if (ReadFile(hNumPort, lpBuffor_read, len, &temppor, NULL))
//                {
//                    for (int i = 0; i < 200; i++)
//                    {
//                        cout << lpBuffor_read[i] << endl;
//                            cout << temppor << endl;
//                    }
//                }
//
//                else cout<<"zjeba"<<endl;
//            }
//            
//
//        }
//    }
//
//    else std::cout << "nie moge czytac";
//   
//   
//   // ReadFile(hNumPort, lpBuffor_read, 15, &RS_ile, 0);
//   // CloseHandle(hNumPort);
}





