package ru.cubos.emulator;

import ru.cubos.UserInterfaceListener;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;

public class Emulator extends JFrame {
    private ImagePanel imageWrapper;
    public BufferedImage image;

    protected int width;
    protected int height;

    protected String isTouched = "0";
    protected String touchX = addLeaderZeroes(0);
    protected String touchY = addLeaderZeroes(0);

    public Emulator(int width, int height){
        imageWrapper = new EmulatorImagePanel(this);
        setContentPane(imageWrapper);
        setTitle("CubOS3 Emulator");

        setScreenWidth(width);
        setScreenHeight(height);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        setSize(new Dimension(getScreenWidth() + 45,getScreenHeight() + 80));
        image = new BufferedImage(getScreenWidth(), getScreenHeight(), BufferedImage.TYPE_INT_RGB);
        updateImage();
        setVisible(true);

        imageWrapper.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent mouseEvent) {
                touchX = addLeaderZeroes(getTouchX(mouseEvent));
                touchY = addLeaderZeroes(getTouchY(mouseEvent));
            }

            @Override
            public void mouseMoved(MouseEvent mouseEvent) {

            }
        });

        imageWrapper.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent mouseEvent) {

            }

            @Override
            public void mousePressed(MouseEvent mouseEvent) {
                //System.out.println("Mouse press start");

                touchX = addLeaderZeroes(getTouchX(mouseEvent));
                touchY = addLeaderZeroes(getTouchY(mouseEvent));
                isTouched = "1";
            }

            @Override
            public void mouseReleased(MouseEvent mouseEvent) {
                //System.out.println("Mouse press released");
                isTouched = "0";
            }

            @Override
            public void mouseEntered(MouseEvent mouseEvent) {

            }

            @Override
            public void mouseExited(MouseEvent mouseEvent) {

            }
        });
    }

    float screen_koef = (float) 0.0;

    float x_koef;
    float y_koef;
    void updateScreenKoef(){
        x_koef = (float)this.imageWrapper.getWidth()/(float)this.getScreenWidth();
        y_koef = (float)this.imageWrapper.getHeight()/(float)this.getScreenHeight();
        //System.out.println("x_koef " + x_koef);
        //System.out.println("y_koef " + y_koef);

        screen_koef = Math.min(x_koef, y_koef);
    }

    private int getTouchX(MouseEvent mouseEvent){
        updateScreenKoef();
        int touch_x = mouseEvent.getX();
        touch_x = this.getScreenWidth()/2 - (int)(((float)(this.imageWrapper.getWidth()/2 - mouseEvent.getX()))/screen_koef);
        //System.out.println("Touch event x: " + (int)(((float)(this.getWidth()/2 - mouseEvent.getX()))/screen_koef));
        if(touch_x>this.getScreenWidth()) touch_x = this.getScreenWidth();
        if(touch_x<0) touch_x = 0;

        //System.out.println("Touch event x: " + touch_x);
        return touch_x;
    }
    private int getTouchY(MouseEvent mouseEvent){
        updateScreenKoef();
        int touch_y = mouseEvent.getY();
        touch_y = this.getScreenHeight()/2 - (int)(((float)(this.imageWrapper.getHeight()/2 - mouseEvent.getY()))/screen_koef);
        if(touch_y>this.getScreenHeight()) touch_y = this.getScreenHeight();
        if(touch_y<0) touch_y = 0;
        //System.out.println("Touch event y: " + touch_y);
        return touch_y;
    }

    public String addLeaderZeroes(int value){
        String outString = ("00000" + value);
        outString = outString.substring(outString.length()-5);
        //System.out.println(outString);
        return outString;
    }

    public BufferedImage getImage(){
        return image;
    }

    public void updateImage(BufferedImage image){
        this.image = image;
        imageWrapper.setImage(image);
        repaint();
    }

    public void updateImage(){
        imageWrapper.setImage(image);
        repaint();
    }

    private void createUIComponents() {
        //imageWrapper = new EmulatorImagePanel(this);
    }

    /*
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * *                                                                                                             * *
     * *                                                   DRAWING                                                   * *
     * *                                                                                                             * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     */

    void drawPixel(int x, int y, int r, int g, int b){
        Color  color = new Color(r,g,b);
        image.setRGB(x,y, color.getRGB());
    }

    public void drawPixel(int x, int y, Color color){
        image.setRGB(x,y, color.getRGB());
    }

    static final char font_cubos[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x5B, 0x4F, 0x5B, 0x3E, 0x3E, 0x6B, 0x4F, 0x6B, 0x3E, 0x1C, 0x3E, 0x7C, 0x3E, 0x1C, 0x18, 0x3C, 0x7E, 0x3C, 0x18, 0x1C, 0x57, 0x7D, 0x57, 0x1C, 0x1C, 0x5E, 0x7F, 0x5E, 0x1C, 0x00, 0x18, 0x3C, 0x18, 0x00,
            0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 0x00, 0x18, 0x24, 0x18, 0x00, 0xFF, 0xE7, 0xDB, 0xE7, 0xFF, 0x30, 0x48, 0x3A, 0x06, 0x0E, 0x26, 0x29, 0x79, 0x29, 0x26, 0x40, 0x7F, 0x05, 0x05, 0x07, 0x40, 0x7F, 0x05, 0x25, 0x3F, 0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
            0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x14, 0x22, 0x7F, 0x22, 0x14, 0x5F, 0x5F, 0x00, 0x5F, 0x5F, 0x06, 0x09, 0x7F, 0x01, 0x7F, 0x00, 0x66, 0x89, 0x95, 0x6A, 0x60, 0x60, 0x60, 0x60, 0x60, 0x94, 0xA2, 0xFF, 0xA2, 0x94,
            0x08, 0x04, 0x7E, 0x04, 0x08, 0x10, 0x20, 0x7E, 0x20, 0x10, 0x08, 0x08, 0x2A, 0x1C, 0x08, 0x08, 0x1C, 0x2A, 0x08, 0x08, 0x1E, 0x10, 0x10, 0x10, 0x10, 0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 0x30, 0x38, 0x3E, 0x38, 0x30, 0x06, 0x0E, 0x3E, 0x0E, 0x06,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x23, 0x13, 0x08, 0x64, 0x62, 0x36, 0x49, 0x56, 0x20, 0x50, 0x00, 0x08, 0x07, 0x03, 0x00,
            0x00, 0x1C, 0x22, 0x41, 0x00, 0x00, 0x41, 0x22, 0x1C, 0x00, 0x2A, 0x1C, 0x7F, 0x1C, 0x2A, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 0x80, 0x70, 0x30, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x60, 0x60, 0x00, 0x20, 0x10, 0x08, 0x04, 0x02,
            0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00, 0x42, 0x7F, 0x40, 0x00, 0x72, 0x49, 0x49, 0x49, 0x46, 0x21, 0x41, 0x49, 0x4D, 0x33, 0x18, 0x14, 0x12, 0x7F, 0x10, 0x27, 0x45, 0x45, 0x45, 0x39, 0x3C, 0x4A, 0x49, 0x49, 0x31, 0x41, 0x21, 0x11, 0x09, 0x07,
            0x36, 0x49, 0x49, 0x49, 0x36, 0x46, 0x49, 0x49, 0x29, 0x1E, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x40, 0x34, 0x00, 0x00, 0x00, 0x08, 0x14, 0x22, 0x41, 0x14, 0x14, 0x14, 0x14, 0x14, 0x00, 0x41, 0x22, 0x14, 0x08, 0x02, 0x01, 0x59, 0x09, 0x06,
            0x3E, 0x41, 0x5D, 0x59, 0x4E, 0x7C, 0x12, 0x11, 0x12, 0x7C, 0x7F, 0x49, 0x49, 0x49, 0x36, 0x3E, 0x41, 0x41, 0x41, 0x22, 0x7F, 0x41, 0x41, 0x41, 0x3E, 0x7F, 0x49, 0x49, 0x49, 0x41, 0x7F, 0x09, 0x09, 0x09, 0x01, 0x3E, 0x41, 0x41, 0x51, 0x73,
            0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 0x41, 0x7F, 0x41, 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, 0x7F, 0x08, 0x14, 0x22, 0x41, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x7F, 0x02, 0x1C, 0x02, 0x7F, 0x7F, 0x04, 0x08, 0x10, 0x7F, 0x3E, 0x41, 0x41, 0x41, 0x3E,
            0x7F, 0x09, 0x09, 0x09, 0x06, 0x3E, 0x41, 0x51, 0x21, 0x5E, 0x7F, 0x09, 0x19, 0x29, 0x46, 0x26, 0x49, 0x49, 0x49, 0x32, 0x03, 0x01, 0x7F, 0x01, 0x03, 0x3F, 0x40, 0x40, 0x40, 0x3F, 0x1F, 0x20, 0x40, 0x20, 0x1F, 0x3F, 0x40, 0x38, 0x40, 0x3F,
            0x63, 0x14, 0x08, 0x14, 0x63, 0x03, 0x04, 0x78, 0x04, 0x03, 0x61, 0x59, 0x49, 0x4D, 0x43, 0x00, 0x7F, 0x41, 0x41, 0x41, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x41, 0x41, 0x41, 0x7F, 0x04, 0x02, 0x01, 0x02, 0x04, 0x40, 0x40, 0x40, 0x40, 0x40,
            0x00, 0x03, 0x07, 0x08, 0x00, 0x20, 0x54, 0x54, 0x78, 0x40, 0x7F, 0x28, 0x44, 0x44, 0x38, 0x38, 0x44, 0x44, 0x44, 0x28, 0x38, 0x44, 0x44, 0x28, 0x7F, 0x38, 0x54, 0x54, 0x54, 0x18, 0x00, 0x08, 0x7E, 0x09, 0x02, 0x18, 0xA4, 0xA4, 0x9C, 0x78,
            0x7F, 0x08, 0x04, 0x04, 0x78, 0x00, 0x44, 0x7D, 0x40, 0x00, 0x20, 0x40, 0x40, 0x3D, 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, 0x00, 0x41, 0x7F, 0x40, 0x00, 0x7C, 0x04, 0x78, 0x04, 0x78, 0x7C, 0x08, 0x04, 0x04, 0x78, 0x38, 0x44, 0x44, 0x44, 0x38,
            0xFC, 0x18, 0x24, 0x24, 0x18, 0x18, 0x24, 0x24, 0x18, 0xFC, 0x7C, 0x08, 0x04, 0x04, 0x08, 0x48, 0x54, 0x54, 0x54, 0x24, 0x04, 0x04, 0x3F, 0x44, 0x24, 0x3C, 0x40, 0x40, 0x20, 0x7C, 0x1C, 0x20, 0x40, 0x20, 0x1C, 0x3C, 0x40, 0x30, 0x40, 0x3C,
            0x44, 0x28, 0x10, 0x28, 0x44, 0x4C, 0x90, 0x90, 0x90, 0x7C, 0x44, 0x64, 0x54, 0x4C, 0x44, 0x00, 0x08, 0x36, 0x41, 0x00, 0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 0x41, 0x36, 0x08, 0x00, 0x02, 0x01, 0x02, 0x04, 0x02, 0x3C, 0x26, 0x23, 0x26, 0x3C,
            0x1E, 0xA1, 0xA1, 0x61, 0x12, 0x3A, 0x40, 0x40, 0x20, 0x7A, 0x38, 0x54, 0x54, 0x55, 0x59, 0x21, 0x55, 0x55, 0x79, 0x41, 0x22, 0x54, 0x54, 0x78, 0x42, 0x21, 0x55, 0x54, 0x78, 0x40, 0x20, 0x54, 0x55, 0x79, 0x40, 0x0C, 0x1E, 0x52, 0x72, 0x12,
            0x39, 0x55, 0x55, 0x55, 0x59, 0x39, 0x54, 0x54, 0x54, 0x59, 0x39, 0x55, 0x54, 0x54, 0x58, 0x00, 0x00, 0x45, 0x7C, 0x41, 0x00, 0x02, 0x45, 0x7D, 0x42, 0x00, 0x01, 0x45, 0x7C, 0x40, 0x7D, 0x12, 0x11, 0x12, 0x7D, 0xF0, 0x28, 0x25, 0x28, 0xF0,
            0x7C, 0x54, 0x55, 0x45, 0x00, 0x20, 0x54, 0x54, 0x7C, 0x54, 0x7C, 0x0A, 0x09, 0x7F, 0x49, 0x32, 0x49, 0x49, 0x49, 0x32, 0x3A, 0x44, 0x44, 0x44, 0x3A, 0x32, 0x4A, 0x48, 0x48, 0x30, 0x3A, 0x41, 0x41, 0x21, 0x7A, 0x3A, 0x42, 0x40, 0x20, 0x78,
            0x00, 0x9D, 0xA0, 0xA0, 0x7D, 0x3D, 0x42, 0x42, 0x42, 0x3D, 0x3D, 0x40, 0x40, 0x40, 0x3D, 0x3C, 0x24, 0xFF, 0x24, 0x24, 0x48, 0x7E, 0x49, 0x43, 0x66, 0x2B, 0x2F, 0xFC, 0x2F, 0x2B, 0xFF, 0x09, 0x29, 0xF6, 0x20, 0xC0, 0x88, 0x7E, 0x09, 0x03,
            0x20, 0x54, 0x54, 0x79, 0x41, 0x00, 0x00, 0x44, 0x7D, 0x41, 0x30, 0x48, 0x48, 0x4A, 0x32, 0x38, 0x40, 0x40, 0x22, 0x7A, 0x00, 0x7A, 0x0A, 0x0A, 0x72, 0x7D, 0x0D, 0x19, 0x31, 0x7D, 0x26, 0x29, 0x29, 0x2F, 0x28, 0x26, 0x29, 0x29, 0x29, 0x26,
            0x30, 0x48, 0x4D, 0x40, 0x20, 0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x38, 0x2F, 0x10, 0xC8, 0xAC, 0xBA, 0x2F, 0x10, 0x28, 0x34, 0xFA, 0x00, 0x00, 0x7B, 0x00, 0x00, 0x08, 0x14, 0x2A, 0x14, 0x22, 0x22, 0x14, 0x2A, 0x14, 0x08,
            0x55, 0x00, 0x55, 0x00, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0xFF, 0x55, 0xFF, 0x55, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x10, 0x10, 0x10, 0xFF, 0x00, 0x14, 0x14, 0x14, 0xFF, 0x00, 0x10, 0x10, 0xFF, 0x00, 0xFF, 0x10, 0x10, 0xF0, 0x10, 0xF0,
            0x14, 0x14, 0x14, 0xFC, 0x00, 0x14, 0x14, 0xF7, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x14, 0x14, 0xF4, 0x04, 0xFC, 0x14, 0x14, 0x17, 0x10, 0x1F, 0x10, 0x10, 0x1F, 0x10, 0x1F, 0x14, 0x14, 0x14, 0x1F, 0x00, 0x10, 0x10, 0x10, 0xF0, 0x00,
            0x00, 0x00, 0x00, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x1F, 0x10, 0x10, 0x10, 0x10, 0xF0, 0x10, 0x00, 0x00, 0x00, 0xFF, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xFF, 0x10, 0x00, 0x00, 0x00, 0xFF, 0x14, 0x00, 0x00, 0xFF, 0x00, 0xFF,
            0x00, 0x00, 0x1F, 0x10, 0x17, 0x00, 0x00, 0xFC, 0x04, 0xF4, 0x14, 0x14, 0x17, 0x10, 0x17, 0x14, 0x14, 0xF4, 0x04, 0xF4, 0x00, 0x00, 0xFF, 0x00, 0xF7, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0xF7, 0x00, 0xF7, 0x14, 0x14, 0x14, 0x17, 0x14,
            0x10, 0x10, 0x1F, 0x10, 0x1F, 0x14, 0x14, 0x14, 0xF4, 0x14, 0x10, 0x10, 0xF0, 0x10, 0xF0, 0x00, 0x00, 0x1F, 0x10, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x14, 0x00, 0x00, 0x00, 0xFC, 0x14, 0x00, 0x00, 0xF0, 0x10, 0xF0, 0x10, 0x10, 0xFF, 0x10, 0xFF,
            0x14, 0x14, 0x14, 0xFF, 0x14, 0x10, 0x10, 0x10, 0x1F, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
            0x38, 0x44, 0x44, 0x38, 0x44, 0xFC, 0x4A, 0x4A, 0x4A, 0x34, 0x7E, 0x02, 0x02, 0x06, 0x06, 0x02, 0x7E, 0x02, 0x7E, 0x02, 0x63, 0x55, 0x49, 0x41, 0x63, 0x38, 0x44, 0x44, 0x3C, 0x04, 0x40, 0x7E, 0x20, 0x1E, 0x20, 0x06, 0x02, 0x7E, 0x02, 0x02,
            0x99, 0xA5, 0xE7, 0xA5, 0x99, 0x1C, 0x2A, 0x49, 0x2A, 0x1C, 0x4C, 0x72, 0x01, 0x72, 0x4C, 0x30, 0x4A, 0x4D, 0x4D, 0x30, 0x30, 0x48, 0x78, 0x48, 0x30, 0xBC, 0x62, 0x5A, 0x46, 0x3D, 0x3E, 0x49, 0x49, 0x49, 0x00, 0x7E, 0x01, 0x01, 0x01, 0x7E,
            0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x44, 0x44, 0x5F, 0x44, 0x44, 0x40, 0x51, 0x4A, 0x44, 0x40, 0x40, 0x44, 0x4A, 0x51, 0x40, 0x00, 0x00, 0xFF, 0x01, 0x03, 0xE0, 0x80, 0xFF, 0x00, 0x00, 0x08, 0x08, 0x6B, 0x6B, 0x08, 0x36, 0x12, 0x36, 0x24, 0x36,
            0x06, 0x0F, 0x09, 0x0F, 0x06, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x30, 0x40, 0xFF, 0x01, 0x01, 0x00, 0x1F, 0x01, 0x01, 0x1E, 0x00, 0x19, 0x1D, 0x17, 0x12, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00
    };


    static final char FONT_CHAR_WIDTH   = 6;
    static final char FONT_CHAR_HEIGHT  = 8;

    public void drawString(int x, int y, String string, Color color, int fontSize){

        byte[] stringBytes = string.getBytes();
        for (int i=0; i<string.length(); i++){

            for (char char_part=0; char_part<5; char_part++){
                byte char_part_element = (byte)(font_cubos[stringBytes[i] *5 + char_part] - 128);
                for (char bit=0; bit<8; bit++){

                    if (((char_part_element >> (bit)) & 1) == (bit!=(char)7?1:0) ){
                        if(fontSize>1){
                            for(int j=0; j<fontSize; j++){
                                for(int jj=0; jj<fontSize; jj++){
                                    drawPixel(x + char_part*fontSize + i*FONT_CHAR_WIDTH*fontSize + jj, y + bit*fontSize - j, color);
                                }
                            }
                        }else{
                            drawPixel((char)(x + char_part + i*FONT_CHAR_WIDTH), (char)(y + bit), color);
                        }
                    }
                }
            }
        }
    }
    public void drawLine(int x0, int y0, int x1, int y1, Color color){
        int dy = y1 - y0; // Difference between y0 and y1
        int dx = x1 - x0; // Difference between x0 and x1
        int stepx, stepy;

        if (dy < 0)
        {
            dy = -dy;
            stepy = -1;
        }
        else
            stepy = 1;

        if (dx < 0)
        {
            dx = -dx;
            stepx = -1;
        }
        else
            stepx = 1;

        dy <<= 1; // dy is now 2*dy
        dx <<= 1; // dx is now 2*dx
        drawPixel(x0, y0, color); // Draw the first pixel.

        if (dx > dy)
        {
            int fraction = dy - (dx >> 1);
            while (x0 != x1)
            {
                if (fraction >= 0)
                {
                    y0 += stepy;
                    fraction -= dx;
                }
                x0 += stepx;
                fraction += dy;
                drawPixel(x0, y0, color);
            }
        }
        else
        {
            int fraction = dx - (dy >> 1);
            while (y0 != y1)
            {
                if (fraction >= 0)
                {
                    x0 += stepx;
                    fraction -= dy;
                }
                y0 += stepy;
                fraction += dx;
                drawPixel(x0, y0, color);
            }
        }
    }

    public void drawRect(int x0, int y0, int x1, int y1, Color color){
        if(x0<0) x0=0;
        if(x1<0) x1=0;
        if(y1<0) y1=0;
        if(y0<0) y0=0;
        if(x0>=width) x0=(char)(width-1);
        if(x1>=width) x1=(char)(width-1);
        if(y0>=height) y0=(char)(height-1);
        if(y1>=height) y1=(char)(height-1);

        int xDiff;
        if(x0 > x1) xDiff = x0 - x1 + 1;
        else xDiff = x1 - x0 + 1;

        if(xDiff==1) drawLine(x0, y0, x0, y1, color);
        else while(xDiff > 0) {
            drawLine(x0, y0, x0, y1, color);
            if(x0 > x1) x0--;
            else x0++;
            xDiff--;
        }

    }

    /*
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * *                                                                                                             * *
     * *                                                    OTHER                                                    * *
     * *                                                                                                             * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     */

    public void setScreenWidth(int width) {
        this.width = width;
    }

    public void setScreenHeight(int height) {
        this.height = height;
    }

    public int getScreenWidth() {
        return width;
    }

    public int getScreenHeight() {
        return height;
    }

}
