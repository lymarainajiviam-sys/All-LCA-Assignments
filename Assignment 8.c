#include <stdio.h>

void swap(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int motor1, motor2;
    int *p1, *p2;

    printf("Enter speed of Motor 1: ");
    scanf("%d", &motor1);
    printf("Enter speed of Motor 2: ");
    scanf("%d", &motor2);

    p1 = &motor1;
    p2 = &motor2;

    printf("\n--- Before Swapping ---\n");
    printf("Motor 1 Speed = %d | Memory Address = %p\n", motor1, (void *)p1);
    printf("Motor 2 Speed = %d | Memory Address = %p\n", motor2, (void *)p2);

    swap(p1, p2);

    printf("\n--- After Swapping (Verified) ---\n");
    printf("Motor 1 Speed = %d | Memory Address = %p\n", motor1, (void *)p1);
    printf("Motor 2 Speed = %d | Memory Address = %p\n", motor2, (void *)p2);

    return 0;
}
