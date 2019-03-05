#include "mbed.h"

Timer timer;
Ticker tickerLED;
Ticker tickerButton;
PwmOut pwm1(PB_4);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalIn button(PA_12, PullUp);
AnalogIn adc1(PA_0);
AnalogOut dac1(PA_1);
Serial pc(SERIAL_TX, SERIAL_RX);
// BusOut leds(PB_3, PB_2, PB_1, PB_0); 0 <= leds <= 15
// PortOut port(PortB, 0x0F);

void task1Func() {
    uint32_t tmp = led1;
    led1 = 1;
    wait(0.2);
    led1 = 0;
    wait(0.8);
    led1 = tmp;
}

void task2Func() {
    if(button == 1) {
        led2 = 1;
        wait(0.2);
        led2 = 0;
        wait(0.8);
        pc.printf("button opened\n");
    }
}

int main() {
    pc.baud(115200);
    pc.printf("commands: t=toggle, 1=on, 0=off\n");
    pwm1.period_ms(10);     // set PWM period
    pwm1 = 0.5;             // set PWM duty cycle
    tickerLED.attach(&task1Func, 5);   // callback every 5 seconds
    tickerButton.attach(&task2Func, 1);   // callback every 1 seconds
    //
    while(true) {
        timer.start();
        char c = pc.getc(); // Read hyperterminal
        timer.stop();
        pc.printf("time %.3f [s]\n", timer.read());
        timer.reset();
        switch(c) {
        case 't':
            led1 = !led1;
            pc.printf("toggle\n");
            break;
        case '0':
            led1 = 0;
            pc.printf("off\n");
            break;
        case '1':
            led1 = 1;
            pc.printf("on\n");
            break;
        default:
            pc.printf("unknown command\n");
            wait(1);
            break;
        }
        pc.getc();  // skip newline
    }
}

