#define led LED_BUILTIN //LED en el pin 13
#define Trigger 7 //Trigger en el pin 7
#define Echo 6 //Echo en el pin 6
void setup(){
  Serial.begin (9600);
  pinMode (led, OUTPUT);
  pinMode (Trigger, OUTPUT); //Define al pin trigger como salida
  pinMode (Echo, INPUT); //define al pin echo como entrada
  digitalWrite (Trigger, LOW); //Se inicializa el pin con
}
void loop (){
  long tiempo; //timepo que se demora en llegar el eco
  long distancia; //distancia viene en centimetros

  // Iniciar la comunicación entre el Trigger y el Echo para ello debemos mandar un pulso de 10 ms
  digitalWrite (Trigger, HIGH); //se envia el pulso al trigger
  delayMicroseconds (10); //tiempo definido por tipo de sensor
  digitalWrite (Trigger, LOW);

  //Encotrar el acho del pulso
  tiempo= pulseIn (Echo, HIGH);
  distancia= tiempo/59; //Se busca la distancia en centiemtros segun el tiempo
  
  if (distancia < 6){ //La distancia en cisterna del agua y el sensor es de 4 centimetros por lo que se ha definido un umbral de 6
    digitalWrite (led, HIGH); //Se  activa la alarma.
  }else{
    digitalWrite (led, LOW); //Alarma desactivada
  }
  
  Serial.print ("Distancia del sensor con nivel del agua: ");
  Serial.print (distancia); //Se manda la impresion de la distancia del sensor con relacion al agua
  Serial.println();
  delay (1000);//se imprime el resultado cada segundo.
}
