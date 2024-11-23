#include <cctype>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

int get_minute() {
    time_t now = time(0);
    tm* local_time = localtime(&now);
    return local_time->tm_min;
}

char calcChecksum(ifstream* inputFile, bool timeDependent) {
    char ch;
    unsigned char checksum = 0;
    unsigned long long index = 0;

    while (inputFile->get(ch)) {

        checksum += ((unsigned char)ch * (index + 1));
        index++;
    }

    if (timeDependent) {
        checksum += get_minute() % 2; // Добавляем текущее время
    }

    inputFile->clear();
    inputFile->seekg(0, ios_base::beg);

    return (char)checksum;
}

int main() {
    // Открываем файл
    ifstream inputFile; // Создаем объект ifstream
    inputFile.open("C:\\c++\\input.txt");
    // Вызываем функцию calcChecksum
    char checksum = calcChecksum(&inputFile, false); // false - не зависит от времени

    if (checksum == 0) {
        cout << "Error open file" << endl; // Используем cout вместо wcout
    } else {
        // Выводим контрольную сумму
        cout << "Control sum: " << (int)(unsigned char)checksum << endl;
    }

    // Закрываем файл и освобождаем память
    inputFile.close();
    return 0;
    
}



