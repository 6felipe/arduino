#define PWM1 3
#define PWM2 5
#define PWM3 6
#define PWM4 9

#define INPUT1 16
#define INPUT2 14
#define INPUT3 13
#define INPUT4 10

#define INPUT1_ 17
#define INPUT2_ 15
#define INPUT3_ 12
#define INPUT4_ 11

void setup() {
  pinMode(INPUT1, INPUT);
  pinMode(INPUT2, INPUT);
  pinMode(PWM1, OUTPUT);
}

class Motor {
  public:
    void velocidade(int v) {
      if (v > 255) { v = 0; }
      if (v < 0) { v = 0; }

      this->v = v;
    }

    void parar() {
      digitalWrite(INPUT1,LOW);
      digitalWrite(INPUT2,LOW);
    }

    void andar() {
      this->sentido(1, 1);
      analogWrite(PWM1, this->v);
    }

    void sentido(int s1, int s2) {
      digitalWrite(INPUT1, s1);
      digitalWrite(INPUT1, s2);
    }

  private:
    int v;
};

Motor * m = new Motor;

void update() {
  m->velocidade(50);
  m->andar();
}
