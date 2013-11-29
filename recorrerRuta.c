#pragma config(Sensor, S3,     senluz3,             sensorLightActive)
#pragma config(Sensor, S4,     senluz4,             sensorLightActive)
#pragma systemFile

void recorrerRuta(int valorMedio){
  while(SensorValue(senluz3)>valorMedio || SensorValue(senluz4)>valorMedio){
    if(SensorValue(senluz3)>valorMedio && SensorValue(senluz4)>valorMedio){
      motor[motorB]=25;
      motor[motorC]=25;
    }
	  else{

	     if(SensorValue(senluz4)<valorMedio){
	        motor[motorB]=25;
	        motor[motorC]=0;
	    }

	    if(SensorValue(senluz3)<valorMedio){
	      motor[motorC]=25;
	      motor[motorB]=0;
	    }
	  }
	}
}
void Girar(short grados,short sentido){
	nMotorPIDSpeedCtrl[motorC] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[motorB] = mtrSpeedReg;
	double indiceGrados = 2;
	int giro =  indiceGrados*grados;
	nMotorEncoder[motorC] = 0;
	nMotorEncoder[motorB] = 0;
	if(sentido==1){
	while(nMotorEncoder[motorC] <giro) {
	motor[motorC] = 20;
	motor[motorB] = -20;
	}
	}else{
		  while(nMotorEncoder[motorB] <giro) {
			motor[motorC] = -20;
			motor[motorB] = 20;
		  }
	   }
}

void avanzar(int avance){
     nMotorEncoder[motorC] = 0;
     nMotorEncoder[motorB] = 0;
		while(nMotorEncoder[motorB] < avance) {
					motor[motorC] = 20;
					motor[motorB] = 20;
				  }

}
