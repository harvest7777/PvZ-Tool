#pragma once
#include <Windows.h>
class Level
{
private:
	HANDLE handle;
	DWORD baseAddress;

	//Sun address is a multi level pointer which is not constructed from base class
	//Must follow pointer path at runtime
	DWORD SUN_ADDRESS; 

	const DWORD COOLDOWN_OFFSET = 0x91E55;
	const DWORD ORIGINAL_COOLDOWN_INSTRUCTION = 0x47C7147E;
	const DWORD NO_COOLDOWN_INSTRUCTION = 0x47C79090;

	const DWORD PLANT_DAMAGE_OFFSET = 0x140680;
	const DWORD ORIGINAL_PLANT_DAMAGE_INSTRUCTION = 0xFC404683;
	const DWORD NO_PLANT_DAMAGE_INSTRUCTION = 0x90909090;

	//the way this works is by checking if your gamemode == 27
	//will set cf if equal
	//jne (zf=0) if the gamemode is not 27, normal plant. if 27, skip the jne and row plant
	//we want to force skip the zf check
	const DWORD ROW_PLANT_OFFSET = 0x134A7;
	const DWORD ORINGINAL_PLANT_DECISION_INSTRUCTION = 0x00E3850F;
	const DWORD ROW_PLANT_DECISION_INSTRUCTION = 0x00E3840F;

	const DWORD GAMEMODE_OFFSET = 0x134A6;
public:
	Level(HANDLE hndl, DWORD baseAddr);

	void setSun(int newSun);
	int getSun();
	void refreshSunAddress();

	void enableNoCoolDown();
	void disableNoCooldown();

	void enableNoPlantDamage();
	void disableNoPlantDamage();

	void enableRowPlant();
	void disableRowPlant();
};

