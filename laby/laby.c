
void laby(){
// the void value is what the function returns... in this case void?
// run with arguments or return values? so that's int and return
    // some variables
    
    bool escaped = false;
    char seen = look(forward);
    bool rock = false;
    char map[50][50]; //largest map handled. can I use this syntax?
    int xchord = 24; //initial values, note that the map is based on the
    int ychord = 24; //starting direction of the bug, not necisarily XY.
    
    // to declare that particular map you would use:
    char map[50][50] {{0,0},{0,1}}
    // but we should auto generate various maps
    // each value in the array is a one charecter (IE CHAR)
    // possibly use *pointers to dynamically allocate memory    
    //new functions
    
    void turnaround(){
        right();
        right();
    }
    
    // code starts here:
    
    while(!escaped){
        switch seen
            case Void:
                forward();
                //nav functions?
                break;
            case Rock:
                if (rock == false){
                    take();
                    rock = true;
                }
                //get rid of rock in most situations?
                //now that you have the rock, how does the logic change?
                break;
            case Wall:
                left();
                if (seen != Void){
                    turnaround();
                }
                //this may or may not solve some pipe problems
                break;
            case Web:
                if (rock == true){
                    drop();
                    rock = false;
                }
                // can we have it remember to get a rock? hmmmm
                if (seen == web){
                    left();
                }
            case Exit:
                // one bug, you can't exit with a rock:
                if (rock == true){
                    turnaround();
                    drop();
                    turnaround();
                }
                escape();
                escaped=true; // finish the logic
    }
}