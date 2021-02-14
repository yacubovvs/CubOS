/*
*************************************
*                                   *
*          BASIC FUNCTIONS          *
*                                   *
*************************************
*/

//const float pi = 3.141592;

const float get_pi(){
    #ifdef platform_m5stack
        return 3.141592;
    #endif

    #ifdef platform_esp8266
        return 3.141592;
    #endif

    #ifdef platform_avr
        #ifndef conf_atm64_watch4
            return pi;
        #endif
    #endif

    return 3.141592;
}

char * int_to_char(int val){
    char str[2] = "";
    printf(str, "%d", val);
    return str;
}

void int_to_char(char *string, int num, bool fillNull){
    sprintf(string, (num<10&&fillNull?"0%d":"%d"), num);
}

// 1 bit array operations
void set_bit_to_byte(unsigned char &b, unsigned char position, bool value){ if (value) b|=1<<position; else b&=~(1<<position);}
bool get_bit_from_byte(unsigned char b, unsigned char position){return (b&1<<position);}

/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                   #
    #                           READ RAW DATA                           #
    #                                                                   #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

// Also this func need for B apps
uint64_t bytes_to_value(byte byte0, byte byte1, byte byte2, byte byte3, byte byte4, byte byte5, byte byte6, byte byte7){
  return (byte7<<56)|(byte6<<48)|(byte5<<40)|(byte4<<32)|(byte3<<24)|(byte2<<16)|(byte1<<8)|byte0;
}

int readRawParam(const unsigned char* data, long &position){
    byte paramType = readRawChar(data, position);

    if (paramType==0x02){
      return (byte)readRawChar(data, position);
    }else if(paramType==0x03){
      return (unsigned int)bytes_to_value(readRawChar(data, position), readRawChar(data, position),0,0,0,0,0,0);
    }
}

long readRawChar(const unsigned char* data, long &position){
    unsigned char data_char = (char)pgm_read_word(&(data[position]));
    position ++;
    return data_char;
}   

/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                   #
    #                              CONVERT                              #
    #                                                                   #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                   #
    #                               OTHER                               #
    #                                                                   #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

#ifdef device_can_cpu_prescale
    #ifdef platform_avr
        void set_cpu_prescale(clock_div_t prescale){
            clock_prescale_set(prescale);
        }
    #endif
#endif