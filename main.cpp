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

    return decor_choice::Option::Option_invalid;
}

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

        // ����� ����������
         // �������� ������ ���������
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
        case 16:
            v1_3_2(&input, &output, test);
            break;
        case 17:
            v1_4_1(&input, &output, test);
            break;
        case 18:
            v1_4_2(&input, &output, test);
            break;
        default:
            cout << "���������" << endl;
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

    // ����� ����������
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
        default:
            cout << "To be continued..." << endl;
            break;
        }

    input.close();
    output.close();
    return 0;
}

