#include <iostream>
#include <ctime>

using namespace std;

int get_week_day() // Функция для получения текущего дня недели
{
    time_t now = time(nullptr); // Получаем текущее время
    tm* ltm = localtime(&now); // Преобразуем время в tm структуру

    int week_day = ltm->tm_wday; // Номер дня недели (0-6, где 0 - Sunday, 6 - Saturday)
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", // Перевод номера дня недели в текстовое представление
                           "Thursday", "Friday", "Saturday"};

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
int main()
{
    setlocale(LC_ALL, "Russian");
    cout<<get_week_day()<<endl;
    cout<<get_mouth_day()<<endl;
    cout<<get_minute()<<endl;
    return 0;
}

