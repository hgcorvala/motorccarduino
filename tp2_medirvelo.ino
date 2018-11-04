//MEDIDOR DE VELOCIDAD
volatile unsigned long contador=0;//Cuento los flancos ascendentes.
unsigned long contador_aux=0;//Cuento los flancos ascendentes.
int ppv=20; //Defino la cantidad de ranuras del encoder

unsigned long t_act=0;
unsigned long t_ant=0;

void setup(){
  Serial.begin(9600);
  attachInterrupt(0,medicion,RISING); //Defino la interrupción 0, pin 2
  Serial.println("Medición de la velocidad");
  Serial.println("Velocidad medida en RPM");  
}

void loop(){
  //delay(1000);//Contamos la cantidad de flancos en 1 segundo
 t_act=micros();
 if(t_act-t_ant>=1000000){
   
   t_ant=t_act;
   contador_aux=contador;
   
   Serial.print ("Velocidad: ");
   Serial.print ((60*contador)/ppv);
   Serial.println ("  rpm");   
   contador=0;
 }
   
}

void medicion(){
  contador++;   
}

