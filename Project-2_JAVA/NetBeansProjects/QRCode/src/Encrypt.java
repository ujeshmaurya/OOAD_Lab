/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Admin
 */

import java.io.*;

public class Encrypt{
  byte[] encryptedText;
  public Encrypt() throws Exception {
      
  }
  public String encryptText(String text, int k) throws Exception {
//      k = 9;
      String returnText = "";
      for (int i = 0; i < text.length(); i++) {
          char c = text.charAt(i);
          if (c >= 65 && c <= 90) {
            c = (char)((c - 65 + k)%26 + 65);
          }
          else if (c >= 97 && c<= 122){
            c = (char)((c - 97 + k)%26 + 97);  
          }
//          char c = (char) ((int)text.charAt(i) + k);
          returnText = returnText + c;
      }
      return returnText;
  }
  
  public String decryptText(String text, int k) throws Exception{
      String returnText = "";
      for (int i = 0; i < text.length(); i++) {
          char c = text.charAt(i);
          if (c >= 65 && c <= 90) {
            c = (char)((c - 65 - k + 2600)%26 + 65);
          }
          else if (c >= 97 && c<= 122){
            c = (char)((c - 97 - k + 2600)%26 + 97);  
          }
          returnText = returnText + c;
      }
      return returnText;
  }
  
}

