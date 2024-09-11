#include <stdio.h>



int main() {

    int FINE_HELMET = 2000 ;
int FINE_INSURANCE  = 5000 ;
int FINE_LICENSE  = 3000 ;
    int num_vehicles, total_fine = 0;

    // Input the number of vehicles
    printf("Enter the number of vehicles to be monitored: ");
    scanf("%d", &num_vehicles);

    // Input safety compliance for each vehicle
    for (int i = 1; i <= num_vehicles; i++) {
        int helmet, insurance, license;
        printf("Enter the safety compliance for vehicle %d (helmet insurance license): ", i);
        scanf("%d %d %d", &helmet, &insurance, &license);

        // Calculate fines based on safety compliance
        if (helmet == 0)
            total_fine += FINE_HELMET;
        if (insurance == 0)
            total_fine += FINE_INSURANCE;
        if (license == 0)
            total_fine += FINE_LICENSE;
    }

    // Display total fine collected
    printf("Total fine collected: Rs. %d\n", total_fine);

    return 0;
}
