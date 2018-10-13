//

#include <Windows.h>

constexpr long MonitorPowerOn = -1;
constexpr long MonitorLowPower = 1;
constexpr long MonitorPowerOff = 2;

int wmain()
{
	int result = 0;

	HWND hWnd = FindWindow(nullptr, nullptr);

	BOOL success = LockWorkStation();
	if (success == TRUE)
	{
		SendMessage(hWnd, WM_SYSCOMMAND, SC_MONITORPOWER, MonitorPowerOff);
	}
	return result;
}
