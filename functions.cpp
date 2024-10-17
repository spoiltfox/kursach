#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;
struct offsets { //� ������ �������������� ����� ���� ��������� �������������� ���������� � ���������
    int lat = 0;
    int kir = 0;
    int num = 0;
    bool sybmol_count_needed = false;
    bool checksum_needed = false;
};

int caesar(ifstream* input_file, ofstream* output_file, offsets offset){        //������� ��� "�����������" ��� "������" ������ ���� ����:  int func_name(ifstream* a, ofstream* b, offsets c){
                                                                                                                                                //���-�� �����;
                                                                                                                                                //return caesar(a, b, d);}

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
    input_file->clear();
    input_file->seekg(0, ios_base::beg);
    return 0;


}


char symboul (ifstream* file)  //�� ��������� ������� ���������� �������� � redme
{
    char ch;
    char charcount=0;
    //������ ����������� ���� ����
    while(file->get(ch))
    {
        if (ch!='\r') //�.�. Enter � Windows ��������� �� ��� �������
        {
            ++charcount;
        }
    }

    file->clear();
    file->seekg(0, ios_base::beg);
    return charcount;
}

int get_week_day() // ������� ��� ��������� �������� ��� ������
{
    time_t now = time(nullptr); // �������� ������� �����
    tm* ltm = localtime(&now); // ����������� ����� � tm ���������

    int week_day = ltm->tm_wday; // ����� ��� ������ (0-6, ��� 0 - Sunday, 6 - Saturday)
    //const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", // ������� ������ ��� ������ � ��������� �������������
    //                       "Thursday", "Friday", "Saturday"};
    return week_day;
}

int get_mouth_day() // �� �� ����� ��� ��� ������
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    int day_of_month = ltm->tm_mday; // ����� ��� ������ (1-31)

    return day_of_month;
}

int get_minute() {
    time_t now = time(0);
    tm* local_time = localtime(&now);

    int minute = local_time->tm_min;

    return minute;
}

char calcChecksum(fstream* inputFile, bool timeDependent) {
    if (!inputFile->is_open() || !inputFile->good()) {
        return 1; // ������ �������� �����
    }

    char ch;
    unsigned long long checksum = 0;
    unsigned long long sdvig = 0;
    while (inputFile->get(ch)) {

        // ���������� ����� � ����������� �� �������
        if (isalpha(ch)) { // ��������� �����
            sdvig = (ch >= 'a' && ch <= 'z') ? 3 : 3; // ��������� ����� - ����� 3
        } else if ((ch >= 0xC0 && ch <= 0xFF) || (ch >= 0xE0 && ch <= 0xEF)) { // ��������� � UTF-8
            sdvig = 5; // ��������� - ����� 5
        } else if (isdigit(ch)) { // �����
            sdvig = 2; // ����� - ����� 2
        } else {
            sdvig = 0; // ������ �������
        }

        // ��������� ����� � ��������� ����������� �����
        checksum += (ch + sdvig);
    }

    if (timeDependent) {
        // ������ ������������ ������� ����� ��� ���������� ����������� �����
        checksum += get_minute() % 2; //������
    }

    inputFile->clear();
    inputFile->seekg(0, ios_base::beg);
    return checksum;
}

void print_help(){          //����� ������
    cout << "Usage:\n\t kursach.exe [input_file] [output_file]\n";
}
