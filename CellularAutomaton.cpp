
// ===========================================================================
//                                  Includes
// ===========================================================================
#include "CellularAutomaton.h"


// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
  
// ===========================================================================
//                                Constructors
// ===========================================================================
//Constructeur par défaut
CellularAutomaton::CellularAutomaton() {
  N_ = 0;
  Tn_=NULL;
}

//Constructeur par copie
CellularAutomaton::CellularAutomaton(const CellularAutomaton& rhs) {
  N_ = rhs.N();
  Tn_=new int*[N_];
  for (int i=0;i<N_;i++){
    Tn_[i]=new int[N_];
    for (int j=0;j<N_;j++){
      Tn_[i][j]=rhs.Tn()[i][j];
    }
  };
}

//tab initializing
CellularAutomaton::CellularAutomaton(int N) {
  N_ = N;
  Tn_=new int* [N_];
  for (int i=0; i<N_;i++){
    Tn_[i]=new int [N_];
    for (int j=0;j<N_;j++){
      Tn_[i][j]=0;
    }
  }
  Tn_[0][N_/2]= 1;
  //begin 0 , first number lines, second columns
}

// ===========================================================================
//                                 Destructor
// ===========================================================================
CellularAutomaton::~CellularAutomaton(){
  for (int i=0; i<N_;i++){
    delete[] Tn_[i];
  }
  delete[] Tn_;
}
  
// ===========================================================================
//                               Public Methods
// ===========================================================================

//Getter N and tabEtat
int CellularAutomaton::N(void) const{ //L is the nb of column and line
  return N_;
}

int** CellularAutomaton::Tn(void) const{
  return Tn_;
}

//Method to print the table
void CellularAutomaton::PrintTn(void){
  for (int i=0; i<N_;i++){
    for (int j=0;j<N_;j++){
      printf("%d ",Tn_[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  //Image ima(N_,Tn_);
  //ima.save("DLAclass")
}

//Method to do the time n+1
void CellularAutomaton::NextTime(int n){
  int* Transit=new int[N_];
  for (int i=0; i<N_;i++){
    if (i==0){
      int k=N_-1; //=k-1
      int kk=i+1;//=k+1
      this->ValueNext(n,k,i,kk,Transit);
    }
    else if(i==N_-1){
      int k=i-1; //=k-1
      int kk=0;//=k+1
      this->ValueNext(n,k,i,kk,Transit);
    }
    else {
      int k=i-1; //=k-1
      int kk=i+1;//=k+1
      this->ValueNext(n,k,i,kk,Transit);  
    }
  }
  
  for (int j=0;j<N_;j++){
    Tn_[n+1][j]=Transit[j];
  }
  delete[] Transit;
}

//Method to know the value of k at n+1
void CellularAutomaton::ValueNext(int n,int k,int i,int kk,int* Transit){
  if (Tn_[n][k]==0){
    if(Tn_[n][i]==1){ //k-1=0 et k=1 => k de n+1 =1
      Transit[i]=1;
    }
    else if(Tn_[n][kk]==1){
      Transit[i]=1;
    }
    else {
      Transit[i]=0;
    }
  }
  
  else {
    if (Tn_[n][i]==1){
      Transit[i]=0;
    }
    else if(Tn_[n][kk]==1){
      Transit[i]=0;
    }
    else {
      Transit[i]=1;
    }
  }
}

//Method doing n times the cycle of NexTime and printing the table
void CellularAutomaton::MimiCycle(int time){
  this->PrintTn();
  for (int t=0;t<time;t++){
    this->NextTime(t);
    this->PrintTn();
  }
}


// ===========================================================================
//                              Protected Methods
// ===========================================================================
