const int dataPin  = 10;
const int latchPin = 11;
const int clockPin = 12;

int byteToSend;



void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,  OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  byteToSend = 0;
  // put your main code here, to run repeatedly:
  for(int i = 0;i < 8;i++){
     // Обнуляем байт при каждом проходе 
    bitWrite(byteToSend, i , HIGH);// При bitPos=0 получим B00000001, при bitPos=1 - B00000010, при bitPos=2 - B00000100 и т.д. 
    digitalWrite(latchPin, LOW);  // устанавливаем синхронизацию "защелки" на LOW
    shiftOut(dataPin, clockPin, MSBFIRST, byteToSend); // Инвертируем сигнал при помощи MSBFIRST, грузим с первого бита 
    digitalWrite(latchPin, HIGH); //"защелкиваем" регистр, тем самым устанавливая значения на выходах
    delay(150);
  } 
  for(int i = 0;i < 8;i++){
     // Обнуляем байт при каждом проходе 
    bitWrite(byteToSend, i , LOW);// При bitPos=0 получим B00000001, при bitPos=1 - B00000010, при bitPos=2 - B00000100 и т.д. 
    digitalWrite(latchPin, LOW);  // устанавливаем синхронизацию "защелки" на LOW
    shiftOut(dataPin, clockPin, LSBFIRST, byteToSend); // Инвертируем сигнал при помощи MSBFIRST, грузим с первого бита 
    digitalWrite(latchPin, HIGH); //"защелкиваем" регистр, тем самым устанавливая значения на выходах
    delay(150);
  } 
}
