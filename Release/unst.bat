@echo off
SETLOCAL EnableDelayedExpansion

@ECHO OFF&(PUSHD "%~DP0")&(REG QUERY "HKU\S-1-5-19">NUL 2>&1)||(
powershell -Command "Start-Process '%~sdpnx0' -Verb RunAs"&&EXIT)

:: ��ȡ��ǰ�ű����ڵ�Ŀ¼
:: Get the directory of the current script
SET "CURRENT_DIR=%~dp0"

:: ע�� 7zADP.dll
:: Unregister the 7zADP.dll
IF EXIST "%CURRENT_DIR%7zADP.dll" (
    echo.
    echo ����ע�� 7zADP.dll...
    echo Unregistering 7zADP.dll...
    regsvr32 /u /s "%CURRENT_DIR%7zADP.dll"
    IF %ERRORLEVEL% EQU 0 (
        echo.
        echo 7zADP.dll ע���ɹ���
        echo 7zADP.dll unregistered successfully.
        goto s
        
    ) ELSE (
        echo.
        echo ע�� 7zADP.dll ʧ�ܡ�
        echo Failed to unregister 7zADP.dll.
    )
) ELSE (
    echo �Ҳ��� 7zADP.dll �ļ���
    echo 7zADP.dll file not found.
)
echo.
pause
exit

:s
        :: ��ʾ�û��Ƿ����������ļ���Դ������
        set /p RESTART="��Ҫ�����ļ���Դ��������ע��������ȫж�أ��Ƿ����������ļ���Դ������? (Y/N): "
        IF /i "%RESTART%"=="Y" (
            echo ���������ļ���Դ������...
            taskkill /f /im explorer.exe
            start explorer.exe
            echo �ļ���Դ��������������
        ) ELSE (
            echo �ļ���Դ������û��������
        )
exit

ENDLOCAL