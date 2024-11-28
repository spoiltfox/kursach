/**
\file
\brief Основной файл проекта

В данном файле содержится логика ввода-вывода программы
*/
#include "functions.h"
#include "caesar_variations.h"
#include "help.h"
#include <string.h>
using namespace std;

///Набор возможных вариаций шифра Цезаря
namespace decor_choice {
    enum Option
    {
        Option_invalid,///< Неправильный ввод вариации шифра
        Option1_1_1,///< Выбор пункта Ш1.1.1
        Option1_1_2,///< Выбор пункта Ш1.1.2
        Option1_2_1,///< Выбор пункта Ш1.2.1
        Option1_2_2,///< Выбор пункта Ш1.2.2
        Option1_2_3,///< Выбор пункта Ш1.2.3
        Option1_2_4,///< Выбор пункта Ш1.2.4
        Option1_2_5,///< Выбор пункта Ш1.2.5
        Option1_2_6,///< Выбор пункта Ш1.2.6
        Option1_2_7,///< Выбор пункта Ш1.2.7
        Option1_2_8,///< Выбор пункта Ш1.2.8
        Option1_2_9,///< Выбор пункта Ш1.2.9
        Option1_2_10,///< Выбор пункта Ш1.2.10
        Option1_2_11,///< Выбор пункта Ш1.2.11
        Option1_2_12,///< Выбор пункта Ш1.2.12
        Option1_3_1,///< Выбор пункта Ш1.3.1
        Option1_3_2,///< Выбор пункта Ш1.3.2
        Option1_4_1,///< Выбор пункта Ш1.4.1
        Option1_4_2,///< Выбор пункта Ш1.4.2
        Option1_5_1,///< Выбор пункта Ш1.5.1
        Option1_5_2,///< Выбор пункта Ш1.5.2
        Option1_5_3,///< Выбор пункта Ш1.5.3
        Option1_5_4,///< Выбор пункта Ш1.5.4
        Option1_5_5,///< Выбор пункта Ш1.5.5
        Option1_5_6,///< Выбор пункта Ш1.5.6
        Option1_5_7,///< Выбор пункта Ш1.5.7
        Option1_5_8,///< Выбор пункта Ш1.5.8
        Option1_5_9,///< Выбор пункта Ш1.5.9
        Option1_5_10,///< Выбор пункта Ш1.5.10
        Option1_5_11,///< Выбор пункта Ш1.5.11
        Option1_5_12,///< Выбор пункта Ш1.5.12
        Option1_6_1_1,///< Выбор пункта Ш1.6.1.1
        Option1_6_1_2,///< Выбор пункта Ш1.6.1.2
        Option1_6_1_3,///< Выбор пункта Ш1.6.1.3
        Option1_6_1_4,///< Выбор пункта Ш1.6.1.4
        Option1_6_1_5,///< Выбор пункта Ш1.6.1.5
        Option1_6_1_6,///< Выбор пункта Ш1.6.1.6
        Option1_6_1_7,///< Выбор пункта Ш1.6.1.7
        Option1_6_1_8,///< Выбор пункта Ш1.6.1.8
        Option1_6_1_9,///< Выбор пункта Ш1.6.1.9
        Option1_6_1_10,///< Выбор пункта Ш1.6.1.10
        Option1_6_1_11,///< Выбор пункта Ш1.6.1.11
        Option1_6_1_12,///< Выбор пункта Ш1.6.1.12
        Option1_6_2_1,///< Выбор пункта Ш1.6.2.1
        Option1_6_2_2,///< Выбор пункта Ш1.6.2.2
        Option1_6_2_3,///< Выбор пункта Ш1.6.2.3
        Option1_6_2_4,///< Выбор пункта Ш1.6.2.4
        Option1_6_2_5,///< Выбор пункта Ш1.6.2.5
        Option1_6_2_6,///< Выбор пункта Ш1.6.2.6
        Option1_6_2_7,///< Выбор пункта Ш1.6.2.7
        Option1_6_2_8,///< Выбор пункта Ш1.6.2.8
        Option1_6_2_9,///< Выбор пункта Ш1.6.2.9
        Option1_6_2_10,///< Выбор пункта Ш1.6.2.10
        Option1_6_2_11,///< Выбор пункта Ш1.6.2.11
        Option1_6_2_12,///< Выбор пункта Ш1.6.2.12
        Option1_7_1,///< Выбор пункта Ш1.7.1
        Option1_7_2,///< Выбор пункта Ш1.7.2
        Option1_8_1_1,///< Выбор пункта Ш1.8.1.1
        Option1_8_1_2,///< Выбор пункта Ш1.8.1.2
        Option1_8_1_3,///< Выбор пункта Ш1.8.1.3
        Option1_8_1_4,///< Выбор пункта Ш1.8.1.4
        Option1_8_1_5,///< Выбор пункта Ш1.8.1.5
        Option1_8_1_6,///< Выбор пункта Ш1.8.1.6
        Option1_8_1_7,///< Выбор пункта Ш1.8.1.7
        Option1_8_1_8,///< Выбор пункта Ш1.8.1.8
        Option1_8_1_9,///< Выбор пункта Ш1.8.1.9
        Option1_8_1_10,///< Выбор пункта Ш1.8.1.10
        Option1_8_1_11,///< Выбор пункта Ш1.8.1.11
        Option1_8_1_12,///< Выбор пункта Ш1.8.1.12
        Option1_8_2_1,///< Выбор пункта Ш1.8.2.1
        Option1_8_2_2,///< Выбор пункта Ш1.8.2.2
        Option1_8_2_3,///< Выбор пункта Ш1.8.2.3
        Option1_8_2_4,///< Выбор пункта Ш1.8.2.4
        Option1_8_2_5,///< Выбор пункта Ш1.8.2.5
        Option1_8_2_6,///< Выбор пункта Ш1.8.2.6
        Option1_8_2_7,///< Выбор пункта Ш1.8.2.7
        Option1_8_2_8,///< Выбор пункта Ш1.8.2.8
        Option1_8_2_9,///< Выбор пункта Ш1.8.2.9
        Option1_8_2_10,///< Выбор пункта Ш1.8.2.10
        Option1_8_2_11,///< Выбор пункта Ш1.8.2.11
        Option1_8_2_12,///< Выбор пункта Ш1.8.2.12
    };
}
/**
    \brief Функция для сопоставления вводимого пункта курсовой работы с вариацией шифра Цезаря
    \param[in] input Номер пункта курсовой работы, совпадающий с желаемой вариацией шифра Цезаря
    \return Пункт, соответствующий вводу
*/
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
    if (input == "1.8.1.1") return decor_choice::Option::Option1_8_1_1;
    if (input == "1.8.1.2") return decor_choice::Option::Option1_8_1_2;
    if (input == "1.8.1.3") return decor_choice::Option::Option1_8_1_3;
    if (input == "1.8.1.4") return decor_choice::Option::Option1_8_1_4;
    if (input == "1.8.1.5") return decor_choice::Option::Option1_8_1_5;
    if (input == "1.8.1.6") return decor_choice::Option::Option1_8_1_6;
    if (input == "1.8.1.7") return decor_choice::Option::Option1_8_1_7;
    if (input == "1.8.1.8") return decor_choice::Option::Option1_8_1_8;
    if (input == "1.8.1.9") return decor_choice::Option::Option1_8_1_9;
    if (input == "1.8.1.10") return decor_choice::Option::Option1_8_1_10;
    if (input == "1.8.1.11") return decor_choice::Option::Option1_8_1_11;
    if (input == "1.8.1.12") return decor_choice::Option::Option1_8_1_12;
    if (input == "1.8.2.1") return decor_choice::Option::Option1_8_2_1;
    if (input == "1.8.2.2") return decor_choice::Option::Option1_8_2_2;
    if (input == "1.8.2.3") return decor_choice::Option::Option1_8_2_3;
    if (input == "1.8.2.4") return decor_choice::Option::Option1_8_2_4;
    if (input == "1.8.2.5") return decor_choice::Option::Option1_8_2_5;
    if (input == "1.8.2.6") return decor_choice::Option::Option1_8_2_6;
    if (input == "1.8.2.7") return decor_choice::Option::Option1_8_2_7;
    if (input == "1.8.2.8") return decor_choice::Option::Option1_8_2_8;
    if (input == "1.8.2.9") return decor_choice::Option::Option1_8_2_9;
    if (input == "1.8.2.10") return decor_choice::Option::Option1_8_2_10;
    if (input == "1.8.2.11") return decor_choice::Option::Option1_8_2_11;
    if (input == "1.8.2.12") return decor_choice::Option::Option1_8_2_12;
    return decor_choice::Option::Option_invalid;
}

