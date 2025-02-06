#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <fstream>
#include <cstdio>
#include <windows.h>

using namespace std;

bool is_nvidia_gpu_present() {
    FILE* fp = _popen("wmic path win32_VideoController get name", "r");
    if (fp == nullptr) {
        cout << "Error of Execution of The Command WMIC.\n";
        return false;
    }

    char buffer[256];
    bool found_nvidia = false;
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, "NVIDIA")) {
            found_nvidia = true;
            break;
        }
    }

    fclose(fp);
    return found_nvidia;
}

void show_serials() {
    system("cls");

    cout << "\033[94m                                 YOUR SERIALS:\n";
    cout << "\033[93mMotherboard\n\033[97m";
    system("wmic baseboard get product,Manufacturer,serialnumber,version");

    cout << "\033[90mChassis\n\033[97m";
    system("wmic systemenclosure get serialnumber");

    cout << "\033[96mBIOS\n\033[97m";
    system("wmic bios get manufacturer,serialnumber,releasedate");
    system("wmic csproduct get name,vendor,uuid");

    cout << "\033[94mCPU\n\033[97m";
    system("wmic cpu get Name, Caption");
    system("wmic cpu get socketdesignation, processorid, SerialNumber");

    cout << "\033[92mGPU\n\033[97m";

    if (is_nvidia_gpu_present()) {
        cout << "\nNVIDIA GPU found!\n" << endl;
        system("wmic path win32_VideoController get pnpdeviceid");
        system("nvidia-smi -L");
    }
    else {
        cout << "\nNo NVIDIA GPU detected.\n" << endl;
        system("wmic path win32_VideoController get pnpdeviceid");
    }

    cout << "\033[91mVolumeID(s):\n\033[97m";
    system("wmic logicaldisk get name,volumeserialnumber");
    system("wmic diskdrive get Model, SerialNumber");

    cout << "\033[96mProductID\n\033[97m";
    system("wmic OS GET Caption,SerialNumber,CSName,Version");
    system("wmic computersystem get PrimaryOwnerName");

    cout << "\033[95mNetwork\n\033[97m";

    cout << "PublicIP: ";
    system("curl -s https://api.ipify.org");
    cout << endl;

    system("ipconfig | findstr /i \"IPv4\" > ipconfig_output.txt");

    ifstream file("ipconfig_output.txt");
    string line;

    if (getline(file, line)) {
        size_t pos = line.find(":") + 2;
        string ip = line.substr(pos);
        cout << "PrivateIP: " << ip << "\n" << endl;
    }
    cout << "Arp Information:"<<endl;
    system("arp -a");
    system("getmac /fo csv /nh");
    cout << "\n";
    cout << "\033[93mPress 1 to Refresh Your Serials or 0 to go back to the Main Menu...\n\033[93mYour Choice: ";
    int choice;
    while (!(cin >> choice) || (choice != 0 && choice != 1)) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "\033[93mYour Choice: ";
    }
    system("color 1");
    if (choice == 1) show_serials();
    if (choice == 0) system("cls");system("color 1");
}


