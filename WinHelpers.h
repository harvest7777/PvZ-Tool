#pragma once
#include <Windows.h>
class WinHelpers
{
public:
	DWORD getProcessId(const char* processName);
	DWORD getBaseAddress(DWORD processId);

};

