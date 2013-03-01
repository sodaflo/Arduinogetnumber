void setup(){
  Serial.begin(9600);
}
double lol = 0;
void loop(){
  lol = getint();
  if(lol != 0){
    Serial.println(lol);
    lol = 0;
  }
}

double getnumber(){
  double number = 0;
  if(Serial.available() > 0){
    boolean minus = false;
    double get[20];
    int i = 0;
    double c = 1;
    while(Serial.available() > 0){
      get[i] = Serial.read() - 48;
      if(get[i] == -3){
        i--;
        minus = true;
      }
      i++;
      delay(30);
    }
    i--;
    while(i>=0){
      number += get[i]*l;
      l *= 10;
      i--;
    }
  }
  if(minus){
    number *= -1;
  }
  return number;
}

