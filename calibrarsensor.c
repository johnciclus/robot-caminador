#pragma config(Sensor, S1,     senImpacto,          sensorTouch)
#pragma config(Sensor, S3,     senluz3,             sensorLightActive)
#pragma config(Sensor, S4,     senluz4,             sensorLightActive)
#pragma systemFile

int calibrarsensor(){
  int valorOscuro;
  int valorMedio;
  int valorClaro;
  while(SensorValue(senImpacto)==0){
    nxtDisplayCenteredTextLine(1,"Luz Clara:");
    nxtDisplayCenteredTextLine(4,"Sensor luz 3= %d",SensorValue(senluz3));
    nxtDisplayCenteredTextLine(5,"Sensor luz 4= %d",SensorValue(senluz4));
    }
  valorClaro = (SensorValue(senluz3));
  eraseDisplay();
  nxtDisplayCenteredTextLine(4,"Luz clara: %d:",valorClaro);
  wait1Msec(2000);
  while(SensorValue(senImpacto)==0){
    nxtDisplayCenteredTextLine(1,"Luz Oscura:");
    nxtDisplayCenteredTextLine(4,"Sensor luz 3= %d",SensorValue(senluz3));
    nxtDisplayCenteredTextLine(5,"Sensor luz 4= %d",SensorValue(senluz4));
    }
  valorOscuro = (SensorValue(senluz3));
  eraseDisplay();
  nxtDisplayCenteredTextLine(4,"Luz oscura: %d:",valorOscuro);
  wait1Msec(2000);
  valorMedio = (valorClaro + valorOscuro)/2;
  eraseDisplay();
  nxtDisplayCenteredTextLine(4,"Umbral: %d",valorMedio);
  wait1Msec(2000);
  return valorMedio;
 }
