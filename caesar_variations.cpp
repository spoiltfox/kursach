/**
\file
\brief Файл содержащий вариации шифратора

В данный файл выведены все функции вида vX_X_X(ifstream*, wofstream*, offsets),
где Х_Х_Х номер соответствующего шифра из файла с ТЗ.
Каждая функция вызывает caesar(ifstream*, wofstream*, offsets), где через
структуру offsets передаются параметры шифратора
*/

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

//ИМЯ ФУНКЦИИ ДОЛЖНО СОТВЕТСТВОВАТЬ КОНКРЕТНОЙ ВАРИАЦИИ ИЗ ФАЙЛА
// Для шифра Ш1.1.1 - v1_1_1

int v1_1_1(wifstream* input_file, wofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = 3; offset.kir = 5; offset.num = 2;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

int v1_1_2(wifstream* input_file, wofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = -3; offset.kir = -5; offset.num = -2;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

// Ш1.2.1 - однонаправленный сдвиг вправо, зависящий от времени начала шифрования
int v1_2_1(wifstream* input_file, wofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // Четная минута
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетная минута
        offset.lat = 4;
        offset.kir = 6;
        offset.num = 2;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.2 - однонаправленный сдвиг влево, зависящий от времени начала шифрования
int v1_2_2(wifstream* input_file, wofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) {
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else {
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.3 - одинаковый разнонаправленный сдвиг, зависящий от времени начала шифрования
int v1_2_3(wifstream* input_file, wofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // Четная минута - сдвиг вправо
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетная минута - сдвиг влево
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.4 - разнонаправленные сдвиги, зависящие от времени начала шифрования
int v1_2_4(wifstream* input_file, wofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // Четная минута - - сдвиг вправо
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетная минута - - сдвиг влево
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.5: Ш1.2.1 с учётом четности дня месяца (вправо)
int v1_2_5(wifstream* input_file, wofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    if (day_of_month % 2 == 0) { // Четный день месяца
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетный день месяца
        offset.lat = 4;
        offset.kir = 6;
        offset.num = 2;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.6: Ш1.2.2 с учётом четности дня месяца (влево)
int v1_2_6(wifstream* input_file, wofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    if (day_of_month % 2 == 0) { // Четный день месяца
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else { // Нечетный день месяца
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.7: Ш1.2.3 с одинаковыми разнонаправленными сдвигами, зависящими от числа месяца
int v1_2_7(wifstream* input_file, wofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();

    if (day_of_month % 2 == 0) { // Четный день месяца - сдвиг вправо
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетный день месяца - сдвиг влево
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    }

    return caesar(input_file, output_file, offset);
}

// Ш1.2.8: Ш1.2.4 с разными разнонаправленными сдвигами, зависящими от числа месяца
int v1_2_8(wifstream* input_file, wofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    if (day_of_month % 2 == 0) { // Четный день месяца - сдвиг вправо
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетный день месяца - сдвиг влево
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.9: Ш1.2.1 с учётом четности дня недели (вправо)
int v1_2_9(wifstream* input_file, wofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    if (week_day % 2 == 0) { // Четный день недели
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетный день недели
        offset.lat = 4;
        offset.kir = 6;
        offset.num = 2;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.10: Ш1.2.2 с учётом четности дня недели (влево)
int v1_2_10(wifstream* input_file, wofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    if (week_day % 2 == 0) { // Четный день недели
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else { // Нечетный день недели
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.11: Ш1.2.3 с одинаковыми разнонаправленными сдвигами, зависящими от дня недели
int v1_2_11(wifstream* input_file, wofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    if (week_day % 2 == 0) { // Четный день недели - сдвиг вправо
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетный день недели - сдвиг влево
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.2.12: Ш1.2.4 с разными разнонаправленными сдвигами, зависящими от дня недели
int v1_2_12(wifstream* input_file, wofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    if (week_day % 2 == 0) { // Четный день недели - сдвиг вправо
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // Нечетный день недели - сдвиг влево
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}
/*
int time_based_decorator(wifstream* input_file, wofstream* output_file, offsets offset) {
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
//

int v1_3_1(wifstream* input_file, wofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = 3; offset.kir = 5; offset.num = 2; offset.symbol_count_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}
int v1_3_2(wifstream* input_file, wofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = -3; offset.kir = -5; offset.num = -2; offset.symbol_count_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

int v1_4_1(wifstream* input_file, wofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = 3; offset.kir = 5; offset.num = 2; offset.checksum_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}
int v1_4_2(wifstream* input_file, wofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = -3; offset.kir = -5; offset.num = -2; offset.checksum_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

//1.5.1 Ш1.2.1 с полем длины открытого текста
int v1_5_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    int textpole = symboul(ifstream* file);
    int minute = get_minute();
    while (textpole!=0){

        if (minute % 2 == 0) { // Четная минута
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетная минута
            offset.lat = 4;
            offset.kir = 6;
            offset.num = 2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.2 - Ш1.2.2 с полем длины открытого текста
int v1_5_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    int textpole = symboul(ifstream* file);
    int minute = get_minute();
    while (textpole!=0){

        if (minute % 2 == 0) { // Четная минута
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;
            textpole-=1;
        } else { // Нечетная минута
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.3 - Ш1.2.3 с полем длины открытого текста
int v1_5_3(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (minute % 2 == 0) { // Четная минута - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетная минута - сдвиг влево
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.4 - Ш1.2.4 с полем длины открытого текста
int v1_5_4(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (minute % 2 == 0) { // Четная минута - - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетная минута - - сдвиг влево
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.5: Ш1.2.5 с полем длины открытого текста
int v1_5_5(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (day_of_month % 2 == 0) { // Четный день месяца
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетный день месяца
            offset.lat = 4;
            offset.kir = 6;
            offset.num = 2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.6: Ш1.2.6 с полем длины открытого текста
int v1_5_6(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (day_of_month % 2 == 0) { // Четный день месяца
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;
            textpole-=1;
        } else { // Нечетный день месяца
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.7: Ш1.2.7 с полем длины открытого текста
int v1_5_7(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (day_of_month % 2 == 0) { // Четный день месяца - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетный день месяца - сдвиг влево
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.8:Ш1.2.8 с полем длины открытого текста
int v1_5_8(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (day_of_month % 2 == 0) { // Четный день месяца - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетный день месяца - сдвиг влево
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.9: Ш1.2.9 с полем длины открытого текста
int v1_5_9(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (week_day % 2 == 0) { // Четный день недели
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетный день недели
            offset.lat = 4;
            offset.kir = 6;
            offset.num = 2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.10: Ш1.2.10 с полем длины открытого текста
int v1_5_10(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (week_day % 2 == 0) { // Четный день недели
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;
            textpole-=1;
        } else { // Нечетный день недели
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.11: Ш1.2.11 с полем длины открытого текста
int v1_5_11(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (week_day % 2 == 0) { // Четный день недели - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетный день недели - сдвиг влево
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.12: Ш1.2.12 с полем длины открытого текста
int v1_5_12(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    int textpole = symboul(ifstream* file);
    while (textpole!=0){
        if (week_day % 2 == 0) { // Четный день недели - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;
            textpole-=1;
        } else { // Нечетный день недели - сдвиг влево
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;
            textpole-=1;
        }
    }
    return caesar(input_file, output_file, offset);
}
