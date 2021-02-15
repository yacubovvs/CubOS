package ru.cubos.server;

import ru.cubos.emulator.Emulator;

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

    public SocketServer(int port, int width, int height){
        super(width, height);
        this.port = port;
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
            //byte bytes[] = new byte[16 * 1024 * 1024];
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
    void decodeString(String message){
        decoderMessage = message;
        /*
        String command = readCommang();
        System.out.print("Command found: " + command + " ");

        long parametr1 = readLong();
        int parametr2 = readInt();
        int parametr3 = readInt();
        System.out.print(" parametr1: " + parametr1);
        System.out.print(" parametr2: " + parametr2);
        System.out.println(" parametr3: " + parametr3);
        */

        String command = readCommand();

        switch(command){
            /*
            case _BOARD_RESET:
                reset();
                break;
            case _0_SET_PIN_MODE_INPUT:
                pin = readInt();
                pinMode(pin, INPUT);
                break;
            case _1_SET_PIN_MODE_INPUT_PULLUP:
                pin = readInt();
                pinMode(pin, INPUT_PULLUP);
                break;
            case _2_SET_PIN_MODE_OUTPUT:
                pin = readInt();
                pinMode(pin, OUTPUT);
                break;
            case _3_SET_PIN_INTERRUPT:
                pin = readInt();
                setPinInterrupt(pin);
                break;
            case _4_CLEAR_PIN_INTERRUPT:
                pin = readInt();
                clearPinInterrupt(pin);
                break;
            case _0_DIGITAL_READ:
                pin = readInt();
                write(_0_DIGITAL_READ + " " + pin + " " + (digitalRead(pin) == HIGH ? "1" : "0") + " ");
                break;
            case _1_DIGITAL_WRITE:
                pin = readInt();
                value = readInt();
                digitalWrite(pin, value);
                break;
            case _2_ANALOG_READ:
                pin = readInt();
                value = analogRead(pin);
                write(_2_ANALOG_READ + " " + pin + " " + value + " ");
                break;
            case _3_ANALOG_WRITE:
                pin = readInt();
                value = readInt();
                analogWrite(pin, value);
                break;*/
            default:
                //write(_0_ERROR_UNKNOWN_COMMAND);
                System.out.println(command);
                break;
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

