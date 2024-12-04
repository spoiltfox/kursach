/**
    \file
    \brief Файл содержащий функции помощи для пользователя в ОС Linux

*/
#include <iostream>

void print_help(){
    cout << "Usage:\n\t kursach.exe [input_file] [output_file] [cipher_number]\n";
}

using namespace std;
void helpWithCipherNumbers() {
    cout << "Available encoder numbers:\n";
    cout << " \t 1.1.1\n \t 1.1.2\n \t 1.2.1\n \t 1.2.2\n \t 1.2.3\n \t 1.2.4\n \t 1.2.5\n \t 1.2.6\n \t 1.2.7\n \t 1.2.8\n \t 1.2.9\n \t 1.2.10\n \t 1.2.11\n \t 1.2.12\n"
         << " \t 1.3.1\n \t 1.3.2\n \t 1.4.1\n \t 1.4.2\n \t 1.5.1\n \t 1.5.2\n \t 1.5.3\n \t 1.5.4\n \t 1.5.5\n \t 1.5.6\n \t 1.5.7\n \t 1.5.8\n \t 1.5.9\n \t 1.5.10\n \t 1.5.11\n \t 1.5.12\n"
         << " \t 1.6.1.1\n \t 1.6.1.2\n \t 1.6.1.3\n \t 1.6.1.4\n \t 1.6.1.5\n \t 1.6.1.6\n \t 1.6.1.7\n \t 1.6.1.8\n \t 1.6.1.9\n \t 1.6.1.10\n \t 1.6.1.11\n \t 1.6.1.12\n"
         << " \t 1.6.2.1\n \t 1.6.2.2\n \t 1.6.2.3\n \t 1.6.2.4\n \t 1.6.2.5\n \t 1.6.2.6\n \t 1.6.2.7\n \t 1.6.2.8\n \t 1.6.2.9\n \t 1.6.2.10\n \t 1.6.2.11\n \t 1.6.2.12\n"
         << " \t 1.7.1\n \t 1.7.2\n \t 1.8.1.1\n \t 1.8.1.2\n \t 1.8.1.3\n \t 1.8.1.4\n \t 1.8.1.5\n \t 1.8.1.6\n \t 1.8.1.7\n \t 1.8.1.8\n \t 1.8.1.9\n \t 1.8.1.10\n \t 1.8.1.11\n \t 1.8.1.12\n"
         << " \t 1.8.2.1\n \t 1.8.2.2\n \t 1.8.2.3\n \t 1.8.2.4\n \t 1.8.2.5\n \t 1.8.2.6\n \t 1.8.2.7\n \t 1.8.2.8\n \t 1.8.2.9\n \t 1.8.2.10\n \t 1.8.2.11\n \t 1.8.2.12\n";
}

void help_1_1_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо.\n \t Производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 2 для цифр \n";
}
void help_1_1_2(){
    cout << "\t Шифр Цезаря со сдвигом влево.\n \t Производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 2 для цифр \n";
}


