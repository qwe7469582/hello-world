#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int potpin = A2; //定义模拟接口0
int ledpin = 13; //定义数字接口13
unsigned long start;    //定义两个时间变量
unsigned long whole;
unsigned long s;
int val; //将定义变量val,并赋初值0
void setup()
{
  lcd.begin(16, 2);
  lcd.print("The Speed is");
  lcd.setCursor(13, 1);
  lcd.print("m/s");//输出到显示屏
  //        lcd.print((whole - s) / 80); //计算速度
  pinMode(ledpin, OUTPUT); //定义数字接口为输出接口
  Serial.begin(9600);//设置波特率为9600

}
void loop()
{
  val = analogRead(potpin); //读取模拟接口0 的值，并将其赋给val

  while (val < 1021) {
    val = analogRead(potpin);
    if (val > 1021)break;
  };    while (val > 1021) {
    val = analogRead(potpin);
    if (val < 1021)break;
  };
  //  lcd.clear();
  if (val < 1021)
  { delay(50);    //滤波
    start = millis() - 50;
    s = start;
    //    Serial.println(start); //同上
    //记录起始点并处理误差
    val = analogRead(potpin);
    while (val < 1021) {
      val = analogRead(potpin);
      if (val > 1021)break;
    };    while (val > 1021) {
      val = analogRead(potpin);
      if (val < 1021)break;
    };
    if (val < 1021)
    { delay(50);    //滤波
      whole = millis() - 50;
      Serial.println(whole); //串口调试，成功后删除这两行
      Serial.println((whole - s) / 80); //输出时间
      //      Serial.println("mS");    //输出单位
      lcd.setCursor(0, 1);
      lcd.print((whole - s) / 80); //计算速度
    }
  }
}

