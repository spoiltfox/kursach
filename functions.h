/**
    \file
    \brief Заголовочный файл с функциями
    В данном файле выведены все заголовки функций, необходимые для вариаций шифра цезаря по ТЗ
*/
#pragma once
#include "functions.cpp"
//заголовочный файл

int caesar(wifstream* input_file, wofstream* output_file, offsets offset);

char symboul (wifstream* file);

int get_week_day();

int get_mouth_day();

int get_minute();

char calcChecksum(wifstream* inputFile, bool timeDependent);

void print_help();
