#include <Gamepad.h>

// Center and scaling values for joystick axes
int rightXcenter = 500;
int rightYcenter = 500;
int leftXcenter = 500;
int leftYcenter = 500;
double multiplierRX = 0.254; // 127 / 500
double multiplierRY = 0.254;
double multiplierLX = 0.254;
double multiplierLY = 0.254;

Gamepad gp;

void setup() {
  // Configure analog pins for joystick axes
  pinMode(A2, INPUT); // Right joystick X-axis
  pinMode(A3, INPUT); // Right joystick Y-axis
  pinMode(A1, INPUT); // Left joystick Y-axis
  pinMode(A0, INPUT); // Left joystick X-axis

  // Configure digital pins for buttons
  pinMode(6, INPUT_PULLUP);  // UP
  pinMode(8, INPUT_PULLUP);  // DOWN
  pinMode(9, INPUT_PULLUP);  // LEFT
  pinMode(7, INPUT_PULLUP);  // RIGHT
  pinMode(4, INPUT_PULLUP);  // RIGHTBUTTON
  pinMode(5, INPUT_PULLUP);  // LEFTBUTTON
  pinMode(15, INPUT_PULLUP); // Y
  pinMode(10, INPUT_PULLUP); // X
  pinMode(16, INPUT_PULLUP); // A
  pinMode(14, INPUT_PULLUP); // B
  pinMode(2, INPUT_PULLUP);  // Top shoulder button (L1)
  pinMode(3, INPUT_PULLUP);  // Top shoulder button (R1)

  calibrate(); // Calibrate the joystick centers
}

void loop() {
  int lx, ly, rx, ry;

  // Read and scale joystick values
  lx = floor((analogRead(A0) - leftXcenter) * multiplierLX);
  ly = floor((analogRead(A1) - leftYcenter) * multiplierLY);
  rx = floor((analogRead(A2) - rightXcenter) * multiplierRX);
  ry = floor((analogRead(A3) - rightYcenter) * multiplierRY);

  // Clamp values to the range [-127, 127]
  lx = constrain(lx, -127, 127);
  ly = constrain(ly, -127, 127);
  rx = constrain(rx, -127, 127);
  ry = constrain(ry, -127, 127);

  // Set joystick axes
  gp.setLeftXaxis(lx);
  gp.setLeftYaxis(ly);
  gp.setRightXaxis(rx);
  gp.setRightYaxis(ry);

  // Read button states
  gp.setButtonState(0, digitalRead(6) == LOW);  // UP
  gp.setButtonState(1, digitalRead(8) == LOW);  // DOWN
  gp.setButtonState(2, digitalRead(9) == LOW);  // LEFT
  gp.setButtonState(3, digitalRead(7) == LOW);  // RIGHT
  gp.setButtonState(4, digitalRead(4) == LOW);  // RIGHTBUTTON
  gp.setButtonState(5, digitalRead(5) == LOW);  // LEFTBUTTON
  gp.setButtonState(6, digitalRead(15) == LOW); // Y
  gp.setButtonState(7, digitalRead(10) == LOW); // X
  gp.setButtonState(8, digitalRead(16) == LOW); // A
  gp.setButtonState(9, digitalRead(14) == LOW); // B
  gp.setButtonState(10, digitalRead(2) == LOW); // Top shoulder button (L1)
  gp.setButtonState(11, digitalRead(3) == LOW); // Top shoulder button (R1)

  delay(20); // Add a small delay for stability
}

void calibrate() {
  int lx, ly, rx, ry;
  int i = 0;

  while (i < 13) {
    lx = analogRead(A0);
    ly = analogRead(A1);
    rx = analogRead(A2);
    ry = analogRead(A3);

    bool validLX = lx > (leftXcenter - 100) && lx < (leftXcenter + 100);
    bool validLY = ly > (leftYcenter - 100) && ly < (leftYcenter + 100);
    bool validRX = rx > (rightXcenter - 100) && rx < (rightXcenter + 100);
    bool validRY = ry > (rightYcenter - 100) && ry < (rightYcenter + 100);

    if (validLX && validLY && validRX && validRY) {
      i++;
    } else {
      i = 0;
    }
    delay(20);
  }

  // Save calibration data
  leftXcenter = lx;
  leftYcenter = ly;
  rightXcenter = rx;
  rightYcenter = ry;
  multiplierLX = (double)127 / (double)lx;
  multiplierLY = (double)127 / (double)ly;
  multiplierRX = (double)127 / (double)rx;
  multiplierRY = (double)127 / (double)ry;
}


