@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "ROOT=%~dp0"
set "DEFAULT_PREFIX=%ProgramFiles%\Lucy"
if "%LUCY_PREFIX%"=="" set "LUCY_PREFIX=%DEFAULT_PREFIX%"
if "%LUCY_BUILD_DIR%"=="" set "LUCY_BUILD_DIR=%ROOT%build-install"

where cmake >nul 2>&1
if errorlevel 1 (
  echo CMake is required. Install CMake and a C++17 compiler first.
  exit /b 1
)

rem Test whether the selected installation prefix is writable.
if not exist "%LUCY_PREFIX%" mkdir "%LUCY_PREFIX%" >nul 2>&1
set "WRITE_TEST=%LUCY_PREFIX%\.lucy-write-test-%RANDOM%"
>"%WRITE_TEST%" echo test
if errorlevel 1 (
  if /I "%LUCY_PREFIX%"=="%DEFAULT_PREFIX%" (
    set "LUCY_PREFIX=%LocalAppData%\Lucy"
    if not exist "%LUCY_PREFIX%" mkdir "%LUCY_PREFIX%" >nul 2>&1
    if errorlevel 1 (
      echo Cannot create the user Lucy installation directory.
      exit /b 1
    )
    echo Program Files is not writable; using !LUCY_PREFIX! instead.
  ) else (
    echo Installation prefix is not writable: %LUCY_PREFIX%
    exit /b 1
  )
) else (
  del /q "%WRITE_TEST%" >nul 2>&1
)

rem Let CMake select the native Windows generator. Override with LUCY_CMAKE_GENERATOR if needed.
if "%LUCY_CMAKE_GENERATOR%"=="" (
  cmake -S "%ROOT%" -B "%LUCY_BUILD_DIR%" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="%LUCY_PREFIX%"
) else (
  cmake -S "%ROOT%" -B "%LUCY_BUILD_DIR%" -G "%LUCY_CMAKE_GENERATOR%" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="%LUCY_PREFIX%"
)
if errorlevel 1 exit /b 1

cmake --build "%LUCY_BUILD_DIR%" --config Release
if errorlevel 1 exit /b 1
ctest --test-dir "%LUCY_BUILD_DIR%" -C Release --output-on-failure
if errorlevel 1 exit /b 1
cmake --install "%LUCY_BUILD_DIR%" --config Release
if errorlevel 1 exit /b 1

rem Add Lucy to the current user's PATH without requiring administrator rights.
set "PATH=%LUCY_PREFIX%;%PATH%"
powershell -NoProfile -ExecutionPolicy Bypass -Command "$p=[Environment]::GetEnvironmentVariable('Path','User'); $d='%LUCY_PREFIX%'; if (-not (($p -split ';') -contains $d)) { [Environment]::SetEnvironmentVariable('Path', (($p.TrimEnd(';') + ';' + $d).Trim(';')), 'User') }" >nul 2>&1

echo.
echo Lucy 1.0.0 installed successfully.
echo Binary: %LUCY_PREFIX%\lucy.exe
echo Stdlib: %LUCY_PREFIX%\stdlib
echo Editors: %LUCY_PREFIX%\editors
echo.
echo The standard library is resolved relative to lucy.exe, so the Lucy folder can be moved safely.
echo Restart your terminal once if the lucy command is not found yet.
endlocal
