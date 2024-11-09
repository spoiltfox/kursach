/**
\file
\brief Основной файл проекта

В данном файле содержится логика ввода-вывода программы
*/
#include "functions.h"
#include "caesar_variations.h"

using namespace std;

namespace decor_choice {
    enum Option
    {
        Option_invalid,
        Option1_1_1,
        Option1_1_2,
        Option1_2_1,
        Option1_2_2,
        Option1_2_3,
        Option1_2_4,
        Option1_2_5,
        Option1_2_6,
        Option1_2_7,
        Option1_2_8,
        Option1_2_9,
        Option1_2_10,
        Option1_2_11,
        Option1_2_12,
        Option1_3_1,
        Option1_3_2,
        Option1_4_1,
        Option1_4_2,
        Option1_5_1,
        Option1_5_2,
        Option1_5_3,
        Option1_5_4,
        Option1_5_5,
        Option1_5_6,
        Option1_5_7,
        Option1_5_8,
        Option1_5_9,
        Option1_5_10,
        Option1_5_11,
        Option1_5_12,
        Option1_6_1_1,
        Option1_6_1_2,
        Option1_6_1_3,
        Option1_6_1_4,
        Option1_6_1_5,
        Option1_6_1_6,
        Option1_6_1_7,
        Option1_6_1_8,
        Option1_6_1_9,
        Option1_6_1_10,
        Option1_6_1_11,
        Option1_6_1_12,
        Option1_6_2_1,
        Option1_6_2_2,
        Option1_6_2_3,
        Option1_6_2_4,
        Option1_6_2_5,
        Option1_6_2_6,
        Option1_6_2_7,
        Option1_6_2_8,
        Option1_6_2_9,
        Option1_6_2_10,
        Option1_6_2_11,
        Option1_6_2_12,
        Option1_7_1,
        Option1_7_2,
    };
}

decor_choice::Option resolveOption(string input){
    if (input == "1.1.1") return decor_choice::Option::Option1_1_1;
    if (input == "1.1.2") return decor_choice::Option::Option1_1_2;
    if (input == "1.2.1") return decor_choice::Option::Option1_2_1;
    if (input == "1.2.2") return decor_choice::Option::Option1_2_2;
    if (input == "1.2.3") return decor_choice::Option::Option1_2_3;
    if (input == "1.2.4") return decor_choice::Option::Option1_2_4;
    if (input == "1.2.5") return decor_choice::Option::Option1_2_5;
    if (input == "1.2.6") return decor_choice::Option::Option1_2_6;
    if (input == "1.2.7") return decor_choice::Option::Option1_2_7;
    if (input == "1.2.8") return decor_choice::Option::Option1_2_8;
    if (input == "1.2.9") return decor_choice::Option::Option1_2_9;
    if (input == "1.2.10") return decor_choice::Option::Option1_2_10;
    if (input == "1.2.11") return decor_choice::Option::Option1_2_11;
    if (input == "1.2.12") return decor_choice::Option::Option1_2_12;
    if (input == "1.3.1") return decor_choice::Option::Option1_3_1;
    if (input == "1.3.2") return decor_choice::Option::Option1_3_2;
    if (input == "1.4.1") return decor_choice::Option::Option1_4_1;
    if (input == "1.4.2") return decor_choice::Option::Option1_4_2;
    if (input == "1.5.1") return decor_choice::Option::Option1_5_1;
    if (input == "1.5.2") return decor_choice::Option::Option1_5_2;
    if (input == "1.5.3") return decor_choice::Option::Option1_5_3;
    if (input == "1.5.4") return decor_choice::Option::Option1_5_4;
    if (input == "1.5.5") return decor_choice::Option::Option1_5_5;
    if (input == "1.5.6") return decor_choice::Option::Option1_5_6;
    if (input == "1.5.7") return decor_choice::Option::Option1_5_7;
    if (input == "1.5.8") return decor_choice::Option::Option1_5_8;
    if (input == "1.5.9") return decor_choice::Option::Option1_5_9;
    if (input == "1.5.10") return decor_choice::Option::Option1_5_10;
    if (input == "1.5.11") return decor_choice::Option::Option1_5_11;
    if (input == "1.5.12") return decor_choice::Option::Option1_5_12;
    if (input == "1.6.1.1") return decor_choice::Option::Option1_6_1_1;
    if (input == "1.6.1.2") return decor_choice::Option::Option1_6_1_2;
    if (input == "1.6.1.3") return decor_choice::Option::Option1_6_1_3;
    if (input == "1.6.1.4") return decor_choice::Option::Option1_6_1_4;
    if (input == "1.6.1.5") return decor_choice::Option::Option1_6_1_5;
    if (input == "1.6.1.6") return decor_choice::Option::Option1_6_1_6;
    if (input == "1.6.1.7") return decor_choice::Option::Option1_6_1_7;
    if (input == "1.6.1.8") return decor_choice::Option::Option1_6_1_8;
    if (input == "1.6.1.9") return decor_choice::Option::Option1_6_1_9;
    if (input == "1.6.1.10") return decor_choice::Option::Option1_6_1_10;
    if (input == "1.6.1.11") return decor_choice::Option::Option1_6_1_11;
    if (input == "1.6.1.12") return decor_choice::Option::Option1_6_1_12;
    if (input == "1.6.2.1") return decor_choice::Option::Option1_6_2_1;
    if (input == "1.6.2.2") return decor_choice::Option::Option1_6_2_2;
    if (input == "1.6.2.3") return decor_choice::Option::Option1_6_2_3;
    if (input == "1.6.2.4") return decor_choice::Option::Option1_6_2_4;
    if (input == "1.6.2.5") return decor_choice::Option::Option1_6_2_5;
    if (input == "1.6.2.6") return decor_choice::Option::Option1_6_2_6;
    if (input == "1.6.2.7") return decor_choice::Option::Option1_6_2_7;
    if (input == "1.6.2.8") return decor_choice::Option::Option1_6_2_8;
    if (input == "1.6.2.9") return decor_choice::Option::Option1_6_2_9;
    if (input == "1.6.2.10") return decor_choice::Option::Option1_6_2_10;
    if (input == "1.6.2.11") return decor_choice::Option::Option1_6_2_11;
    if (input == "1.6.2.12") return decor_choice::Option::Option1_6_2_12;
    if (input == "1.7.1") return decor_choice::Option::Option1_7_1;
    if (input == "1.7.2") return decor_choice::Option::Option1_7_2;
    return decor_choice::Option::Option_invalid;
}

