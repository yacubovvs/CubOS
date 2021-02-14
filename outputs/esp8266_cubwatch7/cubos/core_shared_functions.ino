String getHexStringFromByte(byte b){
    return "0x" + getHexNumberFromNumber(b/16) + getHexNumberFromNumber(b%16);
}

String getHexNumberFromNumber(byte b){
    switch(b){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return String((int)b);
        case 10:
            return "A";
        case 11:
            return "B";
        case 12:
            return "C";
        case 13:
            return "D";
        case 14:
            return "E";
        case 15:
            return "F";
        default:
            return "";
    }

}