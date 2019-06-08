import javax.swing.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import com.google.zxing.BarcodeFormat;
import com.google.zxing.WriterException;
import com.google.zxing.client.j2se.MatrixToImageWriter;
import com.google.zxing.common.BitMatrix;
import com.google.zxing.qrcode.QRCodeWriter;
import java.awt.Component;
import java.awt.image.BufferedImage;
import java.io.FileInputStream;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Scanner;
import javax.imageio.ImageIO;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chama
 */
public class inputText extends javax.swing.JFrame {

    /**
     * Creates new form inputText
     */
    public inputText() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        enterTextLabel = new javax.swing.JLabel();
        enterTextField = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();
        cancelBtn = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("INPUT FORM");

        enterTextLabel.setText("ENTER TEXT");

        enterTextField.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                enterTextFieldKeyReleased(evt);
            }
        });

        jButton1.setText("OK");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        cancelBtn.setText("Cancel");
        cancelBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelBtnActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(139, 139, 139)
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 112, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(38, 38, 38)
                        .addComponent(enterTextLabel)
                        .addGap(61, 61, 61)
                        .addComponent(enterTextField, javax.swing.GroupLayout.PREFERRED_SIZE, 143, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(95, 95, 95)
                        .addComponent(jButton1)
                        .addGap(52, 52, 52)
                        .addComponent(cancelBtn)))
                .addContainerGap(99, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(25, 25, 25)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(enterTextLabel)
                    .addComponent(enterTextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(66, 66, 66)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(cancelBtn))
                .addContainerGap(118, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    QRCodeGenerator QRObj;
    
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        boolean [] sign = {true};
        Thread t = new Thread(new Runnable() {
               public void run() {
                try {
                    Scanner scanner = new Scanner(new File("./a.txt"));
                    int fileNo = scanner.nextInt();
                    System.out.println("haha " + fileNo);

                    Writer wr = new FileWriter("./a.txt");
                    wr.write(new Integer(fileNo + 1).toString());
                    wr.close();

                    String text = enterTextField.getText();
                    text = new Encrypt().encryptText(text, fileNo);
                    if(text == "") return;
                    QRObj = new QRCodeGenerator();
                    try {
                        
                        QRObj.generateQRCodeImage(text, 350, 350, fileNo);

                        //IMAGE CONVERSION TO BUFFER
                        FileInputStream fis = new FileInputStream ("qrcodes/MyQRCode" + fileNo + ".png");
                        byte[] buffer = new byte[fis.available()];
                        fis.read(buffer);

                        itemSend tr = new itemSend(buffer, fileNo, sign, false);
                        Sender client = new Sender();       //*****Sending object through client
                        client.communicate(tr);

                        JFrame frame = new JFrame("YOUR IMAGE");
                        BufferedImage img = ImageIO.read(new File("./qrcodes/MyQRCode" + fileNo + ".png"));
                        ImageIcon icon = new ImageIcon(img);
                        JLabel labelObj = new JLabel(icon);
                        frame.add(labelObj);
                        frame.pack();
                        frame.setVisible(true);

                    }
                    catch (WriterException e) {
                        System.out.println("Could not generate QR Code, WriterException :: " + e.getMessage());
                    }
                    catch (IOException e) {
                        System.out.println("Could not generate QR Code, IOException :: " + e.getMessage());
                    }
               }
                catch (FileNotFoundException ex) {
                    Logger.getLogger(inputText.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    Logger.getLogger(inputText.class.getName()).log(Level.SEVERE, null, ex);
                } catch (Exception ex) {
                    Logger.getLogger(inputText.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
            
        t.start();
        
    }//GEN-LAST:event_jButton1ActionPerformed

    private void enterTextFieldKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_enterTextFieldKeyReleased
        boolean [] sign = {true};
        Thread t = new Thread(new Runnable() {
               public void run() {
                try {
                    Scanner scanner = new Scanner(new File("./a.txt"));
                    int fileNo = scanner.nextInt();
//                    System.out.println("haha " + fileNo);

                    String text = enterTextField.getText();
                    text = new Encrypt().encryptText(text, fileNo);
                    QRObj = new QRCodeGenerator();
                    try {
                        QRObj.generateQRCodeImage(text, 350, 350, fileNo);

                        //IMAGE CONVERSION TO BUFFER
                        FileInputStream fis = new FileInputStream ("qrcodes/MyQRCode" + fileNo + ".png");
                        byte[] buffer = new byte[fis.available()];
                        fis.read(buffer);

                        itemSend tr = new itemSend(buffer, fileNo, sign, false);
                        Sender client = new Sender();
                        client.communicate(tr);

                    }
                    catch (WriterException e) {
                        System.out.println("Could not generate QR Code, WriterException :: " + e.getMessage());
                    }
                    catch (IOException e) {
                        System.out.println("Could not generate QR Code, IOException :: " + e.getMessage());
                    }
               }
                catch (FileNotFoundException ex) {
                    Logger.getLogger(inputText.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    Logger.getLogger(inputText.class.getName()).log(Level.SEVERE, null, ex);
                } catch (Exception ex) {
                    Logger.getLogger(inputText.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
            
        t.start();
        
    }//GEN-LAST:event_enterTextFieldKeyReleased

    private void cancelBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelBtnActionPerformed
        this.dispose();
        new chooseOptionsFrame().setVisible(true);
    }//GEN-LAST:event_cancelBtnActionPerformed

    /**
     * @param args the command line arguments
     */
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton cancelBtn;
    private javax.swing.JTextField enterTextField;
    private javax.swing.JLabel enterTextLabel;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    // End of variables declaration//GEN-END:variables

    /**
     *
     */
    //@Override
    //public void run() {
     //   throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    //}
}
