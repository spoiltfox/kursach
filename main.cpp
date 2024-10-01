#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

int symboul (string path = "README.md")  //�� ��������� ������� ���������� �������� � redme
{
    //������ �����
    ifstream file;
    file.open(path, ios::binary);
    char ch;
    int charcount=0;
    //������ ����������� ���� ����
    while(file.get(ch))
    {
        if (ch!='\r') //�.�. Enter � Windows ��������� �� ��� �������
        {
            ++charcount;
        }
    }
    cout<<"number of characters: "<<charcount;
    file.close();
    return charcount;
}

int get_week_day() // ������� ��� ��������� �������� ��� ������
{
    time_t now = time(nullptr); // �������� ������� �����
    tm* ltm = localtime(&now); // ����������� ����� � tm ���������

    int week_day = ltm->tm_wday; // ����� ��� ������ (0-6, ��� 0 - Sunday, 6 - Saturday)
    //const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", // ������� ������ ��� ������ � ��������� �������������
    //                       "Thursday", "Friday", "Saturday"};

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

void print_help(){          //����� ������
    cout << "Usage:\n\t kursach.exe [input_file] [output_file]\n";
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    if(argc != 3)
    {
        print_help();
        /*return 0; //����� ������� ��� ��������� ��� �������
                    //����� �����������
        cout << argv[1]<< endl;
        cout << argv[2]<< endl;*/
    }

    symboul();

    return 0;
}

