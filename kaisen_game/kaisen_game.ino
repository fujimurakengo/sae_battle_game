
#include <Adafruit_NeoPixel.h>
#define a0 A_player_contlor_x
#define a1 A_player_contlor_y
#define a2 B_player_contlor_x
#define a3 B_player_contlor_y


#define 8  a_led
#define 9  b_led
#define 10 c_led
#define 11 d_led
#define 12 e_led
#define 13 f_led
#define 28 g_led





int A_plyer_map[4][4]={{0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}
                       };
                       
int B_plyer_map[4][4]={{0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}
                       };
Servo water_direction;  // create servo object to control a servo 
Servo water_swich;  // create servo object to control a servo 


void setup() {
  // put your setup code here, to run once:
  water_direction.attach(4); 
  water_direction.attach(5); 
  
  pinMode(A_player_contlor_x,INPUT);
  pinMode(A_player_contlor_y,INPUT);  
  pinMode(B_player_contlor_x,INPUT);
  pinMode(B_player_contlor_y,INPUT);    

//7segument display i/o
  pinMode(a_led,OUTPUT);
  pinMode(b_led,OUTPUT);
  pinMode(c_led,OUTPUT);
  pinMode(d_led,OUTPUT);
  pinMode(e_led,OUTPUT);
  pinMode(f_led,OUTPUT);
  pinMode(g_led,OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
