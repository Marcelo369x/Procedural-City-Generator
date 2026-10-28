#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

using namespace std::chrono;

int RandomNum(int n)
{

    std::srand(std::time(nullptr));

    // 2. Generar el número del 0 al 9
    int numero_random = std::rand() % n;

    return numero_random;
}

void createSTreets(array<array<char, 9>, 9> &map)
{
    
    int axis;
    int startPointX;
    int startPointY;
    int streetLength;
    for (int j = 0; j < 2; j++)
    {
        axis = RandomNum(3);
        // 0=eje x
        // 1=eje y
        // 2=eje d (diagonal)
        startPointX = RandomNum(8);
        this_thread::sleep_for(milliseconds(983));
        startPointY = RandomNum(8);
        this_thread::sleep_for(milliseconds(RandomNum(1001)));
        streetLength = RandomNum(9);

        if (axis == 0)
        {
            for (int i = 1; i < streetLength; i++)
            {
                if(startPointY + i == 8){break;}
                map[startPointX][startPointY + i] = ' ';
            }
        }
        else if (axis == 1)
        {
            for (int i = 1; i < streetLength; i++)
            {
                if(startPointX + i == 8){break;}
                map[startPointX + i][startPointY] = ' ';
            }
        }
        else if (axis == 2)
        {
            for (int i = 1; i < streetLength; i++)
            {
                if(startPointX - i == 0){break;}
                map[startPointX - i][startPointY + i] = ' ';
            }
        }
    }


    
}


void MapSacanner(array<array<char, 9>, 9> &map,vector<vector<int>>&coordVectorline ){
    
    for (int i = 0; i < 9; i++)
        {
            for (int k = 0; k < 9; k++)
            {
                if(map[i][k] == " "){
                    coordVectorline.push_back( );
                }
            }
        
    }    

}

void printMap(const array<array<char, 9>, 9> &map)
{
    //28
    for (int i = 0; i < 9; i++)
    {
        for (int k = 0; k < 9; k++)
        {

            cout << map[i][k] << " ";
        }  
        cout << endl;
    }
}
int main(){
    vector<array<int,2>>coordVectorline;
    array<array<char, 9>, 9> map = {

        {{'#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#'}}
    };

    createSTreets(map);
    printMap(map);
    return 0;
}