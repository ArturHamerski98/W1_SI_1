#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

#pragma warning(disable: 4996)

enum statuses {
    Exploring,
    Sampling,
    Returning,
    Idle
};

char robot_name[30] = "Blitzcrank";
int battery_charge_status = 66;
float temperature = 34.5;
float velocity = 433.61f;
enum statuses robot_status;
robot_status = Idle;
char temperature_system = 'C';

void printRobotInfo() {
    char menu_choice1[32];
    printf("\nWhat info you want to get? Write (robot_name, battery_charge_status,"
        "\ntemperature, velocity or robot_status): ");
    scanf("%s", menu_choice1);

    if (strcmp(menu_choice1, "robot_name") == 0) {
        printf("Robot name is %s", robot_name);
    }
    else if (strcmp(menu_choice1, "battery_charge_status") == 0) {
        printf("Baterry have %d%% ", battery_charge_status);
    }
    else if (strcmp(menu_choice1, "temperature") == 0) {
        printf("The temperature is %f%c%c ", temperature, 248, temperature_system);
    }
    else if (strcmp(menu_choice1, "velocity") == 0) {
        printf("Velocity is %f", velocity);
    }
    else if (strcmp(menu_choice1, "robot_status") == 0) {
        if (robot_status == Exploring)
            printf("Robot status: Exploring");
        else if (robot_status == Sampling)
            printf("Robot status: Sampling");
        else if (robot_status == Returning)
            printf("Robot status: Returning");
        else if (robot_status == Idle)
            printf("Robot status: Idle");
        else
            printf("Unknow status");
    }
    else
        printf("WRONG NAME");

}

void setValues() {
    char menu_choice1[32];
    printf("\nWhat value you want to set? Write (robot_name, battery_charge_status,"
        "\ntemperature, velocity or robot_status): ");
    scanf("%s", menu_choice1);

    if (strcmp(menu_choice1, "robot_name") == 0) {
        printf("Enter the new value\n");
        scanf("%s", robot_name);
    }
    else if (strcmp(menu_choice1, "battery_charge_status") == 0) {
        printf("Enter the new value\n");
        scanf_s("%d", &battery_charge_status);
    }
    else if (strcmp(menu_choice1, "temperature") == 0) {
        printf("Enter the new temperatur in %c\n", temperature_system);
        scanf_s("%f", &temperature);
    }
    else if (strcmp(menu_choice1, "velocity") == 0) {
        printf("Enter the new value\n");
        scanf_s("%f", &velocity);
    }
    else if (strcmp(menu_choice1, "robot_status") == 0) {
        printf("Select the new status\n0 Exploring \n1 Sampling \n2 Returning \n3 Idle");
        scanf_s("%d", &robot_status);
    }
    else
        printf("WRONG NAME");

}

void printBytesInfo() {
    printf("Number of bytes reserved for each variable type\n");
    printf("char %I64u\n", sizeof(char));
    printf("int %I64u\n", sizeof(int));
    printf("float %I64u\n", sizeof(float));
    printf("double %I64u\n", sizeof(double));
    printf("Enum statuses %I64u\n", sizeof(enum statuses));
}

void printMaxMinInfo() {
    printf("Min value of battery status is: %d max value of bettery status is: %d\n", INT_MIN, INT_MAX);
    printf("Min value of temperature is: %.10e max value of temperature is: %.10e\n", FLT_MIN, FLT_MAX);
    printf("Min value of velocity is: %.10e max value of velocity is: %.10e\n", FLT_MIN, FLT_MAX);
}

void convertTheTemperatureToAbsoluteInfo() {
    if (temperature_system == 'C')
        temperature = -273.15f;
    else
        temperature = 0;
    printf("Temperature is set to her absolute value\n");
}
void VelocityConvertAndInfo() {
    printf("Velocity in decimal notatnion: %f\n", velocity);
    printf("Velocity in scientific notatnion: %e\n", velocity);
}
void ConvertTheTemperatureToKelvin() {
    temperature_system = 'K';
    temperature = temperature + 273.15f;
    printf("\nTemperature is coverted to Kelvin");

}
void ConvertTheTemperatureToCelsius() {
    temperature_system = 'C';
    temperature = temperature - 273.15f;
    printf("\nTemperature is coverted to Celsius");

}

int main() {
    int menu_choice;
    while (1 == 1) {
        printf("\nWhat you want to do?\n1 Display robot info\n2 Display bytes reserved info\n3 Display max and min values info\n"
            "4 Converting the temperature valure to its absolute value\n5 Display the velocity in decimal and scientific notation\n"
            "6 Convert temperature from Celsius to Kelvins\n7 Convert temperature from Kelvin to Celsius\n"
            "8 Set values\n9 Quit program\nYoure choice:");
        scanf_s("%d", &menu_choice);

        switch (menu_choice) {
        case 1:
            printRobotInfo();
            break;
        case 2:
            printBytesInfo();
            break;
        case 3:
            printMaxMinInfo();
            break;
        case 4:
            convertTheTemperatureToAbsoluteInfo();
            break;
        case 5:
            VelocityConvertAndInfo();
            break;
        case 6:
            ConvertTheTemperatureToKelvin();
            break;
        case 7:
            ConvertTheTemperatureToCelsius();
            break;
        case 8:
            setValues();
            break;
        case 9:
            exit(0);
            break;

        default:
            break;

        }
    }

}