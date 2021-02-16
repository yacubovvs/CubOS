cd x86_64_pc_display_emulator
cd cubos
g++ -w main.cpp -o cubos.exe
cubos.exe | java -jar screenemulator.jar
cd ..
cd ..