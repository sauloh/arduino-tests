/*
  Traffic Light
  by Saulo Hachem
*/

int GREEN = 10;
int YELLOW = 11;
int RED = 12;

int PED_GREEN = 9;
int PED_RED = 8;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
}

void green_car(){
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);  
}

void yellow_car(){
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}

void red_car(){
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}

void green_ped(){
  digitalWrite(PED_GREEN, HIGH);
  digitalWrite(PED_RED, LOW);
}

void red_ped(){
  digitalWrite(PED_GREEN, LOW);
  digitalWrite(PED_RED, HIGH);
}

void alert_ped(){
  digitalWrite(PED_GREEN, LOW);

  for(int k=0; k<=5; k++){
    digitalWrite(PED_RED, HIGH);
    delay(300);
    digitalWrite(PED_RED, LOW);
    delay(300);
  }
}

// the loop function runs over and over again forever
void loop() {
  // Red for cars, green for pedestritians
  red_car();
  delay(1000);
  green_ped();
  delay(5000);
  alert_ped();

  // Green for cars, red for pedestritians
  red_ped();
  delay(1000);
  green_car();
  delay(5000);

  // Yellow for car, blink pedestritians
  yellow_car();
  delay(2000);
}
