#include <RoboKit.hpp>
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
}
//ここから下はマルチプレクサの処理
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