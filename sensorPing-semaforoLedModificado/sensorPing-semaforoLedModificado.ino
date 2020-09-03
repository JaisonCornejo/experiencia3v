/*
   ################
   #   Lab15125   #
   ################
 
   Este codigo tiene como objetivo dar muestra de un uso practico de:
   Sensor ultrasonico ping (parallax)

   Según la hoja de datos de Parallax para el PING))), 
   hay 73,746 microsegundos por pulgada o 29,034 microsegundos por centimetro 
   (es decir, el sonido viaja a 1130 pies (o 34442.4cm) por segundo). 
   Este da la distancia recorrida por el ping, ida y vuelta, 
   por lo que dividimos por 2 para obtener la distancia del obstáculo.
   ver: 
   https://www.parallax.com/sites/default/files/downloads/28015-PING-Sensor-Product-Guide-v2.0.pdf
        [En el PDF: TO_IN = 73_746' Inches ; TO_CM = 29_034' Centimeters ]

   El circuito:
     * +V conectado a sensor PING))) en +5V
     * GND conectado a sensor PING))) en GND (ground)
     * SIG conectado a sensor PING))) en pin digital 7
     * LED conectado a pin 9 (PWM)

   Funcion
   readUltrasonicDistance(int triggerPin, int echoPin): Referencia obtenida de sensor ultrasonico tinkercad.com
*/


/*
Inicio declaracion funcion readUltrasonicDistance
*/
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Inicializar LOW para limpiar trigger por 2 microsegundos
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Inicializar trigger en HIGH por 8 microsegundos para comenzar
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // lectura de pin echo con el retorno de la señal
  return pulseIn(echoPin, HIGH);
}
/*
Fin declaracion funcion readUltrasonicDistance
*/


/*
Inicio funcion setup
*/
void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT); /* Se define pin 8 Salida (LED VERDE) */
  pinMode(5, OUTPUT); /* Se define pin 7 Salida (LED AMARILLO) */
  pinMode(2, OUTPUT); /* Se define pin 4 Salida (LED ROJO) */
}
/*
Fin funcion setup
*/


/*
Inicio funcion loop
*/
void loop()
{
  float distancia = 0.01723 * readUltrasonicDistance(2, 2);

  if((distancia <= 333) && (distancia >= 200)) { /*si la distancia se encuentra entre 333 cm y 200 cm se enciende led Verde */
    digitalWrite(4, HIGH);
  } 
  else {
    digitalWrite(4, LOW); /* de lo contrario se apaga */
  }
  if((distancia < 200) && (distancia >= 100)) { /*si la distancia se encuentra entre 200 cm y 100 cm se enciende led Amarillo*/
    digitalWrite(7, HIGH);
  } 
  else {
    digitalWrite(7, LOW); /* de lo contrario se apaga */
  }
  if(distancia < 100) { /*si la distancia se encuentra inferior a 100 cm se enciende led Rojo */
    digitalWrite(8, HIGH);
  } 
  else {
    digitalWrite(8, LOW);/* de lo contrario se apaga */ 
  }

  Serial.print("Distancia:"); /* Se imprimie en pantalla la palabra distancia y luego se presenta en pantalla el valor distancia corregida)*/
  Serial.println(1.8+distancia);

  delay(10); /* Delay a little bit to improve simulation performance */
}
