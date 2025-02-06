@echo off
title #1 Skid - Fraden1
color 1
SET TempVBSFile=%temp%\~tmpSendKeysTemp.vbs
IF EXIST "%TempVBSFile%" DEL /F /Q "%TempVBSFile%"
ECHO Set WshShell = WScript.CreateObject("WScript.Shell") >>"%TempVBSFile%"
ECHO Wscript.Sleep 1                                    >>"%TempVBSFile%"
ECHO WshShell.SendKeys "{F11}"                            >>"%TempVBSFile%"
ECHO Wscript.Sleep 1                                    >>"%TempVBSFile%"

CSCRIPT //nologo "%TempVBSFile%"

:start
cls
echo      :::::::::  :::            :::     ::::::::: ::::::::::          :::    ::: :::       ::: ::::::::::: :::::::::          ::::::::  :::    ::: :::::::::: ::::::::  :::    ::: :::::::::: ::::::::: 
echo     :+:    :+: :+:          :+: :+:        :+:  :+:                 :+:    :+: :+:       :+:     :+:     :+:    :+:        :+:    :+: :+:    :+: :+:       :+:    :+: :+:   :+:  :+:        :+:    :+: 
echo    +:+    +:+ +:+         +:+   +:+      +:+   +:+                 +:+    +:+ +:+       +:+     +:+     +:+    +:+        +:+        +:+    +:+ +:+       +:+        +:+  +:+   +:+        +:+    +:+  
echo   +#++:++#+  +#+        +#++:++#++:    +#+    +#++:++#            +#++:++#++ +#+  +:+  +#+     +#+     +#+    +:+        +#+        +#++:++#++ +#++:++#  +#+        +#++:++    +#++:++#   +#++:++#:    
echo  +#+    +#+ +#+        +#+     +#+   +#+     +#+                 +#+    +#+ +#+ +#+#+ +#+     +#+     +#+    +#+        +#+        +#+    +#+ +#+       +#+        +#+  +#+   +#+        +#+    +#+    
echo #+#    #+# #+#        #+#     #+#  #+#      #+#                 #+#    #+#  #+#+# #+#+#      #+#     #+#    #+#        #+#    #+# #+#    #+# #+#       #+#    #+# #+#   #+#  #+#        #+#    #+#     
echo #########  ########## ###     ### ######### ##########          ###    ###   ###   ###   ########### #########          ########  ###    ### ########## ########  ###    ### ########## ###    ###      
echo.
echo.
echo [96m[1] Check Your Serials
echo [96m[2] Our Informations
echo [96m[0] Exit
echo.
set /p choice="Choose A Option (1/2/0): "

if "%choice%"=="1" (
    call :show_serials
) else if "%choice%"=="2" (
    call :show_info
) else if "%choice%"=="0" (
    exit
) else (
    echo Option Non Valid. Try Again.
    pause
color 1
    goto start
)

:show_serials
for /f "tokens=1 delims=," %%a in ('curl -silent api.ipify.org') do (set PublicIP=%%a)

for /f "tokens=2 delims=:" %%G in ('ipconfig ^| findstr /i "IPv4 Address"') do (set "PrivateIP=%%G")

cls
echo [94m                                 YOUR SERIALS:                  
echo [93mMotherboard
echo [97m
wmic baseboard get product,Manufacturer,serialnumber,version
echo [90mChassis
echo [97m
wmic systemenclosure get serialnumber
echo [96mBIOS
echo [97m
wmic bios get manufacturer,serialnumber,releasedate
wmic csproduct get name,vendor,uuid
echo [94mCPU
echo [97m
wmic cpu get Name, Caption
wmic cpu get socketdesignation, processorid, SerialNumber
echo [92mGPU
echo [97m
set "gpu="
for /f "tokens=2 delims==" %%i in ('wmic path win32_VideoController get name /format:list ^| find "Name"') do (
    set "gpu=%%i"
)
echo %gpu% | findstr /i "NVIDIA" >nul
if %errorlevel% equ 0 (
   wmic path win32_VideoController get pnpdeviceid
   nvidia-smi -L
   echo.
) else (
  wmic path win32_VideoController get pnpdeviceid
  echo.
  wmic path win32_VideoController get name,driverversion
)
endlocal
echo [91mVolumeID(s):
echo [97m
wmic logicaldisk get name,volumeserialnumber
wmic diskdrive get Model, SerialNumber
echo [96mProductID
echo [97m
wmic OS GET Caption,SerialNumber,CSName,Version
wmic computersystem get PrimaryOwnerName      
echo [95mNetwork
echo.      
echo.[97mPublicIP        PrivateIP
echo.%PublicIP% %PrivateIP%
echo.
echo.[97mARP Information:
arp -a
echo.
getmac /fo csv /nh
echo.
echo.
echo [93mPress 1 to Refresh Your Serials or 0 to go back to the Main Menu...                                                                         
set /p refresh_choice="Your choice: "
:: echo [94m
color 1
if "%refresh_choice%"=="1" (
    goto show_serials
) else if "%refresh_choice%"=="0" (
    goto start
) else (
    echo Invalid choice, please press 1 to Refresh Your Serials or 0 to go back to the Main Menu.
    pause
    goto show_serials
)
cls

:show_info
cls
color 1
echo         :::   :::       :::     :::::::::  ::::::::::          :::::::::  :::   :::          :::::::::: :::::::::      :::     :::::::::  :::::::::: ::::    :::   ::: 
echo       :+:+: :+:+:    :+: :+:   :+:    :+: :+:                 :+:    :+: :+:   :+:          :+:        :+:    :+:   :+: :+:   :+:    :+: :+:        :+:+:   :+: :+:+:  
echo     +:+ +:+:+ +:+  +:+   +:+  +:+    +:+ +:+                 +:+    +:+  +:+ +:+           +:+        +:+    +:+  +:+   +:+  +:+    +:+ +:+        :+:+:+  +:+   +:+   
echo    +#+  +:+  +#+ +#++:++#++: +#+    +:+ +#++:++#            +#++:++#+    +#++:            :#::+::#   +#++:++#:  +#++:++#++: +#+    +:+ +#++:++#   +#+ +:+ +#+   +#+    
echo   +#+       +#+ +#+     +#+ +#+    +#+ +#+                 +#+    +#+    +#+             +#+        +#+    +#+ +#+     +#+ +#+    +#+ +#+        +#+  +#+#+#   +#+     
echo  #+#       #+# #+#     #+# #+#    #+# #+#                 #+#    #+#    #+#             #+#        #+#    #+# #+#     #+# #+#    #+# #+#        #+#   #+#+#   #+#      
echo ###       ### ###     ### #########  ##########          #########     ###             ###        ###    ### ###     ### #########  ########## ###    #### #######     
echo.
echo [96m[+] Created For discord.gg/blazeai
echo [96m[+] My Bios fakecrime.bio/fraden1
echo.
echo [97m==============================================================================[97m
echo [94m[+] Press a Key to go back to the Main Menu...
pause>nul
color 1
goto start
