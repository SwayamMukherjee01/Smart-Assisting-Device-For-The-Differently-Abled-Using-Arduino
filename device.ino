#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int littlefinger = A0;
int ringfinger = A1;
int middlefinger = A2;
int indexfinger = A3;
float maxlittle = 75;
float minlittle = 65;
float maxring = 122;
float minring = 82;
float maxmiddle = 76;
float minmiddle = 60;
float maxindex = 80;
float minindex = 45;


int value;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(littlefinger, INPUT);
  pinMode(ringfinger, INPUT);
  pinMode(middlefinger, INPUT);
  pinMode(indexfinger, INPUT);
  Serial.begin(9600);

}

void loop() {
  //put your main code here, to run repeatedly:

  float littlefingervalue = analogRead(littlefinger);
  float ringfingervalue = analogRead(ringfinger);
  float middlefingervalue = analogRead(middlefinger);
  float indexfingervalue = analogRead(indexfinger);
  float littlefingerdeci = (littlefingervalue - minlittle) / (maxlittle - minlittle);

  // Serial.print("little finger: ");
  // Serial.println(littlefingerdeci);
  // Serial.print("littlefingervalue:  ");
  // Serial.println(littlefingervalue);

  float ringfingerdeci = (ringfingervalue - minring) / (maxring - minring);

  // Serial.print("ringfingervalue: ");
  // Serial.println(ringfingervalue);
  // Serial.print("ringerfingerdeci: ");
  // Serial.println(ringfingerdeci);

  float middlefingerdeci = (middlefingervalue - minmiddle) / (maxmiddle - minmiddle);

  // Serial.print("middlefingervalue: ");
  // Serial.println(middlefingervalue);
  // Serial.print("middlefingerdeci: ");
  // Serial.println(middlefingerdeci);

  float indexfingerdeci = (indexfingervalue - minindex) / (maxindex - minindex);

  // Serial.print("indexfinger: ");
  // Serial.println(indexfingervalue);
  // Serial.print("indexfingerdeci: ");
  // Serial.println(indexfingerdeci); 
  func(littlefingerdeci, ringfingerdeci, middlefingerdeci, indexfingerdeci);

  delay(2000);

  

}

void func(float l, float r, float m, float i) {

  while(l < 0.5 && r < 0.5 && m < 0.5 && i < 0.5) {

    Serial.println("inside the while loop");
    int count = 0;

    float littlefingervalue = analogRead(littlefinger);
    delay(1);
    float ringfingervalue = analogRead(ringfinger);
    delay(1);
    float middlefingervalue = analogRead(middlefinger);
    delay(1);
    float indexfingervalue = analogRead(indexfinger);

    
    float lv = (littlefingervalue - minlittle) / (maxlittle - minlittle);
    if (lv > 0.5) {count++;}
    float rv = (ringfingervalue - minring) / (maxring - minring);
    if (rv > 0.5) {count++;}
    float mv = (middlefingervalue - minmiddle) / (maxmiddle - minmiddle);
    if (mv > 0.5) {count++;}
    float iv = (indexfingervalue - minindex) / (maxindex - minindex);
    if (iv > 0.5) {count++;}

    if (count == 1) {
      oneFingerGesture(iv, mv, rv, lv);

    } else if (count == 2) {
      twoFingerGesture(iv, mv, rv, lv);

    } else if (count == 3) {
      threeFingerGesture(iv, mv, rv, lv);

    } else if (count == 4) {
      fourFingerGesture(iv, mv, rv, lv);

    }else {
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("no move");
      delay(100);
    }


  }
}

void oneFingerGesture(float iv, float mv, float rv, float lv) {

  if (iv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("index");
    Serial.println("index finger bend only");
    delay(100);

  } else if (mv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("middle");
    Serial.print("middle finger bend only");
    delay(100);

  } else if (rv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ring");
    delay(100);

  } else if (lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("litlte");
    delay(100);
  }

}

void twoFingerGesture(float iv, float mv, float rv, float lv) {
  if (iv > 0.5 && mv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("index middle");
    delay(100);

  } else if (iv > 0.5 && rv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("index ring");
    delay(100);

  } else if (iv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("index little");
    delay(100);

  } else if (mv > 0.5 && rv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("middle ring");
    delay(100);
  } else if (mv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("middle little");
    delay(100);

  } else if (rv > 0.5 &&  lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ring little");
    delay(100);
  }

}

void threeFingerGesture(float iv, float mv, float rv, float lv) {
  
  if (iv > 0.5 && mv > 0.5 > rv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("in mid li");
    delay(100);

  } else if (iv > 0.5 && mv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("in mi li");
    delay(100);

  } else if (iv > 0.5 && rv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("in ri li");
    delay(100);

  } else if (mv > 0.5 && rv > 0.5 && lv > 0.5) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("mi ri li");
    delay(100);
  }
}

void fourFingerGesture(float iv, float mv, float rv, float lv) {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("all fingers");
    delay(100);
}
