class Motor {
    public:
    
    Motor(int enablePin, int in1, int in2) {
        this->enablePin = enablePin;
        this->input1 = in1;
        this->input2 = in2;
    }
    
    void velocidade(int v) {
        if (v > 10) { //valor ainda nao sei
            v = 0; // pra nao coisa o motor
        }
        analogWrite(this->enablePin, v);
    }
    
    void sentido(int a, int b) {
        digitalWrite(this->input1, a);
        digitalWrite(this->input2, b);
    }
    
    void para() {
        this->sentido(0, 0);
    }
    
    void pinConfig() {
        pinMode(this->enablePin, OUTPUT);
        pinMode(this->input1, OUTPUT);
        pinMode(this->input2, OUTPUT);
    }
    
    private:
    
    int enablePin;
    int input1;
    int input2;
};

Motor * m = new Motor(enablePin, in1, in2);
