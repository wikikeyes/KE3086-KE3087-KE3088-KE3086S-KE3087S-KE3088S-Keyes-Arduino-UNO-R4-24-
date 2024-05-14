/*  
 * 名称   : sound-controlled lights
 * 功能   : 声音传感器控制LED亮灭
 * 作者   : http://www.keyes-robot.com/ 
*/
int microPin = A0;  //定义声音传感器的控制引脚为A0
#define LED_PIN  3   //定义led模块控制引脚为D3

void setup() {
  Serial.begin(9600); //波特率设置为9600
  pinMode(microPin, INPUT);    //将传感器的引脚设置为输入模式
  pinMode(LED_PIN, OUTPUT);  // 设置led引脚为输出模式.
}

void loop() {
  int val = analogRead(microPin); //读取模拟值
  Serial.print(val); // 串口打印
  if(val > 150){ //超过阈值
    digitalWrite(LED_PIN, HIGH);  //打开LED
    delay(5000);
  }else{ //否则
    digitalWrite(LED_PIN, LOW);  //关闭LED
  }
  delay(100);
}