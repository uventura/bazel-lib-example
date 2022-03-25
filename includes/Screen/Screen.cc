#include "Screen.h"

void ClearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else if
        system("clear");
    #endif
}

void PrintScreen(char symbol, uint32_t x_axis, uint32_t y_axis)
{
    const char transitionSymbol = '*';
    bool transition = false;
    bool show = false;

    std::clock_t clk = std::clock();
    double delta_time;

    int repetitions = 0;

    while(repetitions < 10)
    {
        delta_time = (std::clock() - clk) / (double) CLOCKS_PER_SEC;
        if(delta_time > 1)
        {
            ClearScreen();
            show = true;
            clk = std::clock();
            repetitions += 1;
        }

        if(show)
        {
            for(uint32_t i = 0; i < x_axis; ++i)
            {
                for(uint32_t j = 0; j < y_axis; ++j)
                    std::cout << (transition?symbol:transitionSymbol) << " ";
                std::cout << "\n";
            }
            show = false;
            transition = !transition;
        }
    }
}