void help_1_2_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от времени начала шифрования.\n \t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_2(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от времени начала шифрования.\n \t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_3(){
     cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования.\n \t Каждую чётную минуту производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг влево на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_4(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования.\n \t Каждую чётную минуту производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг влево на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_5(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от числа месяца.\n \t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_6(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от числа месяца.\n \t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_7(){
     cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца.\n \t Каждый чётный день месяца производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг влево на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_8(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца.\n \t Каждый чётный день месяца производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг влево на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_9(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от дня недели.\n \t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_10(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от дня недели.\n \t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_11(){
     cout << "\t Шифр Цезаря со сдвигом, зависящим от дня недели.\n \t Каждый чётный день недели производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг влево на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_2_12(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от дня недели.\n \t Каждый чётный день недели производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый чётный день недели производит сдвиг влево на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}



void help_1_3_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо и полем длины открытого текста.\n \t Производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 2 для цифр \n \t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_3_2(){
    cout << "\t Шифр Цезаря со сдвигом влево и полем длины открытого текста.\n \t Производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 2 для цифр \n \t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}



void help_1_4_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо и контрольной суммой\n \t Производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 2 для цифр \n \t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_4_2(){
    cout << "\t Шифр Цезаря со сдвигом влево и контрольной суммой.\n \t Производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 2 для цифр \n \t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}





void help_1_5_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от времени начала шифрования и с полем длины открытого текста.\n \t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_2(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от времени начала шифрования и с полем длины открытого текста.\n \t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_3(){
     cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования и с полем длины открытого текста.\n \t Каждую чётную минуту производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг влево на 3 для латиницы, на 4 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_4(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования и с полем длины открытого текста.\n \t Каждую чётную минуту производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг влево на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_5(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от числа месяца и с полем длины открытого текста.\n \t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_6(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от числа месяца и с полем длины открытого текста.\n \t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_7(){
     cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца и с полем длины открытого текста.\n \t Каждый чётный день месяца производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг влево на 3 для латиницы, на 4 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_8(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца и с полем длины открытого текста.\n \t Каждый чётный день месяца производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг влево на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_9(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от дня недели и с полем длины открытого текста.\n \t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_10(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от дня недели и с полем длины открытого текста.\n \t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_11(){
     cout << "\t Шифр Цезаря со сдвигом, зависящим от дня недели и с полем длины открытого текста.\n \t Каждый чётный день недели производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг влево на 3 для латиницы, на 4 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}
void help_1_5_12(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от дня недели и с полем длины открытого текста.\n \t Каждый чётный день недели производит сдвиг вправо на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый чётный день недели производит сдвиг влево на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n \t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}




void help_1_6_1_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от времени начала шифрования и контрольной суммой, не зависящей от времени.\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_2(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от времени начала шифрования и с контрольной суммой, не зависящей от времени (Ш1.2.2).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_3(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования и с контрольной суммой, не зависящей от времени (Ш1.2.3).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_4(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования с контрольной суммой, не зависящей от времени (Ш1.2.4).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_5(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от числа месяца с контрольной суммой, не зависящей от времени (Ш1.2.5).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_6(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от числа месяца. с контрольной суммой, не зависящей от времени (Ш1.2.6).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_7(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца с контрольной суммой, не зависящей от времени (Ш1.2.7).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_8(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца с контрольной суммой, не зависящей от времени (Ш1.2.8).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_9(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от дня недели с контрольной суммой, не зависящей от времени (Ш1.2.9).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_10(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от дня недели с контрольной суммой, не зависящей от времени (Ш1.2.10).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_6_1_11(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от дня недели с контрольной суммой, не зависящей от времени (Ш1.2.11).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_1_12(){
    cout << "\t Шифр Цезаря о сдвигом, зависящим от дня недели  с контрольной суммой, не зависящей от времени (Ш1.2.12).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}



void help_1_6_2_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от времени начала шифрования и контрольной суммой,  зависящей от времени.\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_2(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от времени начала шифрования и с контрольной суммой,  зависящей от времени (Ш1.2.2).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_3(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования и с контрольной суммой,  зависящей от времени (Ш1.2.3).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_4(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования с контрольной суммой,  зависящей от времени (Ш1.2.4).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_5(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от числа месяца с контрольной суммой,   зависящей от времени (Ш1.2.5).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_6(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от числа месяца. с контрольной суммой,  зависящей от времени (Ш1.2.6).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_7(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца с контрольной суммой,  зависящей от времени (Ш1.2.7).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_8(){"контрольной суммой, не зависящей от времени (Ш1.2.8).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_9(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от дня недели с контрольной суммой, не зависящей от времени (Ш1.2.9).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_10(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от дня недели с контрольной суммой, не зависящей от времени (Ш1.2.10).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}
void help_1_6_2_11(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от дня недели с контрольной суммой, не зависящей от времени (Ш1.2.11).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}

void help_1_6_2_12(){
    cout << "\t Шифр Цезаря о сдвигом, зависящим от дня недели  с контрольной суммой, не зависящей от времени (Ш1.2.12).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n";
}



void help_1_7_1(){
    cout << "\t Шифр Цезаря с полем длины открытого текста и контрольной суммой со сдвигом вправо.\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 2 для цифр \n \t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_7_2(){
    cout << "\t Шифр Цезаря с полем длины открытого текста и контрольной суммой со сдвигм влево.\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 2 для цифр \n \t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}





void help_1_8_1_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от времени начала шифрования с полем длины открытого текста и контрольной суммой, не зависящей от времени.\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_2(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от времени начала шифрования с полем длины открытого текста и контрольной суммой, не зависящей от времени.\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_3(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.3).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_4(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.4).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_5(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от числа месяца с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.5).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_6(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от числа месяца с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.6).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_7(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.7).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_8(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.8).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_9(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от дня недели с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.9).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_10(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от дня недели с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.10).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_11(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от дня недели с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.11).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_1_12(){
    cout << "\t Шифр Цезаря о сдвигом, зависящим от дня недели с полем длины открытого текста и с контрольной суммой, не зависящей от времени (Ш1.2.12).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}




void help_1_8_2_1(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от времени начала шифрования с полем длины открытого текста и контрольной суммой, зависящей от времени.\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_2(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от времени начала шифрования с полем длины открытого текста и контрольной суммой, зависящей от времени.\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_3(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.3).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_4(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от времени начала шифрования с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.4).\n\t Каждую чётную минуту производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждую нечётную минуту производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_5(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от числа месяца с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.5).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_6(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от числа месяца с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.6).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_7(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.7).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_8(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от числа месяца с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.8).\n\t Каждый чётный день месяца производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день месяца производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_9(){
    cout << "\t Шифр Цезаря со сдвигом вправо, зависящим от дня недели с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.9).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_10(){
    cout << "\t Шифр Цезаря со сдвигом влево, зависящим от дня недели с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.10).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_11(){
    cout << "\t Шифр Цезаря со сдвигом, зависящим от дня недели с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.11).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}

void help_1_8_2_12(){
    cout << "\t Шифр Цезаря о сдвигом, зависящим от дня недели с полем длины открытого текста и с контрольной суммой, зависящей от времени (Ш1.2.12).\n\t Каждый чётный день недели производит сдвиг на 3 для латиницы, на 5 для кириллицы, на 3 для цифр \n \t Каждый нечётный день недели производит сдвиг на 4 для латиницы, на 6 для кириллицы, на 2 для цифр\n\t После зашифрованного текста присутствует байт, содержащий контрольную сумму от открытого текста.\n\t После зашифрованного текста присутствует байт, содержащий длину открытого текста\n";
}