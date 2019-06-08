/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chaman
 */

import java.awt.image.BufferedImage;
import java.io.*;

import javax.imageio.ImageIO;

import com.google.zxing.BinaryBitmap;
import com.google.zxing.ChecksumException;
import com.google.zxing.FormatException;
import com.google.zxing.NotFoundException;
import com.google.zxing.Result;
import com.google.zxing.client.j2se.BufferedImageLuminanceSource;
import com.google.zxing.common.HybridBinarizer;
import com.google.zxing.qrcode.QRCodeReader;

public class QRCodeSimplifier {
    
    public String getQRText(int id) {
        
        // You can change Image Path accordingly.
        String imagePath = "qrcodes/MyQRCode" + id + ".png";
        // Defining File Object using Path
        File file = new File(imagePath);
        try {
            // Defining BufferedImage Object using Image File
            BufferedImage bufferedImage = ImageIO.read(file);

            // Defining BufferedImageLuminanceSource using BufferedImage Object
            BufferedImageLuminanceSource source = new BufferedImageLuminanceSource(bufferedImage);

            // Defining HybridBinarizer using BufferedImageLuminanceSource Object
            HybridBinarizer hybridBinarizer = new HybridBinarizer(source);

            // Defining BinaryBitmap using HybridBinarizer
            BinaryBitmap binaryBitmap = new BinaryBitmap(hybridBinarizer);

            // Defining QRCodeReader Object
            QRCodeReader qrCodeReader = new QRCodeReader();

            // Decoding Text from QR Code Image
            Result result = qrCodeReader.decode(binaryBitmap);

            // Getting the Text from Result Object
            String decodedText = result.getText();

            // Printing the Text
            //System.out.println("The decoded String value is : "+decodedText);
            return decodedText;
        } catch (IOException e) {

                System.out.println(e.getMessage());
                e.printStackTrace();
        } catch (NotFoundException e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
        } catch (ChecksumException e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
        } catch (FormatException e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
        }
        return null;
    }
    
    public String getQRText(String imagePath) {
        File file = new File(imagePath);
        try {
            // Defining BufferedImage Object using Image File
            BufferedImage bufferedImage = ImageIO.read(file);

            // Defining BufferedImageLuminanceSource using BufferedImage Object
            BufferedImageLuminanceSource source = new BufferedImageLuminanceSource(bufferedImage);

            // Defining HybridBinarizer using BufferedImageLuminanceSource Object
            HybridBinarizer hybridBinarizer = new HybridBinarizer(source);

            // Defining BinaryBitmap using HybridBinarizer
            BinaryBitmap binaryBitmap = new BinaryBitmap(hybridBinarizer);

            // Defining QRCodeReader Object
            QRCodeReader qrCodeReader = new QRCodeReader();

            // Decoding Text from QR Code Image
            Result result = qrCodeReader.decode(binaryBitmap);

            // Getting the Text from Result Object
            String decodedText = result.getText();

            // Printing the Text
            //System.out.println("The decoded String value is : "+decodedText);
            return decodedText;
        } catch (IOException e) {

                System.out.println(e.getMessage());
                e.printStackTrace();
        } catch (NotFoundException e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
        } catch (ChecksumException e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
        } catch (FormatException e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
        }
        return null;
    }
    
    
}
