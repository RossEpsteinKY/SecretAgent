#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\nWelcome, Agent.  You are trying to hack The Operation's level " << Difficulty;
    std::cout << "\n server room... You must enter the correct codes to continue!\n";
    
}

bool PlayGame(int Difficulty, int Chances)
{

    
    PrintIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;
    
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    

    std::cout << std::endl;
    std::cout << "\n Remaining Chances: " << Chances << " Current Level: " << Difficulty;
    std::cout << "\n+ There are three numbers in the code";
    std::cout << "\n+ The codes add-up to:  " << CodeSum;
    std::cout << "\n+ The codes multiply to give:  " << CodeProduct << "\n";
    
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You entered:  " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You got the level " << Difficulty << " plans! \n";
        return true;
    } else {
        std::cout << "You failed to break in!\n";

        return false;
    }

}

int main()
{
    srand(time(NULL));

    const int MaxLevel = 20;
    int LevelDifficulty = 1;
    int Losses = 0;
    int Chances = 5;
    while(LevelDifficulty <= MaxLevel)
    {
        
        bool bLevelComplete = PlayGame(LevelDifficulty, Chances);
        std::cin.clear();
        std::cin.ignore();
        
        if (bLevelComplete)
        {
            //increase difficulty
            ++LevelDifficulty;

        }
        if(!bLevelComplete)
        {
            ++Losses;
            --Chances;
        }

        if(Losses == 5)
        {
            std::cout << "Sorry agent, but you lose!";
            return 0;
        }
        
    }
    std::cout << "*** Great work!  You hacked all the files! Now get out of there! ***\n";    
    return 0;    
}

