#include "DataWriters.hpp"


void DataWriters::cpWriter(const std::vector<double> & cp,const std::vector<Panel>& Panels ){

std::FILE *pFile = fopen("cp.dat","w");
if (pFile == nullptr)
{
    std::runtime_error("Cannot Write CP Data");
}
 
   std::fprintf(pFile, "#Xcoord, Ycoord, Cp\n");
for (int i=0; i < cp.size() ; i++)
{
    std::fprintf(pFile, "%f , %f , %f \n", Panels[i].xm,Panels[i].ym, cp[i] );
} 

std::fclose(pFile);

}

