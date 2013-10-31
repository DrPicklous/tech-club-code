// mainConvert.c : implementation file
#include "Main.h"
float xaxis;
float yaxis;
float axaxis;
float ayaxis;
float lt;
float ls;
float rt;
float rs;
float tu;
float td;
float tl;
float tr;
float b1;
float b2;
float b3;
float b4;
float xplimit;
float xnlimit;
float bateryV;
int dis;
int gyro;
int rotation;
int gyroP;
int shift;
int rotationP;
int cal = 0;
int scal = 0;
int close = 0;


void mainConvert(void){
 

 yaxis = GetJoystickAnalog( 1 , 3 ) ;
 xaxis = GetJoystickAnalog( 1 , 4 ) ;
 axaxis = GetJoystickAnalog( 1 , 1 ) ;
 ayaxis = GetJoystickAnalog( 1 , 2 ) ;
 lt = GetJoystickDigital ( 1 , 5 , 2 ) ;
 ls = GetJoystickDigital ( 1 , 5 , 1 ) ;
 rt = GetJoystickDigital ( 1 , 6 , 2 ) ;
 rs = GetJoystickDigital ( 1 , 6 , 1 ) ;
 tu = GetJoystickDigital ( 1 , 7 , 2 ) ;
 td = GetJoystickDigital ( 1 , 7 , 1 ) ;
 tl = GetJoystickDigital ( 1 , 7 , 3 ) ;
 tr = GetJoystickDigital ( 1 , 7 , 4 ) ;
 b1 = GetJoystickDigital ( 1 , 8 , 1 ) ;
 b2 = GetJoystickDigital ( 1 , 8 , 3 ) ;
 b3 = GetJoystickDigital ( 1 , 8 , 2 ) ;
 b4 = GetJoystickDigital ( 1 , 8 , 4 ) ;
 bateryV = GetMainBattery ( ) ; 
 rotation = GetQuadEncoder ( 5 , 6 ) ;  
 gyro = GetGyroAngle ( 1 ) ; 
///*

if(cal == 0){

if(gyro < 1408){
SetMotor ( 6 , 120 ) ; 
Wait ( 1600 ) ;

SetMotor ( 6 , 20 ) ;

}

cal = 1;


scal = 1;
}
if(scal == 1){
StartQuadEncoder ( 5 , 6 , 0 ) ;
scal =0;
}
//*/

if(b4 == 1){
shift = 3;
}else{
shift = 1;
}

 
if(bateryV >= 7.5){
SetDigitalOutput ( 10 , 1 ) ;
}
SetDigitalOutput ( 12 , 0 ) ; 
//dis = GetUltrasonic ( 8 , 9 ) ;  
//PrintToScreen ( "%d\n" , dis ) ; 
//PrintToScreen ( "%d\n" , gyro ) ;
//PrintToScreen ( "%d\n" , rotation) ;
//Wait ( 500 ) ; 
if(axaxis <= 20 && axaxis >= -20){
Arcade4 ( 1 , 3 , 4 , 2 , 3 , 4 , 5 , 0 , 0 , 0 , 0 ) ; 
SetDigitalOutput ( 12 , 1 ) ;
}


if(axaxis >= 20 || axaxis <= -20){
SetDigitalOutput ( 12 , 1 ) ;

SetMotor ( 2 , axaxis ) ;
SetMotor ( 3 , axaxis ) ;
SetMotor ( 4 , axaxis * -1) ;
SetMotor ( 5 , axaxis * -1) ;
// input1 + input2 = xplimit
// imput1 - input2 = xnlimit
}
if(rs == 1){
SetMotor ( 6 , 127/shift) ;
//gyroP = gyro;
rotationP = rotation;
}
else if(rt == 1){
SetMotor ( 6 , -127/shift) ;
//gyroP = gyro;
rotationP = rotation;
}
else{
SetMotor ( 6 , 0) ;
}



if(ls == 1){
SetMotor ( 7 , 127) ;
close = 0;
}
else if(lt == 1){
SetMotor ( 7 , -127) ;
close = 1;
} 
else if(close == 1){
SetMotor ( 7 , -50) ;
}else{
SetMotor ( 7 , 0) ;
}



if(rs == 0 && rt == 0){






if(rotation < rotationP){
SetMotor ( 6 , -20) ;
}else if(rotation > rotationP){
SetMotor ( 6 , 20) ;
}


}





}



















