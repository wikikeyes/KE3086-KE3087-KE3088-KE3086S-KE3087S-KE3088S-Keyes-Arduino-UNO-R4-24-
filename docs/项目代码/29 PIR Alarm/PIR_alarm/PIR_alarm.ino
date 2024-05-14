/*  
 * 名称   : PIR alarm
 * 功能   : PIR控制蜂鸣器和led模块
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIR_PIN  5     //PIR运动传感器控制引脚为D5
#define BUZZER_PIN  8  //定义有源蜂鸣器控制引脚为D8
int item = 0;

int ledpin = 3;    // 定义LED引脚D3

void setup() {
  Serial.begin(9600);//启动串口监视器，设置波特率为9600
  pinMode(PIR_PIN, INPUT);  //设置PIR运动传感器的引脚为输入模式
  pinMode(BUZZER_PIN, OUTPUT); //设置有源蜂鸣器的引脚为输出模式
  pinMode(ledpin, OUTPUT);   //设置LED引脚为输出模式
}

void loop() {
  item = digitalRead(PIR_PIN);//读取红外热释传感器输出的数字信号
  Serial.println(item);          //打印变量item的值
  if (item == 1) {  //运动检测
    digitalWrite(BUZZER_PIN, HIGH); //打开蜂鸣器
    digitalWrite(ledpin, HIGH);  // LED点亮
    delay(200); 
    digitalWrite(BUZZER_PIN, LOW); //关闭蜂鸣器
    digitalWrite(ledpin, LOW);  // LED不亮
    delay(200);
  } else {  //没有检测到任何信号或数据
    digitalWrite(BUZZER_PIN, LOW); //关闭蜂鸣器
    digitalWrite(ledpin, LOW);  // LED不亮
  }
}