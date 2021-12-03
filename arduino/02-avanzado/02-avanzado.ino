//PINES DE CONEXIÓN 
  const int motor_izquierdo_1      = 8;  
  const int motor_izquierdo_2      = 10; 
  const int motor_izquierdo_velocidad  = 9;
  const int motor_derecho_1      = 12; 
  const int motor_derecho_2      = 13; 
  const int motor_derecho_velocidad  = 11;
  const int sensor_izquierdo =A0;
  const int sensor_derecho =A1;
//VARIABLES DE USO INTERNO
  int velocidad_crucero = 110;        // MAX 255
  int giro_velocidad = 230;    // MAX 255 
  int giro_retardo = 10;
  int sensor_izquierdo_estado;
  int sensor_derecho_estado;
//CONFIGURAMOS ARDUNIO
  void setup() {
    pinMode(motor_izquierdo_1, OUTPUT);
    pinMode(motor_izquierdo_2, OUTPUT);
    pinMode(motor_derecho_1, OUTPUT);
    pinMode(motor_derecho_2, OUTPUT);
    Serial.begin(9600);
    delay(3000);
  }
//PROGRAMA DEL SEGUIDOR DE LINEAS
  void loop() {
    sensor_izquierdo_estado = analogRead(sensor_izquierdo);
    sensor_derecho_estado = analogRead(sensor_derecho);
    if(sensor_derecho_estado > 500 && sensor_izquierdo_estado < 500)
    {
      Serial.println("turning right");
      digitalWrite (motor_izquierdo_1,LOW);
      digitalWrite(motor_izquierdo_2,HIGH);                       
      digitalWrite (motor_derecho_1,LOW);
      digitalWrite(motor_derecho_2,HIGH);
      analogWrite (motor_izquierdo_velocidad, velocidad_crucero);
      analogWrite (motor_derecho_velocidad, giro_velocidad);
    }
    if(sensor_derecho_estado < 500 && sensor_izquierdo_estado > 500)
    {
      Serial.println("turning left");
      digitalWrite (motor_izquierdo_1,HIGH);
      digitalWrite(motor_izquierdo_2,LOW);                       
      digitalWrite (motor_derecho_1,HIGH);
      digitalWrite(motor_derecho_2,LOW);
      analogWrite (motor_izquierdo_velocidad, giro_velocidad);
      analogWrite (motor_derecho_velocidad, velocidad_crucero);
      delay(giro_retardo);
    }
    if(sensor_derecho_estado > 500 && sensor_izquierdo_estado > 500)
    {
      Serial.println("going forward");
      digitalWrite (motor_izquierdo_2,LOW);
      digitalWrite(motor_izquierdo_1,HIGH);                       
      digitalWrite (motor_derecho_2,HIGH);
      digitalWrite(motor_derecho_1,LOW);
      analogWrite (motor_izquierdo_velocidad, velocidad_crucero);
      analogWrite (motor_derecho_velocidad, velocidad_crucero);
      delay(giro_retardo);
    }
    if(sensor_derecho_estado < 500 && sensor_izquierdo_estado < 500)
    { 
      Serial.println("stop");
      analogWrite (motor_izquierdo_velocidad, 0);
      analogWrite (motor_derecho_velocidad, 0);
    }
  }
