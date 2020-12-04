/**
Created by MathInDOS
Copyright (C) 2018-2020 MathInDOS
License: GNU GPLv3

**/

#include "EasyBMP.h"
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
    if(argv[1]==NULL){return 1;}
    if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "/?"))
    {
        cout << "BmpBPP Version-1.0" << endl
        << "Copyright (C) 2018-2020 MathInDOS" << endl
        << "License: GNU GPLv3" << endl << endl
        << "Usage: BmpBPP [Input Image] [Bit Depth] [Output Image]" << endl
        << "Bit Depth's are: 1, 2, 4, 8, 16, 24, 32" << endl
        << "Notice: 1 Bit means the output image will be monochrome." << endl << endl;
        return 0;
    }

    BMP Image;
    Image.ReadFromFile(argv[1]);

    BMP Output;
    Output.SetSize(Image.TellWidth(), Image.TellHeight());
    Output.SetBitDepth(24);

    RangedPixelToPixelCopy(Image, 0, Output.TellWidth()-1, Output.TellHeight()-1, 0, Output, 0, 0);

    if(argv[2]==NULL){return 1;
    }else{
    Output.SetBitDepth(atol(argv[2]));
    if(argv[3]==NULL){return 1;}
    cout << "Writing bit's in file please wait... "<< endl;
    Output.WriteToFile(argv[3]);
    return 0;
}
}