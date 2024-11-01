#pragma once
#include "functions.cpp"
//заголовочный файл

int caesar(wifstream* input_file, wofstream* output_file, offsets offset);

char symboul (wifstream* file);

int get_week_day();

int get_mouth_day();

int get_minute();

void print_help();
