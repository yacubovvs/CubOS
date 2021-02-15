package ru.cubos;

import ru.cubos.emulator.Emulator;
import ru.cubos.server.SocketServer;

import java.awt.*;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        //emulator.drawLine(5,5,50,50, new Color(255,255,255));

        SocketServer socketServer = new SocketServer(9100, 240, 240);
        socketServer.start();

    }
}
