note: GIT must installed and accessible through PATH
note: mbed uses both GIT and HG
note: HG has currently only beta support for python3

pip install mercurial
pip install mbed-cli
mbed config -G ARM_PATH C:\GNU_Tools_ARM_Embedded\7_2018\bin
mbed new test1
cd test1
touch main.cpp # write code
mbed compile --target nucleo_l432kc --toolchain gcc_arm
mbed compile --target nucleo_l432kc --toolchain gcc_arm -v
mbed compile --target nucleo_l432kc --toolchain gcc_arm -v --flash
