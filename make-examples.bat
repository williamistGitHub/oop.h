@echo off

:: Do not update on library version update! This is a build script version number, not the library one.
echo oop.h example build script (v1.0)
echo ==================================

setlocal

:: Different build modes
set debugFlag=
if /i "%1"=="debug" (
    echo Debug builds enabled!
    set debugFlag=-g
)

if /i "%1"=="clean" (
    del /q /s build.exe
    echo Cleaned!
    exit /b
)

:: Restaurant Menu
gcc -Iexamples\restaurant-menu -I. -Wall %debugFlag% examples\restaurant-menu\main.c examples\restaurant-menu\CMenu.c -o examples\restaurant-menu\build.exe

:: Extending Classes
gcc -Iexamples\extending-classes -I. -Wall %debugFlag% examples\extending-classes\main.c examples\extending-classes\CBase.c examples\extending-classes\CExtending.c -o examples\extending-classes\build.exe

echo Built!

endlocal