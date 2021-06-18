#ifdef SOFTWARE_KEYBOARD_ENABLE
    #ifndef SOFTWARE_KEYBOARD_HEIGHT
        #define SOFTWARE_KEYBOARD_HEIGHT (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT  - FONT_SIZE_DEFAULT*2)
    #endif

    #ifndef SOFTWARE_KEYBOARD_WIDTH
        #define SOFTWARE_KEYBOARD_WIDTH (SCREEN_WIDTH - SOFTWARE_BUTTONS_BAR_SIZE)
    #endif

    core_software_keyboard_show(){

    }

    core_software_keyboard_hide(){
        
    }

    core_software_keyboard_draw(boolean draw){
        
    }

#endif