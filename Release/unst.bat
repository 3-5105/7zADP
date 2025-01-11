@echo off
SETLOCAL EnableDelayedExpansion

@ECHO OFF&(PUSHD "%~DP0")&(REG QUERY "HKU\S-1-5-19">NUL 2>&1)||(
powershell -Command "Start-Process '%~sdpnx0' -Verb RunAs"&&EXIT)

:: 获取当前脚本所在的目录
:: Get the directory of the current script
SET "CURRENT_DIR=%~dp0"

:: 注销 7zADP.dll
:: Unregister the 7zADP.dll
IF EXIST "%CURRENT_DIR%7zADP.dll" (
    echo.
    echo 正在注销 7zADP.dll...
    echo Unregistering 7zADP.dll...
    regsvr32 /u /s "%CURRENT_DIR%7zADP.dll"
    IF %ERRORLEVEL% EQU 0 (
        echo.
        echo 7zADP.dll 注销成功。
        echo 7zADP.dll unregistered successfully.
        goto s
        
    ) ELSE (
        echo.
        echo 注销 7zADP.dll 失败。
        echo Failed to unregister 7zADP.dll.
    )
) ELSE (
    echo 找不到 7zADP.dll 文件。
    echo 7zADP.dll file not found.
)
echo.
pause
exit

:s
        :: 提示用户是否立即重启文件资源管理器
        set /p RESTART="需要重启文件资源管理器或注销方可完全卸载，是否立即重启文件资源管理器? (Y/N): "
        IF /i "%RESTART%"=="Y" (
            echo 正在重启文件资源管理器...
            taskkill /f /im explorer.exe
            start explorer.exe
            echo 文件资源管理器已重启。
        ) ELSE (
            echo 文件资源管理器没有重启。
        )
exit

ENDLOCAL