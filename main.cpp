#include <iostream>
#include <ctime>

using namespace std;

int get_week_day() // ������� ��� ��������� �������� ��� ������
{
    time_t now = time(nullptr); // �������� ������� �����
    tm* ltm = localtime(&now); // ����������� ����� � tm ���������

    int week_day = ltm->tm_wday; // ����� ��� ������ (0-6, ��� 0 - Sunday, 6 - Saturday)
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", // ������� ������ ��� ������ � ��������� �������������
                           "Thursday", "Friday", "Saturday"};

    // ����� �����������
    //cout << "�������� �������� ��� ������: " << week_day << endl;
    //cout << "���� ������: " << days[week_day] << endl;
    return week_day;
}

int get_mouth_day() // �� �� ����� ��� ��� ������
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    int day_of_month = ltm->tm_mday; // ����� ��� ������ (1-31)

    //cout << "������� ���� ������: " << day_of_month << endl; // ����� ����������
    return day_of_month;
}

int get_minute() {
    time_t now = time(0);
    tm* local_time = localtime(&now);

    int minute = local_time->tm_min;

    //wcout << minute << endl;

    if (minute % 2 == 0) {
        //���� ������ ������
    } else {
        //���� ������ ��������
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
