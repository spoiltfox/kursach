#include "functions.h"
#include "caesar_variations.h"


using namespace std;

int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "Russian");
    ifstream input;
    ofstream output;

    string exe_name = argv[0];
    int variation;

    bool is_debug_run = (exe_name.find("kursach\\bin\\Debug\\kursach.exe") <= exe_name.length() && argc == 1);
    if (is_debug_run) {
        // Debug
        cin >> variation;
        input.open("ioFiles\\test.txt", ios::binary);
        output.open("output.txt", ios::binary);
        if(input.is_open()){cout << "input file open ok\n";}
        else{return 2;}
        if(output.is_open()){cout << "output file open ok\n";}
        else{return 2;}
        offsets test;
        test.kir = 1; test.lat = 1; test.num = 1;

        // Выбор декоратора
         // Выбираем нужный декоратор
        switch (variation)
        {
        case 1:
            v1_1_1(&input, &output, test);
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
        default:
            cout << "Декоратор" << endl;
            break;
        }
        input.close();
        output.close();
        return 0;
        // Debug end
    }

    if (argc != 3) {
        print_help();
        return 1;
    }

    // Release
    cout << "Print the number of variant(1 - 1.1.1, 2 - 1.1.2): ";
    cin >> variation;
    input.open(argv[1], ios::binary);
    output.open(argv[2], ios::binary);
    if(input.is_open()){cout << "input file open ok\n";}
    else{return 2;}
    if(output.is_open()){cout << "output file open ok\n";}
    else{return 2;}

    offsets test;

    // Выбор декоратора
    switch (variation)
        {
        case 1:
            v1_1_1(&input, &output, test);
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
        default:
            cout << "To be continued..." << endl;
            break;
        }

    input.close();
    output.close();
    return 0;
}

