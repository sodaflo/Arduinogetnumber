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
      //-48, da ASCII-Code ankommt
      get[i] = Serial.read() - 48;
      //'-' ist in ASCII 45 und wäre dann jetzt -3
      //Wenn das erste Zeichen ein '-' ist, dann wir das i wieder zurückgesetzt
      //in 'minus' wird gespeichert, dass die Zahl negativ ist
      if(get[i] == -3){ 
        i--;  		
        minus = true;	
      }
      i++;
      //kleine Zeitverzögerung um der Schnittstelle Zeit zu lassen
      delay(5);
    }
    i--;
    while(i>=0){
      //zusammenrechnung der verschiedenen Werte mit entsprechender 10er-Potenz
      number += get[i]*l;	
      l *= 10;
      i--;
    }
  }
  //wenn erstes Zeichen ein Minuszeichen ist, dann wird 'number' negativ
  if(minus){ 
    number *= -1;
  }
  //gibt die empfangene Zahl zurück
  return number;
}