void show_info() {
    system("cls");
    system("color 1");
    cout << "         :::   :::       :::     :::::::::  ::::::::::          :::::::::  :::   :::          :::::::::: :::::::::      :::     :::::::::  :::::::::: ::::    :::   ::: \n";
    cout << "       :+:+: :+:+:    :+: :+:   :+:    :+: :+:                 :+:    :+: :+:   :+:          :+:        :+:    :+:   :+: :+:   :+:    :+: :+:        :+:+:   :+: :+:+:  \n";
    cout << "     +:+ +:+:+ +:+  +:+   +:+  +:+    +:+ +:+                 +:+    +:+  +:+ +:+           +:+        +:+    +:+  +:+   +:+  +:+    +:+ +:+        :+:+:+  +:+   +:+   \n";
    cout << "    +#+  +:+  +#+ +#++:++#++: +#+    +:+ +#++:++#            +#++:++#+    +#++:            :#::+::#   +#++:++#:  +#++:++#++: +#+    +:+ +#++:++#   +#+ +:+ +#+   +#+    \n";
    cout << "   +#+       +#+ +#+     +#+ +#+    +#+ +#+                 +#+    +#+    +#+             +#+        +#+    +#+ +#+     +#+ +#+    +#+ +#+        +#+  +#+#+#   +#+     \n";
    cout << "  #+#       #+# #+#     #+# #+#    #+# #+#                 #+#    #+#    #+#             #+#        #+#    #+# #+#     #+# #+#    #+# #+#        #+#   #+#+#   #+#      \n";
    cout << " ###       ### ###     ### #########  ##########          #########     ###             ###        ###    ### ###     ### #########  ########## ###    #### #######     \n";

    cout << "\033[96m[+] Created For discord.gg/blazeai\n";
    cout << "\033[96m[+] My Bios fakecrime.bio/fraden1\n";
    cout << "\n\033[97m==============================================================================\033[97m\n";
    cout << "\033[94m[+] Press a Key to go back to the Main Menu...\n";
    cin.ignore();
    cin.get();
    system("color 1");
    system("cls");
    system("color 1");
}

int main() {
    HWND hwnd = GetConsoleWindow();ShowWindow(hwnd, SW_MAXIMIZE);

    string choice;

    system("cls");
    system("title #1 Skid - Fraden1");
    system("color 1");

    while (true) {
        cout << "        n:::::::  :::            :::     ::::::::: ::::::::::          :::    ::: :::       ::: ::::::::::: :::::::::          ::::::::  :::    ::: :::::::::: ::::::::  :::    ::: :::::::::: ::::::::: \n";
        cout << "      :+:    :+: :+:          :+: :+:        :+:  :+:                 :+:    :+: :+:       :+:     :+:     :+:    :+:        :+:    :+: :+:    :+: :+:       :+:    :+: :+:   :+:  :+:        :+:    :+: \n";
        cout << "     +:+    +:+ +:+         +:+   +:+      +:+   +:+                 +:+    +:+ +:+       +:+     +:+     +:+    +:+        +:+        +:+    +:+ +:+       +:+        +:+  +:+   +:+        +:+    +:+  \n";
        cout << "    +#++:++#+  +#+        +#++:++#++:    +#+    +#++:++#            +#++:++#++ +#+  +:+  +#+     +#+     +#+    +:+        +#+        +#++:++#++ +#++:++#  +#+        +#++:++    +#++:++#   +#++:++#:    \n";
        cout << "   +#+    +#+ +#+        +#+     +#+   +#+     +#+                 +#+    +#+ +#+ +#+#+ +#+     +#+     +#+    +#+        +#+        +#+    +#+ +#+       +#+        +#+  +#+   +#+        +#+    +#+    \n";
        cout << "  #+#    #+# #+#        #+#     #+#  #+#      #+#                 #+#    #+#  #+#+# #+#+#      #+#     #+#    #+#        #+#    #+# #+#    #+# #+#       #+#    #+# #+#   #+#  #+#        #+#    #+#     \n";
        cout << " #########  ########## ###     ### ######### ##########          ###    ###   ###   ###   ########### #########          ########  ###    ### ########## ########  ###    ### ########## ###    ###  \n";
        cout << "\033[96m[1] Check Your Serials\n";
        cout << "\033[96m[2] Our Informations\n";
        cout << "\033[96m[0] Exit\n";
        cout << "\nChoose A Option (1/2/0): ";
        cin >> choice;

        if (choice == "1") {
            show_serials();
        }
        else if (choice == "2") {
            show_info();
        }
        else if (choice == "0") {
			exit(0);
        }
        else {
            cout << "Option Non Valid. Try Again.\n";
            system("cls");
            system("color 1");
        }
    }

    return 0;
}
