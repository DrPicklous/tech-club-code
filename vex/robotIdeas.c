#include Main.h
float powerfactor
powerfactor=vexRT[ch2] / 127;
task main() {
  while (1 == 1){
    //base
    motor[port1] = floor(powerfactor * vexRT[ch1]) + vexRT[ch4];
    motor[port3] = floor(powerfactor * vexRT[ch1]) + vexRT[ch4];
    motor[port2] = floor(-powerfactor * vexRT[ch1]) - vexRT[ch4];
    motor[port4] = floor(-powerfactor * vexRT[ch1]) - vexRT[ch4];
    //pull
    if (vexRT[btn6U] == 1){
      motor[port5] = 127;
      motor[port6] = -127;
    }else if (vexRT[btn6D] == 1){
      motor[port5] = -127;
      motor[port6] = 127;
    }else {
      motor[port5] = 0;
      motor[port6] = 0;
    }
    //up
    if (vexRT[btn5U] == 1){
      motor[port7] = 127;
    }else if (vexRT[btn5D] == 1){
      motor[port7] = -127;
    }else {
      motor[port7] = 0;
    }
  }
}
