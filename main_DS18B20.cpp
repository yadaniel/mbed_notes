#include "mbed.h"
#include "DS1820.h"

Serial pc(USBTX, USBRX);
// DigitalOut led(LED1);
DigitalOut led(D13);

//Serial pc(SERIAL_TX, SERIAL_RX);
// PwmOut mypwm(PWM_OUT);
// DigitalOut myled(LED1);
// InterruptIn tempSensor(D13);
// InterruptIn sw(D12);

// Timer timer;
// Ticker tickerLED;
// Ticker tickerButton;
// PwmOut pwm1(PB_4);
// DigitalOut led1(LED1);
// DigitalOut led2(LED2);
// DigitalIn button(PA_12, PullUp);
// AnalogIn adc1(PA_0);
// AnalogOut dac1(PA_1);
// Serial pc(SERIAL_TX, SERIAL_RX);
// BusOut leds(PB_3, PB_2, PB_1, PB_0); 0 <= leds <= 15
// PortOut port(PortB, 0x0F);
// InterruptIn tempSensor(D12);  // using green labels
// InterruptIn tempSensor(PB_4);   // using blue labels

int main() {
    pc.baud(115200);
    pc.printf("\nstarted\n");
    DS1820 ds1820(A0);   // works
    // DS1820 ds1820(A1);   // works
    // DS1820 ds1820(D7);   // does not work (not connected on pinout map)
    // DS1820 ds1820(D8);   // does not work (not connected on pinout map)
    // DS1820 ds1820(D9);   // works
    // DS1820 ds1820(D10);  // works
    // DS1820 ds1820(D11);  // works
    // DS1820 ds1820(D12);  // works
    bool ok = ds1820.begin();
    //
    int cnt = 0;
    while(true) {
        pc.printf("cnt = %i, ", cnt);
        if(ok) {
            ds1820.startConversion();
            pc.printf("temp = %3.1f\n", ds1820.read());
        } else {
            ok = ds1820.begin();
            pc.printf("failed to connect\n");
        }
        cnt += 1;
        wait(0.1);
        led = !led;
    }
    return 0;
}

