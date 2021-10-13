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

#ifdef SOFTWARE_KEYBOARD_ENABLE
    unsigned char software_keyboard_type = SOFTWARE_KEYBOARD_TYPES_TEXT;
    int core_software_keyboard_lastActiveBtn = -1;
    bool core_software_keyboard_shift_pressed = false;
    bool core_software_keyboard_caps_pressed = false;

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

    #if SOFTWARE_KEYBOARD_SIZE == SOFTWARE_KEYBOARD_SIZES_MOBILE
        #define SOFTWARE_KEYBOARD_TOTAL_BTNS 12
    #endif

    struct BtnCoords{
        int x1=-1;
        int x2=-1;
        int y1=-1;
        int y2=-1;
        int x_center=-1;
        int y_center=-1;
    };

    BtnCoords core_software_getBtnsCoords(int btnNum){
        BtnCoords coords;
        #if SOFTWARE_KEYBOARD_SIZE == SOFTWARE_KEYBOARD_SIZES_MOBILE
            
            int keyBoardRealHeight = SOFTWARE_KEYBOARD_HEIGHT - SOFTWARE_KEYBOARD_HEIGHT%4;

            unsigned char y_button_num = btnNum/3;
            unsigned char x_button_num = btnNum%3;

            coords.x_center = x_button_num*SOFTWARE_KEYBOARD_WIDTH/3 + SOFTWARE_KEYBOARD_WIDTH/6;
            coords.y_center = (SCREEN_HEIGHT - keyBoardRealHeight) + y_button_num*SOFTWARE_KEYBOARD_HEIGHT/4 + SOFTWARE_KEYBOARD_HEIGHT/8; 
            
            coords.x1 = SOFTWARE_KEYBOARD_WIDTH/3 + SOFTWARE_KEYBOARD_WIDTH*(x_button_num-1)/3;
            coords.x2 = SOFTWARE_KEYBOARD_WIDTH/3 + SOFTWARE_KEYBOARD_WIDTH*x_button_num/3;
            coords.y1 = SCREEN_HEIGHT - keyBoardRealHeight/4 - keyBoardRealHeight*(3-y_button_num)/4;
            coords.y2 = SCREEN_HEIGHT - keyBoardRealHeight/4 - keyBoardRealHeight*((3-y_button_num)-1)/4;

        #endif
        return coords;
    }

    bool core_software_keyboard_isVisible = false;

    bool get_core_software_keyboard_isVisible(){
        return core_software_keyboard_isVisible;
    }

    unsigned char software_keyboard_get_label_levels_in_keyboard(unsigned char keyboard_type, unsigned char button){
        #if SOFTWARE_KEYBOARD_SIZE == SOFTWARE_KEYBOARD_SIZES_MOBILE
            switch(keyboard_type){
                case SOFTWARE_KEYBOARD_TYPES_TEXT:
                    switch(button){
                        case 9:
                        //case 11:
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
                                case 11: return "Capslock";
                            }
                        case 1:
                            if(core_software_keyboard_shift_pressed){
                                switch(button){
                                    case 0: return "123";
                                    case 1: return "ABC";
                                    case 2: return "DEF";
                                    case 3: return "GHI";
                                    case 4: return "JKL";
                                    case 5: return "MNO";
                                    case 6: return "PQRS";
                                    case 7: return "TNV";
                                    case 8: return "WXYZ";
                                    case 10: return "_";
                                    case 11: return "Shift";
                                }
                            }else{
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
                                    case 11: return "Shift";
                                }
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

    int core_software_keyboard_getPressedButton(){
        #if SOFTWARE_KEYBOARD_SIZE == SOFTWARE_KEYBOARD_SIZES_MOBILE
        #endif
        return -1;
    }

    void core_software_keyboard_drawButton(bool draw, int btnNum, bool isActive){
        BtnCoords coords = core_software_getBtnsCoords(btnNum);
        if(coords.x_center==-1||coords.y_center == -1) return;

        if(isActive) setDrawColor(64, 64, 64);
        else setDrawColor(128, 128, 128);
        
        drawRect(coords.x1, coords.y1, coords.x2, coords.y2, true);
        
        if(isActive) setDrawColor(32, 32, 32);
        else setDrawColor(64, 64, 64);

        drawRect(coords.x1, coords.y1, coords.x2, coords.y2, false);

        if(software_keyboard_get_label_levels_in_keyboard(software_keyboard_type, btnNum)==1){
            // For 1 string
            if(isActive) setDrawColor(172, 172, 172);
            else setDrawColor(64, 64, 64);
            //setDrawColor(64, 64, 64);
            drawString_centered(
                software_keyboard_get_button_label(software_keyboard_type, btnNum, 0), 
                coords.x_center, 
                coords.y_center - SOFTWARE_KEYBOARD_KEYS_FONST_SIZE*FONT_CHAR_HEIGHT/2,
                SOFTWARE_KEYBOARD_KEYS_FONST_SIZE
            );
        }else{
            // for 2 strings
            if(isActive) setDrawColor(128, 128, 128);
            else setDrawColor(64, 64, 64);
            //setDrawColor(64, 64, 64);
            drawString_centered(
                software_keyboard_get_button_label(software_keyboard_type, btnNum, 0), 
                coords.x_center, 
                coords.y_center - SOFTWARE_KEYBOARD_KEYS_FONST_SIZE*FONT_CHAR_HEIGHT/2  - SOFTWARE_KEYBOARD_KEYS_BETWEEN_LINES_MARGIN/2,
                SOFTWARE_KEYBOARD_KEYS_FONST_SIZE
            );

            if(isActive) setDrawColor(216, 216, 216);
            else setDrawColor(0, 0, 0);
            //setDrawColor(0, 0, 0);
            drawString_centered(
                software_keyboard_get_button_label(software_keyboard_type, btnNum, 1), 
                coords.x_center, 
                coords.y_center - SOFTWARE_KEYBOARD_KEYS_FONST_SIZE*FONT_CHAR_HEIGHT/2 + SOFTWARE_KEYBOARD_KEYS_BETWEEN_LINES_MARGIN/2,
                SOFTWARE_KEYBOARD_KEYS_FONST_SIZE
            );   
        }
    }

    void core_software_keyboard_draw(bool draw){
        for(int btnNum=0; btnNum<SOFTWARE_KEYBOARD_TOTAL_BTNS; btnNum++){
            core_software_keyboard_drawButton(draw, btnNum, false);
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

    bool core_software_keyboard_isTouchInBtn(int btnNum, int touch_x, int touch_y){
        BtnCoords coords = core_software_getBtnsCoords(btnNum);
        if(
            touch_x>coords.x1 && 
            touch_x<coords.x2 &&
            touch_y>coords.y1 && 
            touch_y<coords.y2 &&
            true
        ) return true;
        else return false;
    }

    int core_software_keyboard_getTouchingButton(int touch_x, int touch_y){
        for(int btnNum=0; btnNum<SOFTWARE_KEYBOARD_TOTAL_BTNS; btnNum++){
            if(core_software_keyboard_isTouchInBtn(btnNum, touch_x, touch_y)) return btnNum; 
        }
        return -1;
    }

    void core_software_keyboard_onEvent(unsigned char event, int val1, int val2, int val3, int val4, int val5){
        if(!core_software_keyboard_isVisible) return; 
        
        if(event==EVENT_ON_TOUCH_START){
            //debug("On keyboard touch start " + String(val1) + " " + String(val2));
            int touch_btn = core_software_keyboard_getTouchingButton(val1, val2);

            #if SOFTWARE_KEYBOARD_SIZE == SOFTWARE_KEYBOARD_SIZES_MOBILE
                if(software_keyboard_type == SOFTWARE_KEYBOARD_TYPES_TEXT && touch_btn==11){
                    if(core_software_keyboard_shift_pressed){
                        if(core_software_keyboard_caps_pressed){
                            core_software_keyboard_shift_pressed = false;
                            core_software_keyboard_caps_pressed = false;
                            core_software_keyboard_draw(true);
                        }else{
                            core_software_keyboard_caps_pressed = true;
                            //core_software_keyboard_draw(true);
                            core_software_keyboard_drawButton(true, 11, true);
                        }
                    }else{
                        core_software_keyboard_shift_pressed = true;
                        core_software_keyboard_draw(true);
                        core_software_keyboard_lastActiveBtn = touch_btn;
                        core_software_keyboard_drawButton(true, touch_btn, true);
                    }
                }else 
            #endif
            if(touch_btn!=-1){
                //debug("Touching " + String(touch_btn) + "!");
                core_software_keyboard_lastActiveBtn = touch_btn;
                core_software_keyboard_drawButton(true, touch_btn, true);
            }
        }else if(event==EVENT_ON_TOUCH_CLICK){    

        }else if(event==EVENT_ON_TOUCH_RELEASED){
            if(core_software_keyboard_lastActiveBtn!=-1){
                core_software_keyboard_drawButton(true, core_software_keyboard_lastActiveBtn, false);
                core_software_keyboard_lastActiveBtn=-1;
            }
        }else if(event==EVENT_ON_TOUCH_DRAG){

        }
    }

#endif