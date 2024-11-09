/**
\file
\brief Файл содержащий вариации шифратора

В данный файл выведены все функции вида vX_X_X(ifstream*, ofstream*, offsets),
где Х_Х_Х номер соответствующего шифра из файла с ТЗ.
Каждая функция вызывает caesar(ifstream*, ofstream*, offsets), где через
структуру offsets передаются параметры шифратора
*/

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

//ИМЯ ФУНКЦИИ ДОЛЖНО СОТВЕТСТВОВАТЬ КОНКРЕТНОЙ ВАРИАЦИИ ИЗ ФАЙЛА
// Для шифра Ш1.1.1 - v1_1_1

//Ш1.1. Простой шифр Цезаря
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

//Ш1.2. Шифр Цезаря с маркантом
//Ш1.2.1. Шифр Цезаря с разными однонаправленными сдвигами вправо, зависящими от времени начала шифрования
int v1_2_1(ifstream* input_file, ofstream* output_file, offsets offset) {
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
//Ш1.2.2. Шифр Цезаря с разными однонаправленными сдвигами, влево зависящими от времени начала шифрования
int v1_2_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // Четная минута
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else { // Нечетная минута
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}
//Ш1.2.3. Шифр Цезаря с одинаковыми разнонаправленными сдвигами, зависящими от времени начала шифрования
int v1_2_3(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_4(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_5(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_6(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_7(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_8(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_9(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_10(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_11(ifstream* input_file, ofstream* output_file, offsets offset) {
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
int v1_2_12(ifstream* input_file, ofstream* output_file, offsets offset) {
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

//Ш1.3. Шифр Цезаря с полем длины открытого текста
//Ш1.3.1. Шифр Цезаря с сдвигом вправо и полем длины открытого текста
int v1_3_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = 3; offset.kir = 5; offset.num = 2; offset.symbol_count_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}
//Ш1.3.2. Шифр Цезаря с сдвигом влево и полем длины открытого текста
int v1_3_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = -3; offset.kir = -5; offset.num = -2; offset.symbol_count_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

//Ш1.4. Шифр Цезаря с контрольной суммой
//Ш1.4.1. Шифр Цезаря с сдвигом вправо и контрольной суммой:
int v1_4_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = 3; offset.kir = 5; offset.num = 2; offset.checksum_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}
//Ш1.4.2. Шифр Цезаря с сдвигом влево контрольной суммой:
int v1_4_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = -3; offset.kir = -5; offset.num = -2; offset.checksum_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

//Ш1.5. Шифр Цезаря с маркантом и полем длины открытого текста
//1.5.1 Ш1.2.1 с полем длины открытого текста
int v1_5_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    offset.symbol_count_needed = true;
    int minute = get_minute();
    if (true){

        if (minute % 2 == 0) { // Четная минута
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетная минута
            offset.lat = 4;
            offset.kir = 6;
            offset.num = 2;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.2 - Ш1.2.2 с полем длины открытого текста
int v1_5_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    offset.symbol_count_needed = true;
    int minute = get_minute();
    if (true){

        if (minute % 2 == 0) { // Четная минута
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;

        } else { // Нечетная минута
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.3 - Ш1.2.3 с полем длины открытого текста
int v1_5_3(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    offset.symbol_count_needed = true;
    if (true){
        if (minute % 2 == 0) { // Четная минута - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетная минута - сдвиг влево
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.4 - Ш1.2.4 с полем длины открытого текста
int v1_5_4(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    offset.symbol_count_needed = true;
    if (true){
        if (minute % 2 == 0) { // Четная минута - - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетная минута - - сдвиг влево
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.5: Ш1.2.5 с полем длины открытого текста
int v1_5_5(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    offset.symbol_count_needed = true;
    if (true){
        if (day_of_month % 2 == 0) { // Четный день месяца
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетный день месяца
            offset.lat = 4;
            offset.kir = 6;
            offset.num = 2;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.6: Ш1.2.6 с полем длины открытого текста
int v1_5_6(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    offset.symbol_count_needed = true;
    if (true){
        if (day_of_month % 2 == 0) { // Четный день месяца
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;

        } else { // Нечетный день месяца
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.7: Ш1.2.7 с полем длины открытого текста
int v1_5_7(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    offset.symbol_count_needed = true;
    if (true){
        if (day_of_month % 2 == 0) { // Четный день месяца - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетный день месяца - сдвиг влево
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.8:Ш1.2.8 с полем длины открытого текста
int v1_5_8(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    offset.symbol_count_needed = true;
    if (true){
        if (day_of_month % 2 == 0) { // Четный день месяца - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетный день месяца - сдвиг влево
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.9: Ш1.2.9 с полем длины открытого текста
int v1_5_9(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    offset.symbol_count_needed = true;
    if (true){
        if (week_day % 2 == 0) { // Четный день недели
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетный день недели
            offset.lat = 4;
            offset.kir = 6;
            offset.num = 2;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.10: Ш1.2.10 с полем длины открытого текста
int v1_5_10(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    offset.symbol_count_needed = true;
    if (true){
        if (week_day % 2 == 0) { // Четный день недели
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;

        } else { // Нечетный день недели
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.11: Ш1.2.11 с полем длины открытого текста
int v1_5_11(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    offset.symbol_count_needed = true;
    if (true){
        if (week_day % 2 == 0) { // Четный день недели - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетный день недели - сдвиг влево
            offset.lat = -3;
            offset.kir = -5;
            offset.num = -3;

        }
    }
    return caesar(input_file, output_file, offset);
}

// Ш1.5.12: Ш1.2.12 с полем длины открытого текста
int v1_5_12(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    offset.symbol_count_needed = true;
    if (true){
        if (week_day % 2 == 0) { // Четный день недели - сдвиг вправо
            offset.lat = 3;
            offset.kir = 5;
            offset.num = 3;

        } else { // Нечетный день недели - сдвиг влево
            offset.lat = -4;
            offset.kir = -6;
            offset.num = -2;

        }
    }
    return caesar(input_file, output_file, offset);
}

//Ш1.6. Шифр Цезаря с маркантом и контрольной суммой
// Ш1.6.1.1. Ш1.2.1 с контрольной суммой, не зависящей от времени
int v1_6_1_1(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.2. Ш1.2.2 с контрольной суммой, не зависящей от времени
int v1_6_1_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // Четная минута
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else { // Нечетная минута
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.3. Ш1.2.3 с контрольной суммой, не зависящей от времени
int v1_6_1_3(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.4. Ш1.2.4 с контрольной суммой, не зависящей от времени
int v1_6_1_4(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.5. Ш1.2.5 с контрольной суммой, не зависящей от времени
int v1_6_1_5(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.6. Ш1.2.6 с контрольной суммой, не зависящей от времени
int v1_6_1_6(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.7. Ш1.2.7 с контрольной суммой, не зависящей от времени
int v1_6_1_7(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.8. Ш1.2.8 с контрольной суммой, не зависящей от времени
int v1_6_1_8(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.9. Ш1.2.9 с контрольной суммой, не зависящей от времени
int v1_6_1_9(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.10. Ш1.2.10 с контрольной суммой, не зависящей от времени
int v1_6_1_10(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.11. Ш1.2.11 с контрольной суммой, не зависящей от времени
int v1_6_1_11(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.1.12. Ш1.2.12 с контрольной суммой, не зависящей от времени
int v1_6_1_12(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.1. Ш1.2.1 с контрольной суммой, зависящей от времени
int v1_6_2_1(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.2. Ш1.2.2 с контрольной суммой, зависящей от времени
int v1_6_2_2(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.3. Ш1.2.3 с контрольной суммой, зависящей от времени
int v1_6_2_3(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.4. Ш1.2.4 с контрольной суммой, зависящей от времени
int v1_6_2_4(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.5. Ш1.2.5 с контрольной суммой, зависящей от времени
int v1_6_2_5(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.6. Ш1.2.6 с контрольной суммой, зависящей от времени
int v1_6_2_6(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.7. Ш1.2.7 с контрольной суммой, зависящей от времени
int v1_6_2_7(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.8. Ш1.2.8 с контрольной суммой, зависящей от времени
int v1_6_2_8(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.9. Ш1.2.9 с контрольной суммой, зависящей от времени
int v1_6_2_9(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.10. Ш1.2.10 с контрольной суммой, зависящей от времени
int v1_6_2_10(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.11. Ш1.2.11 с контрольной суммой, зависящей от времени
int v1_6_2_11(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.6.2.12. Ш1.2.12 с контрольной суммой, зависящей от времени
int v1_6_2_12(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

//Ш1.7. Шифр Цезаря с полем длины и контрольной суммой
//Ш1.7.1. Ш1.1.1 с полем длины открытого текста и контрольной суммой.
int v1_7_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = 3;
    offset.kir = 5;
    offset.num = 2;
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}
//Ш1.7.2. Ш1.1.2 с полем длины открытого текста и контрольной суммой.

int v1_7_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    // Логика сдвига
    offset.lat = -3;
    offset.kir = -5;
    offset.num = -2;

    offset.symbol_count_needed = true;
    offset.checksum_needed = true;

    // Вызов основной функции (шифр Цезаря)
    return caesar(input_file, output_file, offset);
}

//Ш1.8. Шифр Цезаря с маркантом, полем длины открытого текста и контрольной суммой

//Ш1.8.1. Шифр Цезаря с маркантом, полем длины открытого текста и контрольной суммой, не зависящей от времени

//Ш1.8.1.1. Ш1.2.1 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_1(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.2. Ш1.2.2 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // Четная минута
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else { // Нечетная минута
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.3. Ш1.2.3 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_3(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.4. Ш1.2.4 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_4(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.5. Ш1.2.5 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_5(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.6. Ш1.2.6 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_6(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.7. Ш1.2.7 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_7(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.8. Ш1.2.8 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_8(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.9. Ш1.2.9 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_9(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.10. Ш1.2.10 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_10(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.11. Ш1.2.11 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_11(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.1.12. Ш1.2.12 с полем длины открытого текста и контрольной суммой, не зависящей от времени
int v1_8_1_12(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = false;
    return caesar(input_file, output_file, offset);
}


//Ш1.8.2. Шифр Цезаря с маркантом, полем длины открытого текста и контрольной суммой, зависящей от времени

//Ш1.8.2.1. Ш1.2.1 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_1(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

//Ш1.8.2.2. Ш1.2.2 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_2(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.3. Ш1.2.3 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_3(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.4. Ш1.2.4 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_4(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.5. Ш1.2.5 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_5(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.6. Ш1.2.6 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_6(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.7. Ш1.2.7 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_7(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.8. Ш1.2.8 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_8(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.9. Ш1.2.9 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_9(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.10. Ш1.2.10 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_10(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.11. Ш1.2.11 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_11(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}

// Ш1.8.2.12. Ш1.2.12 с полем длины открытого текста и контрольной суммой, зависящей от времени
int v1_8_2_12(ifstream* input_file, ofstream* output_file, offsets offset) {
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
    offset.symbol_count_needed = true;
    offset.checksum_needed = true;
    offset.checksum_time_dependent = true;
    return caesar(input_file, output_file, offset);
}



