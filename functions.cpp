/**
\file
\brief Файл содержащий основные функции необходимые для работы программы

*/
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

/**
\brief Структура для передачи параметров в caesar()
*/
struct offsets { //в случае неообходимости могут быть добавлены дополнительные переменные в структуру
    int lat = 0; ///< Сдвиг для латиницы
    int kir = 0; ///< Сдвиг для кириллицы
    int num = 0; ///< Сдвиг для чисел
    bool symbol_count_needed = false; ///< Необходимость вычисления количества символов
    bool checksum_needed = false; ///< Необходимость вычисления контрольной суммы
    bool checksum_time_dependent = false; ///< Зависит ли контрольная сумма от времени
};

char symboul (ifstream* file)
{
    char ch;
    char charcount=0;
    //читаем посимвольно весь файл
    while(file->get(ch))
    {
        if (ch!='\r') //т.к. Enter в Windows считается за два символа
        {
            ++charcount;
        }
    }

    file->clear();
    file->seekg(0, ios_base::beg);
    return charcount;
}

int get_week_day() // Функция для получения текущего дня недели
{
    time_t now = time(nullptr); // Получаем текущее время
    tm* ltm = localtime(&now); // Преобразуем время в tm структуру

    int week_day = ltm->tm_wday; // Номер дня недели (0-6, где 0 - Sunday, 6 - Saturday)
    //const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", // Перевод номера дня недели в текстовое представление
    //                       "Thursday", "Friday", "Saturday"};
    return week_day;
}

int get_mouth_day() // То же самое для дня месяца
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    int day_of_month = ltm->tm_mday; // Номер дня месяца (1-31)

    return day_of_month;
}

int get_minute() {
    time_t now = time(0);
    tm* local_time = localtime(&now);

    int minute = local_time->tm_min;

    return minute;
}

char calcChecksum(ifstream* inputFile, bool timeDependent) {
    if (!inputFile->is_open() || !inputFile->good()) {
        return 1; // Ошибка открытия файла
    }

    char ch;
    unsigned long long checksum = 0;
    unsigned long long sdvig = 0;
    unsigned long long index = 0; // Индекс для определения позиции символа

    while (inputFile->get(ch)) {
        // Определяем сдвиг в зависимости от символа
        if (isalpha(ch)) { // Латинские буквы
            sdvig = (ch >= L'a' && ch <= L'z') ? 3 : 3; // Латинские буквы - сдвиг 3
        } else if ((ch >= 0xC0 && ch <= 0xFF) || (ch >= 0xE0 && ch <= 0xEF)) { // Кириллица в UTF-8
            sdvig = 5; // Кириллица - сдвиг 5
        } else if (isdigit(ch)) { // Цифры
            sdvig = 2; // Цифры - сдвиг 2
        } else {
            sdvig = 0; // Прочие символы
        }

        // Применяем сдвиг и обновляем контрольную сумму, учитывая индекс символа
        checksum += (ch + sdvig) * (index + 1); // Увеличиваем значение в зависимости от позиции
        index++; // Увеличиваем индекс
    }

    if (timeDependent) {
        // Добавляем текущее время к контрольной сумме
        checksum += get_minute() % 2; // Пример
    }

    inputFile->clear();
    inputFile->seekg(0, ios_base::beg);

    return (char)checksum;
}

int caesar(ifstream* input_file, ofstream* output_file, offsets offset){

    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string abc = "abcdefghijklmnopqrstuvwxyz";
    string abc_rus_ANSI = {(char)0xE0, (char)0xE1, (char)0xE2, (char)0xE3, (char)0xE4,
    (char)0xE5, (char)0xB8, (char)0xE6, (char)0xE7, (char)0xE8, (char)0xE9, (char)0xEA,
    (char)0xEB, (char)0xEC, (char)0xED, (char)0xEE, (char)0xEF, (char)0xF0, (char)0xF1,
    (char)0xF2, (char)0xF3, (char)0xF4, (char)0xF5, (char)0xF6, (char)0xF7, (char)0xF8,
    (char)0xF9, (char)0xFA, (char)0xFB, (char)0xFC, (char)0xFD, (char)0xFE, (char)0xFF};
    string ABC_RUS_ANSI = {(char)0xC0, (char)0xC1, (char)0xC2, (char)0xC3, (char)0xC4,
    (char)0xC5, (char)0xA8, (char)0xC6, (char)0xC7, (char)0xC8, (char)0xC9, (char)0xCA,
    (char)0xCB, (char)0xCC, (char)0xCD, (char)0xCE, (char)0xCF, (char)0xD0, (char)0xD1,
    (char)0xD2, (char)0xD3, (char)0xD4, (char)0xD5, (char)0xD6, (char)0xD7, (char)0xD8, (char)0xD9,
    (char)0xDA, (char)0xDB, (char)0xDC, (char)0xDD, (char)0xDE, (char)0xDF};
    string num = "1234567890";
    string symbols[] = {ABC, abc, abc_rus_ANSI, ABC_RUS_ANSI, num};
    char x, y;

    if(offset.symbol_count_needed)
    {
        x = symboul(input_file);
    }
    if(offset.checksum_needed)
    {
        y = calcChecksum(input_file, offset.checksum_time_dependent);
    }
    bool symbol_found = false;
    char current_byte = 0;
    int crypted_symbol_pos = 0;
    int crypted_symbol_abc = 0;
    while (input_file[0].get(current_byte)){
        symbol_found = false;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < symbols[i].length(); j++)
            {
                if(current_byte == symbols[i][j])
                {
                    symbol_found = true;
                    crypted_symbol_abc = i;
                    if(i < 2){
                        crypted_symbol_pos = (j + offset.lat + symbols[i].length()*16) % symbols[i].length();
                    }
                    else if(i < 4){
                        crypted_symbol_pos = (j + offset.kir + symbols[i].length()*16) % symbols[i].length();
                    }
                    else{
                        crypted_symbol_pos = (j + offset.num + symbols[i].length()*16) % symbols[i].length();
                    }
                    break;
                }
            }
        }
        if(symbol_found){cout << symbols[crypted_symbol_abc][crypted_symbol_pos]; output_file[0].put(symbols[crypted_symbol_abc][crypted_symbol_pos]);}
        else {cout << current_byte; output_file[0].put(current_byte);}
    }
    if(offset.symbol_count_needed)
    {
        cout << x;
        output_file[0].put(x);
    }
    if(offset.checksum_needed)
    {
        cout << y;
        output_file[0].put(y);
    }
    input_file->clear();
    input_file->seekg(0, ios_base::beg);
    return 0;
}


void print_help(){          //вывод помощи
    cout << "Usage:\n\t kursach.exe [input_file] [output_file] [cipher_number]\n";
}
