#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int var1; //Đồ ăn 13
int var2; //Đồ uống 12
int var3; //Chọn 11

String food[4] = {"", "Com ga 15K", "Bun tron 20K", "Thit nuong 20M"};
String drink[4] = {"", "Bia 15K", "Coca 10K", "Tra da 20M"};
int i = 0; //index var for food
int j = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  printMenu();
}

void loop() {
  var1 = digitalRead(13);
  var2 = digitalRead(12);
  var3 = digitalRead(11);

  if (var1 == LOW) {
    if (i == 4) {
      i = 0;
    }
    lcd.clear();
    lcd.print("LUA CHON DO AN");
    lcd.setCursor(0, 1);
    lcd.print(food[i]);
    i++;
  }

  if (var2 == LOW) {
    if (j == 4) {
      j = 0;
    }
    lcd.clear();
    lcd.print("LUA CHON DO UONG");
    lcd.setCursor(0, 1);
    lcd.print(drink[j]);
    j++;
  }

  if (var3 == LOW) {
    lcd.clear();
    lcd.print("Ban da chon: ");
    delay(1000);
    lcd.clear();
    if (i == 0 && j == 0) {
      lcd.print(food[i]);
      lcd.setCursor(0, 1);
      lcd.print(drink[j]);
    }
    else if (i == 0) {
      lcd.print(food[i]);
      lcd.setCursor(0, 1);
      lcd.print(drink[j - 1]);
    } else if (j == 0) {
      lcd.print(food[i - 1]);
      lcd.setCursor(0, 1);
      lcd.print(drink[j]);
    } else {
      lcd.print(food[i - 1]);
      lcd.setCursor(0, 1);
      lcd.print(drink[j - 1]);
    }
    i = j = 0;
    delay(2000);
    printMenu();
  }

  delay(200);
}

void printMenu() {
  lcd.clear();
  lcd.print("DO AN - DO UONG");
}
