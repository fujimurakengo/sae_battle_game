/*
0 means Player A
1 means Player B

*/

#include <Servo.h>
//#include <Adafruit_NeoPixel.h>
#include "Pin_init.h"




int Count_down_Timer=0;
//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_Pin_OUT, LED_Pin_IN, NEO_GRB + NEO_KHZ800);

int A_player_pos[2] ={0,0};
int B_player_pos[2] ={0,0};
int Player_turn=1;

void select_map_possion(int *pos){
  
  (pos[0]  ) =  int(analogRead(x) * 4 /1023);
  (pos[1]) =  int(analogRead(y) * 4 /1023);

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
  //pixels.begin(); // This initializes the NeoPixel library.

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
 
  Count_down_Timer = 10;
  while(Count_down_Timer){
    select_map_possion( A_player_pos);
    select_map_possion( B_player_pos);
  }
  //player initial possion setting
  A_plyer_map[A_player_pos[0]][A_player_pos[1]]=1;
  B_plyer_map[B_player_pos[0]][B_player_pos[1]]=1;
}




void loop() {

  Player_turn = (1+Player_turn) % 2;//maybe this row's code will not use

  Count_down_Timer = 10; 
  while(Count_down_Timer){
    select_map_possion(A_player_pos);
  }
  if(A_plyer_map[B_player_pos[0]][B_player_pos[1]]==1){
    //Write here win code
  }
    
   Count_down_Timer = 10; 
   while(Count_down_Timer){
    select_map_possion( B_player_pos);
  }
  if(B_plyer_map[A_player_pos[0]][A_player_pos[1]]==1){
    //Write here win code
  } 
 
    
}
