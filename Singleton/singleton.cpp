#include <iostream>
#include "singleton.h"

ChocolateBoiler::ChocolateBoiler() : m_Empty(true), m_Boiled(false)
{
    std::cout << "ChocolateBoiler created!" << std::endl;
}

// Initializing static pointer to instance - not the object inself.
ChocolateBoiler* ChocolateBoiler::m_pInstance = nullptr;

ChocolateBoiler* ChocolateBoiler::Instance()
{
    if (!m_pInstance)
      m_pInstance = new ChocolateBoiler;
    return m_pInstance;
}

void ChocolateBoiler::ResetInstance()
{
   delete m_pInstance;
   m_pInstance = nullptr;
}

void ChocolateBoiler::Fill()
{
    if (IsEmpty())
    {
        m_Empty = false;
        m_Boiled = false;
        std::cout << "Filled!" << std::endl;
    }
}

void ChocolateBoiler::Drain()
{
    if (!IsEmpty() && IsBoiled())
    {
        m_Empty = true;
        std::cout << "Drained!" << std::endl;
    }
}

void ChocolateBoiler::Boil(void)
{
    if (!IsEmpty() && !IsBoiled())
    {
        m_Boiled = true;
        std::cout << "Boiled!" << std::endl;
    }
}

bool ChocolateBoiler::IsEmpty(void)
{
    return m_Empty;
}

bool ChocolateBoiler::IsBoiled(void)
{
    return m_Boiled;
}

int main()
{
    std::cout<< "Singleton example" << std::endl;

    // Doesn't work
    // ChocolateBoiler* ptr = new ChocolateBoiler();
    ChocolateBoiler* factory_boiler = ChocolateBoiler::Instance();
    factory_boiler->Fill();
    factory_boiler->Boil();
    factory_boiler->Drain();
    ChocolateBoiler::Instance()->Drain();
    ChocolateBoiler::Instance()->Boil();
    factory_boiler = ChocolateBoiler::Instance();
    factory_boiler->Drain();
    factory_boiler->ResetInstance();
    factory_boiler = ChocolateBoiler::Instance();
    ChocolateBoiler* unknown_boiler = ChocolateBoiler::Instance();
    // the addresses will be the same
    std::cout << factory_boiler << " = " << unknown_boiler << std::endl;

    return 0;
}