int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "Russian");
    wifstream input;
    wofstream output;

    string exe_name = argv[0];
    int variation;

    bool is_debug_run = (exe_name.find("kursach\\bin\\Debug\\kursach.exe") <= exe_name.length() && argc == 1);
    if (is_debug_run) {
        // Debug
        cin >> variation;
        input.open("ioFiles\\testANSI.txt");
        output.open("output.txt", ios::binary);
        if(input.is_open()){cout << "input file open ok\n";}
        else{return 2;}
        if(output.is_open()){cout << "output file open ok\n";}
        else{return 2;}
        offsets test;

        // Выбор декоратора
         // Выбираем нужный декоратор
        switch (variation)
        {
        case 1:
            v1_1_1(&input, &output, test); // 3 5 2
            break;
        case 2:
            v1_1_2(&input, &output, test);
            break;
        case 3:
            v1_2_1(&input, &output, test);
            break;
        case 4:
            v1_2_2(&input, &output, test);
            break;
        case 5:
            v1_2_3(&input, &output, test);
            break;
        case 6:
            v1_2_4(&input, &output, test);
            break;
        case 7:
            v1_2_5(&input, &output, test);
            break;
        case 8:
            v1_2_6(&input, &output, test);
            break;
        case 9:
            v1_2_7(&input, &output, test);
            break;
        case 10:
            v1_2_8(&input, &output, test);
            break;
        case 11:
            v1_2_9(&input, &output, test);
            break;
        case 12:
            v1_2_10(&input, &output, test);
            break;
        case 13:
            v1_2_11(&input, &output, test);
            break;
        case 14:
            v1_2_12(&input, &output, test);
            break;
        case 15:
            v1_3_1(&input, &output, test);
            break;
        case 16:
            v1_3_2(&input, &output, test);
            break;
        case 17:
            v1_4_1(&input, &output, test);
            break;
        case 18:
            v1_4_2(&input, &output, test);
            break;
        case 19:
            v1_5_1(&input, &output, test);
            break;
        case 20:
            v1_5_2(&input, &output, test);
            break;
        case 21:
            v1_5_3(&input, &output, test);
            break;
        case 22:
            v1_5_4(&input, &output, test);
            break;
        case 23:
            v1_5_5(&input, &output, test);
            break;
        case 24:
            v1_5_6(&input, &output, test);
            break;
        case 25:
            v1_5_7(&input, &output, test);
            break;
        case 26:
            v1_5_8(&input, &output, test);
            break;
        case 27:
            v1_5_9(&input, &output, test);
            break;
        case 28:
            v1_5_10(&input, &output, test);
            break;
        case 29:
            v1_5_11(&input, &output, test);
            break;
        case 30:
            v1_5_12(&input, &output, test);
            break;
        case 31:
            v1_6_1_1(&input, &output, test);
            break;
        case 32:
            v1_6_1_2(&input, &output, test);
            break;
        case 33:
            v1_6_1_3(&input, &output, test);
            break;
        case 34:
            v1_6_1_4(&input, &output, test);
            break;
        case 35:
            v1_6_1_5(&input, &output, test);
            break;
        case 36:
            v1_6_1_6(&input, &output, test);
            break;
        case 37:
            v1_6_1_7(&input, &output, test);
            break;
        case 38:
            v1_6_1_8(&input, &output, test);
            break;
        case 39:
            v1_6_1_9(&input, &output, test);
            break;
        case 40:
            v1_6_1_10(&input, &output, test);
            break;
        case 41:
            v1_6_1_11(&input, &output, test);
            break;
        case 42:
            v1_6_1_12(&input, &output, test);
            break;
        case 43:
            v1_6_2_1(&input, &output, test);
            break;
        case 44:
            v1_6_1_2(&input, &output, test);
            break;
        case 45:
            v1_6_2_3(&input, &output, test);
            break;
        case 46:
            v1_6_2_4(&input, &output, test);
            break;
        case 47:
            v1_6_2_5(&input, &output, test);
            break;
        case 48:
            v1_6_2_6(&input, &output, test);
            break;
        case 49:
            v1_6_2_7(&input, &output, test);
            break;
        case 50:
            v1_6_2_8(&input, &output, test);
            break;
        case 51:
            v1_6_2_9(&input, &output, test);
            break;
        case 52:
            v1_6_2_10(&input, &output, test);
            break;
        case 53:
            v1_6_2_11(&input, &output, test);
            break;
        case 54:
            v1_6_2_12(&input, &output, test);
            break;
        case 55:
            v1_7_1(&input, &output, test);
            break;
        case 56:
            v1_7_2(&input, &output, test);
            break;
        default:
            cout << "Декоратор" << endl;
            break;
        }
        input.close();
        output.close();
        return 0;
        // Debug end
    }

    if (argc != 4) {
        print_help();
        return 1;
    }

    // Release

    /*cout << "Print the number of variant(1 - 1.1.1, 2 - 1.1.2): ";
    cin >> variation;*/
    input.open(argv[1], ios::binary);
    output.open(argv[2], ios::binary);
    string decorator_choice = argv[3];
    if(input.is_open()){cout << "input file open ok\n";}
    else{return 2;}
    if(output.is_open()){cout << "output file open ok\n";}
    else{return 2;}

    offsets test;

    // Выбор декоратора
    switch (resolveOption(decorator_choice))
        {
        case decor_choice::Option::Option1_1_1:
            v1_1_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_1_2:
            v1_1_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_1:
            v1_2_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_2:
            v1_2_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_3:
            v1_2_3(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_4:
            v1_2_4(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_5:
            v1_2_5(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_6:
            v1_2_6(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_7:
            v1_2_7(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_8:
            v1_2_8(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_9:
            v1_2_9(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_10:
            v1_2_10(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_11:
            v1_2_11(&input, &output, test);
            break;
        case decor_choice::Option::Option1_2_12:
            v1_2_12(&input, &output, test);
            break;
        case decor_choice::Option::Option1_3_1:
            v1_3_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_3_2:
            v1_3_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_4_1:
            v1_4_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_4_2:
            v1_4_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_1:
            v1_5_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_2:
            v1_5_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_3:
            v1_5_3(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_4:
            v1_5_4(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_5:
            v1_5_5(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_6:
            v1_5_6(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_7:
            v1_5_7(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_8:
            v1_5_8(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_9:
            v1_5_9(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_10:
            v1_5_10(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_11:
            v1_5_11(&input, &output, test);
            break;
        case decor_choice::Option::Option1_5_12:
            v1_5_12(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_1:
            v1_6_1_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_2:
            v1_6_1_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_3:
            v1_6_1_3(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_4:
            v1_6_1_4(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_5:
            v1_6_1_5(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_6:
            v1_6_1_6(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_7:
            v1_6_1_7(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_8:
            v1_6_1_8(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_9:
            v1_6_1_9(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_10:
            v1_6_1_10(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_11:
            v1_6_1_11(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_1_12:
            v1_6_1_12(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_1:
            v1_6_2_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_2:
            v1_6_1_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_3:
            v1_6_2_3(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_4:
            v1_6_2_4(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_5:
            v1_6_2_5(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_6:
            v1_6_2_6(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_7:
            v1_6_2_7(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_8:
            v1_6_2_8(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_9:
            v1_6_2_9(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_10:
            v1_6_2_10(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_11:
            v1_6_2_11(&input, &output, test);
            break;
        case decor_choice::Option::Option1_6_2_12:
            v1_6_2_12(&input, &output, test);
            break;
        case decor_choice::Option::Option1_7_1:
            v1_7_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_7_2:
            v1_7_2(&input, &output, test);
            break;
        default:
            wcout << "To be continued..." << endl;
            break;
        }

    input.close();
    output.close();
    return 0;
}

