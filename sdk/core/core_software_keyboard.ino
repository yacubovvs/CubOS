
#define SOFTWARE_KEYBOARD_ENABLE

#define SOFTWARE_KEYBOARD_SIZES_MOBILE 0x00
#define SOFTWARE_KEYBOARD_SIZES_FULL 0x01

#ifndef SOFTWARE_KEYBOARD_SIZE
    #define SOFTWARE_KEYBOARD_SIZE SOFTWARE_KEYBOARD_SIZES_MOBILE
#endif 

#define SOFTWARE_KEYBOARD_TYPES_TEXT                0x00
#define SOFTWARE_KEYBOARD_TYPES_UPPER_TEXT          0x01
#define SOFTWARE_KEYBOARD_TYPES_NUMBERS             0x02
#define SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_1      0x03
#define SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_2      0x04
#define SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_3      0x05
#define SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_4      0x06

unsigned char software_keyboard_type = SOFTWARE_KEYBOARD_TYPES_TEXT;

#ifdef SOFTWARE_KEYBOARD_ENABLE
    #ifndef SOFTWARE_KEYBOARD_HEIGHT
        #define SOFTWARE_KEYBOARD_HEIGHT (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT  - FONT_CHAR_HEIGHT*FONT_SIZE_DEFAULT*3 - 1)
    #endif

    #ifndef SOFTWARE_KEYBOARD_WIDTH
        #define SOFTWARE_KEYBOARD_WIDTH (SCREEN_WIDTH - SOFTWARE_BUTTONS_BAR_SIZE - 1)
    #endif

    #ifndef SOFTWARE_KEYBOARD_KEYS_FONST_SIZE
        #define SOFTWARE_KEYBOARD_KEYS_FONST_SIZE 1
    #endif

    #ifndef SOFTWARE_KEYBOARD_KEYS_BETWEEN_LINES_MARGIN
        //#define SOFTWARE_KEYBOARD_KEYS_BETWEEN_LINES_MARGIN (SOFTWARE_KEYBOARD_KEYS_FONST_SIZE*FONT_CHAR_HEIGHT*4/3)
        #define SOFTWARE_KEYBOARD_KEYS_BETWEEN_LINES_MARGIN (SOFTWARE_KEYBOARD_KEYS_FONST_SIZE*FONT_CHAR_HEIGHT*5/3)
    #endif

    bool core_software_keyboard_isVisible = false;

    bool get_core_software_keyboard_isVisible(){
        return core_software_keyboard_isVisible;
    }

    unsigned char software_keyboard_get_levels_in_keyboard(unsigned char keyboard_type, unsigned char button){
        #if SOFTWARE_KEYBOARD_SIZE == SOFTWARE_KEYBOARD_SIZES_MOBILE
            switch(keyboard_type){
                case SOFTWARE_KEYBOARD_TYPES_TEXT:
                    switch(button){
                        case 9:
                        case 11:
                            return 1;
                    }
                    return 2;
                case SOFTWARE_KEYBOARD_TYPES_UPPER_TEXT:
                    return 2;
                case SOFTWARE_KEYBOARD_TYPES_NUMBERS:
                    switch(button){
                        case 9:
                        case 10:
                        case 11:
                            return 2;
                    }
                    return 1;
                case SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_1:
                    return 1;
                case SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_2:
                    return 1;
                case SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_3:
                    return 1;
                case SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_4:
                    return 1;
            }
            return 1;
        #else
            return 1;
        #endif
    }

    String software_keyboard_get_button_label(unsigned char keyboard_type, int button, unsigned char level){
        #if SOFTWARE_KEYBOARD_SIZE == SOFTWARE_KEYBOARD_SIZES_MOBILE
            switch(keyboard_type){
                case SOFTWARE_KEYBOARD_TYPES_TEXT:
                    switch(level){
                        case 0:
                            switch(button){
                                case 0: return "1";
                                case 1: return "2";
                                case 2: return "3";
                                case 3: return "4";
                                case 4: return "5";
                                case 5: return "6";
                                case 6: return "7";
                                case 7: return "8";
                                case 8: return "9";
                                case 9: return "%&?";
                                case 10: return "0";
                                case 11: return "Shift";
                            }
                        case 1:
                            switch(button){
                                case 0: return "123";
                                case 1: return "abc";
                                case 2: return "def";
                                case 3: return "ghi";
                                case 4: return "jkl";
                                case 5: return "mno";
                                case 6: return "pqrs";
                                case 7: return "tnv";
                                case 8: return "wxyz";
                                case 10: return "_";
                            }
                    }
                    return "";
                case SOFTWARE_KEYBOARD_TYPES_UPPER_TEXT:
                    return "2";
                case SOFTWARE_KEYBOARD_TYPES_NUMBERS:
                    return "1";
                case SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_1:
                    return "1";
                case SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_2:
                    return "1";
                case SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_3:
                    return "1";
                case SOFTWARE_KEYBOARD_TYPES_SCPECSYMBOLS_4:
                    return "1";
            }
            return "1";
        #else
            return "1";
        #endif
    }

    void core_software_keyboard_draw(bool draw){

        //For small screens as 240x230

        setDrawColor(128, 128, 128);
        int keyBoardRealHeight = SOFTWARE_KEYBOARD_HEIGHT - SOFTWARE_KEYBOARD_HEIGHT%4;
        drawRect(0, SCREEN_HEIGHT, SOFTWARE_KEYBOARD_WIDTH, SCREEN_HEIGHT - keyBoardRealHeight, true);

        // Buttons lines
        setDrawColor(64, 64, 64);
        for(int y_buttons = SCREEN_HEIGHT - keyBoardRealHeight/4; y_buttons > SCREEN_HEIGHT - keyBoardRealHeight; y_buttons-=keyBoardRealHeight/4){
            drawLine(0, y_buttons, SOFTWARE_KEYBOARD_WIDTH, y_buttons);
        }

        for(int x_buttons = SOFTWARE_KEYBOARD_WIDTH/3; x_buttons < SCREEN_WIDTH - SOFTWARE_KEYBOARD_WIDTH/3; x_buttons+=SOFTWARE_KEYBOARD_WIDTH/3){
            drawLine(x_buttons, SCREEN_HEIGHT, x_buttons, SCREEN_HEIGHT - keyBoardRealHeight);
        }

        // Labels
        unsigned char button_num=0;
        setDrawColor(64, 64, 64);
        for(int y_buttons = 0; y_buttons < 4; y_buttons++){
            for(int x_buttons = 0; x_buttons < 3; x_buttons++){
                if(software_keyboard_get_levels_in_keyboard(software_keyboard_type, button_num)==1){
                    // For 1 string
                    drawString_centered(
                        software_keyboard_get_button_label(software_keyboard_type, button_num, 0), 
                        x_buttons*SOFTWARE_KEYBOARD_WIDTH/3 + SOFTWARE_KEYBOARD_WIDTH/6, 
                        (SCREEN_HEIGHT - keyBoardRealHeight) + y_buttons*SOFTWARE_KEYBOARD_HEIGHT/4 + SOFTWARE_KEYBOARD_HEIGHT/8 - SOFTWARE_KEYBOARD_KEYS_FONST_SIZE*FONT_CHAR_HEIGHT/2,
                        SOFTWARE_KEYBOARD_KEYS_FONST_SIZE
                    );
                }else{
                    // for 2 strings
                    setDrawColor(64, 64, 64);
                    drawString_centered(
                        software_keyboard_get_button_label(software_keyboard_type, button_num, 0), 
                        x_buttons*SOFTWARE_KEYBOARD_WIDTH/3 + SOFTWARE_KEYBOARD_WIDTH/6, 
                        (SCREEN_HEIGHT - keyBoardRealHeight) + y_buttons*SOFTWARE_KEYBOARD_HEIGHT/4 + SOFTWARE_KEYBOARD_HEIGHT/8 - SOFTWARE_KEYBOARD_KEYS_FONST_SIZE*FONT_CHAR_HEIGHT/2  - SOFTWARE_KEYBOARD_KEYS_BETWEEN_LINES_MARGIN/2,
                        SOFTWARE_KEYBOARD_KEYS_FONST_SIZE
                    );

                    setDrawColor(0, 0, 0);
                    drawString_centered(
                        software_keyboard_get_button_label(software_keyboard_type, button_num, 1), 
                        x_buttons*SOFTWARE_KEYBOARD_WIDTH/3 + SOFTWARE_KEYBOARD_WIDTH/6, 
                        (SCREEN_HEIGHT - keyBoardRealHeight) + y_buttons*SOFTWARE_KEYBOARD_HEIGHT/4 + SOFTWARE_KEYBOARD_HEIGHT/8 - SOFTWARE_KEYBOARD_KEYS_FONST_SIZE*FONT_CHAR_HEIGHT/2 + SOFTWARE_KEYBOARD_KEYS_BETWEEN_LINES_MARGIN/2,
                        SOFTWARE_KEYBOARD_KEYS_FONST_SIZE
                    );   
                }

                button_num ++;
            }
        }
    }

    void core_software_keyboard_show(){
        core_software_keyboard_isVisible = true;
        core_software_keyboard_draw(true);
    }

    void core_software_keyboard_hide(){
        core_software_keyboard_isVisible = false;
        core_software_keyboard_draw(false);
    }

#endif