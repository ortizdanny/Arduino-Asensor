#include <CapacitiveSensor.h>

#define E1 2  	 // activa el Pin para motor 
#define I1 3     // Control pin 1 para motor 
#define I2 4     // Control pin 2 para motor 



int PULSADOR_1 = 0; //variables para controlar el estado de los pulsadores de cada planta
int PULSADOR_2 = 0;
int PULSADOR_3 = 0;
int PULSADOR_4 = 0;

int plantaActual=1; //definimos la planta actual donde comienza el ascensor

void setup()
   {
       Serial.begin(9600);
       
        pinMode( I1, OUTPUT);//MOTOR
        pinMode( I2, OUTPUT);//MOTOR
        pinMode( E1, OUTPUT);//MOTOR
        
        pinMode(8, INPUT);//Planta1
        pinMode(9, INPUT);//Planta2
        pinMode(10, INPUT);//Planta3
        pinMode(11, INPUT);//Planta4

       
   }
   
void loop()
   {    
        PULSADOR_1=digitalRead(8); //lee el estado del pin 2 asignado para la planta primera
        PULSADOR_2=digitalRead(9); //lee el estado del pin 3 asignado para la planta segunda
        PULSADOR_3=digitalRead(10); //lee el estado del pin 4 asignado para la planta tercera
        PULSADOR_4=digitalRead(11); //lee el estado del pin 4 asignado para la planta tercera

// Caso para cuando queramos ir a la planta 1
        if(PULSADOR_1==HIGH) //si se pulsa el boton de la primera planta
        {Serial.print("Planta solicitada: Planta Baja \n");
          if(plantaActual==2) // y la planta actual es la segunda, el ascensor baja
          {
            Serial.print("PLANTA 1\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, LOW);     // Arrancamos para BAJAR
            digitalWrite(I2, HIGH);
            Serial.print("Bajando a Planta Baja \n");
            delay(900); //tiempo de bajada del ascensor de la planta 2 a la planta 1
            digitalWrite(E1, LOW);      // Paramos Motor 
            Serial.print("Planta Baja \n");
            plantaActual = 1; //como hemos pulsado el pulsador de la planta primera, la planta actual es la primera
            
          }
          if(plantaActual==3) //si esta la cabina en la planta tercera el ascensor baja más timempo
          {
            Serial.print("PLANTA 2\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, LOW);     // Arrancamos para BAJAR
            digitalWrite(I2, HIGH);
            Serial.print("Bajando a Planta Baja \n");
            delay(2200); //tiempo de bajada del ascensor de la planta 3 a la planta 1
            digitalWrite(E1, LOW);      // Paramos Motor
            Serial.print("Planta Baja \n");
            plantaActual=1; //como hemos pulsado el pulsador de la planta primera, la planta actual es la primera
          }
         if(plantaActual==4) //si esta la cabina en la planta tercera el ascensor baja más timempo
          {
            Serial.print("PLANTA 3\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, LOW);     // Arrancamos para BAJAR
            digitalWrite(I2, HIGH);
            Serial.print("Bajando a Planta Baja \n");
            delay(3500); //tiempo de bajada del ascensor de la planta 3 a la planta 1
            Serial.print("Planta Baja \n");
            digitalWrite(E1, LOW);      // Paramos Motor

            plantaActual=1; //como hemos pulsado el pulsador de la planta primera, la planta actual es la primera
          }
        }
       // Caso para ir a la planta 2
        else if(PULSADOR_2==HIGH) //si pulsamos el boton de la planta segunda
        {
          Serial.print("Planta solicitada: 1 \n");
          if(plantaActual==1) //y la planta actual es la primera
          {
            Serial.print("PLANTA ACTUAL  Planta Baja \n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, HIGH);     // Arrancamos para SUBIR
            digitalWrite(I2, LOW);
            Serial.print("Subiendo a Planta 1 \n");
            delay(1300); //tiempo para subir el ascensor de la planta 1 a la planta 2
            Serial.print("Planta 1 \n");
            digitalWrite(E1, LOW);      // Paramos Motor

            plantaActual=2; //ahora la planta actual es la segunda
            
          }
          if(plantaActual==3) //y la planta actual es la tercera
          {
            Serial.print("PLANTA 2\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, LOW);     // Arrancamos para BAJAR
            digitalWrite(I2, HIGH);
            Serial.print("Bajando a Planta 1 \n");           
            delay(800); //tiempo para bajar el ascensor de la planta 3 a la planta 2
	    Serial.print("Planta 1 \n");
            digitalWrite(E1, LOW);      // Paramos Motor

            plantaActual=2; //ahora la planta actual es la segunda
          }
         if(plantaActual==4) //y la planta actual es la cuarta
          {
            Serial.print("PLANTA ACTUAL ES 3\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, LOW);     // Arrancamos para BAJAR
            digitalWrite(I2, HIGH);
            Serial.print("Bajando a Planta 1 \n");
            delay(1600); //tiempo para bajar el ascensor de la planta 4 a la planta 2
            Serial.print("Planta 1 \n");	
            digitalWrite(E1, LOW);      // Paramos Motor

            plantaActual=2; //ahora la planta actual es la segunda
          }
        }
        //Caso para ir a la planta 3
        else if(PULSADOR_3==HIGH) //si pulsamos el boton de la tercera planta
        {
          Serial.print("Planta solicitada 2 \n");
          if(plantaActual==2)// y la planta actual es la segunda
          {
            Serial.print("PLANTA  1\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
  
            digitalWrite(I1, HIGH);     // Arrancamos para SUBIR
            digitalWrite(I2, LOW);
            Serial.print("Subiendo a Planta 2 \n");
            delay(1100); //tiempo para subir de la segunda planta a la tercera
            Serial.print("Planta 2 \n");
            digitalWrite(E1, LOW);      // Paramos Motor 

            plantaActual=3; //ahora la planta actual es la tercera
            
          }
          if(plantaActual==1) //y la planta actual es la primera
          {
            Serial.print("PLANTA  BAJA\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, HIGH);     // Arrancamos para SUBIR
            digitalWrite(I2, LOW);
            Serial.print("Subiendo a Planta 2 \n");
            delay(2000); //tiempo para subir de la primera planta a la tercera
            Serial.print("Planta 2 \n");
            digitalWrite(E1, LOW);      // Paramos Motor
            
            plantaActual=3; //ahora la planta actual es la 
            
          }
          if(plantaActual==4) //y la planta actual es la cuarta
          {
            Serial.print("PLANTA  3\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, LOW);     // Arrancamos para BAJAR
            digitalWrite(I2, HIGH);
            Serial.print("Bajando a Planta 2 \n");
            delay(900); //tiempo para bajar el ascensor de la planta 4 a la planta 3
            Serial.print("Planta 2 \n");	
            digitalWrite(E1, LOW);      // Paramos Motor

            plantaActual=3; //ahora la planta actual es la segunda
          }
        }
        //caso para ir a la planta 4
       else if(PULSADOR_4==HIGH) //si pulsamos el boton de la cuarta planta
        {
          Serial.print("Planta solicitada 3 \n");
          if(plantaActual==3)// y la planta actual es la tercera
          {
            Serial.print("PLANTA 2\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
            digitalWrite(I1, HIGH);     // Arrancamos para SUBIR
            digitalWrite(I2, LOW);
            Serial.print("Subiendo a Planta 3 \n");
            delay(1300); //tiempo para subir de la segunda planta a la tercera
            Serial.print("Planta 3 \n");
            digitalWrite(E1, LOW);      // Paramos Motor 

            plantaActual=4; //ahora la planta actual es la tercera
            
          }
          if(plantaActual==2) //y la planta actual es la segunda
          {
            Serial.print("PLANTA  1\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
        
            digitalWrite(I1, HIGH);     // Arrancamos para SUBIR
            digitalWrite(I2, LOW);
            Serial.print("Subiendo a Planta 3\n");
            delay(2600); //tiempo para subir de la primera planta a la tercera
            Serial.print("Planta 3 \n");
            digitalWrite(E1, LOW);      // Paramos Motor
            
            plantaActual=4; //ahora la planta actual es la tercera
          }
          if(plantaActual==1) //y la planta actual es la primera
          {
            Serial.print("PLANTA  BAJA\n");
            digitalWrite(E1, HIGH);     // Activamos Motor
        
            digitalWrite(I1, LOW);     // Arrancamos para BAJAR
            digitalWrite(I2, HIGH);
            Serial.print("Subiendo a Planta 3 \n");
            delay(3900); //tiempo para bajar el ascensor de la planta 4 a la planta 3
	    Serial.print("Planta 3 \n");	
            digitalWrite(E1, LOW);      // Paramos Motor

            plantaActual=4; //ahora la planta actual es la segunda
          }
        }
   }
