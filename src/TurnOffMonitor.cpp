// Lock workstation and turn off monitor(s)

#include <Windows.h>

constexpr long MonitorPowerOn = -1;
constexpr long MonitorLowPower = 1;
constexpr long MonitorPowerOff = 2;

int wmain()
{
	bool lockWorkstation = true;
	size_t retries = 2;
	DWORD delayBeforeRetry = 2000;

	HWND hWnd = FindWindow(nullptr, nullptr);

	if (lockWorkstation)
	{
		LockWorkStation();
	}
	for (size_t retry = 0; retry < retries; retry++)
	{
		SendMessageW(hWnd, WM_SYSCOMMAND, SC_MONITORPOWER, MonitorPowerOff);

		if (delayBeforeRetry > 0)
		{
			Sleep(delayBeforeRetry);
		}
	}

	return 0;
}
