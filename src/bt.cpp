#innclude <SoftwareSerial.h>
SoftwareSerial BT(rx, tx);

// type data = data;

void setup() {
  BT.begin(9600);
  pinMode(x, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
  }

  while (!BT.available()) {
    BT.print("no bluetooth");
  }
}