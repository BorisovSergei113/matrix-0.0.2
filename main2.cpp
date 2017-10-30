#include <iostream>
#include <sstream>
using namespace std;

void enter_mat (int,int,float **);

float ** create_mat ( unsigned int stroki,unsigned int stolbi,bool znak) {
    float ** mat=new float*[stroki];
    for (int i=0; i<stroki; i++) {
        mat[i]=new float [stolbi];
    }
    if(znak) enter_mat(stroki,stolbi,mat);
    return mat;
}


void enter_mat(int stroki,int stolbi,float **mat){
    
    for (int i =0; i<stroki ; i++)
    {
        
        for (string string;getline(cin, string);  )
        {  istringstream stream (string);
            bool failure = false;
            for (int j =0; j<stolbi; j++)
            {
                if (!(stream>>mat[i] [j]))
                {
                    failure = true;
                    break;
                }
            }
            if(!failure)
                break;
            else
            {cout<<"An error has occured while reading input data"<<'\n';}
        }
    }
}

int proverka(unsigned int stroki,unsigned int stolbi,unsigned int stroki2,unsigned int stolbi2){
    if(stolbi==stolbi2 && stroki==stroki2) return 1;
    else if(stroki==stolbi2) return 0;
    return -1;
}

float ** plus_mat(float **mat1,float **mat2,unsigned int stroki,unsigned int stolbi,unsigned int stroki2,unsigned int stolbi2){
    if(proverka( stroki,stolbi, stroki2, stolbi2)!=1){
        cout<<"Error add"<<endl;
        exit(1);
    }
    float **mat3 = create_mat( stroki,stolbi,false);
    for(int i=0;i<stroki;i++){
        for(int j=0;j<stolbi;j++){
            mat3[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    return mat3;
}


float ** minus_mat(float **mat1,float **mat2,unsigned int stroki,unsigned int stolbi,unsigned int stroki2,unsigned int stolbi2){
    if(proverka( stroki,stolbi, stroki2, stolbi2)!=1){
        cout<<"Error sub"<<endl;
        exit(1);
    }
    
    float **mat3 = create_mat( stroki,stolbi,false);
    for(int i=0;i<stroki;i++){
        for(int j=0;j<stolbi;j++){
            mat3[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
    return mat3;
}

float ** umnog_mat(float **mat1,float **mat2,unsigned int stroki,unsigned int stolbi,unsigned int stroki2,unsigned int stolbi2){
    if(proverka(  stroki,stolbi, stroki2, stolbi2)==-1){
        cout<<"Error mult"<<endl;
        exit(2);
    }
    float **mat3=create_mat(stroki,stolbi2,false);
    for(int i = 0; i < stroki; i++){
        for(int j = 0; j < stolbi2; j++)
        {
            mat3[i][j] = 0;
            for(int k = 0; k < stroki2; k++)
                mat3[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    return mat3;
}


float ** transp_mat(unsigned int stroki,unsigned int stolbi,float **mat1){
    float ** mat3= create_mat(stolbi,stroki,false);
    
    for(int i = 0; i<stolbi; i++){
        for(int j = 0; j<stroki; j++){
            mat3[i][j] = mat1[j][i];
        }
        
    }
    return mat3;
    
}

bool issqure(unsigned int stroki,unsigned int stolbi){
    if (stroki==stolbi) return true;
    else return false;
}

float opredel ( float ** ,unsigned int);

void Short_Mat(float **,float**,int ,int,unsigned int);

float **obrat(float **mat1,unsigned int stroki,unsigned int stolbi){
    if( issqure(stroki,stolbi) ){
        if(opredel(mat1,stroki)!=0){
            float **M;
            M=new float*[stroki];
            for (int i=0; i<stroki; i++) {
                M[i]=new float[stroki];
            }
            float **V;
            V=new float*[stroki];
            for (int i=0; i<stroki; i++) {
                V[i]=new float[stroki];
            }
            int x=0;
            for(int i=0;i<stroki;i++){
                for (int j=0; j<stroki; j++) {
                    Short_Mat(mat1,V,i,j,stroki);
                    float m =opredel(V,stroki-1);
                    x=i+j;
                    if((x%2)!=0) m=m*(-1);
                    M[i][j]=m;
                }
            }
            M=transp_mat(stroki,stolbi,M);
            float a =opredel(mat1,stroki);
            for(int i=0;i<stroki;i++){
                for (int j=0; j<stroki; j++) {
                    M[i][j] *= (1/a);
                }
                
            }
            
            return M;
        }
        
    }
    cout<<"There is no reverse matrix"<<endl;
    exit(3);
}


void Short_Mat(float **mat1,float **p, int i, int j,unsigned int stroki ){
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<stroki - 1; ki++) {
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj<stroki - 1; kj++) {
            if (kj == j) dj = 1;
            p[ki][kj] = mat1[ki + di][kj + dj];
        }
    }
}

float opredel(float **mat1,unsigned int stroki){
    int i,d,k,n,j;
    
    float **p;
    p=new float*[stroki];
    for(int i=0;i<stroki;i++){
        p[i]=new float[stroki];
    }
    j=0;
    d=0;
    k=1;
    n=stroki-1;
    if (stroki<1) {cout << "An error has occured while reading input data"; exit(0);}
    if (stroki == 1) {
        d = mat1[0][0];
        return(d);
    }
    if (stroki == 2) {
        d = mat1[0][0] * mat1[1][1] - (mat1[1][0] * mat1[0][1]);
        return(d);
    }
    if (stroki>2) {
        for (i = 0; i<stroki; i++) {
            Short_Mat(mat1, p, i, 0, stroki);
            d = d + k * mat1[i][0] * opredel(p, n);
            k = -k;
        }
    }
    for (int i=0; i<stroki; i++) {
        delete [] p[i];
    }
    delete [] p;
    
    return(d);
}

void del_mem(float **mat,unsigned int stroki,unsigned int stolbi){
    for (int i=0; i<stroki; i++) {
        delete [] mat[i];
    }
    delete [] mat;
}

void out(float **mat3,unsigned int stroki,unsigned int stolbi){
    cout<<endl;
    for (int i=0; i<stroki; i++) {
        for (int j=0; j<stolbi; j++) {
            if(mat3[i][j]==-0){
                cout<<"0"<<" ";
            }
            else{
            cout<<mat3[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    del_mem(mat3, stroki, stolbi);
    
}

void enter_size(unsigned int& stroki, unsigned int& stolbi)
{
    string str;
    char zap;
    getline(cin,str);
    istringstream size(str);
    if ((size >>stroki) && (size >>zap) && (size >> stolbi) && (zap == ',')&&(size.eof())) {
        
    }
    else
    {cout<<"An error has occured while reading input data"<<endl;
        exit(0);
    }
    
}

int main() {
    
    unsigned int stroki = 0,stolbi=0,stroki2=0,stolbi2=0;
    char op= ' ';
    float **mat1,**mat2;
    
    enter_size(stroki,stolbi);
    mat1=create_mat(stroki,stolbi,true);
    
    cin>>op;
    cin.get();
    
    switch (op) {
        case 'T':
            out(transp_mat(stroki,stolbi,mat1),stolbi,stroki);
            del_mem(mat1,stroki,stolbi);
            break;
        case 'R':
            out(obrat(mat1,stroki,stolbi),stroki,stolbi);
            del_mem(mat1, stroki, stolbi);
            break;
        case '+':
            enter_size(stroki2,stolbi2);
            mat2=create_mat(stroki2,stolbi2,true);
            out(plus_mat(mat1,mat2,stroki,stolbi,stroki2,stolbi2),stroki,stolbi);
            del_mem(mat1, stroki, stolbi);
            del_mem(mat2, stroki2, stolbi2);
            break;
        case '-':
            enter_size(stroki2,stolbi2);
            mat2=create_mat(stroki2,stolbi2,true);
            out(minus_mat(mat1,mat2,stroki,stolbi,stroki2,stolbi2),stroki,stolbi);
            del_mem(mat1, stroki, stolbi);
            del_mem(mat2, stroki2, stolbi2);
            break;
        case '*':
            enter_size(stroki2,stolbi2);
            mat2=create_mat(stroki2,stolbi2,true);
            out(umnog_mat(mat1,mat2,stroki,stolbi,stroki2,stolbi2),stroki,stolbi2);
            del_mem(mat1, stroki, stolbi);
            del_mem(mat2, stroki2, stolbi2);
            break;
        default:
            cout<<"An error has occured while reading input data"<<endl;
            break;
    }
    return 0 ;
}
