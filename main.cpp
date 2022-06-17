#include <windows.h>
#include "mem.h"
#include "classes.h"
#include <iostream>

using namespace std;

int main()
{
	uintptr_t moduleBase = GetModuleBaseAddress(GetProcId(L"Among Us.exe"), L"GameAssembly.dll");
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, GetProcId(L"Among Us.exe"));
	uintptr_t localPointer = moduleBase + 0x01C83F10;
	uintptr_t killCooldown = FindDMAAddy(hProcess, localPointer, { 0x5c, 0x6c, 0x10 });
	uintptr_t killDistance = FindDMAAddy(hProcess, localPointer, { 0x5c, 0x6c, 0x0C });
	uintptr_t velocity = FindDMAAddy(hProcess, localPointer, { 0x5c, 0x6c, 0x08 });
	uintptr_t tripulationVision = FindDMAAddy(hProcess, localPointer, { 0x5c, 0x6c, 0x48 });
	uintptr_t impostorVision = FindDMAAddy(hProcess, localPointer, { 0x5c, 0x6c, 0x4C });
	uintptr_t confirmEject = FindDMAAddy(hProcess, localPointer, { 0x5c, 0x6c, 0x50 });
	//uintptr_t impostorVision = FindDMAAddy(hProcess, localPointer, { 0x5c, 0x6c, 0x4C });

	int iZero = 0;
	float fZero = 0.f;
	float newVision = 30.f;
	int newconfirmEject = 1;
	float newVellocity = 3.f;
	int newkillDistance = 2;

	bool killCdr = false;
	bool killDis = false;
	bool tVision = false;
	bool iVision = false;
	bool cEject = false;
	bool velo = false;



	while (true)
	{

		cout << "Sus hack" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "Kills Hacks ";

		if (killCdr)
		{
			cout << "[ON]" << endl;
			cout << "" << endl;
			cout << "" << endl;
		}
		else
		{
			cout << "[OFF]" << endl;
			cout << "" << endl;
			cout << "" << endl;
		}

		cout << "Vision Hacks ";

		if (tVision)
		{
			cout << "[ON]" << endl;
			cout << "" << endl;
			cout << "" << endl;
		}
		else
		{
			cout << "[OFF]" << endl;
			cout << "" << endl;
			cout << "" << endl;
		}

		cout << "Confirm Eject Hack ";

		if (cEject)
		{
			cout << "[ON]" << endl;
		}
		else
		{
			cout << "[OFF]" << endl;
		}
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "Copyright Staayzinho balaclava 2022" << endl;
		system("cls");

		if (GetAsyncKeyState(VK_F1) & 1)
		{
			killCdr = !killCdr;
			killDis = !killDis;
		}

		if (GetAsyncKeyState(VK_F2) & 1)
		{
			tVision = !tVision;
			iVision = !iVision;
		}

		if (GetAsyncKeyState(VK_F3) & 1)
		{
			cEject = !cEject;
		}

		if (killCdr && killDis)
		{
			WriteProcessMemory(hProcess, (BYTE*)killCooldown, &iZero, sizeof(iZero), nullptr);
			WriteProcessMemory(hProcess, (BYTE*)killDistance, &newkillDistance, sizeof(newkillDistance), nullptr);
		}
		
		if (iVision && tVision)
		{
			WriteProcessMemory(hProcess, (BYTE*)tripulationVision, &newVision, sizeof(newVision), nullptr);
			WriteProcessMemory(hProcess, (BYTE*)impostorVision, &newVision, sizeof(newVision), nullptr);
		}

		if (cEject)
		{
			WriteProcessMemory(hProcess, (BYTE*)confirmEject, &newconfirmEject, sizeof(newconfirmEject), nullptr);
		}


	}

	return 0;
}