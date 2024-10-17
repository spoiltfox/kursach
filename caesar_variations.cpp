#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

//��� ������� ������ �������������� ���������� �������� �� �����
// ��� ����� �1.1.1 - v1_1_1

int v1_1_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    // ������ ������
    offset.lat = 3; offset.kir = 5; offset.num = 2;

    // ����� �������� ������� (���� ������)
    return caesar(input_file, output_file, offset);
}

int v1_1_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    // ������ ������
    offset.lat = -3; offset.kir = -5; offset.num = -2;

    // ����� �������� ������� (���� ������)
    return caesar(input_file, output_file, offset);
}

/*
int time_based_decorator(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();  // �������� ������� ���� ������
    int minute = get_minute();      // �������� ������� ������
    int day_of_month = get_mouth_day();  // �������� ������� ���� ������

    if (minute%2 == 0)
    {
        offset.lat += 3;
        offset.kir += 5;
        offset.num += 3;
        cout << "���� ������: " << week_day << ", ����� �� �������� ������ �� " << 3 << endl;
        cout << "������: " << minute << ", ����� ��� ��������� ������ �� " << 5 << endl;
        cout << "���� ������: " << day_of_month << ", ����� ��� ����� ������ �� " << 3 << endl;
    }
    else
    {
        offset.lat += 4;
        offset.kir += 6;
        offset.num += 2;
        cout << "���� ������: " << week_day << ", ����� �� �������� ������ �� " << 4 << endl;
        cout << "������: " << minute << ", ����� ��� ��������� ������ �� " << 6 << endl;
        cout << "���� ������: " << day_of_month << ", ����� ��� ����� ������ �� " << 2 << endl;
    }

    // ����� �������� ������� (���� ������)
    return caesar(input_file, output_file, offset);
}
*/
