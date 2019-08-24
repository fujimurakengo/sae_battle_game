#define  A_player_contlor_x 0
#define  A_player_contlor_y 1
#define  B_player_contlor_x 2
#define  B_player_contlor_y 3


#define  a_led 13
#define  b_led 14
#define  c_led 15
#define  d_led 16
#define  e_led 17
#define  f_led 18
#define  g_led 19
int Led_number_list[]={a_led,b_led,c_led ,d_led ,e_led ,f_led ,g_led };
void select_map_possion(int x, int y,int *pos,int *pre_pos,int player_num);
int conversion_position(int player_turn);
void off7SegLED();
void flash() ;
int Count_down_Timer=0;
int LED_Pin_OUT;
int LED_Pin_IN;
int A_player_pos[2] ={0,0};
int B_player_pos[2] ={0,0};
int A_pre_player_pos[2] ={0,0};
int B_pre_player_pos[2] ={0,0};
int Player_turn=1;



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
//playermapの変換
const int A_player_transmap[4][4] = {{12,13,14,15},
                               {11,10,9,8},
                               {4,5,6,7},
                               {3,2,1,0}
                               };

const int B_player_transmap[4][4] = {{16,23,24,31},
                               [{17,22,25,30},
                               {18,21,26,29},
                               {19,20,27,28}
                               };                       
                   
//LEDレイアウトを定義
boolean Num_Array[10][7]={
{0,0,0,0,0,0,1}, //0
{1,0,0,1,1,1,1}, //1
{0,0,1,0,0,1,0}, //2
{0,0,0,0,1,1,0}, //3
{1,0,0,1,1,0,0}, //4
{0,1,0,0,1,0,0}, //5
{0,1,0,0,0,0,0}, //6
{0,0,0,1,1,0,1}, //7
{0,0,0,0,0,0,0}, //8
{0,0,0,0,1,0,0} //9
};
