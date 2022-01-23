int IRSensorL = 2;
int IRSensorR = 3;
int LED = 13;

int mot1F = 9;
int mot1B = 8;
int mot1E = 10;
int mot2F = 7;
int mot2B = 6;
int mot2E = 5;

void forward(){               //fucntion to move forwards
   digitalWrite(mot1F,HIGH);
   digitalWrite(mot1B,LOW);
   digitalWrite(mot2F,HIGH);
   digitalWrite(mot2B,LOW);
  }
void backward(){             //fucntion to move backwards
  digitalWrite(mot1F,LOW);
  digitalWrite(mot1B,HIGH);
  digitalWrite(mot2F,LOW);
  digitalWrite(mot2B,HIGH);
  }
void turn(String direction){ //function to turn right or left
  if(direction == "right"){
    digitalWrite(mot1F,HIGH);
    digitalWrite(mot1B,LOW);
    digitalWrite(mot2F,LOW);
    digitalWrite(mot2B,HIGH);
  }
  if(direction == "left"){
    digitalWrite(mot1F,HIGH);
    digitalWrite(mot1B,LOW);
    digitalWrite(mot2F,LOW);  
    digitalWrite(mot2B,HIGH);
  }
}
void halt(){
  digitalWrite(mot1F,LOW);
  digitalWrite(mot1B,LOW);
  digitalWrite(mot2F,LOW);
  digitalWrite(mot2B,LOW);
}

void setup(){

  Serial.begin(9600);
  
  pinMode (IRSensorL, INPUT);
  pinMode (IRSensorR, INPUT);
  pinMode (LED, OUTPUT);
  digitalWrite(mot1E, HIGH);
  digitalWrite(mot2E, HIGH);
}

void loop(){
  int IRoutL = digitalRead(IRSensorL); //Creates a variable that will constantly hold the value of IR sensor ( 1 or 0)
  int IRoutR = digitalRead(IRSensorR); 
  Serial.print(IRoutL);
  Serial.print("     ");
  Serial.println(IRoutR);
   
  if (IRoutL == 1){   //left senses line
    digitalWrite(LED, HIGH);
    turn("left");
    Serial.println("Left");
    delay(100);
  }
  else if (IRoutR == 1){   //right senses line
    digitalWrite(LED, HIGH);
    turn("right");
    Serial.println("Right");
    delay(100);
  }
  
  digitalWrite(LED, LOW);
  forward();                 //continue forward
  delay(100);
}
