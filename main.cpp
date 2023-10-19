#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class versh {
public:
    double x;
    double y;
    double z;

    versh() {

    }
    versh(double X, double Y, double Z) {
        x = X;
        y = Y;
        z = Z;
    }
};

class norm {
public:
    double x;
    double y;
    double z;

    norm() {

    }
    norm(double X, double Y, double Z) {
        x = X;
        y = Y;
        z = Z;
    }
};

class tcor {
public:
    double x;
    double y;
    double z;

    tcor() {

    }
    tcor(double X, double Y, double Z) {
        x = X;
        y = Y;
        z = Z;
    }
};

class plosk {
public:
    vector<int> x;
    vector<int> y;
    vector<int> z;
    vector<int> n;

    plosk() {

    }
    plosk(vector<double> X, vector<double> Y, vector<double> Z) {
        for (int i = 0; i < X.size(); i++) x.push_back(X.at(i));
        for (int i = 0; i < Y.size(); i++) y.push_back(Y.at(i));
        for (int i = 0; i < Z.size(); i++) z.push_back(Z.at(i));

    }
};


int main() {
    vector<versh> vershs;
    vector<norm> norms;
    vector<tcor> tcors;
    vector<plosk> plosks;

    int a = NULL;
    int b = NULL;
    int c = NULL;
    int d = NULL;
    int e = NULL;
    int f = NULL;
    int g = NULL;
    int h = NULL;
    int i = NULL;
    int j = NULL;
    int k = NULL;
    int l = NULL;

    char input[256];
    cout << "insert name of file(with extension)" << "\n";
    cin >> input;

    FILE* db = fopen(input, "r");

    char buffer[256];
    fseek(db, 0, SEEK_SET);

    while (buffer != NULL) {
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

        plosk objF = *new plosk;
        scanf("f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", a, b, c, d, e, f, g, h, i, j, k, l);

        //cout << x << " - " << y << " - " << z << "\n";

        objF.x.push_back(a);
        objF.x.push_back(b);
        objF.x.push_back(c);

        objF.y.push_back(d);
        objF.y.push_back(e);
        objF.y.push_back(f);

        objF.z.push_back(g);
        objF.z.push_back(h);
        objF.z.push_back(i);

        objF.n.push_back(j);
        objF.n.push_back(k);
        objF.n.push_back(l);
        
    }

    cout << "cout of vershs: " << vershs.size() << "\n";
    cout << "cout of normals: " << norms.size() << "\n";
    cout << "cout of textcord: " << tcors.size() << "\n";
    cout << "cout of plosks: " << plosks.size() << "\n";
}
