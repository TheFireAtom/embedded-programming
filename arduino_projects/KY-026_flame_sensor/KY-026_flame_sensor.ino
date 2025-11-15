const int digital_input = 3;   // digital sensor output -> arduino input
const int analog_input = A0;   // analog sensor output -> arduino input
const int buzzer = 8;           
const int led = 13;

void setup() {
  Serial.begin(9600);
  pinmode(digital_input, INPUT);
  pinmode(analog_input, INPUT);
  pinmode(led, OUTPUT);
  pinmode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int digital_signal = digitalRead(digital_input);
  int analog_signal = analogRead(analog_input);

  Serial.print("Digital: ");
  Serial.print(digital == LOW ? "FLAME" : "SAFE");
  Serial.print("Analog intensity");
  Serial.println(analog);

  if (digital == HIGH) {
    digitalWrite(led, HIGH);

    if (analog < 300) {
      tone(buzzer, 2000);
    } if else (analog < 600) {
      tone(buzzer, 1000);
    } else {
      tone(buzzer, 500);3
    }
  } else if {
    digitalWrite(led, LOW);
    noTone(buzzer);
  }

  delay(200);
}
