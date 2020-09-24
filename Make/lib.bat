@echo off
%comspec% /c ""c:\Program Files (x86)\Microsoft Visual Studio\2019\Preview\VC\Auxiliary\Build\vcvarsall.bat" >NUL amd64 && lib.exe %*"
