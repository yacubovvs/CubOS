
#define SOFTWARE_KEYBOARD_ENABLE

#ifdef SOFTWARE_KEYBOARD_ENABLE
    #ifndef SOFTWARE_KEYBOARD_HEIGHT
        #define SOFTWARE_KEYBOARD_HEIGHT (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT  - FONT_CHAR_HEIGHT*FONT_SIZE_DEFAULT*3 - 1)
    #endif

    #ifndef SOFTWARE_KEYBOARD_WIDTH
        #define SOFTWARE_KEYBOARD_WIDTH (SCREEN_WIDTH - SOFTWARE_BUTTONS_BAR_SIZE - 1)
    #endif

    bool core_software_keyboard_isVisible = false;

    bool get_core_software_keyboard_isVisible(){
        return core_software_keyboard_isVisible;
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
        int i=0;
        setDrawColor(64, 64, 64);
        for(int y_buttons = 0; y_buttons < 4; y_buttons++){
            for(int x_buttons = 0; x_buttons < 3; x_buttons++){
                drawString_centered(String(i), 
                    x_buttons*SOFTWARE_KEYBOARD_WIDTH/3 + SOFTWARE_KEYBOARD_WIDTH/6, 
                    (SCREEN_HEIGHT - keyBoardRealHeight) + y_buttons*SOFTWARE_KEYBOARD_HEIGHT/4 + SOFTWARE_KEYBOARD_HEIGHT/8 - FONT_CHAR_HEIGHT/2
                );
                i ++;
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