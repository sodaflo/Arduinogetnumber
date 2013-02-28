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

double getint(){
  boolean minus = false;
  double l = 1;
  double number = 0;
  if(Serial.available() > 0){
    int get[20];
    int i = 0;
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
    if(i > 0){
      int a = i;
      while(a > 0){
       l *= 10;
       a--;
      }
    }      
    double c = 1;
    while(i>=0){
      number = number + get[i]*c;
      c *= 10;
      i--;
    }
  }
  if(minus){
    number *= -1;
  }
  return number;
}



