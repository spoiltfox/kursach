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

// �1.2.1 - ���������������� ����� ������, ��������� �� ������� ������ ����������
int v1_2_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // ������ ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ������
        offset.lat = 4;
        offset.kir = 6;
        offset.num = 2;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.2 - ���������������� ����� �����, ��������� �� ������� ������ ����������
int v1_2_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) {
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else {
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.3 - ���������� ����������������� �����, ��������� �� ������� ������ ����������
int v1_2_3(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // ������ ������ - ����� ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ������ - ����� �����
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.4 - ����������������� ������, ��������� �� ������� ������ ����������
int v1_2_4(ifstream* input_file, ofstream* output_file, offsets offset) {
    int minute = get_minute();
    if (minute % 2 == 0) { // ������ ������ - - ����� ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ������ - - ����� �����
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.5: �1.2.1 � ������ �������� ��� ������ (������)
int v1_2_5(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    if (day_of_month % 2 == 0) { // ������ ���� ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ���� ������
        offset.lat = 4;
        offset.kir = 6;
        offset.num = 2;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.6: �1.2.2 � ������ �������� ��� ������ (�����)
int v1_2_6(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    if (day_of_month % 2 == 0) { // ������ ���� ������
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else { // �������� ���� ������
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.7: �1.2.3 � ����������� ������������������ ��������, ���������� �� ����� ������
int v1_2_7(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();

    if (day_of_month % 2 == 0) { // ������ ���� ������ - ����� ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ���� ������ - ����� �����
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    }

    return caesar(input_file, output_file, offset);
}

// �1.2.8: �1.2.4 � ������� ������������������ ��������, ���������� �� ����� ������
int v1_2_8(ifstream* input_file, ofstream* output_file, offsets offset) {
    int day_of_month = get_mouth_day();
    if (day_of_month % 2 == 0) { // ������ ���� ������ - ����� ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ���� ������ - ����� �����
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.9: �1.2.1 � ������ �������� ��� ������ (������)
int v1_2_9(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    if (week_day % 2 == 0) { // ������ ���� ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ���� ������
        offset.lat = 4;
        offset.kir = 6;
        offset.num = 2;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.10: �1.2.2 � ������ �������� ��� ������ (�����)
int v1_2_10(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    if (week_day % 2 == 0) { // ������ ���� ������
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    } else { // �������� ���� ������
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.11: �1.2.3 � ����������� ������������������ ��������, ���������� �� ��� ������
int v1_2_11(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    if (week_day % 2 == 0) { // ������ ���� ������ - ����� ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ���� ������ - ����� �����
        offset.lat = -3;
        offset.kir = -5;
        offset.num = -3;
    }
    return caesar(input_file, output_file, offset);
}

// �1.2.12: �1.2.4 � ������� ������������������ ��������, ���������� �� ��� ������
int v1_2_12(ifstream* input_file, ofstream* output_file, offsets offset) {
    int week_day = get_week_day();
    if (week_day % 2 == 0) { // ������ ���� ������ - ����� ������
        offset.lat = 3;
        offset.kir = 5;
        offset.num = 3;
    } else { // �������� ���� ������ - ����� �����
        offset.lat = -4;
        offset.kir = -6;
        offset.num = -2;
    }
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
//
int v1_3_1(ifstream* input_file, ofstream* output_file, offsets offset) {
    // ������ ������
    offset.lat = 3; offset.kir = 5; offset.num = 2; offset.symbol_count_needed = true;

    // ����� �������� ������� (���� ������)
    return caesar(input_file, output_file, offset);
}
int v1_3_2(ifstream* input_file, ofstream* output_file, offsets offset) {
    // ������ ������
    offset.lat = -3; offset.kir = -5; offset.num = -2; offset.symbol_count_needed = true;

    // ����� �������� ������� (���� ������)
    return caesar(input_file, output_file, offset);
}
