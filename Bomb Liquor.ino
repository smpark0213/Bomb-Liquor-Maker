const int waterPump1 = A1; //소주
const int waterPump2 = A2; //맥주
const int waterPump3 = A3; //막걸리
const int waterPump4 = A4; //콜라
const int waterPump5 = A5; //사이다

const int trigPin1 = 13;
const int echoPin1 = 12;

const int trigPin2 = 11;
const int echoPin2 = 10; 

const int trigPin3 = 9;
const int echoPin3 = 8; 

const int trigPin4 = 7;
const int echoPin4 = 6; 

const int button1 = 5; //소맥
const int button2 = 4; //고진감래
const int button3 = 3; //막소사
const int button4 = 2; // 맥콜


long duration1, duration2, duration3, duration4;
long distance1, distance2, distance3, distance4;


int button1_value;
int button2_value;
int button3_value;
int button4_value;


void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT); //불필요
  pinMode(button2, INPUT); //불필요
  pinMode(button3, INPUT); //불필요
  pinMode(button4, INPUT); //불필요
  pinMode(waterPump1, OUTPUT);
  pinMode(waterPump2, OUTPUT);
  pinMode(waterPump3, OUTPUT);
  pinMode(waterPump4, OUTPUT);
  pinMode(waterPump5, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
}

void loop() {
  
  long duration;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);



  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);



  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);



  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);

  distance1 = duration1/29/0.2; // (mm)
  distance2 = duration2/29/0.2;
  distance3 = duration3/29/0.2;
  distance4 = duration4/29/0.2;
  //distance4 = ((34000 * duration4) / 1000000) / 2; (cm)

