#define DEBUGx
#include "Level.h"
#include <iostream>
Level::Level(HANDLE hndl, DWORD baseAddr)
{
	handle = hndl;
	baseAddress = baseAddr;
	DWORD pointer1;
	DWORD pointer2;
	ReadProcessMemory(handle, LPCVOID(baseAddress + 0x329670), &pointer1, sizeof(pointer1), nullptr);
	ReadProcessMemory(handle, LPCVOID(pointer1 + 0x868), &pointer2, sizeof(pointer2), nullptr);

	SUN_ADDRESS = pointer2 + 0x5578;

#ifdef DEBUG
	std::cout << std::hex << "Game Base Address: " << baseAddr << std::endl;
	std::cout << std::hex << "Level pointer1: " << pointer1 << std::endl;
	std::cout << std::hex << "Level pointer2: " << pointer2 << std::endl;
	std::cout << std::hex << "Level SUN_ADDRESS: " << SUN_ADDRESS << std::endl;
#endif
}
void Level::refreshSunAddress()
{
	DWORD pointer1;
	DWORD pointer2;
	ReadProcessMemory(handle, LPCVOID(baseAddress + 0x329670), &pointer1, sizeof(pointer1), nullptr);
	ReadProcessMemory(handle, LPCVOID(pointer1 + 0x868), &pointer2, sizeof(pointer2), nullptr);

	SUN_ADDRESS = pointer2 + 0x5578;
}
void Level::setSun(int newSun)
{
	if (newSun > 9990)
	{
		newSun = 9990;
	}
	WriteProcessMemory(handle, LPVOID(SUN_ADDRESS), &newSun, sizeof(newSun), nullptr);
}
int Level::getSun()
{
	int sunValue = -1;
	ReadProcessMemory(handle, LPCVOID(SUN_ADDRESS), &sunValue, sizeof(sunValue), nullptr);

#ifdef DEBUG
	std::cout << std::dec << "Sun Value: " << sunValue << std::endl;
#endif
	return sunValue;
}

void Level::enableNoCoolDown()
{
	WriteProcessMemory(handle, LPVOID(baseAddress + COOLDOWN_OFFSET), &NO_COOLDOWN_INSTRUCTION, sizeof(NO_COOLDOWN_INSTRUCTION), nullptr);
}

void Level::disableNoCooldown()
{
	WriteProcessMemory(handle, LPVOID(baseAddress + COOLDOWN_OFFSET), &ORIGINAL_COOLDOWN_INSTRUCTION, sizeof(ORIGINAL_COOLDOWN_INSTRUCTION), nullptr);
}

void Level::enableNoPlantDamage()
{
	WriteProcessMemory(handle, LPVOID(baseAddress + PLANT_DAMAGE_OFFSET), &NO_PLANT_DAMAGE_INSTRUCTION, sizeof(NO_PLANT_DAMAGE_INSTRUCTION), nullptr);
}

void Level::disableNoPlantDamage()
{
	WriteProcessMemory(handle, LPVOID(baseAddress + PLANT_DAMAGE_OFFSET), &ORIGINAL_PLANT_DAMAGE_INSTRUCTION, sizeof(ORIGINAL_PLANT_DAMAGE_INSTRUCTION), nullptr);
}

void Level::enableRowPlant()
{
	/*
	original game logic: cmp gamemode == 27?
	
	if yes -> zf = 1 (27-27=0)
	if no -> zf = 0

	jne -> jump when previous comparison was false (zf = 0)
	jne -> jump when gamemode is not 27
	
	if gamemode is 27, DONT jump. continue with row plant

	hack logic:
	cmp gamemode == unused gamemode ID
	je single plant

	if gamemode == (lets just say 100) zf = 1
	if gamemode not 100 zf = 0

	if gamemode == 100 (zf = 1) jump to single plant
	else continue with row plant

	GAMEMODE WILL NEVER == 10= because it doesnt exist
	WILL ALWAYS ROW PLANT regardless of gamemode
	*/

	WriteProcessMemory(handle, LPVOID(baseAddress + ROW_PLANT_OFFSET), &ROW_PLANT_DECISION_INSTRUCTION, sizeof(ROW_PLANT_DECISION_INSTRUCTION), nullptr);

	DWORD currentGamemode;
	BYTE newGamemode = 0x28;

	ReadProcessMemory(handle, LPCVOID(baseAddress + GAMEMODE_OFFSET), &currentGamemode, sizeof(currentGamemode), nullptr);
	currentGamemode = (currentGamemode & 0xFFFFFF00) | newGamemode;

	WriteProcessMemory(handle, LPVOID(baseAddress + GAMEMODE_OFFSET), &currentGamemode, sizeof(currentGamemode), nullptr);
}

void Level::disableRowPlant()
{
	WriteProcessMemory(handle, LPVOID(baseAddress + ROW_PLANT_OFFSET), &ORINGINAL_PLANT_DECISION_INSTRUCTION, sizeof(ORIGINAL_PLANT_DAMAGE_INSTRUCTION), nullptr);
	DWORD currentGamemode;
	BYTE newGamemode = 0x1B;

	ReadProcessMemory(handle, LPCVOID(baseAddress + GAMEMODE_OFFSET), &currentGamemode, sizeof(currentGamemode), nullptr);
	currentGamemode = (currentGamemode & 0xFFFFFF00) | newGamemode;

	WriteProcessMemory(handle, LPVOID(baseAddress + GAMEMODE_OFFSET), &currentGamemode, sizeof(currentGamemode), nullptr);

}