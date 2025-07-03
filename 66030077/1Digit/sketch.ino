// กำหนดขา GPIO ของ ESP32 สำหรับแต่ละส่วนของ 7-segment display
const int PIN_A = 18; // ส่วน A
const int PIN_B = 5;  // ส่วน B
const int PIN_C = 17; // ส่วน C
const int PIN_D = 16; // ส่วน D
const int PIN_E = 4;  // ส่วน E
const int PIN_F = 0;  // ส่วน F
const int PIN_G = 2;  // ส่วน G

// ข้อมูลการเปิดปิดของแต่ละ segment สำหรับตัวเลข 0-9
// HIGH = เปิด, LOW = ปิด (สำหรับ common cathode)
const int digitPattern[10][7] = {
  // A  B  C  D  E  F  G
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // ตั้งค่าขา GPIO ให้เป็น OUTPUT
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
}

void loop() {
  // แสดงตัวเลขจาก 0 ถึง 9 ทีละตัว
  for (int val = 0; val < 10; val++) {
    showDigit(val);   // แสดงค่าที่เลือก
    delay(1000);      // หน่วงเวลา 1 วินาที
  }
}

// ฟังก์ชันสำหรับแสดงตัวเลขบน 7-segment
void showDigit(int val) {
  if (val >= 0 && val <= 9) {
    digitalWrite(PIN_A, digitPattern[val][0]);
    digitalWrite(PIN_B, digitPattern[val][1]);
    digitalWrite(PIN_C, digitPattern[val][2]);
    digitalWrite(PIN_D, digitPattern[val][3]);
    digitalWrite(PIN_E, digitPattern[val][4]);
    digitalWrite(PIN_F, digitPattern[val][5]);
    digitalWrite(PIN_G, digitPattern[val][6]);
  }
}
