/*  
 * 名称   : Night_Lamp
 * 功能   : 光敏传感器控制LED
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;  //设置item为0
int PIN_ANALOG_IN = A0;   //光敏传感器的引脚定义为A0
int PIN_LED = 3;   //LED的引脚定义为D3

void setup() {
  Serial.begin(9600); //设置串口波特率为9600
  pinMode(PIN_ANALOG_IN, INPUT);    //将传感器的引脚设置为输入模式
  pinMode(PIN_LED, OUTPUT);  // 设置led引脚为输出模式.
}

void loop() {
  item = analogRead(PIN_ANALOG_IN);    //读取传感器的模拟信号
  Serial.println(item);  //串口打印光敏传感器输出的模拟信号
  if (item > 200) {  //光照强度的模拟值大于200
    digitalWrite(PIN_LED, LOW);  //关闭LED
  } else {  //模拟值小于等于200
    digitalWrite(PIN_LED, HIGH);  //打开LED
  }
}