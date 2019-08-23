
/*
0 means Player A
1 means Player B
*/
#include <Servo.h>
#include <MsTimer2.h>
//#include <Adafruit_NeoPixel.h>
#include "Pin_init.h"
//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_Pin_OUT, LED_Pin_IN, NEO_GRB + NEO_KHZ800);
Servo water_direction;  // create servo object to control a servo 
Servo water_swich;  // create servo object to control a servo 
int k=9;
void setup() {
   Serial.begin(115200); 
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
  MsTimer2::set(1000, flash);
  MsTimer2::start();
  while(Count_down_Timer){
    select_map_possion(A_player_contlor_x, A_player_contlor_y, A_player_pos,A_pre_player_pos,0);
    select_map_possion(B_player_contlor_x, B_player_contlor_y, B_player_pos,B_pre_player_pos,1);

  }
  MsTimer2::stop();
  //player initial possion setting
  A_plyer_map[A_player_pos[0]][A_player_pos[1]]=1;
  B_plyer_map[B_player_pos[0]][B_player_pos[1]]=1;
}

void loop() {
  Player_turn = (1+Player_turn) % 2;//maybe this row's code will not use

  Count_down_Timer = 10; 
  MsTimer2::start();
  while(Count_down_Timer){
    select_map_possion(A_player_contlor_x, A_player_contlor_y, A_player_pos,A_pre_player_pos,0);
  }
  MsTimer2::stop();
  water_direction.write(180);
  delay(1000);
  if(B_plyer_map[A_player_pos[0]][A_player_pos[1]]==1){
    //Write here win code
    water_swich.write(10);
    delay(2000);
  }
  int kinbou=0;
  for(int x_kinbou=-1;x_kinbou<2;x_kinbou+=2){
    for(int y_kinbou=-1;y_kinbou<2;y_kinbou+=2){    
       kinbou=B_plyer_map[x_kinbou+A_player_pos[0]][y_kinbou+A_player_pos[1]]+kinbou;
    }   
  }
  if (kinbou>0){
    water_swich.write(10);
    delay(500);
  }
  water_swich.write(0);  
  
  
  
  
  
   Count_down_Timer = 10; 
   MsTimer2::start();
   while(Count_down_Timer){
    select_map_possion(B_player_contlor_x, B_player_contlor_y, B_player_pos,B_pre_player_pos,1);
  }
  MsTimer2::stop();
  water_direction.write(0);
  delay(1000);
  if(A_plyer_map[B_player_pos[0]][B_player_pos[1]]==1){
    //Write here win code
    water_swich.write(10);
    delay(2000);
  }

  for(int x_kinbou=-1;x_kinbou<2;x_kinbou+=2){
    for(int y_kinbou=-1;y_kinbou<2;y_kinbou+=2){
    
       kinbou=A_plyer_map[x_kinbou+B_player_pos[0]][y_kinbou+B_player_pos[1]]+kinbou;
    }   
  }
  if (kinbou>0){
    water_swich.write(10);
    delay(500);
  }


   water_swich.write(0); 
}

int conversion_position(int player_turn)
{
  //A:0
  if(player_turn==0){
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(A_plyer_map[i][j]==1){
          return(A_player_transmap[i][j]);
        }
      }
    }
  }else{
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(B_plyer_map[i][j]==1){
          return(B_player_transmap[i][j]);
        }
      }
    }
  }
}



void select_map_possion(int x, int y,int *pos,int *pre_pos,int player_num){
  
  (pos[0]  ) =  int(analogRead(x) * 4 /1023);
  (pos[1]) =  int(analogRead(y) * 4 /1023);

  Serial.write("led;");
  Serial.println(player_num);
  Serial.println(pre_pos[0]+pre_pos[1]*4);
  Serial.println(0);//red
  Serial.println(0);//blue
  Serial.println(0);//green
    
  Serial.write("led;");
  Serial.println(player_num);
  Serial.println(pos[0]+pos[1]*4);
  Serial.println(225);//red
  Serial.println(0);
  Serial.println(0);    
  pre_pos[0] =  pos[0];
  pre_pos[1] =  pos[1];
//here.you use pointer to detect axises
}
  
//全てのLEDを非表示にする
void off7SegLED(){
//for文で2番ピンから8番ピンまでをLOWにする
 for(int j=2;j<9;j++){
  digitalWrite(j,HIGH);
 }
}
void flash() {
    for (int w=0; w<=7; w++){
     digitalWrite(Led_number_list[w],-Num_Array[Count_down_Timer][w]);
    }
    
    if(Count_down_Timer>=0)Count_down_Timer--;
}
