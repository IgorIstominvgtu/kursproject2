#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define RACERS 20
#define NAME_LENGTH 20

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    char names[RACERS][NAME_LENGTH] = {
        "������", "�������", "��������", "������", "��������",
        "�������", "������", "���������", "���������", "�����",
        "�����", "�������", "��������", "������", "�������",
        "����", "��������", "������", "���������", "����������"
    };
    int times[RACERS][3];
    int total_times[RACERS];
    int places[RACERS];
    int scores[RACERS];

    for (int i = 0; i < RACERS; i++) {
        times[i][0] = rand() % 20 + 10;
        times[i][1] = rand() % 20 + 10;
        times[i][2] = rand() % 20 + 10;
    }

    for (int i = 0; i < RACERS; i++) {
        total_times[i] = times[i][0] + times[i][1] + times[i][2];
        places[i] = 1;
        scores[i] = 0;
    }

    for (int i = 0; i < RACERS - 1; i++) {
        for (int j = i + 1; j < RACERS; j++) {
            if (total_times[i] > total_times[j]) {
                int temp_time = total_times[i];
                total_times[i] = total_times[j];
                total_times[j] = temp_time;

                char temp_name[NAME_LENGTH];
                strcpy(temp_name, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp_name);

            }
        }
    }

    for (int i = 1; i < RACERS; i++) {
        if (total_times[i] == total_times[i - 1]) {
            places[i] = places[i - 1];
        }
        else {
            places[i] = i + 1;
        }
    }

    for (int i = 0; i < RACERS; i++) {
        scores[i] = RACERS - places[i] + 1;
    }

    int choice = -1;
    int threshold;
    while (choice != 0) {
        printf("\n�������� ��������:\n");
        printf("1 - ����� ������� �������\n");
        printf("2 - ����� ������� �������\n");
        printf("3 - ����� �������� � ����� �������� ������ n\n");
        printf("4 - ������������� �� ��������\n");
        printf("5 - ������� �������� �������\n");
        printf("6 - ������� �������������� �������\n");
        printf("0 - �����\n");
        printf("��� �����: ");

        if (scanf("%d", &choice) != 1) {
            printf("�������� ����. ���������.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            printf("\n������ ������(�):\n");
            int bestPlace = 1;
            for (int i = 0; i < RACERS; i++) {
                if (places[i] == bestPlace) {
                    printf("%s � ����� �������� %d � %d ������\n", names[i], total_times[i], scores[i]);
                }
                else if (places[i] > bestPlace) {
                    break;
                }
            }
            break;
        case 2:
            printf("\n������ ������(�):\n");
            int worstPlace = RACERS;
            for (int i = RACERS - 1; i >= 0; i--) {
                if (places[i] == worstPlace) {
                    printf("%s � ����� �������� %d � %d ������\n", names[i], total_times[i], scores[i]);
                }
                else if (places[i] < worstPlace) {
                    break;
                }
            }
            break;
        case 3:
            printf("������� ��������� �����: ");
            if (scanf("%d", &threshold) != 1) {
                printf("�������� ����. ���������.\n");
                while (getchar() != '\n');
                continue;
            }
            printf("\n������� � ����� �������� ������ %d:\n", threshold);
            for (int i = 0; i < RACERS; i++) {
                if (total_times[i] > threshold) {
                    printf("%s � ����� �������� %d � %d ������\n", names[i], total_times[i], scores[i]);
                }
            }
            break;
        case 4:
        {

            int n = RACERS;
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (scores[j] < scores[j + 1]) {
                        int temp_score = scores[j];
                        scores[j] = scores[j + 1];
                        scores[j + 1] = temp_score;

                        int temp_time = total_times[j];
                        total_times[j] = total_times[j + 1];
                        total_times[j + 1] = temp_time;

                        int temp_place = places[j];
                        places[j] = places[j + 1];
                        places[j + 1] = temp_place;


                        char temp_name[NAME_LENGTH];
                        strcpy(temp_name, names[j]);
                        strcpy(names[j], names[j + 1]);
                        strcpy(names[j + 1], temp_name);


                    }
                }
            }
            printf("\n�������������� �������:\n");
            printf("|   ������           | ����� ����� | ����� | ����  |\n");

            for (int n = 0; n < RACERS; n++) {
                printf("|%18s |     %3d      |  %2d   |  %3d  |\n", names[n], total_times[n], places[n], scores[n]);
            }
            break;
        }
        case 5:
            printf("\n�������� ������� ������������:\n");
            printf("|   ������           | ����� 1 ����� | ����� 2 ����� | ����� 3 ����� |\n");
            for (int n = 0; n < RACERS; n++) {
                printf("|%18s |      %3d      |     %3d      |     %3d      |\n", names[n], times[n][0], times[n][1], times[n][2]);
            }
            break;
        case 6:
            printf("\n�������������� �������:\n");
            printf("|   ������           | ����� ����� | ����� | ����  |\n");
            for (int n = 0; n < RACERS; n++) {
                printf("|%18s |     %3d      |  %2d   |  %3d  |\n", names[n], total_times[n], places[n], scores[n]);
            }
            break;
        case 0:
            printf("���������� ���������.\n");
            break;
        default:
            printf("�������� �����.\n");
        }
    }


}