#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

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

    if(argc != 3)
    {
        print_help();
        /*return 0; //прога требует два аргумента при запуске
                    //можно закоментить
        cout << argv[1]<< endl;
        cout << argv[2]<< endl;*/
    }

    symboul();

    return 0;
}

