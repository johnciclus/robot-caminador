task main(){
 nMotorEncoder[motorC] = 0;
     nMotorEncoder[motorB] = 0;
     //para moverse 10cm necesita 120
		while(nMotorEncoder[motorB] < 17) {
					motor[motorC] = 20;
					motor[motorB] = 20;
				  }



}
