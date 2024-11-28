  #define forward 23
  #define revers 19
  #define LED_forward 22
  #define LED_revers 21
  int dummy=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(forward,OUTPUT);
  pinMode(revers,OUTPUT);
  pinMode(LED_forward,OUTPUT);
  pinMode(LED_revers,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()> 0) {//ตรวจสอบว่ามีข้อมูลเข้ามาหรือไม่
    Serial.println("Enter your order");
    dummy = Serial.read() - '0';//รับค่าตัวเลขมาใส่ใน dummy
  if(dummy==1||dummy==2){
    Serial.println(dummy);//ปริ้นค่า dummy ถ้า dummy มีค่า1หรือ2
  }
  if(dummy ==1){//ถ้า dummy มีค่าเท่ากับ1สะพานจะยกขึ้น 
    Serial.println("bridge up");
    digitalWrite(forward,HIGH);//up
    digitalWrite(LED_forward,HIGH);
    digitalWrite(revers,LOW);
    digitalWrite(LED_revers,LOW);
    delay(500);
    digitalWrite(forward,LOW);//stay
    digitalWrite(LED_forward,LOW);
    digitalWrite(revers,LOW);
    digitalWrite(LED_revers,LOW);
    delay(500);
    }
  if(dummy==2){//ถ้า dummy มีค่าเท่ากับ2สะพานจะปล่อยลง 
    Serial.println("bridge down");
    digitalWrite(forward,LOW);//down
    digitalWrite(LED_forward,LOW);
    digitalWrite(revers,HIGH);
    digitalWrite(LED_revers,HIGH);
    delay(500);
    digitalWrite(forward,LOW);//stay
    digitalWrite(LED_forward,LOW);
    digitalWrite(revers,LOW);
    digitalWrite(LED_revers,LOW);
    delay(500);
   }
  }
}
