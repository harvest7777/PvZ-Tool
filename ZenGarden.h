#pragma once
#include <Windows.h>
class ZenGarden
{
private:
	HANDLE handle;
	DWORD zenGardenBaseAddress;
	const DWORD ZEN_GARDEN_OFFSET = 0x00326E14;
	const DWORD TREE_OF_WISDOM_OFFSET = 0x244;
	const DWORD MONEY_OFFSET = 0x178;
public:
	ZenGarden(HANDLE hndl, DWORD baseAddr);

	void setTreeHeight(int newHeight);
	int getTreeHeight();

	void setMoney(int newMoney);
	int getMoney();

};

