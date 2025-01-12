@echo off
SETLOCAL EnableDelayedExpansion

@ECHO OFF&(PUSHD "%~DP0")&(REG QUERY "HKU\S-1-5-19">NUL 2>&1)||(
powershell -Command "Start-Process '%~sdpnx0' -Verb RunAs"&&EXIT)
:: 获取当前脚本所在的目录
:: Get the directory where the script is located
SET "CURRENT_DIR=%~dp0"

:: 注册 7zADP.dll
:: Register the 7zADP.dll
IF EXIST "%CURRENT_DIR%7zADP.dll" (
    echo 正在注册 7zADP.dll...
    echo Registering 7zADP.dll...
    echo.
    regsvr32 /s "%CURRENT_DIR%7zADP.dll"
    IF %ERRORLEVEL% EQU 0 (
        echo 7zADP.dll 注册成功。
        echo 7zADP.dll registration successful.
        echo.
    ) ELSE (
        echo 注册 7zADP.dll 失败。
        echo Failed to register 7zADP.dll.
        echo.
    )
) ELSE (
    echo 找不到 7zADP.dll 文件。
    echo 7zADP.dll file not found.
    echo.
)

:: 尝试在注册表中查找 7-Zip 安装路径
:: Attempt to find the 7-Zip installation path in the registry
echo 正在搜索 7-Zip 安装路径...
echo Searching for 7-Zip installation path...
echo.

:: 通过注册表搜索 7-Zip 安装路径
:: Search for 7-Zip installation path via registry
SET "REG_PATH=HKLM\SOFTWARE\7-Zip"
SET "REG_KEY=Path"
FOR /F "tokens=2,*" %%A IN ('reg query "%REG_PATH%" /v "%REG_KEY%" 2^>nul') DO SET "INSTALL_PATH=%%B"

IF NOT DEFINED INSTALL_PATH (
    SET "REG_PATH=HKCU\SOFTWARE\7-Zip"
    FOR /F "tokens=2,*" %%A IN ('reg query "%REG_PATH%" /v "%REG_KEY%" 2^>nul') DO SET "INSTALL_PATH=%%B")

:: 判断是否找到了 7-Zip 安装路径
:: Check if the 7-Zip installation path was found
IF DEFINED INSTALL_PATH (
    echo 找到 7-Zip 安装路径: %INSTALL_PATH%
    echo 7-Zip installation path found: %INSTALL_PATH%
    echo.
    
    :: 输出路径到 config.ini
    :: Write the path to config.ini
    echo [Settings] > "%CURRENT_DIR%config.ini"
    echo 7zPath=%INSTALL_PATH%7z.exe >> "%CURRENT_DIR%config.ini"
    echo ExtraParams=-mx=9 -mmt=4 >> "%CURRENT_DIR%config.ini"

    echo 7zPath 已写入 config.ini 文件。
    echo 7zPath has been written to config.ini.
) ELSE (
    echo 未能找到 7-Zip 安装路径，请确保 7-Zip 已正确安装。
    echo Could not find 7-Zip installation path, please ensure 7-Zip is correctly installed.
    echo.
)

echo.
pause
ENDLOCAL
