#include "ZenGarden.h"
#include "iostream"
#include <Windows.h>

ZenGarden::ZenGarden(HANDLE hndl, DWORD baseAddr)
{
	handle = hndl;
	DWORD pointerToZenBaseAddress = baseAddr + ZEN_GARDEN_OFFSET;

	ReadProcessMemory(handle, LPCVOID(pointerToZenBaseAddress), &zenGardenBaseAddress, sizeof(zenGardenBaseAddress), nullptr);
}

void ZenGarden::setTreeHeight(int newHeight)
{
	//Avoid going over maximum allowed height
	if (newHeight > 1000000) newHeight = 1000000;

	WriteProcessMemory(handle, LPVOID(zenGardenBaseAddress + TREE_OF_WISDOM_OFFSET), &newHeight, sizeof(newHeight), nullptr);
}

int ZenGarden::getTreeHeight()
{
	int height = -1;
	ReadProcessMemory(handle, LPCVOID(zenGardenBaseAddress + TREE_OF_WISDOM_OFFSET), &height, sizeof(height), nullptr);

	return height;
}
void ZenGarden::setMoney(int newMoney)
{
	//Avoid going over the maximum allowed money
	if (newMoney > 999990) newMoney = 999990;

	//PvZ money is calculated by taking your money * 10
	newMoney = newMoney / 10;
	WriteProcessMemory(handle, LPVOID(zenGardenBaseAddress + MONEY_OFFSET), &newMoney, sizeof(newMoney), nullptr);

}

int ZenGarden::getMoney()
{
	int money = -1;
	ReadProcessMemory(handle, LPCVOID(zenGardenBaseAddress + MONEY_OFFSET), &money, sizeof(money), nullptr);
	
	return money;
}