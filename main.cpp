#include "functions.h"
//#include "caesar_variations.h"



int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    ifstream input;
    ofstream output;

    string exe_name = argv[0];





    bool is_debug_run = (exe_name.find("kursach\\bin\\Debug\\kursach.exe") <= exe_name.length() && argc == 1);
    if(is_debug_run){

                //      Debug
    //  build and run from code::blocks
    // место для записи отладочных скриптов
        input.open("ioFiles/test.txt", ios::binary);
        offsets test;
        test.kir = 1; test.lat = -54; test.num = -1;

        symboul(&input);
        caesar(&input, &output, test);
        input.close();
        return 0;
    //  Debug End  /////////////////////////
    }

    if(argc != 3){
        print_help();
        return 1;
    }
    //      Release
    // место для красивейшего кода, срабатывает при запуске с двумя аргументами
    // требуется проверка на открытие
    input.open(argv[1]), ios::binary;
    output.open(argv[2], ios::binary);

    offsets test;
    test.kir = 1; test.lat = 1; test.num = -1;
    caesar(&input, &output, test);


    input.close();
    output.close();
    return 1;
}

