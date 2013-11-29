#pragma systemFile

typedef struct{
  short idCiuSalida;
  short sentido;// si es 1 el giro es a la derecha si es -1 el giro a la izquierda.
  int grados;
}Salidas;

typedef struct{
  short x;
  short y;
  short numsalidas;
  char nombre;
  Salidas salida[7];
}Ciudad;

typedef struct{
  short idCiuOri;
  short idCiuDes;
  short costo;
}Ruta;

Ciudad ciudades[7];
Ciudad solucionCiudad[7];
Ruta rutas[9];

int cerrados[7],abiertos[7];
int tamA=0,tamC=0;
int avanceGlobal;
short sentidoGlobal;

int distCiudades(Ciudad &ciuOri,Ciudad &ciuDes){
  return sqrt(((ciuDes.x-ciuOri.x)*(ciuDes.x-ciuOri.x))+((ciuDes.y-ciuOri.y)*(ciuDes.y-ciuOri.y)));
}

int busIndCiuNom(char nom){
  int i=0;
  while(i<7){
    if(ciudades[i].nombre==nom){
      return i;
      break;
    }
  i++;
  }
  return i;
}

int detRuta(int indCiuAct, int indCiuSig){
  int i;
  int ind=-1;
  for(i=0;i<9;i++){
    if((rutas[i].idCiuOri==indCiuAct)&&(rutas[i].idCiuDes==indCiuSig)){
      ind=i;
      break;
    }
    if((rutas[i].idCiuDes==indCiuAct)&&(rutas[i].idCiuOri==indCiuSig)){
      ind=i;
      break;
    }
  }
  return ind;
}

int funcEval(int indCiuDes){
  int i=0;
  int indMen=0;
  int fAct=0, fAnt=0;
  int cosAct=0, cosAnt=0;
  while(i<tamA){
    if(tamC>0){
      cosAct=rutas[detRuta(cerrados[tamC-1],abiertos[i])].costo;
      cosAnt=rutas[detRuta(cerrados[tamC-1],abiertos[indMen])].costo;
    }
    fAct=distCiudades(ciudades[abiertos[i]],ciudades[indCiuDes])+cosAct;
    fAnt=distCiudades(ciudades[abiertos[indMen]],ciudades[indCiuDes])+cosAnt;
    if(fAct<fAnt){
      indMen=i;
    }
    i++;
  }
  return abiertos[indMen];
}

bool abiertosContiene(int indAbi){
  int i;
  for(i=0;i<tamA;i++){
    if(abiertos[i]==indAbi){
      return true;
    }
  }
  return false;
}

bool cerradosContiene(int indCer){
  int i;
  for(i=0;i<tamC;i++){
    if(cerrados[i]==indCer){
      return true;
    }
  }
  return false;
}

void expandirAbiertos(int indCiu){
  int i,j=0;
  for(i=0;i<9;i++){
    if(rutas[i].idCiuOri==indCiu){
      if(!abiertosContiene(rutas[i].idCiuDes)&&!cerradosContiene(rutas[i].idCiuDes)){
        abiertos[j]=rutas[i].idCiuDes;
        j++;
      }
    }
    if(rutas[i].idCiuDes==indCiu){
      if(!abiertosContiene(rutas[i].idCiuOri)&&!cerradosContiene(rutas[i].idCiuOri)){
        abiertos[j]=rutas[i].idCiuOri;
        j++;
      }
    }
  }
  tamA=j;
}

void detMejorRecorrido(int indCiuOri, int indCiuDes){
  string resultado="";
  abiertos[tamA]=indCiuOri;
  tamA=tamA+1;
  do{
    if(tamA==0){
      resultado="Camino no encontra.";
      break;
    }
    cerrados[tamC]=funcEval(indCiuDes);
    tamC=tamC+1;
    if(cerrados[tamC-1]==indCiuDes){
      resultado="Camino encontrado";
    }
    expandirAbiertos(cerrados[tamC-1]);
  }while(cerrados[tamC-1]!=indCiuDes);

  eraseDisplay();
  nxtDisplayCenteredTextLine(3,resultado);
  wait1Msec(2000);
}
