#include <stdio.h>
#include <string.h>

struct RobotRecord {
    int id;
    float depth;
    float pressure;
    float temperature;
    float battery;
    char defect[20];
};

int main() {
    struct RobotRecord r;
    FILE *fp1, *fp2;
    int total = 0, unsafe = 0;

    fp1 = fopen("underwater_log.txt", "a");
    if (fp1 == NULL) {
        printf("Error opening log file!\n");
        return 1;
    }

    printf("Enter Robot ID: ");
    scanf("%d", &r.id);
    printf("Enter Depth (m): ");
    scanf("%f", &r.depth);
    printf("Enter Water Pressure (bar): ");
    scanf("%f", &r.pressure);
    printf("Enter Temperature (C): ");
    scanf("%f", &r.temperature);
    printf("Enter Battery Percentage: ");
    scanf("%f", &r.battery);
    printf("Enter Structural Defect (None/Crack/Corrosion): ");
    scanf("%s", r.defect);

    fprintf(fp1, "%d %.2f %.2f %.2f %.2f %s\n", r.id, r.depth, r.pressure, r.temperature, r.battery, r.defect);
    fclose(fp1);

    fp1 = fopen("underwater_log.txt", "r");
    fp2 = fopen("underwater_report.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    fprintf(fp2, "=== UNDERWATER ROBOT INSPECTION REPORT ===\n");
    fprintf(fp2, "ID\tDepth\tPress\tTemp\tBatt\tDefect\t\tStatus\n");
    fprintf(fp2, "------------------------------------------------------------\n");

    while (fscanf(fp1, "%d %f %f %f %f %s", &r.id, &r.depth, &r.pressure, &r.temperature, &r.battery, r.defect) != EOF) {
        total++;
        if (r.depth > 300 || r.pressure > 30 || r.temperature > 35 || r.battery < 20 || strcmp(r.defect, "None") != 0) {
            unsafe++;
            fprintf(fp2, "%d\t%.1f\t%.1f\t%.1f\t%.1f\t%-10s\tUNSAFE\n", r.id, r.depth, r.pressure, r.temperature, r.battery, r.defect);
        } else {
            fprintf(fp2, "%d\t%.1f\t%.1f\t%.1f\t%.1f\t%-10s\tSAFE\n", r.id, r.depth, r.pressure, r.temperature, r.battery, r.defect);
        }
    }

    fprintf(fp2, "------------------------------------------------------------\n");
    fprintf(fp2, "Total Records : %d\n", total);
    fprintf(fp2, "Unsafe Records: %d\n", unsafe);
    fprintf(fp2, "Safe Records  : %d\n", total - unsafe);

    fclose(fp1);
    fclose(fp2);

    printf("Inspection report generated in underwater_report.txt!\n");
    return 0;
}
