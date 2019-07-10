//0x20 address I2C 1 (1-16)
//0x27 address I2C 2 (17-32)

#include "Wire.h"

//I2C1
String   binPA1    ="";
uint8_t BinPA1[8] ={};
uint8_t decA1[8]  ={};
uint8_t sumdecA1  =0;

String   binPB1    ="";
uint8_t BinPB1[8] ={};
uint8_t decB1[8]  ={};
uint8_t sumdecB1  =0;

//I2C2
String   binPA2    ="";
uint8_t BinPA2[8] ={};
uint8_t decA2[8]  ={};
uint8_t sumdecA2  =0;

String   binPB2    ="";
uint8_t BinPB2[8] ={};
uint8_t decB2[8]  ={};
uint8_t sumdecB2  =0;

String   Bit         ="";
uint8_t  i          =0;

void setup()
{
 Serial.begin(9600);
 Wire.begin(); // wake up I2C bus

 //I2C1
 // set I/O pins to outputs
 Wire.beginTransmission(0x20);
 Wire.write(0x00); // IODIRA register
 Wire.write(0x00); // set all of port A to outputs
 Wire.endTransmission();

 Wire.beginTransmission(0x20);
 Wire.write(0x01); // IODIRB register
 Wire.write(0x00); // set all of port B to outputs
 Wire.endTransmission();

 //I2C2
 // set I/O pins to outputs
 Wire.beginTransmission(0x27);
 Wire.write(0x00); // IODIRA register
 Wire.write(0x00); // set all of port A to outputs
 Wire.endTransmission();

 Wire.beginTransmission(0x27);
 Wire.write(0x01); // IODIRB register
 Wire.write(0x00); // set all of port B to outputs
 Wire.endTransmission();
}

void loop() {
  bintodec("00000000000000000000000000000000");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);
  
  bintodec("11111111111111111111111111111111");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000); 
  
  bintodec("11111111111111110000000000000000");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);
  
  bintodec("00000000000000001111111111111111");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);  
  
  bintodec("11111111000000001111111100000000");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);

  bintodec("00000000111111110000000011111111");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);

  bintodec("11111111000000000000000011111111");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);
    
  bintodec("00000000111111111111111100000000");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);

  bintodec("11110000111100001111000011110000");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);

  bintodec("00001111000011110000111100001111");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);
      
  bintodec("11001100110011001100110011001100");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);  

  bintodec("00110011001100110011001100110011");
  Turn(sumdecA1,sumdecB1,sumdecA2,sumdecB2);
  delay(5000);    
}

void Turn(uint8_t VA1, uint8_t VB1, uint8_t VA2, uint8_t VB2){
  //I2C1
  Wire.beginTransmission(0x20);
  Wire.write(0x12); // GPIOA
  Wire.write(VA1); // port A
  Wire.endTransmission();  
   
  Wire.beginTransmission(0x20);
  Wire.write(0x13); // GPIOA
  Wire.write(VB1); // port B
  Wire.endTransmission();  

   //I2C2
  Wire.beginTransmission(0x27);
  Wire.write(0x12); // GPIOA
  Wire.write(VA2); // port A
  Wire.endTransmission();  

  Wire.beginTransmission(0x27);
  Wire.write(0x13); // GPIOA
  Wire.write(VB2); // port A
  Wire.endTransmission();
}


