/*------ Seguidor de Lineas Basico ----- */
/*------ Definamos lo pines de arduino que vamos a utilizar -----*/
#define sensor_izquierdo 2  // sensor izquierdo
#define sensor_derecho 3    // sensor derecho
#define motor_izquierdo_1 5 // motor izquierdo
#define motor_izquierdo_2 4 // motor izquierdo
#define motor_derecho_1 7   // motor derecho
#define motor_derecho_2 6   // motor derecho

/*variables internas*/
int sensor_izquierdo_estado;
int sensor_derecho_estado;

/*------ Configuramos Ardunio segun nuestro esquema -----*/
void setup()
{
  pinMode(sensor_izquierdo, INPUT);
  pinMode(sensor_derecho, INPUT);
  pinMode(motor_izquierdo_1, OUTPUT);
  pinMode(motor_izquierdo_2, OUTPUT);
  pinMode(motor_derecho_1, OUTPUT);
  pinMode(motor_derecho_2, OUTPUT);

  Serial.begin(9600);
  delay(3000);
  Serial.println("Configuración completa");
}
/*------ Ponemos a correr el programa que controla el seguidor de lineas -----*/
void loop()
{
  sensor_izquierdo_estado = !digitalRead(sensor_izquierdo);
  sensor_derecho_estado = !digitalRead(sensor_derecho);

  Serial.print("derecho estado: ");
  Serial.println(sensor_izquierdo_estado);
  Serial.print("izquierdo estado: ");
  Serial.println(sensor_derecho_estado);

  if(sensor_izquierdo_estado && sensor_derecho_estado)    // muevo adelante
  {
    digitalWrite(motor_izquierdo_1, HIGH);
    digitalWrite(motor_izquierdo_2, LOW);
    digitalWrite(motor_derecho_1, HIGH);
    digitalWrite(motor_derecho_2, LOW);
  }
  
  if(!(sensor_izquierdo_estado) && sensor_derecho_estado)   // doblo a la derecha
  {
    digitalWrite(motor_izquierdo_1, LOW);
    digitalWrite(motor_izquierdo_2, LOW);
    digitalWrite(motor_derecho_1, HIGH);
    digitalWrite(motor_derecho_2, LOW);
  }
  
  if(sensor_izquierdo_estado && !(sensor_derecho_estado))   // doblo a la izquierda
  {
    digitalWrite(motor_izquierdo_1, HIGH);
    digitalWrite(motor_izquierdo_2, LOW);
    digitalWrite(motor_derecho_1, LOW);
    digitalWrite(motor_derecho_2, LOW);
  }
  
  if(!(sensor_izquierdo_estado) && !(sensor_derecho_estado))  // paro
  {
    digitalWrite(motor_izquierdo_1, LOW);
    digitalWrite(motor_izquierdo_2, LOW);
    digitalWrite(motor_derecho_1, LOW);
    digitalWrite(motor_derecho_2, LOW);
  }
}
