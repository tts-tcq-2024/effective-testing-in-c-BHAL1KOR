#include <stdio.h>

// Function pointer for alert function
int (*networkAlert)(float);

// Stub function for testing
int networkAlertStub(float celcius) {
    if (celcius > 200.0) {
        return 500; // Simulate failure
    }
    return 200; // Simulate success
}

// Real function for production (example)
int networkAlertReal(float celcius) {
    // Real network alert code would go here
    return 200; // Simulate success
}

int alertFailureCount = 0;

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int responseCode = networkAlert(celcius);
    if (responseCode != 200) {
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    
    // Set the function pointer to the stub for testing
    networkAlert = networkAlertStub;

    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
