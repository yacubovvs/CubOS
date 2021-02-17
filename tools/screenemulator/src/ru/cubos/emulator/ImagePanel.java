package ru.cubos.emulator;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;

public class ImagePanel extends JPanel {
    BufferedImage image;

    float image_k = 1;
    boolean verticalOffset = false;
    int offsetSize = 0;
    float scale_k = 1;

    public ImagePanel() { }

    public void loadImage(BufferedImage image){
        setLayout(new BorderLayout());
        setImage(image);
    }

    public void setImage(BufferedImage image) {
        this.image = image;
    }

    public void paintComponent(Graphics g) {

        super.paintComponent(g);
        if(image != null){

            float panel_k = (float)getWidth()/(float)getHeight();
            image_k = (float)image.getWidth()/(float)image.getHeight();

            if(panel_k>image_k){
                verticalOffset = false;
                offsetSize = (getWidth() - (int)(getHeight()*image_k))/2;
                scale_k = (float)getHeight()/(float)image.getHeight();
                g.drawImage(image,  offsetSize, 0, (int)(getHeight()*image_k), getHeight(), null);
            }else{
                verticalOffset = true;
                offsetSize = (getHeight() - (int)(getWidth()/image_k))/2;
                scale_k = (float)getWidth()/(float)image.getWidth();
                g.drawImage(image, 0, offsetSize, getWidth(),  (int)(getWidth()/image_k), null);
            }

        }

    }

}