#include <WS2812FX.h>
#include <OneButton.h>

// Указываем, какое количество пикселей у наших лент
#define LED_COUNT 144

// Указываем, к каким портам подключены входы DIN, кнопки и геркон
#define LED_PIN_1 0
#define LED_PIN_2 1
#define LED_PIN_3 2
#define LED_PIN_4 3
#define LED_PIN_5 4
#define LED_PIN_6 5
#define LED_PIN_7 6
#define LED_PIN_8 7
#define LED_PIN_9 8
#define LED_PIN_10 9
#define LED_PIN_11 10

#define BTN_PIN_1 11
#define BTN_PIN_2 12
#define BTN_PIN_3 13
#define BTN_PIN_4 14
#define MGN_PIN_1 15

// Создаем объекты для управления нашими лентами
WS2812FX ws2812fx_1 = WS2812FX(LED_COUNT, LED_PIN_1, NEO_GRB + NEO_KHZ800, 1, 1); // Уменьшаем объем оперативной памяти, которую использует каждый экземпляр WS2812FX,
WS2812FX ws2812fx_2 = WS2812FX(LED_COUNT, LED_PIN_2, NEO_GRB + NEO_KHZ800, 1, 1); // указав максимальное количество активных сегментов
WS2812FX ws2812fx_3 = WS2812FX(LED_COUNT, LED_PIN_3, NEO_GRB + NEO_KHZ800, 1, 1);
WS2812FX ws2812fx_4 = WS2812FX(LED_COUNT, LED_PIN_4, NEO_GRB + NEO_KHZ800, 1, 1);
WS2812FX ws2812fx_5 = WS2812FX(LED_COUNT, LED_PIN_5, NEO_GRB + NEO_KHZ800, 1, 1);
WS2812FX ws2812fx_6 = WS2812FX(LED_COUNT, LED_PIN_6, NEO_GRB + NEO_KHZ800, 1, 1);
WS2812FX ws2812fx_7 = WS2812FX(LED_COUNT, LED_PIN_7, NEO_GRB + NEO_KHZ800, 1, 1);
WS2812FX ws2812fx_8 = WS2812FX(LED_COUNT, LED_PIN_8, NEO_GRB + NEO_KHZ800, 1, 1);
WS2812FX ws2812fx_9 = WS2812FX(LED_COUNT, LED_PIN_9, NEO_GRB + NEO_KHZ800, 1, 1);
WS2812FX ws2812fx_10 = WS2812FX(LED_COUNT, LED_PIN_10, NEO_GRB + NEO_KHZ800, 1, 1);
WS2812FX ws2812fx_11 = WS2812FX(LED_COUNT, LED_PIN_11, NEO_GRB + NEO_KHZ800, 1, 1);

// Создаем объекты для управления нашими кнопками и герконом
OneButton btn_1 = OneButton(BTN_PIN_1, true, true); // true, тк используется подтягивающий резистор
OneButton btn_2 = OneButton(BTN_PIN_2, true, true);
OneButton btn_3 = OneButton(BTN_PIN_3, true, true);
OneButton btn_4 = OneButton(BTN_PIN_4, true, true);
OneButton mgn_1 = OneButton(MGN_PIN_1);

void setup()
{
  pinMode(BTN_PIN_1, INPUT_PULLUP);
  pinMode(BTN_PIN_2, INPUT_PULLUP);
  pinMode(BTN_PIN_3, INPUT_PULLUP);
  pinMode(BTN_PIN_4, INPUT_PULLUP);
  pinMode(MGN_PIN_1, INPUT);

  // Привязываем функции Click, которые должны быть вызваны при нажатии на кнопку и при открытии двери
  btn_1.attachClick(click_1);
  btn_2.attachClick(click_2);
  btn_3.attachClick(click_3);
  btn_4.attachClick(click_4);
  mgn_1.attachClick(open_door);
  
  // Инициализируем ленты
  init_LEDs();

  // Задаем яркость
  brightness_LEDs(0);
  
  // Задаем скорость
  speed_LEDs(0);

  // Задаем цвет
  color_LEDs(0x000000);

  // Запускаем анимацию
  start_LEDs();
}

void loop()
{
  // Следим за кнопками и состоянием геркона
  btn_1.tick();
  btn_2.tick();
  btn_3.tick();
  btn_4.tick();
  mgn_1.tick();

  // Постоянно запускаем службу анимации
  service_LEDs();
  
  delay(10);
}

void click_1() 
{
  start_LEDs();
  brightness_LEDs(255);
  color_LEDs(0xFFFF00);
  ws2812fx_1.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_2.setMode(FX_MODE_THEATER_CHASE);
  ws2812fx_3.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_4.setMode(FX_MODE_THEATER_CHASE);
  ws2812fx_5.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_6.setMode(FX_MODE_THEATER_CHASE);
  ws2812fx_7.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_8.setMode(FX_MODE_THEATER_CHASE);
  ws2812fx_9.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_10.setMode(FX_MODE_THEATER_CHASE);
  ws2812fx_11.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
}

