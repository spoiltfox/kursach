#include "functions.h"
#include "caesar_variations.h"


using namespace std;

int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "Russian");
    ifstream input;
    ofstream output;

    string exe_name = argv[0];
    int decorator_chosoe;
    cin >> decorator_chosoe;

    bool is_debug_run = (exe_name.find("kursach\\bin\\Debug\\kursach.exe") <= exe_name.length() && argc == 1);
    if (is_debug_run) {
        // Debug
        input.open("test.txt", ios::binary);
        offsets test;
        test.kir = 1; test.lat = -54; test.num = -1;

        // Выбор декоратора
         // Выбираем нужный декоратор
        switch (decorator_chosoe)
        {
        case 1:
            shift_decorator(&input, &output, test);
            break;
        case 2:
            time_based_decorator(&input, &output, test);
            break;
        default:
            cout << "Декоратор" << endl;
            break;
        }
        input.close();
        return 0;
    }

    if (argc != 4) {
        print_help();
        return 1;
    }

    // Release
    input.open(argv[1], ios::binary);
    output.open(argv[2], ios::binary);

    offsets test;
    test.kir = 0; test.lat = 0; test.num = 0;

    // Выбор декоратора
    switch (decorator_chosoe)
        {
        case 1:
            shift_decorator(&input, &output, test);
            break;
        case 2:
            time_based_decorator(&input, &output, test);
            break;
        default:
            cout << "Декоратор гавна" << endl;
            break;
        }

    input.close();
    output.close();
    return 0;
}

