String commend;

const unsigned int red= 8;
const unsigned int  green = 9;
const unsigned int blue = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  delay(1000);
  Serial.println("Type commend (red, green, blue, all, off");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    commend = Serial.readStringUntil('\n');
    commend.trim(); // trim whitespace
    if (commend.equals("red")) {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }else if (commend.equals("green")) {
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
    }else if (commend.equals("blue")) {
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
    }else if (commend.equals("all")) {
      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
    }else if (commend.equals("off")) {
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }else {
      Serial.println("bad command");
    }
    Serial.print("Command: ");
    Serial.println(commend);
  }
}

