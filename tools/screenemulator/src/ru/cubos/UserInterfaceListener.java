package ru.cubos;

import java.awt.event.KeyEvent;

public interface UserInterfaceListener {
    public void keyTyped(KeyEvent keyEvent);
    public void keyPressed(KeyEvent keyEvent);
    public void keyReleased(KeyEvent keyEvent);
}
