#pragma config(Sensor, S1,     senImpacto,          sensorTouch)
#pragma config(Sensor, S3,     senluz3,             sensorLightActive)
#pragma config(Sensor, S4,     senluz4,             sensorLightActive)
#include "calibrarsensor.c"
#include "mapa.c"
#include "recorrerRuta.c"

#pragma systemFile

task main(){
  ciudades[0].x=9;
  ciudades[0].y=51;
  ciudades[0].nombre='A';
  ciudades[0].numsalidas=2;
      ciudades[0].salida[1].idCiuSalida=1;  // De A hacia B
      ciudades[0].salida[1].grados=50;
      ciudades[0].salida[1].sentido=-1;     //a izquierda
      ciudades[0].salida[2].idCiuSalida=2;  // de A hacia C
      ciudades[0].salida[2].grados=50;
      ciudades[0].salida[2].sentido=1;      //a la derecha

  ciudades[1].x=57;
  ciudades[1].y=88;
  ciudades[1].nombre='B';
  ciudades[1].numsalidas=3;
			ciudades[1].salida[0].idCiuSalida=0;  // De B hacia A
			ciudades[1].salida[0].grados=130;
			ciudades[1].salida[0].sentido=1;
			ciudades[1].salida[3].idCiuSalida=3;  // De B hacia D
      ciudades[1].salida[3].grados=50;
      ciudades[1].salida[3].sentido=1;
      ciudades[1].salida[4].idCiuSalida=4;  // De B hacia E
      ciudades[1].salida[4].grados=0;
      ciudades[1].salida[4].sentido=1;

  ciudades[2].x=54;
  ciudades[2].y=13;
  ciudades[2].nombre='C';
  ciudades[2].numsalidas=3;
		  ciudades[2].salida[0].idCiuSalida=0;  //De C hacia A
		  ciudades[2].salida[0].grados=130;
      ciudades[2].salida[0].sentido=-1;
      ciudades[2].salida[3].idCiuSalida=3;  //De C hacia D
      ciudades[2].salida[3].grados=60;
      ciudades[2].salida[3].sentido=-1;
      ciudades[2].salida[5].idCiuSalida=5;  //De C hacia F
      ciudades[2].salida[5].grados=0;
      ciudades[2].salida[5].sentido=-1;

  ciudades[3].x=74;
  ciudades[3].y=53;
  ciudades[3].nombre='D';
  ciudades[3].numsalidas=4;
		  ciudades[3].salida[1].idCiuSalida=1;  // De D hacia B
		  ciudades[3].salida[1].grados=125;
      ciudades[3].salida[1].sentido=-1;
      ciudades[3].salida[2].idCiuSalida=2;  // De D hacia C
      ciudades[3].salida[2].grados=125;
      ciudades[3].salida[2].sentido=1;
      ciudades[3].salida[6].idCiuSalida=6;  // De D hacia G
      ciudades[3].salida[6].grados=45;
      ciudades[3].salida[6].sentido=1;
		  ciudades[3].salida[4].idCiuSalida=4;  // De D hacia E
		  ciudades[3].salida[4].grados=45;
      ciudades[3].salida[4].sentido=-1;

  ciudades[4].x=119;
  ciudades[4].y=87;
  ciudades[4].nombre='E';
  ciudades[4].numsalidas=2;
		  ciudades[4].salida[2].idCiuSalida=2; // De E hacia B
		  ciudades[4].salida[2].grados=180;
      ciudades[4].salida[2].sentido=1;
      ciudades[4].salida[3].idCiuSalida=3; // De E hacia D
      ciudades[4].salida[3].grados=120;
      ciudades[4].salida[3].sentido=1;

  ciudades[5].x=92;
  ciudades[5].y=13;
  ciudades[5].nombre='F';
  ciudades[5].numsalidas=2;
		  ciudades[5].salida[6].idCiuSalida=6;  //De F hacia G
		  ciudades[5].salida[6].grados=45;
      ciudades[5].salida[6].sentido=-1;
      ciudades[5].salida[2].idCiuSalida=2; // De F hacia C
   	  ciudades[5].salida[2].grados=180;
      ciudades[5].salida[2].sentido=-1;

  ciudades[6].x=118;
  ciudades[6].y=35;
  ciudades[6].nombre='G';
  ciudades[6].numsalidas=2;
		  ciudades[6].salida[5].idCiuSalida=5;  // De G hacia D
		  ciudades[6].salida[5].grados=135;
      ciudades[6].salida[5].sentido=-1;
      ciudades[6].salida[3].idCiuSalida=3;  // De G hacia F
      ciudades[6].salida[3].grados=120;
      ciudades[6].salida[3].sentido=-1;

  rutas[0].idCiuOri=0;
  rutas[0].idCiuDes=1;
  rutas[0].costo=50;

  rutas[1].idCiuOri=0;
  rutas[1].idCiuDes=2;
  rutas[1].costo=70;

  rutas[2].idCiuOri=1;
  rutas[2].idCiuDes=3;
  rutas[2].costo=42;

  rutas[3].idCiuOri=1;
  rutas[3].idCiuDes=4;
  rutas[3].costo=70;

  rutas[4].idCiuOri=2;
  rutas[4].idCiuDes=3;
  rutas[4].costo=60;

  rutas[5].idCiuOri=2;
  rutas[5].idCiuDes=5;
  rutas[5].costo=38;

  rutas[6].idCiuOri=3;
  rutas[6].idCiuDes=4;
  rutas[6].costo=50;

  rutas[7].idCiuOri=3;
  rutas[7].idCiuDes=6;
  rutas[7].costo=45;

  rutas[8].idCiuOri=5;
  rutas[8].idCiuDes=6;
  rutas[8].costo=37;

  int indCiuOri=busIndCiuNom('A');
  int indCiuDes=busIndCiuNom('G');

  detMejorRecorrido(indCiuOri,indCiuDes);
  eraseDisplay();
  nxtDisplayCenteredTextLine(1,"Camino inferido");
  int i;
  for(i=0;i<tamC;i++){
    nxtDisplayCenteredTextLine(i+3,"*  %d : %c  *",cerrados[i],ciudades[cerrados[i]].nombre);
  }
  wait1Msec(2000); //Solucion guardada en cerrado


  eraseDisplay();
  int valorMedio=calibrarsensor();

  /////////////////////////////////////////////////////////////////////////////// parte fisica

    eraseDisplay();
    nxtDisplayCenteredTextLine(4,"Ciudad: %c:",ciudades[cerrados[0]].nombre);
    avanceGlobal=84;    //verificar avance en cm
    avanzar(avanceGlobal);

   Girar(ciudades[cerrados[0]].salida[cerrados[1]].grados , ciudades[cerrados[0]].salida[cerrados[1]].sentido);

			  for( i=0;i<=tamC-1;i++) //verificar tamc
			  {
			    while(SensorValue(senluz3)<valorMedio && SensorValue(senluz4)<valorMedio&& i<tamC-1)
			    {
			    avanceGlobal=12;
			    avanzar(avanceGlobal);
			    }
			    while(SensorValue(senluz3)>valorMedio && SensorValue(senluz4)>valorMedio && i<tamC-1)
			    {
			    girar(10,-1);
			    }
			    while(SensorValue(senluz3)>valorMedio && SensorValue(senluz4)>valorMedio)
			    {
			    girar(10,1);
			    }

			    recorrerRuta(valorMedio);
			     if(i<tamC-1){
			       eraseDisplay();
			    nxtDisplayCenteredTextLine(4,"Ciudad: %c:",ciudades[cerrados[i+1]].nombre);
			              }
			    avanceGlobal=48;
			    avanzar(avanceGlobal);
			    if((ciudades[cerrados[i]].salida[cerrados[i+1]].grados) > 0)
			                   {
			                sentidoGlobal = (ciudades[cerrados[i]].salida[cerrados[i+1]].sentido)*-1;
			              	Girar((90 - (ciudades[cerrados[i]].salida[cerrados[i+1]].grados)),sentidoGlobal); // ubicar norte.
			                   }
			         if(i<tamC-1){
			       Girar(ciudades[cerrados[i+1]].salida[cerrados[i+2]].grados , ciudades[cerrados[i+1]].salida[cerrados[i+2]].sentido);
			       avanceGlobal=24;
			       avanzar(avanceGlobal)
			                   }
			  }


    /*/
  avanceGlobal=80;
  avanzar(avanceGlobal);
  Girar(ciudades[0].salida[0].grados , ciudades[0].salida[0].sentido);
  recorrerRuta(valorMedio);
  eraseDisplay();
  nxtDisplayCenteredTextLine(4,"Ciudad: %c:",ciudades[2].nombre);
  avanzar(avanceGlobal);
  if((ciudades[0].salida[0].grados) > 0)
                   {
                sentidoGlobal = (ciudades[0].salida[0].sentido)*-1;
              	Girar((90 - (ciudades[0].salida[0].grados)),sentidoGlobal); // ubicar norte.
                   }

 Girar(ciudades[1].salida[1].grados , ciudades[1].salida[1].sentido);
 recorrerRuta(valorMedio);
 eraseDisplay();
 nxtDisplayCenteredTextLine(4,"Ciudad: %c:",ciudades[5].nombre);
  avanzar(avanceGlobal);
  if(ciudades[1].salida[1].grados>0)
                   {
                sentidoGlobal = (ciudades[1].salida[1].sentido)*-1;
              	Girar((90 - (ciudades[1].salida[1].grados)),sentidoGlobal); // ubicar norte.
                   }

 Girar(ciudades[3].salida[3].grados , ciudades[3].salida[3].sentido);
 recorrerRuta(valorMedio);

 nxtDisplayCenteredTextLine(4,"Ciudad Final!!: %c:",ciudades[6].nombre);
 avanzar(avanceGlobal);
 /*/
}
