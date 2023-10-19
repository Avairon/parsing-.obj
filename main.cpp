#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class versh{
public:
    double x;
    double y;
    double z;

    versh(){

    }
    versh(double X, double Y, double Z){
        x = X;
        y = Y;
        z = Z;
    }
};

class norm{
public:
    double x;
    double y;
    double z;

    norm(){

    }
    norm(double X, double Y, double Z){
        x = X;
        y = Y;
        z = Z;
    }
};

class tcor{
public:
    double x;
    double y;
    double z;

    tcor(){

    }
    tcor(double X, double Y, double Z){
        x = X;
        y = Y;
        z = Z;
    }
};

class plosk{
public:
    vector<int> x;
    vector<int> y;
    vector<int> z;

    plosk(){
        
    }
    plosk(vector<double> X, vector<double> Y, vector<double> Z){
        for(int i = 0; i < X.size(); i++) x.push_back(X.at(i));
        for(int i = 0; i < Y.size(); i++) y.push_back(Y.at(i));
        for(int i = 0; i < Z.size(); i++) z.push_back(Z.at(i));
        
    }
};


int main(){
    vector<versh> vershs;
    vector<norm> norms;
    vector<tcor> tcors;
    vector<plosk> plosks;

    char input[256];
    cout << "insert name of file(with extension)";
    cin >> input;

    FILE* db = fopen(input, "r");

    char buffer[256];
    fseek(db, 0, SEEK_SET);
 
    while(buffer != NULL){
        fgets(buffer, 256, db);

        versh objV = *new versh();
        scanf("v %lf %lf %lf", objV.x, objV.y, objV.z);
        vershs.push_back(objV);

        tcor objVT = *new tcor;
        scanf("vt %lf %lf %lf", objVT.x, objVT.y, objVT.z);
        tcors.push_back(objVT);

        norm objVN = *new norm;
        scanf("vn %lf %lf %lf", objVN.x, objVN.y, objVN.z);
        norms.push_back(objVN);

        if(buffer[0] == 'f' and strtok(buffer, " ") == 4){
            plosk objF = *new plosk;

            int x, y, z, v;
            for(int i = 0; i < 4; i++){
                
                scanf("%d/%d/%d", x, y, z);

                switch(i){
                    case(1):
                        objF.x.push_back(x);
                        objF.x.push_back(y);
                        objF.x.push_back(z);
                        break;
                    case(2):
                        objF.y.push_back(x);
                        objF.y.push_back(y);
                        objF.y.push_back(z);
                        break;
                    case(3):
                        objF.z.push_back(x);
                        objF.z.push_back(y);
                        objF.z.push_back(z);
                        break;
                }
            }
        }
    }

    cout << "cout of vershs: " << vershs.size() << "\n";
    cout << "cout of normals: " << norms.size() << "\n";
    cout << "cout of textcord: " << tcors.size() << "\n";
    cout << "cout of plosks: " << plosks.size() << "\n";
}
