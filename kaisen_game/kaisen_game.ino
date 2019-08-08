
#include <Servo.h>
#include <Adafruit_NeoPixel.h>


#define  A_player_contlor_x 0
#define  A_player_contlor_y 1
#define  B_player_contlor_x 2
#define  B_player_contlor_y 3
#define LED_Pin_IN   6
#define LED_Pin_OUT  7

int *A_player_pos[2] ={0,0};
int *B_player_pos[2] ={0,0};




#define  a_led  8
#define  b_led  9
#define  c_led 10
#define  d_led 11
#define  e_led 12
#define  f_led 13
#define  g_led 14

int Countown_Timer=0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_Pin_OUT, LED_Pin_IN, NEO_GRB + NEO_KHZ800);
void select_map_possion(int x, int y,int **pos){
 
  int x_axis_pos = int(analogRead(x) * 4 /1023);
  int y_axis_pos = int(analogRead(y) * 4 /1023);
  //here.you use pointer to detect axises
  
  
}
  

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
  water_direction.attach(4); // This initializes serv motor
  water_direction.attach(5); // This initializes serv motor
  pixels.begin(); // This initializes the NeoPixel library.

//player contlloer GPIO setting
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
  
 //setup sequence
 
  Countown_Timer = 10;
  while(Countown_Timer){
    //select_map_possion(A_player_contlor_x, A_player_contlor_y, &A_player_pos);
   // select_map_possion(B_player_contlor_x, B_player_contlor_y, &B_player_pos);
  }
  

}



void loop() {
  // put your main code here, to run repeatedly: 
  
}
