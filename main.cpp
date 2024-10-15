#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;
struct offsets {
    int lat;
    int kir;
    int num;
};

void caesar(ifstream* input_file, ofstream* output_file, offsets offset){
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string abc = "abcdefghijklmnopqrstuvwxyz";
    string abc_rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    string ABC_RUS = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string num = "1234567890";
    string symbols[] = {ABC, abc, abc_rus, ABC_RUS, num};

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
                        crypted_symbol_pos = (j + offset.lat + symbols[i].length()) % symbols[i].length();
                    }
                    else if(i < 4){
                        crypted_symbol_pos = (j + offset.kir + symbols[i].length()) % symbols[i].length();
                    }
                    else{
                        crypted_symbol_pos = (j + offset.num + symbols[i].length()) % symbols[i].length();
                    }
                    break;
                }

            }
        }
        if(symbol_found){cout << symbols[crypted_symbol_abc][crypted_symbol_pos];}
        else {cout << current_byte;}
    }
    cout << "File crypted";


}


int symboul (string path = "README.md")  //по умолчанию выводит количество символов в redme
{
    //Чтение файла
    ifstream file;
    file.open(path, ios::binary);
    char ch;
    int charcount=0;
    //читаем посимвольно весь файл
    while(file.get(ch))
    {
        if (ch!='\r') //т.к. Enter в Windows считается за два символа
        {
            ++charcount;
        }
    }
    cout<<"number of characters: "<<charcount;
    file.close();
    return charcount;
}

int get_week_day() // Функция для получения текущего дня недели
{
    time_t now = time(nullptr); // Получаем текущее время
    tm* ltm = localtime(&now); // Преобразуем время в tm структуру

    int week_day = ltm->tm_wday; // Номер дня недели (0-6, где 0 - Sunday, 6 - Saturday)
    //const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", // Перевод номера дня недели в текстовое представление
    //                       "Thursday", "Friday", "Saturday"};

    // Вывод результатов
    //cout << "Числовое значение дня недели: " << week_day << endl;
    //cout << "День недели: " << days[week_day] << endl;
    return week_day;
}

int get_mouth_day() // То же самое для дня месяца
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    int day_of_month = ltm->tm_mday; // Номер дня месяца (1-31)

    //cout << "Текущий день месяца: " << day_of_month << endl; // Вывод результата
    return day_of_month;
}

int get_minute() {
    time_t now = time(0);
    tm* local_time = localtime(&now);

    int minute = local_time->tm_min;

    //wcout << minute << endl;

    if (minute % 2 == 0) {
        //если минута четная
    } else {
        //если минута нечетная
    }
    return minute;
}

void print_help(){          //вывод помощи
    cout << "Usage:\n\t kursach.exe [input_file] [output_file]\n";
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    if(argc != 3){print_help();}

    //symboul();

    ifstream input;
    ofstream output;

    input.open("test.txt");


    //место для проверки открытия
    offsets test;
    test.kir = 1; test.lat = 1; test.num = -1;
    caesar(&input, &output, test);

    return 0;
}

