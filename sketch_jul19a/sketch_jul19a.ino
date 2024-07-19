#include <RoboKit.hpp>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#define BNO055_SAMPLERATE_DELAY_MS (100)
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

float Kp = 10;       // 比例ゲインKp
float Ki = 0;       // 比例ゲインKi
float Kd = 0;       // 比例ゲインKd
float target = 180;  // 目標角度[rad]



void displaySensorDetails(void){
  sensor_t sensor;
  bno.getSensor(&sensor);
}
void setup(void){
  Serial.begin(115200);
  Serial.println("Orientation Sensor Test"); Serial.println("");




  /* Initialise the sensor */
  if(!bno.begin()){
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
   
  delay(1000);

  /* Use external crystal for better accuracy */
  bno.setExtCrystalUse(true);
   
  /* Display some basic information on this sensor */
  displaySensorDetails();
}
void Loop(void){
  /* Get a new sensor event */
  sensors_event_t event;
  bno.getEvent(&event);



  /* The processing sketch expects data as roll, pitch, heading */
  Serial.print(F("Orientation: "));
  Serial.print((float)event.orientation.x);
  const char direction=(float)event.orientation.x;
  Serial.print(F(" "));
  Serial.print((float)event.orientation.y);
  Serial.print(F(" "));
  Serial.print((float)event.orientation.z);
  Serial.println(F(""));



static float integral = 0;
  static float last_err = 0;
  static unsigned long last_micros = 0;
  
  float current_rad = event.orientation.x;    // エンコーダから現在の角度を取得
  float err = target - current_rad;                   // 偏差を計算
  float P = Kp * err;                                 // Pを計算
  unsigned long current_micros = micros();            // 現在の時間を取得
  float dt = ((float)(current_micros - last_micros))
              / 1000000.0;                            // 経過時間を計算
  integral += err * dt;                               // 偏差の積分を計算
  float I = Ki * integral;                            // Iを計算
  float diff = (err - last_err) / dt;                 // 偏差の微分を計算
  float D = Kd * diff; 
  robot.motor(P+I+D, P+I+D);
  /*                               // Dを計算
   if(event.orientation.x > 180){
     robot.motor(P+I+D, (P+I+D));
   }else{
     robot.motor(-1*(P+I+D), -1*(P+I+D));
   }*/
               
// PIDでモータを制御
  last_err = err;                                     // 現在の偏差を保存
  last_micros = current_micros;                       // 現在の時間を保存


  delay(BNO055_SAMPLERATE_DELAY_MS);
}
