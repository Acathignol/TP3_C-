
// ===========================================================================
//                                  Includes
// ===========================================================================
#include "DLA.h"


// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
  
// ===========================================================================
//                                Constructors
// ===========================================================================
//Constructeur par défaut
DLA::DLA() {
  L_ = 0;
  tab_= NULL;
}

//Constructeur par copie
DLA::DLA(const DLA& rhs) {

  L_ = rhs.L();
  
  tab_ = new int*[L_];
  
  for (int i=0; i<L_;i++){
    tab_[i]=new int [L_];
    for (int j=0;j<L_;j++){
      tab_[i][j]=rhs.tab()[i][j];
    }
  }
}


//tab initializing
DLA::DLA(int L) {
  L_ = L;
  
  tab_ = new int*[L_];
  
  for (int i=0; i<L_;i++){
    tab_[i]=new int [L_];
    for (int j=0;j<L_;j++){
      tab_[i][j]=0;
    }
  }
  
  tab_[3*L/4][3*L/4] = 1;
  //begin 0 , first number columns, second lines
}



// ===========================================================================
//                                 Destructor
// ===========================================================================
DLA::~DLA(){
  for (int i=0; i<L_;i++){
    delete[] tab_[i];
  }
  delete[] tab_;
}
  
// ===========================================================================
//                               Public Methods
// ===========================================================================

//Getter L and Ldata and Tab
int DLA::L(void) const{ //L is the nb of column and line
  return L_;
}

int** DLA::tab(void) const{
  return tab_;
}

int DLA::x(void) const{
  return x_;
}

int DLA::y(void) const{
  return y_;
}

//Setter value in table
void DLA::setVal(int whereCol,int whereLine,int value){
  tab_[whereCol][whereLine]=value;
}

void DLA::setx(int value) {
  x_=value;
}

void DLA::sety(int value) {
  y_=value;
}

//New particle arrive
void DLA::NewParticle(void) {
  x_ = L_/4;
  y_ = L_/4;
  tab_[x_][y_] = 1;
  //begin 0 , first number columns, second lines
  
}

//HUGE cycle of life !!!!!!
void DLA::CycleofLife(void) {
  this->NewParticle();
  this->MvmtUntilEnd();
  
  if (tab_[L_/4][L_/4] != 1){
    if (tab_[(L_/4)+1][L_/4] != 1 and tab_[(L_/4)-1][L_/4] != 1 and
    tab_[L_/4][(L_/4)+1] != 1 and tab_[L_/4][(L_/4)-1] != 1){
      this->CycleofLife();
    }
  }
}

//checking for post-mvmt outside
void DLA::Mvmtout(void){
  if (x_>=L_){
      x_ = L_/4;
      y_ = L_/4;
  }
  else if (x_<0){
      x_ = L_/4;
      y_ = L_/4;
  }
  else if (y_>=L_){
      x_ = L_/4;
      y_ = L_/4;
  }
  else if (y_<0){
      x_ = L_/4;
      y_ = L_/4;
  }
}

//checking for post-mvmt next to some1=> stop
void DLA::MvmtUntilEnd(void){
  
  this->ParticleMvmt();
  
  int N=y_-1;
  int S=y_+1;
  int W=x_-1;
  int E=x_+1;
  
  if (W>=0 and tab_[W][y_]==1){
    this->PrintTab();
  }
  
  else if (E<L_ and tab_[E][y_]==1){
    this->PrintTab();
  }
  
  else if (N>=0 and tab_[x_][N]==1){
    this->PrintTab();
  }
  
  else if (S<L_ and tab_[x_][S]==1){
    this->PrintTab();
  }
  
  else {
    this->PrintTab();
    this->MvmtUntilEnd();
  }
}

void DLA::PrintTab(void){
  for (int i=0; i<L_;i++){
    for (int j=0;j<L_;j++){
      printf("%d ",tab_[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  //Image ima(L_,tab_);
  //ima.save("DLAclass")
}

//Particle moves with Bronien movment (north, south, east, west)
void DLA::ParticleMvmt(void){
  /* initialize random seed: */
  int mvmt1= rand() % 4; //0=North 1=S 2=W 3=E
  tab_[x_][y_] = 0;
  if (mvmt1==0){
    y_ = y_-1;
  }
  else if (mvmt1==1){
    y_ = y_+1;
  }
  else if (mvmt1==2){
    x_ = x_-1;
  }
  else if (mvmt1==3){
    x_ = x_+1;
  }
  this->Mvmtout();
  tab_[x_][y_] = 1;
}




// ===========================================================================
//                              Protected Methods
// ===========================================================================
