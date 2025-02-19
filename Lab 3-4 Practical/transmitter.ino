/**
 * author : Syeed Mohd. Ameen                                                                           Dated: 19-02-2025
 * Email  : syeedmohdameen@zhcet.ac.in 
 * webpage : https://syeedameen.github.io/
 */

// Transmit rate in bps
#define TX_RATE 5

// Pin assignments
#define TX_CLOCK 2
#define TX_DATA 3

const char *message = "Hello, world!";

void setup() {

    // open serial terminal at 9600 baud rate. 
    Serial.begin(9600);             
    pinMode(TX_CLOCK, OUTPUT);
    pinMode(TX_DATA, OUTPUT);


  for (int byte_idx = 0; byte_idx < strlen(message); byte_idx++) {
    char tx_byte = message[byte_idx];

    for (int bit_idx = 0; bit_idx < 8; bit_idx++) {
      bool tx_bit = tx_byte & (0x80 >> bit_idx);

      digitalWrite(TX_DATA, tx_bit);
      delay((1000 / TX_RATE) / 2);

      // Pulse clock
      digitalWrite(TX_CLOCK, HIGH);
      delay((1000 / TX_RATE) / 2);
      digitalWrite(TX_CLOCK, LOW);      
    }
  }
  digitalWrite(TX_DATA, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}