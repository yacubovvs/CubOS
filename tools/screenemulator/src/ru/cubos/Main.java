package ru.cubos;

import ru.cubos.emulator.Emulator;
import ru.cubos.server.ReadServer;
import ru.cubos.server.SocketServer;

import java.awt.*;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        //Emulator emulator = new Emulator(240,240);
        //ReadServer readServer = new ReadServer(emulator);

        //SocketServer socketServer = new SocketServer(9100, 240, 240);
        SocketServer socketServer = new SocketServer(9100, 320, 240);
        socketServer.start();

    }
}
