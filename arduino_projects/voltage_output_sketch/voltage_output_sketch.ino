// Here we declare out input pins
int const analog_input = A0;
int const digital_imput = 3;

// pins setup
void setup() {
  pinmode(digital_input, INPUT);
  pinmode(analog_inputm, INPUT);
  Serial.begin(9600);
  Serial.println("KY-026 flame sensor");
}

void loop() {
  float analog_value; // float because we conver value with 5/1023 
  int digital_value;

  analog_value = analogRead(analog_input) * (5.0 / 1023.0); 
  digital_value = digitalRead(digital_input);

  Serial.print("Analog voltage level: ");
  Serial.print(analog_value, 4);  // here 
  Serial.print(" V");

  if (digital_value == 1) {
    Serial.print("reached");
  } else {
    Serial.print("not reached yet");
  }

  Serial.println("---------------------------------");
  delay(1000);
}
