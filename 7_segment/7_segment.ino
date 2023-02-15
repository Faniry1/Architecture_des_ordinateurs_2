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
  affiche_nombre(val);
  val = (val + 1) % 100;
  delay(300);

}

void affiche_nombre(int n) {
  int unite = n % 10;
  int dizaine = n / 10;

  // si n=-1, on efface tout sur l'afficheur
  if (n == -1) {
    unite = 10;
    dizaine = 10;
  }
  // on entre tous les segments correspondant au chiffre des dizaines dans le registre à décalage
  for (int i = 0; i < 7; i++) {
    // on présente l'entrée sur le registre à décalage
    digitalWrite(ser, tabChiffres[dizaine][i]);
    // on active l'écriture en envoyant un front montant sur srcl
    digitalWrite(srcl, LOW);
    digitalWrite(srcl, HIGH);
  }
  // comme le 8 eme emplacement du registre n'est pas utilisé on envoie une valeur quelconque dans le registre
  digitalWrite(srcl, LOW);
  digitalWrite(srcl, HIGH);

  // on entre tous les segments correspondant au chiffre des unités dans le registre à décalage
  for (int i = 0; i < 7; i++) {
    // on présente l'entrée sur le registre à décalage
    digitalWrite(ser, tabChiffres[unite][i]);
    // on active l'écriture en envoyant un front montant sur srcl

    digitalWrite(srcl, LOW);
    digitalWrite(srcl, HIGH);
  }
  // comme le 8 eme emplacement du registre n'est pas utilisé on envoie une valeur quelconque dans le registre
  digitalWrite(rclk, LOW);
  digitalWrite(rclk, HIGH);
}
