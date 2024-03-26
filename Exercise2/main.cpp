#include <iostream>
#include <fstream>
#include <sstream>

double MapPoint(double N)
{
    return N*(0.75) - 1.75; // mappatura dei punti in [-1,2]
}

int main()

{
    std::string fileName = "data.csv";
    std::ifstream ifstr(fileName);

    if(ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    double val=0;
    double newval=0;
    double sumval=0;
    double mean=0;
    int i=0;


    while (ifstr>>val)
    {
        newval= MapPoint(val);
        std::ofstream outFile("result.csv");
        i++;
        sumval=sumval+newval;
        mean=sumval/i;
        outFile << i << ". " << mean << "\n";
        std::cout << i << ". " << mean << "\n";
        outFile.close();
    }

    ifstr.close();

}

