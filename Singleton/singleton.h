#ifndef SINGLETON_H
#define SINGLETON_H

class ChocolateBoiler
{
public:
    void Fill();
    void Drain();
    void Boil();
    bool IsEmpty();
    bool IsBoiled();
    static void ResetInstance();
    // 2. Define a public static accessor function
    static ChocolateBoiler* Instance();

private:
    // 3. Define private or protected constructor
    ChocolateBoiler();

    bool m_Empty;
    bool m_Boiled;
    // 1. Define a private static attribute
    static ChocolateBoiler* m_pInstance;
};

#endif // SINGLETON_H
