// ขากำหนดการควบคุมแต่ละ segment (a-g)
int segPins[] = {18, 5, 17, 16, 4, 0, 2};  // ขาเชื่อมแต่ละ segment
int ctrlDigits[] = {19, 21, 22};          // ขาควบคุมหลักแสดงผล (Digit 1-3)

// รูปแบบการเปิด segment สำหรับเลข 0-9
byte segMap[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

void setup() {
  // ตั้งค่าขา segment เป็น OUTPUT
  for (int s = 0; s < 7; s++) {
    pinMode(segPins[s], OUTPUT);
  }
  // ตั้งค่าขาควบคุม digit เป็น OUTPUT
  for (int d = 0; d < 3; d++) {
    pinMode(ctrlDigits[d], OUTPUT);
  }
}

void loop() {
  // แสดงเลขตั้งแต่ 0 ถึง 99
  for (int val = 0; val <= 99; val++) {
    int h = val / 100;        // หลักร้อย (มักเป็น 0 ในช่วงนี้)
    int t = (val / 10) % 10;  // หลักสิบ
    int u = val % 10;         // หลักหน่วย

    // Multiplexed display: วนซ้ำหลายรอบเพื่อความต่อเนื่อง
    for (int i = 0; i < 200; i++) {
      showDigits(h, t, u);
    }
  }
}

// แสดงตัวเลข 3 หลักบนจอแสดงผลแบบ Multiplex
void showDigits(int x, int y, int z) {
  int values[] = {x, y, z};
  for (int i = 0; i < 3; i++) {
    lightUp(values[i]);
    digitalWrite(ctrlDigits[i], LOW);   // เปิดหลักนี้
    delay(3);                            // หน่วงเวลาเพื่อให้มองเห็น
    digitalWrite(ctrlDigits[i], HIGH);  // ปิดหลักนี้
  }
}

// เปิด segment ตามตัวเลขที่กำหนด
void lightUp(int number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], segMap[number][i]);
  }
}
