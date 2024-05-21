#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Configura el LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Cambia 0x27 si tu dirección I2C es diferente

void setup() {
  // Inicia el puerto serie
  Serial.begin(115200);
  
  // Inicia el LCD
  lcd.begin(16, 2);
  Serial.println("iniciando ");

  // Enciende la luz de fondo
  lcd.backlight();

  // Muestra "Hola Mundo" en el LCD
  lcd.setCursor(0, 0);
  lcd.print("uwu ");
}

void loop() {
  // Lee el valor del potenciómetro (entre 0 y 1023)
  int valor = analogRead(A0);

  // Convierte el valor a un porcentaje (entre 0 y 100)
  int porcentaje = map(valor, 0, 910, 0, 100 ) ;
  

  // Limpia el LCD
  lcd.clear();

  // Establece el cursor en la esquina superior izquierda
  lcd.setCursor(0, 0);

  // Muestra el porcentaje en el LCD
  lcd.print("Potenciometro: ");
  lcd.setCursor(0, 1);
  lcd.print(porcentaje);
  lcd.print("%");
  
  // Espera un poco antes de la próxima lectura
  delay(50);
}