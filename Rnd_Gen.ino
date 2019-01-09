
const int led0 = 11;
const int led1 = 10;
const int led2 = 9;
const int led3 = 8;
const int ledGreen = 7;

const int button = 2;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 Serial.begin(9600);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  setLow();
}

int rnd = 0;

int bli_cnt = 0;
boolean bli = false;

void loop() {
  if(digitalRead(button) == false){
    rnd = (int)random(16);
    bli_cnt = rnd+rnd;
    bli = false;
    digitalWrite(ledGreen,bli);
  }
  digitalWrite(led0,(rnd & 0x1));
  digitalWrite(led1,(rnd & 0x2));
  digitalWrite(led2,(rnd & 0x4));
  digitalWrite(led3,(rnd & 0x8));
  
  Serial.println("Random");
  Serial.println(rnd);

  if(bli_cnt > 0){
    bli_cnt--;
    bli = !bli;
    digitalWrite(ledGreen,bli);
  }
  
  delay(100);
}


void setLow(){
  digitalWrite(led0,false);
  digitalWrite(led1,false);
  digitalWrite(led2,false);
  digitalWrite(led3,false);
  digitalWrite(ledGreen,false);
}





