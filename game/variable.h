#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

#define sHeight 705
#define sWidth 500
int cnt = 0;

char menupage[50] = "image//menupage.bmp";
int egg[500];
int over[500];
int background[500];
int chicken[500];
int stool[1000];

//chickens
int dp = 2;			//to control chicken 1s movement about x axis
int dq = 2;			//to control chicken 1s movement about y axis
int da = 2;			//to control chicken 2s movement about x axis
int db = 2;			//to control chicken 2s movement about y axis
int de = 2;			//to control chicken 3s movement about x axis
int df = 2;			//to control chicken 3s movement about y axis

int drop = 1;
bool isGameOver = false;		//when we miss a regular egg
bool isGameOver1 = false;		//when we catch a dark egg

//eggs
int dm = 3;
int dn = 4;
int dk = 2;
//stool
int ds = 2;

char basket[100] = "image//game//basket1.bmp";

bool game = false;//flag to start game
//basket co-ordinates
int basketx = 250;
int baskety = 30;

int n = 7; //flag for multiple option choice in menu

//initialization of the positions of the chickens
int chicken1_x = 250;
int chicken1_y = 550;
int chicken2_x = 200;
int chicken2_y = 500;
int chicken3_x = 300;
int chicken3_y = 400;

//initialization of the positions of the regular egg
int egg_x = chicken1_x + 40;
int egg_y = chicken1_y - 30;

//initialization of the positions of the black egg
int egg1_x = chicken2_x + 40;
int egg1_y = chicken2_y - 30;

//initialization of the positions of the bonus egg
int egg2_x = chicken3_x + 40;
int egg2_y = chicken3_y - 30;

//initialization of the positions of the stools
int stool_x = chicken1_x + 40;
int stool_y = chicken1_y - 30;

int score = 0;  //initial score
char SCORE[1000];
int bonus = 0;	//bonus egg score
char BONUS[1000];
int minus_point = 0;	//score decrease for stool
char MINUS[1000];
int total = 0;	//total score calculating all scoring system
char TOTAL[1000];
int final_s, high_s;  //final score after the game finnishes and highscore
char HIGH[1000];

//music
bool musicOn = true;

void getHigh();
void showHigh();


#endif // VARIABLE_H_INCLUDED
