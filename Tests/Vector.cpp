#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include "FlatVolume.h"
#include "Volume.h"
#include "Image.h"
#include "FlatImage.h"


using namespace std;





int main()
{
    cout << "Hello World!" << endl;

//    Volume<int> vol;
//    vol.printVolume(10);

//    Volume<float> volww;
//    volww.printVolume(10);



    char x = 130;

    Yuri::FlatVolume<int> vs(10, 10, 10);

   std::cout << (int)(unsigned char)x;
    int* pData = vs.GetPVolumeData();
    int ctr = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
            {
                pData[ctr] = ctr;
                std::cout << pData[ctr];
                ctr++;
            }






    return 0;
}
