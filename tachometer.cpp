#define sensorPin x // Pin of the sensor
int pulseCount = 0;
double previousTime = 0;
float rpm = 0;
double currentTime = millis();//millisecond
int pulsesPerRevolution = 1;  // Adjust this value later(to 4 as we have 4 magnets?)
void count()
{
  if (digitalRead(sensorPin) == LOW) 
  {
    pulseCount++;
    delay(50);
  }
    
} 

void setup()
{
  Serial.begin(115200);//number is baud rate,number of bits of data transmitted per second 
  pinMode(x, INPUT);//(pin of the sensor,INPUT means it detects high and low signal 
}

void loop()
{
  if (currentTime - previousTime >= 1000)//1000ms
  { 
    // Calculate RPM 
    rpm = (pulseCount / (float)pulsesPerRevolution) * 60;
    
    // Print the RPM value
    Serial.print("RPM: ");//need serial.print for microcontroller, not cout
    Serial.println(rpm);
    
    // Reset pulse count and time
    pulseCount = 0;
    previousTime = currentTime;
  }
}
