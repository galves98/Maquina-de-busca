#include <iostream>
#include <fstream>
#include "funcoes.h"
#include <string>
#include <math.h>
#include <windows.h>

using namespace std;

int main(){
  system("cls");
  Dicionario indiceinvertido;
  string palavra;
  int loop=1;

  while(loop!=0){
    double n=0,nt=0;
    int c_consulta;
    c_consulta = criar_consulta();
    if(c_consulta==0)return 0;

    ifstream p;
    p.open("consulta.txt");
    int a=0;
    set<string> docs;
    while(p>>palavra){
      minusculo(palavra);
      if(a==0){
        docs = indiceinvertido.consulta(palavra);
        a++;
        continue;
      }
      set<string> aux = indiceinvertido.consulta(palavra);
      for(set<string>::iterator it = docs.begin();it != docs.end();it++){
        if(aux.count(*it)==0){
          docs.erase(*it);
        }
      }
    }
    cout<<"Os arquivos que contem a consulta sao: "<<endl;
    if(docs.size() > 0){
      for(set<string>::iterator it = docs.begin();it != docs.end();it++){
        cout << *it << endl;
      }
    }
    else{
      cout<<"Nao existe esse texto no banco de dados"<<endl;
      continue;
    }

    /*

    //TF
    vector<int> tf_ = tf(docs,palavra);
    cout<<"TF: ";
    for(vector<int>::iterator it = tf_.begin();it != tf_.end();it++){
      cout << *it << endl;
    }

    //IDF;
    double idf_=0;
    n = indiceinvertido.numdoc();
    idf_ = log(n/nt);
    cout<<"idf= "<<idf_<<endl;

    // w
    vector<double> w;
    for (int i=0;i<tf_.size();i++){
      double aux = tf_[i]*idf_;
      w.push_back(aux);
      cout<<"w["<<i<<"] = "<<w[i]<<endl;
    }

    //SIM
    vector<double> sim_;
    double q = idf_;
    for (int i=0;i < w.size();i++){
    }
    */
  }
}
