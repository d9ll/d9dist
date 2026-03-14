#ifndef D9DIST_H
#define D9DIST_H
#include <Arduino.h>

class d9dist {
  public:
    // Конструктор: указываем пины Trig и Echo
    d9dist(int trig, int echo);
    
    // Возвращает точную дистанцию в см (float)
    float getDist();
    
    // Проверка на близость: возвращает true, если объект ближе чем "cm"
    bool near(int cm);

  private:
    int _trig, _echo;
    float _lastDist = 0;
};
#endif