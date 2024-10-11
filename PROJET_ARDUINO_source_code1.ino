#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Configuration du LCD avec RS, EN, D4, D5, D6, D7
const char message[] = "Bienvenue a ESTC";  // Message à afficher

void setup() {
  lcd.begin(16, 2);  // Initialisation du LCD avec 16 colonnes et 2 lignes
}

void loop() {
  scrollMessageToLeft(message, 100);  // Faire défiler le message vers la gauche avec un délai de 100 millisecondes
  delay(500);  // Pause pendant 500 millisecondes
  scrollMessageToRight(message, 100);  // Faire défiler le message vers la droite avec un délai de 100 millisecondes
  delay(500);  // Pause pendant 500 millisecondes
}

void scrollMessageToLeft(const char* msg, int delayTime) {
  int msgLength = strlen(msg);

  for (int i = 0; i <= 16; ++i) {
    lcd.clear();  // Effacer l'affichage du LCD
    lcd.setCursor(0 - i, 0);  // Positionner le curseur à la position actuelle
    lcd.print(msg);  // Afficher le message
    delay(delayTime);  // Délai pour contrôler la vitesse de défilement
  }
}

void scrollMessageToRight(const char* msg, int delayTime) {
  int msgLength = strlen(msg);

  for (int i = 0; i <= 16; ++i) {
    lcd.clear();  // Effacer l'affichage du LCD
    lcd.setCursor(16 - i, 0);  // Positionner le curseur à la position actuelle
    lcd.print(msg);  // Afficher le message
    delay(delayTime);  // Délai pour contrôler la vitesse de défilement
  }
}
