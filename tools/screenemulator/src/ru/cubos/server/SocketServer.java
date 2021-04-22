package ru.cubos.server;

import ru.cubos.emulator.Emulator;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

public class SocketServer extends Emulator {

    private Socket clientSocket; //сокет для общения
    private ServerSocket socketServer; // серверсокет
    private InputStream in; // поток чтения из сокета
    private OutputStream out; // поток записи в сокет
    private int port;
    public List<byte[]> messagesToSend = new ArrayList<>();

    private Reader reader;
    private Writer writer;


    public static int serverBufferSize = 128 * 1024;
    public static int clientBufferSize = serverBufferSize;

    public static int serverBufferSize_max = serverBufferSize;
    public static int clientBufferSize_max = serverBufferSize;

    String keys[] = {"0", "0", "0", "0"};

    public SocketServer(int port, int width, int height){
        super(width, height);
        this.port = port;

        addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent keyEvent) { }

            @Override
            public void keyPressed(KeyEvent keyEvent) {
                //System.out.println("Pressed");
                switch (keyEvent.getKeyCode()){
                    case 37:
                        keys[0] = "1";
                        break;
                    case 32:
                        keys[1] = "1";
                        break;
                    case 39:
                        keys[2] = "1";
                        break;
                    case 38:
                        keys[3] = "1";
                        break;
                }
            }

