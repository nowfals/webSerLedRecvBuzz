/* 
This is an Xbee test sketch using a switch

This is for the receiving xbee

DigitalPin 8 has an LED

When the switch is turned on it broadcasts that to the other xbee
*/

#define LED 4 //the pin with the LED
#define RELAY1 5
#define speakerPin 9

byte val = 0;  //what is the other xbee saying
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup () {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
        pinMode(RELAY1, OUTPUT);   
      pinMode(speakerPin, OUTPUT);    
}


void beep(unsigned char delayms){
  analogWrite(9, 90);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
}  


void loop(){
  //delay(500);
  if (Serial.available()){
    val = Serial.read(); //What is the other xbee saying
   
    if (val == 'X'){
      digitalWrite(LED, HIGH);//turn on the LED
      digitalWrite(RELAY1, LOW);// // Turns ON Relays 1
      beep(1000);
      delay(2000);
      digitalWrite(LED, LOW);
        
       /*paly music*/
   
   /*
        for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    //turn on the LED
    // pause between notes
   // delay(tempo / 2); 
  }
  
  */
    }
   if (val == 'S'){
    //  digitalWrite(LED, HIGH);//turn on the LED
    //  digitalWrite(RELAY1, LOW);// // Turns ON Relays 1
      beep(10);
      delay(2000);
    //  digitalWrite(LED, LOW);
        
       /*paly music*/
   
     // Serial.print(val);
    }
    
    if (val == 'O') {
      digitalWrite(LED,LOW);
      digitalWrite(RELAY1, HIGH);// // Turns OFF Relays 1
     //  playNote(notes[0], beats[0] * 0);
      //  digitalWrite(RELAY1, HIGH);// // Turns OFF Relays 1
     // Serial.print(val);
    }
    
    
 
    
  }
}
