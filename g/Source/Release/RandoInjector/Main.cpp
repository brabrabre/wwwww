

// TODO: iiro �l� p�lli mun koodii D: jos p�llit en pelk�� nukuttaa! ja laita sun omaa junk koodii toho asm edit eli laita numeroi homo!

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#define DLL_NAME "pphud.beta.dll"

#define JUNKS \
__asm _emit 0x10 \
__asm _emit 0x51 \
__asm _emit 0x56 \
__asm _emit 0x63 \
__asm _emit 0x61 \
__asm _emit 0x41 \
__asm _emit 0x77 \
__asm _emit 0x08 \
__asm _emit 0x52 \
__asm _emit 0x10 \
__asm _emit 0x51 \
__asm _emit 0x56 \
__asm _emit 0x63 \
__asm _emit 0x61 \
__asm _emit 0x41 \
__asm _emit 0x77 \
__asm _emit 0x08 \
__asm _emit 0x52 \
__asm _emit 0x19 \
__asm _emit 0x51 \
__asm _emit 0x11 \
__asm _emit 0x61 \
__asm _emit 0x41 \
__asm _emit 0x26 \
__asm _emit 0x77 \
__asm _emit 0x51 \
__asm _emit 0x55 \



#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:


/////////////////////////////////////////////////////////////////////////////////////
//               el� vaiha n�it tai rikot kokonaa                                  //
/////////////////////////////////////////////////////////////////////////////////////

DWORD Process(char* ProcessName)
{
	_JUNK_BLOCK(jmp_label1)
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	_JUNK_BLOCK(jmp_label2)
	PROCESSENTRY32 ProcEntry;
	
	_JUNK_BLOCK(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	
	_JUNK_BLOCK(jmp_label4)
	do
	{
		_JUNK_BLOCK(jmp_label5)
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			_JUNK_BLOCK(jmp_label6)
			DWORD dwPID = ProcEntry.th32ProcessID;
			
			_JUNK_BLOCK(jmp_label7)
			CloseHandle(hPID);
			
			_JUNK_BLOCK(jmp_label8)
			return dwPID;
		}
		
		_JUNK_BLOCK(jmp_label9)
	}
	while (Process32Next(hPID, &ProcEntry));
	
	_JUNK_BLOCK(jmp_label10)
}

int main()
{
	_JUNK_BLOCK(jmp_label11)
	DWORD dwProcess;
	
	_JUNK_BLOCK(jmp_label12)
	char myDLL[MAX_PATH];
	
	_JUNK_BLOCK(jmp_label13)
	GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);
	
	_JUNK_BLOCK(jmp_label4)
	dwProcess = Process("csgo.exe");
	
	_JUNK_BLOCK(jmp_label15)
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	
	_JUNK_BLOCK(jmp_label16)
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	
	_JUNK_BLOCK(jmp_label17)
	WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
	
	_JUNK_BLOCK(jmp_label18)
	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
	
	_JUNK_BLOCK(jmp_label19)
	CloseHandle(hProcess);
	
	_JUNK_BLOCK(jmp_label20)
	return 0;
	
	_JUNK_BLOCK(jmp_label21)
}