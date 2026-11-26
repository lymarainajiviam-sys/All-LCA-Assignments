char *months[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

int monthDays[] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

printf("Enter year: ");
scanf("%d", &year);

if (isLeapYear(year))
    monthDays[1] = 29;

// Calculate the starting day of the year
startDay = (year + (year - 1) / 4
            - (year - 1) / 100
            + (year - 1) / 400) % 7;

for (month = 0; month < 12; month++)
{
    printf("\n\n       %s %d\n", months[month], year);
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    for (i = 0; i < startDay; i++)
        printf("    ");

    days = monthDays[month];

    for (day = 1; day <= days; day++)
    {
        printf("%4d", day);

        if ((day + startDay) % 7 == 0)
            printf("\n");
    }

    startDay = (startDay + days) % 7;
}

return 0;
