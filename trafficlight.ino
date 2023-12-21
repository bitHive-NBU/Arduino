#define LED_Red_1     5
#define LED_Yellow_1  4
#define LED_Green_1   3
#define LED_Red_2    11
#define LED_Yellow_2  9
#define LED_Green_2   8

#define BTN_MODE1      2
#define BTN_MODE2      10

enum State {
    state_0,
    state_1,
    state_2,
    state_3,
    state_4,
    state_5,
    state_6
};

State state = state_0;

void setup() {
    pinMode(LED_Red_1, OUTPUT);
    pinMode(LED_Yellow_1, OUTPUT);
    pinMode(LED_Green_1, OUTPUT);

    pinMode(LED_Red_2, OUTPUT);
    pinMode(LED_Yellow_2, OUTPUT);
    pinMode(LED_Green_2, OUTPUT);

    pinMode(BTN_MODE1, INPUT);
    pinMode(BTN_MODE2, INPUT);
}

void loop() {
    switch(state) {
        case state_0:
            // 1 RED -- 2 GREEN
            digitalWrite(LED_Red_1, HIGH);
            digitalWrite(LED_Yellow_1, LOW);
            digitalWrite(LED_Green_1, LOW);

            digitalWrite(LED_Red_2, LOW);
            digitalWrite(LED_Yellow_2, LOW);
            digitalWrite(LED_Green_2, HIGH);
            delay(10000);
            state = state_1;
            break;
        case state_1:
            // 1 RED -- 2 YELLOW
            digitalWrite(LED_Red_1, HIGH);
            digitalWrite(LED_Yellow_1, LOW);
            digitalWrite(LED_Green_1, LOW);

            digitalWrite(LED_Red_2, LOW);
            digitalWrite(LED_Yellow_2, HIGH);
            digitalWrite(LED_Green_2, LOW);
            delay(3000);
            state = state_2;
            break;
        case state_2:
            // 1 RED -- 2 RED
            digitalWrite(LED_Red_1, HIGH);
            digitalWrite(LED_Yellow_1, LOW);
            digitalWrite(LED_Green_1, LOW);

            digitalWrite(LED_Red_2, HIGH);
            digitalWrite(LED_Yellow_2, LOW);
            digitalWrite(LED_Green_2, LOW);
            delay(2000);
            state = state_3;
            break;
        case state_3:
            // 1 YELLOW-RED -- 2 RED
            digitalWrite(LED_Red_1, HIGH);
            digitalWrite(LED_Yellow_1, HIGH);
            digitalWrite(LED_Green_1, LOW);

            digitalWrite(LED_Red_2, HIGH);
            digitalWrite(LED_Yellow_2, LOW);
            digitalWrite(LED_Green_2, LOW);
            state = state_4;
            delay(1000);
            break;
        case state_4:
            // 1 GREEN -- 2 RED
            digitalWrite(LED_Red_1, LOW);
            digitalWrite(LED_Yellow_1, LOW);
            digitalWrite(LED_Green_1, HIGH);

            digitalWrite(LED_Red_2, HIGH);
            digitalWrite(LED_Yellow_2, LOW);
            digitalWrite(LED_Green_2, LOW);
            delay(10000);
            state = state_5;
            break;
        case state_5:
            // 1 YELLOW -- 2 RED
            digitalWrite(LED_Red_1, LOW);
            digitalWrite(LED_Yellow_1, HIGH);
            digitalWrite(LED_Green_1, LOW);

            digitalWrite(LED_Red_2, HIGH);
            digitalWrite(LED_Yellow_2, LOW);
            digitalWrite(LED_Green_2, LOW);
            delay(3000);
            state = state_6;
            break;
        case state_6:
            // Handle other states if needed
            break;
    }

    // Check button states
    if(digitalRead(BTN_MODE1) == HIGH) {
        state = state_1;
    } else if(digitalRead(BTN_MODE2) == HIGH) {
        state = state_5;
    }
}