void bintodec(String binAll){
  sumdecA1=0;
  sumdecA2=0;
  
  sumdecB1=0;
  sumdecB2=0;
   
  String bin1="";
  String bin2="";
  
  if (binAll.length()==32) {   
    bin1=binAll.substring(0,16);
    Serial.print("bin1:");Serial.println(bin1);
    //Serial.println();
    
    bin2=binAll.substring(16,32);
    Serial.print("bin2:");Serial.println(bin2);
    //Serial.println();    
    
    //I2C1
    if (bin1.length()==16){
      //portA
      binPA1 = bin1.substring(0,8);
      Serial.print("binPA1:");Serial.println(binPA1);
      
      for (i=0; i<8; i++) {
        Bit = binPA1.substring(i,i+1);  
//        Serial.print("Bit ");
//        Serial.print(i);
//        Serial.print(":");
//        Serial.print(Bit);
//        Serial.print("\t\t");
            
        BinPA1[i]=Bit.toInt();
//        Serial.print("BinPA1 ");
//        Serial.print(i);
//        Serial.print(" :");
//        Serial.print(BinPA1[i]);
//        Serial.println();    
      }
      
      decA1[0]= (BinPA1[0])*(pow(2,0));
      decA1[1]= (BinPA1[1])*(pow(2,1)); 
      decA1[2]= (BinPA1[2])*(pow(2,2));
      decA1[3]= (BinPA1[3])*(pow(2,3));       
      decA1[4]= (BinPA1[4])*(pow(2,4));
      decA1[5]= (BinPA1[5])*(pow(2,5)); 
      decA1[6]= (BinPA1[6])*(pow(2,6));
      decA1[7]= (BinPA1[7])*(pow(2,7)); 
      sumdecA1 = (decA1[0]+decA1[1]+decA1[2]+decA1[3]+decA1[4]+decA1[5]+decA1[6]+decA1[7]);
      Serial.print("sumdecA1:");
      Serial.print(sumdecA1);
      Serial.println();
      
      
      //portB
      binPB1 = bin1.substring(8,16);
      Serial.print("binPB1:");Serial.println(binPB1);
       for (i=0; i<8; i++) {
        Bit = binPB1.substring(i,i+1);
//        Serial.print("Bit ");
//        Serial.print(i);
//        Serial.print(":");
//        Serial.print(Bit);
//        Serial.print("\t\t");
                     
        BinPB1[i]=Bit.toInt();
//        Serial.print("binPB1 ");
//        Serial.print(i);
//        Serial.print(" :");
//        Serial.print(binPB1[i]);
//        Serial.println();    
      }       
       
      decB1[0]= (BinPB1[0])*(pow(2,0));
      decB1[1]= (BinPB1[1])*(pow(2,1)); 
      decB1[2]= (BinPB1[2])*(pow(2,2));
      decB1[3]= (BinPB1[3])*(pow(2,3));       
      decB1[4]= (BinPB1[4])*(pow(2,4));
      decB1[5]= (BinPB1[5])*(pow(2,5)); 
      decB1[6]= (BinPB1[6])*(pow(2,6));
      decB1[7]= (BinPB1[7])*(pow(2,7)); 
      sumdecB1 = (decB1[0]+decB1[1]+decB1[2]+decB1[3]+decB1[4]+decB1[5]+decB1[6]+decB1[7]);
      Serial.print("sumdecB1:");
      Serial.print(sumdecB1);
      Serial.println();     
    }
  
    //I2C2    
    if (bin2.length()==16){
      //portA
      binPA2 = bin2.substring(0,8);
      Serial.print("binPA2:");Serial.println(binPA2);
      
      for (i=0; i<8; i++) {
        Bit = binPA2.substring(i,i+1);  
//        Serial.print("Bit ");
//        Serial.print(i);
//        Serial.print(":");
//        Serial.print(Bit);
//        Serial.print("\t\t");
            
        BinPA2[i]=Bit.toInt();
//        Serial.print("BinPA1 ");
//        Serial.print(i);
//        Serial.print(" :");
//        Serial.print(BinPA1[i]);
//        Serial.println();    
      }  
      decA2[0]= (BinPA2[0])*(pow(2,0));
      decA2[1]= (BinPA2[1])*(pow(2,1)); 
      decA2[2]= (BinPA2[2])*(pow(2,2));
      decA2[3]= (BinPA2[3])*(pow(2,3));    
      decA2[4]= (BinPA2[4])*(pow(2,4));
      decA2[5]= (BinPA2[5])*(pow(2,5)); 
      decA2[6]= (BinPA2[6])*(pow(2,6));
      decA2[7]= (BinPA2[7])*(pow(2,7)); 
      sumdecA2 = (decA2[0]+decA2[1]+decA2[2]+decA2[3]+decA2[4]+decA2[5]+decA2[6]+decA2[7]);
      Serial.print("sumdecA2:");
      Serial.print(sumdecA2);
      Serial.println();

      //portB
      binPB2 = bin2.substring(8,16);
      Serial.print("binPB2:");Serial.println(binPB2);
       for (i=0; i<8; i++) {
        Bit = binPB2.substring(i,i+1);
//        Serial.print("Bit ");
//        Serial.print(i);
//        Serial.print(":");
//        Serial.print(Bit);
//        Serial.print("\t\t");
                     
        BinPB2[i]=Bit.toInt();
//        Serial.print("binPB1 ");
//        Serial.print(i);
//        Serial.print(" :");
//        Serial.print(binPB1[i]);
//        Serial.println();    
      }             
      decB2[0]= (BinPB2[0])*(pow(2,0));
      decB2[1]= (BinPB2[1])*(pow(2,1)); 
      decB2[2]= (BinPB2[2])*(pow(2,2));
      decB2[3]= (BinPB2[3])*(pow(2,3));
      decB2[4]= (BinPB2[4])*(pow(2,4));
      decB2[5]= (BinPB2[5])*(pow(2,5)); 
      decB2[6]= (BinPB2[6])*(pow(2,6));
      decB2[7]= (BinPB2[7])*(pow(2,7)); 
      sumdecB2 = (decB2[0]+decB2[1]+decB2[2]+decB2[3]+decB2[4]+decB2[5]+decB2[6]+decB2[7]);
      Serial.print("sumdecB2:");
      Serial.print(sumdecB2);
      Serial.println();                         
    }   
  }

  Serial.println();
}
