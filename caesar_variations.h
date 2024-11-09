/**
    \file
    \brief Заголовочный файл с вариациями шифра Цезаря
    В данном файле выведенены все заголовки функций, которые реализуют, соответствующие названию, пункты из ТЗ
*/
#pragma once
#include "caesar_variations.cpp"
//заголовочный файл

 /**
    \brief Шифр Цезаря с сдвигом вправо
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_1_1(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с сдвигом влево
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_1_2(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с разными однонаправленными сдвигами вправо, зависящими от времени начала шифрования
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_1(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с разными однонаправленными сдвигами, влево зависящими от времени начала шифрования
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_2(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с одинаковыми разнонаправленными сдвигами, зависящими от времени начала шифрования
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_3(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с разными разнонаправленными сдвигами, зависящими от времени начала шифрования
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_4(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.1 с сдвигом зависящим от числа месяца
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_5(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief  Ш1.2.2 с сдвигом зависящим от числа месяца
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_6(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.3 с сдвигом зависящим от числа месяца
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_7(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief  Ш1.2.4 с сдвигом зависящим от числа месяца
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_8(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.1 с сдвигом зависящим от дня недели
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_9(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.2 с сдвигом зависящим от дня недели
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_10(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.3 с сдвигом зависящим от дня недели
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_11(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.4 с сдвигом зависящим от дня недели
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_2_12(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с сдвигом вправо и полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_3_1(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с сдвигом влево и полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_3_2(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с сдвигом вправо и контрольной суммой
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_4_1(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Шифр Цезаря с сдвигом влево контрольной суммой
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_4_2(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.1 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_1(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.2 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_2(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.3 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_3(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.4 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_4(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.5 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_5(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.6 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_6(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.7 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_7(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.8 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_8(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.9 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_9(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.10 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_10(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.11 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_11(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.12 с полем длины открытого текста
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_5_12(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.1 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_1(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.2 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_2(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.3 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_3(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.4 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_4(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.5 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_5(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.6 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_6(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.7 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_7(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.8 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_8(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.9 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_9(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.10 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_10(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.11 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_11(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.12 с контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_1_12(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.1 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_1(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.2 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_2(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.3 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_3(wifstream* input_file, wofstream* output_file, offsets offset);

 /**
    \brief Ш1.2.4 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_4(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.5 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_5(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.6 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_6(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.7 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_7(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.8 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_8(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.9 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_9(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.10 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_10(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.11 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_11(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.12 с контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_6_2_12(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.1.1 с полем длины открытого текста и контрольной суммой.
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_7_1(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.1.2 с полем длины открытого текста и контрольной суммой.
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_7_2(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.1 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_1(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.2 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_2(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.3 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_3(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.4 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_4(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.5 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_5(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.6 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_6(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.7 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_7(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.8 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_8(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.9 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_9(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.10 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_10(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.11 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_11(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.12 с полем длины открытого текста и контрольной суммой, не зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_1_12(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.1 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_1(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.2 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_2(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.3 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_3(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.4 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_4(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.5 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_5(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.6 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_6(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.7 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_7(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.8 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_8(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.9 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_9(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.10 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_10(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.11 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_11(wifstream* input_file, wofstream* output_file, offsets offset);
/**
    \brief Ш1.2.12 с полем длины открытого текста и контрольной суммой, зависящей от времени
    \param[in] input_file Файл с исходным текстом
    \param[out] output_file Созданный файл с зашифрованным текстом
    \param[in] offset Структура задающая сдвиги
    \return Результат работы функции ceasar()
*/
int v1_8_2_12(wifstream* input_file, wofstream* output_file, offsets offset);


//int time_based_decorator(wifstream* input_file, wofstream* output_file, offsets offset);
