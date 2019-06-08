/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chama
 */
import java.io.Serializable;

public class itemSend implements Serializable{
    byte[] buff;
    int id;
    boolean imageBool;
    boolean [] sign;
    public itemSend(byte[] buff, int fileNo, boolean [] sArr, boolean flag) {
        this.buff = buff;
        id = fileNo;
        imageBool = flag;
        sign = sArr;
    }
    public byte[] getImageByte() {
        return buff;
    }
    public int getId(){
        return id;
    }
    public boolean isImage() {
        return imageBool;
    }
    public boolean [] getSign() {
        return sign;
    }
}
