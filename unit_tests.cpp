/**
    \file
    \brief Файл содержащий юнит-тесты
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "functions.h"

/**
    \brief Юнит-тест для функции ceaser()
*/
void test_caesar() {
    ofstream output;
    ifstream input;
    offsets test_offset;
    test_offset.lat = 1;
    test_offset.kir = 0;
    test_offset.num = 0;

    // Создание входного файла
    ofstream input_test_file("input.txt");
    input_test_file << "ABCabc";
    input_test_file.close();

    input.open("input.txt");
    output.open("output.txt");
    caesar(&input, &output, test_offset);
    input.close();
    output.close();

    ifstream result("output.txt");
    string result_string;
    getline(result, result_string);
    result.close();

    if (result_string == "BCDbcd") {
        cout << "test_caesar passed\n";
    } else {
        cout << "test_caesar failed: expected 'BCDbcd', got '" << result_string << "'\n";
    }
}

/**
    \brief Юнит-тест для функции symboul(),которая считает количество символов в файле
*/
void test_character_count()
{
    ofstream input_test_file("input.txt");
    input_test_file << "Hello\nWorld";
    input_test_file.close();

    ifstream input("input.txt");
    char count = symboul(&input);
    input.close();

    if (count == 11)
    {
        cout << "test_character_count passed\n";
    }
    else
    {
        cout << "test_character_count failed: expected 11, got " << static_cast<int>(count) << "\n";
    }
}

/**
    \brief Юнит-тест для функции get_week_day(), которая выводит номер текущего дня недели
*/
void test_week_day()
{
    int day = get_week_day();
    if (day >= 0 && day <= 6)
    {
        cout << "test_week_day passed\n";
    }
    else
    {
        cout << "test_week_day failed: expected value between 0 and 6, got " << day << "\n";
    }
}

/**
    \brief Юнит-тест для функции get_mouth_day(), которая выводит день месяца
*/
void test_month_day()
{
    int day = get_mouth_day();
    if (day >= 1 && day <= 31)
    {
        cout << "test_month_day passed\n";
    }
    else
    {
        cout << "test_month_day failed: expected value between 1 and 31, got " << day << "\n";
    }
}

/**
    \brief Юнит-тест для функции get_minute(), которая выводит текущую минуту
*/
void test_minute_range()
{
    int minute = get_minute();
    if (minute >= 0 && minute <= 59)
    {
        cout << "test_minute_range passed\n";
    }
    else
    {
        cout << "test_minute_range failed: expected value between 0 and 59, got " << minute << "\n";
    }
}

void test_calcChecksum() {
    ofstream input_test_file("input.txt");
    input_test_file << "Hello123";
    input_test_file.close();

    ifstream input("input.txt");
    char checksum = calcChecksum(&input, false);
    input.close();

    // Предполагаемое значение контрольной суммы для "Hello123"
    // Считаем сумму вручную:
    // H = 72 + 3 = 75
    // e = 101 + 3 = 104
    // l = 108 + 3 = 111
    // l = 108 + 3 = 111
    // o = 111 + 3 = 114
    // 1 = 49 + 2 = 51
    // 2 = 50 + 2 = 52
    // 3 = 51 + 2 = 53
    // Итого: 75 + 104 + 111 + 111 + 114 + 51 + 52 + 53 = 671
    char expected_checksum = 671;

    if (checksum == expected_checksum) {
        cout << "test_calcChecksum passed\n";
    } else {
        cout << "test_calcChecksum failed: expected " << static_cast<int>(expected_checksum) << ", got " << static_cast<int>(checksum) << "\n";
    }
}

void test_calcChecksum_with_special_characters() {
    ofstream input_test_file("input_special.txt");
    input_test_file << "!@#123";
    input_test_file.close();

    ifstream input("input_special.txt");
    char checksum = calcChecksum(&input, false);
    input.close();

    // Предполагаемое значение контрольной суммы для "!@#123"
    // ! = 33 + 0 = 33
    // @ = 64 + 0 = 64
    // # = 35 + 0 = 35
    // 1 = 49 + 2 = 51
    // 2 = 50 + 2 = 52
    // 3 = 51 + 2 = 53
    // Итого: 33 + 64 + 35 + 51 + 52 + 53 = 288
    char expected_checksum = 288;

    if (checksum == expected_checksum) {
        cout << "test_calcChecksum_with_special_characters passed\n";
    } else {
        cout << "test_calcChecksum_with_special_characters failed: expected " << static_cast<int>(expected_checksum) << ", got " << static_cast<int>(checksum) << "\n";
    }
}

void test_calcChecksum_with_russian_characters() {
    ofstream input_test_file("input_russian.txt");
    input_test_file << "Привет123";
    input_test_file.close();

    ifstream input("input_russian.txt");
    char checksum = calcChecksum(&input, false);
    input.close();

    // Предполагаемое значение контрольной суммы для "Привет123"
    // П = 208 + 5 = 213
    // р = 240 + 5 = 245
    // и = 232 + 5 = 237
    // в = 226 + 5 = 231
    // е = 229 + 5 = 234
    // т = 242 + 5 = 247
    // 1 = 49 + 2 = 51
    // 2 = 50 + 2 = 52
    // 3 = 51 + 2 = 53
    // Итого: 213 + 245 + 237 + 231 + 234 + 247 + 51 + 52 + 53 = 1563
    char expected_checksum = 1563;

    if (checksum == expected_checksum) {
        cout << "test_calcChecksum_with_russian_characters passed\n";
    } else {
        cout << "test_calcChecksum_with_russian_characters failed: expected " << static_cast<int>(expected_checksum) << ", got " << static_cast<int>(checksum) << "\n";
    }
}
void int_pow_test(){
    cout << "2^0 = " << int_pow(2, 0) << endl;
    cout << "2^1 = " << int_pow(2, 1) << endl;
    cout << "2^2 = " << int_pow(2, 2) << endl;
    cout << "2^3 = " << int_pow(2, 3) << endl;
}
 /**
    \brief Запуск юнит-тестов
    \return Код завершения программы
 */
int main()
{
    test_caesar();
    test_character_count();
    test_week_day();
    test_month_day();
    test_minute_range();
    test_calcChecksum();
    test_calcChecksum_with_special_characters();
    test_calcChecksum_with_russian_characters();
    int_pow_test();
    return 0;
}
