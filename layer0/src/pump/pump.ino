
class PreassureSensor{
    public:
       PreassureSensor(int pin); 
       Increase(int amount);
       Decrease(int amount);
    private:
       int pin;
       int preasure;
}

class Gate {
    public:
       Gate(int pin, PreassureSensor *sns);
       int IsOpen();
    private:
       int pin;
       PreassureSensor *sns;
}

class PumpMotor {
    public:
      PumpMotor(int pin, PreassureSensor *sns);
      int IsRunning();
    private:
      int pin;
      PreassureSensor *sns;
}

PreassureSensor::PreassureSensor(int pin){
    this.pin = pin;
    this.preasure = 0;
    pinMode(this.pin,OUTPUT);
    analogWrite(this.pin, 0)
}

PreassureSensor::Increase(int amount){
    this.preasure += amount;
}

PreassureSensor::Decrease(int amount){
    this.preasure -= amount;
}


PumpMotor::PumpMotor(int pin, PreassureSensor *sns){
    this.pin = pin; 
    this.sns = sns;
    pinMode(this.pin,INPUT);
}

int PumpMotor::IsOpen(){
    return digitalRead(this.pin)
}

Gate::Gate(int pin  PreassureSensor *sns){
    this.pin = pin;
    this.sns = sns;
    pinMode(this.pin,INPUT);
}

int Gate::IsOpen(){
    return digitalRead(this.pin);
}

PumpMotor *motor;
PreassureSensor *sensor;
Gate *gate;

void setup() {
   //green
   sensor = new sensor(3);

   //yellow
   motor = new motor(4, sensor);
}

void loop() {
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
}
