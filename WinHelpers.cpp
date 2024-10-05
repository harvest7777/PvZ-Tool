#include "WinHelpers.h"
#include <Windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <cstdint> 

DWORD WinHelpers::getProcessId(const char* processName)
{
	//Get handle
	HWND hWnd = FindWindowA(NULL, processName);
	if (hWnd == NULL)
	{
		return 0;
	}

	DWORD processId;
	GetWindowThreadProcessId(hWnd, &processId);
	
	return processId;
}

DWORD WinHelpers::getBaseAddress(DWORD processId)
{
	DWORD processBaseAddress = 0;

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);

	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		return processBaseAddress;
	}

	MODULEENTRY32 modEntry;
	modEntry.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnapshot, &modEntry))
	{
		processBaseAddress = (uintptr_t)modEntry.modBaseAddr;
	}

	CloseHandle(hSnapshot);
	return processBaseAddress;
}