/*
  Serial.print(" wall 1 ");

  Serial.println(distance1 );

  Serial.print(" wall 2 ");

  Serial.println(distance2 );

  Serial.print(" wall 3 ");

  Serial.println(distance3 );
  */

  Serial.print(" ceiling ");

  Serial.println(distance4 );

  Serial.println(" ");

  //delay(500);


  button1_value = digitalRead(5);
  button2_value = digitalRead(4);
  button3_value = digitalRead(3);
  button4_value = digitalRead(2);
  
  //소맥
  if(button1_value == 1){
    Serial.println("소맥 실행");
    delay(5000);
    if(distance3 < 100){
    Serial.println("소맥 실행중 - 소주 출력");
    delay(1000);
    analogWrite(waterPump1, 255);
    delay(10000);
      if(distance4 < 258){
        Serial.println("소맥 실행중 - 맥주 출력");
        delay(1000);
        analogWrite(waterPump2, 255);

        if(distance4 < 160){
          Serial.println("소맥 종료");
          delay(1000);
          }
        } 
    }
     
    
    else if(distance2 < 100){
    Serial.println("소맥 실행중 - 소주 출력");
    delay(1000);
    analogWrite(waterPump1, 255); 
    delay(1000);
      if(distance4 < 273){
        Serial.println("소맥 실행중 - 맥주 출력");
        delay(1000);
        analogWrite(waterPump2, 255);

        if(distance4 < 210){
          Serial.println("소맥 종료");
          delay(1000);
          }
        }   
    }  
     
  
    
    else if(distance1 < 100){
    Serial.println("소맥 실행중 - 소주 출력");
    delay(1000);
    analogWrite(waterPump1, 255);
    delay(10000);
      if(distance4 < 288){
        Serial.println("소맥 실행중 - 맥주 출력");
        delay(1000);
        analogWrite(waterPump2, 255);
        if(distance4 < 260){
          Serial.println("소맥 종료");
          delay(1000);
          }
    }
    }
else{
          Serial.println("컵이 인식되지 않았습니다.");
          delay(1000);
          }
  }

  
  //고진감래
  else if(button2_value == 1){
    Serial.println("고진감래 실행");
    delay(5000);
    if(distance3 < 100){
    Serial.println("고진감래 실행중 - 소주 출력");
    delay(1000);
    analogWrite(waterPump1, 255);
    analogWrite(waterPump2, 0);
    analogWrite(waterPump3, 0);
    analogWrite(waterPump4, 0);
    analogWrite(waterPump5, 0);
      if(distance4 < 265){
        Serial.println("고진감래 실행중 - 맥주 출력");
        delay(1000);
        analogWrite(waterPump1, 0);
        analogWrite(waterPump2, 255);
        analogWrite(waterPump3, 0);
        analogWrite(waterPump4, 0);
        analogWrite(waterPump5, 0);
        if(distance4 < 195){
          Serial.println("고진감래 실행중 - 콜라 출력");
          delay(1000);
          analogWrite(waterPump1, 0);
          analogWrite(waterPump2, 0);
          analogWrite(waterPump3, 0);
          analogWrite(waterPump4, 255);
          analogWrite(waterPump5, 0);
          if(distance4 < 160){
            Serial.println("고진감래 종료");
            delay(1000);
            analogWrite(waterPump1, 0);
            analogWrite(waterPump2, 0);
            analogWrite(waterPump3, 0);
            analogWrite(waterPump4, 0);
            analogWrite(waterPump5, 0);
            }
        }
      }
          
             
     }
    
    else if(distance2 < 100){
    Serial.println("고진감래 실행중 - 소주 출력");
    delay(1000);
    analogWrite(waterPump1, 255);
    analogWrite(waterPump2, 0);
    analogWrite(waterPump3, 0);
    analogWrite(waterPump4, 0);
    analogWrite(waterPump5, 0);
      if(distance4 < 277){
        Serial.println("고진감래 실행중 - 맥주 출력");
        delay(1000);
        analogWrite(waterPump1, 0);
        analogWrite(waterPump2, 255);
        analogWrite(waterPump3, 0);
        analogWrite(waterPump4, 0);
        analogWrite(waterPump5, 0);
      if(distance4 < 233){
          Serial.println("고진감래 실행중 - 콜라 출력");
          delay(1000);
          analogWrite(waterPump1, 0);
          analogWrite(waterPump2, 0);
          analogWrite(waterPump3, 0);
          analogWrite(waterPump4, 255);
          analogWrite(waterPump5, 0);
          if(distance4 < 210){
            Serial.println("고진감래 종료");
            delay(1000);
            analogWrite(waterPump1, 0);
            analogWrite(waterPump2, 0);
            analogWrite(waterPump3, 0);
            analogWrite(waterPump4, 0);
            analogWrite(waterPump5, 0);
            }
      }
      }    
    }
     else if(distance1 < 100){
      Serial.println("고진감래 실행중 - 소주 출력");
      delay(1000);
      analogWrite(waterPump1, 255);
      analogWrite(waterPump2, 0);
      analogWrite(waterPump3, 0);
      analogWrite(waterPump4, 0);
      analogWrite(waterPump5, 0);
        if(distance4 < 290){
          Serial.println("고진감래 실행중 - 맥주 출력");
          delay(1000);
         analogWrite(waterPump1, 0);
         analogWrite(waterPump2, 255);
         analogWrite(waterPump3, 0);
         analogWrite(waterPump4, 0);
         analogWrite(waterPump5, 0);
         if(distance4 < 270){
          Serial.println("고진감래 실행중 - 콜라 출력");
          delay(1000);
           analogWrite(waterPump1, 0);
           analogWrite(waterPump2, 0);
           analogWrite(waterPump3, 0);
           analogWrite(waterPump4, 255);
           analogWrite(waterPump5, 0);
         if(distance4 < 260){
              Serial.println("고진감래 종료");
              delay(1000);
              analogWrite(waterPump1, 0);
              analogWrite(waterPump2, 0);
              analogWrite(waterPump3, 0);
              analogWrite(waterPump4, 0);
              analogWrite(waterPump5, 0); 
     }
  }
        }
     }
  else{
          Serial.println("컵이 인식되지 않았습니다.");
          delay(1000);
          }
  }
  
  //막소사
  else if(button3_value == 1){
    Serial.println("막소사 실행");
    delay(5000);
    if(distance3 < 100){
    Serial.println("막소사 실행중 - 소주 출력");
    delay(1000);
    analogWrite(waterPump1, 255);
    analogWrite(waterPump2, 0);
    analogWrite(waterPump3, 0);
    analogWrite(waterPump4, 0);
    analogWrite(waterPump5, 0);
      if(distance4 < 254){
        Serial.println("막소사 실행중 - 막걸리 출력");
        delay(1000);
        analogWrite(waterPump1, 0);
        analogWrite(waterPump2, 0);
        analogWrite(waterPump3, 255);
        analogWrite(waterPump4, 0);
        analogWrite(waterPump5, 0);
      if(distance4 < 208){
          Serial.println("막소사 실행중 - 사이다 출력");
          delay(1000);
          analogWrite(waterPump1, 0);
          analogWrite(waterPump2, 0);
          analogWrite(waterPump3, 0);
          analogWrite(waterPump4, 0);
          analogWrite(waterPump5, 255);
        if(distance4 < 162){
            Serial.println("막소사 종료");
            delay(1000);
            analogWrite(waterPump1, 0);
            analogWrite(waterPump2, 0);
            analogWrite(waterPump3, 0);
            analogWrite(waterPump4, 0);
            analogWrite(waterPump5, 0);
          }
     }
      }
    }
    
    else if(distance2 < 100){
    Serial.println("막소사 실행중 - 소주 출력");
    delay(1000);
    analogWrite(waterPump1, 255);
    analogWrite(waterPump2, 0);
    analogWrite(waterPump3, 0);
    analogWrite(waterPump4, 0);
    analogWrite(waterPump5, 0);
      if(distance4 < 270){
        Serial.println("막소사 실행중 - 막걸리 출력");
        delay(1000);
        analogWrite(waterPump1, 0);
        analogWrite(waterPump2, 0);
        analogWrite(waterPump3, 255);
        analogWrite(waterPump4, 0);
        analogWrite(waterPump5, 0);
       if(distance4 < 240){
          Serial.println("막소사 실행중 - 사이다 출력");
          delay(1000);
          analogWrite(waterPump1, 0);
          analogWrite(waterPump2, 0);
          analogWrite(waterPump3, 0);
          analogWrite(waterPump4, 0);
          analogWrite(waterPump5, 255);
         if(distance4 < 210){
            Serial.println("막소사 종료");
            delay(1000);
            analogWrite(waterPump1, 0);
            analogWrite(waterPump2, 0);
            analogWrite(waterPump3, 0);
            analogWrite(waterPump4, 0);
            analogWrite(waterPump5, 0);
            }  
     }}}
     else if(distance1 < 100){
      Serial.println("막소사 실행중 - 소주 출력");
      delay(1000);
      analogWrite(waterPump1, 255);
      analogWrite(waterPump2, 0);
      analogWrite(waterPump3, 0);
      analogWrite(waterPump4, 0);
      analogWrite(waterPump5, 0);
        if(distance4 < 287){
          Serial.println("막소사 실행중 - 막걸리 출력");
          delay(1000);
          analogWrite(waterPump1, 0);
         analogWrite(waterPump2, 0);
         analogWrite(waterPump3, 255);
         analogWrite(waterPump4, 0);
         analogWrite(waterPump5, 0);
        if(distance4 < 274){
          Serial.println("막소사 실행중 - 사이다 출력");
          delay(1000);
           analogWrite(waterPump1, 0);
           analogWrite(waterPump2, 0);
           analogWrite(waterPump3, 0);
           analogWrite(waterPump4, 0);
           analogWrite(waterPump5, 255);
         if(distance4 < 261){
              Serial.println("막소사 종료");
              delay(1000);
              analogWrite(waterPump1, 0);
              analogWrite(waterPump2, 0);
              analogWrite(waterPump3, 0);
              analogWrite(waterPump4, 0);
              analogWrite(waterPump5, 0);
            }
        }
        }
     }
     else{
          Serial.println("컵이 인식되지 않았습니다.");
          delay(1000);
          }
  }
  
  //맥콜
  else if(button4_value == 1){
    Serial.println("맥콜 실행");
    delay(5000);
    if(distance3 < 100){
    Serial.println("맥콜 실행중 - 맥주 출력");
    delay(1000);
    analogWrite(waterPump1, 0);
    analogWrite(waterPump2, 255);
    analogWrite(waterPump3, 0);
    analogWrite(waterPump4, 0);
    analogWrite(waterPump5, 0);
      if(distance4 < 230){
        Serial.println("맥콜 실행중 - 콜라 출력");
        delay(1000);
        analogWrite(waterPump1, 0);
        analogWrite(waterPump2, 0);
        analogWrite(waterPump3, 0);
        analogWrite(waterPump4, 255);
        analogWrite(waterPump5, 0);
      if(distance4 < 160){
          Serial.println("맥콜 종료");
          delay(1000);
          analogWrite(waterPump1, 0);
          analogWrite(waterPump2, 0);
          analogWrite(waterPump3, 0);
          analogWrite(waterPump4, 0);
          analogWrite(waterPump5, 0);
          }     
     }
    }
    else if(distance2 < 100){
    Serial.println("맥콜 실행중 - 맥주 출력");
    delay(1000);
    analogWrite(waterPump1, 0);
    analogWrite(waterPump2, 255);
    analogWrite(waterPump3, 0);
    analogWrite(waterPump4, 0);
    analogWrite(waterPump5, 0);
      if(distance4 < 255){
        Serial.println("맥콜 실행중 - 콜라 출력");
        delay(1000);
        analogWrite(waterPump1, 0);
        analogWrite(waterPump2, 0);
        analogWrite(waterPump3, 255);
        analogWrite(waterPump4, 0);
        analogWrite(waterPump5, 0);
       if(distance4 < 210){
          Serial.println("맥콜 종료");
          delay(1000);
          analogWrite(waterPump1, 0);
          analogWrite(waterPump2, 0);
          analogWrite(waterPump3, 0);
          analogWrite(waterPump4, 0);
          analogWrite(waterPump5, 0);
          }  
      }
     }
    
    else if(distance1 < 100){
    Serial.println("맥콜 실행중 - 맥주 출력");
    delay(1000);
    analogWrite(waterPump1, 0);
    analogWrite(waterPump2, 255);
    analogWrite(waterPump3, 0);
    analogWrite(waterPump4, 0);
    analogWrite(waterPump5, 0);
      if(distance4 < 280){
        Serial.println("맥콜 실행중 - 콜라 출력");
        delay(1000);
        analogWrite(waterPump1, 0);
        analogWrite(waterPump2, 0);
        analogWrite(waterPump3, 0);
        analogWrite(waterPump4, 0);
        analogWrite(waterPump5, 255);
        if(distance4 < 260){
          Serial.println("맥콜 종료");
          delay(1000);
          analogWrite(waterPump1, 0);
          analogWrite(waterPump2, 0);
          analogWrite(waterPump3, 0);
          analogWrite(waterPump4, 0);
          analogWrite(waterPump5, 0);
          }
        }   
    }
        else{
          Serial.println("컵이 인식되지 않았습니다.");
          delay(1000);
          }  
  } 


  

/*
  if (distance3 < 10) {
    analogWrite(waterPump, 255);
      if (distance4 < 15    
    ) {
      analogWrite(waterPump, 0);
    }
  } else if (distance2 < 10) {
      analogWrite(waterPump, 255);
      if (distance4 < 20) {
        analogWrite(waterPump, 0);
      }
    } else if (distance1 < 10) {
        analogWrite(waterPump, 225);
        if (distance4 < 25) {
          analogWrite(waterPump, 0);
        }
      } else {
        analogWrite(waterPump, 0);
      }
      */

}
