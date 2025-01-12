@echo off
SETLOCAL EnableDelayedExpansion

@ECHO OFF&(PUSHD "%~DP0")&(REG QUERY "HKU\S-1-5-19">NUL 2>&1)||(
powershell -Command "Start-Process '%~sdpnx0' -Verb RunAs"&&EXIT)
:: ��ȡ��ǰ�ű����ڵ�Ŀ¼
:: Get the directory where the script is located
SET "CURRENT_DIR=%~dp0"

:: ע�� 7zADP.dll
:: Register the 7zADP.dll
IF EXIST "%CURRENT_DIR%7zADP.dll" (
    echo ����ע�� 7zADP.dll...
    echo Registering 7zADP.dll...
    echo.
    regsvr32 /s "%CURRENT_DIR%7zADP.dll"
    IF %ERRORLEVEL% EQU 0 (
        echo 7zADP.dll ע��ɹ���
        echo 7zADP.dll registration successful.
        echo.
    ) ELSE (
        echo ע�� 7zADP.dll ʧ�ܡ�
        echo Failed to register 7zADP.dll.
        echo.
    )
) ELSE (
    echo �Ҳ��� 7zADP.dll �ļ���
    echo 7zADP.dll file not found.
    echo.
)

:: ������ע����в��� 7-Zip ��װ·��
:: Attempt to find the 7-Zip installation path in the registry
echo �������� 7-Zip ��װ·��...
echo Searching for 7-Zip installation path...
echo.

:: ͨ��ע������� 7-Zip ��װ·��
:: Search for 7-Zip installation path via registry
SET "REG_PATH=HKLM\SOFTWARE\7-Zip"
SET "REG_KEY=Path"
FOR /F "tokens=2,*" %%A IN ('reg query "%REG_PATH%" /v "%REG_KEY%" 2^>nul') DO SET "INSTALL_PATH=%%B"

IF NOT DEFINED INSTALL_PATH (
    SET "REG_PATH=HKCU\SOFTWARE\7-Zip"
    FOR /F "tokens=2,*" %%A IN ('reg query "%REG_PATH%" /v "%REG_KEY%" 2^>nul') DO SET "INSTALL_PATH=%%B")

:: �ж��Ƿ��ҵ��� 7-Zip ��װ·��
:: Check if the 7-Zip installation path was found
IF DEFINED INSTALL_PATH (
    echo �ҵ� 7-Zip ��װ·��: %INSTALL_PATH%
    echo 7-Zip installation path found: %INSTALL_PATH%
    echo.
    
    :: ���·���� config.ini
    :: Write the path to config.ini
    echo [Settings] > "%CURRENT_DIR%config.ini"
    echo 7zPath=%INSTALL_PATH%7z.exe >> "%CURRENT_DIR%config.ini"
    echo ExtraParams=-mx=9 -mmt=4 >> "%CURRENT_DIR%config.ini"

    echo 7zPath ��д�� config.ini �ļ���
    echo 7zPath has been written to config.ini.
) ELSE (
    echo δ���ҵ� 7-Zip ��װ·������ȷ�� 7-Zip ����ȷ��װ��
    echo Could not find 7-Zip installation path, please ensure 7-Zip is correctly installed.
    echo.
)

echo.
pause
ENDLOCAL
