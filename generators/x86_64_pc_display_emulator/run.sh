DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
./outputs/x86_64_pc_display_emulator/cubos/cubos | java -jar outputs/x86_64_pc_display_emulator/cubos/screenemulator.jar
