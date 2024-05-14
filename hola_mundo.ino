#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C del display 
#define I2C_ADDR 0x27

// Número de columnas y filas del display
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Inicializamos el objeto LCD
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

void setup() {
  // Inicializamos el LCD
  lcd.init();

  // Encendemos el backlight
  lcd.backlight();

  // Imprimimos "Hola Mundo" en la primera fila
  lcd.setCursor(0, 0);
  lcd.print("Hola Mundo!!!");
}

void loop() {
  // El loop está vacío ya que no necesitamos realizar ninguna tarea adicional
}