            @Override
            public void keyReleased(KeyEvent keyEvent) {
                //System.out.println("Released");
                switch (keyEvent.getKeyCode()){
                    case 37:
                        keys[0] = "0";
                        break;
                    case 32:
                        keys[1] = "0";
                        break;
                    case 39:
                        keys[2] = "0";
                        break;
                    case 38:
                        keys[3] = "0";
                        break;

                }
            }
        });
    }

    public void addMessage(byte[] message){
        messagesToSend.add(message);
        messagesToSend.add("\n".getBytes());

        if(writer==null){
            writer = new Writer();
            writer.start();
        }
    }

    public void addMessage(String message){
        message.trim();
        message += "\n";
        messagesToSend.add(message.getBytes());

        if(writer==null){
            writer = new Writer();
            writer.start();
        }
    }

    public void start(){
        //while (true) {
        try {
            try {
                //socketServer = new java.net.ServerSocket(port);
                socketServer = new ServerSocket();
                socketServer.setReceiveBufferSize(serverBufferSize_max);
                socketServer.bind(new InetSocketAddress( (InetAddress) null, port));
                System.out.println("Socket server started at port " + port);

                clientSocket = socketServer.accept();

                try {
                    String dataString = "";

                    in = clientSocket.getInputStream();
                    out = clientSocket.getOutputStream();

                    reader = new Reader();
                    writer = new Writer();

                    reader.start();
                    writer.start();
                } catch (Exception e) {
                    System.out.println("Server error #1");
                } finally {
                    //clientSocket.close();
                    //in.close();
                    //out.close();
                }
            } catch (Exception e) {

                System.out.println("Server error #2");
            } finally {
                System.out.println("Server closed!");
                if(socketServer!=null)socketServer.close();

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                this.start();
            }
        } catch (IOException e) {
            System.err.println(e);
        }

        //}
    }

    String totalIncomeMessage = "";
    private class Reader extends Thread {
        @Override
        public void run() {
            int count;
            //unsigned char bytes[] = new unsigned char[16 * 1024 * 1024];
            byte bytes[] = new byte[serverBufferSize];

            try {
                while ((count = in.read(bytes)) > 0) {
                    //System.out.println("Read server: " + bytes.toString());
                    String inString = (new String(bytes, StandardCharsets.UTF_8)).substring(0, count);
                    totalIncomeMessage += inString;
                    //System.out.println("Read server: " + inString);
                    executeCommands();
                }
            } catch (IOException e) {
                e.printStackTrace();
                //return;
            }

            executeCommands();

        }

        void executeCommands(){
            while(totalIncomeMessage.indexOf('\n')!=-1){
                int stringPosition = totalIncomeMessage.indexOf('\n');
                String parseMessage = totalIncomeMessage.substring(0, stringPosition);
                //System.out.println("Parse message: " + parseMessage);
                decodeString(parseMessage);
                totalIncomeMessage = totalIncomeMessage.substring(stringPosition + 1, totalIncomeMessage.length());
            }
        }
    }


    public void write(String string){
        addMessage(string);
    }

    public class Writer extends Thread {
        @Override
        public void run() {
            while (messagesToSend.size()>0) {

                if(out==null){
                    try {
                        Thread.sleep(200);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    continue;
                }

                try {
                    byte data[] = messagesToSend.get(0);
                    out.write(data);
                    out.flush();
                    messagesToSend.remove(data);
                } catch (IOException e) {}

            }

            writer = null;
        }
    }



    String decoderMessage;
    Color currentColor = new Color(0,0,0);

    void decodeString(String message){
        String[] messages = message.split(" ");
        int x, y, w, h, r, g, b;

        switch(messages[0].trim()){
            case "P":   // Pixel
                try{
                    x = Integer.parseInt(messages[1]);
                    y = Integer.parseInt(messages[2]);
                    this.drawPixel(x,y, currentColor);
                }catch (Exception e){}
                break;
            case "LH":      // Fast line hotizontal
                try{
                    x = Integer.parseInt(messages[1]);
                    y = Integer.parseInt(messages[2]);
                    w = Integer.parseInt(messages[3]);
                    this.drawLine(x,y,x+w,y, currentColor);
                }catch (Exception e){}
                break;
            case "LV":      // Fast line vertical
                try{
                    x = Integer.parseInt(messages[1]);
                    y = Integer.parseInt(messages[2]);
                    h = Integer.parseInt(messages[3]);
                    this.drawLine(x,y,x,y+h, currentColor);
                }catch (Exception e){}
                break;
            case "T":       // READ TOUCHES
                addMessage(isTouched + touchX + touchY);
                break;
            case "R":       // Rectangle
                try{
                    x = Integer.parseInt(messages[1]);
                    y = Integer.parseInt(messages[2]);
                    w = Integer.parseInt(messages[3]);
                    h = Integer.parseInt(messages[4]);
                    this.drawRect(x, y,x+w,y+h, currentColor);
                }catch (Exception e){}
                break;
            case "F":       // Fill
                this.drawRect(0, 0, this.getWidth(),this.getHeight(), currentColor);
                break;
            case "U":       // Update
                this.updateImage();
                break;
            case "K":       // Read keys
                addMessage(keys[0] + keys[1] + keys[2] + keys[3]);
                /*
                if(n==2){
                    System.out.println("1 0 0 0");
                    addMessage("1000");
                    n = 0;
                }else{
                    System.out.println("0 0 0 0");
                    addMessage("0000");
                }
                n++;*/
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

    }


    String readCommand(){
        int position = decoderMessage.indexOf(' ');
        if (position==-1) position = decoderMessage.length();

        String command = decoderMessage.substring(0,position);
        if(position+1<decoderMessage.length()) decoderMessage = decoderMessage.substring(position+1, decoderMessage.length());
        return command;
    }

    int readInt(){
        int position = decoderMessage.indexOf(' ');
        if (position==-1) position = decoderMessage.length();

        int parametr;
        try {
            parametr = Integer.parseInt(decoderMessage.substring(0, position));
        }catch (Exception e){
            return 0;
        }
        if(position+1<decoderMessage.length()) decoderMessage = decoderMessage.substring(position+1, decoderMessage.length());
        return parametr;
    }

    long readLong(){
        int position = decoderMessage.indexOf(' ');
        if (position==-1) position = decoderMessage.length();

        long parametr;
        try {
            parametr = Long.parseLong(decoderMessage.substring(0, position));
        }catch (Exception e){
            return 0;
        }
        if(position+1<decoderMessage.length()) decoderMessage = decoderMessage.substring(position+1, decoderMessage.length());
        return parametr;
    }
}

