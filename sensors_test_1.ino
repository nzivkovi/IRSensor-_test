#include <SharpIR.h>

/* Project level constants */
#define RANGE_SENSOR_PIN_0  0
#define RANGE_SENSOR_PIN_1  1
#define RANGE_SENSOR_PIN_2  2
#define RANGE_SENSOR_PIN_3  3
#define RANGE_SENSOR_PIN_4  4
#define SENSOR_MODEL GP2Y0A21YK0F

/*granica koliko želim ispisa u loopu, koristim ju u if petlji*/
#define MAX_VALUES 51 

/*pomoćna varijabla da si ograničim broj ispisa u loopu*/
int tmp = 1;

 /* Instances */
SharpIR* sensor_0 = new SharpIR(SENSOR_MODEL, RANGE_SENSOR_PIN_0);
SharpIR* sensor_1 = new SharpIR(SENSOR_MODEL, RANGE_SENSOR_PIN_1);
SharpIR* sensor_2 = new SharpIR(SENSOR_MODEL, RANGE_SENSOR_PIN_2);
SharpIR* sensor_3 = new SharpIR(SENSOR_MODEL, RANGE_SENSOR_PIN_3);
SharpIR* sensor_4 = new SharpIR(SENSOR_MODEL, RANGE_SENSOR_PIN_4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* Check for obstacles */
  if(tmp < MAX_VALUES){ 
    Serial.print(sensor_0->getDistance());
    Serial.print(" ");
    Serial.print(sensor_1->getDistance());
    Serial.print(" ");
    Serial.print(sensor_2->getDistance());
    Serial.print(" ");
    Serial.print(sensor_3->getDistance());
    Serial.print(" ");
    Serial.print(sensor_4->getDistance());
    Serial.println();
  }
  tmp += 1;
  /* Avoid reading before the new distance is sampled */
  delay(100);
}
