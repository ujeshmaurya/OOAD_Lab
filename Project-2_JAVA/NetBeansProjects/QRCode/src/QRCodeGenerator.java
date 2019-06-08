/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chama
 */

import com.google.zxing.BarcodeFormat;
import com.google.zxing.WriterException;
import com.google.zxing.client.j2se.MatrixToImageWriter;
import com.google.zxing.common.BitMatrix;
import com.google.zxing.qrcode.QRCodeWriter;

import java.io.*;
import java.nio.file.FileSystems;
import java.nio.file.Path;



public class QRCodeGenerator {
    
    //private final String QR_CODE_IMAGE_PATH = "./qrcodes/MyQRCode.png";

    public void generateQRCodeImage(String text, int width, int height, int fileNo)
            throws WriterException, IOException {
        QRCodeWriter qrCodeWriter = new QRCodeWriter();
        BitMatrix bitMatrix = qrCodeWriter.encode(text, BarcodeFormat.QR_CODE, width, height);

        Path path = FileSystems.getDefault().getPath("./qrcodes/MyQRCode" + fileNo + ".png");
        MatrixToImageWriter.writeToPath(bitMatrix, "PNG", path);
    }
    
}
