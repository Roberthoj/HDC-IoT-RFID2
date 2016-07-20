#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53 //modificable segun el tipo de arduino que tengan
#define RST_PIN 49 //modificable segun el tipo de arduino que tengan


MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

void setup() {
	Serial.begin(9600); //Iniciamos la comunicación  serial
	SPI.begin();        //Iniciamos el Bus SPI
	mfrc522.PCD_Init(); // Iniciamos  el MFRC522
	Serial.println("Lectura del UID");
}

void loop() {
	// Revisamos si hay nuevas tarjetas  presentes
	if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
  		//Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print("Tag UID:");
               
                  for (byte i = 0; i < mfrc522.uid.size; i++) {  //mfrc522.uid.size -> obtiene el tamaño del codigo de identificacion
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); //mfrc522.uid.uidByte -> lee el codigo de identificación
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                        
                  } 
                  Serial.println();
                  // Terminamos la lectura de la tarjeta  actual
                  mfrc522.PICC_HaltA();  
                   
            }      
	}	
}
