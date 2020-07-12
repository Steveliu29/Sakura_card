#ifndef _CARD_INFO_H_
#define _CARD_INFO_H_
const std::string NAME[52]={"Windy","Shadow","Illusion","Flower","Mist","Storm","Float","Fight","Song","Shot","Sweet","Freeze","Arrow","Light","Twin","Tree","Shield","Power","Loop","Mirror","Big","Change","Firey","Voice","Lock","Cloud","Dark","Watery","Rain","Jump","Silent","Time","Erase","Sleep","Return","Dash","Create","Bubbles","Wave","Sand","Ely","Thunder","Sword","Glow","Move","Little","Maze","Snowy","Through","Dream","Libra","Earthy"};

const std::string INS[52];

const int WINDY=0;
const int SHADOW=1;
const int ILLUSION=2;
const int FLOWER=3;
const int MIST=4;
const int STROM=5;
const int FLOAT=6;
const int FIGHT=7;
const int SONG=8;
const int SHOT=9;
const int SWEET=10;
const int FREEZE=11;
const int ARROW=12;
const int LIGHT=13;
const int TWIN=14;
const int TREE=15;
const int SHIELD=16;
const int POWER=17;
const int LOOP=18;
const int MIRROR=19;
const int BIG=20;
const int CHANGE=21;
const int FIREY=22;
const int VOICE=23;
const int LOCK=24;
const int CLOUD=25;
const int DARK=26;
const int WATERY=27;
const int RAIN=28;
const int JUMP=29;
const int SILENT=30;
const int TIME=31;
const int ERASE=32;
const int SLEEP=33;
const int RETURN=34;
const int DASH=35;
const int CREATE=36;
const int BUBBLES=37;
const int WAVE=38;
const int SAND=39;
const int ELY=40;
const int THUNDER=41;
const int SWORD=42;
const int GLOW=43;
const int MOVE=44;
const int LITTLE=45;
const int MAZE=46;
const int SNOWY=47;
const int THROUGH=48;
const int DREAM=49;
const int LIBRA=50;
const int EARTHY=51;

const int ATTACK[52]={3,0,1,0,2,2,0,1,0,1,0,0,1,4,0,0,0,1,0,0,0,0,3,0,0,2,4,3,2,0,0,0,0,0,0,0,1,0,0,1,0,2,1,0,0,0,0,2,0,0,0,3};//0 when the card cannot be used as an attack card
const int DEFEND[52]={3,2,2,0,2,0,1,0,0,0,0,2,0,3,0,2,2,0,0,-1,0,0,3,0,2,2,3,3,0,1,0,5,0,0,5,1,2,1,2,0,1,0,0,-1,-1,-2,0,0,0,0,0,3};//0 when the card cannot be used as a defend card, -1 when the card is a special defend card, -2 when the card is "the little"

#endif
