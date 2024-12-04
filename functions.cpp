/**
\file
\brief Файл содержащий основные функции необходимые для работы программы

*/
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;


uint32_t int_pow(uint32_t base, uint32_t power){
    uint32_t answer = 1;
    for(uint32_t i = 0; i < power; i++){
        answer *= base;
    }
    return answer;
}


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

uint32_t symboul (ifstream* file)
{
    char ch;
    unsigned char prev_char = 0x00;
    uint32_t charcount = 0;
    //читаем посимвольно весь файл
    bool unicode_beg = false;
    bool unicode_cont = false;
    while(file->get(ch))
    {
        if (!(prev_char == 0xd0) && (static_cast<unsigned char>(ch) == 0xa8 || static_cast<unsigned char>(ch) == 0xb8)){
            charcount++;
        }

        if (unicode_beg && (static_cast<unsigned char>(ch) <= 0xbf && static_cast<unsigned char>(ch) >= 0x80)){
            unicode_cont = true;
        }
        else if (unicode_beg && unicode_cont){
            bool unicode_beg = false;
            bool unicode_cont = false;
            charcount++;
        }
        else if (static_cast<unsigned char>(ch) >= 0xc0){
            charcount++;
        }


        if (ch=='\r') //т.к. Enter в Windows считается за два символа
        {
            prev_char = static_cast<unsigned char>(ch);
            continue;
        }
        else if (static_cast<unsigned char>(ch) >= 0xc0){
            unicode_beg = true;
        }
        else if (unicode_beg){
            prev_char = static_cast<unsigned char>(ch);
            continue;
        }
        else {charcount++;}

        prev_char = static_cast<unsigned char>(ch);
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

uint32_t calcChecksum(ifstream* inputFile, bool timeDependent) {
    if (!inputFile->is_open() || !inputFile->good()) {
        return 1; // Ошибка открытия файла
    }

    char ch;
    uint32_t checksum = 0;
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

    return checksum;
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
    (char)0xD2, (char)0xD3, (char)0xD4, (char)0xD5, (char)0xD6, (char)0xD7, (char)0xD8,
    (char)0xD9, (char)0xDA, (char)0xDB, (char)0xDC, (char)0xDD, (char)0xDE, (char)0xDF};

    char ABC_RUS_UTF8[][2] = {{(char)0xD0, (char)0x90}, {(char)0xD0, (char)0x91}, {(char)0xD0, (char)0x92},
    {(char)0xD0, (char)0x93}, {(char)0xD0, (char)0x94}, {(char)0xD0, (char)0x95}, {(char)0xD0, (char)0x81},
    {(char)0xD0, (char)0x96}, {(char)0xD0, (char)0x97}, {(char)0xD0, (char)0x98}, {(char)0xD0, (char)0x99},
    {(char)0xD0, (char)0x9A}, {(char)0xD0, (char)0x9B}, {(char)0xD0, (char)0x9C}, {(char)0xD0, (char)0x9D},
    {(char)0xD0, (char)0x9E}, {(char)0xD0, (char)0x9F}, {(char)0xD0, (char)0xA0}, {(char)0xD0, (char)0xA1},
    {(char)0xD0, (char)0xA2}, {(char)0xD0, (char)0xA3}, {(char)0xD0, (char)0xA4}, {(char)0xD0, (char)0xA5},
    {(char)0xD0, (char)0xA6}, {(char)0xD0, (char)0xA7}, {(char)0xD0, (char)0xA8}, {(char)0xD0, (char)0xA9},
    {(char)0xD0, (char)0xAA}, {(char)0xD0, (char)0xAB}, {(char)0xD0, (char)0xAC}, {(char)0xD0, (char)0xAD},
    {(char)0xD0, (char)0xAE}, {(char)0xD0, (char)0xAF}};

    char abc_rus_UTF8[][2] = {{(char)0xD0, (char)0xB0}, {(char)0xD0, (char)0xB1}, {(char)0xD0, (char)0xB2},
    {(char)0xD0, (char)0xB3}, {(char)0xD0, (char)0xB4}, {(char)0xD0, (char)0xB5}, {(char)0xD1, (char)0x91},
    {(char)0xD0, (char)0xB6}, {(char)0xD0, (char)0xB7}, {(char)0xD0, (char)0xB8}, {(char)0xD0, (char)0xB9},
    {(char)0xD0, (char)0xBA}, {(char)0xD0, (char)0xBB}, {(char)0xD0, (char)0xBC}, {(char)0xD0, (char)0xBD},
    {(char)0xD0, (char)0xBE}, {(char)0xD0, (char)0xBF}, {(char)0xD1, (char)0x80}, {(char)0xD1, (char)0x81},
    {(char)0xD1, (char)0x82}, {(char)0xD1, (char)0x83}, {(char)0xD1, (char)0x84}, {(char)0xD1, (char)0x85},
    {(char)0xD1, (char)0x86}, {(char)0xD1, (char)0x87}, {(char)0xD1, (char)0x88}, {(char)0xD1, (char)0x89},
    {(char)0xD1, (char)0x8A}, {(char)0xD1, (char)0x8B}, {(char)0xD1, (char)0x8C}, {(char)0xD1, (char)0x8D},
    {(char)0xD1, (char)0x8E}, {(char)0xD1, (char)0x8F}};

    string num = "1234567890";
    string symbols[] = {ABC, abc, abc_rus_ANSI, ABC_RUS_ANSI, num};
    uint32_t x, y;

    if(offset.symbol_count_needed)
    {
        x = symboul(input_file);
    }
    if(offset.checksum_needed)
    {
        y = calcChecksum(input_file, offset.checksum_time_dependent);
    }
    bool symbol_found = false;
    bool addicional_byte_is_good = false;

    char current_byte = 0;
    char addicional_byte = 0;
    unsigned char integer_byte_split= 0;

    int crypted_symbol_pos = 0;
    int crypted_symbol_abc = 0;

    while (input_file[0].get(current_byte)){ //Шифрование
        symbol_found = false;
        if((unsigned char)current_byte == 0xd1 || (unsigned char)current_byte == 0xd0) //Шифрование кириллицы в UTF-8
        {
            input_file->get(addicional_byte);
            for(int i = 0; i < 33; i++){
                if(addicional_byte == abc_rus_UTF8[i][1] && current_byte == abc_rus_UTF8[i][0]){
                    crypted_symbol_pos = (i + offset.kir + 33*16) % 33;
                    crypted_symbol_abc = 0;
                    symbol_found = true;
                }
                else if(addicional_byte == ABC_RUS_UTF8[i][1] && current_byte == ABC_RUS_UTF8[i][0]){
                    crypted_symbol_pos = (i + offset.kir + 33*16) % 33;
                    crypted_symbol_abc = 1;
                    symbol_found = true;
                }
            }
            if(symbol_found && crypted_symbol_abc == 0){
                cout << abc_rus_UTF8[crypted_symbol_pos][0]; output_file->put(abc_rus_UTF8[crypted_symbol_pos][0]);
                cout << abc_rus_UTF8[crypted_symbol_pos][1]; output_file->put(abc_rus_UTF8[crypted_symbol_pos][1]);
            }
            else if(symbol_found && crypted_symbol_abc == 1){
                cout << ABC_RUS_UTF8[crypted_symbol_pos][0]; output_file->put(ABC_RUS_UTF8[crypted_symbol_pos][0]);
                cout << ABC_RUS_UTF8[crypted_symbol_pos][1]; output_file->put(ABC_RUS_UTF8[crypted_symbol_pos][1]);
            }
            else if(!symbol_found && (unsigned char)current_byte == 0xd0){
                cout << ABC_RUS_ANSI[(17+ offset.kir + 33*16) % 33]; output_file->put(ABC_RUS_ANSI[(17+ offset.kir + 33*16) % 33]);
                current_byte = addicional_byte;
            }
            else if(!symbol_found && (unsigned char)current_byte == 0xd1){
                cout << ABC_RUS_ANSI[(18+ offset.kir + 33*16) % 33]; output_file->put(ABC_RUS_ANSI[(18+ offset.kir + 33*16) % 33]);
                current_byte = addicional_byte;
            }
        }
        if(symbol_found){continue;}
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
        integer_byte_split = 0;
        for (int i = 0; i < 4; i++){
            integer_byte_split = ((x / int_pow(256, i))% 256);
            output_file->put((char)integer_byte_split);
        }

    }

    if(offset.checksum_needed)
    {
        integer_byte_split = 0;
        for (int i = 0; i < 4; i++){
            integer_byte_split = ((y / int_pow(256, i))% 256);
            output_file->put((char)integer_byte_split);
        }
    }
    input_file->clear();
    input_file->seekg(0, ios_base::beg);
    return 0;
}
