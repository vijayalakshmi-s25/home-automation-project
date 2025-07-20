#include <reg51.h>

// Define relay control pins
sbit FAN_RELAY = P2^0;  // Fan relay via NPN transistor
sbit LED_RELAY = P2^1;  // LED relay via NPN transistor

// Delay function (approximate)
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1275; j++);
}

void main() {
    // Initialize both pins as HIGH (Relay OFF initially)
    FAN_RELAY = 1;
    LED_RELAY = 1;

    while (1) {
        // Turn ON fan and LED (relay is active low)
        FAN_RELAY = 0;   // Turn ON fan relay
        LED_RELAY = 0;   // Turn ON LED relay
        delay_ms(1000);  // 1 second delay

        // Turn OFF fan and LED
        FAN_RELAY = 1;   // Turn OFF fan relay
        LED_RELAY = 1;   // Turn OFF LED relay
        delay_ms(1000);  // 1 second delay
    }
}