void click_2() 
{
  start_LEDs();
  brightness_LEDs(255);
  color_LEDs(0xFFFF00);
  ws2812fx_1.setMode(FX_MODE_CIRCUS_COMBUSTUS);
  ws2812fx_2.setMode(FX_MODE_MULTI_DYNAMIC);
  ws2812fx_3.setMode(FX_MODE_CIRCUS_COMBUSTUS);
  ws2812fx_4.setMode(FX_MODE_MULTI_DYNAMIC);
  ws2812fx_5.setMode(FX_MODE_CIRCUS_COMBUSTUS);
  ws2812fx_6.setMode(FX_MODE_MULTI_DYNAMIC);
  ws2812fx_7.setMode(FX_MODE_CIRCUS_COMBUSTUS);
  ws2812fx_8.setMode(FX_MODE_MULTI_DYNAMIC);
  ws2812fx_9.setMode(FX_MODE_CIRCUS_COMBUSTUS);
  ws2812fx_10.setMode(FX_MODE_MULTI_DYNAMIC);
  ws2812fx_11.setMode(FX_MODE_CIRCUS_COMBUSTUS);
}

void click_3() 
{
  start_LEDs();
  brightness_LEDs(255);
  color_LEDs(0x0033FF);
  ws2812fx_1.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_2.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_3.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_4.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_5.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_6.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_7.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_8.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_9.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_10.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
  ws2812fx_11.setMode(FX_MODE_FIRE_FLICKER_INTENSE);
}

void click_4() 
{
  ws2812fx_1.stop();
  ws2812fx_2.stop();
  ws2812fx_3.stop();
  ws2812fx_4.stop();
  ws2812fx_5.stop();
  ws2812fx_6.stop();
  ws2812fx_7.stop();
  ws2812fx_8.stop();
  ws2812fx_9.stop();
  ws2812fx_10.stop();
  ws2812fx_11.stop();
}

void open_door() 
{
  start_LEDs();
  brightness_LEDs(255);
  color_LEDs(0xFFFFFF);
  ws2812fx_1.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_2.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_3.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_4.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_5.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_6.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_7.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_8.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_9.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_10.setMode(FX_MODE_RUNNING_LIGHTS);
  ws2812fx_11.setMode(FX_MODE_RUNNING_LIGHTS);
}

void init_LEDs() 
{
  ws2812fx_1.init();
  ws2812fx_2.init();
  ws2812fx_3.init();
  ws2812fx_4.init();
  ws2812fx_5.init();
  ws2812fx_6.init();
  ws2812fx_7.init();
  ws2812fx_8.init();
  ws2812fx_9.init();
  ws2812fx_10.init();
  ws2812fx_11.init();
}

void start_LEDs() 
{
  ws2812fx_1.start();
  ws2812fx_2.start();
  ws2812fx_3.start();
  ws2812fx_4.start();
  ws2812fx_5.start();
  ws2812fx_6.start();
  ws2812fx_7.start();
  ws2812fx_8.start();
  ws2812fx_9.start();
  ws2812fx_10.start();
  ws2812fx_11.start();
}

void service_LEDs()
{
  ws2812fx_1.service();
  ws2812fx_2.service();
  ws2812fx_3.service();
  ws2812fx_4.service();
  ws2812fx_5.service();
  ws2812fx_6.service();
  ws2812fx_7.service();
  ws2812fx_8.service();
  ws2812fx_9.service();
  ws2812fx_10.service();
  ws2812fx_11.service();
}

void brightness_LEDs(uint8_t brghtnss) 
{
  ws2812fx_1.setBrightness(brghtnss);
  ws2812fx_2.setBrightness(brghtnss);
  ws2812fx_3.setBrightness(brghtnss);
  ws2812fx_4.setBrightness(brghtnss);
  ws2812fx_5.setBrightness(brghtnss);
  ws2812fx_6.setBrightness(brghtnss);
  ws2812fx_7.setBrightness(brghtnss);
  ws2812fx_8.setBrightness(brghtnss);
  ws2812fx_9.setBrightness(brghtnss);
  ws2812fx_10.setBrightness(brghtnss);
  ws2812fx_11.setBrightness(brghtnss);
}

void speed_LEDs(uint16_t spd) 
{
  ws2812fx_1.setSpeed(spd);
  ws2812fx_2.setSpeed(spd);
  ws2812fx_3.setSpeed(spd);
  ws2812fx_4.setSpeed(spd);
  ws2812fx_5.setSpeed(spd);
  ws2812fx_6.setSpeed(spd);
  ws2812fx_7.setSpeed(spd);
  ws2812fx_8.setSpeed(spd);
  ws2812fx_9.setSpeed(spd);
  ws2812fx_10.setSpeed(spd);
  ws2812fx_11.setSpeed(spd);
}

void color_LEDs(uint32_t clr) 
{
  ws2812fx_1.setColor(clr);
  ws2812fx_2.setColor(clr);
  ws2812fx_3.setColor(clr);
  ws2812fx_4.setColor(clr);
  ws2812fx_5.setColor(clr);
  ws2812fx_6.setColor(clr);
  ws2812fx_7.setColor(clr);
  ws2812fx_8.setColor(clr);
  ws2812fx_9.setColor(clr);
  ws2812fx_10.setColor(clr);
  ws2812fx_11.setColor(clr);
}
