int Pin1 = A4;                                 
int Pin2 = A5;
int right = 0;
int left = 0;
int trigPin=1;
int echoPin=0;
long duration=0,distance=0;

//user defined functions;
  void forword(void)
  {
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
  }
  void right_turn(void)
  {
    //Turn_right;
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);    
  }
  
  void left_turn(void)
  {
    //Turn_left;
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);      
  }

  void backword(void)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }

  void Stop(void)
  {
    //stop;
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);   
    digitalWrite(11,HIGH);
    delay(500);
    digitalWrite(11,LOW);
    delay(500);   
  }
 
// setup starts;
void setup()
{
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);   
  pinMode(11,OUTPUT); //buzzer;   
  
 while(1)
 {
  right = analogRead(Pin1);
  left = analogRead(Pin2);
  if(right>=700 && left<=1000) //right_black;
  break;
  else
  right_turn();
 }
}


//loop starts;
void loop()
{

  //IR sensor
  right = analogRead(Pin1);
  left = analogRead(Pin2);
  if(right>=700 && left<=1000) //right_black;
  {
    right_turn();
  }
  else if(left>=1000 && right<=700) //left_black;
  {
    left_turn();
  }
  else if(right>=700 && left >=1000)//both_black;
  {
    Stop();  
  }
  else //both_white;
  {
    forword();
  }

} 
