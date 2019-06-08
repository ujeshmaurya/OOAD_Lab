/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chama
 */

import java.awt.image.BufferedImage;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.crypto.SecretKey;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class Receiver implements Runnable{
    private ServerSocket serverSocket = null;
    private Socket socket = null;
    private ObjectInputStream inStream = null;
    private QRImageFrame QRFrameObj = null;
public Receiver() throws Exception {
        serverSocket = new ServerSocket(4445);
}

public void setQRImageFrame(QRImageFrame obj) {
    QRFrameObj = obj;
}

public QRImageFrame getQRImageFrame() {
    return QRFrameObj;
}

public void run() {
    
}

public boolean flag = false;

public void communicate() throws ClassNotFoundException, Exception {
    Receiver rc = this;
    try {
            while(true) {
                socket = serverSocket.accept();
                System.out.println("Connected");
                
                if(QRFrameObj != null) {
                    QRFrameObj.setVisible(false);
                    QRFrameObj = null;
                } 
                
//                QRFrameObj = null;
                
//                QRFrameObj = new QRImageFrame(null, "", rc);
                inStream = new ObjectInputStream(socket.getInputStream());
                itemSend receivedObj = (itemSend) inStream.readObject();
                System.out.println("Object received = " + receivedObj + "\n");
                byte[] buff = receivedObj.getImageByte();
                DataInputStream dis = new DataInputStream(socket.getInputStream());
                FileOutputStream fout = new FileOutputStream("./qrcodes/MyQRCode" + receivedObj.getId() + ".png");
                fout.write(buff);
                QRCodeSimplifier QRObj2 = new QRCodeSimplifier();
                String fT = QRObj2.getQRText(receivedObj.getId());
                fT = new Encrypt().decryptText(fT, receivedObj.getId());
                final String finalText = fT;
                byte[] b = new byte[finalText.length()];
                boolean[] sign = receivedObj.getSign();
                if(receivedObj.isImage()) {    
                    for (int i = 0; i < finalText.length(); i++) {
                        //System.out.println(finalText.charAt(i));
                        int bt = (int) finalText.charAt(i);
                        if (sign[i] == true) bt = - bt;
                        b[i] = (byte)bt;
                    }
                }
                fout.close();
                dis.close();
                socket.close();
                if(!receivedObj.isImage())
                    System.out.println("FINAL TEXT IS: " + finalText);
                new Thread(new Runnable() {
                    public void run() {
                        try {
                            if(receivedObj.isImage()) {
                                new QRImageFrame(receivedObj, "", rc).setVisible(true);
                            }
                            else {
                                new QRImageFrame(receivedObj, finalText, rc).setVisible(true);
                            }
                        } catch (Exception e) {
                            System.out.println(e.getMessage());
                        }
                    }
                }).start();
                if(receivedObj.isImage()) {
                    try {
                        File file = new File("receivedImg/", "Image" + receivedObj.getId() + ".png");
                        file.createNewFile();
                        FileOutputStream fos = new FileOutputStream(file);

                        System.out.println(finalText);
                        fos.write(b);
                        fos.close();
                    } catch (IOException ex) {
                        Logger.getLogger(Receiver.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
//                System.out.println("haha");
            }
            
    } 
    catch (SocketException se) {
        System.exit(0);
    } catch (IOException e) {
        e.printStackTrace();
    }
}

}
