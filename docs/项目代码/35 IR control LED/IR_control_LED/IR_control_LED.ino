/*  
 * 名称   : IR Control LED
 * 功能   : 红外遥控LED开关
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN  5   // 定义红外接收模块引脚D5
IRrecv irrecv(IR_RECEIVE_PIN);     // 创建一个用于接收类的类对象
decode_results results;     // 创建一个解码结果类对象

#define LED_PIN  3   //定义LED模块控制引脚为D3

boolean flag = true;  //LED标志钻头

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // 启动接收器
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
      Serial.print(IrReceiver.decodedIRData.decodedRawData, HEX);  // 打印原始数据
      // IrReceiver.printIRResultShort(&Serial); // 在一行中打印接收到的完整数据
      // IrReceiver.printIRSendUsage(&Serial);  // 打印发送这些数据所需的语句
      handleControl(IrReceiver.decodedIRData.decodedRawData);      // 处理来自远程控制的命令
      IrReceiver.resume(); // 启用接收下一个值
  }
}

void handleControl(unsigned long value){
  if (value == 0xBF40FF00 && flag == true){ // 接收数字“OK” 
    digitalWrite(LED_PIN, HIGH); // 点亮LED.
    delay(10);
    Serial.println("  led on");
    flag = false;
  } 
  else if (value == 0xBF40FF00 && flag == false){ // 接收数字“OK”
    digitalWrite(LED_PIN, LOW); // 熄灭LED.
    delay(10);
    Serial.println("  led off"); 
    flag = true;
  }
  else if(value == 0xE916FF00){
    analogWrite(LED_PIN, 85);
    delay(10);
    Serial.println("  weak light");

  } 
  else if(value == 0xE619FF00){
    analogWrite(LED_PIN, 170);
    delay(10);
    Serial.println("  normal light");
  } 
  else if(value == 0xF20DFF00){
    analogWrite(LED_PIN, 255);
    delay(10);
    Serial.println("  strong light");
  }
}