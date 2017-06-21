int EN1 = 9;  
int EN2 = 10;  
int IN1 = 8;
int IN2 = 7;
int IN3 = 5; 
int IN4 = 6;
int i=1;
int buzz = 11;
#define trigPin 3
#define echoPin 4

void Motor1(int pwm, boolean reverse)
        {
          analogWrite(EN1,pwm); //set pwm control, 0 for stop, and 255 for maximum speed
         if(reverse)
         { 
          digitalWrite(IN1,HIGH);
          digitalWrite(IN2,LOW);    
         }
        else
        {
          digitalWrite(IN1,LOW);
          digitalWrite(IN2,HIGH);    
         }
        }  
         
void Motor2(int pwm, boolean reverse)
        {
          analogWrite(EN2,pwm);
         if(reverse)
         { 
          digitalWrite(IN3,HIGH); 
           digitalWrite(IN4,LOW);   
         }
        else
        {
          digitalWrite(IN3,LOW);
          digitalWrite(IN4,HIGH);    
         }
        }  
        
        
void setup() 
{ 
  Serial.begin(9600);   
  for(int i=5;i<=10;i++)  //For Arduino Motor driver
  pinMode(i, OUTPUT);  //set pin 5,6,7,8,9,10 to output mode  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz, HIGH);   
} 
 
 
 void loop() 
{ 
  delay(1000);
  while(i==1)
  {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    if(distance <= 10)
    {
       Motor1(200,false);  //You can change the speed, such as Motor(50,true)
       Motor2(200,true);
       delay(100);
       Motor1(255,true);  //You can change the speed, such as Motor(50,true)
       Motor2(255,true);
    }
    else
    {
      Motor1(255,true);  //You can change the speed, such as Motor(50,true)
      Motor2(255,true);
    }
  }
}

    
   
