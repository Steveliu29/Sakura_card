#ifndef _CARD_INFO_H_
#define _CARD_INFO_H_
const std::string NAME[52]={"Windy","Shadow","Illusion","Flower","Mist","Storm","Float","Fight","Song","Shot","Sweet","Freeze","Arrow","Light","Twin","Wood","Shield","Power","Loop","Mirror","Big","Change","Firey","Voice","Lock","Cloud","Dark","Watery","Rain","Jump","Silent","Time","Erase","Sleep","Return","Dash","Create","Bubbles","Wave","Sand","Ely","Thunder","Sword","Glow","Move","Little","Maze","Snowy","Through","Dream","Libra","Earthy"};

const std::string 
INS[52]={
"Can cause 1 damage to the target player. Two less-than-three-star defending cards or one element card can dodge this attack. Number of defending cards to dodge combo with Watery/Firey/Earthy card follows the rule in the note. Notice: If a full combo of Watery/Firey/Earthy/Windy is used, the player dies immediately and there is no way to avoid.",
"Cannot be used as defending card for Light and Dark cards. Can be used together with Dark card as scroll card to enter Invisible Status (See Dark below).",
"If the judgement card is in the range of the player's minimum and maximum cards, this player will be skipped for 1 turn. Can be used together with Maze card (see Maze below).",
"Recover 1 hp for the player.",
"No special effect.",
"No special effect.",
"No special effect.",
"No special effect.",
"Recover 1 hp for the player.",
"When the player uses defending card(s), he/she can make a combo attack of Thunder and Shot cards to another player. 2 two-star defending cards are required to dodge. Can be deflected by Mirror (see Mirror below).",
"Recover 1 hp for the player.",
"The target player will skip his/her next turn. Can use Firey card to avoid this effect. Can be used singly to defend Watery card. Can be used together with Rain card to cause 1 damage in the next turn for the target player. No way to avoid.",
"Can be used together with Firey/Watery/Light card as a combo attack. This combo cannot use Mirror card to deflect (see Mirror below).",
"Can cause 2 damage to the target player. Two less-than-three-star defending cards or one element card can dodge this attack. One less-than-three-star defending card lessens 1 damage. Can be used together with Dark card as a combo attack. This combo causes 5 damage and 6 less-than-three-star cards are required to dodge. No Move card is allowed.(See Move below). Can be deflected by Mirror (see Mirror below). Can be used together with Firey card as a combo attack. Number of defending cards to dodge this combo follows the rule in the note.",
"Can be used to draw 2 more cards. Can be used together with other scroll or attacking cards to double the effect (for attacking cards, player can choose to double the damage or to double the number of defending cards to dodge).",
"Can be used singly to defend Earthy card. Cannot be used to defend Firey card.",
"Can be used together with Watery card to defend all kinds of attack except for the Watery/Firey/Windy/Earthy full combo one (see explanation in Windy).",
"No special effect.",
"Specify another player to take over your current turn.",
"Can be used to deflect Light/Firey/Watery/Thunder/Shot/Thunder+Shot attack.",
"Can be used to draw 2 more cards. Can be used together with other scroll or attacking cards to have +1 effect (for attacking cards, player can choose to increase 1 damage or to increase 1 defending card to dodge).",
"Exchange all of your cards with another player's cards.",
"Can cause 1 damage to the target player. Two less-than-three-star defending cards or one element card can dodge this attack. Number of defending cards to dodge combo with Watery/Windy/Earthy card follows the rule in the note. Can be deflected by Mirror card. Can be used together with Sword card as a combo attack. This combo ignores all kinds of defend except for Watery+Shield combo/Time (see Time below)/Return (see Return below)/Invisible Status (see Dark below). Notice: If a full combo of Watery/Firey/Earthy/Windy is used, the player dies immediately and there is no way to avoid.",
"Can be used to invalidate Silent card (see Silent below).",
"No special effect.",
"No special effect.",
"Can cause 2 damage to the target player. Two less-than-three-star defending cards or one element card can dodge this attack. One less-than-three-star defending card lessens 1 damage. Can be used together with Light card as a combo attack. This combo causes 5 damage and 6 less-than-three-star cards are required to dodge. No Move card is allowed.(See Move below). Can be used together with Shadow card to enter Invisible Status for 3 turns. In Invisible Status, player's attacking cards can cause 1 more damage and the number of defending cards to dodge increases by 1. Less-than-three-star attacking cards cannot cause damage and the number of defending cards needed to dodge three-star or higher attacking cards decreases by 1.",
"Can cause 1 damage to the target player. Two less-than-three-star defending cards or one element card can dodge this attack. Note: Can be dodged by 1 Freeze card. No Move card is allowed. Can be deflected by Mirror (see Move and Mirror below). Can be used together with Shield card to defend all kinds of attack except for the Watery/Firey/Windy/Earthy full combo one (see explanation in Windy). Number of defending cards to dodge combo with Earthy/Firey/Earthy card follows the rule in the note. Notice: If a full combo of Watery/Firey/Earthy/Windy is used, the player dies immediately and there is no way to avoid.",
"Can be used together with Freeze card to cause 1 damage in the next turn for the target player. No way to avoid.",
"No special effect.",
"If the judgement card is greater than or equal to the player's minimum card, this player will be skipped for 1 turn. Can be invalidated by Voice card.",
"Can invalidate all time-delayed scroll cards. Can be used together with Return card (see Return below) to get the target player's attacking cards or to replace Nightmare Status (see Dream below) with status caused by Illusion card.",
"Let target player discard 2 cards.",
"Let target player skip his/her next turn. Can be used together with Dream card to make the target player enter Nightmare Status (see Dream below) or to eliminate Judger Status (see Libra below).",
"Can be used to let target player take back his/her attacking card which cannot be used in this turn. Can be used together with Time card (see Return below) to get the target player's attacking cards or to replace Nightmare Status (see Dream below) with status caused by Illusion card. Can be used during judging period to get judgement cards in judging area except for the combo of Freeze and Rain cards.",
"No special effect.",
"Can be used during player's judging period to peek the top card of the deck and decide whether to discard it or not. Cannot be used when there are players in Judger Status (see Libra below).",
"Cannot be used to defend Watery card.",
"Cannot be used to defend Watery card. Can be used singly to defend Firey card.",
"No special effect.",
"Cannot be used to defend Windy card.",
"When the player uses defending card(s), he/she can make a combo attack of Thunder and Shot cards to another player. 2 two-star defending cards are required to dodge. Can be deflected by Mirror.",
"Can be used together with Firey/Watery/Light card as a combo attack which cannot be deflected by Mirror (for Firey and Sword cards combo, see Firey above).",
"After using Loop card for 3 turns, no players can enter invisible status. Can be used singly to defend Dark card. Can be used together with Light card as a combo attack which causes 1 more damage.",
"Can be used to transfer an attack to another specified player. Cannot be used for some kinds of attack (see instructions above). Can be used to transfer 1 card from the player to another specified player.",
"Let target player discard 1 card. Cannot be used with Big/Twin and other defending cards together.",
"If the judgement card is not bigger than the target player's biggest card, the target player will be skipped for 1 turn. Can be used together with Through card (see Through below). Can be used together with Illusion card and the target player will be skipped for 2 turns. Can be eliminated by Through card (see Through below).",
"No special effect.",
"Must be used together with Maze card to defend one-star attacking cards for 3 turns or two-star attacking cards for 2 turns or three-star attacking cards for 1 turn. Cannot be used together with Maze card to defend four-star or higher attacking cards. Can be used to eliminate the status caused by Maze card (see Maze above).",
"Must be used together with Sleep card to enter Nightmare Status. In Nightmare Status, the player cannot be affected by attacking cards and scroll cards. Will enter judging period during the stage when players are drawing cards after a turn. If the number of the judging card is inconsistent with the number offered by the player, the player will die immediately. Can be transferred to Illusion status by the combo of Time and Return cards.",
"Can be used to enter Judger Status immediately and will not exit the status until being affected by Sleep card. In judger status, all time-delayed scroll cards will not take effect on the player except for Sleep card. Can adjust the target player of any time-delayed scroll cards. Can discard one card before entering judging period and peek the top card of the deck to decide whether to discard it or not.",
"Can be defended by one single Tree card. Cannot be defended by Move card. Can cause 1 damage to the target player. Two less-than-three-star defending cards or one element card can dodge this attack. Number of defending cards to dodge combo with Watery/Firey/Windy card follows the rule in the note. Notice: If a full combo of Watery/Firey/Earthy/Windy is used, the player dies immediately and there is no way to avoid."
};

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
const int WOOD=15;
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
