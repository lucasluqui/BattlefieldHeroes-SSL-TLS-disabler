#include "InjectionMethod.h"
#include <string>
using namespace std;

int main(int argc, TCHAR *argv[])
{
	bool done = false;
	char szProc[MAX_PATH], szDll[MAX_PATH];
	char* szDllPath1 = (char*)malloc(MAX_PATH);
	char* szExePath1 = (char*)malloc(MAX_PATH);
	char* szDll1 = "Hook.dll";
	szDllPath1 = GetCurrentDir();
	strcat_s(szDllPath1, MAX_PATH, "\\");
	strcat_s(szDllPath1, MAX_PATH, szDll1);

	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;

	if (CreateProcess(argv[1], argv[2], NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}

	if (InjectDll(processInfo.dwProcessId, szDllPath1))
	{
		done = true;
	}

	if (!done) { std::cout << " > Injection failed!" << std::endl; }
	system("pause");
	return 0;
}