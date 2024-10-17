#pragma once
#include "functions.cpp"


int caesar(ifstream* input_file, ofstream* output_file, offsets offset);

char symboul (ifstream* file);

int get_week_day();

int get_mouth_day();

int get_minute();

void print_help();
