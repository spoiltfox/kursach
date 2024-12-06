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

/**
    \brief Юнит-тест для функции calcChecksum(), которая вычисляет контрольную сумму текста
*/
void test_calcChecksum() {
    ofstream input_test_file("input.txt");
    input_test_file << "Hello123";
    input_test_file.close();

    ifstream input("input.txt");
    unsigned int checksum = calcChecksum(&input, false);
    input.close();

    // Предполагаемое значение контрольной суммы для "Hello123"
    // Считаем сумму вручную:
    // H = 72
    // e = 101
    // l = 108
    // l = 108
    // o = 111
    // 1 = 49
    // 2 = 50
    // 3 = 51
    // Итого: 72 + 202 + 324 + 432 + 555 + 294 + 350 + 408 = 2637
    unsigned int expected_checksum = 2637;

    if (checksum == expected_checksum) {
        cout << "test_calcChecksum passed\n";
    } else {
        cout << "test_calcChecksum failed: expected " << expected_checksum << ", got " << checksum << "\n";
    }
}
/**
    \brief Юнит-тест для функции calcChecksum(), которая вычисляет контрольную сумму текста
*/
void test_calcChecksum_with_special_characters() {
    ofstream input_test_file("input_special.txt");
    input_test_file << "!@#123";
    input_test_file.close();

    ifstream input("input_special.txt");
    unsigned int checksum = calcChecksum(&input, false);
    input.close();

    // Предполагаемое значение контрольной суммы для "!@#123"
    // ! = 33
    // @ = 64
    // # = 35
    // 1 = 49
    // 2 = 50
    // 3 = 51
    // Итого: 33 + 128 + 105 + 196 + 250 + 306 = 288
    unsigned int expected_checksum = 1018;

    if (checksum == expected_checksum) {
        cout << "test_calcChecksum_with_special_characters passed\n";
    } else {
        cout << "test_calcChecksum_with_special_characters failed: expected " << expected_checksum << ", got " << checksum << "\n";
    }
}
/**
    \brief Юнит-тест для функции calcChecksum(), которая вычисляет контрольную сумму текста
*/
void test_calcChecksum_with_russian_characters() {
    ofstream input_test_file("input_russian.txt", ios::binary);
    input_test_file << "Привет123";
    input_test_file.close();

    ifstream input("input_russian.txt");
    unsigned int checksum = calcChecksum(&input, false);
    input.close();

    // Предполагаемое значение контрольной суммы для "Привет123"
    // П = 208, 159
    // р = 209, 128
    // и = 208, 184
    // в = 208, 178
    // е = 208, 181
    // т = 209, 130
    // 1 = 49
    // 2 = 50
    // 3 = 51
    // Итого: 208 + 318 + 627 + 512 + 1040 + 1104 + 1456 + 1424 + 1872 + 1810 + 2299 + 1560 + 637 + 700 + 765 = 16332
    unsigned int expected_checksum = 16332;

    if (checksum == expected_checksum) {
        cout << "test_calcChecksum_with_russian_characters passed\n";
    } else {
        cout << "test_calcChecksum_with_russian_characters failed: expected " <<expected_checksum << ", got " << checksum << "\n";
    }
}
/**
    \brief Юнит-тест для функции int_pow(), которая вычисляет число a в степени b
*/
void int_pow_test(){
    bool is_correct = true;
    if (int_pow(2, 0) != 1){is_correct = false;}
    if (int_pow(2, 1) != 2){is_correct = false;}
    if (int_pow(2, 2) != 4){is_correct = false;}
    if (int_pow(2, 3) != 8){is_correct = false;}
    if (is_correct){
        cout << "int_pow_test passed\n";
    }
    else {
        cout <<"int_pow_test failed\n";
        cout << "2^0 = " << int_pow(2, 0) << endl;
        cout << "2^1 = " << int_pow(2, 1) << endl;
        cout << "2^2 = " << int_pow(2, 2) << endl;
        cout << "2^3 = " << int_pow(2, 3) << endl;
    }
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
