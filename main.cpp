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
    string abc_rus = "��������������������������������";
    string ABC_RUS = "�����Ũ��������������������������";
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

    if(argc != 3){print_help();}

    //symboul();

    ifstream input;
    ofstream output;

    input.open("test.txt");


    //����� ��� �������� ��������
    offsets test;
    test.kir = 1; test.lat = 1; test.num = -1;
    caesar(&input, &output, test);

    return 0;
}

