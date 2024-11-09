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
    ofstream output("output.txt");
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
    return 0;
}
