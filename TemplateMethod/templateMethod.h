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
  virtual void additives() = 0;
};

class Coffee : public DrinkWithCaffeine
{
public:
  void brewing() override;
  void additives() override;
};

class Tea : public DrinkWithCaffeine
{
public:
  void brewing() override;
  void additives() override;
};

#endif // TEMPLATEMETHOD_H
