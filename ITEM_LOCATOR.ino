#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS]={4,5,6,7};//connect to the row pinouts of the keypad
byte colPins[COLS]={8,9,10};//connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);


int Incoming_value;
LiquidCrystal_I2C lcd(0x27, 16, 4);
SoftwareSerial mySerial(3,2); //RX, TX

void setup() {
  lcd.begin();
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  lcd.setCursor(6,1);
  lcd.print("TO");
  lcd.setCursor(-2,2);
  lcd.print("MOUNT KENYA");
  lcd.setCursor(-2,3);
  lcd.print("SUPERMARKET");
  delay(2000);

}

void loop() {
  
  char key = keypad.getKey();
   
    if(key == '1'){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("VEGETABLES");
      lcd.setCursor(2,1);
      lcd.print("GROUND FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 1");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 1");
      delay(2000);
    }else if(key == '2'){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("DAIRY PRODUCTS");
      lcd.setCursor(2,1);
      lcd.print("GROUND FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 1");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 2");
      delay(2000);
    }else if(key == '3'){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("BAKERY");
      lcd.setCursor(2,1);
      lcd.print("GROUND FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 2");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 1");
      delay(2000);
    }else if(key == '4'){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("STATIONARY");
      lcd.setCursor(2,1);
      lcd.print("FIRST FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 1");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 1");
      delay(2000);
    }else if(key == '5'){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("CLOTHES");
      lcd.setCursor(2,1);
      lcd.print("FIRST FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 2");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 1");
      delay(2000);
    }else if(key == '6'){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("UTENSILS");
      lcd.setCursor(2,1);
      lcd.print("FIRST FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 3");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 1");
      delay(2000);
    }else if(key == '7'){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("ELECTRONICS");
      lcd.setCursor(2,1);
      lcd.print("SECOND FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROWS NO: 1");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 1");
      delay(2000);
    }else if(key == '8'){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("DETERGENTS");
      lcd.setCursor(2,1);
      lcd.print("SECOND FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 2");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN N0: 3");
      delay(2000);
    }else if(key == '9'){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("BICYCLE");
      lcd.setCursor(2,1);
      lcd.print("SECOND FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 3");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 4");
      delay(2000);
    }else if(key == '*'){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("WHOLESALE ITEMS");
      lcd.setCursor(1,1);
      lcd.print("IN EVERY FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 6");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 6");
      delay(1000);
    }else if(key == '0'){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("CUSTOMER CARE");
      lcd.setCursor(2,1);
      lcd.print("GROUND FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 4");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 4");
      delay(1000);
    }else if(key == '#'){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("TROLLY");
      lcd.setCursor(1,1);
      lcd.print("IN EVERY FLOOR");
      lcd.setCursor(-4,2);
      lcd.print("ROW NO: 5");
      lcd.setCursor(-4,3);
      lcd.print("COLUMN NO: 5");
      delay(1000);
    }

    
    if(mySerial.available()>0){
      Incoming_value = mySerial.read();
      mySerial.print(Incoming_value);
      mySerial.print(Serial.read());
      Serial.print("\n");
      Serial.print("Bluetooth Connected");
      if(Incoming_value == '1'){
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("VEGETABLES");
        lcd.setCursor(2,1);
        lcd.print("GROUND FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 1");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 1");
        delay(2000);
      }else if(Incoming_value == '2'){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("DAIRY PRODUCTS");
        lcd.setCursor(2,1);
        lcd.print("GROUND FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 1");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 2");
        delay(2000);
      }else if(Incoming_value == '3'){
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("BAKERY");
        lcd.setCursor(2,1);
        lcd.print("GROUND FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 2");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 1");
        delay(2000);
      }else if(Incoming_value == '4'){
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("STATIONARY");
        lcd.setCursor(2,1);
        lcd.print("FIRST FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 1");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 1");
        delay(2000);
      }else if(Incoming_value == '5'){
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("CLOTHES");
        lcd.setCursor(2,1);
        lcd.print("FIRST FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 2");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 1");
        delay(2000);
      }else if(Incoming_value == '6'){
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("UTENSILS");
        lcd.setCursor(2,1);
        lcd.print("FIRST FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 3");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 1");
        delay(2000);
      }else if(Incoming_value == '7'){
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("ELECTRONICS");
        lcd.setCursor(2,1);
        lcd.print("SECOND FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROWS NO: 1");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 1");
        delay(2000);
      }else if(Incoming_value == '8'){
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("DETERGENTS");
        lcd.setCursor(2,1);
        lcd.print("SECOND FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 2");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN N0: 3");
        delay(2000);
      }else if(Incoming_value == '9'){
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("BICYCLE");
        lcd.setCursor(2,1);
        lcd.print("SECOND FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 3");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 4");
        delay(2000);
      }else if(Incoming_value == 'a'){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("WHOLESALE ITEMS");
        lcd.setCursor(1,1);
        lcd.print("IN EVERY FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 6");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 6");
        delay(1000);
      }else if(Incoming_value == 'b'){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("CUSTOMER CARE");
        lcd.setCursor(2,1);
        lcd.print("GROUND FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 4");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 4");
        delay(1000);
      }else if(Incoming_value == 'c'){
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("TROLLY");
        lcd.setCursor(1,1);
        lcd.print("IN EVERY FLOOR");
        lcd.setCursor(-4,2);
        lcd.print("ROW NO: 5");
        lcd.setCursor(-4,3);
        lcd.print("COLUMN NO: 5");
        delay(1000);
          
      }
    }else{
      Serial.println("BLUETOOTH NOT CONNECTED");
    }
  
}
  

   
  
