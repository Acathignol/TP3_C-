

// ===========================================================================
//                                  Includes
// ===========================================================================
//#include <cstdio>
#include <cstdlib>
//#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include "Image.h"
using namespace std;

#include "DLA.h"
#include "CellularAutomaton.h"

// ===========================================================================
//                            Function declarations
// ===========================================================================


// ===========================================================================
//                                    MAIN
// ===========================================================================
int main(int argc, char* argv[]) {
  srand (time(NULL));
  printf("Hello World! \n");
  
// ================================== DLA ====================================
  printf("Welcome to the class DLA \n \n");
  
  int size=100;
  DLA dla1(size);
  dla1.CycleofLife(); 
  
  Image ima(dla1.L(),dla1.tab(),0);
  ima.save("DLAclass_10");

// ============================ CELLULAR_AUTOMATON ==========================
  printf("Now we are going to the class CELLULAR_AUTOMATON \n \n");
  
  size=20;
  CellularAutomaton cell(size);
  cell.MimiCycle(size-1);
  Image mimi(cell.N(),cell.Tn(),1);
  mimi.save("CellularAutomatonClass_20");
  
  return 0;
}
