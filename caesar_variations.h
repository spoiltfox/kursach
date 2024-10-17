#pragma once
#include "caesar_variations.cpp"

int shift_decorator(ifstream* input_file, ofstream* output_file, offsets offset);

int time_based_decorator(ifstream* input_file, ofstream* output_file, offsets offset);
