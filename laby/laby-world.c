//the laby physics engine
//remind me to write this in python >.<
#include <stdio.h>
#include <laby.c> //your project. an example at [laby.md]
int environment.x=25;
int environment.y=25;
int environment.ants=3;
int environment.exits=3;
int environment.area=environment.x * environment.y;
float environment.rocks=.1;
float enviornment.webs=.1;
extern char map[environment.x][environment.y];//declare map, remember map values: V E A B W R;
int main(){
    //predefined functions:
    early-bird(minion,passive-active){
        for (var current-ant=0;current-ant<ant[$];current-ant++){
            //exit the lowest ants first
            //wait for arg from ant[minion somehow]
        }
    }
    char get-element-max(counter){
        switch counter
            case 0:tile="A";element_max=environment.ants;break;
            case 1:tile="E";element_max=environment.exits;break;
            case 2:tile="R";element_max=environment.area * environment.rocks;break;
            case 3:tile="W";element_max=environment.area * environment.webs;break;
            case 4:tile="B";element_max=magic-ratio;break;//how to determine?
            case 5:tile="V";element_max=magic-ratio;break;//how should this be determined?
        return tile;
    }
    void random-orient-ant(ant[minion]){
        //generate random int x 0-3: (rand % 4)
        switch x
            case 0: random-orientation="N"; break;
            case 1: random-orientation="E"; break;
            case 2: random-orientation="S"; break;
            case 3: random-orientation="W"; break;
        ant.orientation = random-orientation;
        early-bird(ant[minion]"PASS");
        look();
    }
    char look(){
        switch ant.orientation //this switch also removes .orientation errors
            case 'N':manipulate=map[ant.x][ant.y-1];manipulate.x=ant.x;manipulate.y=ant.y-1;break;
            case 'E':manipulate=map[ant.x+1][ant.y];manipulate.x=ant.x+1;manipulate.y=ant.y;break;
            case 'S':manipulate=map[ant.x][ant.y+1];manipulate.x=ant.x;manipulate.y=ant.y+1;break;
            case 'W':manipulate=map[ant.x-1][ant.y];manipulate.x=ant.x-1;manipulate.y=ant.y;break;
            default:printf("look doesn't actually know which way you're pointing >.< I'll point you randomly, eh?");random-orient-ant();break;
        return manipulate; // V E A B W R NULL
    }
    void left(){
        switch ant.orientation
            case 'N':ant.orientation='W';break;
            case 'E':ant.orientation='N';break;
            case 'S':ant.orientation='E';break;
            case 'W':ant.orientation='S';break;
        early-bird(ant[minion],"PASS");
        look();
    }
    void right(){
        switch ant.orientation
            case 'N':ant.orientation='E';break;
            case 'E':ant.orientation='S';break;
            case 'S':ant.orientation='W';break;
            case 'W':ant.orientation='N';break;
        early-bird(ant[minion],"PASS");
        look();
    }
    void take(){
        early-bird(ant[minion],"FIGHT");
        if (!ant.has-rock){
            if (manipulate == "R"){
                map[manipulate.x][manipulate.y]="V";
                ant.has-rock=true;
            }
            else{
                printf("there's no rock here!");
            }
        }
        else{
            printf("I already have a rock!");
        }
        look();
    }
    void drop(){
        early-bird(ant[minion],"FIGHT");
        if (ant.has-rock){
            if (manipulate == "V"||"W"){
                map[manipulate.x][manipulate.y]="R";
                ant.has-rock=false;
            }
            else{
                printf("I can't drop it here!");
            }
        }
        else{
            printf("I have no rock to drop!");
        }
        look();
    }
    void escape(){
        early-bird(ant[minion],"FIGHT");
        if (manipulate == "E"){
            if (!ant.has-rock){
                map[ant.x][ant.y]="V";
                map[manipulate.x][manipulate.y]="A";
                ant.x=manipulate.x;
                ant.y=manipulate.y;
                ant.escaped=true;
            }
            else{
                printf("I can't escape with rocks");
            }
        }
        else{
            printf("I can't escape here!");
        }
        look();
    }
    void forward(){
        early-bird(ant[minion],"FIGHT");
        if (manipulate == "V" || "W"){
            map[ant.x][ant.y]="V";
            map[manipulate.x][manipulate.y]="A";
            ant.x=manipulate.x;
            ant.y=manipulate.y;
            ant.moves++;
        }
        switch manipulate
            case 'V':break;
            case 'R':printf("I cant go through a rock!");break;
            case 'W':printf("A web! I'm stuck!");ant.stop=true;break;
            case 'E':printf("I can't go through an exit!");break;
            case 'B':printf("I can't go through a brick!");break;
            case 'A':printf("Woa! it's an Ant!");break;
            default :printf("I have no clue what this is xD");break;
        look();
    }
    //actual map generation && execution
    for(var i=0;i<5;i++){//randomly place elements
        tile=(get-element-max(i));
        int generated=0;
        while(generated<element_max){
            /*generate random numbers*/
            if (map[randx][randy]!=void){
                map[randx][randy]=tile;
                    if (tile="A"){
                        ant.x=[randx];
                        ant.y=[randy];
                    }
                generated++;
            }
        }
    }
    for (int minion=0;minion<environment.ants;minion++){//generate the ants
        random-orient-ant(ant[minion]);
        ant[minion].has-rock=false;
        ant[minion].x=;
        ant[minion].y=;
    }
    "IMPORTANT CODE / strong solver"
    after solving, determine IF:
    * ant has access to voids [true/false]
    * ant has access to rocks [true/false]
    * ant has access to webs [true/false]
    * ant has access to exits [true(printf("ESCAPABLE!"))/false(printf("SLENDER!"))]
    starting square paradigm? use the ants[0] index idea?
        * navigate cardinally grabbing only possible array values?
    * determine if grid values solve directly to exit(ant, void, rock, exit)
    * else determine if rocks solve to ants (ant, void, rock)
       * determine if ants now solve to exits through webs (ant, void, rock, web, exit)
       
    //grab cell values from all cardinal sides of ant:
        //calculate routes ants can take to exits
        //if any cardinal value is void rock or exit that value on the map is solveable;
        //if and only if a cardinal web value is paired with a rock value can it be solved
        //evaluate each solveable cardinal value of each instance (don't let the code run forever)
        //if after a complete scan of all neiboring cells there is no solution, printf("SLENDER!");
    for(int y=0;y<environment.y;y++){
        for(int x=0;x<environment.x;x++){//these for loops should kinda scan the entire field
        }
    }
    ants(){
        ant.escaped==false;
        look();
        laby();//break out of it or wait for it to finish? how to run multiple ants at once?
        if (ant.escaped == true){
            printf("laby code was a SUCCESS");
        }
        else{
            printf("laby code FAILED");
        }
    }
}