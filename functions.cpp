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

/**
    Вычисляет длину открытого текста
    \param[in] file Файл с исходным текстом
    \return Количество символов в передаваемом файле
*/
char symboul (wifstream* file)
{
    wchar_t ch;
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

/**
\brief Функция выводящая текущий день недели, используется в задании 1.2

\param now содержит текущее время календарное время
\param ltm содержит преобразованное значение параметра now в виде tm структуры
\param week_day содержит номер дня недели
*/
int get_week_day() // Функция для получения текущего дня недели
{
    time_t now = time(nullptr); // Получаем текущее время
    tm* ltm = localtime(&now); // Преобразуем время в tm структуру

    int week_day = ltm->tm_wday; // Номер дня недели (0-6, где 0 - Sunday, 6 - Saturday)
    //const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", // Перевод номера дня недели в текстовое представление
    //                       "Thursday", "Friday", "Saturday"};
    return week_day;
}

/**
\brief Функция выводящая текущий день месяца, используется в задании 1.2

\param now содержит текущее время календарное время
\param ltm содержит преобразованное значение параметра now в виде tm структуры
\param day_of_month содержит номер дня месяца
*/
int get_mouth_day() // То же самое для дня месяца
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    int day_of_month = ltm->tm_mday; // Номер дня месяца (1-31)

    return day_of_month;
}

/**
\brief Функция выводящая текущую минуту, используется в задании 1.2

\param now содержит текущее время календарное время
\param local_time содержит преобразованное значение параметра now в виде tm структуры
\param minute содержит значение минуты
*/
int get_minute() {
    time_t now = time(0);
    tm* local_time = localtime(&now);

    int minute = local_time->tm_min;

    return minute;
}
/*!
\brief Функция вычисляющая контрольную сумму текста.

Функция принимает на вход wifstream* input_file , bool timeDependent

\param checksum содержит в себе контрольную сумму текста
\param sdvig содержит в себе значение сдвига для латиницы, кириллицы и цифр
\param index индекс для определения позиции файла

*/
char calcChecksum(wifstream* inputFile, bool timeDependent) {
    if (!inputFile->is_open() || !inputFile->good()) {
        return 1; // Ошибка открытия файла
    }

    wchar_t ch;
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

/**
\brief Функция реализующая шифр цезаря.

Функция принимает на вход wifstream* wofstream*, stuct offsets
В качестве смещений принимаются offsets::lat, offsets::kir и offsets::num
для смещений по латинице, кириллице и числам соответственно.
При положительных значениях сдвиг вправо, при отрицательных - влево.
\param [offset::symbol_count_needed] == true повлечет запись в конец файла
одного байта - количества символов в исходном файле.
\param [offset::checksum_needed] == true повлечет запись в конец файла
одного байта - контрольной суммы.
\param [offset::checksum_time_dependent] == true повлечет зависимость
контрольной суммы от времени.
*/
int caesar(wifstream* input_file, wofstream* output_file, offsets offset){

    const wchar_t* ABC = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const wchar_t* abc = L"abcdefghijklmnopqrstuvwxyz";
    const wchar_t* abc_rus = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const wchar_t* ABC_RUS = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    const wchar_t* num = L"1234567890";
    const wchar_t* symbols[] = {ABC, abc, abc_rus, ABC_RUS, num};
    wchar_t x, y;

    if(offset.symbol_count_needed)
    {
        x = symboul(input_file);
    }
    if(offset.checksum_needed)
    {
        y = calcChecksum(input_file, offset.checksum_time_dependent);
    }

    bool symbol_found = false;
    wchar_t current_byte = 0;
    wchar_t additional_utf_byte = 0;
    int crypted_symbol_pos = 0;
    int crypted_symbol_abc = 0;
    while (input_file[0].get(current_byte)){
        symbol_found = false;
        /*
        if(current_byte == 0xd0 || current_byte == 0xd1){ //кирилица в ютф8
            input_file->get(additional_utf_byte); current_byte = additional_utf_byte + current_byte*256;
            current_byte -= 4;
            wcout << current_byte;
            continue;
        }
        */
        for(int i = 0; i < 5; i++){
            for(size_t j = 0; j < wcslen(symbols[i]); j++)
            {
                if(current_byte == symbols[i][j])
                {
                    symbol_found = true;
                    crypted_symbol_abc = i;
                    if(i < 2){
                        crypted_symbol_pos = (j + offset.lat + wcslen(symbols[i])*16) % wcslen(symbols[i]);
                    }
                    else if(i < 4){
                        crypted_symbol_pos = (j + offset.kir + wcslen(symbols[i])*16) % wcslen(symbols[i]);
                    }
                    else{
                        crypted_symbol_pos = (j + offset.num + wcslen(symbols[i])*16) % wcslen(symbols[i]);
                    }
                    break;
                }

            }
        }
        if(symbol_found){wcout << symbols[crypted_symbol_abc][crypted_symbol_pos]; output_file[0].put(symbols[crypted_symbol_abc][crypted_symbol_pos]);}
        else {wcout << current_byte; output_file[0].put(current_byte);}
    }
    if(offset.symbol_count_needed)
    {
        wcout << x%256;
        output_file->put(x%256);
    }
    if(offset.checksum_needed)
    {
        wcout << y%256;
        output_file->put(y%256);
    }
    input_file->clear();
    input_file->seekg(0, ios_base::beg);
    return 0;


}

/**
\brief Функция выводящая подсказку при неправильном запуске программы
*/
void print_help(){          //вывод помощи
    cout << "Usage:\n\t kursach.exe [input_file] [output_file] [cipher_number]\n";
}
