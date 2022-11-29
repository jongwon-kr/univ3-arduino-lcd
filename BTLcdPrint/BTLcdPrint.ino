#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);    

SoftwareSerial BTSerial(4,5);

void setup(){
  Serial.begin(9600);
  Serial.println("Hello!");
  BTSerial.begin(9600);
  lcd.init();  // LCD초기 설정  
  lcd.backlight(); // LCD초기 설정  
  lcd.setCursor(0,0); 
  //처음 텍스트가 LCD에 나타날 위치  lcd.setCursor(열, 행)
  //밑에 사진을 통해 출력시작 위치를 확인할 수 있습니다.
  
  lcd.print("Hello, world!"); 
  lcd.setCursor(3,1); 
  lcd.print("How are you?"); 
}

void loop(){
  if(BTSerial.available()){
    lcd.init();  // LCD초기 설정  
    lcd.backlight(); // LCD초기 설정 
    while(BTSerial.available()){
      byte data = BTSerial.read();
      if(data>32&&data<127){
        lcd.write(data); 
      }
    }
  }

  while(Serial.available()){
    byte data = Serial.read();
    BTSerial.write(data);
  }
}
