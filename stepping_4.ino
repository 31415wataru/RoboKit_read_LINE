#include <RoboKit.hpp>
#define PINA 0
#define PINB 1
#define PINC 2
#define PIND 3
void C0();
void C1();
void C2();
void C3();
void C4();
void C5();
void C6();
void C7();

void setup() {
  robot.init();
  pinMode( 26 , INPUT);
  digitalWrite(26, HIGH);
  Serial.begin(9600);
  pinMode( 19 , OUTPUT);
  pinMode( 18 , OUTPUT);
  pinMode( 17 , OUTPUT);
  pinMode( 16 , OUTPUT);
}

void Loop(){
  int line_value[7] = {0};
  C0(&line_value[0]);
  C1(&line_value[1]);
  C2(&line_value[2]);
  C3(&line_value[3]);
  C4(&line_value[4]);
  C5(&line_value[5]);
  C6(&line_value[6]);
  C7(&line_value[7]);
  int i;
  int n;
  int Min = 1000;
  for(i = 0;i < 8;i++){
    if(line_value[i]< Min){
      Min = line_value[i];
        n = i;
    }else{
      
  }
  }
  if(n==7){
      robot.motor(0, 250);
      /*
      analogWrite(PINA, 0);
      analogWrite(PIND, 150);
      */
  }else{
  if(n==6){
      robot.motor(50, 250);
      /*
      analogWrite(PINA, 50);
      analogWrite(PIND, 150);
      */
  }else{
  if(n==5){
      robot.motor(150, 250);
      /*
      analogWrite(PINA, 75);
      analogWrite(PIND, 150);
      */
  }else{
   if(n==4){
     robot.motor(200, 250);
     /*
      analogWrite(PINA, 100);
      analogWrite(PIND, 150);
    */
  }else{
    if(n==3){
     robot.motor(250, 200);
     /*
      analogWrite(PINA, 150);
      analogWrite(PIND, 100);
    */
  }else{
    if(n==2){
      robot.motor(250, 150);
      /*
      analogWrite(PINA, 150);
      analogWrite(PIND, 75);
      */
  }else{
    if(n==1){
      robot.motor(250, 50);
      /*
      analogWrite(PINA, 150);
      analogWrite(PIND, 50);
      */
  }else{
  if(n==0){
      robot.motor(250, 0);
      /*
      analogWrite(PINA, 150);
      analogWrite(PIND, 0);
      */
  }
  }
  }
  }
  }
  }
  }
  }
  
  Serial.println(n);
  /*
  Serial.print("C0:");
  Serial.print(" ");
  Serial.print(line_value[0]);
  Serial.print(" ");
 
  Serial.print("C1:");
  Serial.print(" ");
  Serial.print(line_value[1]);
  Serial.print(" ");

  Serial.print("C2:");
  Serial.print(" ");
  Serial.print(line_value[2]);
  Serial.print(" ");
  
  Serial.print("C3:");
  Serial.print(" ");
  Serial.print(line_value[3]);
  Serial.print(" ");
 
  Serial.print("C4:");
  Serial.print(" ");
  Serial.print(line_value[4]);
  Serial.print(" ");
 
  Serial.print("C5:");
  Serial.print(" ");
  Serial.print(line_value[5]);
  Serial.print(" ");
  
  Serial.print("C6:");
  Serial.print(" ");
  Serial.print(line_value[6]);
  Serial.print(" ");
  
  Serial.print("C7:");
  Serial.print(" ");
  Serial.print(line_value[7]);
  Serial.print(" ");
  Serial.println();
  */
}

void C0(int *c0_line)
{
  digitalWrite( 16 , LOW );
  digitalWrite( 17 , LOW );
  digitalWrite( 18 , LOW );
  digitalWrite( 19 , LOW );
  *c0_line = analogRead(26);
}
void C1(int *c1_line)
{
  digitalWrite( 16 , HIGH );
  digitalWrite( 17 , LOW );
  digitalWrite( 18 , LOW );
  digitalWrite( 19 , LOW );
  *c1_line = analogRead(26);
}
void C2(int *c2_line)
{
  digitalWrite( 16 , LOW );
  digitalWrite( 17 , HIGH );
  digitalWrite( 18 , LOW );
  digitalWrite( 19 , LOW );
  *c2_line = analogRead(26);
}

void C3(int *c3_line)
{
  digitalWrite( 16 , HIGH );
  digitalWrite( 17 , HIGH );
  digitalWrite( 18 , LOW );
  digitalWrite( 19 , LOW );
  *c3_line = analogRead(26);
}

void C4(int *c4_line)
{
  digitalWrite( 16 , LOW );
  digitalWrite( 17 , LOW );
  digitalWrite( 18 , HIGH );
  digitalWrite( 19 , LOW );
  *c4_line = analogRead(26);
}

void C5(int *c5_line)
{
  digitalWrite( 16 , HIGH );
  digitalWrite( 17 , LOW );
  digitalWrite( 18 , HIGH );
  digitalWrite( 19 , LOW );
  *c5_line = analogRead(26);
}
void C6(int *c6_line)
{
  digitalWrite( 16 , LOW );
  digitalWrite( 17 , HIGH );
  digitalWrite( 18 , HIGH );
  digitalWrite( 19 , LOW );
  *c6_line = analogRead(26);
}

void C7(int *c7_line)
{
  digitalWrite( 16 , HIGH );
  digitalWrite( 17 , HIGH );
  digitalWrite( 18 , HIGH );
  digitalWrite( 19 , LOW );
  *c7_line = analogRead(26);
}