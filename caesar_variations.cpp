#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

//ИМЯ ФУНКЦИИ ДОЛЖНО СОТВЕТСТВОВАТЬ КОНКРЕТНОЙ ВАРИАЦИИ ИЗ ФАЙЛА
// Для шифра Ш1.1.1 - v1_1_1

int v1_1_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = 3; offset.kir = 5; offset.num = 2;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

int v1_1_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = -3; offset.kir = -5; offset.num = -2;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

/*
int time_based_decorator(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();  // Получаем текущий день недели
    int minute = get_minute();      // Получаем текущую минуту
    int day_of_month = get_mouth_day();  // Получаем текущий день месяца

    if (minute%2 == 0)
    {
        offset.lat += 3;
        offset.kir += 5;
        offset.num += 3;
        cout << "День недели: " << week_day << ", Сдвиг по латинице вправо на " << 3 << endl;
        cout << "Минуты: " << minute << ", Сдвиг для кириллицы вправо на " << 5 << endl;
        cout << "День месяца: " << day_of_month << ", Сдвиг для чисел вправо на " << 3 << endl;
    }
    else
    {
        offset.lat += 4;
        offset.kir += 6;
        offset.num += 2;
        cout << "День недели: " << week_day << ", Сдвиг по латинице вправо на " << 4 << endl;
        cout << "Минуты: " << minute << ", Сдвиг для кириллицы вправо на " << 6 << endl;
        cout << "День месяца: " << day_of_month << ", Сдвиг для чисел вправо на " << 2 << endl;
    }

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}
*/
