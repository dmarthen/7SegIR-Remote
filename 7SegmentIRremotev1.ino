#include <IRremote.h>;
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define c1 48703
#define c2 58359
#define c3 539
#define c4 25979
#define c5 15547
#define c6 59295
#define c7 65015
#define c8 5499
#define c9 64539
#define c0 58747

int pinAtoG[] = {4,7,8,9,10,11,12};
int c1A[] = {2,2,3};
int c2A[] = {5,1,2,7,5,4};
int c3A[] = {5,1,2,7,3,4};
int c4A[] = {4,6,7,2,3};
int c5A[] = {5,1,6,7,3,4};
int c6A[] = {6,1,6,5,4,3,7};
int c7A[] = {3,1,2,3};
int c8A[] = {7,5,4,3,7,6,1,2};
int c9A[] = {6,1,6,7,2,3,4};
int c0A[] = {6,1,6,5,4,3,2};

void ResetPins(){
  for (int i=0; i<7; i++){
    digitalWrite(pinAtoG[i],LOW);
  }
}

void BootUp(){
  ResetPins();
  for (int i=0; i<7; i++){
    digitalWrite(pinAtoG[i],HIGH);
    delay(500);
    digitalWrite(pinAtoG[i],LOW);
  }
  delay(500);
  
}
void setup() {
  Serial.begin(9600);
  Serial.println("Booting up .....");
  BootUp();
  delay(500);
  Serial.println("Booting up completed.");
  Serial.println("Ready to receive signal.");
  Serial.println("Press any key to start ....");
  Serial.println("");
  irrecv.enableIRIn();
  for (int i = 0; i < 7; i++){
    pinMode(pinAtoG[i], OUTPUT);
  }
}

void loop() {
  if(irrecv.decode(&results)){
    unsigned int value = results.value;
    ResetPins();
    if ( value != 65535) {
      Serial.println("");
      Serial.print("You press");
      Serial.print("-->");      
      switch(value) {
        case c1:
          Serial.println("1");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c1A[0]; i++){
            int pinActivated = pinAtoG[c1A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break;   
          
        case c2:
          Serial.println("2");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c2A[0]; i++){
            int pinActivated = pinAtoG[c2A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break;   
          
        case c3:
          Serial.println("3");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c3A[0]; i++){
            int pinActivated = pinAtoG[c3A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break;  
        
        case c4:
          Serial.println("4");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c4A[0]; i++){
            int pinActivated = pinAtoG[c4A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break; 
                
        case c5:
          Serial.println("5");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c5A[0]; i++){
            int pinActivated = pinAtoG[c5A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break; 
        
        case c6:
          Serial.println("6");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c6A[0]; i++){
            int pinActivated = pinAtoG[c6A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break; 
  
        case c7:
          Serial.println("7");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c7A[0]; i++){
            int pinActivated = pinAtoG[c7A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break; 
        
        case c8:
          Serial.println("8");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c8A[0]; i++){
            int pinActivated = pinAtoG[c8A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break; 
        
        case c9:
          Serial.println("9");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c9A[0]; i++){
            int pinActivated = pinAtoG[c9A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break; 
  
        case c0:
          Serial.println("0");
          Serial.println("Activating pins ....");
          for (int i = 1; i <= c0A[0]; i++){
            int pinActivated = pinAtoG[c0A[i]-1];
            Serial.print("-->");
            Serial.print(pinActivated);
            delay(500);
            digitalWrite(pinActivated, HIGH); 
            delay(500);             
          } Serial.println("");Serial.println("Task COMPLETED.");
          break;      
      }
      
    } 
    else {
      ResetPins();
    }
    irrecv.resume();
  }
}
