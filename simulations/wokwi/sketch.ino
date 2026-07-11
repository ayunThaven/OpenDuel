#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>

#define TFT_CS    10
#define TFT_DC     9
#define TFT_RST    8

#define TFT_SCK   12
#define TFT_MOSI  11
#define TFT_MISO  13

#define ENC_CLK    4
#define ENC_DT     5
#define ENC_SW     6

#define BTN_PHASE  7
#define BTN_TURN   15

#define LED_PIN    16
#define LED_COUNT  10

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

enum Phase {
  DRAW,
  STANDBY,
  MAIN_1,
  BATTLE,
  MAIN_2,
  END
};

enum ZoneState {
  ZONE_EMPTY,
  ZONE_SELECTED,
  ZONE_ACTIVATED
};

struct DuelState {
  int lp[2] = {8000, 8000};
  int activePlayer = 0;
  int selectedPlayer = 0;
  int turn = 1;
  Phase phase = DRAW;
  int selectedZone = 0;
  ZoneState zones[LED_COUNT] = {
    ZONE_EMPTY, ZONE_EMPTY, ZONE_EMPTY, ZONE_EMPTY, ZONE_EMPTY,
    ZONE_EMPTY, ZONE_EMPTY, ZONE_EMPTY, ZONE_EMPTY, ZONE_EMPTY
  };
};

DuelState duel;

const char* phaseNames[] = {
  "DRAW",
  "STANDBY",
  "MAIN 1",
  "BATTLE",
  "MAIN 2",
  "END"
};

int lastEncoderCLK;
bool lastEncoderButton = HIGH;
bool lastPhaseButton = HIGH;
bool lastTurnButton = HIGH;

uint32_t phaseColor() {
  switch (duel.phase) {
    case DRAW:    return strip.Color(0, 0, 40);
    case STANDBY: return strip.Color(20, 0, 40);
    case MAIN_1:  return strip.Color(0, 40, 0);
    case BATTLE:  return strip.Color(60, 0, 0);
    case MAIN_2:  return strip.Color(0, 30, 30);
    case END:     return strip.Color(30, 30, 0);
  }

  return strip.Color(0, 0, 0);
}

void updateLeds() {
  uint32_t base = phaseColor();

  for (int i = 0; i < LED_COUNT; i++) {
    if (duel.zones[i] == ZONE_ACTIVATED) {
      strip.setPixelColor(i, strip.Color(0, 180, 180));
    } else if (i == duel.selectedZone) {
      strip.setPixelColor(i, strip.Color(180, 120, 0));
    } else {
      strip.setPixelColor(i, base);
    }
  }

  strip.show();
}

void drawZoneLabels() {
  tft.setTextSize(1);

  for (int i = 0; i < LED_COUNT; i++) {
    int x = 20 + (i % 5) * 42;
    int y = (i < 5) ? 220 : 240;

    if (i == duel.selectedZone) {
      tft.setTextColor(ILI9341_YELLOW);
    } else if (duel.zones[i] == ZONE_ACTIVATED) {
      tft.setTextColor(ILI9341_CYAN);
    } else {
      tft.setTextColor(ILI9341_DARKGREY);
    }

    tft.setCursor(x, y);

    if (i < 5) {
      tft.print("M");
      tft.print(i + 1);
    } else {
      tft.print("S");
      tft.print(i - 4);
    }
  }
}

void drawInterface() {
  tft.fillScreen(ILI9341_BLACK);

  tft.setTextColor(ILI9341_CYAN);
  tft.setTextSize(3);
  tft.setCursor(20, 15);
  tft.println("DUEL DISK");

  tft.setTextSize(2);

  tft.setTextColor(duel.selectedPlayer == 0 ? ILI9341_YELLOW : ILI9341_WHITE);
  tft.setCursor(20, 65);
  tft.print("YOU: ");
  tft.println(duel.lp[0]);

  tft.setTextColor(duel.selectedPlayer == 1 ? ILI9341_YELLOW : ILI9341_WHITE);
  tft.setCursor(20, 100);
  tft.print("OPP: ");
  tft.println(duel.lp[1]);

  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(20, 150);
  tft.print("TURN: ");
  tft.println(duel.turn);

  tft.setCursor(20, 180);
  tft.print("PHASE: ");
  tft.println(phaseNames[duel.phase]);

  tft.setCursor(20, 210);
  tft.print("ZONE: ");
  if (duel.selectedZone < 5) {
    tft.print("M");
    tft.println(duel.selectedZone + 1);
  } else {
    tft.print("S");
    tft.println(duel.selectedZone - 4);
  }

  drawZoneLabels();
  updateLeds();
}

void updateEncoder() {
  int currentCLK = digitalRead(ENC_CLK);

  if (currentCLK != lastEncoderCLK && currentCLK == LOW) {
    if (digitalRead(ENC_DT) != currentCLK) {
      duel.lp[duel.selectedPlayer] += 100;
    } else {
      duel.lp[duel.selectedPlayer] -= 100;
      if (duel.lp[duel.selectedPlayer] < 0) {
        duel.lp[duel.selectedPlayer] = 0;
      }
    }

    drawInterface();
  }

  lastEncoderCLK = currentCLK;
}

void updateEncoderButton() {
  bool currentButton = digitalRead(ENC_SW);

  if (lastEncoderButton == HIGH && currentButton == LOW) {
    duel.selectedPlayer = !duel.selectedPlayer;
    drawInterface();
    delay(150);
  }

  lastEncoderButton = currentButton;
}

void updatePhaseButton() {
  bool currentButton = digitalRead(BTN_PHASE);

  if (lastPhaseButton == HIGH && currentButton == LOW) {
    int nextPhase = duel.phase + 1;

    if (nextPhase > END) {
      nextPhase = DRAW;
    }

    duel.phase = static_cast<Phase>(nextPhase);

    duel.selectedZone++;
    if (duel.selectedZone >= LED_COUNT) {
      duel.selectedZone = 0;
    }

    drawInterface();
    delay(150);
  }

  lastPhaseButton = currentButton;
}

void updateTurnButton() {
  bool currentButton = digitalRead(BTN_TURN);

  if (lastTurnButton == HIGH && currentButton == LOW) {
    duel.turn++;
    duel.activePlayer = !duel.activePlayer;
    duel.phase = DRAW;

    duel.zones[duel.selectedZone] =
      duel.zones[duel.selectedZone] == ZONE_ACTIVATED
      ? ZONE_EMPTY
      : ZONE_ACTIVATED;

    drawInterface();
    delay(150);
  }

  lastTurnButton = currentButton;
}

void setup() {
  Serial.begin(115200);

  SPI.begin(TFT_SCK, TFT_MISO, TFT_MOSI, TFT_CS);

  tft.begin();
  tft.setRotation(1);

  strip.begin();
  strip.setBrightness(80);
  strip.show();

  pinMode(ENC_CLK, INPUT);
  pinMode(ENC_DT, INPUT);
  pinMode(ENC_SW, INPUT_PULLUP);

  pinMode(BTN_PHASE, INPUT_PULLUP);
  pinMode(BTN_TURN, INPUT_PULLUP);

  lastEncoderCLK = digitalRead(ENC_CLK);

  drawInterface();

  Serial.println("Duel Disk Core with zones ready");
}

void loop() {
  updateEncoder();
  updateEncoderButton();
  updatePhaseButton();
  updateTurnButton();

  delay(5);
}