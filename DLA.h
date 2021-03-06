#ifndef DLA_H__
#define DLA_H__

// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdlib> 
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Image.h"

class DLA {
 public :
 
  // =========================================================================
  //                               Constructors
  // =========================================================================

  DLA();
  DLA(const DLA& rhs);
  DLA(int L) ;
  
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~DLA();
  // =========================================================================
  //                                  Getters
  // =========================================================================
  int L(void) const;
  int** tab (void) const;
  int x(void) const;
  int y(void) const;
  
  // =========================================================================
  //                                  Setters
  // =========================================================================
  void setVal(int whereCol,int whereLine,int value);
  void setx(int value);
  void sety(int value);
  
  // =========================================================================
  //                                 Operators
  // =========================================================================
  
  // =========================================================================
  //                              Public Methods
  // =========================================================================
  void NewParticle(void);
  void ParticleMvmt(void);
  void Mvmtout(void);
  void MvmtUntilEnd(void);
  void PrintTab(void);
  void CycleofLife(void); 

protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
//attributes Table
  int L_;
  int** tab_;
//attributes Particles
  int x_;
  int y_;
  
};


// ===========================================================================
//                            Getters' definitions
// ===========================================================================


// ===========================================================================
//                            Setters' definitions
// ===========================================================================

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================



#endif // DLA_H__
