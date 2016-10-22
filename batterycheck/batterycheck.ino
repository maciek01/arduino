

int battery_voltage = 0;


void setup() {
	// put your setup code here, to run once:

	Serial.begin(57600);

	battery_voltage = (analogRead(0) + 65) * 1.2317;

}

void loop() {
	// put your main code here, to run repeatedly:

	delay(250);

	battery_voltage = battery_voltage * 0.92 + (analogRead(0) + 65) * 0.09853;

	Serial.println(battery_voltage);
}
