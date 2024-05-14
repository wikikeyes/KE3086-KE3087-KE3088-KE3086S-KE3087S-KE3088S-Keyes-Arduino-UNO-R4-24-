/* 
 * 名称   : Button_control_led
 * 功能   : 模拟一个小台灯
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_BUTTON  5  //将自锁按键的引脚连接到D5
int val = 0;            //用于存储键值

int ledpin = 3;    // 定义LED引脚D3

void setup() {
  Serial.begin(9600);//启动串口监视器，设置波特率为9600
  pinMode(PIN_BUTTON, INPUT);  //设置自锁按键的引脚为输入模式
  pinMode(ledpin, OUTPUT);   //设置LED引脚为输出模式
}

// 循环函数会一直运行下去
void loop() {
  val = digitalRead(PIN_BUTTON);  //读取自锁按键的值并将其赋值给变量val
  Serial.println(val);          //打印变量val的值
  if (val == 0) {             //按下自锁按键时读取到低电平
    digitalWrite(ledpin, HIGH);  //LED点亮
  }
  else {   //按起自锁按键时读取到高电平
    digitalWrite(ledpin, LOW);  //LED不亮
  } 
}
