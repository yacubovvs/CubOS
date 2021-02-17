package ru.cubos.server;

import ru.cubos.UserInterfaceListener;
import ru.cubos.emulator.Emulator;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.util.Scanner;

public class ReadServer implements UserInterfaceListener {
    Emulator emulator;
    Color currentColor;

    int x,y;
    public ReadServer(Emulator emulator){
        this.emulator = emulator;
        currentColor = new Color(0,0,0);

        Thread readThread = new Thread(new Runnable() {
            @Override
            public void run() {
                Scanner in = new Scanner(System.in);
                //System.out.print("Input a number: ");
                while(true){
                    String inString = in.nextLine();
                    if(inString.length()>0){
                        if(inString.trim().equals("quit")){
                            emulator.setVisible(false);
                            System.exit(0);
                            break;
                        }else{
                            decodeCommand(inString.trim());
                        }
                    }


                }

                in.close();
            }
        });

        readThread.start();
    }

    int n=0;

    private void decodeCommand(String message) {
        String[] messages = message.split(" ");
        int x, y, w, h, r, g, b;

        switch(messages[0]){
            case "P":   // Pixel
                try{
                    x = Integer.parseInt(messages[1]);
                    y = Integer.parseInt(messages[2]);
                    emulator.drawPixel(x,y, currentColor);
                }catch (Exception e){}
                break;
            case "LH":      // Fast line hotizontal
                try{
                    x = Integer.parseInt(messages[1]);
                    y = Integer.parseInt(messages[2]);
                    w = Integer.parseInt(messages[3]);
                    emulator.drawLine(x,y,x+w,y, currentColor);
                }catch (Exception e){}
                break;
            case "LV":      // Fast line vertical
                try{
                    x = Integer.parseInt(messages[1]);
                    y = Integer.parseInt(messages[2]);
                    h = Integer.parseInt(messages[3]);
                    emulator.drawLine(x,y,x,y+h, currentColor);
                }catch (Exception e){}
                break;
            case "R":       // Rectangle
                try{
                    x = Integer.parseInt(messages[1]);
                    y = Integer.parseInt(messages[2]);
                    w = Integer.parseInt(messages[3]);
                    h = Integer.parseInt(messages[4]);
                    emulator.drawRect(x, y,x+w,y+h, currentColor);
                }catch (Exception e){}
                break;
            case "F":       // Fill
                emulator.drawRect(0, 0, emulator.getWidth(),emulator.getHeight(), currentColor);
                break;
            case "U":       // Update
                emulator.updateImage();
                break;
            case "K":       // Read keys
                if(n==2){
                    System.out.println("1 0 0 0");
                    n = 0;
                }else{
                    System.out.println("0 0 0 0");
                }
                n++;
                break;
            case "C":       // Set color
                try{
                    r = Integer.parseInt(messages[1]);
                    g = Integer.parseInt(messages[2]);
                    b = Integer.parseInt(messages[3]);
                    currentColor = new Color(r,g,b);
                }catch (Exception e){}
                break;
            case "Ready":   // Ask for ready
                System.out.println("Ready");
                break;
            default:
                return;
        }

        //emulator.updateImage();
    }

    @Override
    public void keyTyped(KeyEvent keyEvent) {
        if(keyEvent.getKeyCode()==37){
            // Left
        }

        if(keyEvent.getKeyCode()==38){
            // Up
        }

        if(keyEvent.getKeyCode()==39){
            // Right
        }

        if(keyEvent.getKeyCode()==40){
            // Right
        }

        return;
    }

    @Override
    public void keyPressed(KeyEvent keyEvent) {
        return;
    }

    @Override
    public void keyReleased(KeyEvent keyEvent) {
        return;
    }

    void addUserEvent(){

    }

    enum UserEvent{
        BUTTON_UP,
        BUTTON_DOWN,
        BUTTON_SELECT,
        BUTTON_BACK,

    }
}
