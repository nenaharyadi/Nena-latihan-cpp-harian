/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 3 Oktober 2025
Deskripsi : menampilkna waktu local dan utc tiap 5 menit
*/

#include <iostream>
#include <ctime>
#include <thread>
using namespace std;

int main() {
    int last_minute = -1; 
    while(true){
        time_t now = time(0);
        tm localTime = *localtime(&now);
        tm utcTime   = *gmtime(&now);

        if(localTime.tm_min % 5 == 0 && localTime.tm_sec == 0 && localTime.tm_min != last_minute){
            char bufLocal[20], bufUTC[20];

            strftime(bufLocal, sizeof(bufLocal), "%H:%M:%S", &localTime);
            strftime(bufUTC, sizeof(bufUTC), "%H:%M:%S", &utcTime);

            cout << "Local Time : " << bufLocal << endl;
            cout << "UTC Time   : " << bufUTC << endl;
            cout << "---------------------" << endl;

            last_minute = localTime.tm_min;
        }

        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}

