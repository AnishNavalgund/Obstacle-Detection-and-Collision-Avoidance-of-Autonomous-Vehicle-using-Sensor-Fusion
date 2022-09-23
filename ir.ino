
int obstaclePin = 7;  // This is our input pin
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() {

  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);  
}
void loop() {
  hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
  if (hasObstacle == LOW) //LOW means something is ahead, so illuminates the 13th Port connected LED
  {
    Serial.println("Stop something is ahead!!");
    
  }
  else
  {
    Serial.println("Path is clear");
   
  }
 delay(500);
}
