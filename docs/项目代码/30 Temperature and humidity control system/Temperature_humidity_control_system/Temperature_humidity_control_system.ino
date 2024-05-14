/*  
 * 名称   : Temperature_humidity_control_system
 * 功能   : 温湿度传感器控制130风扇模块
 * 作者   : http://www.keyes-robot.com/ 
*/
#include "xht11.h"
xht11 xht(3); //定义XHT11的引脚为D3
unsigned char dht[4] = {0, 0, 0, 0};// 只接收数据的前32位，不接收奇偶校验位

void setup() {
  Serial.begin(9600);//启动串口监视器，设置波特率为9600
  pinMode(A4, OUTPUT); //INA对应IN+，将A4设置为输出模式
  pinMode(A5, OUTPUT);//INB对应IN-，将A5置为输出模式
}

void loop() {

  if (xht.receive(dht)) { //正确检查时返回true
    Serial.print("RH:");
    Serial.print(dht[0]); //湿度的积分部分DHT[1]为小数部分系列。打印(“%”);
    Serial.print("  Temp:");
    Serial.print(dht[2]); //温度的积分部分DHT[3]为小数部分
    Serial.println("°C");
    if (dht[2] > 32 || dht[0] > 80) {//温度高于32℃或湿度高于80%RH。  
      digitalWrite(A4, LOW);//打开电风扇
      digitalWrite(A5, HIGH);  
    } else {//否则，关闭风扇
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);  
    }
  } else {    //Read error
    Serial.println("sensor error");
  }
  delay(200);  //等待设备读取需要200ms 
}
