//Edson Leonrdo 1ESPA / RM:553737 

#include <Adafruit_LiquidCrystal.h>

#define trigger 6
#define echo 5

Adafruit_LiquidCrystal lcd_1(0);

float distancia;
float duracao;
float velocidade= 0.0172316;

bool band1 = true;
bool band2 = true;
bool band3 = true;
bool band4 = true;

void setup(){
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  lcd_1.print("Armazenamento...");
}

void loop(){
  digitalWrite(trigger,0);
  delayMicroseconds(5);
  digitalWrite(trigger,1);
  delayMicroseconds(10);
  digitalWrite(trigger,0);
  duracao = pulseIn(echo,1);
  distancia = duracao * velocidade;
  Serial.print("Cm:");
  Serial.println(distancia);
  delay(100);

  if(distancia <10){
    if(band1 == true){
    lcd_1.clear();
    lcd_1.setCursor(0, 1);
    lcd_1.print("cheio");
    band1 = false;
    band2= true;
    band3= true;
    band4= true;
}}

  if(distancia <50){
    if(distancia >10){
   if(band2 == true){
    lcd_1.clear();
    lcd_1.setCursor(0, 1);
    lcd_1.print("Razoavel");
    band1 = true;
    band2= false;
    band3= true;
    band4= true;
}}
}

  if(distancia <100){
    if(distancia >50){
    if (band3 == true){
    lcd_1.clear();
    lcd_1.setCursor(0, 1);
    lcd_1.print("Quase Vazio");
    band1 = true;
    band2= true;
    band3= false;
    band4= true;
} }
}

if(distancia <150){
    if(distancia >100){
    if(band4 == true){
    lcd_1.clear();
    lcd_1.setCursor(0, 1);
    lcd_1.print("Falta de estoque");
    band1 = true;
    band2= true;
    band3= true;
    band4= false;
}}
}
}