/*TP1,5 premier exemple
*/

#include <Adafruit_NeoPixel.h>
#define PIN            6 // Pin de connexion du cercle
#define NUMPIXELS      24 // Nombre de pixels du cercle

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // Initialisation du cercle
  pixels.setBrightness(1000); // Param de la luminosité

  //on commence par afficher la led 3 du cercl
  // Affichage

}
int etat=0;

int etat1  = 0 ;
int etat2 = 23;
void loop() {
  pixels.setPixelColor(etat1 , 0, 0, 255);
  pixels.setPixelColor(etat2, 255, 0, 0);
  pixels.show();
  
  if (etat ==0){
    etat1 +=1;
    etat2 -=1;
    if (etat1==24){
      etat1 = 0;
      etat = 1;
    }
    if (etat2==-1){
      etat2 = 23;
      etat = 1;
    }
  }
  else if (etat ==1){
    etat1 -=1;
    etat2 +=1;
    if (etat1==-1){
      etat1 = 23;
      etat = 0;
    }
    if (etat2==23){
      etat2 = 0;
      etat = 0;
    }
  }
  delay(20);
  pixels.clear();
}
