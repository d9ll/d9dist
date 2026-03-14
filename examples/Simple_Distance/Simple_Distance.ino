#include <d9dist.h>

d9dist sensor(12, 11); // Создаем объект

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // Проверяем: если кто-то подошел ближе 15 см
  if (sensor.near(15)) {
    digitalWrite(13, HIGH); // Включаем светодиод
    Serial.println("Объект РЯДОМ!");
  } else {
    digitalWrite(13, LOW);
    Serial.print("Дистанция: ");
    Serial.println(sensor.getDist()); // Просто выводим см
  }
  
  delay(100); // Чтобы датчик успевал "остыть" между замерами
}
