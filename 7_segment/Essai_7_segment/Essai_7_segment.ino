int val = 0;
int rclk = 8, srcl = 9, ser = 10;
int tabChiffres[11][7] = {{0, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 1, 0, 1, 1}, {1, 0, 0, 1, 1, 1, 1}, {1, 1, 0, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 0, 1}, {0, 0, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0}};

void setup() {
  // l'afficheur n°1
  pinMode(rclk, OUTPUT);
  pinMode(srcl, OUTPUT);
  pinMode(ser, OUTPUT);
}

void loop() {
  affiche_chiffre(val);
  val = (val%100)+1;

  delay(1000);
}

void affiche_chiffre(int n){
  int unite = n%10;
  int dizaine = n/10;
  
  for (int i=0;i<7;i++){
    digitalWrite(ser,tabChiffres[dizaine][i]);

    digitalWrite(srcl,LOW);
    digitalWrite(srcl,HIGH);
  } 

  digitalWrite(srcl,LOW);
  digitalWrite(srcl,HIGH);
  
  for (int i=0;i<7;i++){
    digitalWrite(ser,tabChiffres[unite][i]);

    digitalWrite(srcl,LOW);
    digitalWrite(srcl,HIGH);
  } 
  digitalWrite(rclk,LOW);
  digitalWrite(rclk,HIGH);
}
