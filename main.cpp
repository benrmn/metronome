#include <iostream>
#include <time.h>
#include <windows.h>

void delay(int del) {
    clock_t start = clock();
    while (clock() < start + del)
        ;
}

int main() {
    int bpm;
    int t;
    std::string sbpm;
    std::string ts;
    std::cout << "Enter BPM:";
    std::cin >> sbpm;
    std::cout << "For how long (seconds):";
    std::cin >> ts;
    try {
        bpm = std::stoi(sbpm);
        t = std::stoi(ts);
    } catch (const std::exception& e) {
        std::cout << "Please enter valid bpm" << std::endl;
    }
    double increment = (60 / double(bpm));
    double mili = 1000 * increment;
    std::ios_base::sync_with_stdio(false);
    for (int i = 0; i < t; i++) {
        delay(int(mili));
        Beep(523, 250);
    }
    return 0;
}
