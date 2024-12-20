/**
    \file
    \brief Заголовочный файл с функциями
    В данном файле выведены все заголовки функций, необходимые для вариаций шифра цезаря по ТЗ
*/
#pragma once
#include "functions.cpp"
//заголовочный файл



/**
\brief Функция вычисляющая неотрицательную целую степень числа
*/
unsigned int int_pow(unsigned int base, unsigned int power);
/**

    В качестве смещений принимаются offsets::lat, offsets::kir и offsets::num
    для смещений по латинице, кириллице и числам соответственно.
    При положительных значениях сдвиг вправо, при отрицательных - влево.
    \brief Функция реализующая шифр цезаря.
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \param [offset::symbol_count_needed] == true повлечет запись в конец файла
    одного байта - количества символов в исходном файле.
    \param [offset::checksum_needed] == true повлечет запись в конец файла
    одного байта - контрольной суммы.
    \param [offset::checksum_time_dependent] == true повлечет зависимость
    контрольной суммы от времени.
    \return Код завершения функции
*/
int caesar(ifstream* input_file, ofstream* output_file, offsets offset);

/**
    \brief Функция вычисляющая длину открытого текста
    \param[in] file Файл с исходным текстом
    \return Количество символов в передаваемом файле
*/
unsigned int symboul (ifstream* file);

/**
    \brief Функция выводящая текущий день недели, используется в задании 1.2, 1.5, 1.6, 1.8
    \return Номер дня недели
*/
int get_week_day();

/**
    \brief Функция выводящая текущий день месяца, используется в задании 1.2, 1.5, 1.6, 1.8
    \return День месяца
*/
int get_mouth_day();

/**
    \brief Функция выводящая текущую минуту, используется в задании 1.2, 1.5, 1.6, 1.8
    \return Текущую минуту
*/
int get_minute();

/**
    \brief Функция вычисляющая контрольную сумму текста.
    \param[in] input_file Файл с исходным текстом
    \param[in] timeDependent == true, означает зависимость контрольной суммы от времени
    \return Контрольную сумму незашифрованного текста
*/
unsigned int calcChecksum(ifstream* inputFile, bool timeDependent);




