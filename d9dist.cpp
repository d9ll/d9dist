#include "d9dist.h"

d9dist::d9dist(int trig, int echo) : _trig(trig), _echo(echo) {
  pinMode(_trig, OUTPUT);
  pinMode(_echo, INPUT);
}

float d9dist::getDist() {
  // Посылаем короткий импульс на датчик
  digitalWrite(_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);

  // Считаем время возврата звука (таймаут 30мс)
  long duration = pulseIn(_echo, HIGH, 30000); 
  
  // Если сигнал не вернулся (пустота), отдаем старое значение
  if (duration == 0) return _lastDist;

  // Считаем см: время * скорость звука / 2
  float dist = duration * 0.034 / 2;

  // Ограничиваем рабочий диапазон датчика
  if (dist < 2 || dist > 400) return _lastDist;

  // Плавный фильтр: 70% старого значения + 30% нового
  // Это убирает резкие скачки цифр в мониторе порта
  if (_lastDist == 0) _lastDist = dist; // Первый запуск
  _lastDist = _lastDist * 0.7 + dist * 0.3;
  
  return _lastDist;
}

bool d9dist::near(int cm) {
  // Вызываем измерение и сравниваем с твоим числом
  return (getDist() < (float)cm);
}