* install git (default settings ... 3rd party tools must be able to call git)
* install python2.7 and then using pip install ...
*   pip install mbed-cli
*   pip install mbedls
*   pip install mercurial (not sure needed)
* extend environment variable PATH with C:\Python27;C:\Python27\Script
* use cmd.exe (not cygwin if already installed)
* ... then
* mbed import https://github.com/ARMmbed/mbed-os-example-blinky
* cd mbed-os-example-blinky
* this will pull the mbed-os and some code ... now plugin the board
* mbed detect
* mbed config target NUCLEO-L432KC
* mbed toolchain GCC_ARM
* mbed config GCC_ARM_PATH "C:\GNU_Tools_ARM_Embedded_2018\bin"
* mbed compile

    ...
    Compile [100.0%]: us_ticker.c
    Link: mbed-os-example-blinky
    Elf2Bin: mbed-os-example-blinky
    | Module             |         .text |       .data |        .bss |
    |--------------------|---------------|-------------|-------------|
    | [fill]             |     117(+117) |     12(+12) |     50(+50) |
    | [lib]\c.a          | 26861(+26861) | 2472(+2472) |     89(+89) |
    | [lib]\gcc.a        |   3112(+3112) |       0(+0) |       0(+0) |
    | [lib]\misc         |     208(+208) |     12(+12) |     28(+28) |
    | main.o             |   1066(+1066) |       4(+4) |     36(+36) |
    | mbed-os\cmsis      |   1033(+1033) |       0(+0) |     84(+84) |
    | mbed-os\components |     120(+120) |       0(+0) |       0(+0) |
    | mbed-os\drivers    |     887(+887) |       4(+4) |   100(+100) |
    | mbed-os\hal        |   3333(+3333) |       8(+8) |   247(+247) |
    | mbed-os\platform   |   4334(+4334) |   260(+260) |   232(+232) |
    | mbed-os\rtos       |   9092(+9092) |   168(+168) | 6285(+6285) |
    | mbed-os\targets    | 10528(+10528) |       4(+4) |   593(+593) |
    | Subtotals          | 60691(+60691) | 2944(+2944) | 7744(+7744) |
    Total Static RAM memory (data + bss): 10688(+10688) bytes
    Total Flash memory (text + data): 63635(+63635) bytes
    
    Image: .\BUILD\NUCLEO_L432KC\GCC_ARM\mbed-os-example-blinky.bin

* copy to the virtual USB drive of the device
copy /B BUILD\NUCLEO_L432KC\GCC_ARM\mbed-os-example-blinky.bin G:\

