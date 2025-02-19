/**
 * author : Syeed Mohd. Ameen                                                                           Dated: 19-02-2025
 * Email  : syeedmohdameen@zhcet.ac.in 
 * webpage : https://syeedameen.github.io/
 */


// Pin assignments
#define RX_CLOCK 2
#define RX_DATA 3

char message[16];
volatile byte rx_byte = 0;
volatile int bit_position = 0;
volatile bool update_terminal = true;

void setup() {
    // open serial terminal at 9600 baud rate
    Serial.begin(9600); 
    
    pinMode(RX_DATA, INPUT);
    strcpy(message, "");
    attachInterrupt(digitalPinToInterrupt(RX_CLOCK), onClockPulse, RISING);
}

void onClockPulse() {
  bool rx_bit = digitalRead(RX_DATA);

  if (bit_position == 8) {
    rx_byte = 0;
    bit_position = 0;
  }
  
  if (rx_bit) {
    rx_byte |= (0x80 >> bit_position);
  }

  bit_position += 1;

  if (bit_position == 8) {
    strncat(message, (const char *)&rx_byte, 1);
  }
  
  update_terminal = true;
}

void loop() {
  if (update_terminal) {
    update_terminal = false;
    
    // lcd.noCursor();
    // lcd.setCursor(0, 0);
    // lcd.print(message);
    // lcd.setCursor(0, 1);
    // for (int i = 0; i < 8; i += 1) {
    //   if (i < bit_position) {
    //     lcd.print(rx_byte & (0x80 >> i) ? "1" : "0");
    //   } else {
    //     lcd.print(" ");
    //   }
    // }
    // lcd.setCursor(strlen(message), 0);
    // lcd.cursor();

    /* Print the data on arduino serial terminal program */
    Serial.println(message);
  }
}