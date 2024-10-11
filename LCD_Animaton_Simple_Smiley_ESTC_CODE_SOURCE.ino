#include  <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 3, 4, 5, 6); // Configuration des broches pour le LCD (RS, EN, D4, D5, D6, D7)
byte smile[8] = {0b00000, 0b00000, 0b01010, 0b00000, 0b10001, 0b01110, 0b00000, 0b00000};
byte cry[8] = {0b00000, 0b00000, 0b01010, 0b01010, 0b00000, 0b00000, 0b01110, 0b10001};

int i = 0;

void setup()
{
  //---- Création des caractères personnalisés ----//
  lcd.createChar(1, smile); // Caractère 1 : Smile
  lcd.createChar(2, cry);   // Caractère 2 : Cry
  lcd.begin(16, 2);         // Initialisation du LCD avec une configuration 16x2
  lcd.print("BIENVENUE A ESTC"); // Affichage du message de bienvenue
  delay(2000);
}

void loop()
{
  // Faire défiler le message de gauche à droite
  for (int position = 0; position < 16; position++)
  {
    lcd.clear(); // Effacer l'affichage

    lcd.setCursor(position, 0);
    lcd.print("BIENVENUE A ESTC");

    lcd.setCursor(0, 1);
    for (i = 0; i < 16; i++)
      lcd.write(1); // Afficher le caractère Smile

    delay(500);
  }

  delay(500); // Pause à la fin du défilement

  // Faire défiler le message de droite à gauche
  for (int position = 15; position >= 0; position--)
  {
    lcd.clear(); // Effacer l'affichage

    lcd.setCursor(position, 0);
    lcd.print("BIENVENUE A ESTC");

    lcd.setCursor(0, 1);
    for (i = 0; i < 16; i++)
      lcd.write(2); // Afficher le caractère Cry

    delay(500);
  }

  delay(500); // Pause à la fin du défilement
}