/**
    \param[in] argc Количество аргументов передаваемых через консоль
    \param[in] argv Массив аргументов передаваемых через косноль
    \return Код завершения программы
*/
int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "Russian");
    ifstream input;
    ofstream output;
    string exe_name = argv[0];
    int variation;

    bool is_debug_run = (exe_name.find("kursach\\bin\\Debug\\kursach") <= exe_name.length() && argc == 1);
    if (is_debug_run) {
        // Debug
        cin >> variation;
        input.open("ioFiles/testUTF-8.txt");
        output.open("output.txt", ios::binary);
        if(input.is_open()){cout << "input file open ok\n";}
        else{return 2;}
        if(output.is_open()){cout << "output file open ok\n";}
        else{return 2;}
        offsets test;

        output << endl;
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
        case 57:
            v1_8_1_1(&input, &output, test);
            break;
        case 58:
            v1_8_1_2(&input, &output, test);
            break;
        case 59:
            v1_8_1_3(&input, &output, test);
            break;
        case 60:
            v1_8_1_4(&input, &output, test);
            break;
        case 61:
            v1_8_1_5(&input, &output, test);
            break;
        case 62:
            v1_8_1_6(&input, &output, test);
            break;
        case 63:
            v1_8_1_7(&input, &output, test);
            break;
        case 64:
            v1_8_1_8(&input, &output, test);
            break;
        case 65:
            v1_8_1_9(&input, &output, test);
            break;
        case 66:
            v1_8_1_10(&input, &output, test);
            break;
        case 67:
            v1_8_1_11(&input, &output, test);
            break;
        case 68:
            v1_8_1_12(&input, &output, test);
            break;
        case 69:
            v1_8_2_1(&input, &output, test);
            break;
        case 70:
            v1_8_2_2(&input, &output, test);
            break;
        case 71:
            v1_8_2_3(&input, &output, test);
            break;
        case 72:
            v1_8_2_4(&input, &output, test);
            break;
        case 73:
            v1_8_2_5(&input, &output, test);
            break;
        case 74:
            v1_8_2_6(&input, &output, test);
            break;
        case 75:
            v1_8_2_7(&input, &output, test);
            break;
        case 76:
            v1_8_2_8(&input, &output, test);
            break;
        case 77:
            v1_8_2_9(&input, &output, test);
            break;
        case 78:
            v1_8_2_10(&input, &output, test);
            break;
        case 79:
            v1_8_2_11(&input, &output, test);
            break;
        case 80:
            v1_8_2_12(&input, &output, test);
            break;
        default:
            cout << "This cipher option has not been added yet" << endl;
            break;
        }
        input.close();
        output.close();
        return 0;
        // Debug end
    }
    if (argc == 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)){
        helpWithCipherNumbers();
        return 0;

    }
    if (argc == 3 && (strcmp(argv[2], "--help") == 0 || strcmp(argv[2], "-h") == 0)) {
        string decorator_choice = argv[1];
        switch (resolveOption(decorator_choice)) {
            case decor_choice::Option::Option1_1_1:
                help_1_1_1();
                break;
            case decor_choice::Option::Option1_1_2:
                help_1_1_2();
                break;
            case decor_choice::Option::Option1_2_1:
                help_1_2_1();
                break;
            case decor_choice::Option::Option1_2_2:
                help_1_2_2();
                break;
            case decor_choice::Option::Option1_2_3:
                help_1_2_3();
                break;
            case decor_choice::Option::Option1_2_4:
                help_1_2_4();
                break;
            case decor_choice::Option::Option1_2_5:
                help_1_2_5();
                break;
            case decor_choice::Option::Option1_2_6:
                help_1_2_6();
                break;
            case decor_choice::Option::Option1_2_7:
                help_1_2_7();
                break;
            case decor_choice::Option::Option1_2_8:
                help_1_2_8();
                break;
            case decor_choice::Option::Option1_1_9:
                help_1_2_9();
                break;
            case decor_choice::Option::Option1_2_10:
                help_1_2_10();
                break;
            case decor_choice::Option::Option1_2_11:
                help_1_2_11();
                break;
            case decor_choice::Option::Option1_2_12:
                help_1_2_12();
                break;
            case decor_choice::Option::Option1_3_1:
                help_1_3_1();
                break;
            case decor_choice::Option::Option1_3_2:
                help_1_3_2();
                break;
            case decor_choice::Option::Option1_4_1:
                help_1_4_1();
                break;
            case decor_choice::Option::Option1_4_2:
                help_1_4_2();
                break;
            case decor_choice::Option::Option1_5_1:
                help_1_5_1();
                break;
            case decor_choice::Option::Option1_5_2:
                help_1_5_2();
                break;
            case decor_choice::Option::Option1_5_3:
                help_1_5_3();
                break;
            case decor_choice::Option::Option1_5_4:
                help_1_5_4();
                break;
            case decor_choice::Option::Option1_5_5:
                help_1_5_5();
                break;
            case decor_choice::Option::Option1_5_6:
                help_1_5_6();
                break;
            case decor_choice::Option::Option1_5_7:
                help_1_5_7();
                break;
            case decor_choice::Option::Option1_5_8:
                help_1_5_8();
                break;
            case decor_choice::Option::Option1_5_9:
                help_1_5_9();
                break;
            case decor_choice::Option::Option1_5_10:
                help_1_5_10();
                break;
            case decor_choice::Option::Option1_5_11:
                help_1_5_11();
                break;
            case decor_choice::Option::Option1_5_12:
                help_1_5_12();
                break;
            default:
                cout << "Help is not available for the specified cipher option." << endl;
                break;
        }
        return(0);
    }

    if (argc != 4) {
        print_help();
        cout << "To get help on existing encoder numbers, enter --help\n";
        return 1;
    }

    // Release
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
        case decor_choice::Option::Option1_8_1_1:
            v1_8_1_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_2:
            v1_8_1_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_3:
            v1_8_1_3(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_4:
            v1_8_1_4(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_5:
            v1_8_1_5(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_6:
            v1_8_1_6(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_7:
            v1_8_1_7(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_8:
            v1_8_1_8(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_9:
            v1_8_1_9(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_10:
            v1_8_1_10(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_11:
            v1_8_1_11(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_1_12:
            v1_8_1_12(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_1:
            v1_8_2_1(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_2:
            v1_8_2_2(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_3:
            v1_8_2_3(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_4:
            v1_8_2_4(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_5:
            v1_8_2_5(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_6:
            v1_8_2_6(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_7:
            v1_8_2_7(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_8:
            v1_8_2_8(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_9:
            v1_8_2_9(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_10:
            v1_8_2_10(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_11:
            v1_8_2_11(&input, &output, test);
            break;
        case decor_choice::Option::Option1_8_2_12:
            v1_8_2_12(&input, &output, test);
            break;
        default:
            cout << "This cipher option is not available" << endl;
            break;
        }

    input.close();
    output.close();
    return 0;
}

