//code for Laby

laby(){
    while(look(forward) == void){
        forward();
        }
    while(){
        switch look(forward)
        
        case void:
            forward();
            break;
        
        case Rock:
            take();
            right();
            right();
            drop();
            right();
            right();
            break;

        case Wall:
            left();
            break;

        case Exit:
            escape();
            break;

    }
}
//Brennen Mazur