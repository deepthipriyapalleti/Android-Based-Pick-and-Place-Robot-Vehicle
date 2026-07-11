Arduino Embedded C++ code: 
#include <Servo.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <SoftwareSerial.h>
SoftwareSerial myserial (2, 3);

int L1 = A0, L2 = A1, R1 = A2, R2 = A3;

void setup() 
{
  Serial.begin(9600);
  myserial.begin(9600);
  delay(100);

  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  digitalWrite(R1,LOW); // ROBOT
  digitalWrite(R2,LOW);
  digitalWrite(L1,LOW); // 
  digitalWrite(L2,LOW);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(4,LOW); // ARM
  digitalWrite(5,LOW);
  digitalWrite(6,LOW); // 
  digitalWrite(7,LOW);
  digitalWrite(8,LOW); // 
  digitalWrite(9,LOW);

  lcd.init();
  lcd.backlight();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("     ANDROID    ");
  lcd.setCursor(0, 1); 
  lcd.print("      BASED     ");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" PICK AND PLACE ");
  lcd.setCursor(0, 1); 
  lcd.print("      ROBOT     ");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ROBOT STATUS"); 
  lcd.setCursor(0, 1);
  lcd.print("STOP"); 
  delay(500);
  
}

void loop() 
{ 

  if (myserial.available() > 0) 
  {
    char c = myserial.read();
    Serial.print("INPUT : ");
    Serial.println(c);
    
    if (c == 'F') 
    {   
      //Serial.println("FORWARD");
      f();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("FORWARD"); 
      delay(400);
    }
    
    else if (c == 'B') 
    {   
      //Serial.println("BACKWARD");
      b();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("BACKWARD"); 
      delay(400);
      s();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }
    
    else if (c == 'L') 
    {   
      Serial.println("LEFT");
      l();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("LEFT"); 
      delay(500);
      s();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }
    
    else if (c == 'R') 
    {   
      Serial.println("RIGHT");
      r();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("RIGHT"); 
      delay(500);
      s();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }
    else if(c == 'S')
    {
      s();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);  
    }

    /********* ARM ***********/

    else if (c == 'O') 
    {   
      //Serial.println("OPEN");
      
      digitalWrite(7,HIGH); // ARM
      digitalWrite(6,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("GRIPPER OPEN"); 
      delay(100);
      
      digitalWrite(6,LOW); // ARM
      digitalWrite(7,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }

    else if (c == 'C') 
    {   
      //Serial.println("CLOSE");
      
      digitalWrite(6,HIGH); // ARM
      digitalWrite(7,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("CUTTER CLOSE"); 
      delay(100);
      
      digitalWrite(6,LOW); // ARM
      digitalWrite(7,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }

    else if (c == 'U') 
    {   
      Serial.println("UP");
      
      digitalWrite(4,HIGH); // 
      digitalWrite(5,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("ARM UP"); 
      delay(200);
      
      digitalWrite(4,LOW); // 
      digitalWrite(5,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }

    else if (c == 'D') 
    {   
      Serial.println("DOWN");
      
      digitalWrite(4,LOW); // 
      digitalWrite(5,HIGH);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("ARM DOWN"); 
      delay(200);
      
      digitalWrite(4,LOW); // 
      digitalWrite(5,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }

     else if (c == 'X') 
     {   
      Serial.println("ALEFT");
      
      digitalWrite(8,HIGH); // 
      digitalWrite(9,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("ARM LEFT"); 
      delay(200);
      
      digitalWrite(8,LOW); // 
      digitalWrite(9,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }

    else if (c == 'Y') 
    {   
      Serial.println("ARIGHT");
      
      digitalWrite(8,LOW); // 
      digitalWrite(9,HIGH);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("ARM RIGHT"); 
      delay(200);
      
      digitalWrite(8,LOW); // 
      digitalWrite(9,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROBOT STATUS"); 
      lcd.setCursor(0, 1);
      lcd.print("STOP"); 
      delay(500);
    }
  }
} 
// END OF LOOP

void f() 
{
  digitalWrite(L2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, LOW);
  

}
void b() 
{
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);   

}

void l() 
{
    digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW); 
}

void r() 
{

  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
}

void s() 
{
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}
