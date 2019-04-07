#ifndef TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_H

// Template Method
class DrinkWithCaffeine
{
public:
  virtual ~DrinkWithCaffeine();

  void recipe();
  void boilingWater();
  virtual void brewing() = 0;
  void pourIntoACup();
  void additives();
};

class Coffee : public DrinkWithCaffeine
{
public:
  void brewing() override;
};

class Tea : public DrinkWithCaffeine
{
public:
  void brewing() override;
};

#endif // TEMPLATEMETHOD_H
