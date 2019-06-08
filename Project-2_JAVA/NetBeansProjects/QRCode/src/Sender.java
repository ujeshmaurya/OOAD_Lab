/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chaman
 */
import java.io.*;
import java.net.Socket;
import java.net.SocketException;


public class Sender {
    private Socket socket = null;
    private ObjectInputStream inputStream = null;
    private ObjectOutputStream outputStream = null;
    private boolean isConnected = false;
    public Sender() {
       
    }
    
    public void communicate(itemSend obj) {
        while (!isConnected) {
            try {
                socket = new Socket("localhost", 4445);
                System.out.println("Connected");
                isConnected = true;
                
                DataOutputStream os = new DataOutputStream(socket.getOutputStream());
                
                outputStream = new ObjectOutputStream(socket.getOutputStream());
                System.out.println("Object to be written = " + obj);
                outputStream.writeObject(obj);
            } 
            catch (SocketException se) {
                se.printStackTrace();
            } 
            catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
