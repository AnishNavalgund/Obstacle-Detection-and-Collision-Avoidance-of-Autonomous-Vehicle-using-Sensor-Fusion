int obstaclePin = 7;  // This is our input pin
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE
const int trigPin = 9;
const int echoPin = 10;


int mode1=3;
int mode2=4;
long duration;
int distance;
void setup() {
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(obstaclePin, INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(mode1,OUTPUT);
  pinMode(mode2,OUTPUT);
 // Serial.println("loop");
}
  
void loop() {
  digitalWrite(5,HIGH);
  
  digitalWrite(mode1,LOW);
  digitalWrite(mode2,HIGH);
  
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

  
delay(100);
if(distance<20)
{
Serial.println("OBSTACLE AHEAD");
  Serial.println("WARNING..GO SLOW..DRIVER TAKE OVER");
  hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
  while (hasObstacle == LOW) //LOW means something 13th Port connected LED
  { 
    Serial.println("Stop something is ahead!!");
    digitalWrite(mode1,HIGH);
    digitalWrite(mode2,HIGH);
     Serial.println("VEHICLE STOPPED");
    hasObstacle = digitalRead(obstaclePin);
  }
}
    else

  
  Serial.println("Path is clear");
  
  
   


  
 delay(500);

  
  
  
 
}
