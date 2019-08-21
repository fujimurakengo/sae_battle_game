#define  A_player_contlor_x 0
#define  A_player_contlor_y 1
#define  B_player_contlor_x 2
#define  B_player_contlor_y 3


#define  a_led  8
#define  b_led  9
#define  c_led 10
#define  d_led 11
#define  e_led 12
#define  f_led 13
#define  g_led 14

void select_map_possion(int x, int y,int *pos,int *pre_pos,int player_num);
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
                       
